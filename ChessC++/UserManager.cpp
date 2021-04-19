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
		int test = board->boardArray[Input::MouseY() - (Input::MouseY() % board->tileSize)][Input::MouseX() - (Input::MouseX() % board->tileSize)];
		if (board->boardArray[Input::MouseY() - (Input::MouseY() % board->tileSize)][Input::MouseX() - (Input::MouseX() % board->tileSize)] != 0)
		{
			
		}
	}
}
