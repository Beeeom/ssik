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


enum { EMPTY = 0, MBLOCK = 1, OVERLINE = 2, SBLOCK = 3, WALL = 4, FBLOCK = 5 };

// [블록 종류][블록 회전][블록 모양][블록 모양]
int BlockShape[7][4][4][4] = {
	{
		// ㅁ 블록
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
		// I 블록
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
		// 역 Z 블록
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
		// Z 블록
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
		// ㄱ 블록
		{
			{0, 0, 0, 0},
			{0, 0, 0, 1},
			{0, 1, 1, 1},
			{0, 0, 0, 0}
		},
		{
			{0, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{1, 1, 1, 0},
			{1, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 1, 0}
		}
	},
	{
		// 역 ㄱ 블록
		{
			{0, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 1, 1, 1},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 0, 0},
			{0, 1, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 1, 0},
			{0, 0, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
		}
	},
	{
		// T 블록
		{
			{0, 0, 1, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0},
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
int flag;
int blockTypeNow;

void GotoXY(int, int);
void RemoveCurser();
void NewBlock();
void PrintNextBlock();
void Move(int, int);
void ConsoleSize();
void RemoveScrollbar();
void SetConsole();
void PrintGameBoard();
void ResetGameBoard();
void FixBlock();
int CrushCheck(int, int);
void Keyboard();
void PrintNextBoard();
void TextColor(int);

void main() {
	srand(time(NULL));
	//blockNext = rand() % 7;
	//printNextBlock();
	SetConsole();
	ResetGameBoard(); // 게임판을 초기화
	NewBlock();
	PrintGameBoard();

	while (1) {
		Keyboard();
		if (flag == 1) {
			NewBlock();
		}
		PrintGameBoard();
		PrintNextBoard();

		if (CrushCheck(0, 1) == FALSE) {
			FixBlock();
		}
		else {
			Move(0, 1);
		}
		Sleep(100);
	}

}

void GotoXY(int x, int y) {
	COORD Pos;
	Pos.X = x * 2;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// 커서 제거
void RemoveCurser()
{
	CONSOLE_CURSOR_INFO curinfo = { 0, };
	curinfo.dwSize = 1;
	curinfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
}

void ConsoleSize()// 콘솔창 크기 조절
{
	system("mode con cols=130 lines=35"); // 가로 79, 세로 30으로 설정
}

void RemoveScrollbar() // 콘솔창 스크롤바 삭제
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

void SetConsole() // 콘솔창 세팅
{
	ConsoleSize();
	RemoveScrollbar();
	RemoveCurser();
}

// 글자 색 변경
void TextColor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

void Move(int inputX, int inputY) {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (BlockShape[blockType][blockRotation][y][x] == 1) {
				board[blockY + y][blockX + x] = EMPTY;
			}
		}
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (BlockShape[blockType][blockRotation][y][x] == 1) {
				board[blockY + y + inputY][blockX + x + inputX] = MBLOCK;
			}
		}
	}
	blockX = blockX + inputX; // 입력받은 만큼 x축 이동
	blockY = blockY + inputY; // 입력받은 만큼 y축 이동
}

// 현재 블럭
void NewBlock() {
	blockX = 4;
	blockY = 0;
	blockType = rand() % 7;
	blockRotation = 0;

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (BlockShape[blockType][blockRotation][y][x]) {
				board[blockY + y][blockX + x] = MBLOCK;
			}
		}
	}
	flag = 0;
}
//int main(void) {
//CursorView(0);
//	GotoXY(x, y);
//	printf("ㅁ");
//	while (1) {
//		if (_kbhit()) {
//			int nkey = _getch();
//			switch (nkey) {
//			case UP:
//				system("cls");
//				GotoXY(x, --y);
//				printf("ㅁ");
//				break;
//			case LEFT:
//				system("cls");
//				GotoXY(x=x-2, y);
//				printf("ㅁ");
//				break;
//			case RIGHT:
//				system("cls");
//				GotoXY(x=x+2, y);
//				printf("ㅁ");
//				break;
//			case DOWN:
//				system("cls");
//				GotoXY(x, ++y)      n;
//				printf("ㅁ");
//				break;
//			}
//		}
//	}
//}
void PrintGameBoard()
{
	for (int y = 0; y < BORDER_HEIGHT; y++)
	{
		for (int x = 0; x < BORDER_WIDTH; x++)
		{
			// 게임 종료 라인 항상 보이게 하기
			if (y == 2 && x != 0 && x != BORDER_WIDTH - 1 && board[y][x] == EMPTY) {
				board[y][x] = OVERLINE;
			}
			switch (board[y][x])
			{
			case EMPTY: // 해당칸이 빈공간이면
				GotoXY(x, y);
				printf("  ");
				break;

			case MBLOCK: // 해당칸이 움직이는 블록이면
				GotoXY(x, y);
				printf("■");
				break;

			case OVERLINE: // 해당칸이 게임 오버라인이면
				GotoXY(x, y);
				printf(". ");
				break;

			case WALL: // 해당칸이 벽이면
				GotoXY(x, y);
				printf("▩");
				break;

			case FBLOCK: // 해당칸이 고정된 블록이면
				GotoXY(x, y);
				printf("□");
				break;
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
		printf("■ ");
	}

	for (int y = 0; y < BORDER_HEIGHT - 18; y++) {
		GotoXY(30, y + 6);
		printf("■ ");
	}

	for (int y = 0; y < BORDER_HEIGHT - 18; y++) {
		GotoXY(38, y + 6);
		printf("■ ");
	}

	for (int x = 0; x < BORDER_WIDTH - 3; x++) {
		GotoXY(30 + x, 11);
		printf("■ ");
	}
}

void ResetGameBoard()
{
	for (int y = 0; y < BORDER_HEIGHT; y++) // 빈 공간
		for (int x = 0; x < BORDER_WIDTH; x++)
			board[y][x] = EMPTY;

	for (int y = 0; y < BORDER_HEIGHT; y++)
	{
		for (int x = 0; x < BORDER_WIDTH; x++)
		{
			if (x == 0 || x == BORDER_WIDTH - 1) // 좌-우 벽 그리기
				board[y][x] = WALL;

			if (y == BORDER_HEIGHT - 1) // 하단 벽 그리기
				board[y][x] = WALL;

			if (y == 2 && x != 0 && x != BORDER_WIDTH - 1) // 게임 오버라인 그리기
				board[y][x] = OVERLINE;
		}
	}
}

void FixBlock() {
	for (int y = 0; y < BORDER_HEIGHT; y++) {
		for (int x = 0; x < BORDER_WIDTH; x++) {
			if (board[y][x] == MBLOCK) {
				board[y][x] = FBLOCK;
			}
		}
	}
	flag = 1;
	return;
}

int CrushCheck(int blockXODJ, int blockYODJ) {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (BlockShape[blockType][blockRotation][y][x] == 1
				&& board[blockY + blockYODJ + y][blockX + blockXODJ + x] > 3) {
				return FALSE;
			}
		}
	}
	return TRUE;
}

void Keyboard() {
		if (_kbhit()) {

			int nkey = _getch();
			if (nkey == SPACEBAR) {

			}
			////int nkey = _getch();
			//if (nkey == z) {
			//	printf("z");
			//}
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
					break;
				case LEFT:
					Move(-1, 0);
					break;
				case RIGHT:
					Move(1, 0);
					break;
				case DOWN:
					Move(0, 1);
					break;

				}
			}
		}
	return;
}