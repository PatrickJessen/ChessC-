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
	void SetBoardArray(int x, int y, int value);
	void SetBoardRect(int x, int y);
	void SetClickedPieceToNULL() { clickedPiece = NULL; }
	void RemovePieceAtIndex(int i);
	void GetAvailableMoves();
	void GetAvailablePawnMoves(int x, int y);
	void CanPawnCapture();
	bool CanPawnCaptureTest();
	bool CanPawnMove(int x, int y);
	int GetBoardArray(int x, int y);
	int GetTileSize();
	int GetClickedX() { return Input::MouseX() - (Input::MouseX() % board->tileSize); }
	int GetClickedY() { return Input::MouseY() - (Input::MouseY() % board->tileSize); }
	Piece* GetClickedPiece();
	SDL_Rect& GetBoardRect();
	std::vector<Piece*> GetPieceList();

	bool CheckTurn() { return board->CheckTurn(clickedPiece); }
	void SetTurn();

	bool IsSameColor(int x, int y);
	void CheckIfPawnMoved();

private:
	Piece* clickedPiece;
	bool isPieceSameColor(int x, int y);
};

