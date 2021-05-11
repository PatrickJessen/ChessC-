#pragma once
#include "Board.h"

class BoardManager
{
private:
	Window* window;

public:
	BoardManager(Window* window);
	Board* board;

	void SetClickedPiece(int x, int y);
	Piece* GetClickedPiece();
	int GetBoardArray(int x, int y);
	void SetBoardArray(int x, int y, int value);
	void SetBoardRect(int x, int y);
	bool CheckTurn();
	int GetTileSize();
	void GetAvailableMoves();
	SDL_Rect& GetBoardRect();
	std::vector<Piece*> GetPieceList();

	bool IsSameColor(int x, int y);

private:
	Piece* clickedPiece;
	bool isPieceSameColor(int x, int y);
	bool whiteGoes = true;
};

