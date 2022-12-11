#ifndef STATE_H
#define STATE_H
#include <QString>
#include <QSqlQuery>

class state
{
public:
    state();
    state(QString);
    QString getetat();
    void setetat(QString);
    bool update();
    QString afficher();

private:
    QString ETAT;
};

#endif // STATE_H
