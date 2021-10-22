#pragma once
#include <fstream>
#include <iostream>
#include <cmath>
#include "../number/number.h"



class Complex : public Number {

public:
    bool CreateNumber(float Re, float Im);

    bool CreateNumber(std::ifstream &input) override;

    bool CreateRandomNumber() override;

    void PrintNumber(std::ofstream &output) override;

    float ToReal() override;

private:
    float Re = 0;
    float Im = 0;

};