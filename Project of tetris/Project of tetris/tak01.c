#include<stdio.h>
#include<Windows.h> //커서 제거 위해 선언
#include<conio.h> //입력을 위해 kbhit() 쓰려고 선언
#include<stdlib.h> //종료를 위해 exit() 쓰려고 선언

#define size_x 14
#define size_y 24
#define start_x 2
#define start_y 2
#define end_x 21



cursor_hide(); //커서 제거
ConsoleSize(); // 콘솔창 크기 조절
gotoxy(); //화면 좌표 설정
start_screen(); //시작화면
start_input(); //키 입력 대기
end_screen(); //종료화면
game_screen(); //기본 게임화면
screen_draw(); //화면 생성

pause_screen(); //일시정지화면
game_over(); //게임오버화면

int board[size_y][size_x + 10];
enum { empty = 0, m_block = 1, o_line = 2, s_block = 3, wall = 4, fblock = 5 };




int main() {
	cursor_hide();
	ConsoleSize();
	start_screen();
	start_input();
	game_screen();
}

cursor_hide() {
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.dwSize = 1;
	curInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

ConsoleSize() {
	system("mode con cols=50 lines=30");
}

gotoxy(int x, int y) {
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

start_screen() {
	printf("\n\n\n\n\n"); //시작화면 출력
	printf("           * * *  T E T R I S  * * *\n\n");
	printf("            ◁ ▷ ▽  : 이동\n");
	printf("               △     : 회전\n");
	printf("               Z      : 역회전\n");
	printf("               C      : 블럭 저장 및 교체\n");
	printf("             Space    : 낙하\n");
	printf("               P      : 일시정지\n");
	printf("              ESC     : 게임 종료\n\n");
}

start_input() {
	char save_key;
	while (1)
	{
		if (_kbhit()) //입력이 있으면 실행
		{
			save_key = _getch();
			if (save_key == 13) //Enter면 시작
				return 0;
			if (save_key == 27) //Esc면 종료
				end_screen();
		}
	}
}

end_screen() {
	system("cls"); //화면 초기화
	for (int y = 0; y < size_y; y++) //종료화면 출력
	{
		if (y == 11)
			printf("■ 게  임  종  료 □\n");
		else if (y % 2 == 0)
			printf("□■□■□■□■□■\n");
		else
			printf("■□■□■□■□■□\n");
	}
	Sleep(1000); //1초간 대기
	exit(0); //프로그램 종료
}

game_screen() {
	system("cls");
	for (int y = start_y; y < size_y; y++)
		for (int x = start_x; x < end_x; x++)
			board[y][x] = empty;

	for (int y = start_y; y < size_y; y++)
		for (int x = start_x; x < end_x; x++)
		{
			if (y == start_y && x < size_x - 1)
				board[y][x] = o_line;
			if (y == size_y - 1 && x < size_x - 1)
				board[y][x] = wall;
			if (x == start_x)
				board[y][x] = wall;
			if (x == size_x - 1)
				board[y][x] = wall;

			if ((y == start_y + 2 || y == start_y + 8) && (x > end_x - 6 && x < end_x - 1))
				board[y][x] = wall;
			if ((x == end_x - 6 || x == end_x) && (y > start_y + 2 && y < start_y + 8))
				board[y][x] = wall;
		}
}

pause_screen() {

}
game_over() {

}
