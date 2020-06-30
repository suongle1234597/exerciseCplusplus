// Nhap 1 chuoi vao ban phim co do dai toi da 20 ky tu. Chuyen tat ca cac ky tu cua chuoi do thanh chu thuong(khong dung ham co san)

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

void Chuyen_Chuoi_Ky_Tu_Thanh_In_Thuong (char s[]) {
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		if (s[i] >= 65 && s[i] <= 90) {
			s[i] = s[i] + 32;
		}
	}
}

void Xoa_Tat_Ca(char s[]) {
	int n = strlen(s);
	for (int i = n - 1; i >= 0; i--)
	{
		s[i] = '\0';
	}
}

int main() {
	char s[30];
	cout << " Nhap chuoi: "; gets(s);
//	Chuyen_Chuoi_Ky_Tu_Thanh_In_Thuong(s);
	Xoa_Tat_Ca(s);
	cout << " Xuat chuoi: " << s;
	return 0;
}
