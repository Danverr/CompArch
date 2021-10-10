#ifndef FRACTION_H
#define FRACTION_H

#include <fstream>
#include "random.h"



struct Fraction {

    int Numerator;
    int Denominator;

};



bool CreateNumber(Fraction &fraction, int numerator, int denominator);

bool CreateNumber(Fraction &fraction, std::ifstream &input);

bool CreateRandomNumber(Fraction &fraction);

void PrintNumber(Fraction &fraction, std::ofstream &output);

float ToReal(Fraction &fraction);



#endif // FRACTION_H
