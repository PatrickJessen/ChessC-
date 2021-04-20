#include "BoardManager.h"
#include "Input.h"

BoardManager::BoardManager(Window* window)
{
	this->window = window;
	board = new Board(window);
}

void BoardManager::Update()
{
	board->mouseX = Input::MouseX() - (Input::MouseX() % board->tileSize);
	board->mouseY = Input::MouseY() - (Input::MouseY() % board->tileSize);
	board->board = board->boardArray[board->mouseY / board->tileSize][board->mouseX / board->tileSize];
	board->DrawBoard();
	board->DrawPieces();
	DrawSquare();
	Clear();
}

void BoardManager::DrawSquare()
{
	sqRect = { Input::MouseX() - (Input::MouseX() % board->tileSize), Input::MouseY() - (Input::MouseY() % board->tileSize), board->tileSize, board->tileSize };
	SDL_SetRenderDrawColor(window->GetRender(), 255, 0, 0, 255);
	SDL_RenderDrawRect(window->GetRender(), &sqRect);
}

void BoardManager::Clear()
{
	for (int i = 0; i < board->allPositions.size(); i++)
	{
		delete board->allPositions[i];
	}
	board->allPositions.clear();
	board->allPositions.swap(board->tempPos);
}

