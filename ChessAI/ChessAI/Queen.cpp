#include "Queen.h"

Queen::Queen(const int & x, const int & y, const bool & color, vector<vector<Piece *>> * pBoard, Texture & queenTexture) :
	Piece(x, y, color, pBoard)
{
	std::cout << "Queen constructor." << std::endl;
	getSprite().setTexture(queenTexture);
}

Queen::~Queen()
{
	std::cout << "Queen destructor." << std::endl;
}

void Queen::updateValidMoves()
{
	clearMoveList();

	checkRowNegColPos();
	checkRowPosColPos();
	checkRowPosColNeg();
	checkRowNegColNeg();
	checkRowPosMoves();
	checkRowNegMoves();
	checkColPosMoves();
	checkColNegMoves();
}

void Queen::capture(int & score, bool & victory)
{

}

int Queen::getAverageValue()
{
	return 960;
}

int Queen::getAdjustedValue()
{
	return getAverageValue();
}

void Queen::checkRowNegColPos()
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

void Queen::checkRowPosColPos()
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
void Queen::checkRowPosColNeg()
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

void Queen::checkRowNegColNeg()
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

void Queen::checkRowPosMoves()
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

void Queen::checkRowNegMoves()
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

void Queen::checkColPosMoves()
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

void Queen::checkColNegMoves()
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