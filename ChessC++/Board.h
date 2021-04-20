#pragma once
#include "Window.h"
#include "Piece.h"
#include <vector>

const static int row = 8;
const static int col = 8;

class Board
{
private:
	Window* window;
	Piece* piece = new Piece();

public:
	Board(Window* window);
	~Board();


public:
	void DrawBoard();
	void DrawPieces();
	void DrawHighlighter();
	void ShowAvailableMoves();
	bool IsSameColor(int x, int y);

	std::vector<Piece*> pieces;
	SDL_Rect boardRect;
	SDL_Rect highlighterRect;
	Piece* clickedPiece;
	std::vector<Vector2D*> allPositions;
	std::vector<Vector2D*> tempPos;
	int tileSize = 94;
	bool hasPiece = false;
	bool isClicked = false;
	int boardArray[col][row];
	int mouseX = 0;
	int mouseY = 0;
	int board = 0;

private:
	const char* piecePath[12] = { "Assets/WhiteTower.png", "Assets/WhiteKnight.png", "Assets/WhiteBishop.png", "Assets/WhiteKing.png", "Assets/WhiteQueen.png", "Assets/WhitePawn.png", "Assets/BlackTower.png", "Assets/BlackKnight.png", "Assets/BlackBishop.png", "Assets/BlackKing.png", "Assets/BlackQueen.png", "Assets/BlackPawn.png" };
};

