#pragma once
#include "Board.h"

class BoardManager
{
private:
	Window* window;

public:
	Board* board;
	BoardManager(Window* window);

public:
	void Update();

private:
	void DrawSquare();
	void Clear();
	SDL_Rect sqRect;
};

