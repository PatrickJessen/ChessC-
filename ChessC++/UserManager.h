#pragma once
#include "Board.h"

class UserManager
{
private:
	Board* board;

public:
	UserManager(Board* board);

public:
	void Update(Window* window);

private:
	void ClickPiece(Window* window);
	void MovePiece();
	void CapturePiece(int x, int y);

	int tempPiecePosX = 0;
	int tempPiecePosY = 0;

	SDL_Rect test;
};

