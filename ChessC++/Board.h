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

public:
	Board(Window* window);
	~Board();


public:
	void DrawBoard();
	void DrawPieces();
	void DrawHighlighter();

	std::vector<Piece*> pieces;
	SDL_Rect boardRect;
	int tileSize = 75;
	bool hasPiece = false;
	bool isClicked = false;
	int boardArray[col][row];
	int clickRectX = 0;
	int clickRectY = 0;

private:
	const char* piecePath[12] = { "Assets/WhiteTower.png", "Assets/WhiteKnight.png", "Assets/WhiteBishop.png", "Assets/WhiteKing.png", "Assets/WhiteQueen.png", "Assets/WhitePawn.png", "Assets/BlackTower.png", "Assets/BlackKnight.png", "Assets/BlackBishop.png", "Assets/BlackKing.png", "Assets/BlackQueen.png", "Assets/BlackPawn.png" };
};

