#include "Draw.h"

Draw::Draw(Window* window)
{
	this->window = window;
}

void Draw::DrawAvailableMoves(SDL_Rect& movesRect)
{
	SDL_SetRenderDrawColor(window->GetRender(), 255, 0, 0, 100);
	SDL_RenderFillRect(window->GetRender(), &movesRect);
}

void Draw::DrawBoard(SDL_Rect &boardRect, int r, int c)
{
	if ((r + c) % 2 == 0)
	{
		SDL_SetRenderDrawColor(window->GetRender(), 255, 255, 255, 50);
	}
	else
	{
		SDL_SetRenderDrawColor(window->GetRender(), 150, 105, 63, 255);
	}
	SDL_RenderFillRect(window->GetRender(), &boardRect);
}

void Draw::DrawPiece(SDL_Texture &tex, SDL_Rect &pieceRect)
{
	SDL_RenderCopy(window->GetRender(), &tex, NULL, &pieceRect);
}


void Draw::DrawSquare(int tileSize)
{
	sqRect = { Input::MouseX() - (Input::MouseX() % tileSize), Input::MouseY() - (Input::MouseY() % tileSize), tileSize, tileSize };
	SDL_SetRenderDrawColor(window->GetRender(), 255, 0, 0, 255);
	SDL_RenderDrawRect(window->GetRender(), &sqRect);
}
