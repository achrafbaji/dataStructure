#ifndef FILE_LINKED_H
#define FILE_LINKED_H
#include <cassert>


template <class T> class fileLinked{
    public: 
        fileLinked();
        ~fileLinked();
        bool estVide();
        const T& tete() const;
        void enfiler(const T& e);
        void defiler();
        void vider();
    private;
        class Cellule{
            Cellule(const T& c, Cellule *s = nullptr) : contenue(c), suivant(s) {};
            T contenue;
            Cellule *suivant;

        };
        Cellule *queue;

};


template <class T> fileLinked<T>::fileLinked() : queue(nullptr){}
template <class T> fileLinked<T>::~fileLinked() { vider(); }



//bool estVide();
template <class T> bool fileLinked<T>::estVide() {
    return queue == nullptr;
}

//const T& tete() const;
template <class T> const T& fileLinked<T>::tete() const {
    assert(queue != nullptr);
    return queue->suivant->contenue;
}



//void enfiler(const T& e);

template <class T> void fileLinked<T>::enfiler(const T& e){
    if(queue == nullptr){
        queue = new Cellule(e, nullptr);
        queue->suivant = queue;
    } else {
        Cellule *nvCellule = new Cellule(e, queue->suivant);
        queue->suivant = nvCellule;
        queue = nvCellule;
    }
}

//void defiler();
template <class T> void fileLinked<T>::defiler(){
    assert(queue != nullptr);
    Cellule *c = queue->suivant;      // on enregistre l element a defiler
    if(c == queue){                  // si ya un seul element
        queue = nullptr;
    } else {
        queue->suivant = c->suivant; // on deplace le premier element vers le deuxieme 
    }
    delete c;
}


//void vider();
template <class T> void fileLinked<T>::vider(){
    while(!estvide())
        defiler();
}




#endif