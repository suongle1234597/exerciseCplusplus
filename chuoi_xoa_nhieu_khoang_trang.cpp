/* Nhap vao 1 chuoi tu ban phim. Viet ham chuan hoa chuoi vua nhap theo yeu cau sau: 
+ Khong ton tai ki tu khoang trong o dau chuoi 
+ Khong ton tai ki tu khoang trong o cuoi chuoi
+ Moi tu chi cach nhau 1 ky tu khoang trang
Vi du:
s = "   Ki       thuat lap         trinh     "
===> sau khi chuan hoa: s = "Ki thuat lap trinh" */

#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 100
using namespace std;

void Xoa(char s[], int vt)
{
	int n = strlen(s);
	for (int i = vt + 1; i < n; i++)
	{
		s[i - 1] = s[i];
	}
	s[n - 1] = '\0';
}

void Xoa_Khoang_Trang_O_Dau(char s[]) {
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		if(s[i] == '_') {
			Xoa(s, i);
			i--;
		}
		else break;
	}
}

void Xoa_Khoang_Trang_O_Cuoi(char s[]) {
	int n = strlen(s);
	for (int i = n - 1; i >= 1; i--) {
		if(s[i] == '_') {
			Xoa(s, i);
		}
		else break;
	}
}

void Chuan_Hoa (char s[]) {
	Xoa_Khoang_Trang_O_Cuoi(s);
	Xoa_Khoang_Trang_O_Dau(s);
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		if(s[i] == '_' && s[i + 1] == '_') {
			Xoa(s, i);
			i--;
		}
	}
}

int main() {
	char s[30];
	cout << " Nhap chuoi:"; gets(s);
	Chuan_Hoa(s);
	cout << " Xuat chuoi:" << s;
	return 0;
}
