/* Nhap vao mang 1 chieu cac so nguyen. Viet chuong trinh sap xep so nguyen to tang dan
   Cac phan tu khac(khong phai so nguyen to) giu nguyen vi tri.
VD: 10 7 8 3 9 2 4 5
==> 10 2 8 3 9 5 4 7 */

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

// Kiem tra so nguyen to
bool KT_SNT (int n)
{
	// Ki thuat dat co hieu
	bool KT = true; // gia su n la snt
	if (n < 2)
	return false;
	else
	{
		if (n==2) return true;
		else
		{
			for (int i = 2; i < n; i++)
			{
				if (n % i == 0)
				{
					KT = false;
				    break;  
				}
			}
		}
	}
	return KT;
} 

void SX_PT_SNT (int a[], int n)
{
	int tam[MAX], m = 0, x = 0, dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (KT_SNT(a[i]) == true)
		{
			tam[m] = a[i]; 
			m++;
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (tam[i] > tam[j])
			{
				x = tam[i];
				tam[i] = tam[j];
				tam[j] = x;
			}
		}
    }
	for (int i = 0; i < n; i++)
	{
		if (KT_SNT(a[i]) == true)
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
	SX_PT_SNT (a, n);
	cout << "\n\t Sap xep cac phan tu SNT\n";
	XuatMang(a, n);
	return 0;
}
