#include "Rook.h"
#include <SFML/Graphics.hpp>

int main()
{
	Texture newText;
	vector<vector<Piece *>> boardArr;
	for (int i = 0; i <= 7; ++i)
	{
		boardArr.push_back(*(new vector<Piece *>));
		for (int j = 0; j <= 7; ++j)
		{
			boardArr[i].push_back(nullptr);
		}
	}

	//boardArr[3][4] = new Rook(3, 4, true, &boardArr, newText);
	Piece * pRook = new Rook(3, 4, true, &boardArr, newText);
	pRook = new Rook(3, 5, true, &boardArr, newText);
	pRook = new Rook(4, 4, true, &boardArr, newText);
	pRook = new Rook(3, 3, true, &boardArr, newText);
	pRook = new Rook(2, 4, true, &boardArr, newText);

	boardArr[3][4]->updateValidMoves();

	for (int i = 0; i <= 7; ++i)
	{
		for (int j = 0; j <= 7; ++j)
		{
			delete boardArr[i][j];
		}
	}

	std::cout << "done" << std::endl;

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