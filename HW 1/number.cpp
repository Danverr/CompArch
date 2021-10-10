#include "number.h"



bool CreateNumber(Number& number, std::ifstream &input) {
    int type = 0;
    if (!(input >> type)) {
        return false;
    }

    switch(type) {
        case 1:
            number.type = Number::COMPLEX;
            return CreateNumber(number.complex, input);
        case 2:
            number.type = Number::FRACTION;
            return CreateNumber(number.fraction, input);
        case 3:
            number.type = Number::POLAR;
            return CreateNumber(number.polar, input);
        default:
            return false;
    }
}



bool CreateRandomNumber(Number& number) {
    int type = rand() % 3 + 1;

    switch(type) {
        case 1:
            number.type = Number::COMPLEX;
            return CreateRandomNumber(number.complex);
        case 2:
            number.type = Number::FRACTION;
            return CreateRandomNumber(number.fraction);
        case 3:
            number.type = Number::POLAR;
            return CreateRandomNumber(number.polar);
        default:
            return false;
    }
}



void PrintNumber(Number &number, std::ofstream &output) {
    switch(number.type) {
        case Number::COMPLEX:
            PrintNumber(number.complex, output);
            break;
        case Number::FRACTION:
            PrintNumber(number.fraction, output);
            break;
        case Number::POLAR:
            PrintNumber(number.polar, output);
            break;
        default:
            output << "Incorrect number!" << std::endl;
    }
}



float ToReal(Number &number) {
    switch(number.type) {
        case Number::COMPLEX:
            return ToReal(number.complex);
            break;
        case Number::FRACTION:
            return ToReal(number.fraction);
            break;
        case Number::POLAR:
            return ToReal(number.polar);
            break;
        default:
            return 0.0;
    }
}
