#include <iostream>
#include "rectangle.h"
int main(){

    Rectangle r(2, 4);
    r.afficher();

    Rectangle r1;
    r1.afficher();

    Rectangle r2(-1, -3);
    r2.afficher();

    return 0;
}
