#include <iostream>
#include "etudiant.h"



int main(int argc, char** argv){

    Etudiant a;
    a.nom = "Achraf";
    a.note = 85.5;

    Etudiant b;
    b.nom = "Soufiane";
    b.note = 91;

    a.afficher();
    b.afficher();
    return 0;
}