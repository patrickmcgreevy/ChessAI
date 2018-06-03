#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "ChessGameWrapper.h"
#include <SFML/Graphics.hpp>

int main()
{
	GameWrapper newGame;
	newGame.initializeBoard();
	newGame.printBoardToConsole();
	//Texture newText;
	//vector<vector<Piece *>> boardArr;
	//for (int i = 0; i <= 7; ++i)
	//{
	//	boardArr.push_back(*(new vector<Piece *>));
	//	for (int j = 0; j <= 7; ++j)
	//	{
	//		boardArr[i].push_back(nullptr);
	//	}
	//}

	//Piece * pPawn = new Pawn(6, 4, true, &boardArr, newText);

	//Piece * pRook = new Rook(5, 3, false, &boardArr, newText); // Enemy capable
	//pRook = new Rook(5, 5, true, &boardArr, newText); // Ally
	//pRook = new Rook(5, 4, false, &boardArr, newText); // In way
	//pRook = new Rook(3, 2, true, &boardArr, newText);
	//pRook = new Rook(6, 6, false, &boardArr, newText);

	//boardArr[6][4]->updateValidMoves();
	//boardArr[3][4]->updateValidMoves();

	/*for (int i = 0; i <= 7; ++i)
	{
		for (int j = 0; j <= 7; ++j)
		{
			delete boardArr[i][j];
		}
	}

	std::cout << "done" << std::endl;*/

	/*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;*/
}