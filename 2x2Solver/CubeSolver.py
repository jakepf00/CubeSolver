from Cube import Cube

class CubeSolver:
    def Solve(cube):
        CubeSolver.FirstSide(cube)
        CubeSolver.SecondSide(cube)
        CubeSolver.PBL(cube)


    def FirstSide(cube):
        finishedState = "xxxxxxxxxxxxxxxxxxxxYYYY" # four corner
        firstSideAlg = CubeSolver.BFS(cube, finishedState)
        print("Finished first side: " + firstSideAlg)
        cube.displayCube()


    def SecondSide(cube):
        finishedState = "WWWWxxxxxxxxxxxxxxxxYYYY" # four corner
        secondSideAlg = CubeSolver.BFS(cube, finishedState)
        print("Finished second side: " + secondSideAlg)
        cube.displayCube()

    def PBL(cube):
        finishedState = "WWWWOOOOGGGGRRRRBBBBYYYY" # finished cube
        pblAlg = CubeSolver.BFS(cube, finishedState)
        print("Finished cube: " + pblAlg)
        cube.displayCube()


    def BFS(cube, goalState):
        visited = []
        path = []
        queue = []
        queue.append(cube.cubeRepresentation)
        path.append("")
        visited.append(cube.cubeRepresentation)
        n = 0 # iteration counter

        while queue[0]:

            current = queue.pop(0)
            currentPath = path.pop(0)

            n = n + 1
            if n % 5000 == 0:
                print(n)

            if (CubeSolver.isGoalReached(goalState, current)):
                cube.cubeRepresentation = current
                return currentPath
            else:
                cube.cubeRepresentation = current
                cube.U()
                if cube.cubeRepresentation not in visited:
                    nextPath = currentPath + 'U'
                    queue.append(cube.cubeRepresentation)
                    path.append(nextPath)

                cube.cubeRepresentation = current
                cube.L()
                if cube.cubeRepresentation not in visited:
                    nextPath = currentPath + 'L'
                    queue.append(cube.cubeRepresentation)
                    path.append(nextPath)

                cube.cubeRepresentation = current
                cube.F()
                if cube.cubeRepresentation not in visited:
                    nextPath = currentPath + 'F'
                    queue.append(cube.cubeRepresentation)
                    path.append(nextPath)

                cube.cubeRepresentation = current
                cube.R()
                if cube.cubeRepresentation not in visited:
                    nextPath = currentPath + 'R'
                    queue.append(cube.cubeRepresentation)
                    path.append(nextPath)

                cube.cubeRepresentation = current
                cube.B()
                if cube.cubeRepresentation not in visited:
                    nextPath = currentPath + 'B'
                    queue.append(cube.cubeRepresentation)
                    path.append(nextPath)

                cube.cubeRepresentation = current
                cube.D()
                if cube.cubeRepresentation not in visited:
                    nextPath = currentPath + 'D'
                    queue.append(cube.cubeRepresentation)
                    path.append(nextPath)

    def isGoalReached(goal, current):
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


