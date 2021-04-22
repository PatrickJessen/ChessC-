#pragma once
#include "BoardManager.h"
#include "UserManager.h"
#include "Draw.h"

class GameManager
{
private:
	BoardManager* board;
	UserManager* user;
	Draw* draw;
public:
	GameManager(Window* window);

	void UpdateLogic();
	void UpdateGUI();

private:
	void CreateBoard();
	void CreatePieces();
	void CreateAvailableMoves();
	void UpdateClickedPiece();

	bool IsPieceSameColor(int x, int y);

	bool secondClick = false;

private:
	SDL_Rect highlighterRect;
};

