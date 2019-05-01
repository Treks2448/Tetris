#include "Board.h"

Board::Board()
{
}

void Board::DrawCell(Vector2D& position, Graphics& gfx, Color color)
{
	gfx.DrawRectangleByDimension(int(position.X)*CellSideLength, int(position.Y)*CellSideLength, CellSideLength, CellSideLength, color);
}

void Board::Draw(Graphics& gfx)
{
	for (int iY = 0; iY < Height; iY++)
	{
		for (int iX = 0; iX < Width; iX++)
		{
			Vector2D Position = { iX, iY };
			DrawCell(Position, gfx, Colors::Gray);
		}
	}
}
