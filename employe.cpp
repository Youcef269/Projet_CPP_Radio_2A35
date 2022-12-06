#include "employe.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
#include<QMessageBox>
#include "notification.h"
Employe::Employe()
{
id=0; nom=" "; prenom="";numtel=0;

}

 Employe::Employe(int id,QString nom,QString prenom,int numtel,int age)
 {this->id=id; this->nom=nom; this->prenom=prenom;this->numtel=numtel;this->age=age;}
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
          query.prepare("INSERT INTO TABLE1 (id, nom, prenom,numtel,age) "
                        "VALUES (:id, :nom, :prenom,:numtel,:age)");
          query.bindValue(":id", id);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":numtel", numtel);
          query.bindValue(":age", age);

        return  query.exec();


 }

 bool Employe::supprimer(int id)
 {
     QSqlQuery query;
     query.prepare("Delete from TABLE1 where id=:id ");
     query.bindValue(":id", id);
  return   query.exec();



 }
 bool Employe::modifier(int id,QString nom,QString prenom,int numtel,int age)
 {
     QSqlQuery query;
     query.prepare("update  TABLE1 set  nom=:nom, prenom=:prenom,numtel=:numtel ,age=:age where id=:id " );
     query.bindValue(":id", id);
     query.bindValue(":nom", nom);
     query.bindValue(":prenom", prenom);
     query.bindValue(":numtel", numtel);
     query.bindValue(":age", age);

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
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("age "));




         return model;
 }




 QSqlQueryModel * Employe::recherche(QString cls)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("select * FROM TABLE1 WHERE ID LIKE '%"+cls+"%'");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMTEL"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
 return model;
 }

 void  Employe::genererPDF(){
     QPdfWriter pdf("C:\\Users\\Yasmine\\Downloads\\pdf.pdf");
     QPainter painter(&pdf);
    int i = 4000;
         painter.setPen(Qt::black);
         painter.setFont(QFont("Arial", 50));
         painter.drawText(1100,1200,"Liste Des employés");
         painter.setPen(Qt::black);
         painter.setFont(QFont("Arial", 15));
         painter.drawRect(100,100,7300,2600);
         painter.drawRect(0,3000,9600,500);
         painter.setFont(QFont("Arial", 9));
         painter.drawText(200,3300,"ID ");
         painter.drawText(1300,3300,"NOM");
         painter.drawText(2400,3300,"PRENOM");
            painter.drawText(3500,3300,"NUMTEL");


         QSqlQuery query;
         query.prepare("select * from TABLE1");
         query.exec();
         while (query.next())
         {
             painter.drawText(200,i,query.value(0).toString());
             painter.drawText(1300,i,query.value(1).toString());
             painter.drawText(2400,i,query.value(2).toString());
             painter.drawText(3500,i,query.value(3).toString());



            i = i + 500;
         }


             QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

             notifyIcon->show();
             notifyIcon->showMessage("ALERTE NOTIF ","Un PDF a été crée",QSystemTrayIcon::Information,15000);


 }

 QSqlQueryModel*  Employe::tri(QString colone, QString ordre)
 {
 QSqlQueryModel* model=new QSqlQueryModel();
 model->setQuery("select * from table1 order by "+colone+" "+ordre+"");
 return model;
 }

