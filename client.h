#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class CLIENT
{
    int id;
    QString nom,type,periode;
public:
    CLIENT();
    CLIENT(int,QString,QString,QString);

    int getid();
    QString getnom();
    QString gettype();
    QString getperiode();

    void setid(int);
    void setnom(QString);
    void settype(QString);
    void setperiode(QString);
    bool ajouter();

QSqlQueryModel* afficher();
QSqlQueryModel* rechercherdynamique(QString ,QString );

    bool supprimer(int);
    bool modifier(int id);
  QSqlQueryModel * triNom();
  QSqlQueryModel * triType();


};

#endif // CLIENT_H
