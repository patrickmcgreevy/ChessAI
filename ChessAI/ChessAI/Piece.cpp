#pragma once
#include "Piece.h"

Piece::Piece()
{
	rowCoord = 0;
	colCoord = 0;
	mColor = true;
	//mBoardArr = nullptr;
}

Piece::Piece(const int & x, const int & y, const bool & newColor, vector<vector<Piece *>> * pBoard) :
	rowCoord{ x }, colCoord{ y }, 
	mColor{ newColor }, 
	mBoard{pBoard}
{
	(*mBoard)[x][y] = this;
}

Piece::Piece(Piece & oldPiece) :
	rowCoord{oldPiece.getRow()}, colCoord{oldPiece.getCol()}, 
	mColor{oldPiece.getColor()},
	mBoard{oldPiece.mBoard},
	mSprite{oldPiece.mSprite}
{
}

Piece::~Piece()
{
	std::cout << "Piece destructor." << std::endl;
	//mBoardArr = nullptr;
	// Everything else should work
}

int Piece::getRow()
{
	return rowCoord;
}

int Piece::getCol()
{
	return colCoord;
}

bool Piece::getColor()
{
	return mColor;
}

Sprite & Piece::getSprite()
{
	return mSprite;
}

bool Piece::checkCoord(int n)
{
	return n <= 7 && n >= 0;
}

bool Piece::checkCoords(int x, int y)
{
	return checkCoord(x) && checkCoord(y);
}

void Piece::setRowCoord(int x)
{
	if (checkCoord(x))
	{
		rowCoord = x;
	}
}

void Piece::setColCoord(int y)
{
	if (checkCoord(y))
	{
		colCoord = y;
	}
}

void Piece::move(int x, int y)
{
	rowCoord = x;
	colCoord = y;
}

void Piece::move(sf::Vector2i v)
{
	move(v.x, v.y);
}

void Piece::updateSpriteLoc()
{
	mSprite.setPosition((WINDOW_WIDTH / 8) * colCoord, (WINDOW_HEIGHT / 8) * rowCoord);
}

bool Piece::checkValidMove(int x, int y)
{
	//Piece * tempBoard = mBoardArr;
	//tempBoard += x * 8 + y;
	//tempBoard += y;
	//return checkCoords(x, y) && ((tempBoard == nullptr || mColor != tempBoard->getColor()));
	return checkCoords(x, y) && (*mBoard)[x][y] == nullptr;
}

bool Piece::checkEnemyPiece(int x, int y)
{
	//Piece * tempLoc = mBoardArr;
	//tempLoc += x * 8 + y;

	return checkCoords(x, y) && ((*mBoard)[x][y] != nullptr) && ((*mBoard)[x][y]->getColor() != this->getColor());
}

void Piece::queueMove(int x, int y)
{
	sf::Vector2i newVec(x, y);

	mValidMoves.push_back(newVec);
}

void Piece::clearMoveList()
{
	mValidMoves.clear();
}

void Piece::printToConsole()
{
	if (mColor)
	{
		std::cout << "w";
	}
	else
	{
		std::cout << "b";
	}

	printPieceToConsole();
}