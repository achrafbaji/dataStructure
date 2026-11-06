#ifndef ARBREAVL_H
#define ARBREAVL_H
#include <cassert>

template <class T>
class ArbreAVL{
  public:
    ArbreAVL();
    ~ArbreAVL();
    bool contient(const T& element) const;
    void inserer(const T& element);
    void enlever(const T& element);
    bool vide() const;
    int  hauteur() const;
  private:
    class Noeud{
      public:
        Noeud(const T& element);
        T contenu;
        Noeud *gauche, *droite;
        int equilibre;                 // hg - hd
    };
    Noeud* racine;

    const T* rechercher(Noeud* n, const T& element) const;
    bool inserer(Noeud*& n, const T& element);   // true si le sous-arbre a GRANDI
    bool enlever(Noeud*& n, const T& element);   // true si le sous-arbre a RETRECI
    bool equilibrerApresBaisseGauche(Noeud*& n);
    bool equilibrerApresBaisseDroite(Noeud*& n);
    void rotationGaucheDroite(Noeud*& racinesousarbre);
    void rotationDroiteGauche(Noeud*& racinesousarbre);
    void vider(Noeud*& n);
    int  hauteur(Noeud* n) const;
};

template <class T>
ArbreAVL<T>::Noeud::Noeud(const T& element)
 : contenu(element), gauche(nullptr), droite(nullptr), equilibre(0) {}

template <class T>
ArbreAVL<T>::ArbreAVL() : racine(nullptr) {}
template <class T>
ArbreAVL<T>::~ArbreAVL(){ vider(racine); }
template <class T>
bool ArbreAVL<T>::vide() const { return racine == nullptr; }

// ---------------- recherche : identique a l'ABR ----------------
template <class T>
bool ArbreAVL<T>::contient(const T& element) const {
    return rechercher(racine, element) != nullptr;
}
template <class T>
const T* ArbreAVL<T>::rechercher(Noeud* n, const T& element) const {
    if(n == nullptr) return nullptr;
    if(element < n->contenu) return rechercher(n->gauche, element);
    if(n->contenu < element) return rechercher(n->droite, element);
    return &(n->contenu);
}

// ---------------- rotations ----------------
template <class T>
void ArbreAVL<T>::rotationGaucheDroite(Noeud*& racinesousarbre){
    Noeud* a = racinesousarbre->gauche;
    Noeud* b = racinesousarbre;
    int ea = a->equilibre;
    int eb = b->equilibre;
    int ebp = -(ea > 0 ? ea : 0) - 1 + eb;
    int eap = ea + (ebp < 0 ? ebp : 0) - 1;
    a->equilibre = eap;
    b->equilibre = ebp;
    b->gauche = a->droite;
    a->droite = b;
    racinesousarbre = a;
}

template <class T>
void ArbreAVL<T>::rotationDroiteGauche(Noeud*& racinesousarbre){
    Noeud* a = racinesousarbre->droite;
    Noeud* b = racinesousarbre;
    int ea = a->equilibre;
    int eb = b->equilibre;
    int ebp = -(ea < 0 ? ea : 0) + 1 + eb;
    int eap = ea + (ebp > 0 ? ebp : 0) + 1;
    a->equilibre = eap;
    b->equilibre = ebp;
    b->droite = a->gauche;
    a->gauche = b;
    racinesousarbre = a;
}

// ---------------- insertion ----------------
template <class T>
void ArbreAVL<T>::inserer(const T& element){ inserer(racine, element); }

template <class T>
bool ArbreAVL<T>::inserer(Noeud*& n, const T& element){
    if(n == nullptr){
        n = new Noeud(element);
        return true;                            // la hauteur a augmente
    }
    if(element < n->contenu){                   // ---- cas de GAUCHE ----
        if(inserer(n->gauche, element)){
            n->equilibre++;
            if(n->equilibre == 0) return false; // meme hauteur
            if(n->equilibre == 1) return true;  // a grandi
            assert(n->equilibre == 2);          // reequilibrage requis
            if(n->gauche->equilibre == -1)      // signes opposes -> double rotation
                rotationDroiteGauche(n->gauche);
            rotationGaucheDroite(n);
        }
        return false;
    }
    else if(n->contenu < element){              // ---- cas de DROITE (symetrique) ----
        if(inserer(n->droite, element)){
            n->equilibre--;
            if(n->equilibre ==  0) return false;
            if(n->equilibre == -1) return true;
            assert(n->equilibre == -2);
            if(n->droite->equilibre == 1)
                rotationGaucheDroite(n->droite);
            rotationDroiteGauche(n);
        }
        return false;
    }
    else{                                       // deja present
        n->contenu = element;
        return false;
    }
}

// ---------------- enlevement ----------------
template <class T>
void ArbreAVL<T>::enlever(const T& element){ enlever(racine, element); }

template <class T>
bool ArbreAVL<T>::equilibrerApresBaisseGauche(Noeud*& n){   // le sous-arbre GAUCHE a retreci
    n->equilibre--;
    if(n->equilibre ==  0) return true;        // n a retreci
    if(n->equilibre == -1) return false;       // hauteur inchangee
    assert(n->equilibre == -2);
    int ed = n->droite->equilibre;
    if(ed == 1) rotationGaucheDroite(n->droite);
    rotationDroiteGauche(n);
    return ed != 0;                            // enfant a 0 -> hauteur inchangee
}

template <class T>
bool ArbreAVL<T>::equilibrerApresBaisseDroite(Noeud*& n){   // le sous-arbre DROIT a retreci
    n->equilibre++;
    if(n->equilibre == 0) return true;
    if(n->equilibre == 1) return false;
    assert(n->equilibre == 2);
    int eg = n->gauche->equilibre;
    if(eg == -1) rotationDroiteGauche(n->gauche);
    rotationGaucheDroite(n);
    return eg != 0;
}

template <class T>
bool ArbreAVL<T>::enlever(Noeud*& n, const T& element){
    if(n == nullptr) return false;
    if(element < n->contenu){
        if(enlever(n->gauche, element)) return equilibrerApresBaisseGauche(n);
        return false;
    }
    if(n->contenu < element){
        if(enlever(n->droite, element)) return equilibrerApresBaisseDroite(n);
        return false;
    }
    // element trouve
    if(n->gauche == nullptr){ Noeud* t = n; n = n->droite; delete t; return true; }
    if(n->droite == nullptr){ Noeud* t = n; n = n->gauche; delete t; return true; }
    Noeud* max = n->gauche;                    // max du sous-arbre gauche
    while(max->droite != nullptr) max = max->droite;
    n->contenu = max->contenu;
    if(enlever(n->gauche, max->contenu)) return equilibrerApresBaisseGauche(n);
    return false;
}

template <class T>
int ArbreAVL<T>::hauteur() const { return hauteur(racine); }
template <class T>
int ArbreAVL<T>::hauteur(Noeud* n) const {
    if(n == nullptr) return 0;
    int g = hauteur(n->gauche), d = hauteur(n->droite);
    return (g > d ? g : d) + 1;
}
template <class T>
void ArbreAVL<T>::vider(Noeud*& n){
    if(n == nullptr) return;
    vider(n->gauche);
    vider(n->droite);
    delete n;
    n = nullptr;
}

#endif
