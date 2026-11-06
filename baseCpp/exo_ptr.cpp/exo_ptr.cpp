#include <iostream>

using namespace std;

void incrementerPtr(int *n){
    *n += 1;                // ici pour l incrementer je dois derreferencer le pointeur

}


void incrementerRef(int &n){
    n += 1;
}

void minMax(int a, int b, int &min, int &max){

    min = (a < b) ? a : b;
    max = (a < b) ? b : a; 

}

double moyenne(const double *tab, int n){
    double somme(0);
    for(int i = 0; i < n; ++i){
        somme += tab[i];

    }
    return somme/n;

}

int main(){
    int x = 5;


    incrementerPtr(&x);
    cout << x << endl;

    incrementerRef(x);
    cout << x << endl;

    int petit;
    int grand;

    minMax(12, 4, petit, grand);
    cout << petit << " " << grand << endl;

    double notes[4] = {80, 90, 70, 100};
    cout << moyenne(notes, 4) << endl;


    return 0;
}