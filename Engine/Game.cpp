/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	FT(),
	Blocks(),
	GameBoard()
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float DeltaTime = FT.Mark();
	MoveTimer += DeltaTime;
	FallTimer += DeltaTime;

	for (int iElement = 0; iElement < 4; iElement++) 
	{
		Vector2D ElementCoordinates = Blocks[ControlledBlock].GetElementCoordinates(iElement);
		Vector2D CellBelow = { 0.f, 1.f };

		// if the cell below any element of the block is full or if the block is at the bottom of the board
		if ((!GameBoard.CellIsEmpty(ElementCoordinates + CellBelow))
			|| Blocks[ControlledBlock].GetElementCoordinates(iElement).Y == Board::Height)
		{
			Blocks[ControlledBlock].SetFalling(false);

			for (int iCell = 0; iCell < 4; iCell++)
			{
				GameBoard.FillCell(Blocks[ControlledBlock].GetElementCoordinates(iCell), Blocks[ControlledBlock].GetColour());
			}

			ControlledBlock += 1;

			break;
		}
	}

	if (Blocks[ControlledBlock].IsFalling())
	{
		
	
			if (wnd.kbd.KeyIsPressed(VK_UP))
			{
				if (!KeyHeld)
				{
					Blocks[ControlledBlock].Rotate(true);
				}
				KeyHeld = true;
			}
			else if (wnd.kbd.KeyIsPressed(VK_DOWN) )
			{
				if (!KeyHeld)
				{
					Blocks[ControlledBlock].Rotate(false);
				}
				KeyHeld = true;
			}
			else if (wnd.kbd.KeyIsPressed(VK_LEFT) )
			{
				if (!KeyHeld)
				{
					Blocks[ControlledBlock].Move({ -1.f, 0.f });
				}
				KeyHeld = true;
			}
			else if (wnd.kbd.KeyIsPressed(VK_RIGHT) )
			{
				if (!KeyHeld)
				{
					Blocks[ControlledBlock].Move({ 1.f, 0.f });
				}
				KeyHeld = true;
			}
			else
			{
				KeyHeld = false;
			}

		if (FallTimer >= .3f)
		{
			Blocks[ControlledBlock].Fall();
			FallTimer = 0.f;
		}
	}
	
	GameBoard.DoLineClear();
}

void Game::ComposeFrame()
{
	GameBoard.DrawAllCells(gfx);
	for (int iBlock = 0; iBlock < ControlledBlock + 1; iBlock++)
	{
		Blocks[iBlock].Draw(gfx, GameBoard);
	}
}
