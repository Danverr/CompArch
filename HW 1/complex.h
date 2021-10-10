#ifndef COMPLEX_H
#define COMPLEX_H

#include <fstream>
#include <iostream>
#include <cmath>
#include "random.h"



struct Complex {

    float Re;
    float Im;

};



bool CreateNumber(Complex &complex, float Re, float Im);

bool CreateNumber(Complex &complex, std::ifstream &input);

bool CreateRandomNumber(Complex &complex);

void PrintNumber(Complex &complex, std::ofstream &output);

float ToReal(Complex &complex);



#endif // COMPLEX_H
