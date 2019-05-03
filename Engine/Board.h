#pragma once

#include "Graphics.h"
#include "Vector2D.h"

class Board
{
public:
	Board();

	/* Draws a cell on the board*/
	void DrawCell(Vector2D& position, Graphics& gfx, Color color) const;

	/* Draws the entire board */
	void DrawAllCells(Graphics& gfx) const;

	/* Allows the specified cell to be filled with a block*/
	void FillCell(Vector2D& cellCoordinates);

	/* Returns the state of the cell */
	bool CellIsEmpty(Vector2D& cellCoordinates) const;

	void DoLineClear();

	/* Number of cells horizontally and vertically on the board */
	static constexpr int Width = 10;
	static constexpr int Height = 20;

private:
	/* Moves lines above the cleared line down one cell */
	void MoveCellsDown(int maxY);

	/* Numvber of pixels horizontally and vertically per cell*/
	static constexpr int CellSideLength = 25;

	/* Array showing whether the cells on the board are empty or occupied by a brick (that isn't falling) */
	bool IsEmpty[Width * Height];
};