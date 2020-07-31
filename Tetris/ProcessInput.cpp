
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <cstdint>
#include <conio.h>
#include <ctime>
#include "TetrisClass.h"

extern class Field Tetris_Field;
extern uint32_t g_uint32_Score;

DWORD WINAPI ProcessInput(PVOID pvParam)
{
	while (1)
	{
		if (_kbhit())
		{
			int key = 0;
			key = _getch();
			if (key == 32)
			{
				//printf("SPACE!!\n");
				Tetris_Field.SpacebarKey();
			}
			if (key == 224)
			{
				key = _getch();
				switch (key)
				{
				case 72:
					//printf("UP!!\n");
					Tetris_Field.UpKey();
					break;
				case 80:
					//printf("DOWN!!\n");
					Tetris_Field.DownKey();
					break;
				case 75:
					//printf("LEFT!!\n");
					Tetris_Field.LeftKey();
					break;
				case 77:
					//printf("RIGHT!!\n");
					Tetris_Field.RightKey();
					break;
				default:
					break;
				}
			}
		}
	}

	return 0;
}