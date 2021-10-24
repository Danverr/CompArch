#include "container.h"



Container::~Container() {
    for (int i = 0; i < Size; i++) {
        delete Numbers[i];
        Numbers[i] = nullptr;
    }
}

void Container::CreateContainer(std::ifstream &input) {
    int type = 0;

    while(input >> type) {
        switch (type) {
            case 1:
                Numbers[Size] = new Complex();
                break;
            case 2:
                Numbers[Size] = new Fraction();
                break;
            case 3:
                Numbers[Size] = new Polar();
                break;
        }

        Numbers[Size]->CreateNumber(input);
        ++Size;
    }
}

void Container::CreateRandomContainer(int size) {
    Size = size;

    for (int i = 0; i < size; i++) {
        switch (rand() % 3 + 1) {
            case 1:
                Numbers[i] = new Complex();
                break;
            case 2:
                Numbers[i] = new Fraction();
                break;
            case 3:
                Numbers[i] = new Polar();
                break;
        }
        Numbers[i]->CreateRandomNumber();
    }
}

void Container::PrintContainer(std::ofstream &output) {
    output << "Container size: "<< Size << std::endl;
    for (int i = 0; i < Size; i++) {
        Numbers[i]->PrintNumber(output);
    }
}

void Container::ShakerSort() {
    int left = -1;
    int right = Size;
    int pos = 0;
    bool isChanged = 0;

    do {
        isChanged = 0;

        while (pos + 1 < right) {
            if (Numbers[pos]->ToReal() < Numbers[pos + 1]->ToReal()) {
                std::swap(Numbers[pos], Numbers[pos + 1]);
                isChanged = 1;
            }
            ++pos;
        }
        --pos;
        --right;

        while (pos - 1 > left) {
            if (Numbers[pos - 1]->ToReal() < Numbers[pos]->ToReal()) {
                std::swap(Numbers[pos - 1], Numbers[pos]);
                isChanged = 1;
            }
            --pos;
        }
        ++pos;
        ++left;
    } while (isChanged);
}