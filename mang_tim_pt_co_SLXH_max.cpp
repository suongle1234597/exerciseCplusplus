/* Cho mang 1 chieu cac so nguyen. Viet chuong trinh tim so co so lan xuat hien nhieu nhat trong mang. */

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

void Tim_PT_Co_SLXH_Max (int a[], int n)
{
	int tam[MAX], m = 0, tam2[MAX], m2 = 0, dem;
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
		dem = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[j] == tam[i]) dem++;
		}
		tam2[m2] = dem;
		m2++;	
    }
    
    int max = tam2[0];
	for (int i = 0; i < m2; i++)
	{
		if (tam2[i] > max) {
			max = tam2[i];
		}
	}
	
	for (int i = 0; i < m2; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (max == tam2[i] && i == j) 
			{
				cout << tam[j] << " ";
				break;
			}
		}
    }
}

int main ()
{
	int a[MAX], n;
	cout << "\n Nhap n:"; cin >> n;
	cout << "\n\t NHAP MANG\n";
	NhapMang (a, n);
	cout << "\n\t Phan tu co so lan xuat hien lon nhat la: \n";
    Tim_PT_Co_SLXH_Max (a, n);
	return 0;
}   
