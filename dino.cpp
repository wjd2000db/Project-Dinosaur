#include <stdio.h>
#include <Windows.h>
#include <time.h>


void legs(void);
void gotoxy(int x, int y);
void character(void);
void CursorView();
void console(void);
void DrawMap(void);
void DrawTree();

#define characterX 10
#define characterY 12

int main(void)
{
	console();
	DrawMap();
	character();
	
	return 0;
}

void character(void)
{	
	gotoxy(characterX, characterY); 		printf("    ^ㅡㅡㅡ^\n");
	gotoxy(characterX, characterY+1);		printf("   /  -  - |");
	gotoxy(characterX, characterY+2);		printf("   |    ^  /");
	gotoxy(characterX, characterY+3);		printf("   /       ＼");
	gotoxy(characterX, characterY+4);		printf("  / /     ＼＼");
	gotoxy(characterX, characterY+5);		printf("  ㅡ|     | ㅡ");
	gotoxy(characterX, characterY+6);		printf("    |     |");

	legs();

}

void legs(void)
{

	bool run = true;
	while (1)
	{
		CursorView();
		if (run == true)
		{
			gotoxy(characterX, characterY + 7);		printf("    | |-| |");
			gotoxy(characterX, characterY + 8);		printf("        |_|");
			Sleep(130);
			run = false;
		}
		else
		{
			gotoxy(characterX, characterY + 7); printf("    | |-| |");
			gotoxy(characterX, characterY + 8);	printf("    |_|    ");
			Sleep(130);
			run = true;
		}


	}


}

void eraseLegs(void)
{
	gotoxy(characterX, characterY+7);		printf("        \n");
	gotoxy(characterX, characterY + 8);		printf("        \n");
}

void gotoxy(int x, int y) 
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int time()
{
	for (;;) 
	{
		clock_t time = clock();
		double timeSecond = (double)(time / CLOCKS_PER_SEC);
	}
}

void CursorView(void)
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void console(void)
{
	system("mode con:cols=90 lines=25");
	SetConsoleTitle(TEXT("Run Run!"));
}

void DrawMap()
{
	gotoxy(0, 21);		printf("==========================================================================================\n");
	DrawTree();
}

void DrawTree()
{
	gotoxy(86, 17);		printf("***\n");
	gotoxy(86, 18);		printf("*|* \n");
	gotoxy(86, 19);		printf(" | \n");
	gotoxy(86, 20);		printf(" | \n");
}