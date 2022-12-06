#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
#include<QPdfWriter>
#include<QPainter>
#include<QPrinter>

CLIENT::CLIENT()
{
id=0; nom=""; type=""; periode="";
}
CLIENT::CLIENT(int id ,QString nom ,QString type,QString periode)
{
    this->id=id; this->nom=nom; this->type=type; this->periode=periode;
}



int CLIENT::getid(){ return id; }
QString CLIENT::getnom(){ return nom; }
QString CLIENT::gettype(){ return type; }
QString CLIENT::getperiode(){ return periode; }
void CLIENT::setid(int  id){ this->id=id;}
void CLIENT::setnom(QString nom){this->nom=nom;}
void CLIENT::settype(QString type){this->type=type;}
void CLIENT::setperiode(QString periode){this->periode=periode;}
bool CLIENT::ajouter()
{
    QSqlQuery query;
    QString id_string= QString::number(id);
          query.prepare("INSERT INTO CLIENT (id,nom,type,periode) "
                        "VALUES (:id, :nom, :type, :periode)");
          query.bindValue(":id", id_string);
          query.bindValue(":nom", nom);
          query.bindValue(":type", type);
          query.bindValue(":periode", periode);


    return query.exec();
}


bool CLIENT::supprimer(int id)
{
QSqlQuery query;
QString id_string= QString::number(id);
      query.prepare("DELETE FROM CLIENT WHERE ID=:id");
      query.bindValue(":id", id);



return query.exec();
}
QSqlQueryModel* CLIENT::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


  model->setQuery("SELECT* FROM CLIENT");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("periode"));
  return model;
}
QSqlQueryModel* CLIENT::rechercherdynamique(QString input,QString filter)
     {
         QSqlQueryModel * model= new QSqlQueryModel ();
            QSqlQuery query;
            query.prepare("SELECT * FROM CLIENT WHERE "+filter+" LIKE '%' || :inputValue || '%' ");
            query.bindValue(":inputValue",input);
            query.exec();
            model->setQuery(query);
            return model;
     }

bool CLIENT::modifier(int id){

     QSqlQuery query;
         QString res=QString::number(id);


           query.prepare("update CLIENT""  set TYPE=:type, NOM=:nom,PERIODE=:periode,id=:id where ID ='"+res+"' ");


                 query.bindValue(":id", id);
                 query.bindValue(":nom",nom);
                 query.bindValue(":type",type);
                 query.bindValue(":periode",periode);




             return query.exec();

 }

QSqlQueryModel* CLIENT::triNom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("SELECT * FROM CLIENT ORDER BY NOM");
           return model;
}

QSqlQueryModel* CLIENT::triType()
{
    QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("SELECT * FROM CLIENT ORDER BY TYPE");
           return model;
}


