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
#define Height 16
#define Width 19



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
int map_org[HEIGHT][WIDTH] =
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
int map2[Height][Width] =
{ // 0 : 벽 1: 빈공간 2 : 목표지점 3: 박스  4: 플레이어 가로 19 세로16
	{1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,4,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,0},
	{0,1,3,3,1,1,1,3,3,1,1,3,1,3,1,2,2,2,0},
	{0,1,1,3,3,3,0,1,1,1,1,3,1,1,0,2,2,2,0},
	{0,1,3,1,1,1,0,1,3,3,1,3,3,1,0,2,2,2,0},
	{0,0,0,1,1,1,0,1,1,3,1,1,1,1,0,2,2,2,0},
	{0,1,1,1,1,1,0,1,3,1,3,1,3,1,0,2,2,2,0},
	{0,1,1,1,1,0,0,0,0,0,0,1,0,0,0,2,2,2,0},
	{0,0,1,0,1,1,0,1,1,3,1,3,1,1,0,2,2,2,0},
	{0,1,1,0,0,1,0,1,3,3,1,3,1,3,0,0,2,2,0},
	{0,1,2,2,0,1,0,1,1,3,1,1,1,1,1,1,0,2,0},
	{0,1,2,2,0,1,0,1,3,3,3,1,3,3,3,1,0,2,0},
	{0,0,0,0,0,1,0,1,1,1,1,1,1,1,0,1,0,2,0},
	{1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,1,0,2,0},
	{1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,2,0},
	{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

int map_org2[Height][Width] =
{ // 0 : 벽 1: 빈공간 2 : 목표지점 3: 박스  4: 플레이어 가로 19 세로16
	{1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,4,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,0},
	{0,1,3,3,1,1,1,3,3,1,1,3,1,3,1,2,2,2,0},
	{0,1,1,3,3,3,0,1,1,1,1,3,1,1,0,2,2,2,0},
	{0,1,3,1,1,1,0,1,3,3,1,3,3,1,0,2,2,2,0},
	{0,0,0,1,1,1,0,1,1,3,1,1,1,1,0,2,2,2,0},
	{0,1,1,1,1,1,0,1,3,1,3,1,3,1,0,2,2,2,0},
	{0,1,1,1,1,0,0,0,0,0,0,1,0,0,0,2,2,2,0},
	{0,0,1,0,1,1,0,1,1,3,1,3,1,1,0,2,2,2,0},
	{0,1,1,0,0,1,0,1,3,3,1,3,1,3,0,0,2,2,0},
	{0,1,2,2,0,1,0,1,1,3,1,1,1,1,1,1,0,2,0},
	{0,1,2,2,0,1,0,1,3,3,3,1,3,3,3,1,0,2,0},
	{0,0,0,0,0,1,0,1,1,1,1,1,1,1,0,1,0,2,0},
	{1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,1,0,2,0},
	{1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,2,0},
	{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
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
void map_render2()
{
	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < Width; x++)
		{
			switch (map2[y][x])
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
	initialize();

	 for (int y = 0; y < HEIGHT; y++) {
	 	for (int x = 0; x < WIDTH; x++) {
	 		// 상자(3)나 플레이어(4) 자리는 바닥(1)으로 치환해서 저장
	 		if (map[y][x] == 3 || map[y][x] == 4) {
	 			map_org[y][x] = 1;
	 		}
	 		else {
	 			map_org[y][x] = map[y][x];
	 		}
	 	}
	 }


	

	CONSOLE_SCREEN_BUFFER_INFO buffer;

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(console, &buffer);

	int width = buffer.srWindow.Right - buffer.srWindow.Left - 2;

	int height = buffer.srWindow.Bottom - buffer.srWindow.Top;

	

	int px = 2;

	int py = 10;
	

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

			int bx = px / 2;
			int by = py;
			int nx = bx;
			int ny = by;

			switch (key)
			{
			case UP: ny--; break;
			case DOWN: ny++; break;
			case LEFT: nx--; break;
			case RIGHT: nx++; break;
			}
			if (map[ny][nx] == 1 || map[ny][nx] == 2)
			{
				map[ny][nx] = 3;
				map[by][bx] = map_org[by][bx];
			}
			else
			{
				if (key == UP) py++;
				else if (key == DOWN) py--;
				else if (key == LEFT) px += 2;
				else if (key == RIGHT) px -= 2;
			}
		}
		
	
		int game_clear = 1;
		for (int y = 0; y < HEIGHT; y++) {
			for (int x = 0; x < WIDTH; x++) {
				if (map_org[y][x] == 2 && map[y][x] != 3) {
					game_clear = 0; 
					break;
				}
			}
		}
		

		if (game_clear) {
			clear();
			render(WIDTH / 2, HEIGHT / 2, "GAME CLEAR! NEXT STAGE START : ENTER");
			flip();
			Sleep(3000); 
			break;       
		}
		
	}
	for (int y = 0; y < Height; y++) {
		for (int x = 0; x < Width; x++) {
			// 상자(3)나 플레이어(4) 자리는 바닥(1)으로 치환해서 저장
			if (map2[y][x] == 3 || map2[y][x] == 4) {
				map_org2[y][x] = 1;
			}
			else {
				map_org2[y][x] = map2[y][x];
			}
		}
	}

	px = 4;
	py = 1;
	key = 0;
	while(2)
	{

		flip();

		clear();

		map_render2();


		if (_kbhit())
		{
			key = _getch();

			if (key == -32 || key == 0)
			{

				key = _getch();
			}
			switch (key)
			{
			case UP: if (py > 0 && map2[py - 1][px / 2] != 0) { py--; }
				   break;
			case LEFT: if (px > 0 && map2[py][px / 2 - 1] != 0) { px -= 2; }
					 break;
			case RIGHT:if (width > px && map2[py][px / 2 + 1] != 0) { px += 2; }
					  break;
			case DOWN: if (height > py && map2[py + 1][px / 2] != 0) { py++; }
					 break;
			}
		}
		render(px, py, "★");

		if (map2[py][px / 2] == 3)
		{

			int bx = px / 2;
			int by = py;
			int nx = bx;
			int ny = by;

			switch (key)
			{
			case UP: ny--; break;
			case DOWN: ny++; break;
			case LEFT: nx--; break;
			case RIGHT: nx++; break;
			}
			if (map2[ny][nx] == 1 || map2[ny][nx] == 2)
			{
				map2[ny][nx] = 3;
				map2[by][bx] = map_org2[by][bx];
			}
			else
			{
				if (key == UP) py++;
				else if (key == DOWN) py--;
				else if (key == LEFT) px += 2;
				else if (key == RIGHT) px -= 2;
			}
		}


		int game_clear = 1;
		for (int y = 0; y < Height; y++) {
			for (int x = 0; x < Width; x++) {
				if (map_org2[y][x] == 2 && map2[y][x] != 3) {
					game_clear = 0;
					break;
				}
			}
		}
		if (game_clear) {
			clear();
			render(WIDTH / 2, HEIGHT / 2, "GAME CLEAR! YOU GENIUS.");
			flip();
			Sleep(3000);
			break;
		}


	}

	release();

	return 0;
}