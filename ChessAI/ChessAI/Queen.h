#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(const int & x, const int & y, const bool & color, vector<vector<Piece *>> * pBoard, Texture & queenTexture);
	~Queen();

	void updateValidMoves();
	void capture(int & score, bool & victory);
	int getAverageValue();
	int getAdjustedValue();
	void printPieceToConsole();

private:
	void checkRowNegColPos();
	void checkRowPosColPos();
	void checkRowPosColNeg();
	void checkRowNegColNeg();
	void checkRowPosMoves();
	void checkRowNegMoves();
	void checkColPosMoves();
	void checkColNegMoves();
};