#include "UserManager.h"
#include "Input.h"

UserManager::UserManager(Board* board)
{
	this->board = board;
}

void UserManager::Update(Window* window)
{
	ClickPiece(window);
}

void UserManager::ClickPiece(Window* window)
{
	if (Input::MousePressed(MouseButton::LEFT))
	{
		MovePiece();
		if (board->board != 0)
		{
			std::cout << board->mouseX << " + " << board->mouseY << " + " << board->board << "\n";
			board->highlighterRect = { board->mouseX, board->mouseY, board->tileSize, board->tileSize };
			board->isClicked = true;

			for (int i = 0; i < board->pieces.size(); i++)
			{
				if (board->pieces[i]->rect.x == board->mouseX && board->pieces[i]->rect.y == board->mouseY)
				{
					board->clickedPiece = board->pieces[i];
				}
			}
		}
	}
}

void UserManager::MovePiece()
{
	if (board->isClicked)
	{
		int x = board->mouseX / board->tileSize;
		int y = board->mouseY / board->tileSize;
		for (int i = 0; i < board->allPositions.size(); i++)
		{
			if (board->allPositions[i]->x == x && board->allPositions[i]->y == y)
			{
				board->boardArray[board->clickedPiece->gridPosY][board->clickedPiece->gridPosX] = 0;
				board->clickedPiece->rect.x = board->mouseX;
				board->clickedPiece->rect.y = board->mouseY;
				board->isClicked = false;
			}
		}
	}
}
