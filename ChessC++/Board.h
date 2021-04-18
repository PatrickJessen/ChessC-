#pragma once
#include "Window.h"
#include "Piece.h"
#include <vector>
#include "Sprite.h"

const static int row = 8;
const static int col = 8;

class Board
{
private:
	Window* window;
	Sprite* sprite;
	Piece* piece = new Piece();
	std::vector<Piece*> pieces;

public:
	Board(Window* window);


public:
	void DrawBoard();
	void RenderPiecesToBoard();
	void DragAndDrop();
	void SelectPiece();

private:
	int tileSize = 75;
	bool hasClicked = false;
	Piece* pieceArray[row][col];
	Piece* tempPiece = 0;
	SDL_Rect boardRect;
	SDL_Rect fill;
};

