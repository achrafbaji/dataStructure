#ifndef PRODUIT_H
#define PRODUIT_H


class Produit{
public:
    Produit(int code, double prix);


    int getCode() const;
    double getPrix() const;
    void changerPrix(double nouveau);

private:
    int code;
    double prix;



};








#endif