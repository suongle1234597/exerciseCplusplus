/* Nhap vao 1 chuoi tu ban phim. Viet ham chuan hoa chuoi vua nhap theo yeu cau sau: 
+ Khong ton tai ki tu khoang trong o dau chuoi 
+ Khong ton tai ki tu khoang trong o cuoi chuoi 
+ Moi tu cach nhau 1 ky tu khoang trang
+ Viet hoa ky tu dau cua moi tu
Vi du:
s = "   Ki       thuat lap         trinh     "
===> sau khi chuan hoa: s = "Ki Thuat Lap Trinh" */

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
		if(s[i] == 32) {
			Xoa(s, i);
			i--;
		}
		else break;
	}
}

void Xoa_Khoang_Trang_O_Cuoi(char s[]) {
	int n = strlen(s);
	for (int i = n - 1; i >= 1; i--) {
		if(s[i] == 32) {
			Xoa(s, i);
		}
		else break;
	}
}

void In_Hoa_O_Ky_Tu_Dau(char s[]) {
	int n = strlen(s);
	s[0] = s[0] - 32;
	for(int i = 0; i < n; i++) {
		if(s[i] == 32 && s[i + 1] != 32) s[i + 1] = s[i + 1] - 32;
   }
}

void Xoa_Nhieu_Khoang_Trang(char s[]) {
	Xoa_Khoang_Trang_O_Dau(s);
	Xoa_Khoang_Trang_O_Cuoi(s);
	In_Hoa_O_Ky_Tu_Dau(s);
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		if(s[i] == 32 && s[i + 1] == 32) {
			Xoa(s, i);
			i--;
		}
	}
}

int main() {
	char s[30];
	cout << " Nhap chuoi:"; gets(s);
	Xoa_Nhieu_Khoang_Trang(s);
	
	cout << " Xuat chuoi:" << s;
	return 0;
}           
