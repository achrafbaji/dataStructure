#include "compte.h"



std::istream &operator >> (std::istream &is, Compte &c){
    is >> c.numero >> c.solde;
    return is;
}