/* Kane dang la sinh vien nam nhat va bat dau hoc lap trinh, anh ay nhap vao chuoi bat ky voi cac ky tu in hoa in thuong dan xen lan nhau. 
Thay giao bao Kane hay chuan hoa chuoi bat ky ma thay nhap vao theo nguyen tac sau :
+ In hoa cac ky tu dau cua moi tu
+ Cac ki tu con lai in thuong
Ban hay giup Kane nhe :))
VD: "Ki thUAT LAP TRinh"
==> "Ki Thuat Lap Trinh" */

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void Chuyen_Chuoi_Ky_Tu_Thanh_In_Thuong (char s[]) {
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		if (s[i] >= 65 && s[i] <= 90) {
			s[i] = s[i] + 32;
		}
	}
}

void In_Hoa_Chu_Dau_Con_Lai_In_Thuong (char s[]) {
	Chuyen_Chuoi_Ky_Tu_Thanh_In_Thuong(s);
	int n = strlen(s);
	s[0] = s[0] - 32;
	for (int i = 1; i < n; i++) {
		if(s[i] == 32 && s[i + 1] != 32) s[i + 1] = s[i + 1] - 32;
	}
}

int main() {
	char s[30];
	cout << " Nhap chuoi: "; gets(s);
	In_Hoa_Chu_Dau_Con_Lai_In_Thuong(s);
	cout << " Xuat chuoi: " << s;
	return 0;
}
