#include<stdio.h>
#include<Windows.h> //커서 제거 위해 선언
#include<conio.h> //입력을 위해 kbhit() 쓰려고 선언
#include<stdlib.h> //종료를 위해 exit() 쓰려고 선언



cursor_hide(); //커서 제거
start_screen(); //시작화면
start_input(); //키 입력 대기
end_screen(); //종료화면
gotoxy(); //화면 좌표 설정
game_start(); //게임시작
game_screen(); //게임화면
new_block(); //블럭 생성

pause_screen(); //일시정지화면
game_over(); //게임오버화면

int blocks[7][4][4][4] = {
{{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},
 {0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0}},
{{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0},
 {0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}},
{{0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0},
 {0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0}},
{{0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0},
 {0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0}},
{{0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0},{0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0},
 {0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0},{0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0}},
{{0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0},
 {0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0},{0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0}},
{{0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0},
 {0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0},{0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0}}
}; //블럭모양 저장



int main() {
	cursor_hide();
	start_screen();
	start_input();
	game_start();
}

cursor_hide() {
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.dwSize = 1;
	curInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

start_screen() {
	printf("\n\n\n\n\n"); //시작화면 출력
	printf(" * * *  T E T R I S  * * *\n\n");
	printf("  ◁ ▷ ▽  : 이동\n");
	printf("     △     : 회전\n");
	printf("     Z      : 역회전\n");
	printf("     C      : 블럭 저장 및 교체\n");
	printf("   Space    : 낙하\n");
	printf("     P      : 일시정지\n");
	printf("    ESC     : 게임 종료\n\n");
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
	for (int i = 0; i < 22; i++) //종료화면 출력
	{
		if (i == 10)
			printf("* 게임종료 *\n");
		else
			printf("************\n");
	}
	Sleep(1000); //1초간 대기
	exit(0); //프로그램 종료
}

gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

game_start() {
	int block_num = 0;
	game_screen();
	//while (1)
	//{
	//	if (block_num == 0)
	//		new_block();

	//}
}

game_screen() {
	system("cls");
	int x = 0, y = 0;
	for (int i = 3; i <= 23; i++)
	{
		gotoxy(x, y + i); printf("  ■                    ■");
		if (i == 4 || i == 9)
		{
			gotoxy(x, y + i); printf("  ■                    ■    ㅡㅡㅡㅡ");
		}
		else if (i > 4 && i < 9)
		{
			gotoxy(x, y + i); printf("  ■                    ■  |         |");
		}
		else if (i == 23)
		{
			gotoxy(x, y + i); printf("  ■■■■■■■■■■■");
		}
	}
	gotoxy(x, y + 24);
}

new_block() {
	int x = 0, y = 0;
	int block_type = rand() % 7;
	gotoxy(12, 3);
	for (int i = 0; i < 5; i++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (blocks[block_type][0][i][y] == "1");
		}
	}
	gotoxy(x, y + 24);
}

pause_screen() {

}
game_over() {

}
