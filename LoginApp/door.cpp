#include "door.h"

door::door()
{
etat1="";
}
void door::setdoor(QString n){etat1=n;}
QString door::getdoor(){return etat1;}
