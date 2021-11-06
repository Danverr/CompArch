import random

class Polar:
    def __init__(self):
        self.r  = 0
        self.phi = 0

    def ReadStrArray(self, strArray, i):
        if i >= len(strArray) - 1:
            return 0
        self.r = float(strArray[i])
        self.phi = float(strArray[i + 1])
        i += 2
        return i

    def CreateRandom(self):
        self.r = random.uniform(1, 100000)
        self.phi = random.uniform(1, 100000)

    def ToString(self):
        return f"{self.r:.6f}e^({self.phi:.6f}i)"

    def ToReal(self):
        return self.r
