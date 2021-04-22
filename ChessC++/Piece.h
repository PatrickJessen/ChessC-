#pragma once
#include "Window.h"
#include <vector>

struct Vector2D
{
	int x;
	int y;
public:
	Vector2D(int x, int y) { this->x = x; this->y = y; }
};

class Piece
{
private:
	Window* window;
	enum pieceType
	{
		Rook = 1,
		Knight = 2,
		Bishop = 3,
		Queen = 4,
		King = 5,
		fBishop = 6,
		fKnight = 7,
		fRook = 8,
		Pawn = 9,
	};

public:
	Piece(Window* window, int type, int tileSize, bool isWhite, int rectX, int rectY);
	~Piece();

	void ShowAvailableMoves(int board[8][8]);

	bool CanContinueMoving();

public:
	SDL_Surface* surface;
	SDL_Texture* tex;

	std::vector<Vector2D*> moves;
	std::vector<Vector2D*> availableMoves;

	int type;
	int gridPosX = 0;
	int gridPosY = 0;
	int size = 90;
	bool isWhite;

	SDL_Rect rect;

private:
	const char* path;
	void StartProperties(int tileSize);
};

