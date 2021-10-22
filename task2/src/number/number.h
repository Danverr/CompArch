#pragma once
#include <fstream>
#include "../random/random.h"



class Number {

public:
    virtual bool CreateNumber(std::ifstream &input) = 0;

    virtual bool CreateRandomNumber() = 0;

    virtual void PrintNumber(std::ofstream &output) = 0;

    virtual float ToReal() = 0;

};