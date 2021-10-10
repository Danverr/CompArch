#ifndef NUMBER_H
#define NUMBER_H

#include "complex.h"
#include "fraction.h"
#include "polar.h"



struct Number {

    enum Type {
        COMPLEX,
        FRACTION,
        POLAR
    } type;

    union {
        Complex complex;
        Fraction fraction;
        Polar polar;
    };

};



bool CreateNumber(Number &number, std::ifstream &input);

bool CreateRandomNumber(Number &number);

void PrintNumber(Number &number, std::ofstream &output);

float ToReal(Number &number);



#endif // NUMBER_H
