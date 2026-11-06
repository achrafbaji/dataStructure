#ifndef ARBRE_BINAIRE
#define ARBRE_BINAIRE

template<class T> class ArbreBinaire{
    public:
        ArbreBinaire();
        ~ArbreBinaire();
        void vider();


    private:
        struct Noeud{
            T contenu;
            Noeud *gauche;
            Noeud *droute;
        };
        Noeud *racine;
        vider(Noeud*); // sa vider(Noeud*)  cest exactement comme sa void vider(Noeud* n); 
};





#endif