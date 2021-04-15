#pragma once
#include "Window.h"

class Piece
{
private:
	Window* window;
public:
	enum pieceType
	{
		none = 0,
		king = 1,
		pawn = 2,
		knight = 3,
		bishop = 4,
		rook = 5,
		queen = 6,
		white = 8,
		black = 16
	};



	Piece(Window* window);

	void DrawPiece();


	pieceType type;
	bool isWhite;
	const std::string GetPiece();

public:
	SDL_Surface* surface;
	SDL_Texture* tex;
};

