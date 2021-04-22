#pragma once
#include "Input.h"
#include "Piece.h"

class UserManager
{
public:
	UserManager();

	void ClickPiece(int tileSize);
	void MovePiece(Piece* clickedPiece, int size, bool secondClick);

public:
	bool isClicked = false;;
	int clickedX;
	int clickedY;

	int timesClicked = 0;
};

