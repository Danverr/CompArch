from complex import *
from fraction import *
from polar import *

class Container:
    def __init__(self):
        self.store = []

    def ReadStrArray(self, strArray):
        if strArray == ['']:
            return
            
        arrayLen = len(strArray)
        i = 0

        while i < arrayLen:
            key = int(strArray[i])
            i += 1

            if key == 1:
                shape = Complex()
            elif key == 2:
                shape = Fraction()
            elif key == 3:
                shape = Polar()
            
            i = shape.ReadStrArray(strArray, i)
            self.store.append(shape)

    def CreateRandom(self, size):
        for i in range(size):
            key = random.randint(1, 3)

            if key == 1:
                shape = Complex()
            elif key == 2:
                shape = Fraction()
            elif key == 3:
                shape = Polar()
            
            shape.CreateRandom()
            self.store.append(shape)

    def ToString(self):
        res = ""
        for shape in self.store:
            res += shape.ToString() + "\n"
        return res

    def Size(self):
        return len(self.store)

    def ShakerSort(self):
        left = -1
        right = len(self.store)
        pos = 0

        while(True):
            isChanged = False

            while pos + 1 < right:
                if self.store[pos].ToReal() < self.store[pos + 1].ToReal():
                    self.store[pos], self.store[pos + 1] = self.store[pos + 1], self.store[pos]
                    isChanged = True;
                pos += 1

            pos -= 1
            right -= 1

            while pos - 1 > left:
                if self.store[pos - 1].ToReal() < self.store[pos].ToReal():
                    self.store[pos - 1], self.store[pos] = self.store[pos], self.store[pos - 1]
                    isChanged = True;
                pos -= 1
            
            pos += 1
            left += 1

            if isChanged == False:
                break