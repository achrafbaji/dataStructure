#include <iostream>
#include "point.h"

void montrer(const Point& p){

    p.afficher();
    std::cout << " x = " << p.getX() << std::endl;
}


int main(){
    Point a(3, 4);
    Point b(0, 0);

    montrer(a);
    std::cout << " distance = " << a.distance(b) << std::endl;

    a.deplacer(1, -1);
    std::cout << "Apres deplacement : ";
    a.afficher();
    return 0;


    return 0;
}