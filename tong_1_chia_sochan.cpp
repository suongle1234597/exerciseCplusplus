//  Nhap vao so nguyen n (n>0). Tinh S(n) = 1/2 + 1/4 +...+ 1/2n

#include <iostream>
using namespace std;
 
int main ()
{
	int n, i; 
	float s=0;
	cout << "\n Nhap n: "; cin >> n;
	do
	{
		if (n<0)
		{
			cout << " Nhap lai n (n>0) : "; cin >> n;
		}
	} while (n<0); 
	for (i=1; i<=n; i++)
	{
		if (i%2==0)
		{
			s=s+(float)1/(2*i);
		}
	}
	cout << " S(n)= " << s;
	return 0;
}
