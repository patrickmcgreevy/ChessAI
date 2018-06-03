#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(const int & x, const int & y, const bool & color, vector<vector<Piece *>> * pBoard, Texture & kingTexture);
	~King();

	void updateValidMoves();
	void capture(int & score, bool & victory);
	int getAverageValue();
	int getAdjustedValue();
	void printPieceToConsole();
};