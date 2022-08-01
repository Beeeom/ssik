#include <stdio.h>
#include<windows.h>
#include<conio.h>
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
void GotoXY(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void CursorView(char show) {
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}
void GotoXY(int, int);
	
	while (1) {
		if (_kbhit()) {

			int nkey = _getch();
			if (nkey == SPACEBAR) {
				printf("space bar");
			}
				//int nkey = _getch();
			if (nkey == z) {
				printf("z");
				}
			if (nkey == c) {
				printf("c");
			}
			if(nkey ==p) {
			    printf("p");
			}
			if (nkey == Esc) {
				printf("Esc");
			}

			if (nkey == ARROW) {
				nkey = _getch();
				switch (nkey) {
				case UP:
					printf("up key");
					break;
				case LEFT:
					printf("left key");
					break;
				case RIGHT:
					printf("rigth key");
					break;
				case DOWN:
					printf("down key");
					break; 
				
				}
			}
		}
	}
int main(void) {
	return 0;
}
//int x = 30;
//int y = 7;
//int main(void) {
//CursorView(0);
//	GotoXY(x, y);
//	printf("け");
//	while (1) {
//		if (_kbhit()) {
//			int nkey = _getch();
//			switch (nkey) {
//			case UP:
//				system("cls");
//				GotoXY(x, --y);
//				printf("け");
//				break;
//			case LEFT:
//				system("cls");
//				GotoXY(x=x-2, y);
//				printf("け");
//				break;
//			case RIGHT:
//				system("cls");
//				GotoXY(x=x+2, y);
//				printf("け");
//				break;
//			case DOWN:
//				system("cls");
//				GotoXY(x, ++y);
//				printf("け");
//				break;
//			}
//		}
//	}
//}
