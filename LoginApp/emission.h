#ifndef EMISSION_H
#define EMISSION_H
#include <QString>

class Emission
{
public:
    Emission();
    Emission(int,QString,QString,QString,QString );

    int getid();
    QString getnom();
    QString gettype();
    QString getduree();
    QString getdate();

    void setid(int);
    void setnom(QString);
    void settype(QString);
    void setduree(QString);
    void setdate(QString);
    bool ajouter();

private:
    int ID_EMISSION;
    QString NOM_EMISSION,TYPE_EMISSION,DUREE_EMISSION,DATE_EMISSION;
};

#endif // EMISSION_H
