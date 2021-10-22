#include "polar.h"



bool Polar::CreateNumber(float r, float phi) {
    R = r;
    Phi = phi;
    return true;
}

bool Polar::CreateNumber(std::ifstream &input) {
    float r;
    float phi;

    input >> r >> phi;

    return CreateNumber(r, phi);
}

bool Polar::CreateRandomNumber() {
    return CreateNumber(RandomFloat(), RandomFloat());
}

void Polar::PrintNumber(std::ofstream &output) {
    output << std::fixed << R << "e^(" << Phi << "i)" << std::endl;
}

float Polar::ToReal() {
    return R;
}