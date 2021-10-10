#include "polar.h"


bool CreateNumber(Polar &polar, float r, float phi) {
    polar.R = r;
    polar.Phi = phi;
    return true;
}



bool CreateNumber(Polar &polar, std::ifstream &input) {
    float r;
    float phi;

    input >> r >> phi;

    return CreateNumber(polar, r, phi);
}



bool CreateRandomNumber(Polar &polar) {
    CreateNumber(polar, RandomFloat(), RandomFloat());
}



void PrintNumber(Polar &polar, std::ofstream &output) {
    output << polar.R << "e^(" << polar.Phi << "i)" << std::endl;
}



float ToReal(Polar &polar) {
    return polar.R;
}