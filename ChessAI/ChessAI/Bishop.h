#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(const int & x, const int & y, const bool & color, vector<vector<Piece *>> * pBoard, Texture & knightTexture);
	~Bishop();

	void updateValidMoves();
	void capture(int & score, bool & victory);
	int getAverageValue();
	int getAdjustedValue();
private:
	void checkRowNegColPos();
	void checkRowPosColPos();
	void checkRowPosColNeg();
	void checkRowNegColNeg();
};