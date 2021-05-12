#pragma once
#include "Input.h"
#include "Piece.h"
#include "Board.h"
#include "BoardManager.h"

class UserManager
{
public:
	UserManager();

	void ClickPiece(int tileSize, BoardManager* board);
	void MovePiece(Piece* clickedPiece, int size, BoardManager* board);

public:
	bool isClicked = false;
	int clickedX;
	int clickedY;

private:
	void CapturePiece(Piece* clickedPiece, BoardManager* board);
	int clickCount = 0;
	bool whiteGoes = true;
};

