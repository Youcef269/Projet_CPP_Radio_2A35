#ifndef INVITES_H
#define INVITES_H
#include<QString>
#include <QSqlQuery>
#include<QVariant>
#include<QSqlQueryModel>
#include <QModelIndex>
class invites
{
public:
    invites();
    invites(int,QString,QString,QString,QString,QString,QString );
    invites(int,QString,QString,QString,QString,QString);
    invites(int,QString);
    invites(int);
    int getid();
    QString getnom();
    QString getprenom();
    QString getimage();
    QString getfonction();
     QString gettype();
    void setid(int);
    void setnom(QString);
    void setimage(QString);
    void setprenom(QString);
    void setfonction(QString);
    void settype(QString);
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficher_guest(QString order);
    bool update();
    QSqlQueryModel* search_invites(QString  ,QString );
    QString getDATE_INVITE();
        void setDATE_INVITE(QString);
        bool rechercherinvite(int );
        bool ajouterimage(int ,QString );
        QSqlQueryModel* afficher_image(int ID_INVITE);
        bool ajouterpath(int ID_INVITE,QString PATH);
        QString afficherImage(int ID_INVITE);
private:
    int ID_INVITE;
    QString NOM_INVITE,PRENOM_INVITE,FONCTION,DATE_INVITE,TYPE,IMAGE_INV;
};

#endif // INVITES_H
