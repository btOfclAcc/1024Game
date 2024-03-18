#pragma once
#include "raylib.h"

class Cell
{
public:
	Rectangle rect;
	int number;
	int fontSize;
	bool merged;

	Cell(Rectangle, int);
	void DrawCell();
};

