#include "Board.h"

Board::Board()
{
	for (int iCell = 0; iCell < Width * Height; iCell++)
	{
		IsEmpty[iCell] = true;
	}
}

void Board::DrawCell(Vector2D& position, Graphics& gfx, Color color) const
{
	gfx.DrawRectangleByDimension(int(position.X)*CellSideLength, int(position.Y)*CellSideLength, CellSideLength, CellSideLength, color);
}

void Board::DrawAllCells(Graphics& gfx) const
{
	for (int iY = 0; iY < Height; iY++)
	{
		for (int iX = 0; iX < Width; iX++)
		{
			Vector2D Position = { float(iX), float(iY) };
			if (IsEmpty[iY*Width + iX])
			{
				DrawCell(Position, gfx, Colors::Gray);
			}
			else
			{
				DrawCell(Position, gfx, Colors::Red);
			}
		}
	}
}

void Board::FillCell(Vector2D& cellCoordinates)
{
	IsEmpty[int(cellCoordinates.Y) * Width + int(cellCoordinates.X)] = false;
}

bool Board::CellIsEmpty(Vector2D& cellCoordinates) const
{
	return IsEmpty[int(cellCoordinates.Y) * Width + int(cellCoordinates.X)];
}

void Board::DoLineClear()
{
	for (int iY = 0; iY < Height; iY++)
	{
		int iX = 0;
		do
		{
			if (!IsEmpty[iY * Width + iX])
			{
				iX++;
			}

			if (iX == Width ) { break; }

		} while (!IsEmpty[iY * Width + iX]);

		if (iX == Width )
		{
			for (int iX = 0; iX < Width; iX++)
			{
				IsEmpty[iY * Width + iX] = true;
			}

			MoveCellsDown(iY);
		}
	}
}

void Board::MoveCellsDown(int maxY)
{
	for (int iY = maxY; iY > 1; iY--)
	{
		for (int iX = 0; iX < Width; iX++)
		{
			IsEmpty[iY * Width + iX] = IsEmpty[(iY - 1) * Width + iX];
		}
	}
}
