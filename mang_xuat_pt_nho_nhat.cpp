// Nhap 1 mang so thuc. Viet chuong trinh tim phan tu nho nhat trong mang

#include <iostream>
#define MAX 100
using namespace std;

void NhapMang (float a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " Nhap phan tu a[" << i << "] : ";
		cin >> a[i];
	}
}

float XuatMang (float a[], int n)
{
	float min;
	min = a[0];
	for (int i = 0; i < n; i++)
	{
	    if (a[i] < min) min = a[i];
	}
	return min;
}

int main ()
{
	float a[MAX];
	int n;
	cout << "\n Nhap n: "; cin >> n;
	NhapMang (a, n);
	cout << XuatMang (a, n);
	return 0;
}
