//  Nhap vao so nguyen n (n>0). Tinh S(n) = 1/2 + 3/4 + 5/6 + ...+ (2n + 1)/(2n + 2)

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
	for (i=0; i<=n; i++)
	{
		s=s+(float)(2*i+1)/(2*i+2);
	}
	cout << " S(n)= " << s;
	return 0;
}
