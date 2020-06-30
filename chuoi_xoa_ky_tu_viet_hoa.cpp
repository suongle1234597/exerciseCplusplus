// Nhap 1 chuoi bat ky (do dai 30 ky tu). Xoa cac ky tu in hoa ton tai trong chuoi

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

void Xoa_Ky_Tu_In_Hoa (char s[]) {
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		if (s[i] >= 65 && s[i] <= 90) {
			Xoa(s, i);
			i--;
		}
	}
}

int main() {
	char s[30];
	cout << " Nhap chuoi: "; gets(s);
	Xoa_Ky_Tu_In_Hoa(s);
	cout << " Chuoi sau xoa ky tu hoa: " << s;
	return 0;
}
