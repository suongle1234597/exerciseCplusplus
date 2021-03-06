/* Nhap vao mang 1 chieu cac so nguyen. Viet chuong trinh sap xep cac phan tu chan giam dan.
   Cac phan tu khong phai la so chan thi giu nguyen vi tri*/

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

void SX_PT_Chan (int a[], int n)
{
	int tam[MAX], m = 0, x = 0, dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			tam[m] = a[i]; 
			m++;
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (tam[i] < tam[j])
			{
				x = tam[i];
				tam[i] = tam[j];
				tam[j] = x;
			}
		}
    }
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			for (int j = 0; j < m; j++)
			{
				if (dem == j) 
				{
					a[i] = tam[j];
				}
			}
			dem++;
		}
	}
	
}

int main ()
{
	int a[MAX]; 
	int n, x;
	cout << "\n Nhap n: "; cin >> n;
	cout << "\n\t NHAP MANG\n";
	NhapMang(a, n);
	SX_PT_Chan (a, n);
	cout << "\n\t Sap xep cac phan tu chan\n";
	XuatMang(a, n);
	return 0;
}
