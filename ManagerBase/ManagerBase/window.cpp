#include "window.h"

Window::Window(QWidget *parent) :
    QWidget(parent)
{

    setupModel();

    QGroupBox *box= createFilterGroupBox();

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
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);

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

    QSqlTableModel *relModel= m_model->relationModel( raceIndex);
    m_raceComboBox->setModel( relModel);
    m_raceComboBox->setModelColumn( relModel->fieldIndex("nom_race"));
    m_raceComboBox->setCurrentIndex(-1);


    QSqlTableModel *relModelRang= m_model->relationModel( rangIndex);
    m_rangComboBox->setModel( relModelRang);
    m_rangComboBox->setModelColumn( relModelRang->fieldIndex("nom_rang"));
    m_rangComboBox->setCurrentIndex(-1);


    connect( m_raceComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeFilter()));
    connect( m_rangComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeFilter()));

    QHBoxLayout *lineEditLayout= new QHBoxLayout;
    lineEditLayout->addWidget(m_nomLabel);
    lineEditLayout->addWidget(m_nomEdit);


    QVBoxLayout *layout= new QVBoxLayout;
    layout->addWidget( m_raceComboBox);
    layout->addWidget( m_rangComboBox);
    layout->addLayout( lineEditLayout);

    box->setLayout( layout);
    return box;
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
    m_model->setFilter( filter);}

void Window::changeFilter()
{
    setFilter(m_raceComboBox->currentText(), m_rangComboBox->currentText(), m_nomEdit->text());
}

void Window::addProfil()
{
    AddRowDialog* dialog= new AddRowDialog(m_model , this);
    int accepted= dialog->exec();

    if(accepted == 1){
        QMessageBox::information(0,"Ajout profil" ,"Profil ajouter", QMessageBox::Cancel);
    }
}
