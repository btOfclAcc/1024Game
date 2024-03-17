#pragma once
#include "raylib.h"

class Cell
{
public:
	Rectangle rect;
	int number;
	int fontSize;

	Cell(Rectangle, int);
	void DrawCell();
};

