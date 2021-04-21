#include "Board.h"
#include "Input.h"


Board::Board(Window* window)
{
	this->window = window;
	for (int i = 1, j = 0; i < 8, j < 8; i++, j++)
	{
		pieces.push_back(new Piece(window, i, tileSize, true, j, 7));
		pieces.push_back(new Piece(window, 9, tileSize, true, j, 6));

		pieces.push_back(new Piece(window, i, tileSize, false, j, 0));
		pieces.push_back(new Piece(window, 9, tileSize, false, j, 1));
	}
}

Board::~Board()
{

}
