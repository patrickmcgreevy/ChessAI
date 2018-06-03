#pragma once
#include "Rook.h"

Rook::Rook(const int & x, const int & y, const bool & c, vector<vector<Piece *>> * pBoard, Texture & text) :
	Piece(x, y, c, pBoard)
{
	std::cout << "Rook constructor." << std::endl;
	getSprite().setTexture(text);
}

Rook::~Rook()
{
	std::cout << "Rook destructor." << std::endl;
}

void Rook::capture(int & score, bool & victory)
{

}

int Rook::getAverageValue()
{
	return 520;
}

int Rook::getAdjustedValue()
{
	return getAverageValue();
}

void Rook::updateValidMoves()
{
	clearMoveList();
	checkColNegMoves();
	checkColPosMoves();
	checkRowNegMoves();
	checkRowPosMoves();
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

void Rook::checkRowNegMoves()
{
	int cRow = getRow() - 1, cCol = getCol();

	while (checkValidMove(cRow, cCol))
	{
		queueMove(cRow, cCol);
		cRow--;
	}

	if (checkEnemyPiece(cRow, cCol))
	{
		queueMove(cRow, cCol);
	}
}

void Rook::checkColPosMoves()
{
	int cRow = getRow(), cCol = getCol() + 1;

	while (checkValidMove(cRow, cCol))
	{
		queueMove(cRow, cCol);
		cCol++;
	}

	if (checkEnemyPiece(cRow, cCol))
	{
		queueMove(cRow, cCol);
	}
}

void Rook::checkColNegMoves()
{
	int cRow = getRow(), cCol = getCol() - 1;

	while (checkValidMove(cRow, cCol))
	{
		queueMove(cRow, cCol);
		cCol--;
	}

	if (checkEnemyPiece(cRow, cCol))
	{
		queueMove(cRow, cCol);
	}
}

void Rook::printPieceToConsole()
{
	std::cout << "R";
}