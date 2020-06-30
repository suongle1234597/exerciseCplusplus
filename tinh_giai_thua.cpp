// Nhap vao so nguyen n (0<n<20). Tinh giai thua n.

#include <iostream>
using namespace std;

int main ()
{
	int n, t=1;
	cout << "\n Nhap n: "; cin >> n;
	do
	{
		if (n<0 || n >=20)
		{
			cout << " Nhap lai n (n>0) : "; cin >> n;
		}
	} while (n<0 || n >=20);
	for (int i=1; i<=n; i++)
	{
		t=t*i;
	}
	cout << " Giai thua cua n la: " << t;
	return 0;
}
