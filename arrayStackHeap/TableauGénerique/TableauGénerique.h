#ifndef TABLEAU_GENERIQUE
#define TABLEAU_GENERIQUE



template <class T> class Tableau {
    private:
        Tableau(int capacite_initiale = 4);
        ~Tableau();
        void ajouter(const T &elem);
        int taille () const { return nbElement; }
        T &operator[] (int index);
        const T &operator[] (int index) cosnt;
        void enlever(int index);
    private:
        T *element;
        int capacite, nbElement;
        void redimentionner(int nvCapacite);

};

template <class T> Tableau<T>::Tableau(int capacite_initiale){
    capacite = capacite_initiale;
    nbElement = 0;
    element = new T[capacite];
}

template <class T> Tableau<T>::~Tableau(){
    delete[] element;
    element = nullptr;
}


template <class T> void Tableau<T>::ajouter(const T &elem){
    if(capacite <= nbElement){
        redimentionner(2 * capacite);
    }
    element[nbElement++] = elem;

}

template <class T> void Tableau<T>::redimentionner(int nvCapacite){
    capacite = nvCapacite;
    T *temp = new T[capacite];
    for(int i = 0; i < nbElement; ++i){
        temp[i] = element[i];
    }
    delete[] element;
    element = temp;
}


template <class T> void Tableau<T>::enlever(int index){
    assert(index >=0 && index < nbElement);
        for(int i = index; i < nbElement - 1; ++i){

            element[i] = element[i+1];
        }
    nbElement--;

    
}




#endif