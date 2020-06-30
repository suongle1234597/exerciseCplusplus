//  Nhap mang 1 chieu cac so nguyen. Viet chuong trinh xuat ra cac phan tu la so nguyen to ? 

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

bool KT_SNT (int n)
{
	if (n < 2) return false;
	else if (n == 2) return true;
	else
	{
		for (int i = 2; i < n; i++)
		{
			if (n % i ==0) return false;
		}
	}
	return true;
} 

void XuatMang (int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (KT_SNT(a[i]) == true)
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
