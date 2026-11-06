#include <iostream>

using namespace std;

int main(int argc, char **argv){

    int *p = new int;
    *p = 24;
    cout << *p << endl;
    delete p;


    int n = 5;
    int *tab = new int[n];

    for(int i = 0; i < n; ++i)
        tab[i] = i * i;

    for(int i = 0; i < n; ++i)
        cout << tab[i] << " ";

    delete[] tab;


    int n;
    cout << "combien d elements ? ";
    cin >> n;

    int *tab = new int[n];

    for(int i = 0; i < n; ++i){
        tab[i] = i * 2;
    }

    for(int i = 0; i < n; ++i){
        cout << tab[i] << " ";
    }

    cout << endl;

    delete[] tab;












    return 0;
}