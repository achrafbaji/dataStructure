#include <iostream>
using namespace std;


/**
 * Allocation a taille variable
 * l'allocation est fait à l'execution 
 */
int main(int argc, char** argv){
    int n;
    cout << " entrez le nombre d'elements: ";
    cin >> n;


    int *tab = new int[n];

    for(int i = 0; i < n; ++i)
    {
        tab[i] = i * 2;

    }

    for(int i = 0; i < n; ++i)
    {
        cout << tab[i] << " ";
    }

    cout << endl;

    delete[] tab;





    return 0;
}