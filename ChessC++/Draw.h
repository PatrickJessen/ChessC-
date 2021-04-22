#pragma once
#include "Window.h"
#include "BoardManager.h"
#include "Input.h"

class Draw
{
private:
	Window* window;

public:
	Draw(Window* window);

	void DrawAvailableMoves(Piece* piece, int tileSize);
	void DrawBoard(SDL_Rect & boardRect, int r, int c);
	void DrawPiece(SDL_Texture &tex, SDL_Rect& pieceRect);
	void DrawSquare(int tileSize);

private:
	SDL_Rect sqRect;
	SDL_Rect movesRect;
};

