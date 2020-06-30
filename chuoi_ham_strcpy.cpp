// Hàm strcpy

#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 100
using namespace std;

void STRCPY(char s[], char t[]) {
	int n = strlen(s);
	int m = strlen(t);
	int tam[MAX], k = 0;
	
	for (int i = 0; i < m; i++) {
		tam[k] = t[i];
		k++;
	}
	int dem = 0;
	if(n < m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(i == j) t[j] = s[i];
				else if (i < j) {
					t[j] = '\0';
				}
			}
		}
	}
	else {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if(i == j) t[i] = s[j];
				else if (dem < n) {
					t[i + 1] = '\0';
					m++;
				}
			}
			dem++;
		}
	}
	
	
}

int main () {
	char s[30], t[30];
	cout << "Nhap chuoi s: "; gets(s);
	cout << "Nhap chuoi t: "; gets(t);
	STRCPY(s, t);
	cout << "Xuat chuoi t: " << t;
	return 0;
}
