// ConsoleApplication26.cpp: определяет точку входа для консольного приложения.
#include <stdafx.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

HANDLE hConsole;
HANDLE hStdout, hStdin;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void GotoXY(int X, int Y)
{
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}

enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};
void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
char s1[256];
char *Rus(char *s2)
{
	AnsiToOem(s2, s1); return s1;
}



int sheeps(int pole[10][10])
{
	int i, j, f, k, r;
	int rand_chislo, rand_chislo1, ts, s;

	/*  char kr=219;
	char a=218,b=196,c=191,
	d=179,
	e=192, g=217;   */
	srand(time(NULL));

	for (i = 0; i<10; i++)
		for (j = 0; j<10; j++)
			pole[i][j] = 0;
	

		f = 0;
		rand_chislo = 3 + rand() % 3;
		rand_chislo1 = 3 + rand() % 3;

		ts = 1 + rand() % 4;

		
	switch (ts) {
	case 1: pole[rand_chislo][rand_chislo1] = 1; pole[rand_chislo - 1][rand_chislo1] = 1;
		pole[rand_chislo - 2][rand_chislo1] = 1; pole[rand_chislo - 3][rand_chislo1] = 1; break;
	case 2: pole[rand_chislo][rand_chislo1] = 1; pole[rand_chislo + 1][rand_chislo1] = 1;
		pole[rand_chislo + 2][rand_chislo1] = 1; pole[rand_chislo + 3][rand_chislo1] = 1; break;
	case 3: pole[rand_chislo][rand_chislo1] = 1; pole[rand_chislo][rand_chislo1 - 1] = 1;
		pole[rand_chislo][rand_chislo1 - 2] = 1; pole[rand_chislo][rand_chislo1 - 3] = 1; break;
	case 4: pole[rand_chislo][rand_chislo1] = 1; pole[rand_chislo][rand_chislo1 + 1] = 1;
		pole[rand_chislo][rand_chislo1 + 2] = 1; pole[rand_chislo][rand_chislo1 + 3] = 1; break;
	}






	for (k = 0; k<3; k++)
	{
		do {
			f = 0;
			rand_chislo = 2 + rand() % 4;
			rand_chislo1 = 2 + rand() % 4;

			ts = 1 + rand() % 4;

			if (ts == 1)
			{
				if (rand_chislo != 0) 
				{
					for (i = rand_chislo - 2; i<rand_chislo + 2; i++)
						for (j = rand_chislo1 - 1; j <= rand_chislo1 + 1; j++)	
							if (pole[i][j] != 0)
					    	      f = 1;					    
				}
				else f = 1;
			}
			if (ts == 2) 
			{
				if (rand_chislo != 9)
				{
					for (i = rand_chislo - 1; i <= rand_chislo + 2; i++)
						for (j = rand_chislo1 - 1; j <= rand_chislo1 + 1; j++)						
							if (pole[i][j] != 0) 
								f = 1; 						
				}
				else f = 1;
			}
			if (ts == 3) 
			{
				if (rand_chislo1 != 0) 
				{
					for (i = rand_chislo - 1; i <= rand_chislo + 1; i++)
						for (j = rand_chislo1 - 2; j <= rand_chislo1 + 1; j++)						
							if (pole[i][j] != 0) 
								f = 1; 						
				}
				else f = 1;
			}
			if (ts == 4) 
			{
				if (rand_chislo1 != 9)
				{
					for (i = rand_chislo - 1; i <= rand_chislo + 1; i++)
						for (j = rand_chislo1 - 1; j <= rand_chislo1 + 2; j++)						
							if (pole[i][j] != 0) 
								f = 1; 						
				}
				else f = 1;
			}
		} while (f == 1);
		switch (ts) 
		{
		case 1: 
			pole[rand_chislo][rand_chislo1] = 1;
			pole[rand_chislo - 1][rand_chislo1] = 1;
			break;
		case 2: 
			pole[rand_chislo][rand_chislo1] = 1;
			pole[rand_chislo + 1][rand_chislo1] = 1;
			break;
		case 3: 
			pole[rand_chislo][rand_chislo1] = 1;
			pole[rand_chislo][rand_chislo1 - 1] = 1;
			break;
		case 4: 
			pole[rand_chislo][rand_chislo1] = 1;
			pole[rand_chislo][rand_chislo1 + 1] = 1;
			break;
		}


	}

	for (k = 0; k<2; k++)                                    
	{
		do {
			f = 0;
			rand_chislo = 1 + rand() % 5;
			rand_chislo1 = 1 + rand() % 5;

			ts = 1 + rand() % 4;

			if (ts == 1) {
				if (rand_chislo != 0 && rand_chislo != 1) {
					for (i = rand_chislo - 3; i<rand_chislo + 2; i++)
						for (j = rand_chislo1 - 1; j <= rand_chislo1 + 1; j++)
						{
							if (pole[i][j] != 0) { f = 1; }
						}
				}
				else f = 1;
			}
			if (ts == 2) {
				if (rand_chislo != 9 && rand_chislo != 8) {
					for (i = rand_chislo - 1; i <= rand_chislo + 3; i++)
						for (j = rand_chislo1 - 1; j <= rand_chislo1 + 1; j++)
						{
							if (pole[i][j] != 0) { f = 1; }
						}
				}
				else f = 1;
			}
			if (ts == 3) {
				if (rand_chislo1 != 0 && rand_chislo1 != 1) {
					for (i = rand_chislo - 1; i <= rand_chislo + 1; i++)
						for (j = rand_chislo1 - 3; j <= rand_chislo1 + 1; j++)
						{
							if (pole[i][j] != 0) { f = 1; }
						}
				}
				else f = 1;
			}
			if (ts == 4) {
				if (rand_chislo1 != 9 && rand_chislo1 != 8) {
					for (i = rand_chislo - 1; i <= rand_chislo + 1; i++)
						for (j = rand_chislo1 - 1; j <= rand_chislo1 + 3; j++)
						{
							if (pole[i][j] != 0) { f = 1; }
						}
				}
				else f = 1;
			}
		} while (f == 1);
		switch (ts) {
		case 1: pole[rand_chislo][rand_chislo1] = 1; pole[rand_chislo - 1][rand_chislo1] = 1; pole[rand_chislo - 2][rand_chislo1] = 1; break;
		case 2: pole[rand_chislo][rand_chislo1] = 1; pole[rand_chislo + 1][rand_chislo1] = 1; pole[rand_chislo + 2][rand_chislo1] = 1; break;
		case 3: pole[rand_chislo][rand_chislo1] = 1; pole[rand_chislo][rand_chislo1 - 1] = 1; pole[rand_chislo][rand_chislo1 - 2] = 1; break;
		case 4: pole[rand_chislo][rand_chislo1] = 1; pole[rand_chislo][rand_chislo1 + 1] = 1; pole[rand_chislo][rand_chislo1 + 2] = 1; break;
		}
	}



	for (i = 0; i<4; i++)
	{
		do {
			rand_chislo = 0 + rand() % 10;
			rand_chislo1 = 0 + rand() % 10;
		} while (pole[rand_chislo][rand_chislo1] != 0 || pole[rand_chislo + 1][rand_chislo1] != 0 || pole[rand_chislo - 1][rand_chislo1] != 0 || pole[rand_chislo][rand_chislo1 + 1] != 0 || pole[rand_chislo][rand_chislo1 - 1] != 0 || pole[rand_chislo + 1][rand_chislo1 + 1] != 0 || pole[rand_chislo - 1][rand_chislo1 - 1] != 0 || pole[rand_chislo + 1][rand_chislo1 - 1] != 0 || pole[rand_chislo - 1][rand_chislo1 + 1] != 0);

		pole[rand_chislo][rand_chislo1] = 1;
	}










	/*   for (i=0;i<10;i++)                    
	{for (r=0;r<3;r++){for (j=0;j<10;j++)
	{if (pole[i][j]==0){ if(r==0) printf ("%c%c%c%c%c",a,b,b,b,c);
	if(r==1) printf ("%c   %c",d,d);
	if(r==2) printf ("%c%c%c%c%c",e,b,b,b,g);}

	else printf ("%c%c%c%c%c",kr,kr,kr,kr,kr);}
	printf ("\n");}}



	getch(); */
	return pole[10][10];
}

int vivod(int pole[10][10])
{
	int i, j, x, y;
	// 1 player
	printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBC\n");

	// 2 player
	GotoXY(40, 0); printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB\n");
	GotoXY(40, 1); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 2); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 3); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 4); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 5); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 6); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 7); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 8); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 9); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 10); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 11); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 12); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 13); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 14); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 15); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 16); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 17); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 18); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 19); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 20); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 21); printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBC\n");

	for (i = 0, x = 1; i<10, x<21; i++, x = x + 2)
		for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)

		{
			GotoXY(x, y); if (pole[i][j] == 0) { if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
			else { SetColor(0, 14); printf("  "); }
			GotoXY(x, y + 1); if (pole[i][j] == 0) { if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
			else { SetColor(0, 14); printf("  "); }
		}


	return 0;
}

int ras(int mypole[10][10])
{

	int i, j, x, y, u, f, e, w, nap, ui;
	SetColor(15, 0);
	printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBC\n");


	GotoXY(40, 0); printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB\n");
	GotoXY(40, 1); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 2); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 3); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 4); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 5); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 6); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 7); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 8); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 9); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 10); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 11); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 12); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 13); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 14); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 15); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 16); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 17); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 18); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 19); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 20); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 21); printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBC\n");

	for (i = 0, x = 1; i<10, x<21; i++, x = x + 2)
		for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)

		{
			GotoXY(x, y);  if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
			else { SetColor(0, 9); printf("  "); }
			GotoXY(x, y + 1); if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
			else { SetColor(0, 9); printf("  "); }
		}

	for (i = 0; i<10; i++)
		for (j = 0; j<10; j++)
			mypole[i][j] = 0;


	GotoXY(24, 7); SetColor(15, 0); printf(Rus("поворот-space"));
	GotoXY(24, 8); SetColor(15, 0); printf(Rus("принять-enter"));
	GotoXY(22, 9); SetColor(15, 0); printf(Rus("управление-стрелки"));
	GotoXY(23, 10); SetColor(15, 0); printf(Rus("выход в меню-Esc"));
	ui = 0;
	for (u = 1; u<5; u++)
	{
		if (ui == 0)
			for (i = 0, x = 41; i<10, x<61; i++, x = x + 2)
				for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)

				{
					GotoXY(x, y); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
					else { if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
					GotoXY(x, y + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
					else { if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
				}
		switch (u)
		{
		case 1:
		{   x = 41; y = nap = 1;
		i = j = 0;
		for (e = x; e<x + 8; e = e + 2)
		{

			GotoXY(e, y); SetColor(0, 14); printf("  ");
			GotoXY(e, y + 1); SetColor(0, 14); printf("  ");
		}
		do {
			f = 0;
			int code = _getch();
			if (code == 224)
			{
				code = _getch();
				switch (code)
				{
				case 72:
				{
					if (y != 1)
					{
						if (nap == 1)
						{
							for (e = x; e<x + 8; e = e + 2)
							{
								i = (e - 40) / 2;
								j = y / 2;
								GotoXY(e, y); if ((i + j) % 2 != 0) { SetColor(0, 2); printf("  "); }
								else { SetColor(0, 10); printf("  "); }
								GotoXY(e, y + 1); if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); }
								else { SetColor(0, 9); printf("  "); }
							}
							y = y - 2;
							for (e = x; e<x + 8; e = e + 2)
							{
								GotoXY(e, y); SetColor(0, 14); printf("  ");
								GotoXY(e, y + 1); SetColor(0, 14); printf("  ");
							}
						}
						else
						{
							if (y != 33) {
								for (e = y; e<y + 8; e = e + 2)
								{
									i = (x - 40) / 2;
									j = e / 2;
									GotoXY(x, e); if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); }
									else { SetColor(0, 9); printf("  "); }
									GotoXY(x, e + 1); if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); }
									else { SetColor(0, 9); printf("  "); }
								}
								y = y - 2;
								for (e = y; e<y + 8; e = e + 2)
								{
									GotoXY(x, e); SetColor(0, 14); printf("  ");
									GotoXY(x, e + 1); SetColor(0, 14); printf("  ");
								}
							}
						}

					}
					break;

				}
				case 77:
				{
					if (nap == 1)
					{
						if (x != 53)
						{
							for (e = x; e<x + 8; e = e + 2) {
								i = (e - 40) / 2;
								j = y / 2;
								GotoXY(e, y); if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); }
								else { SetColor(0, 9); printf("  "); }
								GotoXY(e, y + 1); if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); }
								else { SetColor(0, 9); printf("  "); }
							}
							x = x + 2;
							for (e = x; e<x + 8; e = e + 2)
							{
								GotoXY(e, y); SetColor(0, 14); printf("  ");
								GotoXY(e, y + 1); SetColor(0, 14); printf("  ");

							}
						}
					}
					else {
						if (x != 59) {
							for (e = y; e<y + 8; e = e + 2)
							{
								i = (x - 40) / 2;
								j = e / 2;
								GotoXY(x, e); if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); }
								else { SetColor(0, 9); printf("  "); }
								GotoXY(x, e + 1); if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); }
								else { SetColor(0, 9); printf("  "); }
							}
							x = x + 2;
							for (e = y; e<y + 8; e = e + 2)
							{
								GotoXY(x, e); SetColor(0, 14); printf("  ");
								GotoXY(x, e + 1); SetColor(0, 14); printf("  ");
							}
						}
					}
					break;
				}
				case 80:
				{
					if (nap == 1)
					{
						if (y != 19)
						{
							for (e = x; e<x + 8; e = e + 2) {
								i = (e - 40) / 2;
								j = y / 2;
								GotoXY(e, y); if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); }
								else { SetColor(0, 9); printf("  "); }
								GotoXY(e, y + 1); if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); }
								else { SetColor(0, 9); printf("  "); }
							}
							y = y + 2;
							for (e = x; e<x + 8; e = e + 2)
							{
								GotoXY(e, y); SetColor(0, 14); printf("  ");
								GotoXY(e, y + 1); SetColor(0, 14); printf("  ");
							}
						}
					}
					else {
						if (y != 13) {
							for (e = y; e<y + 8; e = e + 2)
							{
								i = (x - 40) / 2;
								j = e / 2;
								GotoXY(x, e); if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); }
								else { SetColor(0, 9); printf("  "); }
								GotoXY(x, e + 1); if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); }
								else { SetColor(0, 9); printf("  "); }
							}
							y = y + 2;
							for (e = y; e<y + 8; e = e + 2)
							{
								GotoXY(x, e); SetColor(0, 14); printf("  ");
								GotoXY(x, e + 1); SetColor(0, 14); printf("  ");
							}
						}
					}
					break;
				}
				case 75:
				{ if (nap == 1)
				{
					if (x != 41)
					{
						for (e = x; e<x + 8; e = e + 2) {
							i = (e - 40) / 2;
							j = y / 2;
							GotoXY(e, y); if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); }
							else { SetColor(0, 9); printf("  "); }
							GotoXY(e, y + 1); if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); }
							else { SetColor(0, 9); printf("  "); }
						}
						x = x - 2;
						for (e = x; e<x + 8; e = e + 2)
						{
							GotoXY(e, y); SetColor(0, 14); printf("  ");
							GotoXY(e, y + 1); SetColor(0, 14); printf("  ");

						}
					}
				}
				else {
					if (x != 41) {
						for (e = y; e<y + 8; e = e + 2)
						{
							i = (x - 40) / 2;
							j = e / 2;
							GotoXY(x, e); if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); }
							else { SetColor(0, 9); printf("  "); }
							GotoXY(x, e + 1); if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); }
							else { SetColor(0, 9); printf("  "); }
						}
						x = x - 2;
						for (e = y; e<y + 8; e = e + 2)
						{
							GotoXY(x, e); SetColor(0, 14); printf("  ");
							GotoXY(x, e + 1); SetColor(0, 14); printf("  ");
						}
					}
				}
				break;
				}
				}
			}

			else {
				switch (code) {
				case 32:
				{
					if (nap == 1 && y<15 || nap == -1 && x<55)
					{
						nap = nap*(-1);
						if (nap == 1)
						{
							for (e = y; e<y + 8; e = e + 2)
							{
								i = (x - 40) / 2;
								j = e / 2;
								GotoXY(x, e); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
								else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
								GotoXY(x, e + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
								else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
							}



							for (e = x; e<x + 8; e = e + 2)
							{
								GotoXY(e, y); SetColor(0, 14); printf("  ");
								GotoXY(e, y + 1); SetColor(0, 14); printf("  ");

							}

						}
						else {
							for (e = x; e<x + 8; e = e + 2) {
								i = (e - 40) / 2;
								j = y / 2;
								GotoXY(e, y); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
								else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
								GotoXY(e, y + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
								else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
							}

							for (e = y; e<y + 8; e = e + 2)
							{
								GotoXY(x, e); SetColor(0, 14); printf("  ");
								GotoXY(x, e + 1); SetColor(0, 14); printf("  ");
							}
						}
					}
					break;
				}
				case 13: {


					if (nap == 1)
					{
						for (e = x; e<x + 8; e = e + 2)
						{
							i = (e - 40) / 2;
							j = y / 2;
							mypole[i][j] = 1;
						}

					}
					else {

						for (e = y; e<y + 8; e = e + 2)
						{
							i = (x - 40) / 2;
							j = e / 2;
							mypole[i][j] = 1;
						}
					}

					f = 1; break;
				}
				case 27: {f = 1; ui = 1; break; }


				}

			}
		} while (f != 1);
		break;

		}
		case 2:
		{ for (w = 0; w<2; w++)
			if (ui == 0)
			{
				for (i = 0, x = 41; i<10, x<61; i++, x = x + 2)
					for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)

					{
						GotoXY(x, y); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
						else { if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
						GotoXY(x, y + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
						else { if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
					}
				x = 41; y = nap = 1;
				i = j = 0;
				for (e = x; e<x + 6; e = e + 2)
				{

					GotoXY(e, y); SetColor(0, 14); printf("  ");
					GotoXY(e, y + 1); SetColor(0, 14); printf("  ");
				}
				do {
					f = 0;
					int code = _getch();
					if (code == 224)
					{
						code = _getch();
						switch (code)
						{
							{
						case 72:
						{
							if (y != 1)
							{
								if (nap == 1)
								{
									for (e = x; e<x + 6; e = e + 2)
									{
										i = (e - 40) / 2;
										j = y / 2;
										GotoXY(e, y); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
										GotoXY(e, y + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
									}
									y = y - 2;
									for (e = x; e<x + 6; e = e + 2)
									{
										GotoXY(e, y); SetColor(0, 14); printf("  ");
										GotoXY(e, y + 1); SetColor(0, 14); printf("  ");
									}
								}
								else
								{
									if (y != 33) {
										for (e = y; e<y + 6; e = e + 2)
										{
											i = (x - 40) / 2;
											j = e / 2;
											GotoXY(x, e); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
											else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
											GotoXY(x, e + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
											else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
										}
										y = y - 2;
										for (e = y; e<y + 6; e = e + 2)
										{
											GotoXY(x, e); SetColor(0, 14); printf("  ");
											GotoXY(x, e + 1); SetColor(0, 14); printf("  ");
										}
									}
								}

							}

							break;

						}
						case 77:
						{
							if (nap == 1)
							{
								if (x != 55)
								{
									for (e = x; e<x + 6; e = e + 2) {
										i = (e - 40) / 2;
										j = y / 2;
										GotoXY(e, y); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
										GotoXY(e, y + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
									}
									x = x + 2;
									for (e = x; e<x + 6; e = e + 2)
									{
										GotoXY(e, y); SetColor(0, 14); printf("  ");
										GotoXY(e, y + 1); SetColor(0, 14); printf("  ");

									}
								}
							}
							else {
								if (x != 59) {
									for (e = y; e<y + 6; e = e + 2)
									{
										i = (x - 40) / 2;
										j = e / 2;
										GotoXY(x, e); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
										GotoXY(x, e + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
									}
									x = x + 2;
									for (e = y; e<y + 6; e = e + 2)
									{
										GotoXY(x, e); SetColor(0, 14); printf("  ");
										GotoXY(x, e + 1); SetColor(0, 14); printf("  ");
									}
								}
							}
							break;
						}
						case 80:
						{
							if (nap == 1)
							{
								if (y != 19)
								{
									for (e = x; e<x + 6; e = e + 2) {
										i = (e - 40) / 2;
										j = y / 2;
										GotoXY(e, y); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
										GotoXY(e, y + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
									}
									y = y + 2;
									for (e = x; e<x + 6; e = e + 2)
									{
										GotoXY(e, y); SetColor(0, 14); printf("  ");
										GotoXY(e, y + 1); SetColor(0, 14); printf("  ");
									}
								}
							}
							else {
								if (y != 15) {
									for (e = y; e<y + 6; e = e + 2)
									{
										i = (x - 40) / 2;
										j = e / 2;
										GotoXY(x, e); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
										GotoXY(x, e + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
									}
									y = y + 2;
									for (e = y; e<y + 6; e = e + 2)
									{
										GotoXY(x, e); SetColor(0, 14); printf("  ");
										GotoXY(x, e + 1); SetColor(0, 14); printf("  ");
									}
								}
							}
							break;
						}
						case 75:
						{ if (nap == 1)
						{
							if (x != 41)
							{
								for (e = x; e<x + 6; e = e + 2) {
									i = (e - 40) / 2;
									j = y / 2;
									GotoXY(e, y); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
									else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
									GotoXY(e, y + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
									else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
								}
								x = x - 2;
								for (e = x; e<x + 6; e = e + 2)
								{
									GotoXY(e, y); SetColor(0, 14); printf("  ");
									GotoXY(e, y + 1); SetColor(0, 14); printf("  ");

								}
							}
						}
						else {
							if (x != 41) {
								for (e = y; e<y + 6; e = e + 2)
								{
									i = (x - 40) / 2;
									j = e / 2;
									GotoXY(x, e); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
									else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
									GotoXY(x, e + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
									else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
								}
								x = x - 2;
								for (e = y; e<y + 6; e = e + 2)
								{
									GotoXY(x, e); SetColor(0, 14); printf("  ");
									GotoXY(x, e + 1); SetColor(0, 14); printf("  ");
								}
							}
						}
						break;
						}
							}
						}
					}
					else {
						switch (code) {
						case 32:
						{
							if (nap == 1 && y<17 || nap == -1 && x<57)
							{
								nap = nap*(-1);
								if (nap == 1)
								{
									for (e = y; e<y + 6; e = e + 2)
									{
										i = (x - 40) / 2;
										j = e / 2;
										GotoXY(x, e); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
										GotoXY(x, e + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
									}



									for (e = x; e<x + 6; e = e + 2)
									{
										GotoXY(e, y); SetColor(0, 14); printf("  ");
										GotoXY(e, y + 1); SetColor(0, 14); printf("  ");

									}

								}
								else {
									for (e = x; e<x + 6; e = e + 2) {
										i = (e - 40) / 2;
										j = y / 2;
										GotoXY(e, y); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
										GotoXY(e, y + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
									}

									for (e = y; e<y + 6; e = e + 2)
									{
										GotoXY(x, e); SetColor(0, 14); printf("  ");
										GotoXY(x, e + 1); SetColor(0, 14); printf("  ");
									}
								}
							}
							break;
						}
						case 13: {int pr = f = 0;


							if (nap == 1)
							{
								for (e = x - 2; e <= x + 6; e = e + 2)
									for (int a = y - 2; a <= y + 2; a = a + 2)
									{
										i = (e - 40) / 2;
										j = a / 2;
										if (i<10 && j<10)if (mypole[i][j] == 1)
											pr = 1;
									}
								if (pr == 0)
									for (e = x; e<x + 6; e = e + 2)

									{
										i = (e - 40) / 2;
										j = y / 2;
										mypole[i][j] = 1; f = 1;
									}

							}
							else {
								for (e = y - 2; e <= y + 6; e = e + 2)
									for (int a = x - 2; a <= x + 2; a = a + 2)
									{
										i = (a - 40) / 2;
										j = e / 2;
										if (i<10 && j<10)if (mypole[i][j] == 1)
											pr = 1;
									}
								if (pr == 0)
									for (e = y; e<y + 6; e = e + 2)
									{
										i = (x - 40) / 2;
										j = e / 2;
										mypole[i][j] = 1; f = 1;
									}
							}

							break;
						}
						case 27: {f = 1; ui = 1; break; }


						}
					}

				} while (f != 1);
			}
		break;

		}

		case 3:
		{ for (w = 0; w<3; w++)
			if (ui == 0)
			{
				for (i = 0, x = 41; i<10, x<61; i++, x = x + 2)
					for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)

					{
						GotoXY(x, y); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
						else { if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
						GotoXY(x, y + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
						else { if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
					}
				x = 41; y = nap = 1;
				i = j = 0;
				for (e = x; e<x + 4; e = e + 2)
				{

					GotoXY(e, y); SetColor(0, 14); printf("  ");
					GotoXY(e, y + 1); SetColor(0, 14); printf("  ");
				}
				do {
					f = 0;
					int code = _getch();
					if (code == 224)
					{
						code = _getch();
						switch (code)
						{
						case 72:
						{
							if (y != 1)
							{
								if (nap == 1)
								{
									for (e = x; e<x + 4; e = e + 2)
									{
										i = (e - 40) / 2;
										j = y / 2;
										GotoXY(e, y); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
										GotoXY(e, y + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
									}
									y = y - 2;
									for (e = x; e<x + 4; e = e + 2)
									{
										GotoXY(e, y); SetColor(0, 14); printf("  ");
										GotoXY(e, y + 1); SetColor(0, 14); printf("  ");
									}
								}
								else
								{
									if (y != 33) {
										for (e = y; e<y + 4; e = e + 2)
										{
											i = (x - 40) / 2;
											j = e / 2;
											GotoXY(x, e); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
											else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
											GotoXY(x, e + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
											else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
										}
										y = y - 2;
										for (e = y; e<y + 4; e = e + 2)
										{
											GotoXY(x, e); SetColor(0, 14); printf("  ");
											GotoXY(x, e + 1); SetColor(0, 14); printf("  ");
										}
									}
								}

							}

							break;

						}
						case 77:
						{
							if (nap == 1)
							{
								if (x != 57)
								{
									for (e = x; e<x + 4; e = e + 2) {
										i = (e - 40) / 2;
										j = y / 2;
										GotoXY(e, y); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
										GotoXY(e, y + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
									}
									x = x + 2;
									for (e = x; e<x + 4; e = e + 2)
									{
										GotoXY(e, y); SetColor(0, 14); printf("  ");
										GotoXY(e, y + 1); SetColor(0, 14); printf("  ");

									}
								}
							}
							else {
								if (x != 59) {
									for (e = y; e<y + 4; e = e + 2)
									{
										i = (x - 40) / 2;
										j = e / 2;
										GotoXY(x, e); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
										GotoXY(x, e + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
									}
									x = x + 2;
									for (e = y; e<y + 4; e = e + 2)
									{
										GotoXY(x, e); SetColor(0, 14); printf("  ");
										GotoXY(x, e + 1); SetColor(0, 14); printf("  ");
									}
								}
							}
							break;
						}
						case 80:
						{
							if (nap == 1)
							{
								if (y != 19)
								{
									for (e = x; e<x + 4; e = e + 2) {
										i = (e - 40) / 2;
										j = y / 2;
										GotoXY(e, y); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
										GotoXY(e, y + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
									}
									y = y + 2;
									for (e = x; e<x + 4; e = e + 2)
									{
										GotoXY(e, y); SetColor(0, 14); printf("  ");
										GotoXY(e, y + 1); SetColor(0, 14); printf("  ");
									}
								}
							}
							else {
								if (y != 17) {
									for (e = y; e<y + 4; e = e + 2)
									{
										i = (x - 40) / 2;
										j = e / 2;
										GotoXY(x, e); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
										GotoXY(x, e + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
									}
									y = y + 2;
									for (e = y; e<y + 4; e = e + 2)
									{
										GotoXY(x, e); SetColor(0, 14); printf("  ");
										GotoXY(x, e + 1); SetColor(0, 14); printf("  ");
									}
								}
							}
							break;
						}
						case 75:
						{ if (nap == 1)
						{
							if (x != 41)
							{
								for (e = x; e<x + 4; e = e + 2) {
									i = (e - 40) / 2;
									j = y / 2;
									GotoXY(e, y); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
									else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
									GotoXY(e, y + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
									else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
								}
								x = x - 2;
								for (e = x; e<x + 4; e = e + 2)
								{
									GotoXY(e, y); SetColor(0, 14); printf("  ");
									GotoXY(e, y + 1); SetColor(0, 14); printf("  ");

								}
							}
						}
						else {
							if (x != 41) {
								for (e = y; e<y + 4; e = e + 2)
								{
									i = (x - 40) / 2;
									j = e / 2;
									GotoXY(x, e); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
									else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
									GotoXY(x, e + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
									else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
								}
								x = x - 2;
								for (e = y; e<y + 4; e = e + 2)
								{
									GotoXY(x, e); SetColor(0, 14); printf("  ");
									GotoXY(x, e + 1); SetColor(0, 14); printf("  ");
								}
							}
						}
						break;
						}
						}
					}
					else {
						switch (code) {
						case 32:
						{
							if (nap == 1 && y<19 || nap == -1 && x<59)
							{
								nap = nap*(-1);
								if (nap == 1)
								{
									for (e = y; e<y + 4; e = e + 2)
									{
										i = (x - 40) / 2;
										j = e / 2;
										GotoXY(x, e); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
										GotoXY(x, e + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
									}



									for (e = x; e<x + 4; e = e + 2)
									{
										GotoXY(e, y); SetColor(0, 14); printf("  ");
										GotoXY(e, y + 1); SetColor(0, 14); printf("  ");

									}

								}
								else {
									for (e = x; e<x + 4; e = e + 2) {
										i = (e - 40) / 2;
										j = y / 2;
										GotoXY(e, y); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
										GotoXY(e, y + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
										else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
									}

									for (e = y; e<y + 4; e = e + 2)
									{
										GotoXY(x, e); SetColor(0, 14); printf("  ");
										GotoXY(x, e + 1); SetColor(0, 14); printf("  ");
									}
								}
							}
							break;
						}
						case 13: {int pr = f = 0;


							if (nap == 1)
							{
								for (e = x - 2; e <= x + 4; e = e + 2)
									for (int a = y - 2; a <= y + 2; a = a + 2)
									{
										i = (e - 40) / 2;
										j = a / 2;
										if (i<10 && j<10)if (mypole[i][j] == 1)
											pr = 1;
									}
								if (pr == 0)
									for (e = x; e<x + 4; e = e + 2)

									{
										i = (e - 40) / 2;
										j = y / 2;
										mypole[i][j] = 1; f = 1;
									}

							}
							else {
								for (e = y - 2; e <= y + 4; e = e + 2)
									for (int a = x - 2; a <= x + 2; a = a + 2)
									{
										i = (a - 40) / 2;
										j = e / 2;
										if (i<10 && j<10)if (mypole[i][j] == 1)
											pr = 1;
									}
								if (pr == 0)
									for (e = y; e<y + 4; e = e + 2)
									{
										i = (x - 40) / 2;
										j = e / 2;
										mypole[i][j] = 1; f = 1;
									}
							}

							break;
						}
						case 27: {f = 1; ui = 1; break; }

						}
					}

				} while (f != 1);
			}
		break;

		}

		case 4:
		{ for (w = 0; w<4; w++)
			if (ui == 0)
			{
				for (i = 0, x = 41; i<10, x<61; i++, x = x + 2)
					for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)

					{
						GotoXY(x, y); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
						else { if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
						GotoXY(x, y + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
						else { if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
					}
				x = 41; y = 1;
				i = j = 0;
				e = x;
				{

					GotoXY(e, y); SetColor(0, 14); printf("  ");
					GotoXY(e, y + 1); SetColor(0, 14); printf("  ");
				}
				do {
					f = 0;
					int code = _getch();
					if (code == 224)
					{
						code = _getch();
						switch (code)
						{
						case 72:
						{
							if (y != 1)
							{

								e = x;
								{
									i = (e - 40) / 2;
									j = y / 2;
									GotoXY(e, y); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
									else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
									GotoXY(e, y + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
									else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
								}
								y = y - 2;
								e = x;
								{
									GotoXY(e, y); SetColor(0, 14); printf("  ");
									GotoXY(e, y + 1); SetColor(0, 14); printf("  ");
								}
							}




							break;

						}
						case 77:
						{

							if (x != 59)
							{
								e = x; {
									i = (e - 40) / 2;
									j = y / 2;
									GotoXY(e, y); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
									else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
									GotoXY(e, y + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
									else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
								}
								x = x + 2;
								e = x;
								{
									GotoXY(e, y); SetColor(0, 14); printf("  ");
									GotoXY(e, y + 1); SetColor(0, 14); printf("  ");

								}
							}


							break;
						}
						case 80:
						{


							if (y != 19)
							{
								e = x; {
									i = (e - 40) / 2;
									j = y / 2;
									GotoXY(e, y); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
									else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
									GotoXY(e, y + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
									else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
								}
								y = y + 2;
								e = x;
								{
									GotoXY(e, y); SetColor(0, 14); printf("  ");
									GotoXY(e, y + 1); SetColor(0, 14); printf("  ");
								}
							}


							break;
						}
						case 75:
						{
							if (x != 41)
							{
								e = x; {
									i = (e - 40) / 2;
									j = y / 2;
									GotoXY(e, y); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
									else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
									GotoXY(e, y + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
									else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
								}
								x = x - 2;
								e = x;
								{
									GotoXY(e, y); SetColor(0, 14); printf("  ");
									GotoXY(e, y + 1); SetColor(0, 14); printf("  ");

								}
							}


							break;
						}
						}
					}
					else {
						switch (code) {
						case 13: {
							int pr = f = 0;


							for (e = x - 2; e <= x + 2; e = e + 2)
								for (int a = y - 2; a <= y + 2; a = a + 2)
								{
									i = (e - 40) / 2;
									j = a / 2;
									if (i<10 && j<10)if (mypole[i][j] == 1)
										pr = 1;
								}
							if (pr == 0)
								for (e = x; e<x + 2; e = e + 2)

								{
									i = (e - 40) / 2;
									j = y / 2;
									mypole[i][j] = 1; f = 1;
								}
							break;
						}
						case 27: {f = 1; ui = 1; break; }

								 break;
						}
					}

				} while (f != 1);

			}


		break;
		}

		break;
		}
	}

	return ui;
}

int menu()
{
	int f = 1, k;
	SetColor(0, 0);
	system("cls");
	GotoXY(30, 10); SetColor(12, 0); printf(Rus("Главное меню"));
	GotoXY(30, 12); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("Новая игра")); SetColor(15, 0); printf("]");
	GotoXY(32, 13); SetColor(15, 0); printf("["); printf(Rus("выход")); SetColor(15, 0); printf("]");
	do {
		k = 0;
		int code = _getch();
		if (code == 224)
		{
			code = _getch();
			switch (code)
			{
			case 80: {f = f*(-1);
				if (f == 1) {
					GotoXY(30, 12); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("Новая игра")); SetColor(15, 0); printf("]");
					GotoXY(32, 13); SetColor(15, 0); printf(Rus("[выход]"));
				}
				else {
					GotoXY(30, 12); SetColor(15, 0); printf("["); printf(Rus("Новая игра")); printf("]");
					GotoXY(32, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("выход")); SetColor(15, 0); printf("]");
				}
				break; }

			case 72: {f = f*(-1);
				if (f == 1) {
					GotoXY(30, 12); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("Новая игра")); SetColor(15, 0); printf("]");
					GotoXY(32, 13); SetColor(15, 0); printf(Rus("[выход]"));
				}
				else {
					GotoXY(30, 12); SetColor(15, 0); printf("["); printf(Rus("Новая игра")); printf("]");
					GotoXY(32, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("выход")); SetColor(15, 0); printf("]");
				}
				break; }

			}
		}

		else
		{
			switch (code)
			{
			case 13: k = 1; break;
			}

		}

	} while (k == 0);
	return f;
}

int comp(int mypole[10][10], int udar, int ud[2], int hod[1])  // ИИ
{

	int i, j, f, per, n, m, x, y, k, str, sto, h, g;
	int pri, prj;


	srand(time(NULL));
	GotoXY(24, 14);
	SetColor(9, 0);
	printf(Rus("  Ходит комп "));
	do {
		f = 1;
		per = 0;
		k = 0;
		GotoXY(28, 16);
		SetColor(15, 0);
		printf(Rus("      "));
		Sleep(1000);

		h = 0; if (hod[0] == 5) 
		{
			for (n = ud[0] - 1; n <= ud[0] + 1 && n<10; n++)
				for (m = ud[1] - 1; m <= ud[1] + 1 && m<10; m++)
					if (mypole[n][m] == 1)
					{
						h = 1;
					}
			if (h == 0)
			{
				mypole[ud[0]][ud[1]] = 5;
				for (n = ud[0] - 1; n <= ud[0] + 1 && n<10; n++)
					for (m = ud[1] - 1; m <= ud[1] + 1 && m<10; m++)
						if (mypole[n][m] == 0)
						{
							mypole[n][m] = 3;
						}
			}
			if (h == 1) {
				per = 1; srand(time(NULL));
				do {
					pri = 1 + rand() % 4; prj = 0;
					switch (pri) {
					case 1:
					{if (mypole[ud[0] - 1][ud[1]] == 0 && ud[0] != 0) { mypole[ud[0] - 1][ud[1]] = 3; GotoXY(28, 16); SetColor(15, 0); Sleep(1000); printf(Rus("Мимо!")); prj = 1; per = 1; f = 1; }
					if (mypole[ud[0] - 1][ud[1]] == 1 && ud[0] != 0) { mypole[ud[0] - 1][ud[1]] = 4; GotoXY(28, 16); SetColor(15, 0); printf(Rus("Попал!")); udar++; Sleep(1000); printf("\x07"); f = 0; prj = 1; per = 1; hod[0] = 1; }
					break; }
					case 2:
					{if (mypole[ud[0] + 1][ud[1]] == 0 && ud[0] != 9) { mypole[ud[0] + 1][ud[1]] = 3; GotoXY(28, 16); SetColor(15, 0); Sleep(1000); printf(Rus("Мимо!")); prj = 1; per = 1; f = 1; }
					if (mypole[ud[0] + 1][ud[1]] == 1 && ud[0] != 9) { mypole[ud[0] + 1][ud[1]] = 4; GotoXY(28, 16); SetColor(15, 0); printf(Rus("Попал!")); udar++; Sleep(1000); printf("\x07"); f = 0; prj = 1; per = 1; hod[0] = 1; }
					break; }
					case 3: {if (mypole[ud[0]][ud[1] - 1] == 0 && ud[1] != 0) { mypole[ud[0]][ud[1] - 1] = 3; GotoXY(28, 16); SetColor(15, 0); Sleep(1000); printf(Rus("Мимо!")); prj = 1; per = 1; f = 1; }
							if (mypole[ud[0]][ud[1] - 1] == 1 && ud[1] != 0) { mypole[ud[0]][ud[1] - 1] = 4; GotoXY(28, 16); SetColor(15, 0); printf(Rus("Попал!")); udar++; Sleep(1000); printf("\x07"); f = 0; prj = 1; per = 1; hod[0] = 1; }
							break; }
					case 4: {if (mypole[ud[0]][ud[1] + 1] == 0 && ud[1] != 9) { mypole[ud[0]][ud[1] + 1] = 3; GotoXY(28, 16); SetColor(15, 0); Sleep(1000); printf(Rus("Мимо!")); prj = 1; per = 1; f = 1; }
							if (mypole[ud[0]][ud[1] + 1] == 1 && ud[1] != 9) { mypole[ud[0]][ud[1] + 1] = 4; GotoXY(28, 16); SetColor(15, 0); printf(Rus("Попал!")); udar++; Sleep(1000); printf("\x07"); f = 0; prj = 1; per = 1; hod[0] = 1; }
							break; }
					}
				} while (prj == 0);
			}
		}

		if (hod[0] == 1)
		{
			for (i = 0; i<10; i++)
				for (j = 0; j<10; j++)
				{
					h = 0;
					if (mypole[i][j] == 4 || mypole[i][j] == 5)
					{
						mypole[i][j] = 5;
						if (i>0) {
							if (mypole[i - 1][j] == 1) {
								h = 1; mypole[i - 1][j] = 5; GotoXY(28, 16); SetColor(15, 0); printf(Rus("Попал!")); Sleep(1000); printf("\x07");
								for (i = 0, x = 41; i<10, x<61; i++, x = x + 2)
									for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)

									{
										GotoXY(x, y); switch (mypole[i][j]) {
										case 0:if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
											   else { SetColor(0, 9); printf("  "); }break;
										case 1:SetColor(0, 12); printf("  "); break;
										case 2:SetColor(0, 7); printf("  "); break;
										case 3: SetColor(0, 11); printf("  "); break;
										case 4:SetColor(0, 7); printf("  "); break;
										case 5:SetColor(0, 7); printf("  "); break;
										}
										GotoXY(x, y + 1); switch (mypole[i][j]) {
										case 0:if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
											   else { SetColor(0, 9); printf("  "); }break;
										case 1:SetColor(0, 12); printf("  "); break;
										case 2:SetColor(0, 7); printf("  "); break;
										case 3:SetColor(0, 11); printf("  "); break;
										case 4:SetColor(0, 7); printf("  "); break;
										case 5:SetColor(0, 7); printf("  "); break;
										}
									}
							}
						}
						if (i<9) {
							if (mypole[i + 1][j] == 1) {
								h = 1; mypole[i + 1][j] = 5; GotoXY(28, 16); SetColor(15, 0); printf(Rus("Попал!")); Sleep(1000); printf("\x07");
								for (i = 0, x = 41; i<10, x<61; i++, x = x + 2)
									for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)

									{
										GotoXY(x, y); switch (mypole[i][j]) {
										case 0:if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
											   else { SetColor(0, 9); printf("  "); }break;
										case 1:SetColor(0, 12); printf("  "); break;
										case 2:SetColor(0, 7); printf("  "); break;
										case 3: SetColor(0, 11); printf("  "); break;
										case 4:SetColor(0, 7); printf("  "); break;
										case 5:SetColor(0, 7); printf("  "); break;
										}
										GotoXY(x, y + 1); switch (mypole[i][j]) {
										case 0:if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
											   else { SetColor(0, 9); printf("  "); }break;
										case 1:SetColor(0, 12); printf("  "); break;
										case 2:SetColor(0, 7); printf("  "); break;
										case 3:SetColor(0, 11); printf("  "); break;
										case 4:SetColor(0, 7); printf("  "); break;
										case 5:SetColor(0, 7); printf("  "); break;
										}
									}
							}
						}
						if (j>0) {
							if (mypole[i][j - 1] == 1) {
								h = 1; mypole[i][j - 1] = 5; GotoXY(28, 16); SetColor(15, 0); printf(Rus("Попал!")); Sleep(1000); printf("\x07");
								for (i = 0, x = 41; i<10, x<61; i++, x = x + 2)
									for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)

									{
										GotoXY(x, y); switch (mypole[i][j]) {
										case 0:if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
											   else { SetColor(0, 9); printf("  "); }break;
										case 1:SetColor(0, 12); printf("  "); break;
										case 2:SetColor(0, 7); printf("  "); break;
										case 3: SetColor(0, 11); printf("  "); break;
										case 4:SetColor(0, 7); printf("  "); break;
										case 5:SetColor(0, 7); printf("  "); break;
										}
										GotoXY(x, y + 1); switch (mypole[i][j]) {
										case 0:if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
											   else { SetColor(0, 9); printf("  "); }break;
										case 1:SetColor(0, 12); printf("  "); break;
										case 2:SetColor(0, 7); printf("  "); break;
										case 3:SetColor(0, 11); printf("  "); break;
										case 4:SetColor(0, 7); printf("  "); break;
										case 5:SetColor(0, 7); printf("  "); break;
										}
									}
							}
						}
						if (j<9) {
							if (mypole[i][j + 1] == 1) {
								h = 1; mypole[i][j + 1] = 5; GotoXY(28, 16); SetColor(15, 0); printf(Rus("Попал!")); Sleep(1000); printf("\x07");
								for (i = 0, x = 41; i<10, x<61; i++, x = x + 2)
									for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)

									{
										GotoXY(x, y); switch (mypole[i][j]) {
										case 0:if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
											   else { SetColor(0, 9); printf("  "); }break;
										case 1:SetColor(0, 12); printf("  "); break;
										case 2:SetColor(0, 7); printf("  "); break;
										case 3: SetColor(0, 11); printf("  "); break;
										case 4:SetColor(0, 7); printf("  "); break;
										case 5:SetColor(0, 7); printf("  "); break;
										}
										GotoXY(x, y + 1); switch (mypole[i][j]) {
										case 0:if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
											   else { SetColor(0, 9); printf("  "); }break;
										case 1:SetColor(0, 12); printf("  "); break;
										case 2:SetColor(0, 7); printf("  "); break;
										case 3:SetColor(0, 11); printf("  "); break;
										case 4:SetColor(0, 7); printf("  "); break;
										case 5:SetColor(0, 7); printf("  "); break;
										}
									}
							}
						}
					}
				}

			for (i = 0; i<10; i++)
				for (j = 0; j<10; j++)
				{
					h = 0;
					if (mypole[i][j] == 5)
					{
						if (i>0) { if (mypole[i - 1][j] == 0) { h = 1; mypole[i - 1][j] = 3; } }
						if (i<9) { if (mypole[i + 1][j] == 0) { h = 1; mypole[i + 1][j] = 3; } }
						if (j>0) { if (mypole[i][j - 1] == 0) { h = 1; mypole[i][j - 1] = 3; } }
						if (j<9) { if (mypole[i][j + 1] == 0) { h = 1; mypole[i][j + 1] = 3; } }
						if (i>0 && j>0) { if (mypole[i - 1][j - 1] == 0) { h = 1; mypole[i - 1][j - 1] = 3; } }
						if (i>0 && j<9) { if (mypole[i - 1][j + 1] == 0) { h = 1; mypole[i - 1][j + 1] = 3; } }
						if (i<9 && j<9) { if (mypole[i + 1][j + 1] == 0) { h = 1; mypole[i + 1][j + 1] = 3; } }
						if (i<9 && j>0) { if (mypole[i + 1][j - 1] == 0) { h = 1; mypole[i + 1][j - 1] = 3; } }
					}
				}

		}
		udar = 0;
		for (i = 0; i<10; i++)
			for (j = 0; j<10; j++)
				if (mypole[i][j] == 4 || mypole[i][j] == 5)
					udar++;

		if (udar == 20)
		{
			f = 1; per = 1;
		}
		for (i = 0, x = 41; i<10, x<61; i++, x = x + 2)
			for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)

			{
				GotoXY(x, y); switch (mypole[i][j]) {
				case 0:if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
					   else { SetColor(0, 9); printf("  "); }break;
				case 1:SetColor(0, 12); printf("  "); break;
				case 2:SetColor(0, 7); printf("  "); break;
				case 3: SetColor(0, 11); printf("  "); break;
				case 4:SetColor(0, 7); printf("  "); break;
				case 5:SetColor(0, 7); printf("  "); break;
				}
				GotoXY(x, y + 1); switch (mypole[i][j]) {
				case 0:if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
					   else { SetColor(0, 9); printf("  "); }break;
				case 1:SetColor(0, 12); printf("  "); break;
				case 2:SetColor(0, 7); printf("  "); break;
				case 3:SetColor(0, 11); printf("  "); break;
				case 4:SetColor(0, 7); printf("  "); break;
				case 5:SetColor(0, 7); printf("  "); break;
				}
			}

		if (per == 0)
		{
			do {
				i = 0 + rand() % 10;
				j = 0 + rand() % 10;
			} while (mypole[i][j]>1);
			if (mypole[i][j] == 1) { mypole[i][j] = 4; ud[0] = i; ud[1] = j; GotoXY(28, 16); SetColor(15, 0); printf(Rus("Попал!")); hod[0] = 5; Sleep(1000); printf("\x07"); f = 0; }

			if (mypole[i][j] == 0) { mypole[i][j] = 3; f = 1; GotoXY(28, 16); SetColor(15, 0); printf(Rus("Мимо!")); Sleep(1000); }

		}

		Sleep(1000);
		for (i = 0, x = 41; i<10, x<61; i++, x = x + 2)
			for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)

			{
				GotoXY(x, y); switch (mypole[i][j]) {
				case 0:if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
					   else { SetColor(0, 9); printf("  "); }break;
				case 1:SetColor(0, 12); printf("  "); break;
				case 2:SetColor(0, 7); printf("  "); break;
				case 3: SetColor(0, 11); printf("  "); break;
				case 4:SetColor(0, 7); printf("  "); break;
				case 5:SetColor(0, 7); printf("  "); break;
				}
				GotoXY(x, y + 1); switch (mypole[i][j]) {
				case 0:if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
					   else { SetColor(0, 9); printf("  "); }break;
				case 1:SetColor(0, 12); printf("  "); break;
				case 2:SetColor(0, 7); printf("  "); break;
				case 3:SetColor(0, 11); printf("  "); break;
				case 4:SetColor(0, 7); printf("  "); break;
				case 5:SetColor(0, 7); printf("  "); break;
				}
			}
	} while (f == 0);

	return udar;
}
int player(int pole[10][10], int udar)
{
	GotoXY(27, 16); SetColor(0, 0); printf(Rus("        "));
	int i, j, x, y, f, e, k = 0, pop, iper, jper; int vih, end;
	for (i = 0, x = 1; i<10, x<21; i++, x = x + 2)
		for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)

		{
			GotoXY(x, y); if (pole[i][j] == 3) { SetColor(0, 11); printf("  "); }
			else { if (pole[i][j] == 2) { SetColor(0, 12); printf("  "); } else { if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } } }
			GotoXY(x, y + 1); if (pole[i][j] == 3) { SetColor(0, 11); printf("  "); }
			else { if (pole[i][j] == 2) { SetColor(0, 12); printf("  "); } else { if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } } }
		}
	x = 1; y = 1;
	i = j = 0;
	e = x;
	{

		GotoXY(e, y); SetColor(0, 14); printf("  ");
		GotoXY(e, y + 1); SetColor(0, 14); printf("  ");
	}
	do {
		f = 0; pop = 0; GotoXY(24, 14); SetColor(15, 0); printf(Rus("  Ходит игрок "));
		int code = _getch();
		if (code == 224)
		{
			GotoXY(27, 16); SetColor(0, 0); printf(Rus("        "));
			code = _getch();
			switch (code)
			{
			case 72:
			{
				if (y != 1)
				{

					e = x;
					{
						i = e / 2;
						j = y / 2;
						GotoXY(e, y); if (pole[i][j] == 3) { SetColor(0, 11); printf("  "); }
						else { if (pole[i][j] == 2) { SetColor(0, 12); printf("  "); } else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } } }
						GotoXY(e, y + 1); if (pole[i][j] == 3) { SetColor(0, 11); printf("  "); }
						else { if (pole[i][j] == 2) { SetColor(0, 12); printf("  "); } else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } } }
					}
					y = y - 2;
					e = x;
					{
						GotoXY(e, y); SetColor(0, 14); printf("  ");
						GotoXY(e, y + 1); SetColor(0, 14); printf("  ");
					}
				}




				break;

			}
			case 77:
			{

				if (x != 19)
				{
					e = x; {
						i = e / 2;
						j = y / 2;
						GotoXY(e, y); if (pole[i][j] == 3) { SetColor(0, 11); printf("  "); }
						else { if (pole[i][j] == 2) { SetColor(0, 12); printf("  "); } else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } } }
						GotoXY(e, y + 1); if (pole[i][j] == 3) { SetColor(0, 11); printf("  "); }
						else { if (pole[i][j] == 2) { SetColor(0, 12); printf("  "); } else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } } }
					}
					x = x + 2;
					e = x;
					{
						GotoXY(e, y); SetColor(0, 14); printf("  ");
						GotoXY(e, y + 1); SetColor(0, 14); printf("  ");

					}
				}


				break;
			}
			case 80:
			{


				if (y != 19)
				{
					e = x; {
						i = e / 2;
						j = y / 2;
						GotoXY(e, y); if (pole[i][j] == 3) { SetColor(0, 11); printf("  "); }
						else { if (pole[i][j] == 2) { SetColor(0, 12); printf("  "); } else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } } }
						GotoXY(e, y + 1); if (pole[i][j] == 3) { SetColor(0, 11); printf("  "); }
						else { if (pole[i][j] == 2) { SetColor(0, 12); printf("  "); } else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } } }
					}
					y = y + 2;
					e = x;
					{
						GotoXY(e, y); SetColor(0, 14); printf("  ");
						GotoXY(e, y + 1); SetColor(0, 14); printf("  ");
					}
				}


				break;
			}
			case 75:
			{
				if (x != 1)
				{
					e = x; {
						i = e / 2;
						j = y / 2;
						GotoXY(e, y); if (pole[i][j] == 3) { SetColor(0, 11); printf("  "); }
						else { if (pole[i][j] == 2) { SetColor(0, 12); printf("  "); } else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } } }
						GotoXY(e, y + 1); if (pole[i][j] == 3) { SetColor(0, 11); printf("  "); }
						else { if (pole[i][j] == 2) { SetColor(0, 12); printf("  "); } else { if ((i + j) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } } }
					}
					x = x - 2;
					e = x;
					{
						GotoXY(e, y); SetColor(0, 14); printf("  ");
						GotoXY(e, y + 1); SetColor(0, 14); printf("  ");

					}
				}


				break;
			}
			}
		}
		else {
			switch (code) {
			case 13: {
				int pr = f = 0;

				pop = 0;
				e = x;
				int a = y;
				{i = e / 2;
				j = a / 2;
				if (i<10 && j<10)if (pole[i][j] == 2 || pole[i][j] == 3)
					pr = 1; }
				if (pr == 0)
				{
					e = x;

					i = e / 2;
					j = y / 2;
					if (pole[i][j] == 0)
					{
						pole[i][j] = 3; f = 1; GotoXY(28, 16); SetColor(15, 0); printf(Rus("Мимо!"));
					}
					else { pole[i][j] = 2; printf("\x07"); GotoXY(27, 16); SetColor(15, 0); printf(Rus("Попал!")); pop = 1; udar++; }
				}
				break;
			}
			case 27: { f = 1;
				GotoXY(24, 14); SetColor(15, 0); printf(Rus("    Выйти?    "));
				GotoXY(24, 16); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("да")); SetColor(15, 0); printf("]  ");
				GotoXY(31, 16); SetColor(15, 0); printf("  ["); printf(Rus("нет")); SetColor(15, 0); printf("]");
				do {
					k = 0; vih = 0;
					int code = _getch();
					if (code == 224)
					{
						code = _getch();
						switch (code)
						{
						case 75: {f = f*(-1);
							if (f == 1) {
								GotoXY(24, 16); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("да")); SetColor(15, 0); printf("]  ");
								GotoXY(31, 16); SetColor(15, 0); printf("  ["); printf(Rus("нет")); SetColor(15, 0); printf("]");
							}
							else {
								GotoXY(24, 16); SetColor(15, 0); printf("["); printf(Rus("да")); printf("]  ");
								GotoXY(31, 16); SetColor(15, 0); printf("  ["); SetColor(0, 2); printf(Rus("нет")); SetColor(15, 0); printf("]");
							}
							break; }

						case 77: {f = f*(-1);
							if (f == 1) {
								GotoXY(24, 16); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("да")); SetColor(15, 0); printf("]  ");
								GotoXY(31, 16); SetColor(15, 0); printf("  ["); printf(Rus("нет")); SetColor(15, 0); printf("]");
							}
							else {
								GotoXY(24, 16); SetColor(15, 0); printf("["); printf(Rus("да")); printf("]  ");
								GotoXY(31, 16); SetColor(15, 0); printf("  ["); SetColor(0, 2); printf(Rus("нет")); SetColor(15, 0); printf("]");
							}
							break; }

						}
					}

					else {
						switch (code)
						{
						case 13: {GotoXY(24, 14); SetColor(0, 0); printf(Rus("              "));
							GotoXY(24, 16); printf("              ");
							if (f == 1) k = 1;  vih = 1; break; }
						}

					}

				} while (vih == 0);
				break; }

			}

			int mas[20][2], flag, sh = 0, a, b;
			for (i = 0; i<10; i++)
				for (j = 0; j<10; j++)
				{
					if (pole[i][j] == 1)
					{
						if (i>0)if (pole[i - 1][j] == 2) {
							mas[sh][0] = i - 1; mas[sh][1] = j; sh++;
							if (i>1)if (pole[i - 2][j] == 2) {
								mas[sh][0] = i - 2; mas[sh][1] = j; sh++;
								if (i>2)if (pole[i - 3][j] == 2) { mas[sh][0] = i - 3; mas[sh][1] = j; sh++; }
							}
						}

						if (i<9)if (pole[i + 1][j] == 2) {
							mas[sh][0] = i + 1; mas[sh][1] = j; sh++;
							if (i<8)if (pole[i + 2][j] == 2) {
								mas[sh][0] = i + 2; mas[sh][1] = j; sh++;
								if (i<7)if (pole[i + 3][j] == 2) { mas[sh][0] = i + 3; mas[sh][1] = j; sh++; }
							}
						}

						if (j>0)if (pole[i][j - 1] == 2) {
							mas[sh][0] = i; mas[sh][1] = j - 1; sh++;
							if (j>1)if (pole[i][j - 2] == 2) {
								mas[sh][0] = i; mas[sh][1] = j - 2; sh++;
								if (j>2)if (pole[i][j - 3] == 2) { mas[sh][0] = i; mas[sh][1] = j - 3; sh++; }
							}
						}

						if (j<9)if (pole[i][j + 1] == 2) {
							mas[sh][0] = i; mas[sh][1] = j + 1; sh++;
							if (i<8)if (pole[i][j + 2] == 2) {
								mas[sh][0] = i; mas[sh][1] = j + 2; sh++;
								if (i<7)if (pole[i][j + 3] == 2) { mas[sh][0] = i; mas[sh][1] = j + 3; sh++; }
							}
						}
					}
				}
			for (i = 0; i<10; i++)
				for (j = 0; j<10; j++)
				{
					b = 0;
					if (pole[i][j] == 2)
					{
						for (a = 0; a<sh; a++)
							if (i == mas[a][0] && j == mas[a][1])
								b = 1;
						if (b == 0)
						{
							if (i>0) { if (pole[i - 1][j] == 0) { pole[i - 1][j] = 3; } }
							if (i<9) { if (pole[i + 1][j] == 0) { pole[i + 1][j] = 3; } }
							if (j>0) { if (pole[i][j - 1] == 0) { pole[i][j - 1] = 3; } }
							if (j<9) { if (pole[i][j + 1] == 0) { pole[i][j + 1] = 3; } }
							if (i>0 && j>0) { if (pole[i - 1][j - 1] == 0) { pole[i - 1][j - 1] = 3; } }
							if (i>0 && j<9) { if (pole[i - 1][j + 1] == 0) { pole[i - 1][j + 1] = 3; } }
							if (i<9 && j<9) { if (pole[i + 1][j + 1] == 0) { pole[i + 1][j + 1] = 3; } }
							if (i<9 && j>0) { if (pole[i + 1][j - 1] == 0) { pole[i + 1][j - 1] = 3; } }
						}
					}

				}
			iper = x; jper = y;
			GotoXY(e, y); SetColor(0, 14); printf("  ");
			GotoXY(e, y + 1); SetColor(0, 14); printf("  ");

			for (i = 0, x = 1; i<10, x<21; i++, x = x + 2)
				for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)

				{
					GotoXY(x, y); switch (pole[i][j]) {
					case 0:if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
						   else { SetColor(0, 9); printf("  "); }break;
					case 1:if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
						   else { SetColor(0, 9); printf("  "); }break;
					case 2:SetColor(0, 12); printf("  "); break;
					case 3: SetColor(0, 11); printf("  "); break;
					}
					GotoXY(x, y + 1); switch (pole[i][j]) {
					case 0:if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
						   else { SetColor(0, 9); printf("  "); }break;
					case 1:if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
						   else { SetColor(0, 9); printf("  "); }break;
					case 2:SetColor(0, 12); printf("  "); break;
					case 3: SetColor(0, 11); printf("  "); break;
					}
				}
			x = iper; y = jper;

			udar = 0;
			for (i = 0; i<10; i++)
				for (j = 0; j<10; j++)
					if (pole[i][j] == 2 || pole[i][j] == 2)
						udar++;
			end = 0;	if (udar == 20)
			{
				f = 1; pop = 0;
			}

			if (k == 1)
			{
				udar = -1; f = 1;
			}
		}
		GotoXY(20, 20);
		printf("%d", udar);
	} while ((f != 1 || pop != 0));


	return udar;
}

int main()
{
label1:
	int pole[10][10], mypole[10][10], x, y, ui, ud[2], hod[1];
	int i, j, m, k;
	keybd_event(VK_MENU, 0x38, 0, 0); //press ALT
	keybd_event(VK_RETURN, 0x1c, 0, 0); //press ENTER
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0); //release ENTER
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0); //release ALT
	do {
		m = menu();
		ui = 0;
		if (m == 1)
		{
			SetColor(0, 0);
			system("cls");
			int f = 1;
			GotoXY(30, 10); SetColor(11, 0); printf(Rus("Расставить корабли"));
			GotoXY(13, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("автоматически")); SetColor(15, 0); printf("]");
			GotoXY(33, 13); SetColor(15, 0); printf("["); printf(Rus("вручную(открыто только в премиум режиме)")); SetColor(15, 0); printf("]");
			do {
				k = 0;
				int code = _getch();
				if (code == 224)
				{
					code = _getch();
					switch (code)
					{
					case 75: {f = f*(-1);//выбор
						if (f == 1) {
							GotoXY(13, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("автоматически")); SetColor(15, 0); printf("]");
							GotoXY(33, 13); SetColor(15, 0); printf("["); printf(Rus("вручную(открыто только в премиум режиме)")); SetColor(15, 0); printf("]");
						}
						else {
							GotoXY(13, 13); SetColor(15, 0); printf("["); printf(Rus("автоматически")); printf("]");
							GotoXY(33, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("вручную(открыто только в премиум режиме)")); SetColor(15, 0); printf("]");
						}
						break; }

					case 77: {f = f*(-1);
						if (f == 1) {
							GotoXY(13, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("автоматически")); SetColor(15, 0); printf("]");
							GotoXY(33, 13); SetColor(15, 0); printf("["); printf(Rus("вручную(открыто только в премиум режиме)")); SetColor(15, 0); printf("]");
						}
						else {
							GotoXY(13, 13); SetColor(15, 0); printf("["); printf(Rus("автоматически")); printf("]");
							GotoXY(33, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("вручную(открыто только в премиум режиме)")); SetColor(15, 0); printf("]");
						}
						break; }

					}
				}

				else {
					switch (code)
					{
					case 13: k = 1; break;
					}

				}

			} while (k == 0);

			if (f == 1) 
			{
				system("cls");
				sheeps(mypole);
			}
			else 
			{
				system("cls");
				SetColor(0, 0);
				vivod(pole);
				ui = ras(mypole);
			}
			if (ui == 0) 
			{
				SetColor(0, 0);
				system("cls");
				GotoXY(30, 10);
				SetColor(15, 0);
				
					ui == 0;
					printf(Rus("Расстановка кораблей"));

					for (i = 1; i <= 100; i++)
					{
						GotoXY(62, 15);
						SetColor(15, 0); printf("%d%%", i);
						if (i % 2 == 0)
						{
							GotoXY(10 + (i / 2), 15);
							SetColor(0, 15); printf(" ");
							sheeps(pole);
						}Sleep(50);
					}
				
				SetColor(0, 0);
				system("cls");
				f = 1;
				GotoXY(30, 10); SetColor(15, 0); printf(Rus("Кто ходит первым?"));//выбор
				GotoXY(23, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("компьютер")); SetColor(15, 0); printf("]");
				GotoXY(43, 13); SetColor(15, 0); printf("["); printf(Rus("игрок")); SetColor(15, 0); printf("]");
				do {
					k = 0;
					int code = _getch();
					if (code == 224)
					{
						code = _getch();
						switch (code)
						{
						case 75: {f = f*(-1);
							if (f == 1) {
								GotoXY(23, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("компьютер")); SetColor(15, 0); printf("]");
								GotoXY(43, 13); SetColor(15, 0); printf("["); printf(Rus("игрок")); SetColor(15, 0); printf("]");
							}
							else {
								GotoXY(23, 13); SetColor(15, 0); printf("["); printf(Rus("компьютер")); printf("]");
								GotoXY(43, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("игрок")); SetColor(15, 0); printf("]");
							}
							break; }

						case 77: {f = f*(-1);
							if (f == 1) {
								GotoXY(23, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("компьютер")); SetColor(15, 0); printf("]");
								GotoXY(43, 13); SetColor(15, 0); printf("["); printf(Rus("игрок")); SetColor(15, 0); printf("]");
							}
							else {
								GotoXY(23, 13); SetColor(15, 0); printf("["); printf(Rus("компьютер")); printf("]");
								GotoXY(43, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("игрок")); SetColor(15, 0); printf("]");
							}
							break; }

						}
					}

					else {
						switch (code)
						{
						case 13: k = 1; break;
						}

					}

				} while (k == 0);

				int chislocomp = 0, chislomy = 0;
				SetColor(15, 0);
				system("cls");
				SetColor(15, 0);
	printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xba"); printf("\t\t     "); printf("\xba\n");
	printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBC\n");


	GotoXY(40, 0); printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB\n");
	GotoXY(40, 1); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 2); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 3); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 4); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 5); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 6); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 7); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 8); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 9); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 10); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 11); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 12); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 13); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 14); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 15); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 16); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 17); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 18); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 19); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 20); printf("\xba"); printf("\t\t     "); printf("\xba\n");
	GotoXY(40, 21); printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBC\n");

				for (i = 0, x = 1; i<10, x<21; i++, x = x + 2)
					for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)

					{
						GotoXY(x, y);
						if ((j + i) % 2 != 0) 
						{ 
						   SetColor(0, 1);
						   printf("  ");
						}
						else 
						{ 
							SetColor(0, 9);
							printf("  "); }
						    GotoXY(x, y + 1);
							if ((j + i) % 2 != 0) 
							{ 
								SetColor(0, 1);
							    printf("  ");
							}
						else 
						{ 
							SetColor(0, 9);
							printf("  ");
						}
					}

				for (i = 0, x = 41; i<10, x<61; i++, x = x + 2)
					for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)

					{
						GotoXY(x, y);
						if (mypole[i][j] == 1) 
						{ 
							SetColor(0, 12);
							printf("  ");
						}
						else 
						{ 
							if ((j + i) % 2 != 0) 
							{ 
								SetColor(0, 1); 
								printf("  "); 
							} 
							else 
							{ 
								SetColor(0, 9);
								printf("  "); 
							} 
						}
						GotoXY(x, y + 1);
						if (mypole[i][j] == 1) 
						{
							SetColor(0, 12);
							printf("  ");
						}
						else 
						{ 
							if ((j + i) % 2 != 0) 
							{ 
								SetColor(0, 1);
								printf("  ");
							}
							else
							{ 
								SetColor(0, 9);
								printf("  ");
							} 
						}
					}

				GotoXY(22, 8); SetColor(15, 0); printf(Rus("потверждение-enter"));
				GotoXY(23, 9); SetColor(15, 0); printf(Rus("наведение-стрелки"));
				GotoXY(26, 10); SetColor(15, 0); printf(Rus("Выход-Esc"));
				GotoXY(22, 12); SetColor(15, 0); printf(Rus("датчик трансляции"));
				GotoXY(23, 13); printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB\n");
				GotoXY(23, 14); printf("\xba"); printf("\t      "); printf("\xba\n");
				GotoXY(23, 15); printf("\xba"); printf("\t      "); printf("\xba\n");
				GotoXY(23, 16); printf("\xba"); printf("\t      "); printf("\xba\n");
				GotoXY(23, 17); printf("\xba"); printf("\t      "); printf("\xba\n");
				GotoXY(23, 18); printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBC\n");
				ud[0] = -3; ud[1] = -3;



				while (chislocomp<20 && chislomy<20)
				{
					if (chislomy == -1) 
					{ 
						break;
					}
					if (chislocomp != 20 && chislomy != 20)
					{
						if (f == 1)
						{
							chislocomp = comp(mypole, chislocomp, ud, hod);
							f = f*(-1);
						}
						else
						{
							chislomy = player(pole, chislomy);
							f = f*(-1);
						}
					}
				}
				SetColor(0, 0); system("cls");

				if (chislocomp == 20)
				{
					GotoXY(33, 14); SetColor(0, 12);
					printf(Rus("Разгром!")); fflush(stdin); _getch(); fflush(stdin);
				}
				if (chislomy == 20)
				{
					GotoXY(33, 14); SetColor(0, 12);
					printf(Rus("Победа!")); fflush(stdin); _getch(); fflush(stdin);
				}

			}
		}
		vivod(mypole);
	} while (m == 1);

}




