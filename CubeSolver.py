from Cube import Cube

class CubeSolver:
    def BeginnerCFOP(cube):
        print("Doing CFOP..")
        CubeSolver.Cross(cube)
        CubeSolver.FirstLayerCorners(cube)
        CubeSolver.SecondLayer(cube)
        CubeSolver.LastLayerCross(cube)
        CubeSolver.LastLayerCorners(cube)
        CubeSolver.PLL(cube)
        print(cube.isSolved())



    def Cross(cube):
        finishedState = "xWxWWWxWxxOxxxxxxxxGxxxxxxxxRxxxxxxxxBxxxxxxxxxxxxxxxx"
        print(CubeSolver.isGoalReached(finishedState, cube.cubeRepresentation))
        cube = CubeSolver.BFS(cube, finishedState)

    def FirstLayerCorners(cube):
        print("Corners..")

    def SecondLayer(cube):
        print("Second layer..")

    def LastLayerCross(cube):
        print("Last layer cross..")

    def LastLayerCorners(cube):
        print("Last layer corners..")

    def PLL(cube):
        print("PLL..")

    def BFS(cube, goalState):
        queue = []

    def isGoalReached(goal, current):
        print(goal)
        print(current)
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


