#include "random.h"



int RandomInt() {
    return rand() * (rand() % 2 ? 1 : -1);
}

float RandomFloat() {
    return float(RandomInt()) / INT32_MAX * rand();
}
