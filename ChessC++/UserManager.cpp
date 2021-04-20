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
