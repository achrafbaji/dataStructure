#ifndef PILE_LINKED_H
#define PILE_LINKED_H
#include <cassert>



template <class T> class Pile{
    public:
        Pile();
        ~Pile();
        bool estVide() const;
        const T &sommet() const;
        void empiler(const T& e);
        T depiler();
        void vider();

    private:
        class Cellule {
            public:
                Cellule(const T& c, Cellule *s) :contenu(c), suivant(s){}

            T contenue;
            Cellule *suivant;
        };
        Cellule *tete;
        
};

//T depiler();

template <class T> T Pile<T>::depiler(){
    assert(tete != nullptr);
    T element = tete->contenue;
    Cellule *ancien = tete;
    tete = tete->suivant;
    delete ancien;
    return element;
}



//void vider();

template <class T> void Pile<T>::vider(){
    while(tete != nullptr){
        Cellule *ancien = tete;
        tete = tete->suivant;
        delete ancien;
    }
}


template <class T> Pile<T>::Pile() : tete(nullptr){}

template <class T> Pile<T>::~Pile() { vider(); }






//EST VIIDE bool estVide() const;
template <class T> bool Pile<T>::estVide() const {
    return tete == nullptr;
}


// const T &sommet() const;
template <class T> const T& Pile<T>::sommet() const{
    assert(tete != nullptr);
    return tete->contenue;
}



//void empiler(const T& e);

template <class T> void Pile<T>::empiler(const T& element){
    Cellule *nvtete = new Cellule(element, tete);
    tete = nvtete; // sa m aide a pas me perdre 
}


#endif