#ifndef VOITURE_H
#define VOITURE_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>
class voiture
{
    QString MATRICULE;
    QString MARQUE;
    QString MODELE;
    QString KILOMETRAGE;
    QString DATE_ARRIVAGE;
    QDate DATE_SORTIE;
    QString TYPE_DE_PANNE;
public:
    voiture();
    voiture(QString MATRICULE,
    QString MARQUE,
    QString MODELE,
    QString KILOMETRAGE,
    QString DATE_ARRIVAGE,
    QDate DATE_SORTIE,
    QString TYPE_DE_PANNE);

    void ajouter();
    QSqlQueryModel * afficher();
    void supprimer(QString ID);
    void modifier();
    QSqlQueryModel * tri();
    QSqlQueryModel * rechercher(QString MATRICULE);
};

#endif // VOITURE_H
