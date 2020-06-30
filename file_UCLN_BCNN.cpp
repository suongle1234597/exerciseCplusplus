/* �?c c�c s? nguy�n t? file INPUT.TXT bi?t
+ Ch? c� 1 d�ng duy nh?t ch?a c�c s? nguy�n v� m?i s? nguy�n c�ch nhau b?i 1 d?u ph?y
VD: INPUT.TXT
1,3,6,9

=== Y�u c?u ===
- File UCLN.TXT luu 1 s? nguy�n l� u?c s? chung l?n nh?t c?a t?t c? c�c ph?n t? c?a m?ng
- File BCNN.TXT luu 1 s? nguy�n l� b?i chung nh? nh?t c?a t?t c? c�c ph?n t? c?a m?ng */

#include <iostream>
#include <fstream>
using namespace std;

void Doc_File(int a[], int &n, ifstream &filein) {
	int i = 0;
	while(filein.eof() == false) {
		filein >> a[i];
		i++;
		n++;
		char tam;
		filein >> tam;
	}
}

void Xuat_Mang(int a[], int n) {
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

int main() {
	int a[100];
	int n = 0;
	
	ifstream filein;
	filein.open("INPUT_3.TXT", ios::in);
	while(filein.fail()) {
		cout << "Mo file khong thanh cong";
		return 0;
	}
	
	filein >> n;
	Doc_File(a, n, filein);
	cout << "Xuat mang: ";
	Xuat_Mang(a, n);
	
//	ofstream fileout;
//	fileout.open("UCLN.TXT", ios::out)
//	
//	fileout.close();
	filein.close();
}
