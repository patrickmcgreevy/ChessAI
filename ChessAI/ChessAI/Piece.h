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
	Piece(const int & x, const int & y, const bool & color, vector<vector<Piece *>> * pBoard);
	Piece(Piece & p);
	~Piece();

	int getRow();
	int getCol();
	Sprite & getSprite();
	void move(int newRow, int newCol); // Each move() moves the piece to the x and y coords if they're valid
	void move(sf::Vector2i newLoc);
	void updateSpriteLoc();
	bool getColor();
	virtual void updateValidMoves() = 0; // Finds all valid squares for a piece to move to and pushes them to the vector
	virtual void capture(int & score, bool & victory) = 0; // The piece has been captured. Update the captor's score and victory bool

protected:
	void setRowCoord(int nRow); // Set the member xCoord and yCoord
	void setColCoord(int yCoord);
	bool checkValidMove(int newX, int newY); // Checks that the move is within bounds of the board and the square isn't occupied by one of the player's
	void queueMove(int row, int col);
	bool checkEnemyPiece(int row, int col);

private:
	bool checkCoord(int coord); // True if [0, 7] (inclusive), false otherwise
	bool checkCoords(int row, int col); // Runs checkCoord() with x and y

	int rowCoord, colCoord;
	Color mColor; // true for white, false for black
	Sprite mSprite;
	//Piece * mBoardArr[8][8];
	//Piece * mBoardArr; // 8x8 array of pointers to pieces
	vector<vector<Piece *>> * mBoard;
	vector<sf::Vector2i> mValidMoves; // Vector for keeping track of squares the piece can move to
};