#include "container.h"



void Clear(Container &container) {
    container.Size = 0;
}



void CreateContainer(Container &container, std::ifstream &input) {
    while(CreateNumber( container.Numbers[container.Size++], input)) {}
}



void CreateRandomContainer(Container &container, int size) {
    for (int i = 0; i < size; i++) {
        CreateRandomNumber(container.Numbers[i]);
    }
}



void PrintContainer(Container &container, std::ofstream &output) {
    for (int i = 0; i < container.Size; i++) {
        PrintNumber(container[i], output);
    }
}



float ShakerSort(Container &container) {
    int left = 0;
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
        --right;

        while (pos - 1 > left) {
            if (ToReal(container.Numbers[pos - 1]) < ToReal(container.Numbers[pos])) {
                std::swap(container.Numbers[pos], container.Numbers[pos + 1]);
                isChanged = 1;
            }
            --pos;
        }
        ++left;
    } while (isChanged);
}
