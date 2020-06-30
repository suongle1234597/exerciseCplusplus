// Nhap vao 1 chuoi ky tu. Thong ke tan xuat xuat hien cua tung ki tu

#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 100
using namespace std;

void Dem_Ky_Tu (char s[]) {
	int n = strlen(s);
	int tam[MAX], m = 0;
	for (int i = 0; i < n; i++) {
		bool KT = true; // gia su i la ky tu doc lap
		for (int j = i - 1; j >= 0; j--)
		{
			if (s[i] == s[j])
			{
				KT = false;
				break;
			}
			
		}
		if (KT == true)
		{
		    tam[m] = s[i];
		    m++; 
		}
	}
	for (int i = 0; i < m; i++)
	{
		int dem = 0;
		for (int j = 0; j < n; j++)
		{
			if (s[j] == tam[i]) dem++;
		}
		cout << char(tam[i]) << " => " << dem << endl;
	}
}

int main() {
	char s[30];
	cout << " Nhap chuoi: "; gets(s);
	Dem_Ky_Tu(s);
//	cout << " Xuat chuoi: " << s;
	return 0;
}
