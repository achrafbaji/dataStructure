#include <iostream>
#include <cmath>
#include "point.h"

//initialisation du constructeur 
/*
    ici on peut ecrire l'initialisation de deux maniere: 
    1) : x(x_) -> x est creer en valant x_
    2) { x = x_; } -> x est creé vide , puis on lui affecte x_

    si x est const { x = x_; } marche pas parce qu'on doit la modifier aprés (avec le = x_ )
    avec le x(x_) meme avec (ou sans) le const sa marche

*/
Point::Point(double x_, double y_) : x(x_), y(y_){

}


double Point::getX() const { return x; }
double Point::getY() const { return y; }

void Point::deplacer(double dx, double dy){
    x += dx;
    y += dy;
}

// ici l objet lui meme doit rester intacte avec le const de la signiature puis l objet en parametre dois aussi restant constant mais on ne veux pas travailler avec une copie donc on utilise le vrai objet c est pour sa qu on passe la reference & vers l objet 


double Point::distance(const Point& autre) const{
    double dx = autre.x - x;
    double dy = autre.y - y;
    return sqrt(dx*dx + dy*dy);
}

void Point::afficher() const {
    std::cout << "(" << x << "," << y << ")" << std::endl;
}