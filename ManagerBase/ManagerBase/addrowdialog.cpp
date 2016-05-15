#include "addrowdialog.h"

AddRowDialog::AddRowDialog(QSqlRelationalTableModel *profil, QWidget *parent) :
    QDialog(parent)
{
    m_model= profil;

    QGroupBox *idBox= createIdInputsWidget();
    QGroupBox *inputBox= createInputsWidget();
    QDialogButtonBox *buttonBox= createButtonBox();

    QVBoxLayout *layout= new QVBoxLayout;
    layout->addWidget(idBox);
    layout->addWidget(inputBox);
    layout->addWidget( buttonBox);

    setLayout( layout);
    setWindowTitle("Ajouter Profil");
}

QGroupBox *AddRowDialog::createInputsWidget()
{
    QGroupBox *box= new QGroupBox("Caracteristiques");

    QLabel *prixLabel= new QLabel("Prix:");
    QLabel *MLabel= new QLabel("M:");
    QLabel *CcLabel= new QLabel("CC:");
    QLabel *CtLabel= new QLabel("CT:");
    QLabel *FLabel= new QLabel("F:");
    QLabel *ELabel= new QLabel("E:");
    QLabel *PvLabel= new QLabel("PV:");
    QLabel *ILabel= new QLabel("I:");
    QLabel *ALabel= new QLabel("A:");
    QLabel *CdLabel= new QLabel("Cd:");


    prixEdit= new QSpinBox;
    MSpinBox= new QSpinBox;
    CcSpinBox= new QSpinBox;
    CtSpinBox= new QSpinBox;
    FSpinBox= new QSpinBox;
    ESpinBox= new QSpinBox;
    PvSpinBox= new QSpinBox;
    ISpinBox= new QSpinBox;
    ASpinBox= new QSpinBox;
    CdSpinBox= new QSpinBox;

    QGridLayout *layout= new QGridLayout;

    layout->addWidget( prixLabel, 1, 0);
    layout->addWidget( prixEdit, 1, 1);

    layout->addWidget( MLabel, 2, 0);
    layout->addWidget( MSpinBox, 2, 1);
    layout->addWidget( CcLabel, 2, 2);
    layout->addWidget( CcSpinBox, 2, 3);
    layout->addWidget( CtLabel, 2, 4);
    layout->addWidget( CtSpinBox, 2, 5);

    layout->addWidget( FLabel, 3, 0);
    layout->addWidget( FSpinBox, 3, 1);
    layout->addWidget( ELabel, 3, 2);
    layout->addWidget( ESpinBox, 3, 3);
    layout->addWidget( PvLabel, 3, 4);
    layout->addWidget( PvSpinBox, 3, 5);

    layout->addWidget( ILabel, 4, 0);
    layout->addWidget( ISpinBox, 4, 1);
    layout->addWidget( ALabel, 4, 2);
    layout->addWidget( ASpinBox, 4, 3);
    layout->addWidget( CdLabel, 4, 4);
    layout->addWidget( CdSpinBox, 4, 5);

    box->setLayout( layout);

    return box;
}

QGroupBox *AddRowDialog::createIdInputsWidget()
{
    QGroupBox *box= new QGroupBox("Identite");

    QLabel *raceLabel= new QLabel("Race:");
    QLabel *rangLabel= new QLabel("Rang:");
    QLabel *nomLabel= new QLabel("Nom:");

    raceCombo= new QComboBox;
    raceLineEdit= new QLineEdit;

    rangCombo= new QComboBox;

    nomEdit= new QLineEdit;

    int raceIndex= m_model->fieldIndex("nom_race");
    QSqlTableModel *raceModel= m_model->relationModel( raceIndex);
    raceCombo->setModel( raceModel);
    raceCombo->setModelColumn( raceModel->fieldIndex("nom_race"));
    raceCombo->setCurrentIndex(-1);
    raceCombo->setInsertPolicy(QComboBox::InsertAtBottom);
    raceCombo->setLineEdit( raceLineEdit);

    int rangIndex= m_model->fieldIndex("nom_rang");
    QSqlTableModel *rangModel= m_model->relationModel( rangIndex);
    rangCombo->setModel( rangModel);
    rangCombo->setModelColumn( rangModel->fieldIndex("nom_rang"));

    QGridLayout *layout= new QGridLayout;

    layout->addWidget( raceLabel, 0, 0);
    layout->addWidget( raceCombo, 0, 1);
    layout->addWidget(rangLabel, 1, 0);
    layout->addWidget( rangCombo, 1, 1);
    layout->addWidget( nomLabel, 2, 0);
    layout->addWidget( nomEdit, 2, 1);

    box->setLayout( layout);

    return box;
}


QDialogButtonBox* AddRowDialog::createButtonBox()
{
    QPushButton *submitButton= new QPushButton("Submit");
    QPushButton *closeButton= new QPushButton("Close");

    closeButton->setDefault( true);

    connect(submitButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

    QDialogButtonBox *buttonBox= new QDialogButtonBox;
    buttonBox->addButton(submitButton, QDialogButtonBox::ResetRole);
    buttonBox->addButton(closeButton, QDialogButtonBox::RejectRole);

    return buttonBox;

}

int AddRowDialog::findRaceId(QString race)
{
    QSqlTableModel *model= m_model->relationModel(m_model->fieldIndex("nom_rang"));
    int index= 0;

    while( index < model->rowCount()){
        QSqlRecord record= model->record( index);
        if( record.value("nom_rang") == race)
            return index;
        else
            index++;
    }

    return index;
}

int AddRowDialog::addNewRace(QString race)
{
    return 0;
}


void AddRowDialog::submit(){

    QString nom= nomEdit->text();

    if( nom.isEmpty() ){
        QMessageBox::information( this, "Ajouter profil", "Ajouter un nom au profil");
    }
    else{

        accept();
    }


}
