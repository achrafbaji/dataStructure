#ifndef ARBREB_H
#define ARBREB_H
#include <cassert>

template <class T>
class ArbreB{
    public:
        ArbreB(int ordre);
        ~ArbreB();

        bool estVide() const;
        bool contient(const T& element) const;
        void inserer(const T& element);
        void enlever(const T& element);
    
    private:
        
        struct Noeud{
            Noeud(int ordre);
            ~Noeud();
            int nbCles;// variable pour savoir combien de case sont prise elle ne sert pas a connaitre le nbCles dispo vu qu on peut les deduire avec m-1 
            T* cles; // tableau de taille m-1 cles trieés
            Noeud** enfants; // un tableau de pointeurs qui pointent vert des noeuds
        };

        int ordre; // m
        Noeud* racine;


        void vider(Noeud* n);

        // pour inserer
        bool inserer(Noeud* n, const T& cle, T& monte, Noeud*& nouveau);
        bool insererDansNoeud(Noeud* n, int pos, const T& cle, Noeud* droite, T& monte, Noeud*& nouveau);

        // pour enlever
        int  minCles() const;
        void enlever(Noeud* n, const T& cle);
        void reequilibrer(Noeud* parent, int i);
        void fusionner(Noeud* parent, int k);


};


//Noeud(int ordre);
template <class T> ArbreB<T>::Noeud::Noeud(int ordre) : nbCles(0){
    cles = new T[ordre - 1];
    enfants = new Noeud*[ordre];
    for(int i = 0; i < ordre ; ++i)
        enfants[i] = nullptr;
}

// destructeur du noeud
template <class T>
ArbreB<T>::Noeud::~Noeud(){
    delete[] cles;
    delete[] enfants;
}

//ArbreB(int ordre);
template <class T>
ArbreB<T>::ArbreB(int ordre) : ordre(ordre), racine(nullptr){}

//~
template <class T> 
ArbreB<T>::~ArbreB(){
    vider(racine);
}

template <class T>
void ArbreB<T>::vider(Noeud* n){
    if(n == nullptr) return;
    for(int i = 0; i <= n->nbCles; ++i)
        vider(n->enfants[i]);
    delete n;
}


// estVide

template <class T>
bool ArbreB<T>::estVide() const{
    return racine == nullptr;
}

// contient

template <class T>
bool ArbreB<T>::contient(const T& cle) const{
    Noeud* n = racine;
    while(n != nullptr){
        int i = 0;
        while(i < n->nbCles && n->cles[i] < cle)      // première clé >= cle
            i++;
        if(i < n->nbCles && !(cle < n->cles[i]))      // cles[i] == cle
            return true;
        n = n->enfants[i];                           
    }
    return false;                                     
}

//inserer

template <class T>
void ArbreB<T>::inserer(const T& cle){
    if(racine == nullptr){                            // arbre vide un seul noeud, une seule clé
        racine = new Noeud(ordre);
        racine->cles[0] = cle;
        racine->nbCles = 1;
        return;
    }
    T monte;
    Noeud* nouveau = nullptr;
    if(inserer(racine, cle, monte, nouveau)){         // la racine s'est coupée en deux
        Noeud* r = new Noeud(ordre);                  // nouvelle racine l'arbre grandit par le haut
        r->cles[0] = monte;
        r->enfants[0] = racine;
        r->enfants[1] = nouveau;
        r->nbCles = 1;
        racine = r;
    }
}

// retourne true si n s'est coupé monte = clé médiane, nouveau = moitié droite
template <class T>
bool ArbreB<T>::inserer(Noeud* n, const T& cle, T& monte, Noeud*& nouveau){
    int i = 0;
    while(i < n->nbCles && n->cles[i] < cle)
        i++;
    if(i < n->nbCles && !(cle < n->cles[i]))          // déjà présente : rien à faire
        return false;

    if(n->enfants[0] == nullptr)                     
        return insererDansNoeud(n, i, cle, nullptr, monte, nouveau);

    T monteEnfant;
    Noeud* nouveauEnfant = nullptr;
    if(!inserer(n->enfants[i], cle, monteEnfant, nouveauEnfant))
        return false;                                 // l'enfant ne s'est pas coupé
    // l'enfant s'est coupé : sa médiane monte dans n, à la position i
    return insererDansNoeud(n, i, monteEnfant, nouveauEnfant, monte, nouveau);
}

// insère cle à la position pos de n droite devient l'enfant à droite de cle
template <class T>
bool ArbreB<T>::insererDansNoeud(Noeud* n, int pos, const T& cle, Noeud* droite, T& monte, Noeud*& nouveau){
    if(n->nbCles < ordre - 1){                        
        for(int j = n->nbCles; j > pos; j--){         
            n->cles[j] = n->cles[j - 1];
            n->enfants[j + 1] = n->enfants[j];
        }
        n->cles[pos] = cle;
        n->enfants[pos + 1] = droite;
        n->nbCles++;
        return false;
    }

    // noeud plein : on forme temporairement les m clés et m + 1 enfants
    T* tc = new T[ordre];
    Noeud** te = new Noeud*[ordre + 1];
    te[0] = n->enfants[0];
    for(int j = 0, k = 0; j < ordre; j++){
        if(j == pos){ tc[j] = cle; te[j + 1] = droite; }
        else        { tc[j] = n->cles[k]; te[j + 1] = n->enfants[k + 1]; k++; }
    }

    int milieu = ordre / 2;                
    monte = tc[milieu];

    n->nbCles = milieu;                               
    for(int j = 0; j < milieu; j++){
        n->cles[j] = tc[j];
        n->enfants[j] = te[j];
    }
    n->enfants[milieu] = te[milieu];
    for(int j = milieu + 1; j < ordre; j++)
        n->enfants[j] = nullptr;

    nouveau = new Noeud(ordre);                      
    nouveau->nbCles = ordre - 1 - milieu;
    for(int j = 0; j < nouveau->nbCles; j++){
        nouveau->cles[j] = tc[milieu + 1 + j];
        nouveau->enfants[j] = te[milieu + 1 + j];
    }
    nouveau->enfants[nouveau->nbCles] = te[ordre];

    delete[] tc;
    delete[] te;
    return true;
}

// enlever

template <class T>
int ArbreB<T>::minCles() const{
    return (ordre + 1) / 2 - 1;                       // ⌈m/2⌉ - 1
}

template <class T>
void ArbreB<T>::enlever(const T& cle){
    if(racine == nullptr) return;
    enlever(racine, cle);
    if(racine->nbCles == 0){                     
        Noeud* ancienne = racine;
        racine = racine->enfants[0];               
        delete ancienne;
    }
}

template <class T>
void ArbreB<T>::enlever(Noeud* n, const T& cle){
    int i = 0;
    while(i < n->nbCles && n->cles[i] < cle)
        i++;
    bool trouvee = i < n->nbCles && !(cle < n->cles[i]);

    if(n->enfants[0] == nullptr){                     
        if(!trouvee) return;                          
        for(int j = i; j < n->nbCles - 1; j++)       
            n->cles[j] = n->cles[j + 1];
        n->nbCles--;
        return;
    }

    if(trouvee){
        
        Noeud* p = n->enfants[i];
        while(p->enfants[p->nbCles] != nullptr)
            p = p->enfants[p->nbCles];
        T predecesseur = p->cles[p->nbCles - 1];
        n->cles[i] = predecesseur;
        enlever(n->enfants[i], predecesseur);       
    }
    else
        enlever(n->enfants[i], cle);

    if(n->enfants[i]->nbCles < minCles())            
        reequilibrer(n, i);
}

// l'enfant i de parent a une clé de trop peu, emprunter à un frère, sinon fusionner
template <class T>
void ArbreB<T>::reequilibrer(Noeud* parent, int i){
    Noeud* c = parent->enfants[i];

    if(i > 0 && parent->enfants[i - 1]->nbCles > minCles()){
        
        Noeud* g = parent->enfants[i - 1];
        for(int j = c->nbCles; j > 0; j--)
            c->cles[j] = c->cles[j - 1];
        for(int j = c->nbCles + 1; j > 0; j--)
            c->enfants[j] = c->enfants[j - 1];
        c->cles[0] = parent->cles[i - 1];
        c->enfants[0] = g->enfants[g->nbCles];
        c->nbCles++;
        parent->cles[i - 1] = g->cles[g->nbCles - 1];
        g->enfants[g->nbCles] = nullptr;
        g->nbCles--;
    }
    else if(i < parent->nbCles && parent->enfants[i + 1]->nbCles > minCles()){
        
        Noeud* d = parent->enfants[i + 1];
        c->cles[c->nbCles] = parent->cles[i];
        c->enfants[c->nbCles + 1] = d->enfants[0];
        c->nbCles++;
        parent->cles[i] = d->cles[0];
        for(int j = 0; j < d->nbCles - 1; j++)
            d->cles[j] = d->cles[j + 1];
        for(int j = 0; j < d->nbCles; j++)
            d->enfants[j] = d->enfants[j + 1];
        d->enfants[d->nbCles] = nullptr;
        d->nbCles--;
    }
    else if(i > 0)
        fusionner(parent, i - 1);                   
    else
        fusionner(parent, i);                        
}

// fusionne enfants[k] et enfants[k+1] ; la clé k du parent descend entre les deux
template <class T>
void ArbreB<T>::fusionner(Noeud* parent, int k){
    Noeud* g = parent->enfants[k];
    Noeud* d = parent->enfants[k + 1];

    g->cles[g->nbCles] = parent->cles[k];
    for(int j = 0; j < d->nbCles; j++)
        g->cles[g->nbCles + 1 + j] = d->cles[j];
    for(int j = 0; j <= d->nbCles; j++)
        g->enfants[g->nbCles + 1 + j] = d->enfants[j];
    g->nbCles += 1 + d->nbCles;

    for(int j = k; j < parent->nbCles - 1; j++){      
        parent->cles[j] = parent->cles[j + 1];
        parent->enfants[j + 1] = parent->enfants[j + 2];
    }
    parent->enfants[parent->nbCles] = nullptr;
    parent->nbCles--;

    delete d;                                       
}


#endif
