// Tinh S(n)= x + x^3/3! + x^5/5!+...+x^(2n+1)/(2n+1)! . x nhap tu ban phim

#include <iostream>
#include <math.h>
using namespace std;

float TinhTong (float x, float n)
{
    float i, s = x, t1 = 1, t2 = 1;
	if (n == 0) s = 1;
	for (i = 1; i <= n; i++)
	{
		t1 = pow (x, 2*i+1);
		t2 = t2*2*i*(2*i+1);
		s = s + (float)t1/t2;
	}
	return s;
}
int main ()
{
	int x, n;
	cout << "\n Nhap x: "; cin >> x;
	cout << " Nhap n: "; cin >> n;
	cout << " S(n) = " << TinhTong (x, n);
	return 0;
}
