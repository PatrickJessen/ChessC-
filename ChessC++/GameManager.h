#pragma once
#include "BoardManager.h"
#include "UserManager.h"
#include "Draw.h"

class GameManager
{
private:
	UserManager* user;
	Draw* draw;
public:
	BoardManager* board;
	GameManager(Window* window);

	void UpdateLogic();
	void UpdateGUI();

private:
	void CreateBoard();
	void CreatePieces();
	void CreateAvailableMoves();
	void UpdateClickedPiece();
	void Clear();

	bool IsPieceSameColor(int x, int y);

	bool secondClick = false;
	bool whiteGoes = true;

private:
	SDL_Rect highlighterRect;
};

