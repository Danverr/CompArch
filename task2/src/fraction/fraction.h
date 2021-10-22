#pragma once
#include "../number/number.h"



class Fraction : public Number {

public:
    bool CreateNumber(int numerator, int denominator);

    bool CreateNumber(std::ifstream &input) override;

    bool CreateRandomNumber() override;

    void PrintNumber(std::ofstream &output) override;

    float ToReal() override;

private:
    int Numerator = 0;
    int Denominator = 1;

};