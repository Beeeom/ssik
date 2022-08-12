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
void ResetCopyGameBoard();  // ResetGameBoard를 ResetCopyGameBoard로 덮음
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
	ResetGameBoard(); // 게임판을 초기화
	ResetCopyGameBoard(); // 게임판을 초기화  // ResetGameBoard를 ResetCopyGameBoard로 덮음
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
			Move(0, 1, 0); // 자동으로 하강
		}
					Sleep(200);
		GameoverCheck();


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
	system("mode con cols=80 lines=25"); // 가로 79, 세로 30으로 설정
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
	blockX = blockX + inputX; // 입력받은 만큼 x축 이동
	blockY = blockY + inputY; // 입력받은 만큼 y축 이동
	blockRotation = tempRotation;
}

// 현재 블럭
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

	// 다음 블럭 출력
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
				printf("■");
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
			if (copyBoard[y][x] != board[y][x]) // 카피보드와 보드가 일치하지 않으면 다시 그리기
			{
				board[y][x] = copyBoard[y][x]; // 카피 보드의 값을 넣어줌  
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
					printf("_ ");
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
				if (y == 2 && x != 0 && x != BORDER_WIDTH - 1 && copyBoard[y][x] == EMPTY)   //오버라인 위치의 셀이 비었다면
					copyBoard[y][x] = OVERLINE; 	//오버라인을 그리기
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

void ResetGameBoard() {
	for (int y = 0; y < BORDER_HEIGHT; y++) {
		for (int x = 0; x < BORDER_WIDTH; x++)
			copyBoard[y][x] = 1000;
	}
}

void ResetCopyGameBoard() // ResetGameBoard를 ResetCopyGameBoard로 덮음
{
	for (int y = 0; y < BORDER_HEIGHT; y++) // 빈 공간
		for (int x = 0; x < BORDER_WIDTH; x++)
			copyBoard[y][x] = EMPTY;  // board를 copyboard로 덮음

	for (int y = 0; y < BORDER_HEIGHT; y++)
	{
		for (int x = 0; x < BORDER_WIDTH; x++)
		{
			if (x == 0 || x == BORDER_WIDTH - 1) // 좌-우 벽 그리기
				copyBoard[y][x] = WALL; // board를 copyboard로 덮음

			if (y == BORDER_HEIGHT - 1) // 하단 벽 그리기
				copyBoard[y][x] = WALL; // board를 copyboard로 덮음

			if (y == 2 && x != 0 && x != BORDER_WIDTH - 1) // 게임 오버라인 그리기
				copyBoard[y][x] = OVERLINE; // board를 copyboard로 덮음
		}
	}
}

void FixBlock() {
	for (int y = 0; y < BORDER_HEIGHT; y++) {
		for (int x = 0; x < BORDER_WIDTH; x++) {
			if (copyBoard[y][x] == MBLOCK) { // board를 copyboard로 덮음
				copyBoard[y][x] = FBLOCK;	 // board를 copyboard로 덮음
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
	int k;  // 라인이 파괴된 Y위치를 저장
	int block_linecheck; // 10개가 전부 채워졌는지 체크하는 용도의 변수

	for (int y = BORDER_HEIGHT - 2; y > 2;)
	{
		block_linecheck = 0; // 다음 y줄에 올때마다 0으로 초기화

		for (int x = 1; x < BORDER_WIDTH - 1; x++) // (탐색) x 이동 >>
			if (copyBoard[y][x] == FBLOCK)  // 해당 위치에 fix된 블록이 있으면
				block_linecheck++; // 값 증가

		if (block_linecheck == BORDER_WIDTH - 2)
		{
			for (k = y; k > 1; k--) // k에 현재 y 값을 넘겨주고 k 가 1이되면 종료
				for (int l = 1; l < BORDER_WIDTH - 1; l++)
				{
					if (copyBoard[k - 1][l] != OVERLINE)
						copyBoard[k][l] = copyBoard[k - 1][l];

					if (copyBoard[k - 1][l] == OVERLINE)  // 한칸 위에 있느 블록이 오버라인일 경우 empty
						copyBoard[k][l] = EMPTY;
				}
		}
		else
			y--;  // 다음줄
	}
}

// 게임 영역 내 블록 모두 비우기
void PrintGameOver() {
	//for (int y = 0; y < BORDER_HEIGHT - 1; y++) 
	//{
	//	for (int x = 1; x < BORDER_WIDTH - 1; x++)
	//	{
	//		copyboard[y][x] = EMPTY;
	//	}
	//} // 블럭 다 지워줌
	PrintGameBoard(); // 블록이 비워진 화면 출력
	GotoXY(4, 12);
	printf("GameOver"); // 게임오버 텍스트 출력

	GotoXY(2, 14);
	printf("Press Any Button");


	Sleep(1000); //몇 초간 정지

	while (_kbhit()) { //Sleep 되어있는동안은 키 입력을 다 씹고
		_getch();
	}

	_getch(); // 그 이후에 키 입력이 들어오면 탈출
}

// 게임 오버 체크
void GameoverCheck()
{
	for (int x = 1; x < BORDER_WIDTH - 2; x++)
	{
		if (copyBoard[2][x] == FBLOCK) // Y가 2인 위치에 고정된 블록이 있으면
		{
			PrintGameOver(); // 게임 오버 화면 출력

			system("cls"); // 화면 전체 비우기

			ResetGameBoard(); // 초기화 게임보드
			ResetCopyGameBoard(); // 초기화 카피 게임보드
			
			PrintGameBoard(); // 게임보드 출력



			system("cls"); // 화면 전체 비우기
			
			for (int y = 0; y < BORDER_HEIGHT; y++) //종료화면 출력
			{
				if (y == 11)
					printf("■ 게  임  종  료 □\n");
				else if (y % 2 == 0)
					printf("□■□■□■□■□■\n");
				else
					printf("■□■□■□■□■□\n");
			}
			exit(0); // cmd 종료
		}
	}
}
