#pragma once
#include "Window.h"
#include <vector>

enum class pieceType
{
	none = 0,
	King = 1,
	Pawn = 2,
	Knight = 3,
	Bishop = 4,
	Rook = 5,
	Queen = 6,
	Clicked = 7
};
class Piece
{
private:
	Window* window;

public:
	Piece(Window* window, int xPos, int yPos, pieceType type, bool isWhite, const char* path);
	Piece() {}
	~Piece();

	bool CapturePiece(std::vector<Piece*> pieces, int xPos, int yPos, int index);

	void ShowAvailableMoves();


public:
	SDL_Surface* surface;
	SDL_Texture* tex;
	SDL_Rect rect;
	pieceType type;
	bool isWhite;
	bool isSelected;
	bool isPlaced = false;

	const char* piecePath[12] = { "Assets/WhiteTower.png", "Assets/WhiteKnight.png", "Assets/WhiteBishop.png", "Assets/WhiteKing.png", "Assets/WhiteQueen.png", "Assets/WhitePawn.png", "Assets/BlackTower.png", "Assets/BlackKnight.png", "Assets/BlackBishop.png", "Assets/BlackKing.png", "Assets/BlackQueen.png", "Assets/BlackPawn.png" };
};

