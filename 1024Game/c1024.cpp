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
		if (dir == "up") {
			for (int i = 0; i < 4; i++) {
				// Merge detection
				if (cells[0][i].number == cells[1][i].number && cells[0][i].number != 0)
						return true;
				if (cells[1][i].number == cells[2][i].number && cells[1][i].number != 0)
						return true;
				if (cells[2][i].number == cells[3][i].number && cells[2][i].number != 0)
						return true;
				if (cells[0][i].number == cells[2][i].number && cells[0][i].number != 0)
					if (cells[1][i].number == 0)
						return true;
				if (cells[1][i].number == cells[3][i].number && cells[1][i].number != 0)
					if (cells[2][i].number == 0)
						return true;
				if (cells[0][i].number == cells[3][i].number && cells[0][i].number != 0)
					if (cells[1][i].number == 0)
						if (cells[2][i].number == 0)
							return true;

				// Gap detection
				if (cells[3][i].number != 0)
					if (cells[2][i].number == 0 || cells[1][i].number == 0 || cells[0][i].number == 0)
						return true;
				if (cells[2][i].number != 0)
					if (cells[1][i].number == 0 || cells[0][i].number == 0)
						return true;
				if (cells[1][0].number != 0)
					if (cells[0][i].number == 0)
						return true;
			}
		}
		else if (dir == "down") {
			for (int i = 0; i < 4; i++) {
				if (cells[0][i].number == cells[1][i].number && cells[0][i].number != 0)
					return true;
				if (cells[1][i].number == cells[2][i].number && cells[1][i].number != 0)
					return true;
				if (cells[2][i].number == cells[3][i].number && cells[2][i].number != 0)
					return true;
				if (cells[0][i].number == cells[2][i].number && cells[0][i].number != 0)
					if (cells[1][i].number == 0)
						return true;
				if (cells[1][i].number == cells[3][i].number && cells[1][i].number != 0)
					if (cells[2][i].number == 0)
						return true;
				if (cells[0][i].number == cells[3][i].number && cells[0][i].number != 0)
					if (cells[1][i].number == 0)
						if (cells[2][i].number == 0)
							return true;

				if (cells[0][i].number != 0)
					if (cells[1][i].number == 0 || cells[2][i].number == 0 || cells[3][i].number == 0)
						return true;
				if (cells[1][i].number != 0)
					if (cells[2][i].number == 0 || cells[3][i].number == 0)
						return true;
				if (cells[2][0].number != 0)
					if (cells[3][i].number == 0)
						return true;
			}
		}
		else if (dir == "left") {
			for (int i = 0; i < 4; i++) {
				if (cells[i][0].number == cells[i][1].number && cells[i][0].number != 0)
					return true;
				if (cells[i][1].number == cells[i][2].number && cells[i][1].number != 0)
					return true;
				if (cells[i][2].number == cells[i][3].number && cells[i][2].number != 0)
					return true;
				if (cells[i][0].number == cells[i][2].number && cells[i][0].number != 0)
					if (cells[i][1].number == 0)
						return true;
				if (cells[i][1].number == cells[i][3].number && cells[i][1].number != 0)
					if (cells[i][2].number == 0)
						return true;
				if (cells[i][0].number == cells[i][3].number && cells[i][0].number != 0)
					if (cells[i][1].number == 0)
						if (cells[i][2].number == 0)
							return true;

				if (cells[i][3].number != 0)
					if (cells[i][2].number == 0 || cells[i][1].number == 0 || cells[i][0].number == 0)
						return true;
				if (cells[i][2].number != 0)
					if (cells[i][1].number == 0 || cells[i][0].number == 0)
						return true;
				if (cells[i][1].number != 0)
					if (cells[i][0].number == 0)
						return true;
			}
		}
		else if (dir == "right") {
			for (int i = 0; i < 4; i++) {
				if (cells[i][0].number == cells[i][1].number && cells[i][0].number != 0)
					return true;
				if (cells[i][1].number == cells[i][2].number && cells[i][1].number != 0)
					return true;
				if (cells[i][2].number == cells[i][3].number && cells[i][2].number != 0)
					return true;
				if (cells[i][0].number == cells[i][2].number && cells[i][0].number != 0)
					if (cells[i][1].number == 0)
						return true;
				if (cells[i][1].number == cells[i][3].number && cells[i][1].number != 0)
					if (cells[i][2].number == 0)
						return true;
				if (cells[i][0].number == cells[i][3].number && cells[i][0].number != 0)
					if (cells[i][1].number == 0)
						if (cells[i][2].number == 0)
							return true;

				if (cells[i][0].number != 0)
					if (cells[i][1].number == 0 || cells[i][2].number == 0 || cells[i][3].number == 0)
						return true;
				if (cells[i][1].number != 0)
					if (cells[i][2].number == 0 || cells[i][3].number == 0)
						return true;
				if (cells[i][2].number != 0)
					if (cells[i][3].number == 0)
						return true;
			}
		}
	}
	return false;
}

void c1024::Slide(std::string dir)
{
	if (dir == "up") {
		for (int j = 0; j < 4; j++) {
			for (int x = 0; x < 4; x++) {
				for (int i = 0; i < 3; i++) {
					if (cells[i][j].number == 0) {
						cells[i][j].number = cells[i + 1][j].number;
						cells[i + 1][j].number = 0;
						cells[i][j].merged = cells[i + 1][j].merged;
						cells[i + 1][j].merged = 0;
					}
					else if (cells[i][j].number == cells[i + 1][j].number && !cells[i][j].merged && !cells[i + 1][j].merged) {
						cells[i][j].number *= 2;
						cells[i][j].merged = true;
						cells[i + 1][j].number = 0;
					}
				}
			}
		}
	}
	else if (dir == "down") {
		for (int j = 0; j < 4; j++) {
			for (int x = 0; x < 4; x++) {
				for (int i = 3; i > 0; i--) {
					if (cells[i][j].number == 0) {
						cells[i][j].number = cells[i - 1][j].number;
						cells[i - 1][j].number = 0;
						cells[i][j].merged = cells[i - 1][j].merged;
						cells[i - 1][j].merged = 0;
					}
					else if (cells[i][j].number == cells[i - 1][j].number && !cells[i][j].merged && !cells[i - 1][j].merged) {
						cells[i][j].number *= 2;
						cells[i][j].merged = true;
						cells[i - 1][j].number = 0;
					}
				}
			}
		}
	}
	else if (dir == "left") {
		for (int i = 0; i < 4; i++) {
			for (int x = 0; x < 4; x++) {
				for (int j = 0; j < 3; j++) {
					if (cells[i][j].number == 0) {
						cells[i][j].number = cells[i][j + 1].number;
						cells[i][j + 1].number = 0;
						cells[i][j].merged = cells[i][j + 1].merged;
						cells[i][j + 1].merged = 0;
					}
					else if (cells[i][j].number == cells[i][j + 1].number && !cells[i][j].merged && !cells[i][j + 1].merged) {
						cells[i][j].number *= 2;
						cells[i][j].merged = true;
						cells[i][j + 1].number = 0;
					}
				}
			}
		}
	}
	else if (dir == "right") {
		for (int i = 0; i < 4; i++) {
			for (int x = 0; x < 4; x++) {
				for (int j = 3; j > 0; j--) {
					if (cells[i][j].number == 0) {
						cells[i][j].number = cells[i][j - 1].number;
						cells[i][j - 1].number = 0;
						cells[i][j].merged = cells[i][j - 1].merged;
						cells[i][j - 1].merged = false;
					}
					else if (cells[i][j].number == cells[i][j - 1].number && !cells[i][j].merged && !cells[i][j - 1].merged) {
						cells[i][j].number *= 2;
						cells[i][j].merged = true;
						cells[i][j - 1].number = 0;
					}
				}
			}
		}
	}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cells[i][j].merged = false;
}

void c1024::newNumber()
{
	while (!isFull()) {
		int i = rand() % 4;
		int j = rand() % 4;
		if (cells[i][j].number == 0) {
			cells[i][j].number = 2;
			break;
		}
	}
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

	cells.clear();
	grid.clear();
	
	for (int row = 0; row < 4; row++) {
		cells.push_back({});
		for (int col = 0; col < 4; col++) {
			Rectangle rect = Rectangle{ (GAP + ((GAP + cellSize) * col)) , (GAP + ((GAP + cellSize) * row)) , cellSize , cellSize };
			Cell temp(rect, 0);
			cells[row].push_back(temp);
		}
	}

	for (int row = 0; row < 4; row++) {
		grid.push_back({});
		for (int col = 0; col < 4; col++) {
			Rectangle rect = Rectangle{ (GAP + ((GAP + cellSize) * col)) , (GAP + ((GAP + cellSize) * row)) , cellSize , cellSize };
			Cell temp(rect, 0);
			grid[row].push_back(temp);
		}
	}

	if (debug) {
		// Horizontal
		cells[0][0].number = 0;
		cells[0][1].number = 0;
		cells[0][2].number = 0;
		cells[0][3].number = 0;

		// Vertical
		cells[0][0].number = 0;
		cells[1][0].number = 4;
		cells[2][0].number = 4;
		cells[3][0].number = 8;
	}
	else {
		newNumber();
		newNumber();
	}
}

void c1024::EvalCurFrame()
{
	if (!canMove())
		gameOver = true;
	
	for (int i = 0; i < (4 * 4); i++)
		if (cells[i / 4][i % 4].number == 1024)
			gameWon = true;

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

	if (IsKeyPressed(KEY_UP) && canMove("up")) {
		Slide("up");
		newNumber();
	}
	if (IsKeyPressed(KEY_DOWN) && canMove("down")) {
		Slide("down");
		newNumber();
	}
	if (IsKeyPressed(KEY_LEFT) && canMove("left")) {
		Slide("left");
		newNumber();
	}
	if (IsKeyPressed(KEY_RIGHT) && canMove("right")) {
		Slide("right");
		newNumber();
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
			grid[i / 4][i % 4].DrawCell();
		}
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

