/* Cho mang 1 chieu cac so nguyen. Viet chuong trinh dem so lan xuat hien cua tung phan tu trong mang.
  VD: 
1 3 5 2 3 1
==>
Phan tu	So lan xuat hien
1 	2
2	1	
3	2	
5 	1  */

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

void Dem_So_Lan_Xuat_Hien (int a[], int n)
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
	for (int i = 0; i < m; i++)
	{
		int dem = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[j] == tam[i]) dem++;
		}
		cout << tam[i] << " => " << dem << endl;
	}
}

int main ()
{
	int a[MAX], n;
	cout << "\n Nhap n:"; cin >> n;
	cout << "\n\t NHAP MANG\n";
	NhapMang (a, n);
	cout << "\n\t SO LAN XUAT HIEN CUA CAC PHAN TU\n";
    Dem_So_Lan_Xuat_Hien (a, n);
	return 0;
 
} 	
