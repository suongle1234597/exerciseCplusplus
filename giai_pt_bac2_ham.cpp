// Giai pt bac 2 - HAM

#include <iostream>
#include <math.h>
using namespace std;

void GiaiPT (float a, float b, float c)
{
	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0) cout << " Phuong trinh vo so nghiem.";
			else cout << " Phuong trinh vo nghiem.";
		}
		else 
		{
			if (c == 0) cout << " Phuong trinh co nghiem x = 0.";
			else cout << " Phuong trinh co nghiem x = " << -(float)c/b;
		}
	}
	else
	{
		float delta = b*b - 4*a*c;
		if (delta < 0) cout << " Phuong trinh vo nghiem.";
		else if (delta == 0)
		{
			cout << " Phuong trinh co nghiem kep x1 = x2 = " << -(float)b/(2*a*c);
		}
		else
		{
			cout << " Phuong trinh co nghiem x1 = " << (float)(-b-sqrt(delta))/(2*a);
			cout << "\n Phuong trinh co nghiem x2 = " << (float)(-b+sqrt(delta))/(2*a);
		}
	}
}

int main ()
{
	int a, b, c;
	cout << "\n Nhap a: "; cin >> a;
	cout << " Nhap b: "; cin >> b;
	cout << " Nhap c: "; cin >> c;
	GiaiPT (a, b, c);
	return 0;
}
