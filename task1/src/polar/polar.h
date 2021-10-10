#ifndef POLAR_H
#define POLAR_H

#include <fstream>
#include "../random/random.h"



struct Polar {

    float R;
    float Phi;

};



bool CreateNumber(Polar &polar, float r, float phi);

bool CreateNumber(Polar &polar, std::ifstream &input);

bool CreateRandomNumber(Polar &polar);

void PrintNumber(Polar &polar, std::ofstream &output);

float ToReal(Polar &polar);



#endif // POLAR_H
