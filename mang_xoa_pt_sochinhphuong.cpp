// // Cho mang 1 chieu cac so nguyen. Viet chuong trinh xoa cac phan tu la so chinh phuong.

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

void Xoa (int a[], int &n, int vt)
{
	for (int i = vt + 1; i < n; i++)
	{
		a[i - 1] = a[i];
	}
	n--; 
}

bool KT_So_Chinh_Phuong (int n)
{
	int i = sqrt (n);
	if (i * i == n) return true;
	else return false;
} 

void Xoa_PT_So_Chinh_Phuong (int a[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		if (KT_So_Chinh_Phuong (a[i]) == true) 
		{
			Xoa (a, n, i);
			i--;
		}
	}
	
}
 
int main ()
{
	int a[MAX], n;
	cout << "\n Nhap n:"; cin >> n;
	cout << "\n\t NHAP MANG\n";
	NhapMang (a, n);
	cout << "\n\t MANG SAU KHI XOA PT SO CHINH PHUONG\n";
	Xoa_PT_So_Chinh_Phuong (a, n);
	XuatMang (a, n);
	return 0;
}
