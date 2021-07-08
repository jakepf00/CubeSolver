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
        print("Cross..")

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
        print("Doing BFS..")