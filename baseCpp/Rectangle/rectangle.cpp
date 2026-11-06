#include <iostream>
#include "rectangle.h"


// le constructeur par defaut
Rectangle::Rectangle() : hauteur(1), largeur(1) {}


// le constructeur qui prend les parametres/ prend ce qu il recoit
// les parametres sont suffixes par _ pour ne PAS masquer les attributs
Rectangle::Rectangle(double hauteur, double largeur) : hauteur(hauteur), largeur(largeur) {
    if(hauteur <= 0) this->hauteur = 1;
    if(largeur <= 0) this->largeur = 1;
}


double Rectangle::perimetre() const{
    return 2 * (largeur + hauteur );
}

double Rectangle::air() const{

    return largeur * hauteur;
}

bool Rectangle::estCarre() const{
    return largeur == hauteur;
}

double Rectangle::gethauteur() const{
    return hauteur;
}

double Rectangle::getlargeur() const{
    return largeur;
}



void Rectangle::afficher() const{
    std::cout << "la hauteur est : " << gethauteur()
              << " et la largeur est : " << getlargeur() << std::endl;
    std::cout << "   aire      : " << air() << std::endl;
    std::cout << "   perimetre : " << perimetre() << std::endl;
    std::cout << "   carre     : " << (estCarre() ? "oui" : "non") << std::endl;
}
