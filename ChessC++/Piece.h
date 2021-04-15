#pragma once
#include "Window.h"

class Piece
{
private:
	Window* window;
public:
	enum pieceType
	{
		pawn = 0,
		rook = 1,
		knight = 2,
		bishop = 3,
		queen = 4,
		king = 5
	};



	Piece(Window* window);

	void DrawPiece();

	pieceType type;
	bool isWhite;
	const std::string GetPiece();
};

