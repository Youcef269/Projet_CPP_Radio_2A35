#include "employe.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
Employe::Employe()
{
id=0; nom=" "; prenom="";numtel=0;

}

 Employe::Employe(int id,QString nom,QString prenom,int numtel)
 {this->id=id; this->nom=nom; this->prenom=prenom;this->numtel=numtel;}
 int Employe::getid(){return id;}
 QString Employe::getnom(){return nom;}
 QString Employe::getprenom(){return prenom;}
 int Employe::getnumtel(){return numtel;}
 void Employe::setnumtel(int numtel){this->numtel=numtel;}
 void Employe::setid(int id){this->id=id;}
 void Employe::setnom(QString nom){this->nom=nom;}
 void Employe::setprenom(QString prenom){this->prenom=prenom;}



 bool Employe::ajouter()
 {

     QSqlQuery query;
   //  QString id_string= QString::number(id);
          query.prepare("INSERT INTO TABLE1 (id, nom, prenom,numtel) "
                        "VALUES (:id, :nom, :prenom,:numtel)");
          query.bindValue(":id", id);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":numtel", numtel);

        return  query.exec();


 }

 bool Employe::supprimer(int id)
 {
     QSqlQuery query;
     query.prepare("Delete from TABLE1 where id=:id ");
     query.bindValue(":id", id);
  return   query.exec();



 }
 bool Employe::modifier(int id,QString nom,QString prenom,int numtel)
 {
     QSqlQuery query;
     query.prepare("update  TABLE1 set  nom=:nom, prenom=:prenom,numtel=:numtel where id=:id " );
     query.bindValue(":id", id);
     query.bindValue(":nom", nom);
     query.bindValue(":prenom", prenom);
     query.bindValue(":numtel", numtel);

   return  query.exec();
 }

 QSqlQueryModel * Employe ::afficheract()
 {

     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("select * from TABLE1");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMTEL "));



         return model;
 }
