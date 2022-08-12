#include<stdio.h>
#include<Windows.h> //Ŀ�� ���� ���� ����
#include<conio.h> //�Է��� ���� kbhit() ������ ����
#include<stdlib.h> //���Ḧ ���� exit() ������ ����

#define size_x 14
#define size_y 24
#define start_x 2
#define start_y 2
#define end_x 21



cursor_hide(); //Ŀ�� ����
ConsoleSize(); // �ܼ�â ũ�� ����
gotoxy(); //ȭ�� ��ǥ ����
start_screen(); //����ȭ��
start_input(); //Ű �Է� ���
end_screen(); //����ȭ��
game_screen(); //�⺻ ����ȭ��
screen_draw(); //ȭ�� ����

pause_screen(); //�Ͻ�����ȭ��
game_over(); //���ӿ���ȭ��

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
	printf("\n\n\n\n\n"); //����ȭ�� ���
	printf("           * * *  T E T R I S  * * *\n\n");
	printf("            �� �� ��  : �̵�\n");
	printf("               ��     : ȸ��\n");
	printf("               Z      : ��ȸ��\n");
	printf("               C      : �� ���� �� ��ü\n");
	printf("             Space    : ����\n");
	printf("               P      : �Ͻ�����\n");
	printf("              ESC     : ���� ����\n\n");
}

start_input() {
	char save_key;
	while (1)
	{
		if (_kbhit()) //�Է��� ������ ����
		{
			save_key = _getch();
			if (save_key == 13) //Enter�� ����
				return 0;
			if (save_key == 27) //Esc�� ����
				end_screen();
		}
	}
}

end_screen() {
	system("cls"); //ȭ�� �ʱ�ȭ
	for (int y = 0; y < size_y; y++) //����ȭ�� ���
	{
		if (y == 11)
			printf("�� ��  ��  ��  �� ��\n");
		else if (y % 2 == 0)
			printf("�����������\n");
		else
			printf("�����������\n");
	}
	Sleep(1000); //1�ʰ� ���
	exit(0); //���α׷� ����
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
