#include <iostream>
#include "echanger.h"


void echangerPtr(int *x, int *y){
    int temp = *x;

    *x = *y;
    *y = temp;

}


void echangerRef(int &x, int &y){

    int temp = x;

    x = y;
    y = temp;
    
}