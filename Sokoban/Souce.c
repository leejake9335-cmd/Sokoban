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
#define WIDTH 17

int map[HEIGHT][WIDTH] =
{ // 0 : 벽 1: 빈공간 2 : 목표지점 3: 박스  4: 플레이어
{1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
{1,1,1,1,1,1,1,1,1,1,0,1,1,2,2,2,0},
{1,1,1,1,1,1,0,0,0,0,0,1,1,2,2,2,0},
{1,1,1,1,1,1,0,1,1,1,1,1,1,2,1,2,0},
{1,1,1,1,1,1,0,1,1,0,0,1,1,2,2,2,0},
{1,1,1,1,1,1,0,0,1,0,0,1,1,2,2,2,0},
{1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0},
{1,1,1,1,1,0,1,3,3,3,1,0,0,1,1,1,1},
{1,0,0,0,0,0,1,1,3,1,3,1,0,0,0,0,0},
{0,0,1,1,1,0,3,1,3,1,1,1,0,1,1,1,0},
{0,4,1,3,1,1,3,1,1,1,1,3,1,1,3,1,0},
{0,0,0,0,0,0,1,3,3,1,3,1,0,0,0,0,0},
{1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1},
};

void map_render()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			switch (map[y][x])
			{
			case 0: render(x * 2, y, "■");
				break;
			case 1: render(x * 2, y, "  ");
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

	int px = 2;

	int py = 10;

	char key = 0;
	int bx = 0;
	int by = 0;

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
			case UP: if (py > 0 && map[py - 1][px / 2] != 0) {py--; }	
				   break;
			case LEFT: if (px > 0 && map[py][px / 2 - 1] != 0) { px -= 2; }
					 break;
			case RIGHT:if (width > px && map[py][px / 2 + 1] != 0) { px += 2; }
					  break;
			case DOWN: if (height > py && map[py + 1][px / 2] != 0 ) { py++; }
					 break;
			} 
		}
		render(px, py, "★");
	

		if (map[py][px / 2] == 3)
		{

			bx = px / 2;
			by = py;
			int nx = bx;
			int ny = by;
			switch (key)
			{
			case UP: ny--;
				break;
			case DOWN: ny++;
				break;
			case LEFT: nx--;
				break;
			case RIGHT: nx++;
				break;
			}
			if (map[ny][nx] == 1 || map[ny][nx] == 2)
			{
				map[ny][nx] = 3;
				map[by][bx] = 1; 
			}
			else
			{
				if (key == UP) py++;
				else if (key == DOWN) py--;
				else if (key == LEFT) px += 2;
				else if (key == RIGHT) px -= 2;
			}
		}
		
	}


	release();

	return 0;
}