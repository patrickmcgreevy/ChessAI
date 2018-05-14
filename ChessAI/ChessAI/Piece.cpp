#pragma once
#include "Piece.h"

Piece::Piece()
{
	xCoord = 0;
	yCoord = 0;
	mColor = true;
	mBoardArr = nullptr;
}

Piece::Piece(int & x, int & y, bool & newColor, Piece *& board) :
	xCoord{ x }, yCoord{ y }, 
	mColor{ newColor }, 
	mBoardArr{board}
{
}

Piece::Piece(Piece & oldPiece) :
	xCoord{oldPiece.getX()}, yCoord{oldPiece.getY()}, 
	mColor{oldPiece.getColor()},
	mBoardArr{oldPiece.mBoardArr},
	mSprite{oldPiece.mSprite}
{
}

Piece::~Piece()
{
	std::cout << "Piece destructor." << std::endl;
	mBoardArr = nullptr;
	// Everything else should work
}

int Piece::getX()
{
	return xCoord;
}

int Piece::getY()
{
	return yCoord;
}

bool Piece::getColor()
{
	return mColor;
}

bool Piece::checkCoord(int n)
{
	return n <= 7 && n >= 0;
}

bool Piece::checkCoords(int x, int y)
{
	return checkCoord(x) && checkCoord(y);
}

void Piece::setXCoord(int x)
{
	if (checkCoord(x))
	{
		xCoord = x;
	}
}

void Piece::setYCoord(int y)
{
	if (checkCoord(y))
	{
		yCoord = y;
	}
}

bool Piece::move(int x, int y)
{

}

bool Piece::move(sf::Vector2i v)
{
	move(v.x, v.y);
}

void Piece::updateSpriteLoc()
{
	mSprite.setPosition((WINDOW_WIDTH / 8) * xCoord, (WINDOW_HEIGHT / 8) * yCoord);
}

bool Piece::checkValidMove(int x, int y)
{
	return checkCoords(x, y) && (mBoardArr[x][y] == nullptr || mColor != mBoardArr[x][y]->getColor());
}