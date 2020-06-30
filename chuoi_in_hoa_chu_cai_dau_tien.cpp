/* Nhap vao 1 chuoi bat ky. In hoa cac ky tu dau tien cua moi tu
VD: "ki thuat lap trinh"
==> "Ki Thuat Lap Trinh" */

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void In_Hoa_Chu_Dau_Tien (char s[]) {
	int n = strlen(s);
	s[0] = s[0] - 32;
	for (int i = 1; i < n; i++) {
		if(s[i] == 32 && s[i + 1] != 32) s[i + 1] = s[i + 1] - 32;
	}
}

int main() {
	char s[30];
	cout << " Nhap chuoi: "; gets(s);
	In_Hoa_Chu_Dau_Tien(s);
	cout << " Xuat chuoi: " << s;
	return 0;
}
