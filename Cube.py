class Cube:
    SOLVED_CUBE = "WWWWWWWWWOOOOOOOOOGGGGGGGGGRRRRRRRRRBBBBBBBBBYYYYYYYYY"

    def __init__(self, scrambleString):
        if (len(scrambleString) != 54):
            self.cubeRepresentation = Cube.SOLVED_CUBE
        else:
            self.cubeRepresentation = scrambleString

    def isSolved(self):
        return self.cubeRepresentation == Cube.SOLVED_CUBE

    def R():
        print("turning R")

    def U():
        print("turning U")

    def F():
        print("turning F")

    def L():
        print("turning L")

    def D():
        print("turning D")

    def B():
        print("turning B")
