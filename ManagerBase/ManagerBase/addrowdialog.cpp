#include "addrowdialog.h"

AddRowDialog::AddRowDialog(QSqlRelationalTableModel *profil, QWidget *parent) :
    QDialog(parent)
{
    m_model= profil;

    QGroupBox *box= createInputsWidget();
    QDialogButtonBox *buttonBox= createButtonBox();

    QVBoxLayout *layout= new QVBoxLayout;
    layout->addWidget(box);
    layout->addWidget( buttonBox);

    setLayout( layout);
    setWindowTitle("Ajouter Profil");
}

QGroupBox *AddRowDialog::createInputsWidget()
{
    QGroupBox *box= new QGroupBox("Ajouter Profil");

    QLabel *raceLabel= new QLabel("Race:");
    QLabel *rangLabel= new QLabel("Rang:");
    QLabel *nomLabel= new QLabel("Nom:");
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

    raceCombo= new QComboBox;
    rangCombo= new QComboBox;

    int raceIndex= m_model->fieldIndex("nom_race");
    QSqlTableModel *raceModel= m_model->relationModel( raceIndex);
    raceCombo->setModel( raceModel);
    raceCombo->setModelColumn( raceModel->fieldIndex("nom_race"));

    int rangIndex= m_model->fieldIndex("nom_rang");
    QSqlTableModel *rangModel= m_model->relationModel( rangIndex);
    rangCombo->setModel( rangModel);
    rangCombo->setModelColumn( rangModel->fieldIndex("nom_rang"));



    nomEdit= new QLineEdit;


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

    layout->addWidget( raceLabel, 0, 0);
    layout->addWidget( raceCombo, 0, 1, 1, 5);
    layout->addWidget(rangLabel, 1, 0);
     layout->addWidget( rangCombo, 1, 1, 1, 5);

    layout->addWidget( nomLabel, 2, 0, 1, 1);
    layout->addWidget( nomEdit, 2, 1, 1, 5);
    layout->addWidget( prixLabel, 3, 0, 1, 1);
    layout->addWidget( prixEdit, 3, 1, 1, 5);

    layout->addWidget( MLabel, 4, 0);
    layout->addWidget( MSpinBox, 4, 1);
    layout->addWidget( CcLabel, 4, 2);
    layout->addWidget( CcSpinBox, 4, 3);
    layout->addWidget( CtLabel, 4, 4);
    layout->addWidget( CtSpinBox, 4, 5);

    layout->addWidget( FLabel, 5, 0);
    layout->addWidget( FSpinBox, 5, 1);
    layout->addWidget( ELabel, 5, 2);
    layout->addWidget( ESpinBox, 5, 3);
    layout->addWidget( PvLabel, 5, 4);
    layout->addWidget( PvSpinBox, 5, 5);

    layout->addWidget( ILabel, 6, 0);
    layout->addWidget( ISpinBox, 6, 1);
    layout->addWidget( ALabel, 6, 2);
    layout->addWidget( ASpinBox, 6, 3);
    layout->addWidget( CdLabel, 6, 4);
    layout->addWidget( CdSpinBox, 6, 5);



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


void AddRowDialog::submit(){

    QString nom= nomEdit->text();

    if( nom.isEmpty() ){
        QMessageBox::information( this, "Ajouter profil", "Ajouter un nom au profil");
        return;
    }
    else{
        accept();
    }


}
