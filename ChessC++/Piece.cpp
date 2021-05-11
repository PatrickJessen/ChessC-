#include "Piece.h"
#include <string>

Piece::Piece(Window* window, int tileSize, PieceType type, bool isWhite, int rectX, int rectY)
{
	this->window = window;
	this->type = type;
	this->isWhite = isWhite;

	path = "Assets/";
	path.append(ToString(isWhite));
	path.append(ToString(type));

	StartProperties();
	surface = IMG_Load(path.c_str());
	tex = SDL_CreateTextureFromSurface(window->GetRender(), surface);
	rect = { rectX * tileSize, rectY * tileSize, size, size };
	gridPosX = rectX * tileSize / size;
	gridPosY = rectY * tileSize / size;
}

Piece::~Piece()
{
	SDL_DestroyTexture(tex);
	SDL_FreeSurface(surface);
}

bool Piece::CanContinueMoving()
{
	if (type == PieceType::Pawn || type == PieceType::Knight || type == PieceType::King)
	{
		return false;
	}
	return true;
}

bool Piece::IsWhite()
{
	if (isWhite)
	{
		return true;
	}
	return false;
}

void Piece::StartProperties()
{
	switch (type)
	{
	case PieceType::Tower:
		moves = { new Vector2D(0, 1), new Vector2D(1, 0), new Vector2D(-1, 0), new Vector2D(0, -1) };
		break;
	case PieceType::Knight:
		moves = { new Vector2D(2, 1), new Vector2D(1, 2), new Vector2D(2, -1), new Vector2D(-1, 2), new Vector2D(-2, 1), new Vector2D(-2, -1), new Vector2D(1, -2), new Vector2D(1, 2), new Vector2D(-1, 2), new Vector2D(-1, -2) };
		break;
	case PieceType::Bishop:
		moves = { new Vector2D(-1, 1), new Vector2D(-1, -1), new Vector2D(1, 1), new Vector2D(1, -1) };
		break;
	case PieceType::Queen:
		moves = { new Vector2D(0, 1), new Vector2D({ 1, 0 }), new Vector2D(-1, 0), new Vector2D(0, -1), new Vector2D(-1, 1), new Vector2D(-1, -1), new Vector2D(1, 1), new Vector2D(1, -1) };
		break;
	case PieceType::King:
		moves = { new Vector2D(0, 1), new Vector2D({ 1, 0 }), new Vector2D(-1, 0), new Vector2D(0, -1), new Vector2D(-1, 1), new Vector2D(-1, -1), new Vector2D(1, 1), new Vector2D(1, -1) };
		break;
	case PieceType::Pawn:
		if (isWhite)
			moves = { new Vector2D(0, -1), new Vector2D(0, -2) };
		else
			moves = { new Vector2D(0, 1), new Vector2D(0, 2) };
		break;
	}
}

// Convert enum type to string
inline const char* Piece::ToString(PieceType type)
{
	switch (type)
	{
	case PieceType::Tower: return "Tower.png";
	case PieceType::Knight: return "Knight.png";
	case PieceType::Bishop: return "Bishop.png";
	case PieceType::King: return "King.png";
	case PieceType::Queen: return "Queen.png";
	case PieceType::Pawn: return "Pawn.png";
	}
}

// convert bool type to string
inline const char* Piece::ToString(bool isWhite)
{
	if (isWhite)
	{
		return "White";
	}
	return "Black";
}


