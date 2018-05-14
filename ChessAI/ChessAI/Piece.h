#pragma once
#include <vector>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "UniversalDimesions.h"

typedef bool Color;

using std::vector;
using sf::Sprite;

class Piece
{
public:
	Piece();
	Piece(int & x, int & y, bool & color, Piece *& pBoard);
	Piece(Piece & p);
	~Piece();

	int getX();
	int getY();
	bool move(int newX, int newY); // Each move() moves the piece to the x and y coords if they're valid
	bool move(sf::Vector2i newLoc);
	void updateSpriteLoc();
	bool getColor();
	virtual void updateValidMoves() = 0; // Finds all valid squares for a piece to move to and pushes them to the vector
	virtual void capture(int & score, bool & victory) = 0; // The piece has been captured. Update the captor's score and victory bool

protected:
	void setXCoord(int xCoord); // Set the member xCoord and yCoord
	void setYCoord(int yCoord);

private:
	bool checkCoord(int coord); // True if [0, 7] (inclusive), false otherwise
	bool checkCoords(int x, int y); // Runs checkCoord() with x and y
	bool checkValidMove(int newX, int newY); // Checks that the move is within bounds of the board and the square isn't occupied by one of the player's

	int xCoord, yCoord;
	Color mColor; // true for white, false for black
	Sprite mSprite;
	//Piece * mBoardArr[8][8];
	Piece * mBoardArr; // 8x8 array of pointers to pieces
	vector<sf::Vector2i> mValidMoves; // Vector for keeping track of squares the piece can move to
};