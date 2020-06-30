#include <stdio.h>
#include <time.h>
#include <iostream>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <iomanip>
using namespace std;

int stop = 1;

void gotoxy(short x,short y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x,y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}  

void DongHo(int gio, int phut) {
	char c;
	int giay = 0;
	do {
		while(!_kbhit()) {
			gotoxy(10, 10);
			if(gio == 0 && phut == 0 && giay == 0) break;
			if(giay > 0) giay--;
			else if(phut > 0) {
				giay = 59;
				phut--;
			} else if(gio > 0) {
				gio--;
				phut = 59;
				giay = 59;
			}
			if(gio < 10) {
				if(phut < 10) {
					if(giay < 10) {
						gotoxy(10, 10);
						cout << "0" << gio << " : 0" << phut << " : 0" << giay; 
					}
					else{
						gotoxy(10, 10);
						cout << "0" << gio << " : 0" << phut << " : " << giay; 
					}
				}
				else {
					gotoxy(10, 10);
					cout << "0" << gio << " : " << phut << " : " << giay; 
				}
			}
			else {
				if(phut < 10) {
					if(giay < 10) {
						gotoxy(10, 10);
						cout << gio << " : 0" << phut << " : 0" << giay; 
					}
					else{
						gotoxy(10, 10);
						cout << gio << " : 0" << phut << " : " << giay; 
					}
				}
				else {
					gotoxy(10, 10);
					cout << gio << " : " << phut << " : " << giay; 
				}
			}
			Sleep(1000);
		}
		if(gio == 0 && phut == 0 && giay == 0) break;
		
		c = getch();
//		if(c == 's') stop == 0;
	} while(c != 's');
	
	
	
}
//tra ve trang thai cua dong ho. cho vong while to o ngoai

int main ()
{
  	int n, phut = 0, gio = 0, giay = 0;
  	
  	cout << "\nNhap so phut: ";
  	cin >> n;
  	gio = n/60;
  	phut = n%60;
//  	cout << gio << " " << phut;
  	
  	int i = 0;
  	char kytu;
  	kytu = getch();
  	DongHo(gio, phut);
//	while(stop) {
//		Sleep(1000);
//		gotoxy(20, 20);
//		cout << "hello" << i;
//		i++;
//	}
	
	
}
