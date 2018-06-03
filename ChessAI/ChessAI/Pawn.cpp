#include "Pawn.h"

Pawn::Pawn(const int & x, const int & y, const bool & color, vector<vector<Piece *>> * pBoard, Texture & pawnTexture) :
	Piece(x, y, color, pBoard)
{
	std::cout << "Pawn const constructor." << std::endl;
	getSprite().setTexture(pawnTexture);
}

Pawn::~Pawn()
{
	std::cout << "Pawn constructor." << std::endl;
}

void Pawn::updateValidMoves()
{
	if (getColor())
	{
		updateValidMovesWhite();
	}
	else 
	{
		updateValidMovesBlack();
	}
}

void Pawn::updateValidMovesWhite()
{
	int moveTries = 1, moveRow = getRow() - 1, i = 0;
	
	if (getRow() == 6)
	{
		++moveTries;
	}

	while (checkValidMove(moveRow, getCol()) && i < moveTries)
	{
		queueMove(moveRow, getCol());
		moveRow--;
		i++;
	}

	updateValidMovesCaptures(getRow() - 1);
}

void Pawn::updateValidMovesBlack()
{
	int moveTries = 1, moveRow = getRow() + 1, i = 0;

	if (getRow() == 1)
	{
		++moveTries;
	}

	while (checkValidMove(moveRow, getCol()) && i < moveTries)
	{
		queueMove(moveRow, getCol());
		moveRow++;
		i++;
	}
	/*for (int i = 0; i < moveTries; ++i)
	{
		if (checkValidMove(moveRow + i, getCol()))
		{
			queueMove(moveRow + i, getCol());
		}
	}*/

	updateValidMovesCaptures(getRow() + 1);
}

void Pawn::updateValidMovesCaptures(int captureRow)
{
	if (checkEnemyPiece(captureRow, getCol() - 1))
	{
		queueMove(captureRow, getCol() - 1);
	}

	if (checkEnemyPiece(captureRow, getCol() + 1))
	{
		queueMove(captureRow, getCol() + 1);
	}
}

void Pawn::capture(int & score, bool & victory)
{

}

int Pawn::getAverageValue()
{
	return 100;
}

int Pawn::getAdjustedValue()
{
	return getAverageValue();
}

void Pawn::printPieceToConsole()
{
	std::cout << "P";
}