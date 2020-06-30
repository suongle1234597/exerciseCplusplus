#include <unistd.h>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main() {
	char str[] = "VN VO DICH";
	int x = 10;
	int y = 5;
	while(true) {
		clrscr();
		gotoXY(x, y);
		cout << str << endl;
		Sleep(1000);
	}
	return 0;
}
