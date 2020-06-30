// Cho mang 1 chieu cac so nguyen. Viet chuong trinh xoa cac phan tu la so hoan thien.

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

void XuatMang (int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

void Xoa (int a[], int &n, int vt)
{
	for (int i = vt + 1; i < n; i++)
	{
		a[i - 1] = a[i];
	}
	n--; 
}

bool KT_So_Hoan_Thien (int n)
{
	int s = 0;
	for (int i=1;i<n;i++)
	{
		if (n%i==0) 
		{
			s=s+i;
		}
	}
	if (n==s) return true;
	else return false;
} 

void Xoa_PT_So_Hoan_Thien (int a[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		if (KT_So_Hoan_Thien (a[i]) == true) 
		{
			Xoa (a, n, i);
			i--;
		}
	}
}
 
int main ()
{
	int a[MAX], n;
	cout << "\n Nhap n:"; cin >> n;
	cout << "\n\t NHAP MANG\n";
	NhapMang (a, n);
	cout << "\n\t MANG SAU KHI XOA PT SO CHINH PHUONG\n";
	Xoa_PT_So_Hoan_Thien (a, n);
	XuatMang (a, n);
	return 0;
}
