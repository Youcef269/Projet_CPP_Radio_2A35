#ifndef HISTORIQUES_H
#define HISTORIQUES_H

#include<QString>
#include<QMessageBox>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>


class Historiques
{
    QString type;
    QString marque;
    QString id;
    QString etat ;
    QString tmp;
public:
    Historiques();
    Historiques(QString type, QString marque, QString id, QString etat, QString tmp);

    void savemateriel();
    QString loadmateriels();
    void saveUpdatemateriel(QString type, QString marque, QString id, QString etat, QString tmp);
    void saveDeletemateriel();
};

#endif // HISTORIQUES_H
