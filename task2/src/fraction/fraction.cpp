#include "fraction.h"



bool Fraction::CreateNumber(int numerator, int denominator) {
    Numerator = numerator;
    Denominator = denominator;
    return true;
}

bool Fraction::CreateNumber(std::ifstream &input) {
    int numerator;
    int denomenator;

    input >> numerator >> denomenator;

    return CreateNumber(numerator, denomenator);
}

bool Fraction::CreateRandomNumber() {
    return CreateNumber(RandomInt(), RandomInt());
}

void Fraction::PrintNumber(std::ofstream &output) {
    output << Numerator << "/" << Denominator << std::endl;
}

float Fraction::ToReal() {
    return float(Numerator) / Denominator;
}
