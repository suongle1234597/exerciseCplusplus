/* �?c c�c s? nguy�n t? file INPUT.TXT bi?t
+ Ch? c� 1 d�ng duy nh?t ch?a c�c s? nguy�n
VD: INPUT.TXT
12 345 135 7 12 1
=== Y�u c?u ===
T�m c�c ph?n t? l� s? Amstrong trong m?ng s? nguy�n d� v� ghi v�o file AMSTRONG.TXT.  */

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

void Doc_File(int a[], int n, ifstream &filein) {
	for (int i = 0; i < n; i++) {
		filein >> a[i];
	}
}

void Xuat_Mang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

bool KiemTra (int n)
{
	int i, j, k, m, dem = 0, s = 0;
	m = n;
	k = n;
	while (n > 0)
	{
		n = n / 10;
		dem++;
	}
	while (m > 0)
	{
		j = m % 10;
		m = m / 10;
		s = s + pow (j, dem);
	}
	
	if (s == k) return true;
	else return false;
}

int main() {
	int a[100]; 
	int n = 0;
	ifstream filein;
	filein.open("INPUT_1.TXT", ios_base::in);
	if (filein.fail() == true) {
		cout << "Mo file khong thanh cong";
		return 0;
	}
	
	filein >> n;
	Doc_File(a, n, filein);
	cout << "Xuat mang: ";
	Xuat_Mang(a, n);
	
	ofstream fileout;
	fileout.open("AMSTRONG.TXT", ios::out);
	for(int i = 0; i < n; i++) {
		if(KiemTra(a[i]) == true) {
			fileout << a[i];
		}
	}
	
	fileout.close();
	
	filein.close();
	return 0;
}
