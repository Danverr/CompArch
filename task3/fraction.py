import random

class Fraction:
    def __init__(self):
        self.num  = 0
        self.denom = 0

    def ReadStrArray(self, strArray, i):
        if i >= len(strArray) - 1:
            return 0
        self.num = int(strArray[i])
        self.denom = int(strArray[i + 1])
        i += 2
        return i

    def CreateRandom(self):
        self.num = random.randint(1, 100000)
        self.denom = random.randint(1, 100000)

    def ToString(self):
        return str(self.num) + "/" + str(self.denom)

    def ToReal(self):
        return self.num / self.denom
