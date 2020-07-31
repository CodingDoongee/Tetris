//이런 허접한 프로그램을 배포할리는 없겠지만 혹시 몰라서 Copyright는 오태동에게 있음을 알림.

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <cstdint>
#include <conio.h>
#include <ctime>
#include "TetrisClass.h"


DWORD WINAPI ProcessInput(PVOID pvParam);

uint32_t g_uint32_Score;
Field Tetris_Field;




int main(void)
{
	CreateThread(NULL, 0, ProcessInput,0,NULL,NULL);
	system("Title Taedong's Tetris");
	system("mode con cols=50 lines=30");
	SYSTEMTIME get_time;
	uint32_t Current_time = 0;
	uint32_t Prev_time = 0;
	srand(time(NULL));


	Tetris_Field.GenNewBlock(rand() % NUM_OBJECTS);

	while (1)
	{
		GetSystemTime(&get_time);
		Current_time = get_time.wHour * 3600 * 60 * 1000 + get_time.wMinute * 60 * 1000 + get_time.wSecond * 1000 + get_time.wMilliseconds;

		if (abs((int)(Current_time - Prev_time)) > TIME_TICK)
		{
			Prev_time = Current_time;
			Tetris_Field.ClearLine();
			Tetris_Field.GetMinHeight();
			Tetris_Field.UpdateField();
		}
		else
		{
			Sleep(10);
		}
	}

	return 0;
}