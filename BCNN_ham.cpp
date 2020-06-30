// Ham_BCNN

#include <iostream>
using namespace std;

int BCNN (int a, int b)
{
	int i, min=0, max=0;
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
    }
    return min;
}
int main ()
{
	int c, d;
	do
	{
		cout << "\n Nhap c (c>0):"; cin >> c;
		cout << " Nhap d (d>0):"; cin >> d;
	} while (c*d<=0);
	cout << " BCNN cua a va b la: " << BCNN (c, d);
	return 0;
}
