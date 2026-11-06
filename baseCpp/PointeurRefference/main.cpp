// ---------- main.cpp ----------
#include <iostream>
#include "echanger.h"
using namespace std;

int main(){
    int a = 1, b = 2;
    echangerPtr(&a, &b);
    cout << a << " " << b << endl;     //2 1

    int c = 1, d = 2;
    echangerRef(c, d);
    cout << c << " " << d << endl;    // 2 1
    return 0;
}