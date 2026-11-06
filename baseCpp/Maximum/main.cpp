#include <iostream>
#include "maximum.h"
using namespace std;

int main(int argc, char ** argv)
{
    cout << maximum(3, 7) << endl;
    cout << maximum(3.5, 7.1) << endl;
    cout << maximum(3, 7, 5) << endl;
    cout << maximum(3, (int)7.1) << endl;

    return 0;
}