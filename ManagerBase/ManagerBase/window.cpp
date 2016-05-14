#include "window.h"

Window::Window(QWidget *parent) :
    QWidget(parent)
{

    setupModel();

    m_raceComboBox= new QComboBox;
    m_rangComboBox= new QComboBox;

    m_nomLabel= new QLabel("Nom:");
    m_nomEdit= new QLineEdit;

    QSqlTableModel *relModel= m_model->relationModel( raceIndex);
    m_raceComboBox->setModel( relModel);
    m_raceComboBox->setModelColumn( relModel->fieldIndex("nom_race"));

    QSqlTableModel *relModelRang= m_model->relationModel( rangIndex);
    m_rangComboBox->setModel( relModelRang);
    m_rangComboBox->setModelColumn( relModelRang->fieldIndex("nom_rang"));


    m_view= new QTableView;
    m_view->setModel( m_model);
    m_view->resizeColumnsToContents();

    m_ajouterButton= new QPushButton("Add");


    QObject::connect( m_raceComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(setRaceFilter(QString)));
    QObject::connect( m_rangComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(setRangFilter(QString)));
    QObject::connect( m_ajouterButton, SIGNAL(clicked()), this, SLOT( addProfil()));


    m_layout= new QGridLayout;
    m_layout->addWidget( m_raceComboBox, 0, 0 , 1, 2);
    m_layout->addWidget( m_rangComboBox, 1, 0, 1, 2);
    m_layout->addWidget(m_view, 2, 0, 1, 2);
    m_layout->addWidget(m_nomLabel, 3 , 0, 1, 1);
    m_layout->addWidget(m_nomEdit, 3 , 1, 1, 1);
    m_layout->addWidget( m_ajouterButton, 4, 0, 1, 1);

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

void Window::setRaceFilter(QString index)
{
    QString filter= QString("nom_race='%1'").arg(index);
    m_model->setFilter( filter);
}

void Window::setRangFilter(QString index)
{
    QString filter= QString("nom_rang='%1'").arg(index);
    m_model->setFilter( filter);
}

void Window::addProfil()
{
    AddRowDialog* dialog= new AddRowDialog(m_model , this);
    int accepted= dialog->exec();

    if(accepted == 1){
        QMessageBox::information(0,"Ajout profil" ,"Profil ajouter", QMessageBox::Cancel);
    }
}
