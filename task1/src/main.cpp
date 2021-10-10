#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "number/number.h"
#include "container/container.h"



int main(int argc, char* argv[]) {
    if(argc != 4) {
        std::cout << "incorrect command line!" << std::endl
                  << "  Waited:" << std::endl
                  << "     command -f infile outfile01 outfile02" << std::endl
                  << "  Or:" << std::endl
                  << "     command -n number outfile01 outfile02" << std::endl;
        return 1;
    }

    srand(static_cast<unsigned int>(time(0)));
    Container container;

    if(!strcmp(argv[1], "-f")) {
        std::ifstream input(argv[2]);
        CreateContainer(container, input);
    } else if(!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);

        if((size < 1) || (size > 10000)) {
            std::cout << "Incorrect number of numbers = " << size << ". Set 0 < number <= 10000" << std::endl;
            return 3;
        }

        CreateRandomContainer(container, size);
    } else {
        std::cout << "Incorrect qualifier value!" << std::endl
                  << "  Waited:" << std::endl
                  << "    command -f infile outfile" << std::endl
                  << "  Or:" << std::endl
                  << "    command -n number outfile" << std::endl;
        return 2;
    }

    std::ofstream output(argv[3]);

    output << "===== FILLED CONTAINER =====" << std::endl;
    PrintContainer(container, output);

    output << std::endl << "===== SORTED CONTAINER =====" << std::endl;
    ShakerSort(container);
    PrintContainer(container, output);

    return 0;
}
