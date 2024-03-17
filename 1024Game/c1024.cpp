#include "c1024.h"
#include "raylib.h"

void c1024::Main()
{
	InitWindow(screenWidth, screenHeight, "1024");

	Start();

	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		Update();
	}
	CloseWindow();
}

void c1024::Start()
{
	
}

void c1024::EvalCurFrame()
{
	if (gameOver)
	{
		if (IsKeyPressed(KEY_ENTER))
		{
			Start();
			gameOver = false;
		}

		return;
	}

	if (gameWon)
	{
		if (IsKeyPressed(KEY_ENTER))
		{
			Start();
			gameWon = false;
		}

		return;
	}

	if (IsKeyPressed(KEY_P))
		gamePaused = !gamePaused;

	if (gamePaused) return;


	
}


void c1024::DrawCurFrame()
{
	BeginDrawing();
	ClearBackground(BLACK);

	if (gameOver)
	{
		DrawText("Press Enter to play again",
			GetScreenWidth() / 2 - MeasureText("Press Enter to play again", 30) / 2,
			GetScreenHeight() / 2 - 15,
			30, GRAY);
	}
	else if (gameWon)
	{
		DrawText("You Won! Press Enter to go to next level!",
			GetScreenWidth() / 2 - MeasureText("You Won! Press Enter to go to next level!", 30) / 2,
			GetScreenHeight() / 2 - 15,
			30, GRAY);
	}
	else
	{
		player.Draw();
		ball.Draw();

		for (Brick b : bricks)
			b.Draw();

		for (PowerUp p : powerUps)
			p.Draw();

		// draw player lives!
		for (int i = 0; i < MAX_LIVES; i++)
		{
			if (i < player.curLife)
				DrawRectangle(10 + 40 * i, screenHeight - 20, 30, 10, LIGHTGRAY);
			else
				DrawRectangle(10 + 40 * i, screenHeight - 20, 30, 10, GRAY);
		}
	}





	EndDrawing();
}

void c1024::Update()
{
	EvalCurFrame();
	DrawCurFrame();
}

