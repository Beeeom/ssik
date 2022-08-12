#include<stdio.h>
#include<Windows.h> //Ŀ�� ���� ���� ����
#include<conio.h> //�Է��� ���� kbhit() ������ ����
#include<stdlib.h> //���Ḧ ���� exit() ������ ����



cursor_hide(); //Ŀ�� ����
start_screen(); //����ȭ��
end_screen(); //����ȭ��
gotoxy(); //ȭ�� ��ǥ ����
game_start(); //����ȭ��
pause_screen(); //�Ͻ�����ȭ��*
game_over(); //���ӿ���ȭ��*

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

	printf("\n\n\n\n\n"); //����ȭ�� ���
	printf(" * * *  T E T R I S  * * *\n\n");
	printf("  �� �� ��  : �̵�\n");
	printf("     ��     : ȸ��\n");
	printf("     Z      : ��ȸ��\n");
	printf("     C      : ��� ���� �� ��ü\n");
	printf("   Space    : ����\n");
	printf("     P      : �Ͻ�����\n");
	printf("    ESC     : ���� ����\n\n");

	for (time = 0;; time++) //���
	{
		if (_kbhit()) //�Է��� ������ ����
		{
			save_key = _getch();
			if (save_key == 13) //Enter�� ����
			{
				system("cls"); //ȭ�� �ʱ�ȭ
				return 0;
			}
			if (save_key == 27) //Esc�� ����
			{
				system("cls");
				end_screen();
			}
		}
	}
}

end_screen() {
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
	int x = 0, y = 0, time = 0;
	for (int i = 1; i <= 21; i++)
	{
		gotoxy(x, y + i); printf("��                    ��");
		if (i == 2 || i == 7)
		{
			gotoxy(x, y + i); printf("��                    ��  �������");
		}
		else if (i > 2 && i < 7)
		{
			gotoxy(x, y + i); printf("��                    ��  ��        ��");
		}
		else if (i == 21)
		{
			gotoxy(x, y + i); printf("������������");
		}
	}
	gotoxy(x, y + 22);
}
