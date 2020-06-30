// Cho mang 1 chieu cac so nguyen. Viet chuong trinh them phan tu 0 vao truoc cac so le

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
void XuatMang (int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

void Them (int a[], int &n, int vt, int x)
{
	for (int i = n - 1; i >= vt; i--)
	{
		a[i + 1] = a[i];
	}
	a[vt] = x; 
	n++; 
}

void Them_0_Truoc_PT_Le (int a[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0) 
		{
			Them(a, n, i, 0);
			i++;
		}
	}
}

int main ()
{
	int a[MAX], n;
	cout << "\n Nhap n: "; cin >> n;
	cout << "\n\t NHAP MANG\n";
	NhapMang (a, n);
	Them_0_Truoc_PT_Le (a, n);
	cout << "\n\t XUAT MANG\n";
	XuatMang (a, n);
	return 0;
}
