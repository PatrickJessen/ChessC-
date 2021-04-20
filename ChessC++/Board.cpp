#include "Board.h"
#include "Input.h"


Board::Board(Window* window)
{
	this->window = window;
	pieces.push_back(new Piece(window, 0 * tileSize, 7 * tileSize, piece->Rook, true, { new Vector2D(0, 1), new Vector2D(1, 0), new Vector2D(-1, 0), new Vector2D(0, -1) }, piece->piecePath[0]));
	pieces.push_back(new Piece(window, 1 * tileSize, 7 * tileSize, piece->Knight, true, { new Vector2D(2, 1), new Vector2D(1, 2), new Vector2D(2, -1), new Vector2D(-1, 2), new Vector2D(-2, 1),
		new Vector2D(-2, -1), new Vector2D(1, -2), new Vector2D(1, 2), new Vector2D(-1, 2), new Vector2D(-1, -2) }, piece->piecePath[1]));
	pieces.push_back(new Piece(window, 2 * tileSize, 7 * tileSize, piece->Bishop, true, { new Vector2D( -1, 1 ), new Vector2D( -1, -1 ), new Vector2D( 1, 1 ), new Vector2D( 1, -1 ) }, piece->piecePath[2]));
	pieces.push_back(new Piece(window, 3 * tileSize, 7 * tileSize, piece->Queen, true, { new Vector2D(0, 1), new Vector2D({ 1, 0 }), new Vector2D(-1, 0), new Vector2D(0, -1), 
		new Vector2D(-1, 1), new Vector2D(-1, -1), new Vector2D(1, 1), new Vector2D(1, -1) }, piece->piecePath[4]));
	pieces.push_back(new Piece(window, 4 * tileSize, 7 * tileSize, piece->King, true, { new Vector2D(0, 1), new Vector2D(1, 0), new Vector2D(-1, 0), new Vector2D(0, -1), }, piece->piecePath[3]));
	pieces.push_back(new Piece(window, 5 * tileSize, 7 * tileSize, piece->Bishop, true, { new Vector2D(-1, 1), new Vector2D(-1, -1), new Vector2D(1, 1), new Vector2D(1, -1) }, piece->piecePath[2]));
	pieces.push_back(new Piece(window, 6 * tileSize, 7 * tileSize, piece->Knight, true, { new Vector2D(2, 1), new Vector2D(1, 2), new Vector2D(2, -1), new Vector2D(-1, 2), new Vector2D(-2, 1),
		new Vector2D(-2, -1), new Vector2D(1, -2), new Vector2D(1, 2), new Vector2D(-1, 2), new Vector2D(-1, -2) }, piece->piecePath[1]));
	pieces.push_back(new Piece(window, 7 * tileSize, 7 * tileSize, piece->Rook, true, { new Vector2D(0, 1), new Vector2D(1, 0), new Vector2D(-1, 0), new Vector2D(0, -1) }, piece->piecePath[0]));

	pieces.push_back(new Piece(window, 0 * tileSize, 0 * tileSize, piece->BRook, false, { new Vector2D(0, 1), new Vector2D(1, 0), new Vector2D(-1, 0), new Vector2D(0, -1) }, piece->piecePath[6]));
	pieces.push_back(new Piece(window, 1 * tileSize, 0 * tileSize, piece->BKnight, false, { new Vector2D(2, 1), new Vector2D(1, 2), new Vector2D(2, -1), new Vector2D(-1, 2), new Vector2D(-2, 1),
		new Vector2D(-2, -1), new Vector2D(1, -2), new Vector2D(1, 2), new Vector2D(-1, 2), new Vector2D(-1, -2) }, piece->piecePath[7]));
	pieces.push_back(new Piece(window, 2 * tileSize, 0 * tileSize, piece->BBishop, false, { new Vector2D(-1, 1), new Vector2D(-1, -1), new Vector2D(1, 1), new Vector2D(1, -1) }, piece->piecePath[8]));
	pieces.push_back(new Piece(window, 3 * tileSize, 0 * tileSize, piece->BQueen, false, { new Vector2D(0, 1), new Vector2D({ 1, 0 }), new Vector2D(-1, 0), new Vector2D(0, -1),
		new Vector2D(-1, 1), new Vector2D(-1, -1), new Vector2D(1, 1), new Vector2D(1, -1) }, piece->piecePath[10]));
	pieces.push_back(new Piece(window, 4 * tileSize, 0 * tileSize, piece->BKing, false, { new Vector2D(0, 1), new Vector2D(1, 0), new Vector2D(-1, 0), new Vector2D(0, -1) }, piece->piecePath[9]));
	pieces.push_back(new Piece(window, 5 * tileSize, 0 * tileSize, piece->BBishop, false, { new Vector2D(-1, 1), new Vector2D(-1, -1), new Vector2D(1, 1), new Vector2D(1, -1) }, piece->piecePath[8]));
	pieces.push_back(new Piece(window, 6 * tileSize, 0 * tileSize, piece->BKnight, false, { new Vector2D(2, 1), new Vector2D(1, 2), new Vector2D(2, -1), new Vector2D(-1, 2), new Vector2D(-2, 1),
		new Vector2D(-2, -1), new Vector2D(1, -2), new Vector2D(1, 2), new Vector2D(-1, 2), new Vector2D(-1, -2) }, piece->piecePath[7]));
	pieces.push_back(new Piece(window, 7 * tileSize, 0 * tileSize, piece->BRook, false, { new Vector2D(0, 1), new Vector2D(1, 0), new Vector2D(-1, 0), new Vector2D(0, -1) }, piece->piecePath[6]));

	for (int i = 0; i < 8; i++)
	{
		pieces.push_back(new Piece(window, i * tileSize, 6 * tileSize, piece->Pawn, true, { new Vector2D(0, -1), }, piece->piecePath[5]));
		pieces.push_back(new Piece(window, i * tileSize, 1 * tileSize, piece->Pawn, false, { new Vector2D(0, 1), }, piece->piecePath[11]));
	}
}

Board::~Board()
{

}

void Board::DrawBoard()
{
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			//boardArray[r][c] = 0;
			boardRect = { r * tileSize, c * tileSize, tileSize, tileSize };
			if ((r + c) % 2 == 0)
			{
				SDL_SetRenderDrawColor(window->GetRender(), 255, 255, 255, 50);
			}
			else
			{
				SDL_SetRenderDrawColor(window->GetRender(), 150, 105, 63, 255);
			}
			SDL_RenderFillRect(window->GetRender(), &boardRect);
		}
	}
	DrawHighlighter();
	//boardRect = { clickRectX, clickRectY, tileSize, tileSize };
}

void Board::DrawPieces()
{
	for (int i = 0; i < pieces.size(); i++)
	{
		boardArray[pieces[i]->rect.y / tileSize][pieces[i]->rect.x / tileSize] = pieces[i]->type;
		if (boardArray[pieces[i]->rect.y / tileSize][pieces[i]->rect.x / tileSize] != 0)
		{
			SDL_RenderCopy(window->GetRender(), pieces[i]->tex, NULL, &pieces[i]->rect);
		}
	}
}

void Board::DrawHighlighter()
{
	if (isClicked)
	{
		if (highlighterRect.w != 0)
		{
			ShowAvailableMoves();
			//SDL_SetRenderDrawColor(window->GetRender(), 255, 0, 0, 255);
			//SDL_RenderFillRect(window->GetRender(), &highlighterRect);
			for (int i = 0; i < allPositions.size(); i++)
			{
				highlighterRect.x = allPositions[i]->x * tileSize;
				highlighterRect.y = allPositions[i]->y * tileSize;
				highlighterRect.w = tileSize;
				highlighterRect.h = tileSize;
				SDL_SetRenderDrawColor(window->GetRender(), 255, 0, 0, 255);
				SDL_RenderFillRect(window->GetRender(), &highlighterRect);
			}
		}
	}
}

void Board::ShowAvailableMoves()
{
	
	for (int i = 0; i < clickedPiece->possibleMoves.size(); i++)
	{
		int x = clickedPiece->gridPosX + clickedPiece->possibleMoves[i]->x;
		int y = clickedPiece->gridPosY + clickedPiece->possibleMoves[i]->y;
		if (!IsSameColor(x, y))
		{
			if (clickedPiece->type != 1 || clickedPiece->type != 2)
			{
				while (boardArray[y][x] == 0)
				{
					allPositions.push_back(new Vector2D(x, y));
					x += clickedPiece->possibleMoves[i]->x;
					y += clickedPiece->possibleMoves[i]->y;
				}
			}
			allPositions.push_back(new Vector2D(x, y));
		}
	}
}

bool Board::IsSameColor(int x, int y)
{
	if (boardArray[y][x] == piece->type && piece->isWhite && clickedPiece->isWhite)
	{
		return true;
	}
	return false;
}
