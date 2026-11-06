#include <iostream>
#include "fraction.h"


Fraction::Fraction() : num(0), den(1)
{

}


Fraction::Fraction(int numerateur) : num(numerateur), den(1)
{


}

Fraction::Fraction(int numerateur, int denominateur) : num(numerateur), den(denominateur)
{
    if(den == 0) den = 1;
    if(den < 0) { num = -num; den = -den; }

}

double Fraction::valeur() const { return (double)num / den; }

void Fraction::afficher() const {
    std::cout << num << "/" << den << "  = " << valeur() << std::endl;
}