#include "materiel.h"
#include<QSqlQuery>
#include<QtDebug>
#include "QMessageBox"
materiel::materiel()
{
    id="";
    marque="";
    type="";
    etat="";
}
materiel::materiel (QString type ,QString marque, QString id,QString etat)
{
    this->type=type;this->marque=marque;this->id=id;this->etat=etat;
}
void materiel::setid(QString n){id=n;}
void materiel::setmarque(QString n){marque=n;}
void materiel::settype(QString n){type=n;}
void materiel::setetat(QString n){etat=n;}


QString materiel::getid(){return id;}
QString materiel::getmarque(){return marque;}
QString materiel::gettype(){return type;}
QString materiel::getetat(){return etat;}



bool materiel::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO materiel (type, marque, id,etat) "
                  "VALUES (:type, :marque, :id,:etat)");
    query.bindValue(":type", type);
    query.bindValue(":marque", marque);
    query.bindValue(":id", id);
    query.bindValue(":etat", etat);
    return query.exec();

}


bool materiel:: supprime(QString id)
{
    QSqlQuery query;
    query.prepare("Delete from materiel where id=:id");
    query.bindValue(":id",id);
    return query.exec();
    }

QSqlQueryModel * materiel::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select *from materiel");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("marque"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("etat"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("type"));
    return model;

}

bool materiel::modifier(QString ){

    QSqlQuery query;


          query.prepare("UPDATE materiel "" SET id=:id, type=:type, marque=:marque, etat=:etat"
                        " where id=:id ");


                query.bindValue(":id", id);
                query.bindValue(":type", type);
                query.bindValue(":marque", marque);
                query.bindValue(":etat", etat);

            return query.exec();

}

//**************************trie*******************************************
QSqlQueryModel * materiel::triermateriel(QString test)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    if(test == "par défaut"){
        model->setQuery("SELECT * from materiel");
    }
    else if(test =="type")
    {
        model->setQuery("SELECT * from materiel order by type asc ");
    }
    else if(test =="marque")
    {
        model->setQuery("SELECT * from materiel order by marque asc ");
    }
    return model;
}

//*******************************statistique materiel********************************************************

int materiel::statistiquemateriel(QString etat)
{
    QSqlQuery query;
    query.prepare("select count(*) from materiel where etat=:etat ");
    query.bindValue(":etat",etat);
    query.exec();

    int count =-1;

            while(query.next())
                    {
                        count = query.value(0).toInt();
                    }

    return count;

}

//**************************recherche*****************************
QSqlQueryModel * materiel::recherchermateriel(QString chaine)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from materiel where ( type LIKE'%"+chaine+"%' OR marque LIKE'%"+chaine+"%' OR etat LIKE'%"+chaine+"%' OR id LIKE'%"+chaine+"%') ");


    return model ;
}



QSqlQuery materiel::afficher(QString id)
{
    QSqlQuery query;
        query.prepare("select * from materiel where id=:id ");
        query.bindValue(":id",id);

        query.exec();
        return query;

}

















