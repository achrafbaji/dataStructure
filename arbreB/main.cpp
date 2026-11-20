#include <iostream>
#include "arbreB.h"

int main(){
    ArbreB<int> arbre(5);                       // arbre B d'ordre 5

    for(int i = 1; i <= 10; i++)
        arbre.inserer(i);

    std::cout << arbre.contient(7)  << std::endl;   
    arbre.enlever(7);
    std::cout << arbre.contient(7)  << std::endl;   
    std::cout << arbre.estVide()    << std::endl;   
    return 0;
}