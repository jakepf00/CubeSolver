#include "Cube.h"

Point RIGHT = Point(1, 0, 0);
Point LEFT = Point(-1, 0, 0);
Point UP = Point(0, 1, 0);
Point DOWN = Point(0, -1, 0);
Point FRONT = Point(0, 0, 1);
Point BACK = Point(0, 0, -1);
Point X_AXIS = RIGHT;
Point Y_AXIS = UP;
Point Z_AXIS = FRONT;


Cube::Cube(std::string cubeString) {
    // add some validation - string length 54 - perhaps automatically remove whitespace - only color chars
	/*
        Format of cubeString:

	            UUU                       0  1  2
                UUU                       3  4  5
                UUU                       6  7  8
            LLL FFF RRR BBB      9 10 11 12 13 14 15 16 17 18 19 20
            LLL FFF RRR BBB     21 22 23 24 25 26 27 28 29 30 31 32
            LLL FFF RRR BBB     33 34 35 36 37 38 39 40 41 42 43 44
                DDD                      45 46 47
                DDD                      48 49 50
                DDD                      51 52 53
	*/
    
    faces.push_back(Piece(RIGHT, std::make_tuple((Color)cubeString[28], Color::none, Color::none)));
    faces.push_back(Piece(LEFT,  std::make_tuple((Color)cubeString[22], Color::none, Color::none)));
    faces.push_back(Piece(UP,    std::make_tuple(Color::none, (Color)cubeString[4],  Color::none)));
    faces.push_back(Piece(DOWN,  std::make_tuple(Color::none, (Color)cubeString[49], Color::none)));
    faces.push_back(Piece(FRONT, std::make_tuple(Color::none, Color::none, (Color)cubeString[25])));
    faces.push_back(Piece(BACK,  std::make_tuple(Color::none, Color::none, (Color)cubeString[31])));
    edges.push_back(Piece(RIGHT + UP,    std::make_tuple((Color)cubeString[16], (Color)cubeString[5],  Color::none)));
    edges.push_back(Piece(RIGHT + DOWN,  std::make_tuple((Color)cubeString[40], (Color)cubeString[50], Color::none)));
    edges.push_back(Piece(RIGHT + FRONT, std::make_tuple((Color)cubeString[27], Color::none, (Color)cubeString[26])));
    edges.push_back(Piece(RIGHT + BACK,  std::make_tuple((Color)cubeString[29], Color::none, (Color)cubeString[30])));
    edges.push_back(Piece(LEFT + UP,     std::make_tuple((Color)cubeString[10], (Color)cubeString[3],  Color::none)));   
    edges.push_back(Piece(LEFT + DOWN,   std::make_tuple((Color)cubeString[34], (Color)cubeString[48], Color::none)));
    edges.push_back(Piece(LEFT + FRONT,  std::make_tuple((Color)cubeString[23], Color::none, (Color)cubeString[24])));
    edges.push_back(Piece(LEFT + BACK,   std::make_tuple((Color)cubeString[21], Color::none, (Color)cubeString[32])));
    edges.push_back(Piece(UP + FRONT,    std::make_tuple(Color::none, (Color)cubeString[7],  (Color)cubeString[13])));
    edges.push_back(Piece(UP + BACK,     std::make_tuple(Color::none, (Color)cubeString[1],  (Color)cubeString[19])));
    edges.push_back(Piece(DOWN + FRONT,  std::make_tuple(Color::none, (Color)cubeString[46], (Color)cubeString[37])));
    edges.push_back(Piece(DOWN + BACK,   std::make_tuple(Color::none, (Color)cubeString[52], (Color)cubeString[43])));
    corners.push_back(Piece(RIGHT + UP + FRONT,   std::make_tuple((Color)cubeString[15], (Color)cubeString[8],  (Color)cubeString[14])));
    corners.push_back(Piece(RIGHT + UP + BACK,    std::make_tuple((Color)cubeString[17], (Color)cubeString[2],  (Color)cubeString[18])));
    corners.push_back(Piece(RIGHT + DOWN + FRONT, std::make_tuple((Color)cubeString[39], (Color)cubeString[47], (Color)cubeString[38])));
    corners.push_back(Piece(RIGHT + DOWN + BACK,  std::make_tuple((Color)cubeString[41], (Color)cubeString[53], (Color)cubeString[42])));
    corners.push_back(Piece(LEFT + UP + FRONT,    std::make_tuple((Color)cubeString[11], (Color)cubeString[6],  (Color)cubeString[12])));
    corners.push_back(Piece(LEFT + UP + BACK,     std::make_tuple((Color)cubeString[9],  (Color)cubeString[0],  (Color)cubeString[20])));
    corners.push_back(Piece(LEFT + DOWN + FRONT,  std::make_tuple((Color)cubeString[35], (Color)cubeString[45], (Color)cubeString[36])));
    corners.push_back(Piece(LEFT + DOWN + BACK,   std::make_tuple((Color)cubeString[33], (Color)cubeString[51], (Color)cubeString[44])));
    pieces.insert(pieces.end(), faces.begin(), faces.end());
    pieces.insert(pieces.end(), edges.begin(), edges.end());
    pieces.insert(pieces.end(), corners.begin(), corners.end());
}