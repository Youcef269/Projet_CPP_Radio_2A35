#include "invites.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>

#include <QModelIndex>
#include <QPixmap>
#include <QLabel>


invites::invites()

{
ID_INVITE=0;
NOM_INVITE="";
PRENOM_INVITE="";
FONCTION="";
 DATE_INVITE="";
 IMAGE_INV="";
 TYPE="";
}

invites :: invites (int ID_INVITE,QString NOM_INVITE ,QString PRENOM_INVITE,QString FONCTION,QString DATE_INVITE,QString TYPE,QString IMAGE_INV )
{
    this->ID_INVITE=ID_INVITE;
    this->NOM_INVITE=NOM_INVITE;
    this->PRENOM_INVITE=PRENOM_INVITE;
    this->FONCTION=FONCTION;
    this->DATE_INVITE=DATE_INVITE;
    this->IMAGE_INV=IMAGE_INV;
    this->TYPE=TYPE;

}
invites :: invites (int ID_INVITE,QString NOM_INVITE ,QString PRENOM_INVITE,QString FONCTION,QString DATE_INVITE,QString TYPE )
{
    this->ID_INVITE=ID_INVITE;
    this->NOM_INVITE=NOM_INVITE;
    this->PRENOM_INVITE=PRENOM_INVITE;
    this->FONCTION=FONCTION;
    this->DATE_INVITE=DATE_INVITE;
    this->TYPE=TYPE;


}
invites :: invites (int ID_INVITE,QString IMAGE_INV  )
{
    this->ID_INVITE=ID_INVITE;
    this->IMAGE_INV=IMAGE_INV;


}
QString invites::getimage()
{
    return IMAGE_INV;
}
int invites::getid()
{
    return ID_INVITE;
}
QString invites::getnom()
{return NOM_INVITE; }
QString invites::gettype()
{return TYPE; }
QString invites ::getprenom()
{return PRENOM_INVITE; }
void invites::setimage(QString IMAGE_INV)
{ this->IMAGE_INV=IMAGE_INV;
}
void invites::setid(int ID_INVITE)
{this->ID_INVITE=ID_INVITE;}
void invites ::setnom(QString NOM_INVITE)
{this->NOM_INVITE=NOM_INVITE;}
void invites ::setDATE_INVITE(QString DATE_INVITE)
{this->DATE_INVITE=DATE_INVITE;}
void invites::setprenom(QString PRENOM_INVITE)
{ this->PRENOM_INVITE=PRENOM_INVITE;
}
QString invites::getDATE_INVITE()
{return DATE_INVITE; }
QString invites::getfonction()
{return FONCTION; }
void invites::setfonction(QString FONCTION)
{ this->FONCTION=FONCTION;
}
void invites::settype(QString TYPE)
{ this->TYPE=TYPE;
}
bool invites::ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(ID_INVITE);
          query.prepare("INSERT INTO invites (ID_INVITE,NOM_INVITE, PRENOM_INVITE, FONCTION, DATE_INVITE,TYPE) "
                        "VALUES (:id, :forename, :surname, :surname1,:surname2,:surname3)");
          query.bindValue(":id", id_string);
          query.bindValue(":forename", NOM_INVITE);
          query.bindValue(":surname", PRENOM_INVITE);
          query.bindValue(":surname1",FONCTION);
          query.bindValue(":surname2", DATE_INVITE);
          query.bindValue(":surname3", TYPE);
          return  query.exec();

}
bool invites::supprimer(int ID_INVITE)
{
    QSqlQuery query;

          query.prepare("Delete from invites where ID_INVITE=:ID_INVITE");
          query.bindValue(0, ID_INVITE);
          return  query.exec();
}
QSqlQueryModel* invites::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT*  FROM invites");
        /* model->setHeaderData(0, Qt::Horizontal, QObject::tr("identenfiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("fonction"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));*/



    return model;
}
bool invites::update( ){
    QSqlQuery query;
    QString id_string=QString::number(ID_INVITE);
    query.prepare( "UPDATE invites SET ID_INVITE=:ID_INVITE  , NOM_INVITE=:NOM_INVITE  ,"
                     " PRENOM_INVITE=:PRENOM_INVITE , DATE_INVITE=:DATE_INVITE,TYPE=:TYPE, FONCTION=:FONCTION  WHERE ID_INVITE=:ID_INVITE ");
   query.bindValue(":ID_INVITE",id_string);
   query.bindValue(":NOM_INVITE", NOM_INVITE);
   query.bindValue(":PRENOM_INVITE",PRENOM_INVITE);
   query.bindValue(":FONCTION",FONCTION);
   query.bindValue(":DATE_INVITE", DATE_INVITE);
   query.bindValue(":TYPE", TYPE);






return query.exec();
}

QSqlQueryModel* invites::search_invites(QString  chaine_search,QString variable)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    QSqlQuery query;
    if(variable=="ID_INVITE")
     {
     model->setQuery("SELECT * FROM invites WHERE  (ID_INVITE like '"+chaine_search+"%""')  ");
     }
    if(variable=="NOM_INVITE")
     {
     model->setQuery("SELECT * FROM invites WHERE  (NOM_INVITE like '"+chaine_search+"%""')  ");
     }
    if(variable=="PRENOM_INVITE")
     {
     model->setQuery("SELECT * FROM invites WHERE  (PRENOM_INVITE like '"+chaine_search+"%""')  ");
     }
    if(variable=="FONCTION")
     {
     model->setQuery("SELECT * FROM invites WHERE  (FONCTION like '"+chaine_search+"%""')  ");
     }
    if(variable=="DATE_INVITE")
     {
     model->setQuery("SELECT * FROM invites WHERE  (FONCTION like '"+chaine_search+"%""')  ");
     }
    if(variable=="TYPE")
     {
     model->setQuery("SELECT * FROM invites WHERE  (FONCTION like '"+chaine_search+"%""')  ");
     }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_INVITE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_INVITE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_INVITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("FONCTION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_INVITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));

        return  model;
}

QSqlQueryModel* invites::afficher_guest(QString order){
    QSqlQueryModel *model = new QSqlQueryModel();

        if(order=="guest id")
        {
           model->setQuery("select * from INVITES order by ID_INVITE ASC ");
        }
        if(order=="guest name")
        {
            model->setQuery("select * from INVITES order by NOM_INVITE ASC ");
        }
        if(order=="guest function")
        {
            model->setQuery("select * from INVITES order by FONCTION ASC ");
        }

       model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_INVITE"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_INVITE"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_INVITE"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("FONCTION"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("image"));


    return model;


}
bool invites::ajouterimage(int ID_INVITE,QString IMAGE_INV){
    QSqlQuery query;
    QString ID_REP = QString::number(ID_INVITE);

    query.prepare("UPDATE invites SET IMAGE_INV=:IMAGE_INV WHERE ID_INVITE=:ID_INVITE");
    query.bindValue(":ID_INVITE", ID_REP);
    query.bindValue(":IMAGE_INV", IMAGE_INV);

    return query.exec();


}

bool invites::ajouterpath(int ID_INVITE,QString PATH){
    QSqlQuery query;
    QString ID_REP = QString::number(ID_INVITE);

    query.prepare("UPDATE invites SET PATH=:PATH WHERE ID_INVITE=:ID_INVITE");
    query.bindValue(":ID_INVITE", ID_REP);
    query.bindValue(":PATH", PATH);

    return query.exec();


}
bool invites::rechercherinvite(int r){
    bool k=false;
    QSqlQuery query;
    QString Id = QString::number(r);
    query.prepare("select * from invites where ID_INVITE=:ID_INVITE");
    query.bindValue(":ID_INVITE",Id);
    query.exec();
    while (query.next()) {
    k=query.value(0).toBool();
    }

    return  k;
}

QString invites::afficherImage(int ID_INVITE)
{
    QSqlQuery query;
    //QString ID_REP = QString::number(ID_INVITE);
       QString k;
    query.prepare("SELECT PATH FROM INVITES WHERE ID_INVITE=:ID_INVITE");
    query.bindValue(":ID_INVITE", ID_INVITE);
    while (query.next()) {
    k=query.value(0).toString();
    }
    return k;
}




