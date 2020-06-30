// Cho mang 1 chieu cac so nguyen. In ra cac phan tu ke nhau ma ca 2 deu chan

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

void KiemTra (int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if ((a[i] % 2 == 0) && ((a[i+1]) % 2 == 0)) 
		cout << a[i] << " " << a[i+1];
	}
}

int main ()
{
	int a[MAX], n;
	cout << "\n Nhap n: "; cin >> n;
	cout << "\n\t NHAP MANG\n";
	NhapMang (a, n);
	cout << "\n\t XUAT MANG\n";
	XuatMang (a, n);
	cout << "\n\t XUAT 2 PT KE NHAU\n";
	KiemTra (a, n);
	return 0;
}



