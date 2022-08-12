#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>


#define SIZE_X 12
#define SIZE_Y 24

int board[SIZE_Y][SIZE_X]; //board[높이][넓이] 배열

#define block_X 4
#define block_Y 0

int block_rotation; // 현재 블록 회전 값
int block_type;     // 현재블록의 타입 값

// EMPTY 빈 공간 / MOVE_BLOCK 움직이는 블럭 / OVERLINE 게임 오버라인 / SBLOCK 그림자 블럭 / WALL 벽 / FIX_BLOCK 고정블럭
enum { EMPTY = 0, MOVE_BLOCK = 1, OVERLINE = 2, SBLOCK = 3, WALL = 4, FIX_BLOCK = 5 };

//블럭 모양
int blocks[7][4][4][4] = {
    // J미노(0번 블록)
    {
        0,0,0,0,// 0번 방향
        0,1,0,0,
        0,1,1,1,
        0,0,0,0,

        0,0,0,0,// 1번 방향
        0,0,1,1,
        0,0,1,0,
        0,0,1,0,

        0,0,0,0,// 2번 방향
        0,0,0,0,
        0,1,1,1,
        0,0,0,1,

        0,0,0,0,// 3번 방향
        0,0,1,0,
        0,0,1,0,
        0,1,1,0
    },
    // L미노(1번 블록)
    {
        0,0,0,0,// 0번 방향
        0,0,0,1,
        0,1,1,1,
        0,0,0,0,

        0,0,0,0,// 1번 방향
        0,0,1,0,
        0,0,1,0,
        0,0,1,1,

        0,0,0,0,// 2번 방향
        0,0,0,0,
        0,1,1,1,
        0,1,0,0,

        0,0,0,0,// 3번 방향
        0,1,1,0,
        0,0,1,0,
        0,0,1,0
    },
    // O미노(2번 블록)
    {
        0,0,0,0,// 0번 방향
        0,1,1,0,
        0,1,1,0,
        0,0,0,0,

        0,0,0,0,// 1번 방향
        0,1,1,0,
        0,1,1,0,
        0,0,0,0,

        0,0,0,0,// 2번 방향
        0,1,1,0,
        0,1,1,0,
        0,0,0,0,

        0,0,0,0,// 3번 방향
        0,1,1,0,
        0,1,1,0,
        0,0,0,0
    },
    // T미노(3번 블록)
    {
        0,0,0,0,// 0번 방향
        0,0,1,0,
        0,1,1,1,
        0,0,0,0,

        0,0,0,0,// 1번 방향
        0,0,1,0,
        0,0,1,1,
        0,0,1,0,

        0,0,0,0,// 2번 방향
        0,0,0,0,
        0,1,1,1,
        0,0,1,0,

        0,0,0,0,// 3번 방향
        0,0,1,0,
        0,1,1,0,
        0,0,1,0
    },
    // I미노(4번 블록)
    {
        0,0,0,0,// 0번 방향
        0,0,0,0,
        1,1,1,1,
        0,0,0,0,

        0,0,1,0,// 1번 방향
        0,0,1,0,
        0,0,1,0,
        0,0,1,0,

        0,0,0,0,// 2번 방향
        1,1,1,1,
        0,0,0,0,
        0,0,0,0,

        0,1,0,0,// 3번 방향
        0,1,0,0,
        0,1,0,0,
        0,1,0,0
    },
    // Z미노(5번 블록)
    {
        0,0,0,0,// 0번 방향
        0,1,1,0,
        0,0,1,1,
        0,0,0,0,

        0,0,0,1,// 1번 방향
        0,0,1,1,
        0,0,1,0,
        0,0,0,0,

        0,1,1,0,// 2번 방향
        0,0,1,1,
        0,0,0,0,
        0,0,0,0,

        0,0,1,0,// 3번 방향
        0,1,1,0,
        0,1,0,0,
        0,0,0,0
    },
    // S미노(6번 블록)
    {
        0,0,0,0,// 0번 방향
        0,0,1,1,
        0,1,1,0,
        0,0,0,0,

        0,0,1,0,// 1번 방향
        0,0,1,1,
        0,0,0,1,
        0,0,0,0,

        0,0,1,1,// 2번 방향
        0,1,1,0,
        0,0,0,0,
        0,0,0,0,

        0,1,0,0,// 3번 방향
        0,1,1,0,
        0,0,1,0,
        0,0,0,0
    }
};

//콘솔창 세팅 1,2,3
void RemoveCurser() // 커서를 표시 X
{
    CONSOLE_CURSOR_INFO curinfo = { 0, };
    curinfo.dwSize = 1;
    curinfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
}
void ConsoleSize()// 콘솔창의 크기를 조절합니다.
{
    system("mode con cols=130 lines=35"); // 가로 130, 세로 35으로 설정
}
void RemoveScrollbar() // 콘솔창의 스크롤바를 삭제
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
// 콘솔창 세팅 (1,2,3)
void SetConsole() 
{
    ConsoleSize(); // 콘솔창의 크기 조절
    RemoveScrollbar(); // 콘솔창의 스크롤바 삭제
    RemoveCurser(); // 커서를 표시 X
}


//글자 색 변경
void textcolor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}


//GotoXY  // cmd창에 x y 좌표 입력
void GotoXY(int x, int y) { 
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


//보드 틀 설정
void start_Board() {
	for (int y = 0; y < SIZE_Y; y++) {  // 빈 공간
		for (int x = 0; x < SIZE_X; x++) {
			board[y][x] = EMPTY;	//board y x 에  empty값 대입
		}
	}
	for (int y = 0; y < SIZE_Y; y++) {

		for (int x = 0; x < SIZE_X; x++) {
			if (x == 0 || x == SIZE_X - 1) {	// 좌 - 우 벽 
				board[y][x] = WALL;
			}

			if (y == SIZE_Y -1) {				// 하단 바닥 벽
				board[y][x] = WALL;
			}

			if (y == 2 && x != 0 && x != SIZE_X - 1) {	//게임 오버라인 그리기
				board[y][x] = OVERLINE;
			}
		}
	}
}


// 메인 보드 = PrintGameBoard(); //게임판을 출력
void print_Board() {
    for (int y = 0; y < SIZE_Y; y++)
    {
        for (int x = 0; x < SIZE_X; x++)
        {
            switch (board[y][x])
            {
            case EMPTY: // 해당칸이 빈공간이면
                GotoXY(x, y);
                printf("  "); // 스페이바 두번
                break;

            case MOVE_BLOCK: // 해당칸이 움직이는 블록이면
                GotoXY(x, y);
                printf("■");
                break;

            case OVERLINE: // 해당칸이 게임 오버라인이면
                GotoXY(x, y);
                printf("_");
                break;

            case WALL: // 해당칸이 벽이면
                GotoXY(x, y);
                //textcolor(14);
                printf("▩");
                break;

            case FIX_BLOCK: // 해당칸이 고정된 블록이면
                GotoXY(x, y);
                printf("■");
                break;
            }
        }
    }
}


//넥스트 보드
void print_Next_Board() {
    GotoXY(30, 4);
    textcolor(14);
    printf("< N E X T >");

    for (int x = 0; x < SIZE_X - 3; x++) { //위쪽 벽
        GotoXY(30+x, 5);
        printf("■");
    }

    for (int y = 0; y < SIZE_Y - 18; y++) {
        GotoXY(30, y+6);
        printf("■");
    }

    for (int y = 0; y < SIZE_Y - 18; y++) {
        GotoXY(38, y + 6);
        printf("■");
    }

    for (int x = 0; x < SIZE_X - 3; x++) { //위쪽 벽
        GotoXY(30 + x, 11);
        printf("■");
    }
}


void NewBlockMaker() // 새로운 블록을 맵에 생성
{
    block_rotation = 0;      // 블록 회전
    block_type = rand() % 7; // 블록 타입 1~7 랜덤 출력

    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if (blocks[block_type][block_rotation][y][x] == 1) // 블록배열과 비교해서 값을 넣어줌
                board[block_Y + y][block_X + x] = MOVE_BLOCK;
        }
    }
}

void BlockMove(int inputX, int inputY) // 블록을 이동 및 회전시킵니다.
{
    block_X + inputX; //입력받은 값 만큼 X값 이동
    block_Y + inputY; //입력받은 값 만큼 Y값 이동

    for (int y = 0; y < 4; y++) // 원래 있던 값 지우기
    {
        for (int x = 0; x < 4; x++)
        {
            if (blocks[block_type][block_rotation][y][x] == 1)
                board[block_Y + y][block_X + x] = EMPTY;
        }
    }

    for (int y = 0; y < 4; y++) // 다시 값 넣기
    {
        for (int x = 0; x < 4; x++)
        {
            if (blocks[block_type][block_rotation][y][x] == 1)
                board[block_Y + y + inputY][block_X + x + inputX] = MOVE_BLOCK;
        }
    }
}





int main() {
    srand((unsigned)time(NULL));
    SetConsole(); //콘솔창 세팅

    //while (1) { }
    start_Board();      // 보드 초기화
    print_Next_Board(); // 넥스트 보드(우측블럭)

    NewBlockMaker();    // <-- 블록 추가

    print_Board();      // 메인 보드(좌측블럭)
    

	return 0;
}