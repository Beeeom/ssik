#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define Block_kind 7  // 
#define Block_size 4  // 
//Block[Bolck_kind][Block_size][Block_size][Block_size];  // Block[7][4][4][4];

#define Board_Width 12
#define Board_Height 22
#define BoardX 10  // X 위치 - background
#define BoardY 0   // Y 위치 - background


#define Next_Board_Width 12    // Next_Board
#define Next_Board_Height 22  // Next_Board
#define Next_BoardX 45		  // Next_Board
#define Next_BoardY 2		  // Next_Board


//글자 색 변경
void textcolor(int colorNum) { 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}


void GotoXY(int x, int y) { //GotoXY  // cmd창에 x y 좌표 입력
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}


int board[Board_Height][Board_Width]; //board[높이][넓이] 배열

//메인 보드 틀 구성  // board[][] 의 값을 만드는 공간
void creatBoard() {
	for (int y = 0; y < Board_Height; y++) {     // #define Borad_Height 22
		board[y][0] = 1;
		board[y][Board_Width - 1 ] = 1;
		for (int x = 0; x < Board_Width; x++) {  // #define Borad_Width 12
			if (y == 0) {
				board[y][x] = 0;
			}
			board[Board_Height - 1][x] = 1;
			if (y > 0 && y < Board_Height - 1) {
				if (x > 0 && x < Board_Width - 1) {
					board[y][x] = 0;
				}
			}
		}
	}
}


//메인 보드 모양 출력
void printBoard() {
	for (int x = 1; x < Board_Width; x++) {				// 맨 위 경계선  // x < 12 = "_" 몇번 출력
		GotoXY(BoardX + x * 2, BoardY + 1);		// "_" x, y 좌표 위치   
		textcolor(14);
		printf("_");
	}

	for (int y = 0; y < Board_Height; y++) {	// 왼쪽 벽면 // y++ 이기 때문에 x는 고정 , y가 아래로 내려감
		GotoXY(BoardX, BoardY + y);				// BoardY + y(++)를 해서 아래로 출력  // x,y 좌표
		if (board[y][0] == 1) {					// board[Board_Height][Board_Width];
			textcolor(5);
			printf("■");
		}
		if (board[y][Board_Width - 1] == 1) {	// 오른쪽 벽면
			GotoXY(BoardX + Board_Width * 2 -2, BoardY + y);		// 오른쪽 벽 x,y 좌표
			textcolor(5);
			printf("■");
		}		
	}

	for (int x = 0; x < Board_Width; x++) { //맨 밑 벽
		GotoXY(BoardX + x * 2, BoardY + Board_Height - 1);  // x 칸의 좌표 x값 1씩 하나씩 출력 * 2  // 맨 밑 벽 x,y 표시
		if (board[Board_Height - 1][x] == 1) {
			textcolor(5);
			printf("■");
		}
	}
	printf("\n");
	textcolor(10); // 글자 색 변경 <- 이 창을 닫으려면..
}


// Next 블럭 표시칸 - 미완성(2) //
void print_Next_Board() {
		// 맨 위 경계선 next 출력
		GotoXY(Next_BoardX + 0 * 2, Next_BoardY );
		textcolor(14);
		printf("< N E X T >");

	for (int x = 1; x < Next_Board_Width; x++) {	// 맨 위 벽
		GotoXY(Next_BoardX + x * 2, Next_BoardY + 1);
		textcolor(4);
		printf("■");
	}	

	for (int y = 0; y < 7; y++) {					// 왼쪽 벽면  // y < Next_Board_Height
		GotoXY(Next_BoardX, Next_BoardY + y);
		if (board[y][0] == 1) {
			textcolor(4);
			printf("■");
		}

		if (board[y][Next_Board_Width - 1] == 1) {	// 오른쪽 벽면
			GotoXY(Next_BoardX + Next_Board_Width * 2 - 2 , Next_BoardY + y);
			textcolor(4);
			printf("■");
		}
	}

	for (int x = 0; x < Next_Board_Width; x++) {	//맨 밑 벽
		GotoXY(Next_BoardX + x * 2, Next_BoardY + 8 - 1);	// Next_Board_Height - 1
		if (board[Next_Board_Height - 1][x] == 1) {
			textcolor(4);
			printf("■");
		}
	}
	printf("\n");
	textcolor(10); // 글자 색 변경 <- 이 창을 닫으려면..
}



int main() {
	
	creatBoard();		// 메인보드 틀 불러오기
	print_Next_Board(); // Next_Board 출력

	printBoard();		// 메인보드 출력

	return 0;
}