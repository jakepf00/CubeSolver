from Cube import Cube
from CubeSolver import CubeSolver

#thing = Cube("RBOBGBYGYOORWRYBYWRGWGOW") # scramble
#thing = Cube("WOWBOOYYGWGWRBRGYBYBRGRO") # 1 turn first side
#thing = Cube("WBWBOOOOGWGWRRRRYBYBYGYG") # R'
#thing = Cube("BBWWYBOOOOGWGWRRRRYBYGYG") # R'U'
#thing = Cube("BYWRYBOOOBGWWRGRGRGBYOYW") # R'U'R'
#thing = Cube("BYWGYROWBWOGORYRGRGBBOYW") # R'U'R'F'
thing = Cube("BYWGYROGBWYRORGBGROWOWBY") # R'U'R'F'D'
#thing = Cube("OYWGBRYGBWYROBGYRWGOOWBR") # R'U'R'F'D'B'

thing.displayCube()
CubeSolver.Solve(thing)