#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "buffer.h"

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define HEIGHT 14
#define WIDTH 16

int map[WIDTH][HEIGHT] =
{ // 0 : 벽 1: 빈공간 2 : 목표지점 3: 박스  4: 플레이어
{0,0,0,0,0,1,0,0,0,0,1,1,1,1,1,1},
{0,2,2,2,0,1,0,1,1,0,0,0,0,1,1,1},
{0,2,2,2,0,0,0,1,1,3,1,1,0,1,1,1},
{0,2,2,2,2,0,0,1,3,1,1,3,0,0,0,1},
{0,0,2,2,2,2,0,0,1,1,1,3,1,1,0,1},
{0,0,0,2,2,2,1,0,0,1,3,1,3,1,0,1},
{0,1,0,0,1,1,1,3,0,1,1,3,1,1,0,1},
{0,1,1,0,0,1,0,1,0,0,0,1,0,0,0,0},
{0,1,3,1,0,1,0,1,1,1,1,1,1,1,1,0},
{0,1,1,3,3,1,1,1,1,4,1,3,3,1,1,0},
{0,1,1,1,0,1,1,3,3,1,1,1,3,0,0,0},
{0,1,1,0,0,0,0,0,0,3,1,0,0,0,1,1},
{0,1,0,0,1,1,1,1,0,0,0,0,1,1,1,1},
{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

void map_render()
{
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			switch (map[x][y])
			{
			case 0: render(x * 2, y, "■");
				break;
			case 1: render(x * 2, y, "　");
				break;
			case 2: render(x * 2, y, "○");
				break;
			case 3: render(x * 2, y, "●");
				break;
			}
		}
	}
}


int main()
{
	CONSOLE_SCREEN_BUFFER_INFO buffer;

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(console, &buffer);

	int width = buffer.srWindow.Right - buffer.srWindow.Left - 2;

	int height = buffer.srWindow.Bottom - buffer.srWindow.Top;

	initialize();

	int x = 18;

	int y = 9;

	char key = 0;

	

	while (1)
	{
		flip();

		clear();

		map_render();

		if (_kbhit())
		{
			key = _getch();

			if (key == -32 || key == 0)
			{
				key = _getch();
			}

			switch (key)
			{
			case UP: if (y > 0) { y--; }
				   break;
			case LEFT: if (x > 0) { x -= 2; }
					 break;
			case RIGHT:if (width > x) { x += 2; }
					  break;
			case DOWN: if (height > y) { y++; }
					 break;
			}
		}
		render(x, y, "★");

	
	}


	release();

	return 0;
}