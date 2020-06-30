// Nhap 1 chuoi bat ky (do dai 30 ky tu). Xoa cac ky tu x(nhap tu ban phim) ton tai trong chuoi

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

void Xoa (char s[], int vt) {
	int n = strlen(s);
	for (int i = vt + 1; i < n; i++) {
		s[i - 1] = s[i];
	}
	s[n - 1] = '\0';
}

void Xoa_Ky_Tu_X (char s[], char x) {
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		if (s[i] == x) {
			Xoa(s, i);
			i--;
		}
	}
}

int main() {
	char s[30], x;
	cout << " Nhap chuoi: "; gets(s);
	cout << " Nhap x: "; cin >> x;
	Xoa_Ky_Tu_X(s, x);
	cout << " Chuoi sau xoa ky tu x (nhap x tu ban phim): " << s;
	return 0;
}
