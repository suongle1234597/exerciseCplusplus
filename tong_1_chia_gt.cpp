//  Nhap vao so nguyen n (n>0). Tinh tong S(n) = 1 + 1/1x2 + 1/1x2x3 + ...+ 1/1x2x3....n

#include <iostream>
using namespace std;
 
int main ()
{
	int n, t=1;
	float s=0;
	cout << "\n Nhap n: "; cin >> n;
	do
	{
		if (n<0)
		{
			cout << " Nhap lai n (n>0) : "; cin >> n;
		}
	} while (n<0);
	for (int i=1; i<=n; i++)
	{
		t=t*i;
		s=s+(float)1/t;
	}
	cout << " Ket qua la: " << s;
	return 0;
}
