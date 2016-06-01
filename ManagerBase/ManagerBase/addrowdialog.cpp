#include "addrowdialog.h"

int uniqueRaceId;
int uniqueProfilId;

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


    prixSpinBox= new QSpinBox;
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
    layout->addWidget( prixSpinBox, 1, 1);

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
    buttonBox->addButton(submitButton, QDialogButtonBox::AcceptRole);
    buttonBox->addButton(closeButton, QDialogButtonBox::RejectRole);

    return buttonBox;

}

int AddRowDialog::findRaceId(QString race)
{
    QSqlTableModel *model= m_model->relationModel(m_model->fieldIndex("nom_race"));
    int index= 0;

    while( index < model->rowCount()){
        QSqlRecord record= model->record( index);
        if( record.value("nom_race") == race){
            qDebug() << "id Race touver - id =" << record.value("ID").toInt();
            return record.value("ID").toInt();
        }
        else
            index++;
    }

    qDebug() << "id Race non touver Creation d'une nouvelle race";
    int idRace= addNewRace(race);
    return idRace;
}

int AddRowDialog::findRangId(QString rang)
{
    QSqlTableModel *model= m_model->relationModel(m_model->fieldIndex("nom_rang"));
    int index= 0;

    while( index < model->rowCount()){
        QSqlRecord record= model->record( index);
        if( record.value("nom_rang") == rang)
            return record.value("id").toInt();
        else
            index++;
    }
    qDebug() << "id Rang non touver. Index= " << index;
    return 0;
}


int AddRowDialog::addNewRace(QString race)
{
    QSqlTableModel *raceModel= m_model->relationModel(m_model->fieldIndex("nom_race"));
    QSqlRecord record;
    int id = generateRaceId();

    QSqlField f1("ID", QVariant::Int);
    QSqlField f2("nom_race", QVariant::String);

    f1.setValue(QVariant(id));
    f2.setValue(QVariant(race));
    record.append(f1);
    record.append(f2);

    bool insert= raceModel->insertRecord(-1, record);


    if(!insert)
        qDebug()<< "Creation Race - Erreur insertion: " << raceModel->lastError().text();
    else{
        qDebug() << "id RaCE Creer. Index= " << id;

    }
return id;

}


int AddRowDialog::addNewProfil( int rangId, int raceId, QString nom, QMap<QString, int> input)
{
    int id=generateProfilId();

    m_model->select();

    QSqlRecord record;

    QSqlField f1("ID", QVariant::Int);
    QSqlField f2("id_rang", QVariant::Int);
    QSqlField f3("id_race", QVariant::Int);
    QSqlField f4("Nom", QVariant::String);
    QSqlField f5("Prix", QVariant::Int);
    QSqlField f6("M", QVariant::Int);
    QSqlField f7("CC", QVariant::Int);
    QSqlField f8("CT", QVariant::Int);
    QSqlField f9("F", QVariant::Int);
    QSqlField f10("E", QVariant::Int);
    QSqlField f11("PV", QVariant::Int);
    QSqlField f12("I", QVariant::Int);
    QSqlField f13("A", QVariant::Int);
    QSqlField f14("Cd", QVariant::Int);
    QSqlField f15("Arme_Armure", QVariant::String);
    QSqlField f16("Regle", QVariant::Int);

    f1.setValue(QVariant(id));
    f2.setValue(QVariant(rangId));
    f3.setValue(QVariant(raceId));
    f4.setValue(QVariant(nom));
    f5.setValue(QVariant(input.value("prix")));
    f6.setValue(QVariant(input.value("M")));
    f7.setValue(QVariant(input.value("Cc")));
    f8.setValue(QVariant(input.value("Ct")));
    f9.setValue(QVariant(input.value("F")));
    f10.setValue(QVariant(input.value("E")));
    f11.setValue(QVariant(input.value("Pv")));
    f12.setValue(QVariant(input.value("I")));
    f13.setValue(QVariant(input.value("A")));
    f14.setValue(QVariant(input.value("Cd")));
    f15.setValue(QVariant(" "));
    f16.setValue(QVariant(0));

    record.append(f1);
    record.append(f2);
    record.append(f3);
    record.append(f4);
    record.append(f5);
    record.append(f6);
    record.append(f7);
    record.append(f8);
    record.append(f9);
    record.append(f10);
    record.append(f11);
    record.append(f12);
    record.append(f13);
    record.append(f14);
    record.append(f15);
    record.append(f16);

    bool insert= m_model->insertRecord(-1, record);
    if(!insert)
        qDebug()<< "Ajout Profil Erreur insertion: " << m_model->lastError().text();
    else
        qDebug() << "Ajout a la base";
    return id;
}

QMap<QString, int> AddRowDialog::getFeatures()
{
    QMap<QString, int> features;

    features.insert("prix", prixSpinBox->value());
    features.insert("M", MSpinBox->value());
    features.insert("Cc", CcSpinBox->value());
    features.insert("Ct", CtSpinBox->value());
    features.insert("F", FSpinBox->value());
    features.insert("E", ESpinBox->value());
    features.insert("Pv", PvSpinBox->value());
    features.insert("I", ISpinBox->value());
    features.insert("A", ASpinBox->value());
    features.insert("Cd", CdSpinBox->value());

    return features;
}


void AddRowDialog::submit()
{
    QString nom_race= raceCombo->currentText();
    QString nom_rang= rangCombo->currentText();

    QString nom= nomEdit->text();

    if( nom.isEmpty() || nom_race.isEmpty() ){
        QMessageBox::information( this, "Ajouter profil", "Ajouter un nom et une race au profil");
    }
    else{
        int raceId= findRaceId( nom_race);
        int rangId= findRangId( nom_rang);
        QMap<QString, int> featuresList= getFeatures();

        int profilId= addNewProfil(rangId, raceId, nom, featuresList);

        accept();
    }
}

int AddRowDialog::generateRaceId()
{
    uniqueRaceId += 1;
    return uniqueRaceId;
}

int AddRowDialog::generateProfilId()
{
    uniqueProfilId += 1;
    return uniqueProfilId;
}
