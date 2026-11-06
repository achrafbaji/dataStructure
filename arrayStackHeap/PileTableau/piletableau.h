#ifndef PILE_TABLEAU_H
#define PILE_TABLEAU_H
#include "../tableauGénerique/TableauGénerique.h"

template <class T>
    class PileTableau{
        public: 
            PileTableau();
            ~PileTableau();
            int taille() const;
            bool estVide() const;
            const T& sommet() const;
            T depiler();
            
        private:
            Tableau<T> tableau;
    };


template <class T> int PileTableau<T>::taille() const {
    return tableau.nbElement;
}
template <class T> bool PileTableau<T>::estVide() const{
    return tableau.nbElement == 0;
}

template <class T> const T& PileTableau<T>::sommet() const{
    return tableau[tableau.nbElement-1];
}

template <class T> T PileTableau<T>:: depiler() {
    T resultat = sommet();
    tableau.enlever(tableau.taille() - 1);
}

#endif
