#include <stdio.h>
#include <Windows.h>


void legs(void);
void gotoxy(int x, int y);
void character(void);

int main(void)
{
	
	character();
	legs();
	return 0;
}

void character(void)
{	

	gotoxy(10, 12); 	printf("    ^ㅡㅡㅡ^ \n");
	gotoxy(10, 13);		printf("   /  -  - |\n");
	gotoxy(10, 14);		printf("   |    ^  /\n");
	gotoxy(10, 15);		printf("   /       ＼\n ");
	gotoxy(10, 16);		printf("  / /     ＼＼\n");
	gotoxy(10, 17);		printf("  ㅡ|     | ㅡ\n");
	gotoxy(10, 18);		printf("    |     |\n");


}

void legs(void)
{
	printf("    | |-| |\n");
	printf("    |_| |_|  \n");
}

void gotoxy(int x, int y) {
	//x, y 좌표 설정
	COORD pos = { x,y };
	//커서 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}