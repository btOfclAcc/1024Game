#include "c1024.h"
#include "raylib.h"

bool c1024::isFull()
{
	for (int i = 0; i < (4 * 4); i++)
		if (cells[i / 4][i % 4].number == 0)
			return false;
	return true;
}

bool c1024::canMove()
{
	if (isFull()) {
		for (int i = 0; i < (4 * 4); i++) {
			if ((i % 4 + 1) < 4)
				if (cells[i / 4][i % 4].number == cells[i / 4][i % 4 + 1].number)
					return true;
			if ((i / 4 + 1) < 4)
				if (cells[i / 4][i % 4].number == cells[i / 4 + 1][i % 4].number)
					return true;
		}
		return false;
	}
	return true;
}

bool c1024::canMove(std::string dir)
{
	if (canMove()) {
		if (dir == "ver") {
			for (int i = 0; i < 4; i++) {
				if (cells[i][0].number == cells[i][1].number)
					return true;
				if (cells[i][0].number == cells[i][2].number)
					return true;
				if (cells[i][0].number == cells[i][3].number)
					return true;
				if (cells[i][1].number == cells[i][2].number)
					return true;
				if (cells[i][1].number == cells[i][3].number)
					return true;
				if (cells[i][2].number == cells[i][3].number)
					return true;
			}
		}
		else if (dir == "hor") {
			for (int i = 0; i < 4; i++) {
				if (cells[0][i].number == cells[1][i].number)
					return true;
				if (cells[0][i].number == cells[2][i].number)
					return true;
				if (cells[0][i].number == cells[3][i].number)
					return true;
				if (cells[1][i].number == cells[2][i].number)
					return true;
				if (cells[1][i].number == cells[3][i].number)
					return true;
				if (cells[2][i].number == cells[3][i].number)
					return true;
			}
		}
	}
	return false;
}

void c1024::Slide(std::string dir)
{
	
}

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
	float cellSize = (screenHeight - (GAP * (4 + 1))) / 4;

	for (int row = 0; row < 4; row++) {
		cells.push_back({});
		for (int col = 0; col < 4; col++) {
			Rectangle rect = Rectangle{ (GAP + ((GAP + cellSize) * col)) , (GAP + ((GAP + cellSize) * row)) , cellSize , cellSize };
			Cell temp(rect, 0);
			cells[row].push_back(temp);
		}
	}
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

		for (int i = 0; i < (4 * 4); i++) {
			cells[i / 4][i % 4].DrawCell();
		}

	}





	EndDrawing();
}

void c1024::Update()
{
	EvalCurFrame();
	DrawCurFrame();
}

