#include <iostream>
#include "Compte.h"

Compte::Compte(int numero, double solde) : numero(numero), solde(solde){
    if(this->solde <= 0) this->solde = 0;

}

int Compte::getNumero() const{
    return numero;
}

double Compte::getSolde() const{
    return solde;
}

void Compte::afficher() const{
    std::cout << "le numero de votre compte est: " << numero << " et le solde est " << solde << std::endl;
}

void Compte::deposer(double montant){
    if(montant > 0){
        solde += montant;
    }
}


void Compte::retirer(double montant){
    if(solde >= montant){
        solde -= montant;
    }
}


bool Compte::memeCompte(const Compte& autre) const{
    return this == &autre;

}
