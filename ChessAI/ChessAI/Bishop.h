#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(const int & x, const int & y, const bool & color, vector<vector<Piece *>> * pBoard, Texture & bishopTexture);
	~Bishop();

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
};