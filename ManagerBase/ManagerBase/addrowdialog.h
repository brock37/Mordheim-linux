#ifndef ADDROWDIALOG_H
#define ADDROWDIALOG_H

#include <QDialog>
#include <QGroupBox>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QSpinBox>
#include <QDebug>
#include <QSqlError>

#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QSqlField>
#include <QComboBox>
#include <QMessageBox>

class AddRowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddRowDialog( QSqlRelationalTableModel *profil, QWidget *parent = 0);
    QGroupBox* createInputsWidget();
    QGroupBox* createIdInputsWidget();
    QDialogButtonBox* createButtonBox();
    QMap<QString, int> getFeatures();
    int findRaceId(QString race);
    int addNewRace(QString race);
    int addNewProfil(int raceId, int rangId, QString nom, QMap<QString, int> input);
    int generateRaceId();
    int generateProfilId();


signals:

public slots:
    void submit();

private:
    QSqlRelationalTableModel *m_model;

    QComboBox *raceCombo;
    QComboBox *rangCombo;

    QLineEdit *raceLineEdit;
    QLineEdit *nomEdit;

    QSpinBox *prixSpinBox;
    QSpinBox *MSpinBox;
    QSpinBox *CcSpinBox;
    QSpinBox *CtSpinBox;
    QSpinBox *FSpinBox;
    QSpinBox *ESpinBox;
    QSpinBox *PvSpinBox;
    QSpinBox *ISpinBox;
    QSpinBox *ASpinBox;
    QSpinBox *CdSpinBox;



};

#endif // ADDROWDIALOG_H
