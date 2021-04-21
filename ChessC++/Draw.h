#pragma once
#include "Window.h"
#include "BoardManager.h"
#include "Input.h"

class Draw
{
private:
	Window* window;
	BoardManager* board;

public:
	Draw(Window* window, BoardManager* board);

	void Update();

private:
	void DrawBoard();
	void DrawPiece();
	void DrawAvailableMoves();
	void DrawSquare();

	SDL_Rect sqRect;
};

