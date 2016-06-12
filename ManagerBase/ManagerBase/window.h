#ifndef WINDOW_H
#define WINDOW_H

#include <QtWidgets>
#include <QMainWindow>
#include <QWidget>
#include <QSqlRelationalTableModel>

#include <QSqlRelationalDelegate>

#include "addprofildialog.h"
#include "connectiondialog.h"
//#include "basemanager.h"


class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    void setupModel();
    QGroupBox *createFilterGroupBox();
    QDialogButtonBox *createFilterButtonBox();
    QDialogButtonBox *createEditDatabaseButtonBox();
    void createMenuBar();

    void setFilter(QString raceFilter="", QString rangFilter="", QString nameFilter="");
    void resetBoxFilter();


    void deleteProfilFromDatabase(QModelIndex index);

signals:

public slots:
    void applyFilter();
    void resetFilter();
    void addProfil();
    void removeProfil();

private:


    QVBoxLayout *m_layout;

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
