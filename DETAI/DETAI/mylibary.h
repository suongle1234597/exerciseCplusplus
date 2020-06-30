// mylibary
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <fstream>
#define Enter 13
#define ESC 27
#define Backspace 8
#define BROWN 20
#define WHITE 15
#define RED 28
#define BLUE 19
#define DARKBLUE 25
#define MAXLOP 500
#define MAXCAUHOI 2000
#define Up 72
#define Down 80
#define Left 75
#define Right 77

using namespace std;

void gotoxy(short x,short y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x,y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}  

int wherex( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}

int wherey( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}
void clreol( ) {
COORD coord;
DWORD written;
CONSOLE_SCREEN_BUFFER_INFO info;
GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
coord.X = info.dwCursorPosition.X;
coord.Y = info.dwCursorPosition.Y;
FillConsoleOutputCharacter (GetStdHandle(STD_OUTPUT_HANDLE), ' ',
  info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
gotoxy (info.dwCursorPosition.X + 1, info.dwCursorPosition.Y + 1);
}

void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void Normal () {
	SetColor(WHITE);
}
void HighLight () {
	SetColor(RED);
}

void VeDuongThang(int x, int y, int dai, char ngang, int color) {
	SetColor(color);
	gotoxy(x, y);
	for (int i = 1; i <= dai; i++) {
		cout << ngang;
	}
}

void VeDuongDoc(int x, int y, int dai, char doc, int color) {
	SetColor(color);
	gotoxy(x, y);
	for (int i = 0; i < dai; i++){
		for(int j = 1; j < 2; j++) {
			gotoxy(x, y + i);
			cout << doc ;
		}
	}
}

//rong - doc. ngang - dai
void VeKhung(char doc, char ngang, char traitren, char traiduoi, char phaitren, char phaiduoi, int x, int y, int rong, int dai, int color) // 160:45 (Ti le 16:9)
{
	SetColor(color);
	gotoxy(x,y);
	for (int i = 1; i <= rong; i++)
	{
		for (int j = 1; j <= dai; j++)
		{
			if (i == 1 || i == rong)
			{
				if (i == 1)
				{
					if (j == 1)
					{
						cout << traitren;
					}
					else
					{
						if (j == dai)
						{
							cout << phaitren;
						}
						else
						{
							cout << ngang;
						}
					}
				}
				else
				{
					if (j == 1)
					{
						cout << traiduoi;
					}
					else
					{
						if (j == dai)
						{
							cout << phaiduoi;
						}
						else
						{
							cout << ngang;
						}
					}
				}
			}
			else
			{
				if (j == 1 || j == dai)
				{
					cout << doc;
				}
				else
				{
					cout << " ";
				}
			}
		}
		gotoxy(x, y + i);
	}
}

void VeKhung1Duong(int x, int y, int rong, int dai, int color)
{
	char traitren = 218; // goc trai tren 1 duong
	char phaitren = 191; // goc phai tren 
	char traiduoi = 192; // goc trai duoi
	char phaiduoi = 217; // goc phai duoi
	char ngang = 196; //ngang
	char doc = 179; //doc
	VeKhung(doc, ngang, traitren, traiduoi, phaitren, phaiduoi, x, y, rong, dai, color);
}

void VeKhung2Duong(int x, int y, int rong, int dai, int color)
{
	char doc = 186;  // doc 2 duong
	char ngang = 205;  //ngang 2 duong
	char traitren = 201; // goc trai tren 2 duong
	char traiduoi = 200; // goc trai duoi 2 duong
	char phaitren = 187; // goc phai tren. 2 duong
	char phaiduoi = 188; // goc phai duoi 2 duong
	VeKhung(doc, ngang, traitren, traiduoi, phaitren, phaiduoi, x, y, rong, dai, color);
}

char* Clear(char s[])
{
	int n = strlen(s);
	s[0]= '\0';
	return s;
}

char* BackSpace(char s[])
{
	int n = strlen(s);
	s[n - 1]= '\0';
	return s;
}

void InHoa(char &ch){
	if (ch>=97&&ch<=122) ch-=32;
	else return;
}

void NhapChuoi(char s[], char c, int &i, int x, int y) {
	SetColor(15);
	s[i] = c;
	s[i + 1] = '\0';
	gotoxy(x + strlen(s), y);
	cout << c;
	i++;
}

void NhapChuoiCoSan(char s[], char c, int &i, int x, int y) {
	SetColor(15);
	s[i] = c;
	s[i + 1] = '\0';
	gotoxy(x + strlen(s) - 1, y);
	cout << c;
	i++;
}

void XoaTungKyTu(char s[], int &i, int x, int y) {
	if(strlen(s) > 0) {
       	gotoxy(x + strlen(s) + 1, y);
       	cout << "\b ";
       	BackSpace(s);
       	i--;
	}
}

void XoaTungKyTuCoSan(char s[], int &i, int x, int y) {
	if(strlen(s) > 0) {
       	gotoxy(x + strlen(s), y);
       	cout << "\b ";
       	BackSpace(s);
       	i--;
	}
}

char* MaHoaPWD(char* s) {
	int n = strlen(s);
	for(int i = 0; i < n; i++) s[i] = '*';
	return s;
}

void VeKhungDS() {
	VeKhung1Duong(15, 12, 30, 100, WHITE); //khung danh sach
	VeDuongThang(16, 14, 98, 196, WHITE); //duong ngang giua
	VeDuongDoc(21, 13, 28, 179, WHITE);
	VeDuongDoc(60, 13, 28, 179, WHITE);
}


