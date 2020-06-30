// Cho mang 1 chieu cac so nguyen. Viet chuong trinh xoa cac phan tu la so nguyen to.

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

bool Kiem_Tra_SNT (int n)
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

void Xoa_PT_SNT (int a[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		if (Kiem_Tra_SNT (a[i]) == true) 
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
	cout << "\n\t MANG SAU KHI XOA PT SNT\n";
	Xoa_PT_SNT (a, n);
	XuatMang (a, n);
	return 0;
}
