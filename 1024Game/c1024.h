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

	
	std::vector<std::vector<Cell>> cells;
	std::vector<std::vector<Cell>> grid;


	bool gamePaused = false;
	bool gameOver = false;
	bool gameWon = false;


	static const int screenWidth = 850;
	static const int screenHeight = 850;


	bool isFull();
	bool canMove();
	bool canMove(std::string);
	void Slide(std::string);
	void newNumber();


	void Main();
	void Start();
	void EvalCurFrame();
	void DrawCurFrame();
	void Update();
};
#endif C1024_H