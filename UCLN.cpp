// Nhap vao 2 so nguyen a va b (a, b > 0). Tim UCLN cua 2 so a va b

#include <iostream>
using namespace std;
 
int main ()
{
	int a, b, i, max;
	do
	{
		{
			cout << "\n Nhap a (a>0):"; cin >> a;
			cout << " Nhap b (b>0):"; cin >> b;
		}
	} while (a*b<=0);
	if (a>b)
	{
		for (i=1; i<=b; i++)
		{
			if(a%i==0 && b%i==0) max=i;
		}
	} 
	else
	{
		for (i=1; i<=a; i++)
		{
			if (a%i==0 && b%i==0) max=i;
		}
	}
	cout << " Uoc chung lon nhat cua a va b la: " << max;
	return 0;
}
