// Nhap vao 2 so nguyen a va b (a, b > 0). Tim BCNN cua 2 so a va b

#include <iostream>
using namespace std;
 
int main ()
{
	int a, b, i, min=0, max=0;
	do
	{
		{
			cout << "\n Nhap a (a>0):"; cin >> a;
			cout << " Nhap b (b>0):"; cin >> b;
		}
	} while (a*b<=0);
	// Cach 1:
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
	cout << " BCNN cua a va b la: " << (a*b)/max;
	return 0;
	/* Cach 2:
	if (a>b)
	{
		for (i=b; i<=(a*b); i++)
		{
			if(i%a==0 && i%b==0)
			{
				min=i;
				break;
			}
		}
		cout << " BCNN cua a va b la: " << min;
	} 
	else
	{
		for (i=a; i<=(a*b); i++)
		{
			if(i%a==0 && i%b==0)
			{
				min=i;
				break;
			}
		}
		cout << " BCNN cua a va b la: " << min;
		return 0;
	}*/
}
