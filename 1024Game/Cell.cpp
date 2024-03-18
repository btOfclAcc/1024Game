#include "Cell.h"
#include "raylib.h"
#include <string>

Cell::Cell(Rectangle rect, int number)
{
	this->rect = rect;
	this->number = number;
	fontSize = 36;
}

void Cell::DrawCell()
{
	std::string txtStr;
	Color color;

	switch (number)
	{
	case 0:
		color = WHITE;
		txtStr = "";
		break;

	case 2:
		color = WHITE;
		txtStr = std::to_string(number);
		break;

	case 4:
		color = WHITE;
		txtStr = std::to_string(number);
		break;

	case 8:
		color = ORANGE;
		txtStr = std::to_string(number);
		break;

	case 16:
		color = ORANGE;
		txtStr = std::to_string(number);
		break;

	case 32:
		color = ORANGE;
		txtStr = std::to_string(number);
		break;

	case 64:
		color = RED;
		txtStr = std::to_string(number);
		break;

	case 128:
		color = RED;
		txtStr = std::to_string(number);
		break;

	case 256:
		color = YELLOW;
		txtStr = std::to_string(number);
		break;

	case 512:
		color = YELLOW;
		txtStr = std::to_string(number);
		break;

	case 1024:
		color = YELLOW;
		txtStr = std::to_string(number);
		break;

	default:
		break;
	}

	Vector2 cardCen = Vector2{ rect.x + rect.width / 2 , rect.y + rect.height / 2 };
	float txtWidth = MeasureText(txtStr.c_str(), fontSize);
	Vector2 txtOrigin = Vector2{
								cardCen.x - txtWidth / 2,
								cardCen.y - fontSize / 2 };

	DrawRectangleRounded(rect, 0.1, 5, color);


	DrawText(txtStr.c_str(), txtOrigin.x,
		txtOrigin.y, fontSize, BLACK);
}