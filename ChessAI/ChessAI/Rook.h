#pragma once
#include "Piece.h"

using sf::Texture;

class Rook : public Piece
{
	Rook(int & x, int & y, bool & color, Piece *& board, Texture & rookTexture);
};