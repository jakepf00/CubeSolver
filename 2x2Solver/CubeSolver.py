from Cube import Cube

class CubeSolver:

    def Solve(self, cube):
        self.memo = {}
        path = self.BFS(cube, "WWWWOOOOGGGGRRRRBBBBYYYY")
        if path:
            return self.compress(path)
        return(self.compress(self.backBFS()))

    def compress(self, alg):
        alg = alg + "***"
        newAlg = ""
        while alg[0] != "*":
            if alg[1] != alg[0]: # only one char in a row
                newAlg = newAlg + alg[0] + " "
                alg = alg[1:]
            elif alg[2] != alg[0]: # only two char in a row
                newAlg = newAlg + alg[0] + "2 "
                alg = alg[2:]
            else: # three char in a row
                newAlg = newAlg + alg[0] + "' "
                alg = alg[3:]
        return newAlg

    def invert(self, alg):
        alg = alg[::-1]
        alg = alg + "***"
        newAlg = ""
        while alg[0] != "*":
            if alg[1] != alg[0]: # only one char in a row
                newAlg = newAlg + alg[0] + alg[0] + alg[0]
                alg = alg[1:]
            elif alg[2] != alg[0]: # only two char in a row
                newAlg = newAlg + alg[0] + alg[0]
                alg = alg[2:]
            else: # three char in a row
                newAlg = newAlg + alg[0]
                alg = alg[3:]
        return newAlg

    def BFS(self, cube, goalState):
        visited = []
        path = []
        queue = []
        queue.append(cube.cubeRepresentation)
        path.append("")
        visited.append(cube.cubeRepresentation)

        while len(queue) > 0:

            current = queue.pop(0)
            currentPath = path.pop(0)

            self.memo[current] = currentPath

            if (self.isGoalReached(goalState, current)):
                cube.cubeRepresentation = current
                return currentPath
            elif len(currentPath) > 6:
                continue
            else:
                moves = ['U', 'L', 'F', 'R', 'B', 'D']
                for move in moves:
                    cube.cubeRepresentation = current
                    cube.applyAlg(move)
                    if cube.cubeRepresentation not in visited:
                        nextPath = currentPath + move
                        queue.append(cube.cubeRepresentation)
                        path.append(nextPath)

    def backBFS(self):
        cube = Cube("WWWWOOOOGGGGRRRRBBBBYYYY")
        visited = []
        path = []
        queue = []
        queue.append(cube.cubeRepresentation)
        path.append("")
        visited.append(cube.cubeRepresentation)

        while queue[0]:

            current = queue.pop(0)
            currentPath = path.pop(0)

            if current in self.memo:
                return self.memo[current] + self.invert(currentPath)

            if (False):
                cube.cubeRepresentation = current
                return currentPath
            else:
                moves = ['U', 'L', 'F', 'R', 'B', 'D']
                for move in moves:
                    cube.cubeRepresentation = current
                    cube.applyAlg(move)
                    if cube.cubeRepresentation not in visited:
                        nextPath = currentPath + move
                        queue.append(cube.cubeRepresentation)
                        path.append(nextPath)

    def isGoalReached(self, goal, current):
        solved = True
        count = 0
        for i in goal:
            if (i == 'x'):
                count = count + 1
                continue
            else:
                if (i != current[count]):
                    solved = False
                    break
                count = count + 1
        return solved


