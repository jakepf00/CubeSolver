#pragma once
#include<tuple>

enum Color { white, orange, green, red, blue, yellow, none };
enum PieceType { face, edge, corner };

class Piece
{
public:
	Piece(std::tuple<int, int, int> position, std::tuple<Color, Color, Color> colors);

private:
	std::tuple<int, int, int> position; // x, y, z (all 0, 1, or -1)
	std::tuple<Color, Color, Color> colors; // gives the color of side of piece on that axis (or none if it does not exist)
	PieceType type;

	void rotate(int matrix[3][3]);
	void setPieceType();
};

