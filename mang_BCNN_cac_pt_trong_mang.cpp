/* Viet chuong trinh tim BCNN cua tat ca cac phan tu trong mang 1 chieu cac so nguyen.
VD: 
+ 3 6 9
==> 18
+ 3 6 9 7
==> 126 */

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

int UCLN (int a, int b)
{
	int uc = 1;
	if (a > b)
	{
		for (int i = 1; i <= b; i++)
		{
			if (a % i == 0 && b % i == 0) uc = i;
		}
	}
	else
	{
		for (int i = 1; i <= a; i++)
		{
			if (a % i == 0 && b % i == 0) uc = i;
		}
	}
	return uc;
}

int BCNN (int a, int b)
{
	return ((a*b)/UCLN(a, b));
}

int TimBCNN (int a[], int n)
{
	int bc = a[0];
	for (int i = 0; i < n; i++)
	{
		bc = BCNN (bc, a[i]);
	}
	return bc;
}

int main ()
{
	int a[MAX], n;
	cout << " Nhap n: "; cin >> n;
	cout << "\n\t NHAP MANG\n";
	NhapMang (a, n);
	cout << "\n\tBCNN cua tat ca cac phan tu trong mang: ";
	cout << TimBCNN (a, n);
	return 0;
}
