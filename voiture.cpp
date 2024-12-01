#include "voiture.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <qDebug>
voiture::voiture()
{

}
voiture::voiture(QString MATRICULE,
                 QString MARQUE,
                 QString MODELE,
                 QString KILOMETRAGE,
                 QString DATE_ARRIVAGE,
                 QDate DATE_SORTIE,
                 QString TYPE_DE_PANNE)
{
    this->MATRICULE=MATRICULE;
    this->MARQUE=MARQUE;
    this->MODELE=MODELE;
    this->KILOMETRAGE=KILOMETRAGE;
    this->DATE_ARRIVAGE=DATE_ARRIVAGE;
    this->DATE_SORTIE=DATE_SORTIE;
    this->TYPE_DE_PANNE=TYPE_DE_PANNE;

}

void voiture::ajouter()
{
    QSqlQuery query;
    query.prepare("insert into VOITURE (MATRICULE,MARQUE,MODELE,KILOMETRAGE,DATE_ARRIVAGE,DATE_SORTIE,TYPE_DE_PANNE) values (:MATRICULE,:MARQUE,:MODELE,:KILOMETRAGE,:DATE_ARRIVAGE,:DATE_SORTIE,:TYPE_DE_PANNE)");//requete bch najouti lel base les attributs
    query.bindValue(":MATRICULE", MATRICULE);
    query.bindValue(":MARQUE", MARQUE);
    query.bindValue(":MODELE", MODELE);
    query.bindValue(":KILOMETRAGE", KILOMETRAGE);
    query.bindValue(":DATE_ARRIVAGE", DATE_ARRIVAGE);
    query.bindValue(":DATE_SORTIE", DATE_SORTIE);
    query.bindValue(":TYPE_DE_PANNE", TYPE_DE_PANNE);
    if(query.exec()){qDebug()<<"saved";};
}
QSqlQueryModel * voiture::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from VOITURE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MODELE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("KILOMETRAGE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_ARRIVAGE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE_SORTIE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("TYPE_DE_PANNE"));
    return model;
}
void voiture::supprimer(QString id)
{
        QSqlQuery query;
        query.prepare("delete from VOITURE where MATRICULE = :MATRICULE");
        query.bindValue(":MATRICULE", id);
        query.exec();
}
void voiture::modifier()
{
    QSqlQuery query;
          query.prepare("update  VOITURE set  MARQUE=:MARQUE, MODELE=:MODELE,KILOMETRAGE=:KILOMETRAGE,DATE_ARRIVAGE=:DATE_ARRIVAGE,DATE_SORTIE=:DATE_SORTIE,TYPE_DE_PANNE=:TYPE_DE_PANNE where(MATRICULE=:MATRICULE)");
          query.bindValue(":MATRICULE", MATRICULE);
          query.bindValue(":MARQUE", MARQUE);
          query.bindValue(":MODELE", MODELE);
          query.bindValue(":KILOMETRAGE", KILOMETRAGE);
          query.bindValue(":DATE_ARRIVAGE", DATE_ARRIVAGE);
          query.bindValue(":DATE_SORTIE", DATE_SORTIE);
          query.bindValue(":TYPE_DE_PANNE", TYPE_DE_PANNE);
          query.exec();
}
QSqlQueryModel * voiture::tri()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from VOITURE ORDER BY KILOMETRAGE DESC");//ASC croissant
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MODELE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("KILOMETRAGE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_ARRIVAGE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE_SORTIE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("TYPE_DE_PANNE"));
    return model;
}
QSqlQueryModel * voiture::rechercher(QString MATRICULE)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from VOITURE where MATRICULE like '%"+MATRICULE+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MODELE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("KILOMETRAGE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_ARRIVAGE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE_SORTIE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("TYPE_DE_PANNE"));
    return model;
}
