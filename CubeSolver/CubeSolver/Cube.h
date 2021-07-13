#pragma once
#include "Piece.h"
#include "CubeMath.h"
#include <string>
#include <vector>

class Cube
{
public:
	Cube(std::string cubeString);
private:
	std::vector<Piece> faces;
	std::vector<Piece> edges;
	std::vector<Piece> corners;
	std::vector<Piece> pieces;
};

