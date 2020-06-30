// Nhap 1 chuoi bat ky (do dai 20 ky tu). Sap xep cac ky tu trong  chuoi giam dan theo ma ASCII

#include <iostream>
#include <string.h>
#include <stdio.h>

void SapXep(char s[]) {
	int n = strlen(s);
	int tam;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if(s[i] > s[j]) {
				tam = s[i];
				s[i] = s[j];
				s[j] = tam;
			}
		}
	}
}

using namespace std;
int main() {
	char s[20];
	cout << " Nhap chuoi: "; gets(s);
	SapXep(s);
	cout << " Chuoi sau khi sap xep: " << s;
	return 0;
}
