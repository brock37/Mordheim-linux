#include "window.h"

extern int uniqueRaceId;
extern int uniqueProfilId;

Window::Window(QWidget *parent) :
    QWidget(parent)
{

    setupModel();

    QGroupBox *box= createFilterGroupBox();

    uniqueProfilId= m_model->rowCount();
    uniqueRaceId= m_raceComboBox->count();

    m_view= new QTableView;
    m_view->setModel( m_model);
    m_view->resizeColumnsToContents();

    m_ajouterButton= new QPushButton("Add");

    QObject::connect( m_ajouterButton, SIGNAL(clicked()), this, SLOT( addProfil()));



    m_layout= new QVBoxLayout;
    m_layout->addWidget( box);
    m_layout->addWidget(m_view);
    m_layout->addWidget( m_ajouterButton);
    this->setLayout( m_layout);

    //this->resize(920,600);

}


void Window::setupModel()
{
    QSqlDatabase db= QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("Mordheim");
    db.setUserName("florent");
    db.setPassword("azerty");

    if(!db.open())
    {
        QMessageBox::critical(0, "Cannot open database",
                    "Unable to establish a database connection.\n"
                       "This example needs SQLite support. Please read "
                       "the Qt SQL driver documentation for information how "
                       "to build it.", QMessageBox::Cancel);
                return;
    }

    m_model= new QSqlRelationalTableModel(this);
    m_model->setTable("ref_profil");

    raceIndex= m_model->fieldIndex("id_race");
    rangIndex= m_model->fieldIndex("id_rang");

    m_model->setRelation(raceIndex, QSqlRelation("race", "id", "nom_race"));
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

    if(raceFilter != "" ){
        if(rangFilter != ""){
            if( nameFilter != ""){
                filter= QString("nom_race='%1' AND nom_rang='%2' AND Nom='%3'").arg(raceFilter).arg(rangFilter).arg(nameFilter);
            }
            else{
                filter= QString("nom_race='%1' AND nom_rang='%2'").arg(raceFilter).arg(rangFilter);
            }
        }
        else{
            filter= QString("nom_race='%1'").arg(raceFilter);
        }
    }
    else{
        if(rangFilter != ""){
            if( nameFilter != ""){
                filter= QString("nom_rang='%2' AND Nom='%3'").arg(rangFilter).arg(nameFilter);
            }
            else{
                filter= QString("nom_rang='%1'").arg(rangFilter);
            }
        }
    }


    m_model->setFilter( filter);
}

void Window::changeFilter()
{
    setFilter(m_raceComboBox->currentText(), m_rangComboBox->currentText(), m_nomEdit->text());
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
}
