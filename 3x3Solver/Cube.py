class Cube:
    SOLVED_CUBE = "WWWWWWWWWOOOOOOOOOGGGGGGGGGRRRRRRRRRBBBBBBBBBYYYYYYYYY"

    def __init__(self, scrambleString):
        # need more input validation: centers are correct colors, 9 of each color, contains only WGORYB chars
        if (len(scrambleString) != 54):
            self.cubeRepresentation = Cube.SOLVED_CUBE
        else:
            self.cubeRepresentation = scrambleString

    def isSolved(self):
        return self.cubeRepresentation == Cube.SOLVED_CUBE

    def displayCube(self):
        a = self.cubeRepresentation
        print("   " +a[0]+a[1]+a[2])
        print("   " +a[3]+a[4]+a[5])
        print("   " +a[6]+a[7]+a[8])
        print(a[9]+a[10]+a[11]+a[18]+a[19]+a[20]+a[27]+a[28]+a[29]+a[36]+a[37]+a[38])
        print(a[12]+a[13]+a[14]+a[21]+a[22]+a[23]+a[30]+a[31]+a[32]+a[39]+a[40]+a[41])
        print(a[15]+a[16]+a[17]+a[24]+a[25]+a[26]+a[33]+a[34]+a[35]+a[42]+a[43]+a[44])
        print("   " +a[45]+a[46]+a[47])
        print("   " +a[48]+a[49]+a[50])
        print("   " +a[51]+a[52]+a[53])
        print()

    def getPosition(self, piece):
        sortPiece = "".join(sorted(piece))
        a = self.cubeRepresentation
        if (len(sortPiece) == 3): #corner
            targetPiece = "".join(sorted(a[6]+a[11]+a[18]))
            if (sortPiece == targetPiece): return 0
            targetPiece = "".join(sorted(a[8]+a[20]+a[27]))
            if (sortPiece == targetPiece): return 1
            targetPiece = "".join(sorted(a[0]+a[9]+a[38]))
            if (sortPiece == targetPiece): return 2
            targetPiece = "".join(sorted(a[2]+a[29]+a[36]))
            if (sortPiece == targetPiece): return 3
            targetPiece = "".join(sorted(a[17]+a[24]+a[45]))
            if (sortPiece == targetPiece): return 4
            targetPiece = "".join(sorted(a[26]+a[33]+a[47]))
            if (sortPiece == targetPiece): return 5
            targetPiece = "".join(sorted(a[15]+a[44]+a[51]))
            if (sortPiece == targetPiece): return 6
            targetPiece = "".join(sorted(a[35]+a[42]+a[53]))
            if (sortPiece == targetPiece): return 7
            return 8
        elif (len(sortPiece) == 2): #edge
            print("edge")
        else: #bad
            return 0


    def R(self):
        a = self.cubeRepresentation
        self.cubeRepresentation = a[0]+a[1]+a[20]+a[3]+a[4]+a[23]+a[6]+a[7]+a[26]
        self.cubeRepresentation += a[9]+a[10]+a[11]+a[12]+a[13]+a[14]+a[15]+a[16]+a[17]
        self.cubeRepresentation += a[18]+a[19]+a[47]+a[21]+a[22]+a[50]+a[24]+a[25]+a[53]
        self.cubeRepresentation += a[33]+a[30]+a[27]+a[34]+a[31]+a[28]+a[35]+a[32]+a[29]
        self.cubeRepresentation += a[2]+a[37]+a[38]+a[5]+a[40]+a[41]+a[8]+a[43]+a[44]
        self.cubeRepresentation += a[45]+a[46]+a[42]+a[48]+a[49]+a[39]+a[51]+a[52]+a[36]

    def U(self):
        a = self.cubeRepresentation
        self.cubeRepresentation = a[6]+a[3]+a[0]+a[7]+a[4]+a[1]+a[8]+a[5]+a[2]
        self.cubeRepresentation += a[18]+a[19]+a[20]+a[12]+a[13]+a[14]+a[15]+a[16]+a[17]
        self.cubeRepresentation += a[27]+a[28]+a[29]+a[21]+a[22]+a[23]+a[24]+a[25]+a[26]
        self.cubeRepresentation += a[36]+a[37]+a[38]+a[30]+a[31]+a[32]+a[33]+a[34]+a[35]
        self.cubeRepresentation += a[9]+a[10]+a[11]+a[39]+a[40]+a[41]+a[42]+a[43]+a[44]
        self.cubeRepresentation += a[45]+a[46]+a[47]+a[48]+a[49]+a[50]+a[51]+a[52]+a[53]

    def F(self):
        a = self.cubeRepresentation
        self.cubeRepresentation = a[0]+a[1]+a[2]+a[3]+a[4]+a[5]+a[17]+a[14]+a[11]
        self.cubeRepresentation += a[9]+a[10]+a[45]+a[12]+a[13]+a[46]+a[15]+a[16]+a[47]
        self.cubeRepresentation += a[24]+a[21]+a[18]+a[25]+a[22]+a[19]+a[26]+a[23]+a[20]
        self.cubeRepresentation += a[6]+a[28]+a[29]+a[7]+a[31]+a[32]+a[8]+a[34]+a[35]
        self.cubeRepresentation += a[36]+a[37]+a[38]+a[39]+a[40]+a[41]+a[42]+a[43]+a[44]
        self.cubeRepresentation += a[33]+a[30]+a[27]+a[48]+a[49]+a[50]+a[51]+a[52]+a[53]

    def L(self):
        a = self.cubeRepresentation
        self.cubeRepresentation = a[44]+a[1]+a[2]+a[41]+a[4]+a[5]+a[38]+a[7]+a[8]
        self.cubeRepresentation += a[15]+a[12]+a[9]+a[16]+a[13]+a[10]+a[17]+a[14]+a[11]
        self.cubeRepresentation += a[0]+a[19]+a[20]+a[3]+a[22]+a[23]+a[6]+a[25]+a[26]
        self.cubeRepresentation += a[27]+a[28]+a[29]+a[30]+a[31]+a[32]+a[33]+a[34]+a[35]
        self.cubeRepresentation += a[36]+a[37]+a[51]+a[39]+a[40]+a[48]+a[42]+a[43]+a[45]
        self.cubeRepresentation += a[18]+a[46]+a[47]+a[21]+a[49]+a[50]+a[24]+a[52]+a[53]

    def D(self):
        a = self.cubeRepresentation
        self.cubeRepresentation = a[0]+a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]
        self.cubeRepresentation += a[9]+a[10]+a[11]+a[12]+a[13]+a[14]+a[42]+a[43]+a[44]
        self.cubeRepresentation += a[18]+a[19]+a[20]+a[21]+a[22]+a[23]+a[15]+a[16]+a[17]
        self.cubeRepresentation += a[27]+a[28]+a[29]+a[30]+a[31]+a[32]+a[24]+a[25]+a[26]
        self.cubeRepresentation += a[36]+a[37]+a[38]+a[39]+a[40]+a[41]+a[33]+a[34]+a[35]
        self.cubeRepresentation += a[51]+a[48]+a[45]+a[52]+a[49]+a[46]+a[53]+a[50]+a[47]

    def B(self):
        a = self.cubeRepresentation
        self.cubeRepresentation = a[29]+a[32]+a[35]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]
        self.cubeRepresentation += a[2]+a[10]+a[11]+a[1]+a[13]+a[14]+a[0]+a[16]+a[17]
        self.cubeRepresentation += a[18]+a[19]+a[20]+a[21]+a[22]+a[23]+a[24]+a[25]+a[26]
        self.cubeRepresentation += a[27]+a[28]+a[53]+a[30]+a[31]+a[52]+a[33]+a[34]+a[51]
        self.cubeRepresentation += a[42]+a[39]+a[36]+a[43]+a[40]+a[37]+a[44]+a[41]+a[38]
        self.cubeRepresentation += a[45]+a[46]+a[47]+a[48]+a[49]+a[50]+a[9]+a[12]+a[15]
