#include<stdio.h>
#include<Windows.h> //커서 제거 위해 선언
#include<conio.h> //입력을 위해 kbhit() 쓰려고 선언
#include<stdlib.h> //종료를 위해 exit() 쓰려고 선언



cursor_hide(); //커서 제거
start_screen(); //시작화면
end_screen(); //종료화면
gotoxy(); //화면 좌표 설정
game_start(); //게임화면
pause_screen(); //일시정지화면*
game_over(); //게임오버화면*

int main() {
	cursor_hide();
	start_screen();
	game_start();
}

cursor_hide() {
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.dwSize = 1;
	curInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

start_screen() {
	char save_key;
	int time;

	printf("\n\n\n\n\n"); //시작화면 출력
	printf(" * * *  T E T R I S  * * *\n\n");
	printf("  ◁ ▷ ▽  : 이동\n");
	printf("     △     : 회전\n");
	printf("     Z      : 역회전\n");
	printf("     C      : 블록 저장 및 교체\n");
	printf("   Space    : 낙하\n");
	printf("     P      : 일시정지\n");
	printf("    ESC     : 게임 종료\n\n");

	for (time = 0;; time++) //대기
	{
		if (_kbhit()) //입력이 있으면 실행
		{
			save_key = _getch();
			if (save_key == 13) //Enter면 시작
			{
				system("cls"); //화면 초기화
				return 0;
			}
			if (save_key == 27) //Esc면 종료
			{
				system("cls");
				end_screen();
			}
		}
	}
}

end_screen() {
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
	int x = 0, y = 0, time = 0;
	for (int i = 1; i <= 21; i++)
	{
		gotoxy(x, y + i); printf("■                    ■");
		if (i == 2 || i == 7)
		{
			gotoxy(x, y + i); printf("■                    ■  ■■■■■■");
		}
		else if (i > 2 && i < 7)
		{
			gotoxy(x, y + i); printf("■                    ■  ■        ■");
		}
		else if (i == 21)
		{
			gotoxy(x, y + i); printf("■■■■■■■■■■■");
		}
	}
	gotoxy(x, y + 22);
}
