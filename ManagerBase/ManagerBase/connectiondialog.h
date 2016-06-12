#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QSettings>

class ConnectionDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ConnectionDialog(QWidget *parent = 0);
    QDialogButtonBox *createButtonBox();
    QGroupBox *creatInputWidget();
    bool createConnection(QString id, QString password);
    void readSettings();
    void writeSettings();


signals:

public slots:
    void connectToBDD();

private:
    QLineEdit *m_id;
    QLineEdit *m_password;


};

#endif // CONNECTIONDIALOG_H
