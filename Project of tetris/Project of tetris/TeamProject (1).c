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
		// I 블록 (축 3, 3)
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
		// 역 Z 블록 (축 2, 3)
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
		// Z 블록 (축 2, 3)
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
		// 역 ㄱ 블록
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
		// T 블록
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

void main() {
	srand(time(NULL));
	SetConsole();

	StartScreen();
	ResetGameBoard(); // 게임판을 초기화
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
			CleanLine();
		}
		else {
			Move(0, 1, 0);
		}
		Sleep(200);
	}

}

//시작화면.탁
void StartScreen() {  //시작화면 출력
	printf("\n\n\n\n\n");
	printf("           * * *  T E T R I S  * * *\n\n");
	printf("            ◁ ▷ ▽  : 이동\n");
	printf("               △     : 회전\n");
	printf("               Z      : 역회전\n");
	printf("               C      : 블럭 저장 및 교체\n");
	printf("             Space    : 낙하\n");
	printf("               P      : 일시정지\n");
	printf("              ESC     : 게임 종료\n\n");

	char save_key;
	while (1)
	{
		if (_kbhit()) //입력이 있으면 실행
		{
			save_key = _getch();
			if (save_key == 13) //Enter면 시작
			{
				system("cls");
				return 0;
			}
			if (save_key == 27) //Esc면 종료화면 실행
				EndScreen();
		}
	}
}

//종료화면.탁
void EndScreen() {
	system("cls"); //화면 초기화
	for (int y = 0; y < BORDER_HEIGHT; y++) //종료화면 출력
	{
		if (y == 11)
			printf("■ 게  임  종  료 □\n");
		else if (y % 2 == 0)
			printf("□■□■□■□■□■\n");
		else
			printf("■□■□■□■□■□\n");
	}
	exit(0); //프로그램 종료
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
				board[blockY + y][blockX + x] = EMPTY;
			}
		}
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (BlockShape[blockType][tempRotation][y][x] == 1) {
				board[blockY + y + inputY][blockX + x + inputX] = MBLOCK;
			}
		}
	}
	blockX = blockX + inputX; // 입력받은 만큼 x축 이동
	blockY = blockY + inputY; // 입력받은 만큼 y축 이동
	blockRotation = tempRotation;
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
	flagNewBlock = 0;
}

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
	flagNewBlock = 1;
	return;
}

int CrushCheck(int blockXODJ, int blockYODJ, int rotateODJ) {
	int tempRotation = (blockRotation + rotateODJ) % 4;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (BlockShape[blockType][tempRotation][y][x] == 1
				&& board[blockY + blockYODJ + y][blockX + blockXODJ + x] > 3) {
				return FALSE; // 겹치면 FALSE
			}
		}
	}
	return TRUE; // 겹치지 않으면 TRUE
}

void Keyboard() {
		if (_kbhit()) {

			int nkey = _getch();
			if (nkey == SPACEBAR) {

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
//한 줄 완성시 삭제
void CleanLine() {
	int clearCount = 0; //한 줄에 찬 블럭 수
	int clearLineNum[4] = { 0 }; //삭제할 줄 위치
	int clearNumSeat = 0; //clearLineNum의 배열 위치
	int clearDeletelSeat = 0; //첫번째로 삭제한 줄 위치

	//줄 삭제
	for (int y = BORDER_HEIGHT - 2; y > 2; y--)
	{
		if (clearDeletelSeat != 0 && y < clearDeletelSeat - 3) //삭제한 줄에서 3칸 위로만 확인
			break;

		for (int x = 1; x < BORDER_WIDTH - 1; x++)
			if (board[y][x] == FBLOCK)
				clearCount++; //한 줄에 찬 블럭 수 체크

		if (clearCount == 10)
		{
			for (int x = 1; x < BORDER_WIDTH - 1; x++)
				board[y][x] = EMPTY; //해당 줄이 가득찼다면 줄 삭제
			clearLineNum[clearNumSeat] = y; //라인 위치 저장
			clearNumSeat++;

			if (clearDeletelSeat = 0)
				clearDeletelSeat = y; //3칸 위로만 확인하기 위해 저장
		}
		clearCount = 0; //블럭 수 체크 초기화
	}

	//줄 내리기
	for (clearNumSeat = 0; clearNumSeat < 4 && clearLineNum[clearNumSeat] != 0; clearNumSeat++)
	{
		for (int y = clearLineNum[clearNumSeat]; y > 2; y--)
		{
			if (y == 3)
			{
				for (int x = 1; x < BORDER_WIDTH - 1; x++)
					board[y][x] = EMPTY;
				break;
			}

			for (int x = 1; x < BORDER_WIDTH - 1; x++)
				board[y][x] = board[y - 1][x];
		}
	}
}
