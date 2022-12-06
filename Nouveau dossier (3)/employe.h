#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Employe
{
public:
    Employe();
    Employe(int,QString,QString,int,int);
    int getid();
    QString getnom();
    int getnumtel();
    QString getprenom();
    void setnumtel(int);
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    bool ajouter();
    QSqlQueryModel * afficheract();
    bool supprimer(int);
    bool modifier(int,QString,QString,int,int);
    //QSqlQueryModel * trier();
    QSqlQueryModel* tri(QString,QString);
    QSqlQueryModel * recherche(QString);
void genererPDF();
private:
    int id;
    int numtel;
    int age;
    QString nom,prenom;
};

#endif // EMPLOYE_H
