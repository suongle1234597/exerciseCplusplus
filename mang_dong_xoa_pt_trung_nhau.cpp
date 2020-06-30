// Xoa cac phan tu trung trong mang dong

#include <iostream>
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

void Cap_Phat_Lai_Vung_Nho (int *&a, int sl_moi, int sl_cu)
{
	int *tam = new int [sl_cu];
	for (int i = 0; i < sl_cu; i++)
	{
		tam[i] = a[i];
	}
	delete []a;
	a = new int [sl_moi];
	for (int i = 0; i < sl_cu; i++)
	{
		a[i] = tam[i];
	}
	delete []tam;
}

void Xoa (int *&a, int &n, int vt)
{
	for (int i = vt + 1; i < n; i++)
	{
		a[i - 1] = a[i];
	}
	n--;
	Cap_Phat_Lai_Vung_Nho(a, n, n);
}

void Xoa_PT_Trung_Nhau (int *&a, int &n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] == a[j])
			{
				Xoa (a, n, j);
				j--;
			}
		}
	}
}

int main ()
{
	int *a;
	int n;
	do
	{
		cout << "\n Nhap phan tu mang: ";
		cin >> n;
		if (n <= 0)
		{
			cout << " So luong mang khong hop le";
		}
	} while (n <= 0);
	a = new int [n];
	cout << "\n\t NHAP MANG\n";
	NhapMang (a, n);
	cout << "\n\t XUAT MANG\n";
	XuatMang (a, n);
	Xoa_PT_Trung_Nhau (a, n);
	cout << "\n\t MANG SAU KHI XOA\n";
	XuatMang (a, n);
	return 0;
}
