#include "Piece.h"

Piece::Piece(std::tuple<int, int, int> position, std::tuple<Color, Color, Color> colors) {
	// probably should add some validation here
	this->position = position;
	this->colors = colors;
}

void Piece::rotate(int matrix[3][3]) {
	// rotate the piece
	//   edits the position matrix and colors
}

void Piece::setPieceType() {
	// set which piece it is based on how many colors are given
}