#include "container.h"



void CreateContainer(Container &container, std::ifstream &input) {
    while(CreateNumber( container.Numbers[container.Size], input)) {
        ++container.Size;
    }
}



void CreateRandomContainer(Container &container, int size) {
    container.Size = size;
    for (int i = 0; i < size; i++) {
        CreateRandomNumber(container.Numbers[i]);
    }
}



void PrintContainer(Container &container, std::ofstream &output) {
    output << "Container size: "<< container.Size << std::endl;
    for (int i = 0; i < container.Size; i++) {
        PrintNumber(container.Numbers[i], output);
    }
}



void ShakerSort(Container &container) {
    int left = -1;
    int right = container.Size;
    int pos = 0;
    bool isChanged = 0;

    do {
        isChanged = 0;

        while (pos + 1 < right) {
            if (ToReal(container.Numbers[pos]) < ToReal(container.Numbers[pos + 1])) {
                std::swap(container.Numbers[pos], container.Numbers[pos + 1]);
                isChanged = 1;
            }
            ++pos;
        }
        --pos;
        --right;

        while (pos - 1 > left) {
            if (ToReal(container.Numbers[pos - 1]) < ToReal(container.Numbers[pos])) {
                std::swap(container.Numbers[pos - 1], container.Numbers[pos]);
                isChanged = 1;
            }
            --pos;
        }
        ++pos;
        ++left;
    } while (isChanged);
}
