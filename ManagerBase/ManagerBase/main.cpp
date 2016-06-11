#include <QApplication>
#include <QDebug>
// this is a comment
#include "connectiondialog.h"
#include "window.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    ConnectionDialog *connection= new ConnectionDialog;

    int accepted= connection->exec();

    if(accepted == 1){
        qDebug() << "Connection ok Lancement app";
        Window *window= new Window;
        window->show();
    }

    return app.exec();
}
