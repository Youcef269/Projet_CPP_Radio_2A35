#ifndef COMPTE_H
#define COMPTE_H
#include<QString>

class compte
{
public:
    void setcompte(QString n);
    QString getcompte();
    compte();
private:
    QString idcompte;
};

#endif // COMPTE_H
