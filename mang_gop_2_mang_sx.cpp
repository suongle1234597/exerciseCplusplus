/* Cho 2 mang 1 chieu cac so nguyen. Viet chuong trinh tren 2 mang lai voi nhau tro thanh 1 mang duoc sap thu tu tang dan.
VD:
A: 3 5 2 1
B: 1 7 8 2 9
==> C: 1 1 2 2 3 5 7 8 9 */

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

void SapXep (int a[], int n)
{
	int tam;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				tam = a[i];
				a[i] = a[j];
				a[j] = tam;
			}
		}
    }
}

void GopMang (int a[], int n, int b[], int m)
{
	int tam[MAX], k = 0;
	for (int i = 0; i < n; i++)
	{
		tam[k] = a[i];
		k++;
		for (int j = 0; j < m; j++)
		{
			if (i == j) 
			{
				tam[k] = b[j];
				k++;
			}
		}
    }
    for (int i = 0; i < k; i++)
    {
    	SapXep (tam, k);
    	cout << tam[i] << " ";
	}
}

int main ()
{
	int a[MAX], b[MAX], n, m;
	cout << " Nhap n: "; cin >> n;
	cout << "\n\t NHAP MANG a:\n";
	NhapMang (a, n);
	cout << " Nhap m: "; cin >> m;
	cout << "\n\t NHAP MANG b:\n";
	NhapMang (b, m);
	cout << "\n\tMang sau khi gop: ";
	GopMang (a, n, b, m);
	return 0;
}
