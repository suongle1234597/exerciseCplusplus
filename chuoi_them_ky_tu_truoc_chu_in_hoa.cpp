// Nhap 1 chuoi bat ky (do dai 35 ky tu). Them ky tu "#" truoc cac ky tu in hoa

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

void Them (char s[], int vt, char x) {
	int n = strlen(s);
	for (int i = n - 1; i >= vt; i--) {
		s[i + 1] = s[i];
	}
	s[vt] = x;
	s[n + 1] = '\0';
}

void Them_Ky_Tu_Truoc_In_Hoa (char s[], char x) {
	int n = strlen(s);
	for (int i = n - 1; i >= 1; i--) {
		if (s[i] >= 65 && s[i] <= 90) {
			Them(s, i, x);
			i++;
		}
	}
}

int main() {
	char s[30];
	cout << " Nhap chuoi: "; gets(s);
	Them_Ky_Tu_Truoc_In_Hoa(s, '#');
	cout << " Xuat chuoi: " << s;
	return 0;
}
