#include <iostream>
#include "produit.h"

void afficher(const Produit &p){
    std::cout << p.getCode() << " : " << p.getPrix() << std::endl;
}

void rabais(Produit &p, double pourcent){
    double nouveau = p.getPrix() * (1 - pourcent / 100);
    p.changerPrix(nouveau);

}

int main(int argc, char** argv){
    Produit a(101, 50);
    afficher(a);          // 101 : 50
    rabais(a, 20);
    afficher(a);          // 101 : 40
    return 0;
}