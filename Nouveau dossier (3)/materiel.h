#ifndef materiel_H
#define materiel_H
#include<QString>
#include<QSqlQueryModel>
class materiel
{
public:
    materiel();
    materiel(QString ,QString, QString ,QString );
    QString gettype();
    QString getmarque();
    QString getid();
    QString getetat();
    void settype(QString);
    void setmarque(QString);
    void setid(QString);
    void setetat(QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprime(QString);
     bool modifier(QString);

     QSqlQueryModel *triermateriel(QString test);
     int statistiquemateriel(QString etat);
     QSqlQueryModel * recherchermateriel(QString chaine);
     QSqlQuery afficher(QString id);

     int materielachet();
     QSqlQuery materielachetDetails();


private:
    QString type , marque , id , etat ;
};

#endif // materiel_H
