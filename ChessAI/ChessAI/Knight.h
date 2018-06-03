#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(const int & x, const int & y, const bool & color, vector<vector<Piece *>> * pBoard, Texture & knightTexture);
	~Knight();

	int getAverageValue(); // Returns the value 100 - 1,000 centipawns as defined by the derived class
	int getAdjustedValue(); // Returns the average value plus the value of each move it can make
	void updateValidMoves(); // Finds all valid squares for a piece to move to and pushes them to the vector
	void capture(int & score, bool &victory);
	void printPieceToConsole();

private:
	void checkUpwardMoves();
	void checkRightwardMoves();
	void checkDownwardMoves();
	void checkLeftwardMoves();
};