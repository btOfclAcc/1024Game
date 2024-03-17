#pragma once
#include <vector>
#include <string>
#include "raylib.h"

#ifndef C1024_H
#define C1024_H

class c1024
{
public:

#define GAP 8
#define CELL_HEIGHT 100

	typedef struct Cell {
		int number;
		Color color;
		Rectangle rect;
		void Draw() { DrawRectangleRounded(rect, 0.3f, 8, color); }
	} Cell;
	std::vector<Cell> cells;


	bool gamePaused = false;
	bool gameOver = false;
	bool levelWon = false;


	static const int screenWidth = 800;
	static const int screenHeight = 450;


	void Main();
	void Start();
	void EvalCurFrame();
	void DrawCurFrame();
	void Update();
};
#endif C1024_H