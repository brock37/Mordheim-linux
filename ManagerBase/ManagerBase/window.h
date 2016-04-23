#ifndef WINDOW_H
#define WINDOW_H

#include <QtWidgets>
#include <QWidget>
#include <QSqlRelationalTableModel>
#include <QSqlDatabase>
#include <QSqlRelationalDelegate>

#include "addrowdialog.h"
//#include "basemanager.h"


class Window : public QWidget
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    void setupModel();

signals:

public slots:
    void setFilter(QString index);
    void addProfil();

private:


    QGridLayout *m_layout;

    QComboBox *m_raceComboBox;
    QComboBox *m_rangComboBox;

    QLabel *m_nomLabel;
    QLineEdit *m_nomEdit;

    QPushButton *m_ajouterButton;

    QTableView *m_view;

    QSqlRelationalTableModel *m_model;

    int raceIndex;
    int rangIndex;




};

#endif // WINDOW_H
