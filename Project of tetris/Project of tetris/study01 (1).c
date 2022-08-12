#include<stdio.h>
#include<Windows.h> //Ŀ�� ���� ���� ����
#include<conio.h> //�Է��� ���� kbhit() ������ ����
#include<stdlib.h> //���Ḧ ���� exit() ������ ����



cursor_hide(); //Ŀ�� ����
start_screen(); //����ȭ��
start_input(); //Ű �Է� ���
end_screen(); //����ȭ��
gotoxy(); //ȭ�� ��ǥ ����
game_start(); //���ӽ���
game_screen(); //����ȭ��
new_block(); //�� ����

pause_screen(); //�Ͻ�����ȭ��
game_over(); //���ӿ���ȭ��

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
}; //����� ����



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
	printf("\n\n\n\n\n"); //����ȭ�� ���
	printf(" * * *  T E T R I S  * * *\n\n");
	printf("  �� �� ��  : �̵�\n");
	printf("     ��     : ȸ��\n");
	printf("     Z      : ��ȸ��\n");
	printf("     C      : �� ���� �� ��ü\n");
	printf("   Space    : ����\n");
	printf("     P      : �Ͻ�����\n");
	printf("    ESC     : ���� ����\n\n");
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
	for (int i = 0; i < 22; i++) //����ȭ�� ���
	{
		if (i == 10)
			printf("* �������� *\n");
		else
			printf("************\n");
	}
	Sleep(1000); //1�ʰ� ���
	exit(0); //���α׷� ����
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
		gotoxy(x, y + i); printf("  ��                    ��");
		if (i == 4 || i == 9)
		{
			gotoxy(x, y + i); printf("  ��                    ��    �ѤѤѤ�");
		}
		else if (i > 4 && i < 9)
		{
			gotoxy(x, y + i); printf("  ��                    ��  |         |");
		}
		else if (i == 23)
		{
			gotoxy(x, y + i); printf("  ������������");
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
