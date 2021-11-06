import sys
from container import *

def incorrectInput():
    print("Incorrect command line! You must write:")
    print("    python main -f <inputFileName> <outputFileName>")
    print("    python main -n <numberOfElements> <outputFileName>")
    exit()

if __name__ == '__main__':
    if len(sys.argv) != 4:
        incorrectInput()

    container = Container()

    if sys.argv[1] == "-f":
        inputFileName  = sys.argv[2]
        outputFileName = sys.argv[3]
        
        ifile = open(inputFileName)
        strArray = ifile.read().replace("\n", " ").split(" ")
        ifile.close()
        
        container.ReadStrArray(strArray)
    elif sys.argv[1] == "-n":
        numberOfElements = int(sys.argv[2])
        outputFileName = sys.argv[3]

        container.CreateRandom(numberOfElements)
    else:
        incorrectInput()

    with open(outputFileName, 'w') as output: 
        print("===== FILLED CONTAINER =====", file=output)
        print("Container size:", container.Size(), file=output)
        print(container.ToString(), file=output)
        
        container.ShakerSort()
        container.ToString()
        print("===== SORTED CONTAINER =====", file=output)
        print("Container size:", container.Size(), file=output)
        print(container.ToString(), end="", file=output)
