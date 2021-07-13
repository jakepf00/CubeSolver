#pragma once
#include "CubeMath.h"
#include <tuple>

enum class Color { white='W', orange='O', green='G', red='R', blue='B', yellow='Y', none='N' };
enum class PieceType { face, edge, corner };

class Piece
{
public:
	Piece(Point position, std::tuple<Color, Color, Color> colors);
	Point position;
	std::tuple<Color, Color, Color> colors; // gives the color of side of piece on that axis (or none if it does not exist)

private:
	PieceType type;

	void rotate(int matrix[3][3]);
	void setPieceType();
};

