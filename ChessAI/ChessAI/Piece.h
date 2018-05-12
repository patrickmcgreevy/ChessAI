#pragma once

class Piece
{
public:
	Piece();
	Piece(int x, int y);
	Piece(Piece & p);
	~Piece();
protected:
	void setX(int x);
	void setY(int y);
private:
	int x, y;
};