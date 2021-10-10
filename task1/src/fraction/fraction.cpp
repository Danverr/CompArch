#include "fraction.h"



bool CreateNumber(Fraction &fraction, int numerator, int denominator) {
    fraction.Numerator = numerator;
    fraction.Denominator = denominator;
    return true;
}



bool CreateNumber(Fraction &fraction, std::ifstream &input) {
    int numerator;
    int denomenator;

    input >> numerator >> denomenator;

    return CreateNumber(fraction, numerator, denomenator);
}



bool CreateRandomNumber(Fraction &fraction) {
    return CreateNumber(fraction, RandomInt(), RandomInt());
}



void PrintNumber(Fraction &fraction, std::ofstream &output) {
    output << fraction.Numerator << "/" << fraction.Denominator << std::endl;
}



float ToReal(Fraction &fraction) {
    return float(fraction.Numerator) / fraction.Denominator;
}
