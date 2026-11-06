#ifndef COMPTE_H
#define COMPTE_H
#include <iostream>


class Compte{
    public:
        Compte(int num = 0, double s = 0 ) : numero(0), solde(s) {}
    private:
        int numero;
        double solde;

        friend std::istream &operator >> (std::istream &is, Compte &c);



};




#endif