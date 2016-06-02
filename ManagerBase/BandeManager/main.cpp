#include "dataBase.h"
#include "window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(!createConnexion())
        return 1;

    Window w;
    w.show();

    return a.exec();
}
