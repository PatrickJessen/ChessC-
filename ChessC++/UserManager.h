#pragma once
#include "Input.h"

class UserManager
{
public:
	UserManager();

	void ClickPiece();
	void MovePiece(int x, int y);

public:
	bool isClicked = false;;
	int clickedX;
	int clickedY;
};

