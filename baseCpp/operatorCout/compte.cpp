#include "compte.h"



std::ostream &operator << (std::ostream &os, const Compte &c){
    os << "compte #" << c.numero << " : " << c.solde << " $";
    return os;
}