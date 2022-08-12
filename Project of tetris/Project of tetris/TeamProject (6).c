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
#define C 99
#define Z 122
#define P 112
#define Enter 13
#define Esc 27
#define BORDER_WIDTH 12
#define BORDER_HEIGHT 24
#define TRUE 1
#define FALSE 0

#pragma comment(lib, "winmm.lib")
#define SOUND_FILE_NAME "C:\\He's a Pirate (online-audio-converter.com).wav"

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
int copyBoard[BORDER_HEIGHT][BORDER_WIDTH];
int nextBlockType;
int flagNextBlock;
int speedUp = 0;
int speed = 0;
int score = 0;
int flagCrush;
int shuffleBlock[7];
int cnt;


void GotoXY(int, int);
void SetConsole();
void ConsoleSize();
void RemoveCurser();
void RemoveScrollbar();
void TextColor(int);

void StartScreen();
void StopScreen();
void EndScreen();

void ResetGameBoard();
void ResetCopyGameBoard();
void PrintGameBoard();
void PrintNextBoard();

void Keyboard();
void NewBlock();
void PrintNextBlock();

int CrushCheck(int, int, int);
void FixBlock();
void CleanLine();
void Level();
void GameOverCheck();
void PrintGameOver();
void BlockShuffler();
int BlockSelector();

void Move(int, int, int);


void main() {
	cnt = 7;
	srand(time(NULL));
	SetConsole();
	StartScreen();
	ResetGameBoard();
	ResetCopyGameBoard();
	PrintGameBoard();
	PrintNextBoard();
	NewBlock();

	while (1) {
		Keyboard();
		if (flagNewBlock == 1)
			NewBlock();

		if (CrushCheck(0, 1, 0) == FALSE) {
			FixBlock();
			CleanLine();
			Level();
			GameOverCheck();
		}
		else {
			Move(0, 1, 0);
		}
		PrintGameBoard();
		PrintNextBoard();
		Sleep(150 - speed);
	}
}

void BlockShuffler() {
	int j, temp;
	for (int i = 0; i < 7; i++) {
		shuffleBlock[i] = i;
	}

	for (int i = 0; i < 7; i++) {
		j = rand() % 7;

		temp = shuffleBlock[i];
		shuffleBlock[i] = shuffleBlock[j];
		shuffleBlock[j] = temp;
	}
}

int BlockSelector() {
	cnt++;
	
	if (cnt > 6) {
		BlockShuffler();
		cnt = 0;
	}
	return shuffleBlock[cnt];
}

// ȭ�� ��ǥ ����
void GotoXY(int x, int y) {
	COORD Pos;
	Pos.X = x * 2;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// �ܼ�â ����
void SetConsole() {
	ConsoleSize();
	RemoveScrollbar();
	RemoveCurser();
	PlaySound(TEXT(SOUND_FILE_NAME), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

// �ܼ�â ũ�� ����
void ConsoleSize() {
	system("mode con cols=51 lines=25");
}

// Ŀ�� ����
void RemoveCurser() {
	CONSOLE_CURSOR_INFO curinfo = { 0, };
	curinfo.dwSize = 1;
	curinfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
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

// ���� �� ����
void TextColor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

// ����ȭ��
void StartScreen() {
	TextColor(15);
	GotoXY(0, 5);
	printf("           * * *  T E T R I S  * * *\n\n"); //����ȭ�� ���
	printf("            �� �� ��  : �̵�\n");
	printf("               ��     : ȸ��\n");
	printf("               Z      : ��ȸ��\n");
	printf("               C      : ��� ���� �� ��ü\n");
	printf("             Space    : ����\n");
	printf("               P      : �Ͻ�����\n");
	printf("              ESC     : ���� ����\n\n");

	while (1) {
		if (_kbhit()) { // �Է��� ������ ����
			int nkey = _getch();
			if (nkey == Enter) // Enter�� ����
			{
				system("cls");
				return 0;
			}
			if (nkey == Esc) // Esc�� ����ȭ�� ����
				EndScreen();
		}
	}
}

// ����ȭ��
void StopScreen() {
	system("cls");
	TextColor(15);
	GotoXY(7, 11);
	printf("�� ��  ��  ��  �� ��\n"); // ����ȭ�� ���
	while (1) {
		if (_kbhit()) {
			int nkey = _getch();
			if (nkey == P) {
				system("cls");
				return 0;
			}
		}
	}
}

// ����ȭ��
void EndScreen() {
	system("cls"); // ȭ�� �ʱ�ȭ
	TextColor(15);
	GotoXY(7, 11);
	printf("�� ��  ��  ��  �� ��\n\n\n\n\n\n\n\n"); // ����ȭ�� ���
	exit(0); // ���α׷� ����
}

// ���� ���� �ʱ�ȭ
void ResetGameBoard()
{
	for (int y = 0; y < BORDER_HEIGHT; y++) { // �� ����
		for (int x = 0; x < BORDER_WIDTH; x++)
			copyBoard[y][x] = 1000;
	}
}

// ResetGameBoard�� ResetCopyGameBoard�� ����
void ResetCopyGameBoard()
{
	for (int y = 0; y < BORDER_HEIGHT; y++) { // �� ����
		for (int x = 0; x < BORDER_WIDTH; x++) {
			copyBoard[y][x] = EMPTY;  // board�� copyboard�� ����
		}
	}

	for (int y = 0; y < BORDER_HEIGHT; y++) {
		for (int x = 0; x < BORDER_WIDTH; x++) {
			if (x == 0 || x == BORDER_WIDTH - 1) // ��-�� �� �׸���
				copyBoard[y][x] = WALL; // board�� copyboard�� ����

			if (y == BORDER_HEIGHT - 1) // �ϴ� �� �׸���
				copyBoard[y][x] = WALL; // board�� copyboard�� ����

			if (y == 2 && x != 0 && x != BORDER_WIDTH - 1) // ���� �������� �׸���
				copyBoard[y][x] = OVERLINE; // board�� copyboard�� ����
		}
	}
}

// ���� ���� ���
void PrintGameBoard()
{
	for (int y = 0; y < BORDER_HEIGHT; y++) {
		for (int x = 0; x < BORDER_WIDTH; x++) {
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
					if (blockType == 0)
						TextColor(4);
					if (blockType == 1)
						TextColor(2);
					if (blockType == 2)
						TextColor(9);
					if (blockType == 3)
						TextColor(10);
					if (blockType == 4)
						TextColor(11);
					if (blockType == 5)
						TextColor(12);
					if (blockType == 6)
						TextColor(13);
					GotoXY(x, y);
					printf("��");
					break;

				case OVERLINE: // �ش�ĭ�� ���� ���������̸�
					TextColor(15);
					GotoXY(x, y);
					printf("_ ");
					break;

				case WALL: // �ش�ĭ�� ���̸�
					TextColor(15);
					GotoXY(x, y);
					printf("��");
					break;

				case FBLOCK: // �ش�ĭ�� ������ ����̸�
					TextColor(15);
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

// �߰� ���� ���
void PrintNextBoard() {
	TextColor(14);
	GotoXY(13, 6);
	printf("S C O R E : %4d", score);
	GotoXY(14, 8);
	printf("< N E X T >");
	TextColor(15);

	for (int x = 0; x < BORDER_WIDTH - 6; x++)
	{
		GotoXY(14 + x, 9);
		printf("��");
	}
	for (int y = 0; y < BORDER_HEIGHT - 20; y++)
	{
		GotoXY(13, y + 10);
		printf("��");
	}
	for (int y = 0; y < BORDER_HEIGHT - 20; y++)
	{
		GotoXY(20, y + 10);
		printf("��");
	}
	for (int x = 0; x < BORDER_WIDTH - 6; x++)
	{
		GotoXY(14 + x, 14);
		printf("��");
	}
}

// Ű���� �Է�
void Keyboard() {
	if (_kbhit())
	{
		int nkey = _getch();
		if (nkey == ARROW)
		{
			nkey = _getch();
			switch (nkey) {
			case UP:
				/*if (CrushCheck(0, 0, 1) == TRUE) {
					Move(0, 0, 1);
				}*/
				// ������ ȸ�� -> ���� �ڵ� ���ظ���
				for (int rotateMoveY = 0;; rotateMoveY--) {
					for (int rotateMoveX = 0; rotateMoveX < 3; rotateMoveX++) {
						for (int n = 0; n < 2; n++) {
							rotateMoveX *= -1;
							if (CrushCheck(rotateMoveX, rotateMoveY, 1) == TRUE) {
								Move(rotateMoveX, rotateMoveY, 1);
								return;
							}
						}
					}
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
		if (nkey == Z)
		{
			if (CrushCheck(0, 0, -1) == TRUE)
				Move(0, 0, -1);
		}
		if (nkey == SPACEBAR)
		{
			while (1) {
				if (CrushCheck(0, 1, 0) == TRUE) {
					Move(0, 1, 0);
				}
				else
					break;
			}
		}
		//if (nkey == C) {
		//	printf("C");
		//}
		if (nkey == P) // P�� ����ȭ�� ����
			StopScreen();
		if (nkey == Esc)
			EndScreen();
	}
}

// ���� ���
void NewBlock() {
	blockX = 4;
	blockY = 0;
	blockRotation = 0;
	if (flagNextBlock == 0)
	{
		blockType = BlockSelector();
		flagNextBlock = 1;
	}
	else
		blockType = nextBlockType;

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (BlockShape[blockType][blockRotation][y][x])
				copyBoard[blockY + y][blockX + x] = MBLOCK;
		}
	}

	flagNewBlock = 0;
	PrintNextBlock();
}

// ���� ��� ���
void PrintNextBlock() {
	nextBlockType = BlockSelector();
	if (nextBlockType == 0)
		TextColor(4);
	if (nextBlockType == 1)
		TextColor(2);
	if (nextBlockType == 2)
		TextColor(9);
	if (nextBlockType == 3)
		TextColor(10);
	if (nextBlockType == 4)
		TextColor(11);
	if (nextBlockType == 5)
		TextColor(12);
	if (nextBlockType == 6)
		TextColor(13);

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			GotoXY(15 + x, 10 + y);
			if (BlockShape[blockType][0][y][x] == 1) {
				printf("  ");
			}
		}
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			GotoXY(15 + x, 10 + y);
			if (BlockShape[nextBlockType][0][y][x] == 1) {
				printf("��");
			}
		}
	}
}

// �浹 üũ
int CrushCheck(int blockXODJ, int blockYODJ, int rotateODJ) {
	int tempRotation = (blockRotation + rotateODJ) % 4;

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
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
	for (int y = 0; y < BORDER_HEIGHT; y++) {
		for (int x = 0; x < BORDER_WIDTH; x++) {
			if (copyBoard[y][x] == MBLOCK) // board�� copyboard�� ����
				copyBoard[y][x] = FBLOCK; // board�� copyboard�� ����
		}
	}
	flagNewBlock = 1;
}

// �� �ϼ��� ���� �� ���� ����
void CleanLine() {
	int blockCount = 0; // �� ���� ��� ��
	int clearLine = 0; // ������ �� ��ġ
	int clearCount = 0; // ������ Ƚ��

	for (int y = BORDER_HEIGHT - 2; y > 2 && clearCount < 4; y--) // 4ȸ �����Ͽ��ٸ� üũ ����
	{
		for (int x = 1; x < BORDER_WIDTH - 1; x++) { // �� ���� ��� �� üũ
			if (copyBoard[y][x] == FBLOCK)
				blockCount++;
		}

		if (blockCount == 10) // �� �ϼ��� ����
		{
			for (clearLine = y; clearLine > 2; clearLine--) // ���� ���� ������
				for (int x = 1; x < BORDER_WIDTH - 1; x++)
				{
					if (clearLine == 3) // ���� �� ���̸� ������ �ʰ� ����
						copyBoard[clearLine][x] = EMPTY;
					else
						copyBoard[clearLine][x] = copyBoard[clearLine - 1][x];
				}
			clearCount++; // ������ Ƚ�� üũ
			y++; // ������ ���� �ٽ� üũ
			speedUp += 1; // ���̵� ������ �ʿ��� �� �� ����
		}
		blockCount = 0; // �� ���� ��� �� üũ �ʱ�ȭ
	}
	if (clearCount == 1)
		score += 10;
	if (clearCount == 2)
		score += 30;
	if (clearCount == 3)
		score += 50;
	if (clearCount == 4)
		score += 70;
}

// �� �ϼ��� ���̵� ����
void Level() {
	if (speedUp >= 4) // ���̵� ������ �ʿ��� �� ��
	{
		speed += 10; // �ӵ� ����
		speedUp -= 4;
	}
}

// �������ο� ������ ���� ����
void GameOverCheck() {
	for (int x = 1; x < BORDER_WIDTH - 1; x++)
	{
		if (copyBoard[2][x] == FBLOCK) // Y�� 2�� ��ġ�� ������ ����� ������
		{
			PrintGameOver(); // ���ӿ��� ȭ�� ���
			system("cls"); // ȭ�� ��ü ����
			ResetGameBoard(); // �ʱ�ȭ ���Ӻ���
			ResetCopyGameBoard(); // �ʱ�ȭ ī�� ���Ӻ���
			PrintGameBoard(); // ���Ӻ��� ���
			EndScreen(); // ����ȭ�� ���
		}
	}
}

// ���ӿ��� ȭ�� ���
void PrintGameOver() {
	PrintGameBoard(); // ����� ����� ȭ�� ���
	GotoXY(4, 11);
	printf("Game Over"); // ���ӿ��� �ؽ�Ʈ ���
	GotoXY(2, 12);
	printf("Press Any Button");
	Sleep(1000); //�� �ʰ� ����

	while (_kbhit()) { //Sleep �Ǿ��ִµ����� Ű �Է��� �� �ð�
		_getch();
	}
	_getch(); // �� ���Ŀ� Ű �Է��� ������ Ż��
}

// ��� �̵�
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