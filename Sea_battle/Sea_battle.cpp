// ConsoleApplication25.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include <stdafx.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

HANDLE hConsole;
//HANDLE hStdout, hStdin;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void GotoXY(int X, int Y)
{
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}

enum ConsoleColor            //Iiaee??aiea oaaoia
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
char s1[256];                         //Iiaee??aiea ?onneie eiae?iaee
char *Rus(char *s2)
{
	AnsiToOem(s2, s1); return s1;
}



int sheeps(int pole[10][10])
{
	int i, j, f, k, r;
	int rand_chislo, rand_chislo1, ts, s; //neo?aeiua ?enea

										  /*  char kr=219;
										  char a=218,b=196,c=191,     //ia?aiaiiua aey ia?aoe eeaoie
										  d=179,
										  e=192, g=217;   */
	srand(time(NULL));      //ooieoey aey aaia?aoee neo?aeiuo ?enae

	for (i = 0; i<10; i++)
		for (j = 0; j<10; j++)
			pole[i][j] = 0;

	do {
		f = 0;                                 //?annoaiiaea ?aoaa?iiai ei?aaey
		rand_chislo = 0 + rand() % 10;
		rand_chislo1 = 0 + rand() % 10;

		ts = 1 + rand() % 4;

		if (ts == 1) { for (i = 0; i<3; i++) if (rand_chislo == i)f = 1; }
		if (ts == 2) { for (i = 7; i<10; i++) if (rand_chislo == i)f = 1; }
		if (ts == 3) { for (i = 0; i<3; i++) if (rand_chislo1 == i)f = 1; }
		if (ts == 4) { for (i = 7; i<10; i++) if (rand_chislo1 == i)f = 1; }
	} while (f == 1);
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






	for (k = 0; k<3; k++)                                       //?annoaiiaea aaieiuo ei?aaeae
	{
		do {
			f = 0;
			rand_chislo = 0 + rand() % 10;
			rand_chislo1 = 0 + rand() % 10;

			ts = 1 + rand() % 4;

			if (ts == 1) {
				if (rand_chislo != 0) {
					for (i = rand_chislo - 2; i<rand_chislo + 2; i++)
						for (j = rand_chislo1 - 1; j <= rand_chislo1 + 1; j++)
						{
							if (pole[i][j] != 0) { f = 1; }
						}
				}
				else f = 1;
			}
			if (ts == 2) {
				if (rand_chislo != 9) {
					for (i = rand_chislo - 1; i <= rand_chislo + 2; i++)
						for (j = rand_chislo1 - 1; j <= rand_chislo1 + 1; j++)
						{
							if (pole[i][j] != 0) { f = 1; }
						}
				}
				else f = 1;
			}
			if (ts == 3) {
				if (rand_chislo1 != 0) {
					for (i = rand_chislo - 1; i <= rand_chislo + 1; i++)
						for (j = rand_chislo1 - 2; j <= rand_chislo1 + 1; j++)
						{
							if (pole[i][j] != 0) { f = 1; }
						}
				}
				else f = 1;
			}
			if (ts == 4) {
				if (rand_chislo1 != 9) {
					for (i = rand_chislo - 1; i <= rand_chislo + 1; i++)
						for (j = rand_chislo1 - 1; j <= rand_chislo1 + 2; j++)
						{
							if (pole[i][j] != 0) { f = 1; }
						}
				}
				else f = 1;
			}
		} while (f == 1);
		switch (ts) {
		case 1: pole[rand_chislo][rand_chislo1] = 1; pole[rand_chislo - 1][rand_chislo1] = 1; break;
		case 2: pole[rand_chislo][rand_chislo1] = 1; pole[rand_chislo + 1][rand_chislo1] = 1; break;
		case 3: pole[rand_chislo][rand_chislo1] = 1; pole[rand_chislo][rand_chislo1 - 1] = 1; break;
		case 4: pole[rand_chislo][rand_chislo1] = 1; pole[rand_chislo][rand_chislo1 + 1] = 1; break;
		}


	}

	for (k = 0; k<2; k++)                                       //?annoaiiaea o?ieiuo ei?aaeae
	{
		do {
			f = 0;
			rand_chislo = 0 + rand() % 10;
			rand_chislo1 = 0 + rand() % 10;

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



	for (i = 0; i<4; i++)                          //?annoaiiaea iae?iuo ei?aaeae
	{
		do {
			rand_chislo = 0 + rand() % 10;
			rand_chislo1 = 0 + rand() % 10;
		} while (pole[rand_chislo][rand_chislo1] != 0 || pole[rand_chislo + 1][rand_chislo1] != 0 || pole[rand_chislo - 1][rand_chislo1] != 0 || pole[rand_chislo][rand_chislo1 + 1] != 0 || pole[rand_chislo][rand_chislo1 - 1] != 0 || pole[rand_chislo + 1][rand_chislo1 + 1] != 0 || pole[rand_chislo - 1][rand_chislo1 - 1] != 0 || pole[rand_chislo + 1][rand_chislo1 - 1] != 0 || pole[rand_chislo - 1][rand_chislo1 + 1] != 0);

		pole[rand_chislo][rand_chislo1] = 1;
	}
	return pole[10][10];
}

/*int vivod(int pole[10][10])
{
int i,j,x,y;


for (i=0,x=1;i<10,x<21;i++,x=x+2)
for (j=0,y=1;j<10,y<21;j++,y=y+2)

{
GotoXY(x,y);if (pole[i][j]==0) {if((j+i)%2!=0) {SetColor(0,1);printf ("  ");} else{SetColor(0,9);printf ("  ");}}else  { SetColor(0,14);printf ("  ");}
GotoXY(x,y+1);if (pole[i][j]==0) { if((j+i)%2!=0) {SetColor(0,1);printf ("  ");} else{SetColor(0,9);printf ("  ");}}else {  SetColor(0,14);printf ("  ");}
}


return 0;
}
*/
void write()
{
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
}

int bonus(int pole[10][10])
{
	int k, rand_chislo, rand_chislo1;
	k = 0;
	do {
		rand_chislo = 0 + rand() % 10;
		rand_chislo1 = 0 + rand() % 10;
		if (pole[rand_chislo][rand_chislo1] == 0)
		{
			pole[rand_chislo][rand_chislo1] = 9;
			k++;
		}
	} while (k != 3);
	return pole[10][10];
}
int atomic_bonus(int pole[10][10])  // your superskill
{
	int k, rand_chislo, rand_chislo1;
	k = 0;
	do
	{
		rand_chislo = 0 + rand() % 10;
		rand_chislo1 = 0 + rand() % 10;
		if (pole[rand_chislo][rand_chislo1] == 0)
		{
			pole[rand_chislo][rand_chislo1] = 10;
			k++;
		}
	} while (k != 1);
	return pole[10][10];
}

int sabatage_bonus(int pole[10][10])
{
	int k, rand_chislo, rand_chislo1;
	k = 0;
	do
	{
		rand_chislo = 0 + rand() % 10;
		rand_chislo1 = 0 + rand() % 10;
		if (pole[rand_chislo][rand_chislo1] == 0)
		{
			pole[rand_chislo][rand_chislo1] = 11;
			k++;
		}
	} while (k != 2);
	return pole[10][10];
}

int sabatage(int pole[10][10])
{
	int k, rand_chislo, rand_chislo1;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			if (pole[i][j] == 1)
			{
				pole[i][j] = 30;
				return 0;
			}
		}
	return 0;
}



void ras_pole1(int mypole[10][10], int i, int j, int x, int y)
{
	GotoXY(x, y);
	if (mypole[i][j] == 1)
	{
		SetColor(0, 12);
		printf("  ");
	}
	else
	{
		if ((i + j) % 2 != 0)
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
		if ((i + j) % 2 != 0)
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
void ras_pole2(int mypole[10][10], int i, int j, int x, int y)
{
	GotoXY(x, y);  if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
	else { SetColor(0, 9); printf("  "); }
	GotoXY(x, y + 1); if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
	else { SetColor(0, 9); printf("  "); }
}
void ras_pole3(int mypole[10][10], int x, int y)
{
	GotoXY(x, y); SetColor(0, 14); printf("  ");
	GotoXY(x, y + 1); SetColor(0, 14); printf("  ");
}
int ras(int mypole[10][10])
{
	system("cls");
	int i, j, x, y, u, f, e, w, nap, ui;
	write();

	for (i = 0, x = 1; i<10, x<21; i++, x = x + 2)
		for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)

		{
			ras_pole2(mypole, i, j, x, y);
		}

	for (i = 0; i<10; i++)
		for (j = 0; j<10; j++)
			mypole[i][j] = 0;


	GotoXY(24, 7); SetColor(15, 0); printf(Rus("�������-space"));
	GotoXY(24, 8); SetColor(15, 0); printf(Rus("�������-enter"));
	GotoXY(22, 9); SetColor(15, 0); printf(Rus("����������-�������"));
	GotoXY(23, 10); SetColor(15, 0); printf(Rus("����� � ����-Esc"));
	ui = 0;
	for (u = 1; u<5; u++)
	{
		if (ui == 0)
			for (i = 0, x = 41; i < 10, x < 61; i++, x = x + 2)
				for (j = 0, y = 1; j < 10, y < 21; j++, y = y + 2)
					ras_pole2(mypole, i, j, x, y);

		switch (u)
		{
		case 1:
		{   x = 41; y = nap = 1;
		i = j = 0;
		for (e = x; e<x + 8; e = e + 2)
		{

			ras_pole3(mypole, e, y);
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
								ras_pole2(mypole, i, j, e, y);
							}
							y = y - 2;
							for (e = x; e<x + 8; e = e + 2)
							{
								ras_pole3(mypole, e, y);
							}
						}
						else
						{
							if (y != 33) {
								for (e = y; e<y + 8; e = e + 2)
								{
									i = (x - 40) / 2;
									j = e / 2;
									ras_pole2(mypole, i, j, x, e);
								}
								y = y - 2;
								for (e = y; e<y + 8; e = e + 2)
								{
									ras_pole3(mypole, x, e);
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
								ras_pole2(mypole, i, j, e, y);
							}
							x = x + 2;
							for (e = x; e<x + 8; e = e + 2)
							{
								ras_pole3(mypole, e, y);

							}
						}
					}
					else {
						if (x != 59) {
							for (e = y; e<y + 8; e = e + 2)
							{
								i = (x - 40) / 2;
								j = e / 2;
								ras_pole2(mypole, i, j, x, e);
							}
							x = x + 2;
							for (e = y; e<y + 8; e = e + 2)
							{
								ras_pole3(mypole, x, e);
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
								ras_pole2(mypole, i, j, e, y);
							}
							y = y + 2;
							for (e = x; e<x + 8; e = e + 2)
							{
								ras_pole3(mypole, e, y);
							}
						}
					}
					else {
						if (y != 13) {
							for (e = y; e<y + 8; e = e + 2)
							{
								i = (x - 40) / 2;
								j = e / 2;
								ras_pole2(mypole, i, j, x, e);
							}
							y = y + 2;
							for (e = y; e<y + 8; e = e + 2)
							{
								ras_pole3(mypole, x, e);
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
							ras_pole2(mypole, i, j, e, y);
						}
						x = x - 2;
						for (e = x; e<x + 8; e = e + 2)
						{
							ras_pole3(mypole, e, y);

						}
					}
				}
				else {
					if (x != 41) {
						for (e = y; e<y + 8; e = e + 2)
						{
							i = (x - 40) / 2;
							j = e / 2;
							ras_pole1(mypole, i, j, x, e);

						}
						x = x - 2;
						for (e = y; e<y + 8; e = e + 2)
						{
							ras_pole3(mypole, x, e);
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
								ras_pole1(mypole, i, j, x, e);
							}



							for (e = x; e<x + 8; e = e + 2)
							{
								ras_pole3(mypole, e, y);

							}

						}
						else {
							for (e = x; e<x + 8; e = e + 2) {
								i = (e - 40) / 2;
								j = y / 2;
								ras_pole1(mypole, i, j, e, y);
							}

							for (e = y; e<y + 8; e = e + 2)
							{
								ras_pole3(mypole, x, e);

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
						ras_pole1(mypole, i, j, x, y);
					}
				x = 41; y = nap = 1;
				i = j = 0;
				for (e = x; e<x + 6; e = e + 2)
				{
					ras_pole3(mypole, e, y);
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
										ras_pole1(mypole, i, j, e, y);
									}
									y = y - 2;
									for (e = x; e<x + 6; e = e + 2)
									{
										ras_pole3(mypole, e, y);
									}
								}
								else
								{
									if (y != 33) {
										for (e = y; e<y + 6; e = e + 2)
										{
											i = (x - 40) / 2;
											j = e / 2;
											ras_pole1(mypole, i, j, x, e);
										}
										y = y - 2;
										for (e = y; e<y + 6; e = e + 2)
										{
											ras_pole3(mypole, x, e);
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
										ras_pole1(mypole, i, j, e, y);
									}
									x = x + 2;
									for (e = x; e<x + 6; e = e + 2)
									{
										ras_pole3(mypole, e, y);

									}
								}
							}
							else {
								if (x != 59) {
									for (e = y; e<y + 6; e = e + 2)
									{
										i = (x - 40) / 2;
										j = e / 2;
										ras_pole1(mypole, i, j, x, e);
									}
									x = x + 2;
									for (e = y; e<y + 6; e = e + 2)
									{
										ras_pole3(mypole, x, e);
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
										ras_pole1(mypole, i, j, e, y);
									}
									y = y + 2;
									for (e = x; e<x + 6; e = e + 2)
									{
										ras_pole3(mypole, e, y);
									}
								}
							}
							else {
								if (y != 15) {
									for (e = y; e<y + 6; e = e + 2)
									{
										i = (x - 40) / 2;
										j = e / 2;
										ras_pole1(mypole, i, j, x, e);
									}
									y = y + 2;
									for (e = y; e<y + 6; e = e + 2)
									{
										ras_pole3(mypole, x, e);
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
									ras_pole1(mypole, i, j, e, y);
								}
								x = x - 2;
								for (e = x; e<x + 6; e = e + 2)
								{
									ras_pole3(mypole, e, y);

								}
							}
						}
						else {
							if (x != 41) {
								for (e = y; e<y + 6; e = e + 2)
								{
									i = (x - 40) / 2;
									j = e / 2;
									ras_pole1(mypole, i, j, x, e);
								}
								x = x - 2;
								for (e = y; e<y + 6; e = e + 2)
								{
									ras_pole3(mypole, x, e);
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
										ras_pole1(mypole, i, j, x, e);
									}



									for (e = x; e<x + 6; e = e + 2)
									{
										ras_pole3(mypole, e, y);

									}

								}
								else {
									for (e = x; e<x + 6; e = e + 2) {
										i = (e - 40) / 2;
										j = y / 2;
										ras_pole1(mypole, i, j, e, y);
									}

									for (e = y; e<y + 6; e = e + 2)
									{
										ras_pole3(mypole, x, e);

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
						ras_pole1(mypole, i, j, x, y);
					}
				x = 41; y = nap = 1;
				i = j = 0;
				for (e = x; e<x + 4; e = e + 2)
				{
					ras_pole3(mypole, e, y);
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
										ras_pole1(mypole, i, j, e, y);
									}
									y = y - 2;
									for (e = x; e<x + 4; e = e + 2)
									{
										ras_pole3(mypole, e, y);
									}
								}
								else
								{
									if (y != 33) {
										for (e = y; e<y + 4; e = e + 2)
										{
											i = (x - 40) / 2;
											j = e / 2;
											ras_pole1(mypole, i, j, x, e);
										}
										y = y - 2;
										for (e = y; e<y + 4; e = e + 2)
										{
											ras_pole3(mypole, x, e);
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
										ras_pole1(mypole, i, j, e, y);
									}
									x = x + 2;
									for (e = x; e<x + 4; e = e + 2)
									{
										ras_pole3(mypole, e, y);

									}
								}
							}
							else {
								if (x != 59) {
									for (e = y; e<y + 4; e = e + 2)
									{
										i = (x - 40) / 2;
										j = e / 2;
										ras_pole1(mypole, i, j, x, e);
									}
									x = x + 2;
									for (e = y; e<y + 4; e = e + 2)
									{
										ras_pole3(mypole, x, e);
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
										ras_pole1(mypole, i, j, e, y);
									}
									y = y + 2;
									for (e = x; e<x + 4; e = e + 2)
									{
										ras_pole3(mypole, e, y);
									}
								}
							}
							else {
								if (y != 17) {
									for (e = y; e<y + 4; e = e + 2)
									{
										i = (x - 40) / 2;
										j = e / 2;
										ras_pole1(mypole, i, j, x, e);
									}
									y = y + 2;
									for (e = y; e<y + 4; e = e + 2)
									{
										ras_pole3(mypole, x, e);

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
									ras_pole1(mypole, i, j, e, y);
								}
								x = x - 2;
								for (e = x; e<x + 4; e = e + 2)
								{
									ras_pole3(mypole, e, y);

								}
							}
						}
						else {
							if (x != 41) {
								for (e = y; e<y + 4; e = e + 2)
								{
									i = (x - 40) / 2;
									j = e / 2;
									ras_pole1(mypole, i, j, x, e);
								}
								x = x - 2;
								for (e = y; e<y + 4; e = e + 2)
								{
									ras_pole3(mypole, x, e);
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
										ras_pole1(mypole, i, j, x, e);
									}



									for (e = x; e<x + 4; e = e + 2)
									{
										ras_pole3(mypole, e, y);

									}

								}
								else {
									for (e = x; e<x + 4; e = e + 2) {
										i = (e - 40) / 2;
										j = y / 2;
										ras_pole1(mypole, i, j, e, y);
									}

									for (e = y; e<y + 4; e = e + 2)
									{
										ras_pole3(mypole, x, e);
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
						ras_pole1(mypole, i, j, x, y);
					}
				x = 41; y = 1;
				i = j = 0;
				e = x;
				{

					ras_pole3(mypole, e, y);
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
									ras_pole1(mypole, i, j, e, y);
								}
								y = y - 2;
								e = x;
								{
									ras_pole3(mypole, e, y);
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
									ras_pole1(mypole, i, j, e, y);
								}
								x = x + 2;
								e = x;
								{
									ras_pole3(mypole, e, y);

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
									ras_pole1(mypole, i, j, e, y);
								}
								y = y + 2;
								e = x;
								{
									ras_pole3(mypole, e, y);
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
									ras_pole1(mypole, i, j, e, y);
								}
								x = x - 2;
								e = x;
								{
									ras_pole3(mypole, e, y);

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
	GotoXY(30, 10); SetColor(15, 0); printf(Rus("������� ����"));
	GotoXY(30, 12); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("����� ����")); SetColor(15, 0); printf("]");
	GotoXY(32, 13); SetColor(15, 0); printf("["); printf(Rus("�����")); SetColor(15, 0); printf("]");
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
					GotoXY(30, 12); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("����� ����")); SetColor(15, 0); printf("]");
					GotoXY(32, 13); SetColor(15, 0); printf(Rus("[�����]"));
				}
				else {
					GotoXY(30, 12); SetColor(15, 0); printf("["); printf(Rus("����� ����")); printf("]");
					GotoXY(32, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("�����")); SetColor(15, 0); printf("]");
				}
				break; }

			case 72: {f = f*(-1);
				if (f == 1) {
					GotoXY(30, 12); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("����� ����")); SetColor(15, 0); printf("]");
					GotoXY(32, 13); SetColor(15, 0); printf(Rus("[�����]"));
				}
				else {
					GotoXY(30, 12); SetColor(15, 0); printf("["); printf(Rus("����� ����")); printf("]");
					GotoXY(32, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("�����")); SetColor(15, 0); printf("]");
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
	return f;
}

void comp_yourpole(int mypole[10][10], int x, int y, int i, int j)
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
	case 8:SetColor(0, 10); printf("  "); break;
	}
}

void comp_mimo(int* prj, int* per, int* f)
{
	GotoXY(28, 16); SetColor(15, 0);
	Sleep(1000);
	printf(Rus("����!"));
	*prj = 1;
	*per = 1;
	*f -= 1;
}

void comp_popal(int* udar, int* hod[1], int* prj, int* per)
{
	GotoXY(28, 16);
	SetColor(15, 0);
	printf(Rus("�����!"));
	udar++;
	Sleep(1000);
	printf("\x07");
	*prj = 1;
	*per = 1;
	*hod[0] = 1;
}

void comp_bonus(int* hod[1], int* prj, int* per, int* f)
{
	GotoXY(28, 16); SetColor(15, 0);
	printf(Rus("�����!"));
	Sleep(1000);
	printf("\x07");
	*f += 1;
	*prj = 1;
	*per = 1;
	*hod[0] = 1;
}

int comp(int mypole[10][10], int udar, int ud[2], int hod[1])
{

	int i, j, f, per, n, m, x, y, k, str, sto, h, g;
	int pri, prj;
	srand(time(NULL));
	GotoXY(24, 14);
	SetColor(9, 0);
	printf(Rus("  ����� ���� "));
	f = 0;
	do {
		per = 0;
		k = 0;
		GotoXY(28, 16);
		SetColor(15, 0);
		printf(Rus("      "));
		Sleep(1000);
		h = 0;
		if (hod[0] == 5)
		{
			for (n = ud[0] - 1; n <= ud[0] + 1 && n<10; n++)
				for (m = ud[1] - 1; m <= ud[1] + 1 && m<10; m++)
					if ((mypole[n][m] == 1) || (mypole[n][m] == 9))
						h = 1;
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
				per = 1;
				srand(time(NULL));
				do {
					pri = 1 + rand() % 4; prj = 0;
					switch (pri) {
					case 1:
					{if (mypole[ud[0] - 1][ud[1]] == 0 && ud[0] != 0) {
						mypole[ud[0] - 1][ud[1]] = 3;
						comp_mimo(&prj, &per, &f);
					}
					if (mypole[ud[0] - 1][ud[1]] == 1 && ud[0] != 0)
					{
						mypole[ud[0] - 1][ud[1]] = 4;
						comp_popal(&udar, &hod, &prj, &per);
					}
					if (mypole[ud[0] - 1][ud[1]] == 9 && ud[0] != 0)
					{
						mypole[ud[0] - 1][ud[1]] = 8;
						comp_bonus(&hod, &prj, &per, &f);
					}
					break; }
					case 2:
					{
						if (mypole[ud[0] + 1][ud[1]] == 0 && ud[0] != 9)
						{
							mypole[ud[0] + 1][ud[1]] = 3;
							comp_mimo(&prj, &per, &f);
						}
						if (mypole[ud[0] + 1][ud[1]] == 1 && ud[0] != 9)
						{
							mypole[ud[0] + 1][ud[1]] = 4;
							comp_popal(&udar, &hod, &prj, &per);
						}
						if (mypole[ud[0] + 1][ud[1]] == 9 && ud[0] != 0)
						{
							mypole[ud[0] + 1][ud[1]] = 8;
							comp_bonus(&hod, &prj, &per, &f);
						}
						break; }
					case 3: {
						if (mypole[ud[0]][ud[1] - 1] == 0 && ud[1] != 0)
						{
							mypole[ud[0]][ud[1] - 1] = 3;
							comp_mimo(&prj, &per, &f);
						}
						if (mypole[ud[0]][ud[1] - 1] == 1 && ud[1] != 0)
						{
							mypole[ud[0]][ud[1] - 1] = 4;
							comp_popal(&udar, &hod, &prj, &per);
						}
						if (mypole[ud[0]][ud[1] - 1] == 9 && ud[0] != 0)
						{
							mypole[ud[0]][ud[1] - 1] = 8;
							comp_bonus(&hod, &prj, &per, &f);
						}
						break; }
					case 4: {
						if (mypole[ud[0]][ud[1] + 1] == 0 && ud[1] != 9)
						{
							mypole[ud[0]][ud[1] + 1] = 3;
							comp_mimo(&prj, &per, &f);
						}
						if (mypole[ud[0]][ud[1] + 1] == 1 && ud[1] != 9)
						{
							mypole[ud[0]][ud[1] + 1] = 4;
							comp_popal(&udar, &hod, &prj, &per);
						}
						if (mypole[ud[0]][ud[1] + 1] == 9 && ud[0] != 0)
						{
							mypole[ud[0]][ud[1] + 1] = 8;
							comp_bonus(&hod, &prj, &per, &f);
						}
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
								h = 1;
								mypole[i - 1][j] = 5;
								GotoXY(28, 16);
								SetColor(15, 0);
								printf(Rus("�����!"));
								Sleep(1000);
								printf("\x07");
								for (i = 0, x = 41; i<10, x<61; i++, x = x + 2)
									for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)
										comp_yourpole(mypole, x, y, i, j);
							}
						}
						if (i<9) {
							if (mypole[i + 1][j] == 1) {
								h = 1;
								mypole[i + 1][j] = 5;
								GotoXY(28, 16);
								SetColor(15, 0);
								printf(Rus("�����!"));
								Sleep(1000);
								printf("\x07");
								for (i = 0, x = 41; i<10, x<61; i++, x = x + 2)
									for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)
										comp_yourpole(mypole, x, y, i, j);
							}
						}
						if (j>0) {
							if (mypole[i][j - 1] == 1)
							{
								h = 1;
								mypole[i][j - 1] = 5;
								GotoXY(28, 16);
								SetColor(15, 0);
								printf(Rus("�����!"));
								Sleep(1000);
								printf("\x07");
								for (i = 0, x = 41; i<10, x<61; i++, x = x + 2)
									for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)
										comp_yourpole(mypole, x, y, i, j);
							}
						}
						if (j<9) {
							if (mypole[i][j + 1] == 1)
							{
								h = 1;
								mypole[i][j + 1] = 5;
								GotoXY(28, 16);
								SetColor(15, 0);
								printf(Rus("�����!"));
								Sleep(1000);
								printf("\x07");
								for (i = 0, x = 41; i<10, x<61; i++, x = x + 2)
									for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)
										comp_yourpole(mypole, x, y, i, j);
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
				comp_yourpole(mypole, x, y, i, j);

		if (per == 0)
		{
			do {
				i = 0 + rand() % 10;
				j = 0 + rand() % 10;
			} while (mypole[i][j]>1);
			if (mypole[i][j] == 1)
			{
				mypole[i][j] = 4;
				ud[0] = i;
				ud[1] = j;
				GotoXY(28, 16);
				SetColor(15, 0);
				printf(Rus("�����!"));
				hod[0] = 5;
				Sleep(1000);
				printf("\x07");
			}
			if (mypole[i][j] == 9)
			{
				mypole[i][j] = 8;
				ud[0] = i;
				ud[1] = j;
				GotoXY(28, 16);
				SetColor(15, 0);
				printf(Rus("�����!"));
				hod[0] = 5;
				Sleep(1000);
				printf("\x07");
				f++;
			}
			if (mypole[i][j] == 0)
			{
				mypole[i][j] = 3;
				f--;
				GotoXY(28, 16);
				SetColor(15, 0);
				printf(Rus("����!"));
				Sleep(1000);
			}

		}

		Sleep(1000);
		for (i = 0, x = 41; i<10, x<61; i++, x = x + 2)
			for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)
				comp_yourpole(mypole, x, y, i, j);
	} while (f >= 0);

	return udar;
}
int Exit(int code)
{
	int k = 0;
	int f = 1;
	int vih = 0;
	GotoXY(24, 14); SetColor(15, 0); printf(Rus("    �����?    "));
	GotoXY(24, 16); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("��")); SetColor(15, 0); printf("]  ");
	GotoXY(31, 16); SetColor(15, 0); printf("  ["); printf(Rus("���")); SetColor(15, 0); printf("]");
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
					GotoXY(24, 16); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("��")); SetColor(15, 0); printf("]  ");
					GotoXY(31, 16); SetColor(15, 0); printf("  ["); printf(Rus("���")); SetColor(15, 0); printf("]");
				}
				else {
					GotoXY(24, 16); SetColor(15, 0); printf("["); printf(Rus("��")); printf("]  ");
					GotoXY(31, 16); SetColor(15, 0); printf("  ["); SetColor(0, 2); printf(Rus("���")); SetColor(15, 0); printf("]");
				}
				break; }

			case 77: {f = f*(-1);
				if (f == 1) {
					GotoXY(24, 16); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("��")); SetColor(15, 0); printf("]  ");
					GotoXY(31, 16); SetColor(15, 0); printf("  ["); printf(Rus("���")); SetColor(15, 0); printf("]");
				}
				else {
					GotoXY(24, 16); SetColor(15, 0); printf("["); printf(Rus("��")); printf("]  ");
					GotoXY(31, 16); SetColor(15, 0); printf("  ["); SetColor(0, 2); printf(Rus("���")); SetColor(15, 0); printf("]");
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
	return k;
}

int moving(int pole[10][10], int i, int j, int x, int y)
{
	GotoXY(x, y);
	if (pole[i][j] == 3)
	{
		SetColor(0, 11);
		printf("  ");
	}
	else

	{
		if (pole[i][j] == 2)
		{
			SetColor(0, 12);
			printf("  ");
		}
		else
		{
			if (pole[i][j] == 30)
			{
				SetColor(0, 6); printf("  ");
			}
			if (pole[i][j] == 6)
			{
				SetColor(0, 5); printf("  ");
			}
			if (pole[i][j] == 8)
			{
				SetColor(0, 10); printf("  ");
			}
			if (pole[i][j] == 7)
			{
				SetColor(0, 15); printf("  ");
			}
			if ((i + j) % 2 != 0)
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
	GotoXY(x, y + 1);
	if (pole[i][j] == 3)
	{
		SetColor(0, 11);
		printf("  ");
	}
	else
	{
		if (pole[i][j] == 2)
		{
			SetColor(0, 12);
			printf("  ");
		}
		else
		{
			if (pole[i][j] == 30)
			{
				SetColor(0, 6); printf("  ");
			}
			if (pole[i][j] == 8)
			{
				SetColor(0, 10); printf("  ");
			}
			if (pole[i][j] == 6)
			{
				SetColor(0, 5); printf("  ");
			}
			if ((i + j) % 2 != 0)
			{
				SetColor(0, 1); printf("  ");
			}
			else
			{
				SetColor(0, 9);
				printf("  ");
			}
		}
	}
	return 0;
}

void moving(int x, int y)
{
	GotoXY(x, y);
	SetColor(0, 14);
	printf("  ");
	GotoXY(x, y + 1);
	SetColor(0, 14);
	printf("  ");

}

int player(int pole[10][10], int udar)
{
	srand(time(NULL));
	GotoXY(27, 16);
	SetColor(0, 0);
	printf(Rus("        "));
	int i, j, x, y, f, e, k = 0, pop, iper, jper, vih, end;
	for (i = 0, x = 1; i<10, x<21; i++, x = x + 2)
		for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)
			moving(pole, i, j, x, y);
	x = 1;
	y = 1;
	i = j = 0;
	e = 1;
	f = 0;
	pop = 1;
	moving(e, y);
	do {
		GotoXY(24, 14);
		SetColor(12, 0);
		printf(Rus("  ����� ����� "));
		int code = _getch();
		if (code == 224)
		{
			GotoXY(27, 16);
			SetColor(0, 0);
			printf(Rus("        "));
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
						moving(pole, i, j, x, y);
					}
					y = y - 2;
					e = x;
					moving(e, y);
				}
				break;
			}
			case 77:
			{
				if (x != 19)
				{
					e = x;
					i = e / 2;
					j = y / 2;
					moving(pole, i, j, x, y);
					x = x + 2;
					e = x;
					moving(e, y);
				}
				break;
			}
			case 80:
			{
				if (y != 19)
				{
					e = x;
					i = e / 2;
					j = y / 2;
					moving(pole, i, j, x, y);
					y = y + 2;
					e = x;
					moving(e, y);
				}
				break;
			}
			case 75:
			{
				if (x != 1)
				{
					e = x;
					i = e / 2;
					j = y / 2;
					moving(pole, i, j, x, y);
					x = x - 2;
					e = x;
					moving(e, y);
				}
				break;
			}
			}
		}
		else {
			switch (code) {
			case 13: {
				int pr = 0;

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
						pole[i][j] = 3;
						GotoXY(28, 16);
						SetColor(15, 0);
						printf(Rus("����!"));
						pop--;
					}
					/*	else if (pole[i][j] == 10 )
					{
					pole[i][j] = 7;
					printf("\x07");
					GotoXY(27, 16);
					SetColor(15, 0);
					printf(Rus("�����!!!"));
					}*/
					else if (pole[i][j] == 11)
					{
						pole[i][j] = 6;
						printf("\x07");
						GotoXY(27, 16);
						SetColor(15, 0);
						printf(Rus("�������!!!"));
						sabatage(pole);
						Sleep(500);
						GotoXY(27, 16);
						printf(Rus("          "));
					}
					else if (pole[i][j] == 9)
					{
						pole[i][j] = 8;
						printf("\x07");
						GotoXY(27, 16);
						SetColor(15, 0);
						printf(Rus("�����!"));
						pop++;
					}
					else if ((pole[i][j] == 1) || (pole[i][j] == 30))
					{
						pole[i][j] = 2;
						printf("\x07");
						GotoXY(27, 16);
						SetColor(15, 0);
						printf(Rus("�����!"));
						udar++;
					}
				}
				break;
			}
			case 27:
			{
				k = Exit(code);
				break;
			}
			}
			int mas[20][2], flag, sh = 0, a, b;
			for (i = 0; i<10; i++)
				for (j = 0; j<10; j++)
				{
					if (pole[i][j] == 1)
					{
						if (i>0)
							if (pole[i - 1][j] == 2) {
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
			/*
			for (i = 0; i<10; i++)
			for (j = 0; j<10; j++)
			{
			b = 0;
			if (pole[i][j] == 7)
			{


			if (i>0)
			{
			if (pole[i - 1][j] == 0)
			pole[i - 1][j] = 3;
			else if (pole[i - 1][j] == 2)
			{
			pole[i - 1][j] = 5;
			udar++;
			}
			else if (pole[i - 1][j] == 9)
			{
			pole[i - 1][j] = 8;
			pop++;
			}
			else pole[i - 1][j] = 3;

			}
			if (i<9) {
			if (pole[i + 1][j] == 0)
			pole[i + 1][j] = 3;
			else if (pole[i + 1][j] == 2)
			{
			pole[i + 1][j] = 5;
			udar++;
			}
			else if (pole[i + 1][j] == 9)
			{
			pole[i + 1][j] = 8;
			pop++;
			}
			else pole[i - 1][j] = 3;
			}
			if (j>0) {
			if (pole[i][j - 1] == 0)
			pole[i][j - 1] = 3;
			else if (pole[i][j - 1] == 2)
			{
			pole[i][j - 1] = 5;
			udar++;
			}
			else if (pole[i][j - 1] == 9)
			{
			pole[i][j - 1] = 8;
			pop++;
			}
			else pole[i][j - 1] = 3;
			}
			if (j < 9) {

			if (pole[i - 1][j + 1] == 0)
			pole[i - 1][j + 1] = 3;
			else if (pole[i][j + 1] == 2)
			{
			pole[i - 1][j + 1] = 5;
			udar++;
			}
			else if (pole[i - 1][j + 1] == 9)
			{
			pole[i - 1][j + 1] = 8;
			pop++;
			}
			else pole[i - 1][j + 1] = 3;
			}
			if (i>0 && j>0) {

			if (pole[i - 1][j - 1] == 0)
			pole[i - 1][j - 1] = 3;
			else if (pole[i - 1][j - 1] == 2)
			{
			pole[i - 1][j - 1] = 5;
			udar++;
			}
			else if (pole[i - 1][j - 1] == 9)
			{
			pole[i - 1][j - 1] = 8;
			pop++;
			}
			else pole[i - 1][j - 1] = 3; }
			if (i>0 && j<9) {
			if (pole[i - 1][j + 1] == 0)
			pole[i - 1][j + 1] = 3;
			else if (pole[i - 1][j + 1] == 2)
			{
			pole[i - 1][j + 1] = 5;
			udar++;
			}
			else if (pole[i - 1][j + 1] == 9)
			{
			pole[i - 1][j + 1] = 8;
			pop++;
			}
			else pole[i - 1][j + 1] = 3; }
			if (i<9 && j<9) {

			if (pole[i + 1][j + 1] == 0)
			pole[i + 1][j + 1] = 3;
			else if (pole[i + 1][j + 1] == 2)
			{
			pole[i + 1][j + 1] = 5;
			udar++;
			}
			else if (pole[i + 1][j + 1] == 9)
			{
			pole[i + 1][j + 1] = 8;
			pop++;
			}
			else pole[i][j - 1] = 3; }
			if (i<9 && j>0) {

			if (pole[i + 1][j - 1] == 0)
			pole[i + 1][j - 1] = 3;
			else if (pole[i][j - 1] == 2)
			{
			pole[i + 1][j - 1] = 5;
			udar++;
			}
			else if (pole[i + 1][j - 1] == 9)
			{
			pole[i + 1][j - 1] = 8;
			pop++;
			}
			else pole[i + 1][j - 1] = 3; }

			}

			}
			*/












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
			moving(e, y);
			for (i = 0, x = 1; i<10, x<21; i++, x = x + 2)
				for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)

				{
					GotoXY(x, y); switch (pole[i][j])
					{
					case 0:if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
						   else { SetColor(0, 9); printf("  "); }break;
					case 1:if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
						   else { SetColor(0, 9); printf("  "); }break;
					case 2:SetColor(0, 12); printf("  "); break;
					case 3: SetColor(0, 11); printf("  "); break;
					case 6: SetColor(0, 5); printf("  "); break;
					case 7: SetColor(0, 15); printf("  "); break;
					case 8: SetColor(0, 10); printf("  "); break;
					case 30: SetColor(0, 6); printf("  "); break;
					}
					GotoXY(x, y + 1); switch (pole[i][j])
					{
					case 0:if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
						   else { SetColor(0, 9); printf("  "); }break;
					case 1:if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
						   else { SetColor(0, 9); printf("  "); }break;
					case 2:SetColor(0, 12); printf("  "); break;
					case 3: SetColor(0, 11); printf("  "); break;
					case 6: SetColor(0, 5); printf("  "); break;
					case 7: SetColor(0, 15); printf("  "); break;
					case 8: SetColor(0, 10); printf("  "); break;
					case 30: SetColor(0, 6); printf("  "); break;
					}
				}
			x = iper;
			y = jper;
			udar = 0;
			for (i = 0; i<10; i++)
				for (j = 0; j<10; j++)
					if (pole[i][j] == 2)
						udar++;
			end = 0;
			if (udar == 20)
			{
				k = 1; pop = 0;
			}
			if (k == 1)
				udar = -1;
		}
		GotoXY(25, 20);
		printf("%d", udar);
	} while ((k != 1) && (pop > 0));
	return udar;
}

int main()
{

	int pole[10][10], mypole[10][10], x, y, ui, ud[2], hod[1];
	int i, j, m, k;
	keybd_event(VK_MENU, 0x38, 0, 0); //press ALT
	keybd_event(VK_RETURN, 0x1c, 0, 0); //press ENTER
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0); //release ENTER
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0); //release ALT
	do {
		m = menu(); ui = 0; if (m == 1)
		{
			SetColor(0, 0);
			system("cls");
			int f = 1;
			GotoXY(30, 10); SetColor(15, 0); printf(Rus("���������� �������"));
			GotoXY(23, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("�������������")); SetColor(15, 0); printf("]");
			GotoXY(43, 13); SetColor(15, 0); printf("["); printf(Rus("�������")); SetColor(15, 0); printf("]");
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
							GotoXY(23, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("�������������")); SetColor(15, 0); printf("]");
							GotoXY(43, 13); SetColor(15, 0); printf("["); printf(Rus("�������")); SetColor(15, 0); printf("]");
						}
						else {
							GotoXY(23, 13); SetColor(15, 0); printf("["); printf(Rus("�������������")); printf("]");
							GotoXY(43, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("�������")); SetColor(15, 0); printf("]");
						}
						break; }

					case 77: {f = f*(-1);
						if (f == 1) {
							GotoXY(23, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("�������������")); SetColor(15, 0); printf("]");
							GotoXY(43, 13); SetColor(15, 0); printf("["); printf(Rus("�������")); SetColor(15, 0); printf("]");
						}
						else {
							GotoXY(23, 13); SetColor(15, 0); printf("["); printf(Rus("�������������")); printf("]");
							GotoXY(43, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("�������")); SetColor(15, 0); printf("]");
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
				sheeps(mypole);
				bonus(mypole);
			}
			else {
				SetColor(0, 0);

				//vivod(pole);


				ui = ras(mypole);
				bonus(mypole);
			}
			if (ui == 0) {
				SetColor(0, 0);
				system("cls");
				GotoXY(30, 10);
				SetColor(6, 0);
				printf(Rus("����������� ��������"));
				SetColor(15, 0);
				for (i = 1; i <= 100; i++)
				{
					GotoXY(62, 15);
					SetColor(15, 0); printf("%d%%", i);
					if (i % 2 == 0)
					{
						GotoXY(10 + (i / 2), 15);
						SetColor(0, 15); printf(" ");
						sheeps(pole);
						bonus(pole);
						sabatage_bonus(pole);
						//atomic_bonus(pole);
					}Sleep(50);
				}
				SetColor(0, 0);
				system("cls");
				f = 1;
				GotoXY(30, 10); SetColor(15, 0); printf(Rus("��� ����� ������?"));
				GotoXY(23, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("���������")); SetColor(15, 0); printf("]");
				GotoXY(43, 13); SetColor(15, 0); printf("["); printf(Rus("�����")); SetColor(15, 0); printf("]");
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
								GotoXY(23, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("���������")); SetColor(15, 0); printf("]");
								GotoXY(43, 13); SetColor(15, 0); printf("["); printf(Rus("�����")); SetColor(15, 0); printf("]");
							}
							else {
								GotoXY(23, 13); SetColor(15, 0); printf("["); printf(Rus("���������")); printf("]");
								GotoXY(43, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("�����")); SetColor(15, 0); printf("]");
							}
							break; }

						case 77: {f = f*(-1);
							if (f == 1) {
								GotoXY(23, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("���������")); SetColor(15, 0); printf("]");
								GotoXY(43, 13); SetColor(15, 0); printf("["); printf(Rus("�����")); SetColor(15, 0); printf("]");
							}
							else {
								GotoXY(23, 13); SetColor(15, 0); printf("["); printf(Rus("���������")); printf("]");
								GotoXY(43, 13); SetColor(15, 0); printf("["); SetColor(0, 2); printf(Rus("�����")); SetColor(15, 0); printf("]");
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
				system("cls");
				write();

				for (i = 0, x = 1; i<10, x<21; i++, x = x + 2)
					for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)

					{
						GotoXY(x, y);  if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
						else { SetColor(0, 9); printf("  "); }
						GotoXY(x, y + 1); if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); }
						else { SetColor(0, 9); printf("  "); }
					}

				for (i = 0, x = 41; i<10, x<61; i++, x = x + 2)
					for (j = 0, y = 1; j<10, y<21; j++, y = y + 2)

					{
						GotoXY(x, y); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
						else { if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
						GotoXY(x, y + 1); if (mypole[i][j] == 1) { SetColor(0, 12); printf("  "); }
						else { if ((j + i) % 2 != 0) { SetColor(0, 1); printf("  "); } else { SetColor(0, 9); printf("  "); } }
					}

				GotoXY(25, 8); SetColor(14, 0); printf(Rus("�������-enter"));
				GotoXY(22, 9); SetColor(2, 0); printf(Rus("����������-�������"));
				GotoXY(26, 10); SetColor(14, 0); printf(Rus("�����-Esc"));
				GotoXY(24, 12); SetColor(15, 0); printf(Rus("���� ���������"));
				GotoXY(23, 13); printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBB\n");
				GotoXY(23, 14); printf("\xba"); printf("\t      "); printf("\xba\n");
				GotoXY(23, 15); printf("\xba"); printf("\t      "); printf("\xba\n");
				GotoXY(23, 16); printf("\xba"); printf("\t      "); printf("\xba\n");
				GotoXY(23, 17); printf("\xba"); printf("\t      "); printf("\xba\n");
				GotoXY(23, 18); printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xBC\n");
				ud[0] = -3; ud[1] = -3;



				while (chislocomp<20 && chislomy<20)
				{
					if (chislomy == -1) { break; }
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
					printf(Rus("�� ���������")); fflush(stdin); _getch(); fflush(stdin);
				}
				if (chislomy == 20)
				{
					GotoXY(33, 14); SetColor(0, 12);
					printf(Rus("�� ��������!")); fflush(stdin); _getch(); fflush(stdin);
				}

			}
		}
		// vivod(mypole);
	} while (m == 1);

}