#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <process.h>
#include <conio.h>


void legs(bool run, int currentY);
void stopLegs(int currentY);
void gotoxy(int x, int y);
void character(int currentY, bool jump);
void CursorView();
void console(void);
void DrawMap(void);
void DrawTree(int locationX);
void EraseTree(int locationX);
void eraseCharacter(int currentY);
void eraseLegs(int currentY,bool jump);


#define characterX 10
#define characterY 13
#define treeX	   86
#define treeY	   18



int main(void)
{
	CursorView();
	console();
	DrawMap();
	int currentCharacterY = characterY;
	int currentTreeX=treeX;
	bool run = true;
	bool jumping = false;
	bool jumpMax = false;
	while (1)
	{
	

		if (_kbhit())
		{
			char jump;
			jump = _getch();

			if (jump == ' ')
			{
				jumping = true;
			}
		}

		if (jumping)
		{
			
 			if (jumpMax)
			{
				currentCharacterY++;
				
			}
			else
			{
				if (currentCharacterY > characterY - 6)
				{
					currentCharacterY--;
				

				}

				if (currentCharacterY == characterY - 6)
				{
					jumpMax = true;
					
				}
			}

			if (currentCharacterY == characterY)
			{
				jumping = false;
				jumpMax = false;
			}
			eraseLegs(currentCharacterY,jumping);
			stopLegs(currentCharacterY);
		}
		else
		{
			if (run == true)
			{
				run = false;
			}
			else
			{
				run = true;
			}
			legs(run, currentCharacterY);
		}


		character(currentCharacterY,jumping);
		
  		DrawTree(currentTreeX);
		Sleep(120);
		currentTreeX -= 2;
		EraseTree(currentTreeX);
		if (currentTreeX == 0)
		{
			EraseTree(currentTreeX+2);
			currentTreeX = treeX;
		}
		eraseCharacter(currentCharacterY);

		
		
	
	}



	
	return 0;
}


void character(int currentY, bool jump)
{	

	gotoxy(characterX, currentY); 			printf("    ^-----^\n");
	gotoxy(characterX, currentY +3);		printf("   /       \\ \n");
	gotoxy(characterX, currentY +4);		printf("  /_/     \\_\\\n");

	if (jump == false)
	{

		gotoxy(characterX, currentY + 1);		printf("   /  -  - |\n");
		gotoxy(characterX, currentY + 2);		printf("   |    ^  /\n");
		gotoxy(characterX, currentY + 5);		printf("    |     |   \n");
	}
	if (jump)
	{
		gotoxy(characterX, currentY + 1);		printf("   /  o  o |\n");
		gotoxy(characterX, currentY + 2);		printf("   |    -  /\n");
	}


}

void legs(bool run, int currentY)
{

	if (run == true)
	{
		gotoxy(characterX, currentY + 6);		printf("    | |-| |\n");
		gotoxy(characterX, currentY + 7);		printf("        |_|\n");
		
		
	}
	else
	{
		gotoxy(characterX, currentY +6);	printf("    | |-| |\n");
		gotoxy(characterX, currentY + 7);	printf("    |_|    \n");
		run = true;
	}


}

void stopLegs(int currentY)
{

	gotoxy(characterX, currentY + 5);		printf(" ┌---     ---┐ \n");
	gotoxy(characterX, currentY + 6);		printf(" └-----------┘ \n");

}


void eraseLegs(int currentY,bool jump)
{
	if (jump)
	{
		gotoxy(characterX, currentY + 5);		printf("                \n");
	}
	gotoxy(characterX, currentY +6);		printf("                \n");
	gotoxy(characterX, currentY + 7);		printf("                \n");
}

void eraseCharacter(int currentY)
{
	int i = 0;
	while (i < 21)
	{
		gotoxy(characterX, i);	printf("                  \n");
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

}

void EraseTree(int locationX)
{
	gotoxy(locationX+1, treeY);			printf("       ");
	gotoxy(locationX+1, treeY + 1);		printf("       ");
	gotoxy(locationX+1, treeY + 2);		printf("       ");

}
	


