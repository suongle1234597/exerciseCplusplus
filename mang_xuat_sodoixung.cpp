// Nhap 1 mang so nguyen. Tinh tong cac so doi xung

#include <iostream>
#define MAX 100
using namespace std;

void NhapMang (int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " Nhap phan tu a[" << i << "] : ";
		cin >> a[i];
	}
}

bool KT_doi_xung (int n)
{
	int sodaonguoc = 0;
	int m = n;
	while (m != 0)
	{
		sodaonguoc = (sodaonguoc * 10) + (m % 10);
		m = m / 10;
	}
	if (n == sodaonguoc && n > 10) return true;
	else return false;
}

void XuatMang (int a[], int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		if (KT_doi_xung(a[i]) == true) s = s + a[i];
	}
	cout << " Tong cac so doi xung la: " << s;
}

int main ()
{
	int a[MAX], n;
	cout << "\n Nhap n: "; cin >> n;
	NhapMang (a, n);
	XuatMang (a, n);
	return 0;
}
