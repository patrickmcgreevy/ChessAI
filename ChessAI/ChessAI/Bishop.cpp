#pragma once
#include "Bishop.h"

Bishop::Bishop(const int & x, const int & y, const bool & color, vector<vector<Piece *>> * pBoard, Texture & knightTexture) :
	Piece(x, y, color, pBoard)
{
	std::cout << "Bishop constructor." << std::endl;
	getSprite().setTexture(knightTexture);
}

Bishop::~Bishop()
{
	std::cout << "Bishop destructor." << std::endl;
}

void Bishop::updateValidMoves()
{
	clearMoveList();

	checkRowNegColNeg();
	checkRowNegColPos();
	checkRowPosColNeg();
	checkRowPosColPos();
}

void Bishop::capture(int & score, bool & victory)
{

}

int Bishop::getAverageValue()
{
	return 330;
}

int Bishop::getAdjustedValue()
{
	return getAverageValue();
}

void Bishop::checkRowNegColPos()
{
	int moveRow = getRow() - 1, moveCol = getCol() + 1;

	while (checkValidMove(moveRow, moveCol))
	{
		queueMove(moveRow, moveCol);
		moveRow--;
		moveCol++;
	}

	if (checkEnemyPiece(moveRow, moveCol))
	{
		queueMove(moveRow, moveCol);
	}
}

void Bishop::checkRowPosColPos()
{
	int moveRow = getRow() + 1, moveCol = getCol() + 1;

	while (checkValidMove(moveRow, moveCol))
	{
		queueMove(moveRow, moveCol);
		moveRow++;
		moveCol++;
	}

	if (checkEnemyPiece(moveRow, moveCol))
	{
		queueMove(moveRow, moveCol);
	}
}
void Bishop::checkRowPosColNeg()
{
	int moveRow = getRow() + 1, moveCol = getCol() - 1;

	while (checkValidMove(moveRow, moveCol))
	{
		queueMove(moveRow, moveCol);
		moveRow++;
		moveCol--;
	}

	if (checkEnemyPiece(moveRow, moveCol))
	{
		queueMove(moveRow, moveCol);
	}
}

void Bishop::checkRowNegColNeg()
{
	int moveRow = getRow() - 1, moveCol = getCol() - 1;

	while (checkValidMove(moveRow, moveCol))
	{
		queueMove(moveRow, moveCol);
		moveRow--;
		moveCol--;
	}

	if (checkEnemyPiece(moveRow, moveCol))
	{
		queueMove(moveRow, moveCol);
	}
}