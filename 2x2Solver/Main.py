from Cube import Cube
from CubeSolver import CubeSolver

#thing = Cube("RBOBGBYGYOORWRYBYWRGWGOW") # scramble
thing = Cube("WGWWOGOYRORRGOWRYBYBBBYG") # scramble: R F' R' U' F R U R' U' R2 U'
#                                           solution: U R2 U L U B U' F' L' U L'
#thing = Cube("WOWBOOYYGWGWRBRGYBYBRGRO") # 1 turn first side
#thing = Cube("WBWBOOOOGWGWRRRRYBYBYGYG") # R'
#thing = Cube("BBWWYBOOOOGWGWRRRRYBYGYG") # R'U'
#thing = Cube("BYWRYBOOOBGWWRGRGRGBYOYW") # R'U'R'
#thing = Cube("BYWGYROWBWOGORYRGRGBBOYW") # R'U'R'F'
#thing = Cube("BYWGYROGBWYRORGBGROWOWBY") # R'U'R'F'D'
#thing = Cube("OYWGBRYGBWYROBGYRWGOOWBR") # R'U'R'F'D'B'

thing.displayCube()
solver = CubeSolver()
print(solver.Solve(thing))