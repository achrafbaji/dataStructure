#include <iostream>
#include "produit.h"


Produit::Produit(int code, double prix) : code(code), prix(prix){
    if(this->prix <= 0) this->prix = 0;
}


int Produit::getCode() const{
    return code;

}

double Produit::getPrix() const{
    return prix;

}

void Produit::changerPrix(double nouveau){
    prix = nouveau;

}