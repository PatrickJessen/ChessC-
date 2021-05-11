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
		std::cout << clickedX / tileSize << " + " << clickedY / tileSize << "\n";
		isClicked = true;
	}
}

void UserManager::MovePiece(Piece* clickedPiece, int size, Board* board)
{
	if (isClicked && clickedPiece != NULL)
	{
		int x = clickedX / size;
		int y = clickedY / size;
		for (int i = 0; i < clickedPiece->availableMoves.size(); i++)
		{
			if (x == clickedPiece->availableMoves[i]->x && y == clickedPiece->availableMoves[i]->y)
			{
				board->boardArray[clickedPiece->gridPosY][clickedPiece->gridPosX] = 0;
				clickedPiece->gridPosX = x;
				clickedPiece->gridPosY = y;
				clickedPiece->rect.x = clickedX;
				clickedPiece->rect.y = clickedY;
				//CapturePiece(clickedPiece, board);
				isClicked = false;
			}
		}

	}
}

void UserManager::CapturePiece(Piece* clickedPiece, Board* board)
{
	for (int i = 0; i < board->pieces.size(); i++)
	{
		if (clickedPiece->gridPosX == board->pieces[i]->gridPosX && clickedPiece->gridPosY == board->pieces[i]->gridPosY)
		{
			board->pieces.erase(board->pieces.begin() + i);
		}
	}
}
