#ifndef ARBRE_AVL
#define ARBRE_AVL
#include <cassert>

template <class T> class ArbreAVL{
    public:
        ArbreAVL();
        ~ArbreAVL();
        void inserer(const T& element);
        void enlever(const T& element);
        void vider();
        bool contient(const T& element) const;
        bool vide() const;


    private:
    class Noeud{
        public:
            Noeud(const T& element);
            T contenu;
            Noeud *gauche, *droite;
            int equilibre;
            

    };
    Noeud* racine;

    bool inserer(Noeud*& n, const T& element);
    bool enlever(Noeud*& n, const T& element);
    bool contient(Noeud* n, const T& element) const;
    bool equilibrerApresBaisseGauche(Noeud*& n);
    bool equilibrerApresBaisseDroite(Noeud*& n);
    void rotationGaucheDroite(Noeud*& racinesousarbre);
    void rotationDroiteGauche(Noeud*& racinesousarbre);
    void vider(Noeud*& n);
};



template <class T> ArbreAVL<T>::Noeud::Noeud(const T& element) : contenu(element), gauche(nullptr), droite(nullptr), equilibre(0){}

template <class T> ArbreAVL<T>::ArbreAVL(): racine(nullptr) {}

template <class T> ArbreAVL<T>::~ArbreAVL(){ 
    vider(); 
}

// vider() public et privé
template <class T> void ArbreAVL<T>::vider(){
    vider(racine);
}

template <class T> void ArbreAVL<T>::vider(Noeud*& n){
    if(n == nullptr) return;
    vider(n->gauche); // vider tout le sous-arbre gauche
    vider(n->droite);  // puis tout le sous-arbre droit
    delete n;          // puis le noeud lui-meme
    n = nullptr;        // le parent pointe vers rien 
}

// contient() public et privé

//bool contient(const T& element) const;
//bool contient(Noeud* n, const T& element) const;
template <class T> bool ArbreAVL<T>::contient(const T& e) const{
    return contient(racine, e);
}

template <class T> bool ArbreAVL<T>::contient(Noeud* n, const T& e) const {
    if(n == nullptr) return false; 
    if( e < n->contenu) return contient(n->gauche, e);
    if( n->contenu < e) return contient(n->droite, e);
    return true;
    
}

//vide() public et privé
//void vider(Noeud*& n);

template <class T> bool ArbreAVL<T>::vide() const{
    return racine == nullptr;
}



// void rotationGaucheDroite(Noeud*& racinesousarbre);
template <class T> void ArbreAVL<T>::rotationGaucheDroite(Noeud*& racinesousarbre){
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

template <class T> void ArbreAVL<T>::rotationDroiteGauche(Noeud*& racinesousarbre){
    Noeud* a = racinesousarbre->droite;
    Noeud* b = racinesousarbre;

    int ea = a->equilibre;
    int eb = b->equilibre;
    int ebp = -(ea < 0 ? ea : 0) + 1 + eb;
    int eap = ea + (ebp > 0 ? ebp : 0) + 1;
    a->equilibre = eap;
    b->equilibre =ebp;

    b->droite = a->gauche;
    a->gauche = b;
    racinesousarbre = a;
}


//bool inserer(Noeud*& n, const T& element);
//void inserer(const T& element);

template <class T> void ArbreAVL<T>::inserer(const T& e){
    inserer(racine, e);
}

template <class T> bool ArbreAVL<T>::inserer(Noeud*& n, const T& e){
    if(n == nullptr){ n = new Noeud(e); return true; }
        if(n->contenu < e){
        if(inserer(n->droite, e)){
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
    if(e < n->contenu){
        if(inserer(n->gauche, e)){
            n->equilibre++;
            if(n->equilibre == 0) return false;
            if(n->equilibre == 1) return true;
            assert(n->equilibre == 2);
            if(n->gauche->equilibre == -1)
                rotationDroiteGauche(n->gauche);
            rotationGaucheDroite(n);
        }
        return false;
    } 
    else {
        n->contenu = e;
        return false;
    } 
}




template <class T> void ArbreAVL<T>::enlever(const T& e){
    enlever(racine, e);
}

template <class T> bool ArbreAVL<T>::equilibrerApresBaisseGauche(Noeud*& n){
    n->equilibre--;                        
    if(n->equilibre ==  0) return true;    
    if(n->equilibre == -1) return false;   
    assert(n->equilibre == -2);
    int ed = n->droite->equilibre;
    if(ed == 1) rotationGaucheDroite(n->droite);   
    rotationDroiteGauche(n);
    return ed != 0;                        
}

template <class T> bool ArbreAVL<T>::equilibrerApresBaisseDroite(Noeud*& n){
    n->equilibre++;
    if(n->equilibre == 0) return true;
    if(n->equilibre == 1) return false;
    assert(n->equilibre == 2);
    int eg = n->gauche->equilibre;
    if(eg == -1) rotationDroiteGauche(n->gauche);
    rotationGaucheDroite(n);
    return eg != 0;
}


template <class T> bool ArbreAVL<T>::enlever(Noeud*& n, const T& e){
    if(n == nullptr) return false;       

    if(e < n->contenu){
        if(enlever(n->gauche, e)) return equilibrerApresBaisseGauche(n);
        return false;
    }
    if(n->contenu < e){
        if(enlever(n->droite, e)) return equilibrerApresBaisseDroite(n);
        return false;
    }

    
    if(n->gauche == nullptr){ Noeud* t = n; n = n->droite; delete t; return true; }
    if(n->droite == nullptr){ Noeud* t = n; n = n->gauche; delete t; return true; }

    Noeud* max = n->gauche;  
    while(max->droite != nullptr) max = max->droite;
    n->contenu = max->contenu;
    if(enlever(n->gauche, max->contenu)) return equilibrerApresBaisseGauche(n);
    return false;
}
#endif