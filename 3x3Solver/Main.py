from Cube import Cube
from CubeSolver import CubeSolver

thing = Cube("OGBYWWBWYWOORORWYGWGRGGGYBGGORORWWYBYYGBBWOBROORBYRBRY")
#thing =  Cube("OWYWWWBWBBOYBORRBROGRYGGGOWYRGRRYGBGOBWOBYRYBWGOOYRWGY") # cross done
#thing = Cube("OWYWWWRRYBOWBOGRBOGYOOGGWGRBRGWRYBBGOBWOBYRYBGRYOYRWGY") # one move cross (do F from cross done position)
thing.displayCube()
CubeSolver.BeginnerCFOP(thing)