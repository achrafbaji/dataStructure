#ifndef FRACTION_H
#define FRACTION_H


class Fraction{
public:
    Fraction();
    Fraction(int numerateur);
    Fraction(int numerateur, int denominateur);

    double valeur() const;
    void afficher() const;

private:
    int num;
    int den;



};


#endif