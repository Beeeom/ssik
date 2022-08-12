#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

#define ARROW 224
#define LEFT 75
#define RIGHT 77
#define	UP 72
#define	DOWN 80
#define SPACEBAR 32
#define c 99
#define z 122
#define p 112
#define Esc 27
#define BORDER_WIDTH 12
#define BORDER_HEIGHT 24
#define TRUE 1
#define FALSE 0

// [��� ����][��� ȸ��][��� ���][��� ���]
int BlockShape[7][4][4][4] = {
	{
		// �� ���
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
		}
	},
	{
		// I ��� (�� 3, 3)
		{
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{1, 1, 1, 1},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 1, 0}
		},
		{
			{0, 0, 0, 0},
			{1, 1, 1, 1},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 1, 0, 0}
		}
	},
	{
		// �� Z ��� (�� 2, 3)
		{
			{0, 0, 0, 0},
			{0, 0, 1, 1},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 1, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 0}
		}
	},
	{
		// Z ��� (�� 2, 3)
		{
			{0, 0, 0, 0},
			{1, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 1, 0},
			{0, 1, 1, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 1, 1},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 0, 1, 0},
			{0, 1, 1, 0},
			{0, 1, 0, 0}
		}
	},
	{
		// �� ���
		{
			{0, 0, 0, 0},
			{0, 0, 0, 1},
			{0, 1, 1, 1},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 1, 1, 0},
		},
		{
			{0, 0, 0, 0},
			{1, 1, 1, 0},
			{1, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 1, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 0}
		}
	},
	{
		// �� �� ���
		{
			{0, 0, 0, 0},
			{1, 0, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 1, 1, 0},
			{0, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 1, 1, 1},
			{0, 0, 0, 1},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 0, 1, 0},
			{0, 0, 1, 0},
			{0, 1, 1, 0}
		}
	},
	{
		// T ���
		{
			{0, 0, 0, 0},
			{0, 1, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 1, 1, 1},
			{0, 0, 1, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 0, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 1, 0}
		}
	}
};
enum { EMPTY = 0, MBLOCK = 1, OVERLINE = 2, SBLOCK = 3, WALL = 4, FBLOCK = 5 };
int blockX;
int blockY;
int blockRotation = 0;
int blockType;
int board[BORDER_HEIGHT][BORDER_WIDTH];
int flagNewBlock;
int blockTypeNow;
int speedUp = 0;
int speed = 0;
int score = 0;

void GotoXY(int, int);
void NewBlock();
void PrintNextBlock();
void Move(int, int, int);
void ConsoleSize();
void RemoveCurser();
void RemoveScrollbar();
void SetConsole();
void PrintGameBoard();
void ResetGameBoard();
void FixBlock();
int CrushCheck(int, int, int);
void Keyboard();
void PrintNextBoard();
void TextColor(int);
void StartScreen();
void EndScreen();
void CleanLine();
void Level();
void GameOver();

void main() {
	srand(time(NULL));
	SetConsole();
	StartScreen();
	ResetGameBoard();
	PrintGameBoard();
	PrintNextBoard();
	NewBlock();

	while (1) {
		Keyboard();
		if (flagNewBlock == 1)
			NewBlock();

		if (CrushCheck(0, 1, 0) == FALSE) {
			FixBlock();
			GameOver();
			CleanLine();
			Level();
		}
		else
			Move(0, 1, 0);
		PrintGameBoard();
		PrintNextBoard();
		Sleep(150 - speed);
	}
}

// �ܼ�â ����
void SetConsole() {
	ConsoleSize();
	RemoveScrollbar();
	RemoveCurser();
}

// �ܼ�â ũ�� ����
void ConsoleSize() {
	system("mode con cols=51 lines=25");
}

// �ܼ�â ��ũ�ѹ� ����
void RemoveScrollbar() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
}

// Ŀ�� ����
void RemoveCurser() {
	CONSOLE_CURSOR_INFO curinfo = { 0, };
	curinfo.dwSize = 1;
	curinfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
}

// ȭ�� ��ǥ ����
void GotoXY(int x, int y) {
	COORD Pos;
	Pos.X = x * 2;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// ����ȭ��.Ź
void StartScreen() {
	printf("\n\n\n\n\n"); // ����ȭ�� ���
	printf("           * * *  T E T R I S  * * *\n\n");
	printf("            �� �� ��  : �̵�\n");
	printf("               ��     : ȸ��\n");
	printf("               Z      : ��ȸ��\n");
	printf("               C      : ��� ���� �� ��ü\n");
	printf("             Space    : ����\n");
	printf("               P      : �Ͻ�����\n");
	printf("              ESC     : ���� ����\n\n");

	char save_key;

	while (1) {
		if (_kbhit()) // �Է��� ������ ����
		{
			save_key = _getch();
			if (save_key == 13) // Enter�� ����
			{
				system("cls");
				return 0;
			}
			if (save_key == 27) // Esc�� ����ȭ�� ����
				EndScreen();
		}
	}
}

// ����ȭ��.Ź
void EndScreen() {
	system("cls"); // ȭ�� �ʱ�ȭ
	for (int y = 0; y < BORDER_HEIGHT; y++) // ����ȭ�� ���
	{
		if (y == 11)
			printf("�� ��  ��  ��  �� ��\n");
		else if (y % 2 == 0)
			printf("�����������\n");
		else
			printf("�����������\n");
	}
	exit(0); // ���α׷� ����
}

// ���� ���� �ʱ�ȭ
void ResetGameBoard()
{
	for (int y = 0; y < BORDER_HEIGHT; y++) // �� ����
	{
		for (int x = 0; x < BORDER_WIDTH; x++)
			board[y][x] = EMPTY;
	}

	for (int y = 0; y < BORDER_HEIGHT; y++)
	{
		for (int x = 0; x < BORDER_WIDTH; x++)
		{
			if (x == 0 || x == BORDER_WIDTH - 1) // ��-�� �� �׸���
				board[y][x] = WALL;

			if (y == BORDER_HEIGHT - 1) // �ϴ� �� �׸���
				board[y][x] = WALL;

			if (y == 2 && x != 0 && x != BORDER_WIDTH - 1) // ���� �������� �׸���
				board[y][x] = OVERLINE;
		}
	}
}

// ���� ���� ���
void PrintGameBoard() {
	for (int y = 0; y < BORDER_HEIGHT; y++)
	{
		for (int x = 0; x < BORDER_WIDTH; x++) // ���ӿ��� ���� �׻� ���̰� �ϱ�
		{
			if (y == 2 && x != 0 && x != BORDER_WIDTH - 1 && board[y][x] == EMPTY)
				board[y][x] = OVERLINE;

			switch (board[y][x]) {
			case EMPTY: // �ش�ĭ�� �� �����̸�
				GotoXY(x, y);
				printf("  ");
				break;

			case MBLOCK: // �ش�ĭ�� �����̴� ����̸�
				GotoXY(x, y);
				printf("��");
				break;

			case OVERLINE: // �ش�ĭ�� ���ӿ��� �����̸�
				GotoXY(x, y);
				printf(". ");
				break;

			case WALL: // �ش�ĭ�� ���̸�
				GotoXY(x, y);
				printf("��");
				break;

			case FBLOCK: // �ش�ĭ�� ������ ����̸�
				GotoXY(x, y);
				printf("��");
				break;
			}
		}
	}
}

// �߰� ���� ���
void PrintNextBoard() {
	TextColor(14);
	GotoXY(14, 6);
	printf("S C O R E : %6d", score);
	GotoXY(15, 8);
	printf(" < N E X T >");

	for (int x = 0; x < BORDER_WIDTH - 3; x++)
	{
		GotoXY(14 + x, 9);
		printf("�� ");
	}
	for (int y = 0; y < BORDER_HEIGHT - 20; y++)
	{
		GotoXY(13, y + 10);
		printf("�� ");
	}
	for (int y = 0; y < BORDER_HEIGHT - 20; y++)
	{
		GotoXY(23, y + 10);
		printf("�� ");
	}
	for (int x = 0; x < BORDER_WIDTH - 3; x++)
	{
		GotoXY(14 + x, 14);
		printf("�� ");
	}
}

// ���� �� ����
void TextColor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

// ���� ���
void NewBlock() {
	blockX = 4;
	blockY = 0;
	blockType = rand() % 7;
	blockRotation = 0;

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (BlockShape[blockType][blockRotation][y][x])
				board[blockY + y][blockX + x] = MBLOCK;
		}
	}
	flagNewBlock = 0;
}

// Ű���� �Է�
void Keyboard() {
	if (_kbhit())
	{
		int nkey = _getch();
		if (nkey == SPACEBAR)

			if (nkey == z)
			{
				if (CrushCheck(0, 0, -1) == TRUE)
					Move(0, 0, -1);
			}
		//if (nkey == c) {
		//	printf("c");
		//}
		//if (nkey == p) {
		//	printf("p");
		//}
		//if (nkey == Esc) {
		//	printf("Esc");
		//}

		if (nkey == ARROW)
		{
			nkey = _getch();
			switch (nkey) {
			case UP:
				if (CrushCheck(0, 0, 1) == TRUE) {
					Move(0, 0, 1);
				}
				break;
			case LEFT:
				if (CrushCheck(-1, 0, 0) == TRUE) {
					Move(-1, 0, 0);
				}
				break;
			case RIGHT:
				if (CrushCheck(1, 0, 0) == TRUE) {
					Move(1, 0, 0);
				}
				break;
			case DOWN:
				if (CrushCheck(0, 1, 0) == TRUE) {
					Move(0, 1, 0);
				}
				break;
			}
		}
	}
	return 0;
}

// �浹 üũ
int CrushCheck(int blockXODJ, int blockYODJ, int rotateODJ) {
	int tempRotation = (blockRotation + rotateODJ) % 4;

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (BlockShape[blockType][tempRotation][y][x] == 1
				&& board[blockY + blockYODJ + y][blockX + blockXODJ + x] > 3) {
				return FALSE; // ��ġ�� FALSE
			}
		}
	}
	return TRUE; // ��ġ�� ������ TRUE
}

// �����̴� ����� ������ ������� ����
void FixBlock() {
	for (int y = 0; y < BORDER_HEIGHT; y++)
	{
		for (int x = 0; x < BORDER_WIDTH; x++)
		{
			if (board[y][x] == MBLOCK)
				board[y][x] = FBLOCK;
		}
	}
	flagNewBlock = 1;
	return 0;
}

// �������ο� ������ ���� ����.Ź
void GameOver() {
	for (int x = 1; x < BORDER_WIDTH - 1; x++)
		if (board[2][x] == FBLOCK)
		{
			Sleep(300);
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n");
			printf("           * * *  G A M E   O V E R  * * *");

			while (1)
			{
				if (_kbhit()) // �Է��� ������ ����
				{
					system("cls");
					return 0;
				}
			}
		}
}

// �� �ϼ��� ���� �� ���� ����.Ź
void CleanLine() {
	int blockCount = 0; // �� ���� ��� ��
	int clearLine = 0; // ������ �� ��ġ
	int clearCount = 0; // ������ Ƚ��

	for (int y = BORDER_HEIGHT - 2; y > 2 && clearCount < 4; y--) // 4ȸ �����Ͽ��ٸ� üũ ����
	{
		for (int x = 1; x < BORDER_WIDTH - 1; x++) // �� ���� ��� �� üũ
			if (board[y][x] == FBLOCK)
				blockCount++;

		if (blockCount == 10) // �� �ϼ��� ����
		{
			for (int x = 1; x < BORDER_WIDTH - 1; x++)
				board[y][x] = EMPTY;

			for (clearLine = y; clearLine > 2; clearLine--) // ���� ���� ������
				for (int x = 1; x < BORDER_WIDTH - 1; x++)
				{
					if (clearLine == 3) // ���� �� ���̸� ������ �ʰ� ����
						board[clearLine][x] = EMPTY;
					else
						board[clearLine][x] = board[clearLine - 1][x];
				}
			clearCount++; // ������ Ƚ�� üũ
			y++; // ������ ���� �ٽ� üũ
			score += 10000;
			speedUp += 0.1; // ���̵� ������ �ʿ��� �� �� ����
		}
		blockCount = 0; // �� ���� ��� �� üũ �ʱ�ȭ
	}
}

// �� �ϼ��� ���̵� ����.Ź
void Level() {
	if (speedUp >= 4) // ���̵� ������ �ʿ��� �� ��
	{
		speed += 50; // �ӵ� ����
		speedUp -= 4;
	}
}

// ��� �̵�
void Move(int inputX, int inputY, int rotate) {
	int tempRotation = blockRotation + rotate;

	if (tempRotation > 3)
		tempRotation = 0;

	else if (tempRotation < 0)
		tempRotation = 3;

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (BlockShape[blockType][blockRotation][y][x] == 1)
				board[blockY + y][blockX + x] = EMPTY;
		}
	}
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (BlockShape[blockType][tempRotation][y][x] == 1)
				board[blockY + y + inputY][blockX + x + inputX] = MBLOCK;
		}
	}
	blockX = blockX + inputX; // �Է¹��� ��ŭ x�� �̵�
	blockY = blockY + inputY; // �Է¹��� ��ŭ y�� �̵�
	blockRotation = tempRotation;
}
