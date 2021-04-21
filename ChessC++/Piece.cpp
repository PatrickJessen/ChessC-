#include "Piece.h"
#include <string>

Piece::Piece(Window* window, int type, int tileSize, bool isWhite, int rectX, int rectY)
{
	this->window = window;
	this->type = type;
	this->isWhite = isWhite;

	StartProperties(tileSize);
	surface = IMG_Load(path);
	tex = SDL_CreateTextureFromSurface(window->GetRender(), surface);
	rect = { rectX * tileSize, rectY * tileSize, size, size };
	gridPosX = rectX / size;
	gridPosY = rectX / size;
}

Piece::~Piece()
{
	SDL_DestroyTexture(tex);
	SDL_FreeSurface(surface);
}

void Piece::StartProperties(int tileSize)
{
	switch (type)
	{
	case 5:
		moves = { new Vector2D(0, 1), new Vector2D({ 1, 0 }), new Vector2D(-1, 0), new Vector2D(0, -1), new Vector2D(-1, 1), new Vector2D(-1, -1), new Vector2D(1, 1), new Vector2D(1, -1) };
		if (isWhite)
			path = "Assets/WhiteKing.png";
		else
			path = "Assets/BlackKing.png";
		break;
	case 9:
		if (isWhite)
		{
			moves = { new Vector2D(0, -1), new Vector2D(0, -2) };
			path = "Assets/WhitePawn.png";
		}
		else
		{
			moves = { new Vector2D(0, 1), new Vector2D(0, 2) };
			path = "Assets/BlackPawn.png";
		}
		break;
	case 2:
		moves = { new Vector2D(2, 1), new Vector2D(1, 2), new Vector2D(2, -1), new Vector2D(-1, 2), new Vector2D(-2, 1), new Vector2D(-2, -1), new Vector2D(1, -2), new Vector2D(1, 2), new Vector2D(-1, 2), new Vector2D(-1, -2) };
		if (isWhite)
			path = "Assets/WhiteKnight.png";
		else
			path = "Assets/BlackKnight.png";
		break;
	case 3:
		moves = { new Vector2D(-1, 1), new Vector2D(-1, -1), new Vector2D(1, 1), new Vector2D(1, -1) };
		if (isWhite)
			path = "Assets/WhiteBishop.png";
		else
			path = "Assets/BlackBishop.png";
		break;
	case 1:
		moves = { new Vector2D(0, 1), new Vector2D(1, 0), new Vector2D(-1, 0), new Vector2D(0, -1) };
		if (isWhite)
			path = "Assets/WhiteTower.png";
		else
			path = "Assets/BlackTower.png";
		break;
	case 4:
		moves = { new Vector2D(0, 1), new Vector2D({ 1, 0 }), new Vector2D(-1, 0), new Vector2D(0, -1), new Vector2D(-1, 1), new Vector2D(-1, -1), new Vector2D(1, 1), new Vector2D(1, -1) };
		if (isWhite)
			path = "Assets/WhiteQueen.png";
		else
			path = "Assets/BlackQueen.png";
		break;
	case 7:
		moves = { new Vector2D(2, 1), new Vector2D(1, 2), new Vector2D(2, -1), new Vector2D(-1, 2), new Vector2D(-2, 1), new Vector2D(-2, -1), new Vector2D(1, -2), new Vector2D(1, 2), new Vector2D(-1, 2), new Vector2D(-1, -2) };
		if (isWhite)
			path = "Assets/WhiteKnight.png";
		else
			path = "Assets/BlackKnight.png";
		break;
	case 6:
		moves = { new Vector2D(-1, 1), new Vector2D(-1, -1), new Vector2D(1, 1), new Vector2D(1, -1) };
		if (isWhite)
			path = "Assets/WhiteBishop.png";
		else
			path = "Assets/BlackBishop.png";
		break;
	case 8:
		moves = { new Vector2D(0, 1), new Vector2D(1, 0), new Vector2D(-1, 0), new Vector2D(0, -1) };
		if (isWhite)
			path = "Assets/WhiteTower.png";
		else
			path = "Assets/BlackTower.png";
		break;
	}
}

