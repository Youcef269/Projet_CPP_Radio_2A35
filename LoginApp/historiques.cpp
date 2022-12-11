#include "historiques.h"

Historiques::Historiques()
{

}


Historiques::Historiques(QString type, QString marque, QString id, QString etat, QString tmp){
    this->type = type;
    this->marque = marque;
    this->id = id;
    this->etat = etat;
    this->tmp = tmp;
}


void Historiques::savemateriel(){
    QFile file ("C:/Users/v i p e r/Desktop/crud/Atelier_Connexion/historique.txt");
    if (!file.open(QIODevice::WriteOnly|  QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&file);
    out.setCodec("UTF-8");
    QString sDate = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss.zzz");
    out << "\n type: "+type + ", marque: " +marque+ ", id: " +id +", etat: " +etat<< "\n" "un nouveau materiel a été ajouter le " +sDate << "\n";
}

void Historiques::saveUpdatemateriel(QString type, QString marque, QString id, QString etat, QString Tmp){
    QFile file ("C:/Users/v i p e r/Desktop/crud/Atelier_Connexion/historique.txt");
    if (!file.open(QIODevice::WriteOnly|  QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&file);
    out.setCodec("UTF-8");
    QString sDate = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss.zzz");
    out << "\n""*****************************************Update********************************";
    out << "\n type: "+type + ", marque: " +marque+ ", id: " +id +", etat: " +etat;
    out << "\n type: "+type + ", marque: " +marque+ ", id: " +id +", etat: " +etat<< "\n" "Ce materiel a été modifié le " +sDate << "\n";
    out <<"*****************************************Update********************************" "\n";

}


void Historiques::saveDeletemateriel(){
    QFile file ("C:/Users/v i p e r/Desktop/crud/Atelier_Connexion/historique.txt");
    if (!file.open(QIODevice::WriteOnly|  QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&file);
    out.setCodec("UTF-8");
    QString sDate = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss.zzz");
    out << "\n type: "+type + ", marque: " +marque+ ", id: " +id +", etat: " +etat<< "\n" "Ce materiel a été supprimé le " +sDate << "\n";

}


