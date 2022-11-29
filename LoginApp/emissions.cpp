#include "emissions.h"
#include <QSqlQuery>
#include <QDebug>
#include<QObject>

EMISSIONS::EMISSIONS()
{
    ID_EMISSION=0;
    NOM_EMISSION="";
    TYPE_EMISSION="";
    DUREE_EMISSION="";
    DATE_EMISSION="";
}

EMISSIONS::EMISSIONS(int ID_EMISSION,QString NOM_EMISSION,QString TYPE_EMISSION,QString DUREE_EMISSION ,QString DATE_EMISSION )
{
    this->ID_EMISSION=ID_EMISSION;
    this->NOM_EMISSION=NOM_EMISSION;
    this->TYPE_EMISSION=TYPE_EMISSION;
    this->DUREE_EMISSION=DUREE_EMISSION;
    this->DATE_EMISSION=DATE_EMISSION;

}

int EMISSIONS::getid(){return ID_EMISSION;}
QString EMISSIONS::getnom(){return NOM_EMISSION;}
QString EMISSIONS::gettype(){return TYPE_EMISSION;}
QString EMISSIONS::getduree(){return DUREE_EMISSION;}
QString EMISSIONS::getdate(){return DATE_EMISSION;}

void EMISSIONS::setid(int ID_EMISSION){ this->ID_EMISSION=ID_EMISSION;}
void EMISSIONS::setnom(QString NOM_EMISSION){this->NOM_EMISSION=NOM_EMISSION;}
void EMISSIONS::settype(QString TYPE_EMISSION){this->TYPE_EMISSION=TYPE_EMISSION;}
void EMISSIONS::setduree(QString DUREE_EMISSION){this->DUREE_EMISSION=DUREE_EMISSION;}
void EMISSIONS::setdate(QString DATE_EMISSION){this->DATE_EMISSION=DATE_EMISSION;}

bool EMISSIONS::ajouter()
{


    QSqlQuery query;
    QString id_string=QString::number(ID_EMISSION);
          query.prepare("INSERT INTO EMISSIONS (ID_EMISSION,NOM_EMISSION,TYPE_EMISSION,DUREE_EMISSION,DATE_EMISSION) "
                        "VALUES (:ID_EMISSION, :NOM_EMISSION, :TYPE_EMISSION,:DUREE_EMISSION,:DATE_EMISSION)");

          query.bindValue(":ID_EMISSION", id_string);
          query.bindValue(":NOM_EMISSION", NOM_EMISSION);
          query.bindValue(":TYPE_EMISSION", TYPE_EMISSION);
           query.bindValue(":DUREE_EMISSION", DUREE_EMISSION);
            query.bindValue(":DATE_EMISSION", DATE_EMISSION);

         return query.exec();



}

bool EMISSIONS::supprimer(int ID_EMISSION)
{
    QSqlQuery query;
          //  QString id_string=QString::number(ID_EMISSION);
          query.prepare("Delete from EMISSIONS where ID_EMISSION=:ID_EMISSION");
          query.bindValue(0, ID_EMISSION);
          return  query.exec();
}




QSqlQueryModel* EMISSIONS::afficher()
{
         QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT*  FROM EMISSIONS");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("NAME"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("DURATION"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE"));



    return model;

}

QSqlQueryModel* EMISSIONS::afficher_emission(QString order){
    QSqlQueryModel *model = new QSqlQueryModel();

        if(order=="ID_EMISSION")
        {
           model->setQuery("select * from EMISSIONS order by ID_EMISSION ASC ");
        }
        if(order=="NOM_EMISSION")
        {
            model->setQuery("select * from EMISSIONS order by NOM_EMISSION ASC ");
        }
        if(order=="TYPE_EMISSION")
        {
            model->setQuery("select * from EMISSIONS order by TYPE_EMISSION ASC ");
        }

       model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EMISSION"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_EMISSION"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_EMISSION"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("DUREE_EMISSION"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_EMISSION"));

    return model;


}


bool EMISSIONS::update(){
    QSqlQuery query;
      QString id_string=QString::number(ID_EMISSION);

      query.prepare( "UPDATE emissions SET ID_EMISSION=:ID_EMISSION , NOM_EMISSION=:NOM_EMISSION ,"
                     " DUREE_EMISSION=:DUREE_EMISSION , DATE_EMISSION=:DATE_EMISSION ,TYPE_EMISSION=:TYPE_EMISSION WHERE ID_EMISSION=:ID_EMISSION ");

   query.bindValue(":ID_EMISSION",id_string);
   query.bindValue(":NOM_EMISSION",NOM_EMISSION);
   query.bindValue(":TYPE_EMISSION",TYPE_EMISSION);
   query.bindValue(":DUREE_EMISSION",DUREE_EMISSION);
   query.bindValue(":DATE_EMISSION",DATE_EMISSION);


return query.exec();
}

QSqlQueryModel* EMISSIONS::search_emission(QString  chaine,QString variable)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    QSqlQuery query;
    if(variable=="ID_EMISSION")
     {
     model->setQuery("SELECT * FROM EMISSIONS WHERE  (ID_EMISSION like '"+chaine+"%""')  ");
     }
    if(variable=="NOM_EMISSION")
     {
     model->setQuery("SELECT * FROM EMISSIONS WHERE  (NOM_EMISSION like '"+chaine+"%""')  ");
     }
    if(variable=="TYPE_EMISSION")
     {
     model->setQuery("SELECT * FROM EMISSIONS WHERE  (TYPE_EMISSION like '"+chaine+"%""')  ");
     }
    if(variable=="DUREE_EMISSION")
     {
     model->setQuery("SELECT * FROM EMISSIONS WHERE  (DUREE_EMISSION like '"+chaine+"%""')  ");
     }
    if(variable=="DATE_EMISSION")
     {
     model->setQuery("SELECT * FROM EMISSIONS WHERE  (DATE_EMISSION like '"+chaine+"%""')  ");
     }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EMISSION"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_EMISSION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_EMISSION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DUREE_EMISSION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_EMISSION"));

        return  model;
}

QSqlQueryModel * EMISSIONS:: afficher_calendar(QString x)
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM EMISSIONS WHERE  (DATE_EMISSION like '"+x+"%""')  ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EMISSION"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_EMISSION"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_EMISSION"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DUREE_EMISSION"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_EMISSION"));

    return model;
}
