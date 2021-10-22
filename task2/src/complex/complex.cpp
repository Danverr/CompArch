#include "complex.h"



bool Complex::CreateNumber(float re, float im) {
    Re = re;
    Im = im;
    return true;
}

bool Complex::CreateNumber(std::ifstream &input) {
    float re;
    float im;

    input >> re >> im;

    return CreateNumber(re, im);
}

bool Complex::CreateRandomNumber() {
    return CreateNumber(RandomFloat(), RandomFloat());
}

void Complex::PrintNumber(std::ofstream &output) {
    output << std::fixed << Re;
    if (Im > 0) {
        output << "+";
    }
    output << std::fixed << Im << "i" << std::endl;
}

float Complex::ToReal() {
    return std::sqrt(Re*Re + Im*Im);
};