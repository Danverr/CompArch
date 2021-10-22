#pragma once
#include "../number/number.h"



class Polar : public Number {

public:
    bool CreateNumber(float r, float phi);

    bool CreateNumber(std::ifstream &input) override;

    bool CreateRandomNumber() override;

    void PrintNumber(std::ofstream &output) override;

    float ToReal() override;

private:
    float R;
    float Phi;

};