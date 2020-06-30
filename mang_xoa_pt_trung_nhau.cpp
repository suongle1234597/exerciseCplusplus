/* Cho mang 1 chieu cac so nguyen. Viet chuong trinh xoa cac phan tu trung nhau trong mang. 
   Chi giu lai duy nhat mot phan tu phan biet
   VD: 1 2 4 2 1 5
   ==> 1 2 4 5 */

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

void Xoa (int a[], int &n, int vt)
{
	for (int i = vt + 1; i < n; i++)
	{
		a[i - 1] = a[i];
	}
	n--; 
}

void Xoa_PT_Trung_Nhau (int a[], int &n)
{
	for (int i = 0; i < n; i++)
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
	int a[MAX], n;
	cout << "\n Nhap n:"; cin >> n;
	cout << "\n\t NHAP MANG\n";
	NhapMang (a, n);
	cout << "\n\t MANG SAU KHI XOA PT TRUNG NHAU\n";
	Xoa_PT_Trung_Nhau (a, n);
	XuatMang (a, n);
	return 0;
}   
