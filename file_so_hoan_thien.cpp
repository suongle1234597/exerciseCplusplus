/* �?c c�c s? nguy�n t? file INPUT.TXT bi?t
+ D�ng d?u ti�n l� 1 s? nguy�n bi?u di?n s? lu?ng c�c s? nguy�n c?n d?c
+ D�ng th? 2 l� 1 d�y c�c s? nguy�n c?n d?c
VD: INPUT.TXT
5
1 6 7 18 9 */

#include <iostream>
#include <fstream>
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

bool KT_So_Hoan_Thien(int n) {
	int s = 0;
	for (int  i = 1; i < n; i++) {
		if(n % i == 0) {
			s = s + i;
		}
	}
	if(s == n) return true;
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
	fileout.open("SOHOANTHIEN.TXT", ios::out);
	for(int i = 0; i < n; i++) {
		if(KT_So_Hoan_Thien(a[i]) == true) {
			fileout << a[i];
		}
	}
	
	fileout.close();
	
	filein.close();
	return 0;
}
