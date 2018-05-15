#pragma once
#include "Piece.h"

using sf::Texture;

class Rook : public Piece
{
public:
	Rook(int & x, int & y, bool & color, Piece *& board, Texture & rookTexture);
	~Rook();

	void updateValidMoves();
	void capture(int & score, bool & victory);

private:
	void checkRowPosMoves();
	void checkRowNegMoves();
	void checkColPosMoves();
	void checkColNegMoves();
};