// Nhap vao so nguyen n (n>0). Kiem tra xem n co phai la so chinh phuong hay khong.

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
	for (i=1; i<=n/2; i++)
	{
		if ((i*i)==n) 
		{
			cout << " n la so chinh phuong.";
			break;
		}
	}
	if (i*i!=n) cout << " n KHONG PHAI la so chinh phuong.";
	return 0;
}
