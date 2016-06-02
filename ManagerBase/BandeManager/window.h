#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QSqlRelationalTableModel>
#include <QSqlDatabase>

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QMainWindow *parent = 0);
    ~Window();

private:
    QSqlRelationalTableModel *m_listeBandeModel;

};

#endif // WINDOW_H
