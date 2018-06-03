#include "ChessGameWrapper.h"

GameWrapper::GameWrapper()
{

}

GameWrapper::~GameWrapper()
{

}

void GameWrapper::initializeBlankBoard()
{
	for (int i = 0; i <= 7; ++i)
	{
		mBoard.push_back(*(new vector<Piece *>));
		for (int j = 0; j <= 7; ++j)
		{
			mBoard[i].push_back(nullptr);
		}
	}
}

void GameWrapper::initializeWhitePieces()
{
	bool white = true;

	new Rook(7, 0, white, &mBoard, mWhiteRook);
	new Rook(7, 7, white, &mBoard, mWhiteRook);
	new Bishop(7, 2, white, &mBoard, mWhiteBishop);
	new Bishop(7, 5, white, &mBoard, mWhiteBishop);
	new Knight(7, 1, white, &mBoard, mWhiteKnight);
	new Knight(7, 6, white, &mBoard, mWhiteKnight);
	new Queen(7, 3, white, &mBoard, mWhiteQueen);
	new King(7, 4, white, &mBoard, mWhiteKing);

	for (int col = 0; col < 8; ++col)
	{
		new Pawn(6, col, white, &mBoard, mWhitePawn);
	}
}

void GameWrapper::initializeBlackPieces()
{
	bool black = false;

	new Rook(0, 0, black, &mBoard, mBlackRook);
	new Rook(0, 7, black, &mBoard, mBlackRook);
	new Bishop(0, 2, black, &mBoard, mBlackBishop);
	new Bishop(0, 5, black, &mBoard, mBlackBishop);
	new Knight(0, 1, black, &mBoard, mBlackKnight);
	new Knight(0, 6, black, &mBoard, mBlackKnight);
	new Queen(0, 3, black, &mBoard, mBlackQueen);
	new King(0, 4, black, &mBoard, mBlackKing);
	
	for (int col = 0; col < 8; ++col)
	{
		new Pawn(1, col, black, &mBoard, mWhitePawn);
	}
}

void GameWrapper::initializeBoard()
{
	initializeBlankBoard();
	initializeWhitePieces();
	initializeBlackPieces();
}

void GameWrapper::resetBoard()
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			try {
				if (mBoard.at(i).at(j) != nullptr)
				{
					delete mBoard.at(i).at(j);
					mBoard.at(i).at(j) == nullptr;
				}
			}
			catch (...)
			{
				std::cout << "ERROR 1: Board cannot be reset because the board has not been initialized." << std::endl;
			}
		}
	}

	initializeWhitePieces();
	initializeBlackPieces();
}

void GameWrapper::printBoardToConsole()
{
	std::cout << "  ";
	for (int i = 1; i <= 8; ++i)
	{
		std::cout << " " << i << " ";
	}

	std::cout << std::endl;

	for (int i = 0; i < 8; ++i)
	{
		std::cout << (i + 1) << " ";
		for (int j = 0; j < 8; ++j)
		{
			std::cout << "|";
			if (mBoard[i][j] != nullptr)
			{
				mBoard[i][j]->printToConsole();
			}
			else
			{
				if ((i + 1) % 2 == (j + 1) % 2)
				{
					std::cout << "__";
				}
				else
				{
					std::cout << "xx";
				}
			}
		}
		std::cout << "|" << std::endl;
	}
}