

#define FIELD_SIZE_X 10
#define FIELD_SIZE_Y 20
#define	NUM_OBJECTS 7
#define TIME_TICK 500 //ms단위

extern uint32_t g_uint32_Score;
enum BlockTypes
{
	I_BLOCK = 0, J_BLOCK, L_BLOCK, O_BLOCK, S_BLOCK, T_BLOCK, Z_BLOCK
};

class Field
{
private:
	int Blocks[FIELD_SIZE_Y][FIELD_SIZE_X];
	int NewBlock[FIELD_SIZE_Y][FIELD_SIZE_X];
	int MinHeight[FIELD_SIZE_X];
	int NewBlockTag;
	int NewBlockBoxPosition[2];
public:
	Field()
	{
		for (int i = 0; i < FIELD_SIZE_Y; i++)
		{
			for (int j = 0; j < FIELD_SIZE_X; j++)
			{
				Blocks[i][j] = { 0 };
				NewBlock[i][j] = { 0 };
				MinHeight[j] = { 0 };
			}
		}

	}
	void UpdateField()
	{
		int temp[FIELD_SIZE_X] = { 0 };

		//게임오버 체크
		for (int i = 0; i < FIELD_SIZE_X; i++)
		{
			if (MinHeight[i] >= FIELD_SIZE_Y)
			{
				printf("GAME OVER!!!!\n");
				Sleep(3000);
				exit(1);
			}
		}

		for (int i = 0; i < FIELD_SIZE_Y; i++)
		{
			for (int j = 0; j < FIELD_SIZE_X; j++)
			{
				if ((NewBlock[i][j] == 1) && (MinHeight[j] >= i))
				{
					for (int i = 0; i < FIELD_SIZE_Y; i++)
					{
						for (int j = 0; j < FIELD_SIZE_X; j++)
						{
							if (Blocks[i][j] == 0 && NewBlock[i][j] == 1)
							{
								Blocks[i][j] = 1;
							}

						}
					}
					GenNewBlock(rand() % NUM_OBJECTS);
					return;
				}
			}
		}

		for (int j = 0; j < FIELD_SIZE_X; j++)
		{
			temp[j] = NewBlock[0][j];
		}
		for (int i = 0; i < FIELD_SIZE_Y; i++)
		{
			for (int j = 0; j < FIELD_SIZE_X; j++)
			{
				NewBlock[i][j] = NewBlock[i + 1][j];
			}
		}
		for (int j = 0; j < FIELD_SIZE_X; j++)
		{
			NewBlock[FIELD_SIZE_Y - 1][j] = temp[j];
		}

		NewBlockBoxPosition[1] = NewBlockBoxPosition[1] - 1;
	}
	void GetMinHeight()
	{
		//MIN값들 초기화
		for (int j = 0; j < FIELD_SIZE_X; j++)
		{
			MinHeight[j] = 0;
		}
		for (int j = 0; j < FIELD_SIZE_X; j++)
		{
			for (int i = FIELD_SIZE_Y - 1; i >= 0; i--)
			{
				if (Blocks[i][j] == 1)
				{
					MinHeight[j] = i + 1;
					break;
				}
			}
		}
	}
	void GenNewBlock(int Block_Num)
	{
		//초기화
		for (int i = 0; i < FIELD_SIZE_Y; i++)
		{
			for (int j = 0; j < FIELD_SIZE_X; j++)
			{
				NewBlock[i][j] = 0;
			}
		}

		switch (Block_Num)
		{
		case I_BLOCK:
			NewBlockTag = 0x4444;
			NewBlockBoxPosition[0] = 5;
			NewBlockBoxPosition[1] = FIELD_SIZE_Y - 1;
			NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] = 1;
			NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
			NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] = 1;
			NewBlock[NewBlockBoxPosition[1] - 3][NewBlockBoxPosition[0] + 1] = 1;
			break;
		case J_BLOCK:
			NewBlockTag = 0x44C0;
			NewBlockBoxPosition[0] = 5;
			NewBlockBoxPosition[1] = FIELD_SIZE_Y - 1;
			NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] = 1;
			NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
			NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0]] = 1;
			NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] = 1;
			break;
		case L_BLOCK:
			NewBlockTag = 0x4460;
			NewBlockBoxPosition[0] = 5;
			NewBlockBoxPosition[1] = FIELD_SIZE_Y - 1;
			NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] = 1;
			NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
			NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] = 1;
			NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 2] = 1;
			break;
		case O_BLOCK:
			NewBlockTag = 0xCC00;
			NewBlockBoxPosition[0] = 5;
			NewBlockBoxPosition[1] = FIELD_SIZE_Y - 1;
			NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0]] = 1;
			NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] = 1;
			NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] = 1;
			NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
			break;
		case S_BLOCK:
			NewBlockTag = 0x06C0;
			NewBlockBoxPosition[0] = 5;
			NewBlockBoxPosition[1] = FIELD_SIZE_Y - 1;
			NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
			NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] = 1;
			NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0]] = 1;
			NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] = 1;
			break;
		case T_BLOCK:
			NewBlockTag = 0x0E40;
			NewBlockBoxPosition[0] = 5;
			NewBlockBoxPosition[1] = FIELD_SIZE_Y - 1;
			NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] = 1;
			NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
			NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] = 1;
			NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] = 1;
			break;
		case Z_BLOCK:
			NewBlockTag = 0x0C60;
			NewBlockBoxPosition[0] = 5;
			NewBlockBoxPosition[1] = FIELD_SIZE_Y - 1;
			NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] = 1;
			NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
			NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] = 1;
			NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 2] = 1;
			break;
		default:
			break;
		}
	}
	void Draw()
	{
		HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hC, &csbi);
		system("cls");
		SetConsoleTextAttribute(hC, 10);
		printf("ㅁㅁTaedong's Tetrisㅁㅁ");
		printf("\n");
		for (int j = FIELD_SIZE_Y - 1; j >= 0; j--)
		{
			printf("ㅁ");

			SetConsoleTextAttribute(hC, 7);
			for (int i = 0; i < FIELD_SIZE_X; i++)
			{
				if ((Blocks[j][i] == 1) || (NewBlock[j][i] == 1))
				{
					printf("ㅁ");
				}
				else
				{
					printf("  ");
				}
			}
			SetConsoleTextAttribute(hC, 10);
			printf("ㅁ\n");
		}
		for (int j = FIELD_SIZE_X + 1; j >= 0; j--)
		{
			printf("ㅁ");
		}
		SetConsoleTextAttribute(hC, 7);
		printf("\nScore: %d\n", g_uint32_Score);
	}
	void DownKey()
	{
		GetMinHeight();
		UpdateField();
		Draw();
	}
	void LeftKey()
	{
		int temp[FIELD_SIZE_Y] = { 0 };
		int KeyOn = 1;

		for (int j = 0; j < FIELD_SIZE_Y; j++)
		{
			if (NewBlock[j][0] == 1)
			{
				KeyOn = 0;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if ((NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j + 1] == 1)
					&& (Blocks[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] == 1))
				{
					KeyOn = 0;
				}

			}
		}
		if (KeyOn == 1)
		{
			for (int j = 0; j < FIELD_SIZE_Y; j++)
			{
				temp[j] = NewBlock[j][0];
			}
			for (int i = 0; i < FIELD_SIZE_Y; i++)
			{
				for (int j = 0; j < FIELD_SIZE_X; j++)
				{
					NewBlock[i][j] = NewBlock[i][j + 1];
				}
			}
			for (int j = 0; j < FIELD_SIZE_Y; j++)
			{
				NewBlock[j][FIELD_SIZE_X - 1] = temp[j];
			}


			NewBlockBoxPosition[0] = NewBlockBoxPosition[0] - 1;
			GetMinHeight();
			Draw();
		}
	}
	void RightKey()
	{
		int temp[FIELD_SIZE_Y] = { 0 };
		int KeyOn = 1;

		//맨 좌우측 벽에 붙은 경우 블럭 이동 불가
		for (int j = 0; j < FIELD_SIZE_Y; j++)
		{
			if (NewBlock[j][FIELD_SIZE_X - 1] == 1)
			{
				KeyOn = 0;
			}
		}
		//블럭의 겹침 현상 방지
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if ((NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j - 1] == 1)
					&& (Blocks[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] == 1))
				{
					KeyOn = 0;
				}
			}
		}
		if (KeyOn == 1)
		{
			for (int j = 0; j < FIELD_SIZE_Y; j++)
			{
				temp[j] = NewBlock[j][FIELD_SIZE_X - 1];
			}
			for (int i = 0; i < FIELD_SIZE_Y; i++)
			{
				for (int j = FIELD_SIZE_X - 1; j >= 0; j--)
				{
					NewBlock[i][j] = NewBlock[i][j - 1];
				}
			}
			for (int j = 0; j < FIELD_SIZE_Y; j++)
			{
				NewBlock[j][0] = temp[j];
			}


			NewBlockBoxPosition[0] = NewBlockBoxPosition[0] + 1;
			GetMinHeight();
			Draw();
		}

	}
	void UpKey()
	{
		switch (NewBlockTag)
		{
		case 0x00F0:
			NewBlockTag = 0x4444;
			if ((Blocks[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 3][NewBlockBoxPosition[0] + 1] == 0)
				&& (NewBlockBoxPosition[0] + 1 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 3][NewBlockBoxPosition[0] + 1] = 1;
			}
			break;
		case 0x0E20:
			NewBlockTag = 0x44C0;
			if ((Blocks[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 2] == 0)
				&& (NewBlockBoxPosition[0] + 2 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 2] = 1;
			}
			break;
		case 0x2E00:
			NewBlockTag = 0x4460;
			if ((Blocks[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 2] == 0)
				&& (NewBlockBoxPosition[0] + 2 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 2] = 1;
			}
			break;
		case 0xCC00:
			NewBlockTag = 0xCC00;
			break;
		case 0x4620:
			NewBlockTag = 0x06C0;
			if ((Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0]] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] == 0)
				&& (NewBlockBoxPosition[0] + 2 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0]] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] = 1;
			}
			break;
		case 0x4640:
			NewBlockTag = 0x0E40;
			if ((Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] == 0)
				&& (NewBlockBoxPosition[0] + 2 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] = 1;
			}
			break;
		case 0x2640:
			NewBlockTag = 0x0C60;
			if ((Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 2] == 0)
				&& (NewBlockBoxPosition[0] + 2 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 2] = 1;
			}
			break;
		case 0x4444:
			NewBlockTag = 0x0F00;
			if ((Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 3] == 0)
				&& (NewBlockBoxPosition[0] + 3 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 3] = 1;
			}
			break;
		case 0x44C0:
			NewBlockTag = 0x8E00;
			if ((Blocks[NewBlockBoxPosition[1]][NewBlockBoxPosition[0]] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] == 0)
				&& (NewBlockBoxPosition[0] + 2 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0]] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] = 1;
			}
			break;
		case 0x4460:
			NewBlockTag = 0x0E80;
			if ((Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0]] == 0)
				&& (NewBlockBoxPosition[0] + 2 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0]] = 1;
			}
			break;
		case 0x06C0:
			NewBlockTag = 0x8C40;
			if ((Blocks[NewBlockBoxPosition[1]][NewBlockBoxPosition[0]] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] == 0)
				&& (NewBlockBoxPosition[0] + 1 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0]] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] = 1;
			}
			break;
		case 0x0E40:
			NewBlockTag = 0x4C40;
			if ((Blocks[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] == 0)
				&& (NewBlockBoxPosition[0] + 1 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] = 1;
			}
			break;
		case 0x0C60:
			NewBlockTag = 0x4C80;
			if ((Blocks[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0]] == 0)
				&& (NewBlockBoxPosition[0] + 1 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0]] = 1;
			}
			break;
		case 0x0F00:
			NewBlockTag = 0x2222;
			if ((Blocks[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 2] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 2] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 3][NewBlockBoxPosition[0] + 2] == 0)
				&& (NewBlockBoxPosition[0] + 2 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 2] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 2] = 1;
				NewBlock[NewBlockBoxPosition[1] - 3][NewBlockBoxPosition[0] + 2] = 1;
			}
			break;
		case 0x8E00:
			NewBlockTag = 0x6440;
			if ((Blocks[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 2] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] == 0)
				&& (NewBlockBoxPosition[0] + 2 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 2] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] = 1;
			}
			break;
		case 0x0E80:
			NewBlockTag = 0xC440;
			if ((Blocks[NewBlockBoxPosition[1]][NewBlockBoxPosition[0]] == 0)
				&& (Blocks[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] == 0)
				&& (NewBlockBoxPosition[0] + 1 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0]] = 1;
				NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] = 1;
			}
			break;
		case 0x8C40:
			NewBlockTag = 0x6C00;
			if ((Blocks[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 2] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] == 0)
				&& (NewBlockBoxPosition[0] + 2 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 2] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
			}
			break;
		case 0x4C40:
			NewBlockTag = 0x4E00;
			if ((Blocks[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] == 0)
				&& (NewBlockBoxPosition[0] + 2 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] = 1;
			}
			break;
		case 0x4C80:
			NewBlockTag = 0xC600;
			if ((Blocks[NewBlockBoxPosition[1]][NewBlockBoxPosition[0]] == 0)
				&& (Blocks[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] == 0)
				&& (NewBlockBoxPosition[0] + 2 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0]] = 1;
				NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] = 1;
			}
			break;
		case 0x2222:
			NewBlockTag = 0x00F0;
			if ((Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0]] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 2] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 3] == 0)
				&& (NewBlockBoxPosition[0] + 3 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0]] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 2] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 3] = 1;
			}
			break;
		case 0x6440:
			NewBlockTag = 0x0E20;
			if ((Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 2] == 0)
				&& (NewBlockBoxPosition[0] + 2 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 2] = 1;
			}
			break;
		case 0xC440:
			NewBlockTag = 0x2E00;
			if ((Blocks[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 2] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] == 0)
				&& (NewBlockBoxPosition[0] + 2 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 2] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0]] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] = 1;
			}
			break;
		case 0x6C00:
			NewBlockTag = 0x4620;
			if ((Blocks[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 2] == 0)
				&& (NewBlockBoxPosition[0] + 2 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 2] = 1;
			}
			break;
		case 0x4E00:
			NewBlockTag = 0x4640;
			if ((Blocks[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] == 0)
				&& (NewBlockBoxPosition[0] + 2 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] = 1;
			}
			break;
		case 0xC600:
			NewBlockTag = 0x2640;
			if ((Blocks[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 2] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] == 0)
				&& (Blocks[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] == 0)
				&& (NewBlockBoxPosition[0] + 2 < FIELD_SIZE_X))
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] = 0;
					}
				}
				NewBlock[NewBlockBoxPosition[1]][NewBlockBoxPosition[0] + 2] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 1] = 1;
				NewBlock[NewBlockBoxPosition[1] - 1][NewBlockBoxPosition[0] + 2] = 1;
				NewBlock[NewBlockBoxPosition[1] - 2][NewBlockBoxPosition[0] + 1] = 1;
			}
			break;

		default:
			break;
		}
		GetMinHeight();
		Draw();
	}
	void SpacebarKey()
	{
		int Minimum_Dist = FIELD_SIZE_Y;
		for (int j = 0; j < 4; j++)
		{
			for (int i = 3; i >= 0; i--)
			{
				if (NewBlock[NewBlockBoxPosition[1] - i][NewBlockBoxPosition[0] + j] == 1)
				{
					if (Minimum_Dist >(NewBlockBoxPosition[1] - i) - (MinHeight[NewBlockBoxPosition[0] + j]))
					{
						Minimum_Dist = (NewBlockBoxPosition[1] - i) - (MinHeight[NewBlockBoxPosition[0] + j]);
					}
				}
			}
		}

		for (int i = 0; i < FIELD_SIZE_Y - Minimum_Dist; i++)
		{
			for (int j = 0; j < FIELD_SIZE_X; j++)
			{
				NewBlock[i][j] = NewBlock[i + Minimum_Dist][j];
			}
		}
		for (int i = FIELD_SIZE_Y - Minimum_Dist; i < FIELD_SIZE_Y; i++)
		{
			for (int j = 0; j < FIELD_SIZE_X; j++)
			{
				NewBlock[i][j] = 0;
			}
		}
		NewBlockBoxPosition[1] = NewBlockBoxPosition[1] - Minimum_Dist;
		
		GetMinHeight();
		UpdateField();
		GetMinHeight();

		Draw();
	}
	void ClearLine()
	{
		int HowManyLines = 0;
		int Sum[FIELD_SIZE_Y] = { 0 };
		for (int i = 0; i < FIELD_SIZE_Y; i++)
		{
			for (int j = 0; j < FIELD_SIZE_X; j++)
			{
				Sum[i] += Blocks[i][j];
			}
		}

		for (int i = 0; i < FIELD_SIZE_Y; i++)
		{
			if (Sum[i] == FIELD_SIZE_X)
			{
				HowManyLines++;
			}
		}

		for (int i = FIELD_SIZE_Y - 1; i >= 0; i--)
		{
			if (Sum[i] == FIELD_SIZE_X)
			{
				for (int k = i; k < FIELD_SIZE_Y; k++)
				{
					for (int j = 0; j < FIELD_SIZE_X; j++)
					{
						Blocks[k][j] = Blocks[k + 1][j];
						Sum[k] = Sum[k + 1];
					}
				}
			}
		}
		switch (HowManyLines)
		{
		case 1:
			g_uint32_Score = g_uint32_Score + 100;
			break;
		case 2:
			g_uint32_Score = g_uint32_Score + 220;
			break;
		case 3:
			g_uint32_Score = g_uint32_Score + 360;
			break;
		case 4:
			g_uint32_Score = g_uint32_Score + 500;
			break;
		default:
			break;
		}
		GetMinHeight();
		Draw();
	}
};
