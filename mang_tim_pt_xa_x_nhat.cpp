/* Cho mang 1 chieu cac so nguyen. Hay tim gia tri trong mang cac so nguyen xa gia tri x nhat(x nhap tu ban phim)
VD: 24 45 23 13 43 -12
x = 15
==> gia tri trong mang xa x nhat la: 45 */

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

void Tim_x (int a[], int n, int x)
{
	int tam[MAX], m = 0, max = fabs(x - a[0]);
	for (int i = 0; i < n; i++)
	{
		tam[m] = fabs(x - a[i]);
		m++;
	}
	for (int i = 0; i < m; i++)
	{
		if (tam[i] > max) max = tam[i];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (max == tam[i] && i == j) 
			{
				cout << a[j] << " ";
				break;
			}
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
	cout << "\n Nhap x: "; cin >> x;
	cout << "\n\t Gia tri xa x nhat la: ";
	Tim_x (a, n, x);
	return 0;
}
