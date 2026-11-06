#ifndef POINT_H
#define POINT_H

class Point {

public: //interface

    Point(double x, double y); // constructeur

    //getter
    double getX() const;        
    double getY() const;

    //setter
    void deplacer(double dx, double dy);

    // le (const Point& autre) protege le b 
    // le double distance x const protege le a
    // le Point& on travail sur l objet lui meme et non sa copie 

    double distance(const Point& autre) const;
    
    void afficher() const;

private:

    double x;
    double y;














};


#endif