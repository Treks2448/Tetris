#include "Block.h"
#include "Colors.h"

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
	}
	else if (Index == 1)
	{
		// J-Block
		BlockCoordinates[0] = { CenterPosition.X - 1.f, CenterPosition.Y -1.f};
		BlockCoordinates[1] = { CenterPosition.X - 1.f, CenterPosition.Y };
		BlockCoordinates[2] = CenterPosition;
		BlockCoordinates[3] = { CenterPosition.X +1.f, CenterPosition.Y };
	}
	else if (Index == 2)
	{
		// L-Block
		BlockCoordinates[0] = { CenterPosition.X - 1.f, CenterPosition.Y };
		BlockCoordinates[1] = CenterPosition;
		BlockCoordinates[2] = { CenterPosition.X + 1.f, CenterPosition.Y };
		BlockCoordinates[4] = { CenterPosition.X + 1.f, CenterPosition.Y -1.f};

	}
	else if (Index == 3)
	{
		// O-Block
		BlockCoordinates[0] = { CenterPosition.X , CenterPosition.Y -1.f};
		BlockCoordinates[1] = CenterPosition;
		BlockCoordinates[2] = { CenterPosition.X + 1.f, CenterPosition.Y -1.f};
		BlockCoordinates[3] = { CenterPosition.X + 1.f, CenterPosition.Y };
	}
	else if (Index == 4)
	{
		// S-Block
		BlockCoordinates[0] = { CenterPosition.X - 1.f, CenterPosition.Y -1.f};
		BlockCoordinates[1] = { CenterPosition.X, CenterPosition.Y -1.f};
		BlockCoordinates[2] = CenterPosition;
		BlockCoordinates[3] = { CenterPosition.X + 1.f, CenterPosition.Y };
	}
	else if (Index == 5)
	{
		// T-Block
		BlockCoordinates[0] = { CenterPosition.X - 1.f, CenterPosition.Y };
		BlockCoordinates[1] = CenterPosition;
		BlockCoordinates[2] = { CenterPosition.X + 1.f, CenterPosition.Y };
		BlockCoordinates[3] = { CenterPosition.X, CenterPosition.Y - 1.f};
	}
	else if (Index == 6)
	{
		//Z-Block
		BlockCoordinates[0] = { CenterPosition.X - 1.f, CenterPosition.Y -1.f};
		BlockCoordinates[1] = { CenterPosition.X, CenterPosition.Y -1.f};
		BlockCoordinates[2] = CenterPosition;
		BlockCoordinates[3] = { CenterPosition.X + 1.f, CenterPosition.Y };
	}
	//TODO generate the block
}

void Block::Draw(Graphics& gfx, Board& board)
{
	for (Vector2D ElementCoordinate : BlockCoordinates)
	{
		board.DrawCell(ElementCoordinate, gfx, Colors::Red);
	}
}

void Block::SetCenterPosition(Vector2D centerPosition)
{
	CenterPosition = centerPosition;
}

void Block::SetIsFalling(bool isFalling)
{
	bIsFalling = isFalling;
}

void Block::Fall()
{
	for (int i = 0; i < BlockSize; i++)
	{
		BlockCoordinates[i] -= {1, 1};
	}
}

void Block::Rotate()
{
}

void Block::Move()
{
}
