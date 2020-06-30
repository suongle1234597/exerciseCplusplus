/* Viet chuong trinh tim UCLN cua tat ca cac phan tu trong mang 1 chieu cac so nguyen.
VD: 
+ 3 6 9 
==> 3
+ 3 5 8 12
==> 1 */

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
 
void Tim_UCLN (int a[], int n)
{
//	int tam[MAX], m = 0, min = a[0];
//	for (int i = 0; i < n; i++)
//	{
//       if (min > a[i]) min = a[i];
//	}
//	// Tim uoc cua so nho nhat cho vao mang tam
//	for (int i = 1; i <= min; i++)
//	{
//		if (min % i == 0) 
//		{
//			tam[m] = i;
//			m++;
//		}
//	}
//	for (int i = m - 1; i >= 0; i--)
//	{
//		bool KT = true; // gia su i la UCLN cua mang
//		for (int j = 0; j < n; j++)
//		{
//			if (a[j] % tam[i] != 0)
//			{
//				KT = false;
//				break;
//			}
//		}
//		if (KT = true) 
//		{
//			cout << tam[i];
//			break;
//		}
//	}

     int uc = a[0];
     for (int i = 1; i < n; i++)
     {
     	uc = UCLN (uc, a[i]);
	 }
	 cout << uc;
}

int main ()
{
	int a[MAX]; 
	int n, x;
	cout << "\n Nhap n: "; cin >> n;
	cout << "\n\t NHAP MANG\n";
	NhapMang(a, n);
	Tim_UCLN(a, n);
//	XuatMang(a, n);
	return 0;
}
