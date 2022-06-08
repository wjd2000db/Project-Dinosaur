#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <process.h>
#include <conio.h>


void legs(bool run, int currentY);
void gotoxy(int x, int y);
void character(int currentY);
void CursorView();
void console(void);
void DrawMap(void);
void DrawTree(int locationX);
void EraseTree(int locationX);
void eraseCharacter(int currentY);
void eraseLegs(int currentY);


#define characterX 10
#define characterY 12
#define treeX	   86
#define treeY	   17


int main(void)
{
	CursorView();
	console();
	DrawMap();
	int currentCharacterY = characterY;
	int currentTreeX=treeX;
	bool run = true;
	while (1)
	{
		eraseCharacter(currentCharacterY);
		character(currentCharacterY);
		DrawTree(currentTreeX);
		legs(run, currentCharacterY);
		if (run == true)
		{
			run = false;
		}
		else
		{
			run = true;
		}
		currentTreeX -= 2;
		EraseTree(currentTreeX);
		if (currentTreeX == 0)
		{
			EraseTree(currentTreeX+2);
			currentTreeX = treeX;
		}

    	if (_kbhit())
		{
			char jump;
			jump = _getch();
			if (jump == ' ')
			{
		
				while (currentCharacterY > characterY - 4)
				{
					eraseCharacter(currentCharacterY);
					character(currentCharacterY);
					legs(run,currentCharacterY);
					currentCharacterY--;
					
				}

				while (currentCharacterY < characterY)
				{
					eraseCharacter(currentCharacterY);
					character(currentCharacterY);
					legs(run, currentCharacterY);
					currentCharacterY++;

				}
				
			}

		}
		
	
	}



	
	return 0;
}


void character(int currentY)
{	

	gotoxy(characterX, currentY); 			printf("    ^ㅡㅡㅡ^\n");
	gotoxy(characterX, currentY +1);		printf("   /  -  - |\n");
	gotoxy(characterX, currentY +2);		printf("   |    ^  /\n");
	gotoxy(characterX, currentY +3);		printf("   /       ＼\n");
	gotoxy(characterX, currentY +4);		printf("  / /     ＼＼\n");
	gotoxy(characterX, currentY +5);		printf("  ㅡ|     | ㅡ\n");
	gotoxy(characterX, currentY +6);		printf("    |     |\n");


}

void legs(bool run, int currentY)
{

	if (run == true)
	{
		gotoxy(characterX, currentY + 7);		printf("    | |-| |\n");
		gotoxy(characterX, currentY + 8);		printf("        |_|\n");
		Sleep(130);
		
	}
	else
	{
		gotoxy(characterX, currentY + 7);	printf("    | |-| |\n");
		gotoxy(characterX, currentY + 8);	printf("    |_|    \n");
		Sleep(130);
		run = true;
	}


}

void eraseLegs(int currentY)
{
	gotoxy(characterX, currentY +7);		printf("        \n");
	gotoxy(characterX, currentY + 8);		printf("        \n");
}

void eraseCharacter(int currentY)
{
	int i = 0;
	while (i < 21)
	{
		gotoxy(characterX, i);	printf("              \n");
		i++;
	}
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

}

void DrawTree(int locationX)
{
	gotoxy(locationX, treeY);			printf("*** \n");
	gotoxy(locationX, treeY+1);			printf("*|* \n");
	gotoxy(locationX, treeY + 2);		printf(" |  \n");
	gotoxy(locationX, treeY + 3);		printf(" |  \n");

}

void EraseTree(int locationX)
{
	gotoxy(locationX, treeY);			printf("       ");
	gotoxy(locationX, treeY + 1);		printf("       ");
	gotoxy(locationX, treeY + 2);		printf("       ");
	gotoxy(locationX, treeY + 3);		printf("       ");
}
	


