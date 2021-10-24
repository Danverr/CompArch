#include "random.h"



int RandomInt() {
    return (rand() % 1000000) * (rand() % 2 ? 1 : -1);
}

float RandomFloat() {
    return float(RandomInt()) / 1000000.0 * RandomInt();
}
