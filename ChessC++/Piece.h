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
		King = 1,
		Pawn = 2,
		Knight = 3,
		Bishop = 4,
		Rook = 5,
		Queen = 6,
		White = 8,
		Black = 16
	};


	Piece(Window* window, int xPos, int yPos, bool isWhite, const char* path);
	Piece() {}
	~Piece();

	void LoadPieces(int tileSize);


	pieceType type;
	bool isWhite;
	const char* GetPiece();

public:
	SDL_Surface* surface;
	SDL_Texture* tex;
	SDL_Rect rect;

	const char* whitePieces[16] = { "Assets/WhiteTower.png", "Assets/WhiteKnight.png", "Assets/WhiteBishop.png", "Assets/WhiteKing.png", "Assets/WhiteQueen.png", "Assets/WhiteBishop.png", "Assets/WhiteKnight.png", "Assets/WhiteTower.png", "Assets/WhitePawn.png", "Assets/WhitePawn.png", "Assets/WhitePawn.png", "Assets/WhitePawn.png", "Assets/WhitePawn.png", "Assets/WhitePawn.png", "Assets/WhitePawn.png", "Assets/WhitePawn.png" };
};

