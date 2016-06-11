#include "window.h"

extern int uniqueRaceId;
extern int uniqueProfilId;

Window::Window(QWidget *parent) :
    QMainWindow(parent)
{

    setupModel();

    QGroupBox *box= createFilterGroupBox();

    uniqueProfilId= m_model->rowCount();
    uniqueRaceId= m_raceComboBox->count();

    m_view= new QTableView;
    m_view->setModel( m_model);
    m_view->hideColumn(0);
    m_view->resizeColumnsToContents();

    QDialogButtonBox *editButton= createEditDatabaseButtonBox();



    m_layout= new QVBoxLayout;
    m_layout->addWidget( box);
    m_layout->addWidget(m_view);
    m_layout->addWidget( editButton);

    QWidget *widget= new QWidget;
    widget->setLayout(m_layout);

    createMenuBar();

    setCentralWidget( widget);


    this->resize(920,600);

}


void Window::resetBoxFilter()
{
    m_raceComboBox->setCurrentIndex(-1);
    m_rangComboBox->setCurrentIndex(-1);
    m_nomEdit->clear();

    m_model->setFilter("");
}

void Window::setFilter(QString raceFilter, QString rangFilter, QString nameFilter)
{
    QString filter;

    if( raceFilter != ""){
        filter.append(QString("nom_race='%1'").arg(raceFilter));
    }

    if(!rangFilter.isEmpty()){
        if(filter.isEmpty()){
            filter.append(QString("nom_rang='%1'").arg(rangFilter));
        }
        else{
            filter.append(QString("AND nom_rang='%1'").arg(rangFilter));
        }
    }

    if(!nameFilter.isEmpty()){
        if(filter.isEmpty()){
            filter.append(QString("Nom='%1'").arg(nameFilter));
        }
        else{
            filter.append(QString(" AND Nom='%1'").arg(nameFilter));
        }
    }

    qDebug() << QString("Filter: '%1'").arg(filter);


    m_model->setFilter( filter);
}


void Window::applyFilter()
{
    setFilter(m_raceComboBox->currentText(), m_rangComboBox->currentText(), m_nomEdit->text());
}

void Window::resetFilter()
{
    resetBoxFilter();
}

void Window::addProfil()
{
    AddRowDialog* dialog= new AddRowDialog(m_model , this);
    int accepted= dialog->exec();

    if(accepted == 1){
        int lastRow = m_model->rowCount() - 1;
        m_view->selectRow(lastRow);
        m_view->scrollToBottom();
    }
    qDebug() << m_model->lastError().text();
}

void Window::removeProfil()
{
    QModelIndexList selection= m_view->selectionModel()->selectedRows(0);

    if(!selection.isEmpty())
    {
        QModelIndex idIndex= selection.at(0);
        QString name= idIndex.sibling(idIndex.row(), m_model->fieldIndex("Nom")).data().toString();

        QMessageBox::StandardButton deleteButton;
        deleteButton= QMessageBox::question(this, "Delete Profil", QString("Are you sure you want to "
                                                                        "delete '%1'?")
                                         .arg(name),
                                         QMessageBox::Yes | QMessageBox::No);
        if(deleteButton== QMessageBox::Yes){
            deleteProfilFromDatabase(idIndex);
        }
    }
    else{
        QMessageBox::information(this, "Delete Profil", "Select the profil you want to delete.");
    }

}

void Window::deleteProfilFromDatabase(QModelIndex index)
{
    m_model->removeRow( index.row());
    qDebug() << "Suppresion du profil id:" << index.row();
}

void Window::setupModel()
{

    m_model= new QSqlRelationalTableModel(this);
    m_model->setTable("ref_profil");

    raceIndex= m_model->fieldIndex("id_race");
    rangIndex= m_model->fieldIndex("id_rang");

    m_model->setRelation(raceIndex, QSqlRelation("race", "ID", "nom_race"));
    m_model->setRelation(rangIndex, QSqlRelation( "rang", "id", "nom_rang"));

    m_model->select();


}

QGroupBox *Window::createFilterGroupBox()
{
    QGroupBox *box= new QGroupBox("Filtre");

    m_raceComboBox= new QComboBox;
    m_rangComboBox= new QComboBox;


    m_nomLabel= new QLabel("Nom:");
    m_nomEdit= new QLineEdit;

    QDialogButtonBox *buttonBox= createFilterButtonBox();

    QSqlTableModel *relModel= m_model->relationModel( raceIndex);
    m_raceComboBox->setModel( relModel);
    m_raceComboBox->setModelColumn( relModel->fieldIndex("nom_race"));
    m_raceComboBox->setCurrentIndex(-1);


    QSqlTableModel *relModelRang= m_model->relationModel( rangIndex);
    m_rangComboBox->setModel( relModelRang);
    m_rangComboBox->setModelColumn( relModelRang->fieldIndex("nom_rang"));
    m_rangComboBox->setCurrentIndex(-1);


    QHBoxLayout *lineEditLayout= new QHBoxLayout;
    lineEditLayout->addWidget(m_nomLabel);
    lineEditLayout->addWidget(m_nomEdit);


    QVBoxLayout *layout= new QVBoxLayout;
    layout->addWidget( m_raceComboBox);
    layout->addWidget( m_rangComboBox);
    layout->addLayout( lineEditLayout);
    layout->addWidget( buttonBox);

    box->setLayout( layout);
    return box;
}

QDialogButtonBox *Window::createFilterButtonBox()
{
    QPushButton *applyButton= new QPushButton("Apply");
    QPushButton *resetButton= new QPushButton("Reset");

    resetButton->setDefault( true);

    connect(applyButton, SIGNAL(clicked()), this, SLOT(applyFilter()));
    connect(resetButton, SIGNAL(clicked()), this, SLOT(resetFilter()));

    QDialogButtonBox *buttonBox= new QDialogButtonBox;
    buttonBox->addButton(applyButton, QDialogButtonBox::AcceptRole);
    buttonBox->addButton(resetButton, QDialogButtonBox::ResetRole);

    return buttonBox;

}

QDialogButtonBox *Window::createEditDatabaseButtonBox()
{
    QPushButton *addButton= new QPushButton("Add");
    QPushButton *removeButton= new QPushButton("Remove");

    addButton->setDefault( true);

    connect(addButton, SIGNAL(clicked()), this , SLOT(addProfil()));
    connect(removeButton, SIGNAL(clicked()), this , SLOT(removeProfil()));

    QDialogButtonBox *buttonBox= new QDialogButtonBox;
    buttonBox->addButton( addButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton( removeButton, QDialogButtonBox::ActionRole);

    return buttonBox;
}

void Window::createMenuBar()
{
    QAction *addProfilAction= new QAction(tr("&Add profil"), this);
    QAction *deleteProfilAction= new QAction(tr("&Delete profil"), this);
    QAction *quitAction= new QAction(tr("&Quit"), this);

    addProfilAction->setShortcut(tr("Ctrl+A"));
    deleteProfilAction->setShortcut(tr("Ctrl+D"));
    quitAction->setShortcut(tr("Ctrl+Q"));

    QMenu *fileMenu= menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(addProfilAction);
    fileMenu->addAction(deleteProfilAction);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAction);


    connect(addProfilAction, SIGNAL(triggered(bool)), this, SLOT(addProfil()));
    connect(deleteProfilAction, SIGNAL(triggered(bool)), this, SLOT(removeProfil()));
    connect(quitAction, SIGNAL(triggered(bool)), this, SLOT(close()));

}
