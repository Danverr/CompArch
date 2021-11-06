import random
import math

class Complex:
    def __init__(self):
        self.re = 0
        self.im = 0

    def ReadStrArray(self, strArray, i):
        if i >= len(strArray) - 1:
            return 0
        self.re = float(strArray[i])
        self.im = float(strArray[i + 1])
        i += 2
        return i

    def CreateRandom(self):
        self.re = random.uniform(1, 100000)
        self.im = random.uniform(1, 100000)

    def ToString(self):
        return f"{self.re:.6f}{'+' if self.im >= 0 else ''}{self.im:.6f}i"

    def ToReal(self):
        return math.sqrt(self.re**2 + self.im**2)
