#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "number.h"
#include "container.h"



int main(int argc, char* argv[]) {
    if(argc != 5) {
        std::cout << "incorrect command line!\n"
                "  Waited:\n"
                "     command -f infile outfile01 outfile02\n"
                "  Or:\n"
                "     command -n number outfile01 outfile02\n";
        return 1;
    }

    std::cout << "Start"<< std::endl;
    srand(static_cast<unsigned int>(time(0)));
    Container container;

    if(!strcmp(argv[1], "-f")) {
        std::ifstream input(argv[2]);
        CreateContainer(container, input);
    } else if(!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);

        if((size < 1) || (size > 10000)) {
            std::cout << "incorrect numer of figures = "
                 << size
                 << ". Set 0 < number <= 10000\n";
            return 3;
        }

        CreateRandomContainer(container, size);
    } else {
        std::cout << "incorrect qualifier value!\n"
                "  Waited:\n"
                "     command -f infile outfile01 outfile02\n"
                "  Or:\n"
                "     command -n number outfile01 outfile02\n";
        return 2;
    }

    std::ofstream output1(argv[3]);
    output1 << "Filled container:\n";
    PrintContainer(container, output1);

    std::ofstream output2(argv[4]);
    ShakerSort(container);
    PrintContainer(container, output2);

    Clear(container);
    std::cout << "Stop"<< std::endl;

    return 0;
}
