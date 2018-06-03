#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(const int & x, const int & y, const bool & color, vector<vector<Piece *>> * pBoard, Texture & pawnTexture);
	~Pawn();

	void updateValidMoves();
	void capture(int & score, bool & victory);
	int getAverageValue();
	int getAdjustedValue();
	void printPieceToConsole();

private:
	void updateValidMovesWhite();
	void updateValidMovesBlack();
	void updateValidMovesCaptures(int captureRow);
};