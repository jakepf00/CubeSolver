from Cube import Cube

class CubeSolver:
    def BeginnerCFOP(cube):
        CubeSolver.Cross(cube)
        CubeSolver.FirstLayerCorners(cube)
        CubeSolver.SecondLayer(cube)
        CubeSolver.LastLayerCross(cube)
        CubeSolver.LastLayerCorners(cube)
        CubeSolver.PLL(cube)



    def Cross(cube):
        finishedState = "xxxxWxxWxxxxxOxxxxxGxxGxxxxxxxxRxxxxxxxxBxxxxxxxxYxxxx" # Green cross piece
        cube = CubeSolver.BFS(cube, finishedState)

        finishedState = "xxxxWWxWxxxxxOxxxxxGxxGxxxxxRxxRxxxxxxxxBxxxxxxxxYxxxx" # Red cross piece
        cube = CubeSolver.BFS(cube, finishedState)

        finishedState = "xWxxWWxWxxxxxOxxxxxGxxGxxxxxRxxRxxxxxBxxBxxxxxxxxYxxxx" # Blue cross piece
        cube = CubeSolver.BFS(cube, finishedState)

        finishedState = "xWxWWWxWxxOxxOxxxxxGxxGxxxxxRxxRxxxxxBxxBxxxxxxxxYxxxx" # Orange cross piece
        cube = CubeSolver.BFS(cube, finishedState)
        print("Finished cross")
        cube.displayCube()

    def FirstLayerCorners(cube):
        spot = cube.getPosition("WGR")
        print(spot)
        finishedState = "xWxWWWxWWxOxxOxxxxxGGxGxxxxRRxxRxxxxxBxxBxxxxxxxxYxxxx" # Green/red corner piece
        cube = CubeSolver.BFS(cube, finishedState)
        print("First corner")
        cube.displayCube()

        finishedState = "WWWWWWWWWOOOxxxxxxGGGxxxxxxRRRxxxxxxBBBxxxxxxxxxxxxxxx"
        cube = CubeSolver.BFS(cube, finishedState)
        print("Finished first layer")
        cube.displayCube()

    def SecondLayer(cube):
        print("Second layer..")

    def LastLayerCross(cube):
        print("Last layer cross..")

    def LastLayerCorners(cube):
        print("Last layer corners..")

    def PLL(cube):
        print("PLL..")


    def BFS(cube, goalState):
        num = 0
        queue = []
        queue.append(cube.cubeRepresentation)

        while queue[0]:
            num = num + 1
            print(num)

            current = queue.pop(0)
            #print("Testing " + current)

            if (CubeSolver.isGoalReached(goalState, current)):
                cube.cubeRepresentation = current
                return cube
            else:
                cube.cubeRepresentation = current
                cube.U()
                queue.append(cube.cubeRepresentation)
                cube.cubeRepresentation = current
                cube.L()
                queue.append(cube.cubeRepresentation)
                cube.cubeRepresentation = current
                cube.F()
                queue.append(cube.cubeRepresentation)
                cube.cubeRepresentation = current
                cube.R()
                queue.append(cube.cubeRepresentation)
                cube.cubeRepresentation = current
                cube.B()
                queue.append(cube.cubeRepresentation)
                cube.cubeRepresentation = current
                cube.D()
                queue.append(cube.cubeRepresentation)

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


