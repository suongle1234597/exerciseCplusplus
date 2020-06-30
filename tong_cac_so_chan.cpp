// Nhap vao so nguyen n (n>0). Tinh tong 2 + 4 + 6 +...+ (2*n)

#include <iostream>
using namespace std;
 
int main ()
{
	int n, s=0;
	cout << "\n Nhap n: "; cin >> n;
	do
	{
		if (n<0)
		{
			cout << " Nhap lai n (n>0) : "; cin >> n;
		}
	} while (n<0);
	for (int i=1; i<=(2*n); i++)
	{
		if(i%2==0) s=s+i;
	}
	cout << " Tong la: " << s;
	return 0;
}	
