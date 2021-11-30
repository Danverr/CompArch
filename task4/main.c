#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>



//==================== RANDOM ====================
int RandomInt() {
    return (rand() % 1000000) * (rand() % 2 ? 1 : -1);
}

float RandomFloat() {
    return (float)(RandomInt()) / 1000000.0 * RandomInt();
}



//==================== COMPLEX ====================
struct Complex {
    float Re;
    float Im;
};

bool CreateComplex(struct Complex* complex, float Re, float Im) {
    complex->Re = Re;
    complex->Im = Im;
    return true;
}

bool CreateComplexFromFile(struct Complex* complex, FILE* input) {
    float re;
    float im;

    fscanf(input, "%f%f", &re, &im);

    return CreateComplex(complex, re, im);
}

bool CreateRandomComplex(struct Complex* complex) {
    return CreateComplex(complex, RandomFloat(), RandomFloat());
}

void PrintComplex(struct Complex* complex, FILE* output) {
    fprintf(output, "%.6f", complex->Re);
    if (complex->Im > 0) {
        fprintf(output, "%s", "+");
    }
    fprintf(output, "%.6fi", complex->Im);
};

float ComplexToReal(struct Complex* complex);



//==================== FRACTION ====================
struct Fraction {
    int Numerator;
    int Denominator;
};

bool CreateFraction(struct Fraction* fraction, int numerator, int denominator) {
    fraction->Numerator = numerator;
    fraction->Denominator = denominator;
    return true;
}

bool CreateFractionFromFile(struct Fraction* fraction, FILE* input) {
    int numerator;
    int denominator;

    fscanf(input, "%d%d", &numerator, &denominator);

    return CreateFraction(fraction, numerator, denominator);
}

bool CreateRandomFraction(struct Fraction* fraction) {
    return CreateFraction(fraction, RandomInt(), RandomInt());
}

void PrintFraction(struct Fraction* fraction, FILE* output) {
    fprintf(output, "%d/%d", fraction->Numerator, fraction->Denominator);
}

float FractionToReal(struct Fraction* fraction);



//==================== POLAR ====================
struct Polar {
    float R;
    float Phi;
};

bool CreatePolar(struct Polar* polar, float r, float phi) {
    polar->R = r;
    polar->Phi = phi;
    return true;
}

bool CreatePolarFromFile(struct Polar* polar, FILE* input) {
    float r;
    float phi;

    fscanf(input, "%f%f", &r, &phi);

    return CreatePolar(polar, r, phi);
}

bool CreateRandomPolar(struct Polar* polar) {
    return CreatePolar(polar, RandomFloat(), RandomFloat());
}

void PrintPolar(struct Polar* polar, FILE* output) {
    fprintf(output, "%.6fe^(%.6fi)", polar->R, polar->Phi);
}

float PolarToReal(struct Polar* polar);



//==================== NUMBER ====================
typedef enum {
    COMPLEX,
    FRACTION,
    POLAR
} NumberType;

struct Number {
    NumberType type;
    union {
        struct Complex complex;
        struct Fraction fraction;
        struct Polar polar;
    };
};

bool CreateNumber(struct Number* number, FILE* input) {
    int type = 0;
    if (!fscanf(input, "%d", &type)) {
        return false;
    }

    switch(type) {
        case 1:
            number->type = COMPLEX;
            return CreateComplexFromFile(&number->complex, input);
        case 2:
            number->type = FRACTION;
            return CreateFractionFromFile(&number->fraction, input);
        case 3:
            number->type = POLAR;
            return CreatePolarFromFile(&number->polar, input);
        default:
            return false;
    }
}

bool CreateRandomNumber(struct Number* number) {
    int type = rand() % 3 + 1;

    switch(type) {
        case 1:
            number->type = COMPLEX;
            return CreateRandomComplex(&number->complex);
        case 2:
            number->type = FRACTION;
            return CreateRandomFraction(&number->fraction);
        case 3:
            number->type = POLAR;
            return CreateRandomPolar(&number->polar);
        default:
            return false;
    }
}

void PrintNumber(struct Number* number, FILE* output) {
    switch(number->type) {
        case COMPLEX:
            PrintComplex(&number->complex, output);
            break;
        case FRACTION:
            PrintFraction(&number->fraction, output);
            break;
        case POLAR:
            PrintPolar(&number->polar, output);
            break;
        default:
            fprintf(output, "%s\n", "Incorrect number!");
    }
}

float ToReal(struct Number* number) {
    switch(number->type) {
        case COMPLEX:
            return ComplexToReal(&number->complex);
        case FRACTION:
            return FractionToReal(&number->fraction);
        case POLAR:
            return PolarToReal(&number->polar);
        default:
            return 0.0;
    }
}



//==================== CONTAINER ====================
struct Container {
    int Size;
    struct Number* Numbers[10000];
};

void CreateContainer(struct Container* container, FILE* input) {
    for (int i = 0; i < 10000; ++i) {
        container->Numbers[i] = malloc(sizeof(struct Number));
    }

    container->Size = 0;
    while(CreateNumber(container->Numbers[container->Size], input)) {
        ++container->Size;
    }
}

void DeleteContainer(struct Container* container) {
    for (int i = 0; i < 10000; ++i) {
        free(container->Numbers[i]);
    }
}

void CreateRandomContainer(struct Container* container, int size) {
    for (int i = 0; i < 10000; ++i) {
        container->Numbers[i] = malloc(sizeof(struct Number));
    }

    container->Size = size;
    for (int i = 0; i < size; i++) {
        CreateRandomNumber(container->Numbers[i]);
    }
}

void PrintContainer(struct Container* container, FILE* output) {
    fprintf(output, "%s %d\n", "Container size:", container->Size);
    for (int i = 0; i < container->Size; i++) {
        PrintNumber(container->Numbers[i], output);
        //fprintf(output, "\n");
        fprintf(output, " %0.6f\n", ToReal(container->Numbers[i]));
    }
}

void swap(struct Number* a, struct Number* b) {
    struct Number* temp = a;
    a = b;
    b = temp;
}

void ShakerSort(struct Container* container);



int main(int argc, char* argv[]) {
    if(argc != 4) {
        printf("%s\n%s\n%s\n%s\n%s\n",
               "Incorrect command line!",
               "  Waited:",
               "     command -f infile outfile",
               "  Or:",
               "     command -n number outfile");
        return 1;
    }

    srand(time(0));
    struct Container container;

    if(!strcmp(argv[1], "-f")) {
        FILE* input;
        input = fopen(argv[2], "r");
        CreateContainer(&container, input);
        fclose(input);
    } else if(!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);

        if((size < 1) || (size > 10000)) {
            printf("%s%d%s\n", "Incorrect number of numbers = ", size, ". Set 0 < number <= 10000");
            return 3;
        }

        CreateRandomContainer(&container, size);
    } else {
        printf("%s\n%s\n%s\n%s\n%s\n",
               "Incorrect qualifier value!",
               "  Waited:",
               "     command -f infile outfile",
               "  Or:",
               "     command -n number outfile");
        return 2;
    }

    FILE* output;
    output = fopen(argv[3], "w");

    fprintf(output, "===== FILLED CONTAINER =====\n");
    PrintContainer(&container, output);

    fprintf(output, "\n===== SORTED CONTAINER =====\n");
    ShakerSort(&container);
    PrintContainer(&container, output);

    fclose(output);
    DeleteContainer(&container);
    return 0;
}
