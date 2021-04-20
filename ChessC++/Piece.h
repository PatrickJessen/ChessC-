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

public:
	enum pieceType
	{
		King = 1,
		Pawn = 2,
		Knight = 3,
		Bishop = 4,
		Rook = 5,
		Queen = 6,
		BKing = 7,
		BPawn = 8,
		BKnight = 9,
		BBishop = 10,
		BRook = 11,
		BQueen = 12,
	};
	Piece(Window* window, int xPos, int yPos, pieceType type, bool isWhite, std::vector<Vector2D*> possiblePositions, const char* path);
	Piece() {}
	~Piece();

	bool CapturePiece(std::vector<Piece*> pieces, int xPos, int yPos, int index);

	void ShowAvailableMoves(Piece* clickedPiece, int board, SDL_Rect &rect);


public:
	SDL_Surface* surface;
	SDL_Texture* tex;
	SDL_Rect rect;
	pieceType type;
	std::vector<Vector2D*> possibleMoves;
	std::vector<Vector2D*> clearVector;
	bool isWhite;
	bool isSelected;
	bool isPlaced = false;
	int gridPosX;
	int gridPosY;

	const char* piecePath[12] = { "Assets/WhiteTower.png", "Assets/WhiteKnight.png", "Assets/WhiteBishop.png", "Assets/WhiteKing.png", "Assets/WhiteQueen.png", "Assets/WhitePawn.png", "Assets/BlackTower.png", "Assets/BlackKnight.png", "Assets/BlackBishop.png", "Assets/BlackKing.png", "Assets/BlackQueen.png", "Assets/BlackPawn.png" };
};

