#pragma once
#include <vector>
#include <string>
#include "raylib.h"
#include "Cell.h"

#ifndef C1024_H
#define C1024_H

class c1024
{
public:

#define GAP 10
#define CELL_HEIGHT 200

	
	std::vector<std::vector<Cell>> cells;


	bool gamePaused = false;
	bool gameOver = false;
	bool gameWon = false;


	static const int screenWidth = 850;
	static const int screenHeight = 850;


	void Main();
	void Start();
	void EvalCurFrame();
	void DrawCurFrame();
	void Update();
};
#endif C1024_H