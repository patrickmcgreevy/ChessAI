#pragma once
#include "Rook.h"

Rook::Rook(int & x, int & y, bool & c, Piece *& board, Texture & text) :
	Piece(x, y, c, board)
{
	getSprite().setTexture(text);
}

Rook::~Rook()
{
	std::cout << "Rook destructor." << std::endl;
}

void Rook::capture(int & score, bool & victory)
{

}

void Rook::updateValidMoves()
{

}

void Rook::checkRowPosMoves()
{
	int cRow = getRow() + 1, cCol = getCol();

	while (checkValidMove(cRow, cCol))
	{
		queueMove(cRow, cCol);
		cRow++;
	}

	if (checkEnemyPiece(cRow, cCol))
	{
		queueMove(cRow, cCol);
	}
}