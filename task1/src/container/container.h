#ifndef CONTAINER_H
#define CONTAINER_H

#include "../number/number.h"



struct Container {

    enum {
        MAX_SIZE = 10000
    };

    int Size = 0;
    Number Numbers[MAX_SIZE];

};



void CreateContainer(Container &container, std::ifstream &input);

void CreateRandomContainer(Container &container, int size);

void PrintContainer(Container &container, std::ofstream &output);

void ShakerSort(Container &container);



#endif // CONTAINER_H
