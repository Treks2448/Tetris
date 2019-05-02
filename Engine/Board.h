#pragma once

#include "Graphics.h"
#include "Vector2D.h"

class Board
{
public:
	Board();

	/* Draws a cell on the board*/
	void DrawCell(Vector2D& position, Graphics& gfx, Color color);

	/* Draws the entire board */
	void DrawEmpty(Graphics& gfx);

private:
	/* Numvber of pixels horizontally and vertically per cell*/
	static constexpr int CellSideLength = 25;

	/* Number of cells horizontally and vertically on the board */
	static constexpr int Width = 10;
	static constexpr int Height = 20;

	/* 2D array storing the index of what to draw on the board */
	int Index[Width * Height] = { 0 };

};