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

enum class PieceType
{
	None = 0,
	Tower = 1,
	Knight = 2,
	Bishop = 3,
	Queen = 4,
	King = 5,
	Pawn = 6
};

class Piece
{
private:
	Window* window;

public:
	Piece(Window* window, int tileSize, PieceType type, bool isWhite, int rectX, int rectY);
	~Piece();


	bool CanContinueMoving();
	bool IsWhite();
	int GetXPos() { return gridPosX; }
	int GetYPos() { return gridPosY; }
	void SetXPos(int value) { gridPosX = value; }
	void SetYPos(int value) { gridPosY = value; }
	PieceType GetType() { return type; }
	SDL_Rect& GetRect() { return rect; }

public:
	SDL_Surface* surface;
	SDL_Texture* tex;

	std::vector<Vector2D*> moves;
	std::vector<Vector2D*> availableMoves;

	PieceType type;
	int gridPosX = 0;
	int gridPosY = 0;
	int size = 90;
	bool isWhite;
	bool hasMoved = false;
	bool isChecked = false;

	SDL_Rect rect;

private:
	std::string path;
	void StartProperties();

private:
	inline const char* ToString(PieceType type);
	inline const char* ToString(bool isWhite);
};

