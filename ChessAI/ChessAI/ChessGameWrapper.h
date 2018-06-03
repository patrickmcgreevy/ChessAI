#pragma once
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

class GameWrapper
{
public:
	GameWrapper();
	~GameWrapper();

	void initializeBoard();
	void resetBoard();
	void printBoardToConsole();

private:
	void initializeBlankBoard();
	void initializeWhitePieces();
	void initializeBlackPieces();

	vector<vector<Piece *>> mBoard;
	Texture mBlackPawn;
	Texture mWhitePawn;
	Texture mWhiteRook;
	Texture mBlackRook;
	Texture mWhiteBishop;
	Texture mBlackBishop;
	Texture mWhiteKnight;
	Texture mBlackKnight;
	Texture mWhiteKing;
	Texture mBlackKing;
	Texture mWhiteQueen;
	Texture mBlackQueen;
};