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
		isClicked = true;
		timesClicked++;
		if (timesClicked > 2)
		{
			timesClicked = 0;
			isClicked = false;
		}
	}
}

void UserManager::MovePiece(Piece* clickedPiece, int size, bool secondClick)
{
	if (timesClicked == 2)
	{
		for (int i = 0; i < clickedPiece->moves.size(); i++)
		{
			int x = clickedPiece->moves[i]->x + clickedPiece->gridPosX;
			int y = clickedPiece->moves[i]->y + clickedPiece->gridPosY;
			if (x == clickedX / size && y == clickedY / size)
			{
				clickedPiece->gridPosX = clickedX / size;
				clickedPiece->gridPosY = clickedY / size;
				clickedPiece->rect.x = clickedX;
				clickedPiece->rect.y = clickedY;
				return;
			}
		}
	}
}
