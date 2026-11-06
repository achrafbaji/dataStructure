#ifndef ARBREBINRECH_H
#define ARBREBINRECH_H

template <class T>
class ArbreBinRech{
  public:
    ArbreBinRech();
    ~ArbreBinRech();
    bool     contient(const T& element) const;
    void     inserer(const T& element);
    void     enlever(const T& element);
    bool     vide() const;
    int      hauteur() const;
  private:
    class Noeud{
      public:
        Noeud(const T& element);
        T contenu;
        Noeud *gauche, *droite;
    };
    Noeud* racine;

    const T* rechercher(Noeud* noeud, const T& element) const;
    void     inserer(Noeud*& noeud, const T& element);
    void     enlever(Noeud*& noeud, const T& element);
    void     vider(Noeud*& noeud);
    int      hauteur(Noeud* noeud) const;
};

template <class T>
ArbreBinRech<T>::Noeud::Noeud(const T& element)
 : contenu(element), gauche(nullptr), droite(nullptr) {}

template <class T>
ArbreBinRech<T>::ArbreBinRech() : racine(nullptr) {}

template <class T>
ArbreBinRech<T>::~ArbreBinRech(){ vider(racine); }

template <class T>
bool ArbreBinRech<T>::vide() const { return racine == nullptr; }

// ---------------- recherche ----------------
template <class T>
bool ArbreBinRech<T>::contient(const T& element) const {
    return rechercher(racine, element) != nullptr;
}
template <class T>
const T* ArbreBinRech<T>::rechercher(Noeud* noeud, const T& element) const {
    if(noeud == nullptr) return nullptr;
    if(element < noeud->contenu) return rechercher(noeud->gauche, element);
    if(noeud->contenu < element) return rechercher(noeud->droite, element);
    return &(noeud->contenu);
}

// ---------------- insertion ----------------
template <class T>
void ArbreBinRech<T>::inserer(const T& element){ inserer(racine, element); }

template <class T>
void ArbreBinRech<T>::inserer(Noeud*& noeud, const T& element){
    if(noeud == nullptr){ noeud = new Noeud(element); return; }
    if(element < noeud->contenu)      inserer(noeud->gauche, element);
    else if(noeud->contenu < element) inserer(noeud->droite, element);
    else                              noeud->contenu = element;   // deja present
}

// ---------------- enlevement ----------------
template <class T>
void ArbreBinRech<T>::enlever(const T& element){ enlever(racine, element); }

template <class T>
void ArbreBinRech<T>::enlever(Noeud*& noeud, const T& element){
    if(noeud == nullptr) return;
    if(element < noeud->contenu)      enlever(noeud->gauche, element);
    else if(noeud->contenu < element) enlever(noeud->droite, element);
    else{
        if(noeud->gauche == nullptr){            // 0 ou 1 enfant (a droite)
            Noeud* temp = noeud;
            noeud = noeud->droite;
            delete temp;
        }
        else if(noeud->droite == nullptr){       // 1 enfant (a gauche)
            Noeud* temp = noeud;
            noeud = noeud->gauche;
            delete temp;
        }
        else{                                    // 2 enfants : max a gauche
            Noeud* max = noeud->gauche;
            while(max->droite != nullptr) max = max->droite;
            noeud->contenu = max->contenu;
            enlever(noeud->gauche, max->contenu);
        }
    }
}

template <class T>
int ArbreBinRech<T>::hauteur() const { return hauteur(racine); }
template <class T>
int ArbreBinRech<T>::hauteur(Noeud* noeud) const {
    if(noeud == nullptr) return 0;
    int g = hauteur(noeud->gauche), d = hauteur(noeud->droite);
    return (g > d ? g : d) + 1;
}
template <class T>
void ArbreBinRech<T>::vider(Noeud*& noeud){
    if(noeud == nullptr) return;
    vider(noeud->gauche);
    vider(noeud->droite);
    delete noeud;
    noeud = nullptr;
}

#endif
