/* Nhap vao 1 chuoi bat ky. Dem so luong tu hien co trong chuoi
VD: "nghe thuat chi la 1 anh trang lua doi"
==> 9 tu */

#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 100
using namespace std;

void Dem_So_Luong_Tu (char s[]) {
	int n = strlen(s);
	int dem = 1;
	for (int i = 0; i < n; i++) {
		if(s[i] == 32)
		dem++;
	}
	cout << dem << " tu" << endl;
}

int main() {
	char s[30];
	cout << " Nhap chuoi:"; gets(s);
	Dem_So_Luong_Tu(s);
	return 0;
}   
