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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	Blocks(),
	FT()
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


	if ((!Blocks[ControlledBlock].IsOnTop(Blocks[ControlledBlock -1 ])) //placeholder statement to test block collision
		&& (!Blocks[ControlledBlock].IsAtBottom(19)))					//
	{
		if (MoveTimer >= 0.1f)
		{
			if (wnd.kbd.KeyIsPressed(VK_LEFT))
			{
				Blocks[ControlledBlock].Move({ -1.f, 0.f });
			}
			if (wnd.kbd.KeyIsPressed(VK_RIGHT))
			{
				Blocks[ControlledBlock].Move({ 1.f, 0.f });
			}
			MoveTimer = 0.f;
		}
		if (FallTimer >= .1f)
		{
			Blocks[ControlledBlock].Fall();
			FallTimer = 0.f;
		}
	}
	else
	{
		ControlledBlock += 1;
	}
}

void Game::ComposeFrame()
{
	GameBoard.DrawEmptyCells(gfx);
	for (int iBlock = 0; iBlock < ControlledBlock + 1; iBlock++)
	{
		Blocks[iBlock].Draw(gfx, GameBoard);
	}
}
