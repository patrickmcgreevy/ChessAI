#include "King.h"

King::King(const int & x, const int & y, const bool & color, vector<vector<Piece *>> * pBoard, Texture & kingTexture) :
	Piece(x, y, color, pBoard)
{
	std::cout << "King constructor." << std::endl;
	getSprite().setTexture(kingTexture);
}

King::~King()
{
	std::cout << "King destructor." << std::endl;
}

void King::updateValidMoves()
{
	int moveRow = getRow(), moveCol = getCol();

	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			if ((i != 0 || j != 0) && (checkValidMove(moveRow + i, moveCol + j) || checkEnemyPiece(moveRow + i, moveCol + j)))
			{
				queueMove(moveRow, moveCol);
			}
		}
	}
}

void King::capture(int & score, bool & victory)
{

}

int King::getAverageValue()
{
	return (1,000,000);
}

int King::getAdjustedValue()
{
	return getAverageValue();
}