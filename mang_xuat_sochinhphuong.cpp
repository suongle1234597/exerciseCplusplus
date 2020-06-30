//  Nhap mang 1 chieu cac so nguyen. Viet chuong trinh xuat ra cac phan tu la so chinh phuong ? 

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

bool KT (int n)
{
	for (int i = 1; i <= (n/2); i++)
	{
		if (i*i == n) return true;
	}
	return false;
} 

void XuatMang (int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (KT(a[i]) == true)
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
