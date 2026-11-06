#ifndef COMPTE_H
#define COMPTE_H
#include <iostream>
class Compte{
    public:
    Compte(int num = 0, double s = 0) : numero(num), solde(0) {}

    private:
    int numero;
    double solde;
    friend std::ostream &operator << (std::ostream &os, const Compte &c);
    




};





#endif