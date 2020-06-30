// Nhap vao so nguyen n (n>0). Xuat cac "chu so chan" cua so nguyen duong n

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
	cout << " Cac chu so chan cua n la: ";
	while (n>0)
	{
		i=n%10;
		n=n/10;
		if (i%2==0) cout << i << " ";
	}
	return 0;
}	
