#include <iostream>
#include "fraction.h"

int main(int argc, char** argv){

    
    Fraction a;
    Fraction b(7);
    Fraction c(3, 4);
    Fraction d(1, 0);
    Fraction e(2, -5);


    a.afficher();
    b.afficher();
    c.afficher();
    d.afficher();
    e.afficher();

    return 0;
}