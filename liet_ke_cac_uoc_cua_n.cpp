// Nhap vao so nguyen n (n>5 va la mot so chan). Liet ke tat ca cac uoc so cua so nguyen n.

#include <iostream>
using namespace std;
 
int main ()
{
	int n, i, s=0;
	cout << "\n Nhap n: "; cin >> n;
	do
	{
		if (n<5 || n%2!=0)
		{
			cout << " Nhap lai n (n>5 va la mot so chan) : "; cin >> n;
		}
	} while (n<5 || n%2!=0);
	cout << " Cac uoc so cua n la: ";
	for (int i=1; i<=n; i++)
	{
		if (n%i==0) cout << i << " ";
	}
	return 0;
}
