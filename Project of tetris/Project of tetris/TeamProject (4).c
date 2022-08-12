#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

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
#define _CRT_SECURE_NO_WARNINGS


enum { EMPTY = 0, MBLOCK = 1, OVERLINE = 2, SBLOCK = 3, WALL = 4, FBLOCK = 5 };

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
int blockX;
int blockY;
int blockRotation = 0;
int blockType;
int board[BORDER_HEIGHT][BORDER_WIDTH];
int flagNewBlock;
int blockTypeNow;
int copyBoard[BORDER_HEIGHT][BORDER_WIDTH];
int nextBlockType;
int flagNextBlock;

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
void ResetCopyGameBoard();  // ResetGameBoard�� ResetCopyGameBoard�� ����
void FixBlock();
int CrushCheck(int, int, int);
void Keyboard();
void PrintNextBoard();
void TextColor(int);
void PrintNextBlock();

void StartScreen();
void EndScreen();

void LineCheck();
void PrintGameOver();
void GameoverCheck();

int main() {
	char m[256] = "";
	PlaySound(NULL, 0, 0);
	Sleep(10);
	PlaySound(TEXT("C:\\BGM Tetris Bradinsky (online-audio-converter.com).wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);

	/*while (1)
	{
		scanf_s("%s", &m, 256);
		if (strcmp(m, "pp"))
		{
			printf("%s", m);
		}
		else
		{
			break;
		}
		return 0;*/
	//}
	srand(time(NULL));
	SetConsole();

	StartScreen();
	ResetGameBoard(); // �������� �ʱ�ȭ
	ResetCopyGameBoard(); // �������� �ʱ�ȭ  // ResetGameBoard�� ResetCopyGameBoard�� ����
	NewBlock(); 
	PrintGameBoard();

	while (1) {
		Keyboard();
		if (flagNewBlock == 1) {
			NewBlock();
		}
			PrintGameBoard();
			PrintNextBoard();


		if (CrushCheck(0, 1, 0) == FALSE) {
			FixBlock();
			LineCheck();
		}
		else {
			Move(0, 1, 0); // �ڵ����� �ϰ�
		}
					Sleep(200);
		GameoverCheck();


	}

}

//����ȭ��.Ź
void StartScreen() {  //����ȭ�� ���
	printf("\n\n\n\n\n");
	printf("           * * *  T E T R I S  * * *\n\n");
	printf("            �� �� ��  : �̵�\n");
	printf("               ��     : ȸ��\n");
	printf("               Z      : ��ȸ��\n");
	printf("               C      : �� ���� �� ��ü\n");
	printf("             Space    : ����\n");
	printf("               P      : �Ͻ�����\n");
	printf("              ESC     : ���� ����\n\n");

	char save_key;
	while (1)
	{
		if (_kbhit()) //�Է��� ������ ����
		{
			save_key = _getch();
			if (save_key == 13) //Enter�� ����
			{
				system("cls");
				return 0;
			}
			if (save_key == 27) //Esc�� ����ȭ�� ����
				EndScreen();
		}
	}
}

//����ȭ��.Ź
void EndScreen() {
	system("cls"); //ȭ�� �ʱ�ȭ
	for (int y = 0; y < BORDER_HEIGHT; y++) //����ȭ�� ���
	{
		if (y == 11)
			printf("�� ��  ��  ��  �� ��\n");
		else if (y % 2 == 0)
			printf("�����������\n");
		else
			printf("�����������\n");
	}
	exit(0); //���α׷� ����
}

void GotoXY(int x, int y) {
	COORD Pos;
	Pos.X = x * 2;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// Ŀ�� ����
void RemoveCurser()
{
	CONSOLE_CURSOR_INFO curinfo = { 0, };
	curinfo.dwSize = 1;
	curinfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
}

void ConsoleSize()// �ܼ�â ũ�� ����
{
	system("mode con cols=80 lines=25"); // ���� 79, ���� 30���� ����
}

void RemoveScrollbar() // �ܼ�â ��ũ�ѹ� ����
{
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

void SetConsole() // �ܼ�â ����
{
	ConsoleSize();
	RemoveScrollbar();
	RemoveCurser();
}

// ���� �� ����
void TextColor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

void Move(int inputX, int inputY, int rotate) {
	int tempRotation = blockRotation + rotate;
	if (tempRotation > 3) {
		tempRotation = 0;
	}
	else if (tempRotation < 0) {
		tempRotation = 3;
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (BlockShape[blockType][blockRotation][y][x] == 1) {
				copyBoard[blockY + y][blockX + x] = EMPTY;
			}
		}
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (BlockShape[blockType][tempRotation][y][x] == 1) {
				copyBoard[blockY + y + inputY][blockX + x + inputX] = MBLOCK;
			}
		}
	}
	blockX = blockX + inputX; // �Է¹��� ��ŭ x�� �̵�
	blockY = blockY + inputY; // �Է¹��� ��ŭ y�� �̵�
	blockRotation = tempRotation;
}

// ���� ��
void NewBlock() {
	blockX = 4;
	blockY = 0;
	blockRotation = 0;
	if (flagNextBlock == 0) {
		blockType = rand() % 7;
		flagNextBlock = 1;
	}
	else {
		blockType = nextBlockType;
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (BlockShape[blockType][blockRotation][y][x]) {
				copyBoard[blockY + y][blockX + x] = MBLOCK;
			}
		}
	}
	flagNewBlock = 0;

	PrintNextBlock();
}

	// ���� �� ���
void PrintNextBlock() {
	TextColor(14);

	nextBlockType = rand() % 7;

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			GotoXY(33 + x, 6 + y);
			if (BlockShape[blockType][0][y][x] == 1) {
				printf("  ");
			}
		}
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			GotoXY(33 + x, 6 + y);
			if (BlockShape[nextBlockType][0][y][x] == 1) {
				printf("��");
			}
		}
	}
}


void PrintGameBoard()
{
	for (int y = 0; y < BORDER_HEIGHT; y++)
	{
		for (int x = 0; x < BORDER_WIDTH; x++)
		{
			if (copyBoard[y][x] != board[y][x]) // ī�Ǻ���� ���尡 ��ġ���� ������ �ٽ� �׸���
			{
				board[y][x] = copyBoard[y][x]; // ī�� ������ ���� �־���  
				switch (board[y][x])
				{
				case EMPTY: // �ش�ĭ�� ������̸�
					GotoXY(x, y);
					printf("  ");
					break;

				case MBLOCK: // �ش�ĭ�� �����̴� ����̸�
					GotoXY(x, y);
					printf("��");
					break;

				case OVERLINE: // �ش�ĭ�� ���� ���������̸�
					GotoXY(x, y);
					printf("_ ");
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
				if (y == 2 && x != 0 && x != BORDER_WIDTH - 1 && copyBoard[y][x] == EMPTY)   //�������� ��ġ�� ���� ����ٸ�
					copyBoard[y][x] = OVERLINE; 	//���������� �׸���
			}
		}
	}
}

void PrintNextBoard() {
	GotoXY(30, 4);
	TextColor(14);
	printf("< N E X T >");

	for (int x = 0; x < BORDER_WIDTH - 3; x++) {
		GotoXY(30 + x, 5);
		printf("�� ");
	}

	for (int y = 0; y < BORDER_HEIGHT - 18; y++) {
		GotoXY(30, y + 6);
		printf("�� ");
	}

	for (int y = 0; y < BORDER_HEIGHT - 18; y++) {
		GotoXY(38, y + 6);
		printf("�� ");
	}

	for (int x = 0; x < BORDER_WIDTH - 3; x++) {
		GotoXY(30 + x, 11);
		printf("�� ");
	}
}

void ResetGameBoard() {
	for (int y = 0; y < BORDER_HEIGHT; y++) {
		for (int x = 0; x < BORDER_WIDTH; x++)
			copyBoard[y][x] = 1000;
	}
}

void ResetCopyGameBoard() // ResetGameBoard�� ResetCopyGameBoard�� ����
{
	for (int y = 0; y < BORDER_HEIGHT; y++) // �� ����
		for (int x = 0; x < BORDER_WIDTH; x++)
			copyBoard[y][x] = EMPTY;  // board�� copyboard�� ����

	for (int y = 0; y < BORDER_HEIGHT; y++)
	{
		for (int x = 0; x < BORDER_WIDTH; x++)
		{
			if (x == 0 || x == BORDER_WIDTH - 1) // ��-�� �� �׸���
				copyBoard[y][x] = WALL; // board�� copyboard�� ����

			if (y == BORDER_HEIGHT - 1) // �ϴ� �� �׸���
				copyBoard[y][x] = WALL; // board�� copyboard�� ����

			if (y == 2 && x != 0 && x != BORDER_WIDTH - 1) // ���� �������� �׸���
				copyBoard[y][x] = OVERLINE; // board�� copyboard�� ����
		}
	}
}

void FixBlock() {
	for (int y = 0; y < BORDER_HEIGHT; y++) {
		for (int x = 0; x < BORDER_WIDTH; x++) {
			if (copyBoard[y][x] == MBLOCK) { // board�� copyboard�� ����
				copyBoard[y][x] = FBLOCK;	 // board�� copyboard�� ����
			}
		}
	}
	flagNewBlock = 1;
	return;
}

int CrushCheck(int blockXODJ, int blockYODJ, int rotateODJ) {
	int tempRotation = (blockRotation + rotateODJ) % 4;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (BlockShape[blockType][tempRotation][y][x] == 1
				&& copyBoard[blockY + blockYODJ + y][blockX + blockXODJ + x] > 3) {
				return FALSE; // ��ġ�� FALSE
			}
		}
	}
	return TRUE; // ��ġ�� ������ TRUE
}

void Keyboard() {
		if (_kbhit()) {

			int nkey = _getch();
			if (nkey == SPACEBAR) {
				while (1) {
					if (CrushCheck(0, 1, 0) == TRUE) {
						Move(0, 1, 0);
					}
					else {
						break;
					}
				}
			}
			if (nkey == z) {
				if (CrushCheck(0, 0, -1) == TRUE) {
					Move(0, 0, -1);
				}
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

			if (nkey == ARROW) {
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
	return;
}

void LineCheck() {
	int k;  // ������ �ı��� Y��ġ�� ����
	int block_linecheck; // 10���� ���� ä�������� üũ�ϴ� �뵵�� ����

	for (int y = BORDER_HEIGHT - 2; y > 2;)
	{
		block_linecheck = 0; // ���� y�ٿ� �ö����� 0���� �ʱ�ȭ

		for (int x = 1; x < BORDER_WIDTH - 1; x++) // (Ž��) x �̵� >>
			if (copyBoard[y][x] == FBLOCK)  // �ش� ��ġ�� fix�� ����� ������
				block_linecheck++; // �� ����

		if (block_linecheck == BORDER_WIDTH - 2)
		{
			for (k = y; k > 1; k--) // k�� ���� y ���� �Ѱ��ְ� k �� 1�̵Ǹ� ����
				for (int l = 1; l < BORDER_WIDTH - 1; l++)
				{
					if (copyBoard[k - 1][l] != OVERLINE)
						copyBoard[k][l] = copyBoard[k - 1][l];

					if (copyBoard[k - 1][l] == OVERLINE)  // ��ĭ ���� �ִ� ����� ���������� ��� empty
						copyBoard[k][l] = EMPTY;
				}
		}
		else
			y--;  // ������
	}
}

// ���� ���� �� ��� ��� ����
void PrintGameOver() {
	//for (int y = 0; y < BORDER_HEIGHT - 1; y++) 
	//{
	//	for (int x = 1; x < BORDER_WIDTH - 1; x++)
	//	{
	//		copyboard[y][x] = EMPTY;
	//	}
	//} // �� �� ������
	PrintGameBoard(); // ����� ����� ȭ�� ���
	GotoXY(4, 12);
	printf("GameOver"); // ���ӿ��� �ؽ�Ʈ ���

	GotoXY(2, 14);
	printf("Press Any Button");


	Sleep(1000); //�� �ʰ� ����

	while (_kbhit()) { //Sleep �Ǿ��ִµ����� Ű �Է��� �� �ð�
		_getch();
	}

	_getch(); // �� ���Ŀ� Ű �Է��� ������ Ż��
}

// ���� ���� üũ
void GameoverCheck()
{
	for (int x = 1; x < BORDER_WIDTH - 2; x++)
	{
		if (copyBoard[2][x] == FBLOCK) // Y�� 2�� ��ġ�� ������ ����� ������
		{
			PrintGameOver(); // ���� ���� ȭ�� ���

			system("cls"); // ȭ�� ��ü ����

			ResetGameBoard(); // �ʱ�ȭ ���Ӻ���
			ResetCopyGameBoard(); // �ʱ�ȭ ī�� ���Ӻ���
			
			PrintGameBoard(); // ���Ӻ��� ���



			system("cls"); // ȭ�� ��ü ����
			
			for (int y = 0; y < BORDER_HEIGHT; y++) //����ȭ�� ���
			{
				if (y == 11)
					printf("�� ��  ��  ��  �� ��\n");
				else if (y % 2 == 0)
					printf("�����������\n");
				else
					printf("�����������\n");
			}
			exit(0); // cmd ����
		}
	}
}
