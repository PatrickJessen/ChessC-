#pragma once
#include "Board.h"

class BoardManager
{
private:
	Board* board;
	Window* window;

public:
	BoardManager(Window* window);

	void SetClickedPiece(int x, int y);
	Piece* GetClickedPiece();
	int GetBoardArray(int x, int y);
	void SetBoardArray(int x, int y, int value);
	void SetBoardRect(int x, int y);
	int GetTileSize();
	void GetAvailableMoves();
	SDL_Rect& GetBoardRect();
	std::vector<Piece*> GetPieceList();

private:
	Piece* clickedPiece;
};

