#include "Draw.h"

Draw::Draw(Window* window, BoardManager* board)
{
	this->window = window;
	this->board = board;
}

void Draw::Update()
{
	DrawBoard();
	DrawPiece();
	DrawAvailableMoves();
	DrawSquare();
}

void Draw::DrawBoard()
{
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			board->SetBoardRect(r, c);
			if ((r + c) % 2 == 0)
			{
				SDL_SetRenderDrawColor(window->GetRender(), 255, 255, 255, 50);
			}
			else
			{
				SDL_SetRenderDrawColor(window->GetRender(), 150, 105, 63, 255);
			}
			SDL_RenderFillRect(window->GetRender(), &board->GetBoardRect());
		}
	}
}

void Draw::DrawPiece()
{
	for (int i = 0; i < board->GetPieceList().size(); i++)
	{
		board->SetBoardArray(board->GetPieceList()[i]->rect.x / board->GetTileSize(), board->GetPieceList()[i]->rect.y / board->GetTileSize(), board->GetPieceList()[i]->type);
		if (board->GetBoardArray(board->GetPieceList()[i]->rect.x / board->GetTileSize(), board->GetPieceList()[i]->rect.y / board->GetTileSize()) != 0)
		{
			SDL_RenderCopy(window->GetRender(), board->GetPieceList()[i]->tex, NULL, &board->GetPieceList()[i]->rect);
		}
	}
}

void Draw::DrawAvailableMoves()
{
	for (int i = 0; i < board->GetClickedPiece()->moves.size(); i++)
	{

	}
}

void Draw::DrawSquare()
{
	sqRect = { Input::MouseX() - (Input::MouseX() % board->GetTileSize()), Input::MouseY() - (Input::MouseY() % board->GetTileSize()), board->GetTileSize(), board->GetTileSize() };
	SDL_SetRenderDrawColor(window->GetRender(), 255, 0, 0, 255);
	SDL_RenderDrawRect(window->GetRender(), &sqRect);
}
