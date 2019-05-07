#pragma once

#include "Graphics.h"
#include "Vector2D.h"
#include "Colors.h"

class Board
{
public:
	Board();

	/* Draws a cell on the board*/
	void DrawCell(Vector2D& position, Graphics& gfx, Color color) const;

	/* Draws the entire board */
	void DrawAllCells(Graphics& gfx) const;

	/* Allows the specified cell to be filled with a block*/
	void FillCell(Vector2D& cellCoordinates, Color color);

	/* Returns the state of the cell */
	bool CellIsEmpty(Vector2D& cellCoordinates) const;

	/* Clears the line if it's full of blocks */
	void DoLineClear();

	/* Moves lines above the cleared line down one cell */
	void MoveCellsDown(int maxY);

	/* Number of cells horizontally and vertically on the board */
	static constexpr int Width = 10;
	static constexpr int Height = 20;
	int OffsetX = Graphics::ScreenWidth / 2 - Width * CellSideLength / 2;
	int OffsetY = Graphics::ScreenHeight / 2 - Height * CellSideLength / 2;

private:


	/* Numvber of pixels horizontally and vertically per cell*/
	static constexpr int CellSideLength = 25;

	bool bDoLineClearAnimation = false;

	int LineClearY[4];

	/* Array showing whether the cells on the board are empty or occupied by a brick (that isn't falling) */
	bool IsEmpty[Width * Height];
	Color Colours[Width * Height];
};