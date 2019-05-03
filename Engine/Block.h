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
	void Draw(Graphics& gfx, Board& board) const;

	/* Handles falling of the block*/
	void Fall();

	/* Handles rotation of the block*/
	void Rotate(bool clockwise);

	/* Handles movement of the brick*/
	void Move(Vector2D direction);

	/* Returns the coordinates of the ith element of the block*/
	Vector2D GetElementCoordinates(int iElement) const;

	/* Returns whether the block is in the falling state */
	bool IsFalling() const;

	/* Allows to change the state of the brick to falling / not falling */
	void SetFalling(bool isFalling);

private:
	/* Position of the central cell of the block */
	Vector2D CenterPosition = { 4,3 };

	/* The number of cells that the blocks are made out of */
	static constexpr int BlockSize = 4;

	/* Shows whether the brick is falling or stationary */
	bool bIsFalling = true;

	/* Set of coordinates of each cell of the block*/
	Vector2D BlockCoordinates[BlockSize];

	Keyboard kbd;

};