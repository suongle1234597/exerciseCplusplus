// Cong hai chuoi so

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void Chuyen_KT_So_Thanh_Chu_So (char s[]) {
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		s[i] = s[i] - 48;
	}
}

int main() {
	char s[30];
	cout << " Nhap chuoi ki tu so: "; gets(s);
	Chuyen_KT_So_Thanh_Chu_So(s);
	cout << " Xuat chuoi: " << s;
	return 0;
}
