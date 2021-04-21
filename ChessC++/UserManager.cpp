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
		if (board->isClicked)
		{
			MovePiece();
		}
		else if (board->board != 0)
		{
			std::cout << board->mouseX << " + " << board->mouseY << " + " << board->board << "\n";
			board->highlighterRect = { board->mouseX, board->mouseY, board->tileSize, board->tileSize };
			board->isClicked = true;

			for (int i = 0; i < board->pieces.size(); i++)
			{
				if (board->pieces[i]->rect.x == board->mouseX && board->pieces[i]->rect.y == board->mouseY)
				{
					board->clickedPiece = board->pieces[i];
					tempPiecePosX = board->pieces[i]->gridPosX;
					tempPiecePosY = board->pieces[i]->gridPosY;
					return;
				}
			}
		}
	}
}

void UserManager::MovePiece()
{
	board->isClicked = false;
	int x = board->mouseX / board->tileSize;
	int y = board->mouseY / board->tileSize;
	int tempGridX = board->clickedPiece->gridPosX;
	int tempGridY = board->clickedPiece->gridPosY;
	for (int i = 0; i < board->allPositions.size(); i++)
	{
		if (board->allPositions[i]->x == x && board->allPositions[i]->y == y && !board->IsSameColor(x, y))
		{
			board->boardArray[tempPiecePosY][tempPiecePosX] = 0;
			board->clickedPiece->gridPosX = x;
			board->clickedPiece->gridPosY = y;
			board->clickedPiece->rect.x = board->mouseX;
			board->clickedPiece->rect.y = board->mouseY;
			CapturePiece(board->mouseX / board->tileSize, board->mouseY / board->tileSize);
			return;
		}
	}
}

void UserManager::CapturePiece(int x, int y)
{
	for (int i = 0; i < board->pieces.size(); i++)
	{
		if (board->pieces[i] != board->clickedPiece)
		{
			if (board->clickedPiece->gridPosX == board->pieces[i]->gridPosX && board->clickedPiece->gridPosY == board->pieces[i]->gridPosY)
			{
				board->boardArray[y][x] = 0;
				board->pieces.erase(board->pieces.begin() + i);
				return;
			}
		}
	}
}
