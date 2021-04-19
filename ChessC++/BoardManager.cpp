#include "BoardManager.h"
#include "Input.h"

BoardManager::BoardManager(Window* window)
{
	this->window = window;
	board = new Board(window);
}

void BoardManager::Update()
{
	board->DrawHighlighter();
	board->DrawBoard();
	board->DrawPieces();
	DrawSquare();
}

void BoardManager::DrawSquare()
{
	sqRect = { Input::MouseX() - (Input::MouseX() % board->tileSize), Input::MouseY() - (Input::MouseY() % board->tileSize), board->tileSize, board->tileSize };
	SDL_SetRenderDrawColor(window->GetRender(), 255, 0, 0, 255);
	SDL_RenderDrawRect(window->GetRender(), &sqRect);
}