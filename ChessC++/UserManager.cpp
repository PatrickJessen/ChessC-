#include "UserManager.h"
#include "Input.h"

UserManager::UserManager()
{
	
}

void UserManager::ClickPiece(int tileSize)
{
	clickedX = Input::MouseX() - (Input::MouseX() % tileSize);
	clickedY = Input::MouseY() - (Input::MouseY() % tileSize);
	if (Input::MousePressed(MouseButton::LEFT))
	{
		if (isClicked)
		{
			isClicked = false;
			canMove = true;
		}
		else if (canMove)
		{
			canMove = false;
			isClicked = true;
		}
		else
			isClicked = true;
	}
}

void UserManager::MovePiece(Piece* clickedPiece, int size)
{
	if (canMove)
	{
		int x = clickedX / size;
		int y = clickedY / size;
		for (int i = 0; i < clickedPiece->availableMoves.size(); i++)
		{
			if (x == clickedPiece->availableMoves[i]->x && y == clickedPiece->availableMoves[i]->y)
			{
				clickedPiece->gridPosX = x;
				clickedPiece->gridPosY = y;
				clickedPiece->rect.x = clickedX;
				clickedPiece->rect.y = clickedY;
				return;
			}
		}
		canMove = false;
	}
}
