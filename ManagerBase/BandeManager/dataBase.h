#ifndef DATABASE_H
#define DATABASE_H


#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

bool createConnexion()
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
                return false;
    }

    return true;
}

#endif // DATABASE_H
