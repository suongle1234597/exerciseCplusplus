// Nhap 1 mang so nguyen. Viet chuong trinh in ra so sieu nguyen to co trong mang

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
	bool KT_SNT = true;
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

bool KiemTra (int n)
{
	int i;
	while (n>0)
	{
		if (KT_SNT(n) == true) 
		n = n / 10;
		else return false;
	}
	return true;
}

void XuatMang (int a[], int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		if (KiemTra(a[i]) == true) cout << a[i] << " ";
	}
}

int main ()
{
	int a[MAX], n;
	cout << "\n Nhap n: "; cin >> n;
	NhapMang (a, n);
	XuatMang (a, n);
	return 0;
}
