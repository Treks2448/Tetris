#include "Board.h"

Board::Board()
{
}

void Board::DrawCell(Vector2D& position, Graphics& gfx, Color color) const
{
	gfx.DrawRectangleByDimension(int(position.X)*CellSideLength, int(position.Y)*CellSideLength, CellSideLength, CellSideLength, color);
}

void Board::DrawEmptyCells(Graphics& gfx) const
{
	for (int iY = 0; iY < Height; iY++)
	{
		for (int iX = 0; iX < Width; iX++)
		{
			Vector2D Position = { float(iX), float(iY) };
			DrawCell(Position, gfx, Colors::Gray);
		}
	}
}
