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
	std::vector<Piece> pieces;

public:
	Board(Window* window);

public:
	void DrawBoard();

private:
	int boardArray[row][col];
	int tileSize = 74;
	SDL_Rect boardRect;
};

