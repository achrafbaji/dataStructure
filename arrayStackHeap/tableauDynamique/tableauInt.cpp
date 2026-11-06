#include "tableauInt.h"
#include <cassert>
TableauEntier::TableauEntier(){
    capacite = 4;
    taille = 0;
    tableau = new int[capacite];
}

TableauEntier::~TableauEntier(){
    delete[] tableau;
}

void TableauEntier::ajouter(int nombre){
    if(taille == capacite){
        capacite *= 2;
        int *nouveauTableau = new int[capacite];
        for (int e = 0; e < taille; ++e){
            nouveauTableau[e] = tableau[e];
        }
        delete[] tableau;
        tableau = nouveauTableau;
    }
    tableau[taille++] = nombre;
}

int& TableauEntier::operator[](int indice){
    assert(indice>= 0 && indice < taille);
    return tableau[indice];
}