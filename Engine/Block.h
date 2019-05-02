#pragma once

#include "Vector2D.h"
#include <random>
#include "Graphics.h"
#include "Board.h"
#include "Keyboard.h"

class Block
{
public:
	/* Generates a random block type and assigns it the coordinates*/
	Block();

	/* Draws the block on the board*/
	void Draw(Graphics& gfx, Board& board);

	/* Used to set the coordinate of the center of the block */
	void SetCenterPosition(Vector2D centerPosition);

	/* Handles falling of the block*/
	void Fall();

	/* Handles rotation of the block*/
	void Rotate();

	/* Handles movement of the brick*/
	void Move(Vector2D direction);

private:
	/* Position of the central cell of the block */
	Vector2D CenterPosition = { 4,3 };

	/* The number of cells that the blocks are made out of */
	static constexpr int BlockSize = 4;

	/* Shows whether the brick is falling or stationary */
	bool bIsFalling = false;

	/* Set of coordinates of each cell of the block*/
	Vector2D BlockCoordinates[BlockSize];

	Keyboard kbd;

};