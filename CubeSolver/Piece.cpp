#include "Piece.h"
#include <tuple>

Piece::Piece(Point position, std::tuple<Color, Color, Color> colors) {
	// probably should add some validation here
	this->position = Point(position.x, position.y, position.z);
	this->colors = colors;
	setPieceType();
}

void Piece::rotate(int matrix[3][3]) {
	// rotate the piece
	//   edits the position matrix and colors
	// probably will have to make my own matrix class?
}

void Piece::setPieceType() {
	// set which piece it is based on how many colors are given
	int num = 0;
	if (std::get<0>(colors) == Color::none) num++;
	if (std::get<1>(colors) == Color::none) num++;
	if (std::get<2>(colors) == Color::none) num++;
	if (num == 0) type = PieceType::corner;
	else if (num == 1) type = PieceType::edge;
	else if (num == 2) type = PieceType:: face;
}