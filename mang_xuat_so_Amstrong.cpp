//  Nhap mang 1 chieu cac so nguyen. Viet chuong trinh xuat ra cac phan tu la so Amstrong ? 

#include <iostream>
#include <math.h>
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

int Dem (int n)
{
	int dem = 0;
	while (n > 0)
	{
		n = n / 10;
		dem++;
	}
	return dem;
}

bool KT_so_Amstrong (int n)
{
	int k = Dem(n);
	int i;
	int s = 0;
	int m = n;
	while (n > 0)
	{
		i = n % 10;
		n = n / 10;
		s = s + pow (i, k);
	}
	if (s == m) return true;
	else return false;
}

void XuatMang (int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (KT_so_Amstrong(a[i]) == true)
		cout << a[i] << " ";
	}
}

int main ()
{
	int a[MAX], n;
	cout << "\n Nhap n: "; cin >> n;
	cout << "\n\t NHAP MANG\n";
	NhapMang (a, n);
	cout << "\n\t XUAT MANG\n";
	XuatMang (a, n);
	return 0;
}
