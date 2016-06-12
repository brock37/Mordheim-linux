#include <QApplication>
#include <QDebug>
// this is a comment
#include "connectiondialog.h"
#include "window.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);


   ConnectionDialog connection;
   if(connection.exec() != QDialog::Accepted)
   {
       return -1;
   }
   Window window;
   window.show();

    return app.exec();
}
