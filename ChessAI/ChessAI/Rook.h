#pragma once
#include "Piece.h"

using sf::Texture;

class Rook : public Piece
{
public:
	Rook(const int & x, const int & y, const bool & color, vector<vector<Piece *>> * pBoard, Texture & rookTexture);
	~Rook();

	void updateValidMoves();
	void capture(int & score, bool & victory);

private:
	void checkRowPosMoves();
	void checkRowNegMoves();
	void checkColPosMoves();
	void checkColNegMoves();
};