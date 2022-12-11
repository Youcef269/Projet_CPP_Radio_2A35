#include "state.h"
#include <QSqlQuery>
#include <QDebug>
#include<QObject>
state::state()
{
ETAT="";
}
state::state(QString ETAT)
{
    this->ETAT=ETAT;
}

QString state::getetat(){return ETAT;}
void state::setetat(QString ETAT){this->ETAT=ETAT;}

bool state::update(){
    QSqlQuery query;


      query.prepare( "UPDATE state SET ETAT=:ETAT");

   query.bindValue(":ETAT",ETAT);


return query.exec();
}
QString state::afficher()
{
    QSqlQuery query;
       QString k;
    query.prepare("SELECT ETAT FROM state");
    query.bindValue(":ETAT", ETAT);
    while (query.next()) {
    k=query.value(0).toString();
    }
    return k;
}
