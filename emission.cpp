#include "emission.h"
#include <QSqlQuery>
#include <QDebug>
Emission::Emission()
{
ID_EMISSION=0;
NOM_EMISSION="";
TYPE_EMISSION="";
DUREE_EMISSION="";
DATE_EMISSION="";
}

Emission::Emission(int ID_EMISSION,QString NOM_EMISSION,QString TYPE_EMISSION,QString DUREE_EMISSION ,QString DATE_EMISSION )
{
    this->ID_EMISSION=ID_EMISSION;
    this->NOM_EMISSION=NOM_EMISSION;
    this->TYPE_EMISSION=TYPE_EMISSION;
    this->DUREE_EMISSION=DUREE_EMISSION;
    this->DATE_EMISSION=DATE_EMISSION;

}

int Emission::getid(){return ID_EMISSION;}
QString Emission::getnom(){return NOM_EMISSION;}
QString Emission::gettype(){return TYPE_EMISSION;}
QString Emission::getduree(){return DUREE_EMISSION;}
QString Emission::getdate(){return DATE_EMISSION;}

void Emission::setid(int ID_EMISSION){ this->ID_EMISSION=ID_EMISSION;}
void Emission::setnom(QString NOM_EMISSION){this->NOM_EMISSION=NOM_EMISSION;}
void Emission::settype(QString TYPE_EMISSION){this->TYPE_EMISSION=TYPE_EMISSION;}
void Emission::setduree(QString DUREE_EMISSION){this->DUREE_EMISSION=DUREE_EMISSION;}
void Emission::setdate(QString DATE_EMISSION){this->DATE_EMISSION=DATE_EMISSION;}

bool Emission::ajouter()
{


    QSqlQuery query;
    QString id_string=QString::number(ID_EMISSION);
          query.prepare("INSERT INTO EMISSIONS (ID_EMISSION,NOM_EMISSION,TYPE_EMISSION,DUREE_EMISSION,DATE_EMISSION) "
                        "VALUES (:ID_EMISSION, :NOM_EMISSION, :TYPE_EMISSION,:DUREE_EMISSION,:DATE_EMISSION)");

          query.bindValue(":id", id_string);
          query.bindValue(":NOM_EMISSION", NOM_EMISSION);
          query.bindValue(":TYPE_EMISSION", TYPE_EMISSION);
           query.bindValue(":DUREE_EMISSION", DUREE_EMISSION);
            query.bindValue(":DATE_EMISSION", DATE_EMISSION);

         return query.exec();



}
