//  Nhap vao so nguyen n (n>0). Kiem tra xem n co phai la so nguyen to hay khong.

#include <iostream>
using namespace std;
 
int main ()
{
	int n, i;
	cout << "\n Nhap n: "; cin >> n;
	do
	{
		if (n<0)
		{
			cout << " Nhap lai n (n>0) : "; cin >> n;
		}
	} while (n<0);

   // Cach 1:  
	if (n<2) cout << " n KHONG PHAI la so nguyen to.";
	else
	{
		for (i=2; i<n; i++)
		{
			if (n%i==0) 
			{
				cout << " n KHONG PHAI la so nguyen to.";
				break;
			}
		}
	}
	if (i==n)
	cout << " n la so nguyen to.";
	return 0;
	/*Cach 2: dung dem
	int dem=0;
	for (i=1; i<=n; i++)
	{
		if (n%i==0) dem++;
	}
	if (dem==2) cout << " n la so nguyen to";
	else cout << "n KHONG PHAI la so nguyen to.";
	return 0;*/
}
