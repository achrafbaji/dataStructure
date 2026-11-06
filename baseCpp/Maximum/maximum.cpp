#include <iostream>
#include "maximum.h"

int maximum(int a, int b){
    int max;
    max = (a > b) ? a : b;
    return max;
}

double maximum(double a, double b){
    double max;
    max = (a > b) ? a : b;
    return max;
}

int maximum(int a, int b, int c) 
{
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}