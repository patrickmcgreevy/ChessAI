#pragma once
#include "Knight.h"

Knight::Knight(const int & x, const int & y, const bool & color, vector<vector<Piece *>> * pBoard, Texture & knightTexture):
	Piece(x, y, color, pBoard)
{
	std::cout << "Knight constructor." << std::endl;
	getSprite().setTexture(knightTexture);
}
Knight::~Knight()
{
	std::cout << "Knight destructor." << std::endl;
}

int Knight::getAverageValue()
{
	return 320;
}



void Knight::updateValidMoves()
{
	clearMoveList();
	checkUpwardMoves();
	checkRightwardMoves();
	checkLeftwardMoves();
	checkDownwardMoves();
}

void Knight::checkUpwardMoves()
{
	int moveRow = getRow() - 2, moveCol = getCol() - 1;
	if (checkValidMove(moveRow, moveCol) || checkEnemyPiece(moveRow, moveCol))
	{
		queueMove(moveRow, moveCol);
	}

	moveCol += 2;

	if (checkValidMove(moveRow, moveCol) || checkEnemyPiece(moveRow, moveCol))
	{
		queueMove(moveRow, moveCol);
	}
}

void Knight::checkRightwardMoves()
{
	int moveRow = getRow() - 1, moveCol = getCol() + 2;
	if (checkValidMove(moveRow, moveCol) || checkEnemyPiece(moveRow, moveCol))
	{
		queueMove(moveRow, moveCol);
	}

	moveRow += 2;

	if (checkValidMove(moveRow, moveCol) || checkEnemyPiece(moveRow, moveCol))
	{
		queueMove(moveRow, moveCol);
	}
}

void Knight::checkDownwardMoves()
{
	int moveRow = getRow() + 2, moveCol = getCol() + 1;
	if (checkValidMove(moveRow, moveCol) || checkEnemyPiece(moveRow, moveCol))
	{
		queueMove(moveRow, moveCol);
	}

	moveCol -= 2;

	if (checkValidMove(moveRow, moveCol) || checkEnemyPiece(moveRow, moveCol))
	{
		queueMove(moveRow, moveCol);
	}
}

void Knight::checkLeftwardMoves()
{
	int moveRow = getRow() - 1, moveCol = getCol() - 2;
	if (checkValidMove(moveRow, moveCol) || checkEnemyPiece(moveRow, moveCol))
	{
		queueMove(moveRow, moveCol);
	}

	moveRow += 2;

	if (checkValidMove(moveRow, moveCol) || checkEnemyPiece(moveRow, moveCol))
	{
		queueMove(moveRow, moveCol);
	}
}


// No defs yet b/c I'm not sure which system I want to use yet
int Knight::getAdjustedValue()
{
	return getAverageValue();
}

void Knight::capture(int & score, bool & victory)
{

}

void Knight::printPieceToConsole()
{
	std::cout << "N";
}