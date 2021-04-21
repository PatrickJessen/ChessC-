#pragma once
#include "Window.h"
#include "Piece.h"
#include <vector>

const static int row = 8;
const static int col = 8;

class Board
{
private:
	Window* window;

public:
	Board(Window* window);
	~Board();

	int tileSize = 94;
	int boardArray[col][row];
	std::vector<Piece*> pieces;
	SDL_Rect boardRect;
};

