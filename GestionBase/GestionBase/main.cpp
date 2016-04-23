
#include <QCoreApplication>
#include <QtWidgets>
#include <QtSql>
#include <iostream>

bool connectionBDD()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("Mordheim");
    db.setUserName("florent");
    db.setPassword("azerty");
    bool ok = db.open();

    if (ok)
        std::cout << "Connection réussie!" << std::endl;

    return ok;
}

void initializeModel(QSqlRelationalTableModel *model)
{
    //model->setTable("employee");
    model->setTable("ref_profil");
    model->setJoinMode(QSqlRelationalTableModel::LeftJoin);

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setRelation(2, QSqlRelation("race", "id", "nom_race"));
    model->setRelation(1, QSqlRelation("rang", "id", "nom_rang"));
    //model->setRelation(model->fieldIndex("regle"), QSqlRelation("regles_speciales", "id_race", "nom"));


    model->select();
    std::cout << model->lastError().text().toStdString() << std::endl;
}

QTableView *createView(const QString &title, QSqlTableModel *model)
{
    QTableView *view = new QTableView;
    view->setModel(model);
    view->resizeColumnsToContents();
    view->setItemDelegate(new QSqlRelationalDelegate(view));
    view->setWindowTitle(title);
    view->hideColumn( model->fieldIndex("id"));
    return view;
}

QComboBox *createComboBox(QSqlRelationalTableModel *model)
{
    QComboBox *comboBox= new QComboBox;
    QSqlTableModel *relModel= model->relationModel( model->fieldIndex("nom_race"));
    comboBox->setModel( relModel);
    comboBox->setModelColumn( relModel->fieldIndex("nom_race"));

    model->setFilter("nom_race='"+ comboBox->currentText()+ "' ");

    std::cout << relModel->lastError().text().toStdString() << std::endl;
    return comboBox;

}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget fenetre;
    QVBoxLayout *layout= new QVBoxLayout;



    connectionBDD();

    QSqlRelationalTableModel model;


    initializeModel(&model);

    QTableView *view = createView(QObject::tr("Relational Table Model"), &model);

    QComboBox *raceBox= createComboBox(&model);




    layout->addWidget(raceBox);
    layout->addWidget( view);

    fenetre.setLayout( layout);
    fenetre.show();


    return app.exec();
}
