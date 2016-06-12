#include "connectiondialog.h"

ConnectionDialog::ConnectionDialog(QWidget *parent) :
    QDialog(parent)
{
    QGroupBox *inputBox= creatInputWidget();
    QDialogButtonBox *buttonBox= createButtonBox();

    readSettings();

    QVBoxLayout *layout= new QVBoxLayout;
    layout->addWidget(inputBox);
    layout->addWidget( buttonBox);

    setLayout( layout);
    setWindowTitle("Connection a la BDD");
}

QGroupBox *ConnectionDialog::creatInputWidget(){

    QGroupBox *box= new QGroupBox("Identifiant");

    m_id= new QLineEdit;
    m_password= new QLineEdit;


    QFormLayout *layout= new QFormLayout;
    layout->addRow(tr("&Id"), m_id);
    layout->addRow(tr("&Password"), m_password);

    box->setLayout( layout);
    return box;
}

QDialogButtonBox *ConnectionDialog::createButtonBox(){

    QPushButton *connectButton= new QPushButton("Connect");
    QPushButton *closeButton= new QPushButton("Close");

    connectButton->setDefault( true);

    connect(connectButton, SIGNAL(clicked()), this, SLOT(connectToBDD()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

    QDialogButtonBox *buttonBox= new QDialogButtonBox;
    buttonBox->addButton(connectButton, QDialogButtonBox::AcceptRole);
    buttonBox->addButton(closeButton, QDialogButtonBox::RejectRole);

    return buttonBox;
}

void ConnectionDialog::connectToBDD()
{
    QString id= m_id->text();
    QString password= m_password->text();

    bool connected= createConnection(id, password);
    if( connected){
        writeSettings();
        accept();
    }
    else{
        QMessageBox::information( this, "Connexion", "La connexion à échouer");
    }
}

bool ConnectionDialog::createConnection(QString id, QString password)
{
    QSqlDatabase db= QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("Mordheim");
    db.setUserName(id);
    db.setPassword(password);

    if(!db.open())
    {
        QMessageBox::critical(0, "Cannot open database",
                    "Unable to establish a database connection.\n"
                       "This example needs SQLite support. Please read "
                       "the Qt SQL driver documentation for information how "
                       "to build it.", QMessageBox::Cancel);
                return false;
    }

    return true;
}

void ConnectionDialog::readSettings(){

    QSettings settings("Mordheim", "ManagerBase");

    settings.beginGroup("Connection dialog");
    m_id->setText( settings.value("id", "").toString());
    m_password->setText( settings.value("password", "").toString());
    settings.endGroup();
}

void ConnectionDialog::writeSettings(){

    QSettings settings("Mordheim", "ManagerBase");
    settings.beginGroup("Connection dialog");
    settings.setValue("id", m_id->text());
    settings.setValue("password", m_password->text());
    settings.endGroup();
}
