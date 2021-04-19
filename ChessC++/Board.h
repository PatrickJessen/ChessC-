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
	std::vector<Piece*> pieces;

public:
	Board(Window* window);


public:
	void DrawBoard();
	void RenderPiecesToBoard();
	void DragAndDrop();
	void SelectPiece();
	void CheckForSuicide(int i);
	bool CheckForCapture();
	bool IsSameColor(int i);

private:
	int tileSize = 75;
	bool hasClicked = false;
	int boardArray[row][col];
	int tempPieceNr = NULL;
	Piece* pieceArray[row][col];
	Piece* capturedPiece[2];
	SDL_Rect boardRect;
	SDL_Rect fill;
};

