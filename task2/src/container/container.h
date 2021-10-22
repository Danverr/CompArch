#pragma once
#include "../number/number.h"
#include "../complex/complex.h"
#include "../fraction/fraction.h"
#include "../polar/polar.h"



class Container {

public:
    ~Container();

    void CreateContainer(std::ifstream &input);

    void CreateRandomContainer(int size);

    void PrintContainer(std::ofstream &output);

    void ShakerSort();

private:
    int Size = 0;
    static const int MAX_SIZE = 10000;
    Number* Numbers[MAX_SIZE];

};