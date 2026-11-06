#ifndef COMPTE_H
#define COMPTE_H
class Compte{
public:

    Compte(int numero, double solde);

    int getNumero() const;
    double getSolde() const;
    void afficher() const;

    void deposer(double montant);
    void retirer(double montant);

    bool memeCompte(const Compte& autre) const;

    


    
private:
    int numero;
    double solde;



};


#endif