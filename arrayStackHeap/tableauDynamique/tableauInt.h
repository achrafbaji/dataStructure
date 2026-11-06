#ifndef TABLEAU_H
#define TABLEAU_H

class TableauEntier{
    public:
        TableauEntier();
        ~TableauEntier();
        void ajouter(int nombre);
        int& operator[](int indice);

    private:
        int taille;
        int capacite;
        int *tableau;





};






#endif
