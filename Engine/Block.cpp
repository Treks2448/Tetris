#include "Block.h"
#include "Colors.h"
#include <assert.h>
#include "Matrix2D.h"

Block::Block()
{

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> IndexDistribution(0, 6);
	int Index = IndexDistribution(rng);

	if (Index == 0)
	{
		// I-Block
		BlockCoordinates[0] = { CenterPosition.X - 1.f, CenterPosition.Y };
		BlockCoordinates[1] = CenterPosition;
		BlockCoordinates[2] = { CenterPosition.X + 1.f, CenterPosition.Y };
		BlockCoordinates[3] = { CenterPosition.X + 2.f, CenterPosition.Y };
		Colour = Colors::Cyan;
	}
	else if (Index == 1)
	{
		// J-Block
		BlockCoordinates[0] = { CenterPosition.X - 1.f, CenterPosition.Y -1.f};
		BlockCoordinates[1] = CenterPosition;
		BlockCoordinates[2] = { CenterPosition.X - 1.f, CenterPosition.Y };
		BlockCoordinates[3] = { CenterPosition.X +1.f, CenterPosition.Y };
		Colour = Colors::Blue;
	}
	else if (Index == 2)
	{
		// L-Block
		BlockCoordinates[0] = { CenterPosition.X - 1.f, CenterPosition.Y };
		BlockCoordinates[1] = CenterPosition;
		BlockCoordinates[2] = { CenterPosition.X + 1.f, CenterPosition.Y };
		BlockCoordinates[3] = { CenterPosition.X -1.f, CenterPosition.Y +1.f };
		Colour = { 255, 100, 0 };
	}
	else if (Index == 3)
	{
		// O-Block
		BlockCoordinates[0] = { CenterPosition.X +1.f, CenterPosition.Y +1.f};
		BlockCoordinates[1] = CenterPosition;
		BlockCoordinates[2] = { CenterPosition.X, CenterPosition.Y + 1.f};
		BlockCoordinates[3] = { CenterPosition.X + 1.f, CenterPosition.Y };
		Colour = Colors::Yellow;
	}
	else if (Index == 4)
	{
		// S-Block
		BlockCoordinates[0] = { CenterPosition.X + 1.f, CenterPosition.Y -1.f};
		BlockCoordinates[1] = CenterPosition;
		BlockCoordinates[2] = { CenterPosition.X, CenterPosition.Y - 1.f };
		BlockCoordinates[3] = { CenterPosition.X - 1.f, CenterPosition.Y };
		Colour = Colors::Green;
	}
	else if (Index == 5)
	{
		// T-Block
		BlockCoordinates[0] = { CenterPosition.X - 1.f, CenterPosition.Y };
		BlockCoordinates[1] = CenterPosition;
		BlockCoordinates[2] = { CenterPosition.X + 1.f, CenterPosition.Y };
		BlockCoordinates[3] = { CenterPosition.X, CenterPosition.Y - 1.f};
		Colour = Colors::Magenta;
	}
	else if (Index == 6)
	{
		// Z-Block
		BlockCoordinates[0] = { CenterPosition.X - 1.f, CenterPosition.Y -1.f};
		BlockCoordinates[1] = CenterPosition;
		BlockCoordinates[2] = { CenterPosition.X, CenterPosition.Y - 1.f};
		BlockCoordinates[3] = { CenterPosition.X + 1.f, CenterPosition.Y };
		Colour = Colors::Red;
	}
}

void Block::Draw(Graphics& gfx, Board& board) const
{
	if (bIsFalling)
	{
		for (Vector2D iElement : BlockCoordinates)
		{
			board.DrawCell(iElement, gfx, Colour);
		}
	}
}

void Block::Fall()
{

	for (int i = 0; i < BlockSize; i++)
	{
		BlockCoordinates[i] -= {0, -1.f};
	}
}

void Block::Rotate(bool clockwise)
{
	bool bOutOfBounds = false;
	int count = 0;
	for (int i = 0; i < BlockSize; i++)
	{
		count++;
		Matrix2D RotateClockwise90 = { 0.f, 1.f, -1.f , 0.f };
		if (clockwise)
		{
			BlockCoordinates[i] = RotateClockwise90.Transform(BlockCoordinates[i] - BlockCoordinates[1]) + BlockCoordinates[1];
		}
		else
		{
			BlockCoordinates[i] = RotateClockwise90.Transform(BlockCoordinates[i] - BlockCoordinates[1]) * (-1.f) + BlockCoordinates[1];
		}

		if (BlockCoordinates[i].X > 9.f || BlockCoordinates[i].X < 0.f)
		{
			bOutOfBounds = true;
			break;
		}
	}

	if (bOutOfBounds)
	{
		for (int i = 0; i < count; i++)
		{
			Matrix2D RotateClockwise90 = { 0.f, -1.f, 1.f , 0.f };
			if (clockwise)
			{
				BlockCoordinates[i] = RotateClockwise90.Transform(BlockCoordinates[i] - BlockCoordinates[1]) + BlockCoordinates[1];
			}
			else
			{
				BlockCoordinates[i] = RotateClockwise90.Transform(BlockCoordinates[i] - BlockCoordinates[1]) * (-1.f) + BlockCoordinates[1];
			}
		}
	}
}

void Block::Move(Vector2D direction)
{
	bool bIsOnBoard = true;
	for (int i = 0; i < BlockSize; i++)
	{

		if (BlockCoordinates[i].X + direction.X < 0.f || BlockCoordinates[i].X + direction.X > 9.f)
		{
			bIsOnBoard = false;
			break;
		}
	}
	if (bIsOnBoard)
	{
		for (int i = 0; i < BlockSize; i++)
		{

			BlockCoordinates[i] += direction;

		}
	}
}

Vector2D Block::GetElementCoordinates(int iElement) const
{
	return BlockCoordinates[iElement];
}

bool Block::IsFalling() const
{
	return bIsFalling;
}

void Block::SetFalling(bool isFalling)
{
	bIsFalling = isFalling;
}

Color Block::GetColour()
{
	return Colour;
}
