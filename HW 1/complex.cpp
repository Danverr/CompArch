#include "complex.h"

bool CreateNumber(Complex &complex, float Re, float Im) {
    complex.Re = Re;
    complex.Im = Im;
    return true;
};



bool CreateNumber(Complex &complex, std::ifstream &input) {
    float re;
    float im;

    input >> re >> im;

    return CreateNumber(complex, re, im);
}



bool CreateRandomNumber(Complex &complex) {
    return CreateNumber(complex, RandomFloat(), RandomFloat());
}



void PrintNumber(Complex &complex, std::ofstream &output) {
    output << complex.Re;
    if (complex.Im > 0) {
        output << "+";
    }
    output << complex.Im << "i" << std::endl;
};



float ToReal(Complex &complex) {
    return std::sqrt(complex.Re*complex.Re + complex.Im*complex.Im);
};