#include <iostream>
#include "Compte.h"
int main(){
    Compte a(1001, 500);
    Compte b(1001, 500);

    Compte &c = a;

    a.afficher();
    a.deposer(200);
    a.retirer(1000);
    a.deposer(-500);
    a.afficher();

    std::cout << "a et b : " << (a.memeCompte(b) ? "meme objet" : "objets differents") << std::endl;
    std::cout << "a et c : " << (a.memeCompte(c) ? "meme objet" : "objets differents") << std::endl;
    std::cout << "a et a : " << (a.memeCompte(a) ? "meme objet" : "objets differents") << std::endl;


    



    return 0;
}
