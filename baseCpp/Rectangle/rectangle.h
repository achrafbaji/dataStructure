#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle {
public:
    Rectangle(); // constructeur par defaut 1 x 1 
    Rectangle(double largeur, double hauteur); // constructeur avec parametres
    

    

    void afficher() const;

    double air() const;
    double perimetre() const;
    bool estCarre() const;


    double gethauteur() const;
    double getlargeur() const;




private:

    double hauteur;
    double largeur;




};


#endif