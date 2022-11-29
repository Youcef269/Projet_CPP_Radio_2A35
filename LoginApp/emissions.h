#ifndef EMISSIONS_H
#define EMISSIONS_H
#include <QString>
#include <QSqlQuery>
#include<QSqlQueryModel>

class EMISSIONS
{
public:
    EMISSIONS();
    EMISSIONS(int,QString,QString,QString,QString );

       int getid();
       QString getnom();
       QString gettype();
       QString getduree();
       QString getdate();

       void setid(int);
       void setnom(QString);
       void settype(QString);
       void setduree(QString);
       void setdate(QString);
       bool ajouter();
       bool supprimer(int);
       bool update();
      QSqlQueryModel* afficher();
      QSqlQueryModel* search_emission(QString  ,QString );
      QSqlQueryModel* afficher_emission(QString order);
      QSqlQueryModel *afficher_calendar(QString x);
   private:
       int ID_EMISSION;
       QString NOM_EMISSION,TYPE_EMISSION,DUREE_EMISSION,DATE_EMISSION;
};

#endif // EMISSIONS_H
