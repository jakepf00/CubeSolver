class Cube:
    SOLVED_CUBE = "WWWWOOOOGGGGRRRRBBBBYYYY"

    def __init__(self, scrambleString):
        # need more input validation: 4 of each color, contains only WGORYB chars
        if (len(scrambleString) != 24):
            self.cubeRepresentation = Cube.SOLVED_CUBE
        else:
            self.cubeRepresentation = scrambleString

    def isSolved(self):
        return self.cubeRepresentation == Cube.SOLVED_CUBE

    def displayCube(self):
        a = self.cubeRepresentation
        print("  " + a[0] + a[1])
        print("  " + a[2] + a[3])
        print(a[4] + a[5] + a[8] + a[9] + a[12] + a[13] + a[16] + a[17])
        print(a[6] + a[7] + a[10] + a[11] + a[14] + a[15] + a[18] + a[19])
        print("  " + a[20] + a[21])
        print("  " + a[22] + a[23])

    def R(self):
        a = self.cubeRepresentation
        self.cubeRepresentation = a[0]+a[9]+a[2]+a[11]
        self.cubeRepresentation += a[4]+a[5]+a[6]+a[7]
        self.cubeRepresentation += a[8]+a[21]+a[10]+a[23]
        self.cubeRepresentation += a[14]+a[12]+a[15]+a[13]
        self.cubeRepresentation += a[3]+a[17]+a[1]+a[19]
        self.cubeRepresentation += a[20]+a[18]+a[22]+a[16]

    def U(self):
        a = self.cubeRepresentation
        self.cubeRepresentation = a[2]+a[0]+a[3]+a[1]
        self.cubeRepresentation += a[8]+a[9]+a[6]+a[7]
        self.cubeRepresentation += a[12]+a[13]+a[10]+a[11]
        self.cubeRepresentation += a[16]+a[17]+a[14]+a[15]
        self.cubeRepresentation += a[4]+a[5]+a[18]+a[19]
        self.cubeRepresentation += a[20]+a[21]+a[22]+a[23]

    def F(self):
        a = self.cubeRepresentation
        self.cubeRepresentation = a[0]+a[1]+a[7]+a[5]
        self.cubeRepresentation += a[4]+a[20]+a[6]+a[21]
        self.cubeRepresentation += a[10]+a[8]+a[11]+a[9]
        self.cubeRepresentation += a[2]+a[13]+a[3]+a[15]
        self.cubeRepresentation += a[16]+a[17]+a[18]+a[19]
        self.cubeRepresentation += a[14]+a[12]+a[22]+a[23]

    def L(self):
        a = self.cubeRepresentation
        self.cubeRepresentation = a[19]+a[1]+a[17]+a[3]
        self.cubeRepresentation += a[6]+a[4]+a[7]+a[5]
        self.cubeRepresentation += a[0]+a[9]+a[2]+a[11]
        self.cubeRepresentation += a[12]+a[13]+a[14]+a[15]
        self.cubeRepresentation += a[16]+a[22]+a[18]+a[20]
        self.cubeRepresentation += a[8]+a[21]+a[10]+a[23]

    def D(self):
        a = self.cubeRepresentation
        self.cubeRepresentation = a[0]+a[1]+a[2]+a[3]
        self.cubeRepresentation += a[4]+a[5]+a[18]+a[19]
        self.cubeRepresentation += a[8]+a[9]+a[6]+a[7]
        self.cubeRepresentation += a[12]+a[13]+a[10]+a[11]
        self.cubeRepresentation += a[16]+a[17]+a[14]+a[15]
        self.cubeRepresentation += a[22]+a[20]+a[23]+a[21]

    def B(self):
        a = self.cubeRepresentation
        self.cubeRepresentation = a[13]+a[15]+a[2]+a[3]
        self.cubeRepresentation += a[1]+a[5]+a[0]+a[7]
        self.cubeRepresentation += a[8]+a[9]+a[10]+a[11]
        self.cubeRepresentation += a[12]+a[23]+a[14]+a[22]
        self.cubeRepresentation += a[18]+a[16]+a[19]+a[17]
        self.cubeRepresentation += a[20]+a[21]+a[4]+a[6]

    def applyAlg(self, alg):
        for i in alg:
            if i == 'R':
                Cube.R(self)
            elif i == 'U':
                Cube.U(self)
            elif i == 'F':
                Cube.F(self)
            elif i == 'L':
                Cube.L(self)
            elif i == 'D':
                Cube.D(self)
            elif i == 'B':
                Cube.B(self)
            else:
                print("Illegal char: " + i)