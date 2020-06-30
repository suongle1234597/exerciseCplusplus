/* Tim phan tu lon thu k trong mang 
   VD: 5 2 13 5 6 2
k = 2
==> 6
k = 3
==> 5  */

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

void SapXep (int tam[], int m)
{
	int x = 0;
	for (int i = 0; i < m - 1; i++)
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
}

void Tim_PT_MAX_thu_k (int a[], int n, int k)
{
	int tam[MAX], m = 0;
	for (int i = 0; i < n; i++)
	{
		bool KT = true; // gia su i la so doc lap
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[i] == a[j])
			{
				KT = false;
				break;
			}
		}
		if (KT == true)
		{
		    tam[m] = a[i];
		    m++; 
		}
	}
	SapXep (tam, m);
	for (int i = 0; i < m; i++)
	{
		if (k == i + 1) cout << " " << tam[i];
	}
}

int main ()
{
	int a[MAX];
	int n, k;
	cout << "\n Nhap n: "; cin >> n;
	cout << "\n\t NHAP MANG\n";
	NhapMang (a, n);
	cout << " Nhap k: "; cin >> k;
	Tim_PT_MAX_thu_k (a, n, k);
	return 0;
}
