#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>


#define SIZE_X 12
#define SIZE_Y 24

int board[SIZE_Y][SIZE_X]; //board[����][����] �迭

#define block_X 4
#define block_Y 0

int block_rotation; // ���� ��� ȸ�� ��
int block_type;     // �������� Ÿ�� ��

// EMPTY �� ���� / MOVE_BLOCK �����̴� �� / OVERLINE ���� �������� / SBLOCK �׸��� �� / WALL �� / FIX_BLOCK ������
enum { EMPTY = 0, MOVE_BLOCK = 1, OVERLINE = 2, SBLOCK = 3, WALL = 4, FIX_BLOCK = 5 };

//�� ���
int blocks[7][4][4][4] = {
    // J�̳�(0�� ���)
    {
        0,0,0,0,// 0�� ����
        0,1,0,0,
        0,1,1,1,
        0,0,0,0,

        0,0,0,0,// 1�� ����
        0,0,1,1,
        0,0,1,0,
        0,0,1,0,

        0,0,0,0,// 2�� ����
        0,0,0,0,
        0,1,1,1,
        0,0,0,1,

        0,0,0,0,// 3�� ����
        0,0,1,0,
        0,0,1,0,
        0,1,1,0
    },
    // L�̳�(1�� ���)
    {
        0,0,0,0,// 0�� ����
        0,0,0,1,
        0,1,1,1,
        0,0,0,0,

        0,0,0,0,// 1�� ����
        0,0,1,0,
        0,0,1,0,
        0,0,1,1,

        0,0,0,0,// 2�� ����
        0,0,0,0,
        0,1,1,1,
        0,1,0,0,

        0,0,0,0,// 3�� ����
        0,1,1,0,
        0,0,1,0,
        0,0,1,0
    },
    // O�̳�(2�� ���)
    {
        0,0,0,0,// 0�� ����
        0,1,1,0,
        0,1,1,0,
        0,0,0,0,

        0,0,0,0,// 1�� ����
        0,1,1,0,
        0,1,1,0,
        0,0,0,0,

        0,0,0,0,// 2�� ����
        0,1,1,0,
        0,1,1,0,
        0,0,0,0,

        0,0,0,0,// 3�� ����
        0,1,1,0,
        0,1,1,0,
        0,0,0,0
    },
    // T�̳�(3�� ���)
    {
        0,0,0,0,// 0�� ����
        0,0,1,0,
        0,1,1,1,
        0,0,0,0,

        0,0,0,0,// 1�� ����
        0,0,1,0,
        0,0,1,1,
        0,0,1,0,

        0,0,0,0,// 2�� ����
        0,0,0,0,
        0,1,1,1,
        0,0,1,0,

        0,0,0,0,// 3�� ����
        0,0,1,0,
        0,1,1,0,
        0,0,1,0
    },
    // I�̳�(4�� ���)
    {
        0,0,0,0,// 0�� ����
        0,0,0,0,
        1,1,1,1,
        0,0,0,0,

        0,0,1,0,// 1�� ����
        0,0,1,0,
        0,0,1,0,
        0,0,1,0,

        0,0,0,0,// 2�� ����
        1,1,1,1,
        0,0,0,0,
        0,0,0,0,

        0,1,0,0,// 3�� ����
        0,1,0,0,
        0,1,0,0,
        0,1,0,0
    },
    // Z�̳�(5�� ���)
    {
        0,0,0,0,// 0�� ����
        0,1,1,0,
        0,0,1,1,
        0,0,0,0,

        0,0,0,1,// 1�� ����
        0,0,1,1,
        0,0,1,0,
        0,0,0,0,

        0,1,1,0,// 2�� ����
        0,0,1,1,
        0,0,0,0,
        0,0,0,0,

        0,0,1,0,// 3�� ����
        0,1,1,0,
        0,1,0,0,
        0,0,0,0
    },
    // S�̳�(6�� ���)
    {
        0,0,0,0,// 0�� ����
        0,0,1,1,
        0,1,1,0,
        0,0,0,0,

        0,0,1,0,// 1�� ����
        0,0,1,1,
        0,0,0,1,
        0,0,0,0,

        0,0,1,1,// 2�� ����
        0,1,1,0,
        0,0,0,0,
        0,0,0,0,

        0,1,0,0,// 3�� ����
        0,1,1,0,
        0,0,1,0,
        0,0,0,0
    }
};

//�ܼ�â ���� 1,2,3
void RemoveCurser() // Ŀ���� ǥ�� X
{
    CONSOLE_CURSOR_INFO curinfo = { 0, };
    curinfo.dwSize = 1;
    curinfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
}
void ConsoleSize()// �ܼ�â�� ũ�⸦ �����մϴ�.
{
    system("mode con cols=130 lines=35"); // ���� 130, ���� 35���� ����
}
void RemoveScrollbar() // �ܼ�â�� ��ũ�ѹٸ� ����
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
// �ܼ�â ���� (1,2,3)
void SetConsole() 
{
    ConsoleSize(); // �ܼ�â�� ũ�� ����
    RemoveScrollbar(); // �ܼ�â�� ��ũ�ѹ� ����
    RemoveCurser(); // Ŀ���� ǥ�� X
}


//���� �� ����
void textcolor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}


//GotoXY  // cmdâ�� x y ��ǥ �Է�
void GotoXY(int x, int y) { 
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


//���� Ʋ ����
void start_Board() {
	for (int y = 0; y < SIZE_Y; y++) {  // �� ����
		for (int x = 0; x < SIZE_X; x++) {
			board[y][x] = EMPTY;	//board y x ��  empty�� ����
		}
	}
	for (int y = 0; y < SIZE_Y; y++) {

		for (int x = 0; x < SIZE_X; x++) {
			if (x == 0 || x == SIZE_X - 1) {	// �� - �� �� 
				board[y][x] = WALL;
			}

			if (y == SIZE_Y -1) {				// �ϴ� �ٴ� ��
				board[y][x] = WALL;
			}

			if (y == 2 && x != 0 && x != SIZE_X - 1) {	//���� �������� �׸���
				board[y][x] = OVERLINE;
			}
		}
	}
}


// ���� ���� = PrintGameBoard(); //�������� ���
void print_Board() {
    for (int y = 0; y < SIZE_Y; y++)
    {
        for (int x = 0; x < SIZE_X; x++)
        {
            switch (board[y][x])
            {
            case EMPTY: // �ش�ĭ�� ������̸�
                GotoXY(x, y);
                printf("  "); // �����̹� �ι�
                break;

            case MOVE_BLOCK: // �ش�ĭ�� �����̴� ����̸�
                GotoXY(x, y);
                printf("��");
                break;

            case OVERLINE: // �ش�ĭ�� ���� ���������̸�
                GotoXY(x, y);
                printf("_");
                break;

            case WALL: // �ش�ĭ�� ���̸�
                GotoXY(x, y);
                //textcolor(14);
                printf("��");
                break;

            case FIX_BLOCK: // �ش�ĭ�� ������ ����̸�
                GotoXY(x, y);
                printf("��");
                break;
            }
        }
    }
}


//�ؽ�Ʈ ����
void print_Next_Board() {
    GotoXY(30, 4);
    textcolor(14);
    printf("< N E X T >");

    for (int x = 0; x < SIZE_X - 3; x++) { //���� ��
        GotoXY(30+x, 5);
        printf("��");
    }

    for (int y = 0; y < SIZE_Y - 18; y++) {
        GotoXY(30, y+6);
        printf("��");
    }

    for (int y = 0; y < SIZE_Y - 18; y++) {
        GotoXY(38, y + 6);
        printf("��");
    }

    for (int x = 0; x < SIZE_X - 3; x++) { //���� ��
        GotoXY(30 + x, 11);
        printf("��");
    }
}


void NewBlockMaker() // ���ο� ����� �ʿ� ����
{
    block_rotation = 0;      // ��� ȸ��
    block_type = rand() % 7; // ��� Ÿ�� 1~7 ���� ���

    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if (blocks[block_type][block_rotation][y][x] == 1) // ��Ϲ迭�� ���ؼ� ���� �־���
                board[block_Y + y][block_X + x] = MOVE_BLOCK;
        }
    }
}

void BlockMove(int inputX, int inputY) // ����� �̵� �� ȸ����ŵ�ϴ�.
{
    block_X + inputX; //�Է¹��� �� ��ŭ X�� �̵�
    block_Y + inputY; //�Է¹��� �� ��ŭ Y�� �̵�

    for (int y = 0; y < 4; y++) // ���� �ִ� �� �����
    {
        for (int x = 0; x < 4; x++)
        {
            if (blocks[block_type][block_rotation][y][x] == 1)
                board[block_Y + y][block_X + x] = EMPTY;
        }
    }

    for (int y = 0; y < 4; y++) // �ٽ� �� �ֱ�
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
    SetConsole(); //�ܼ�â ����

    //while (1) { }
    start_Board();      // ���� �ʱ�ȭ
    print_Next_Board(); // �ؽ�Ʈ ����(������)

    NewBlockMaker();    // <-- ��� �߰�

    print_Board();      // ���� ����(������)
    

	return 0;
}