// Tinh S(n)= 1 + x^2/2! + x^4/4!+...+(x^(2n))/(2n)! (x nhap tu ban phim)

#include <iostream>
using namespace std;

float Tinh_Tong (float x, float n)
{
    float i, s = 1, t1 = 1, t2 = 1;
	if (n == 0) s = 1;
	for (i = 1; i <= n; i++)
	{
		t1 = t1*x*x;
		t2 = t2*2*i*(2*i-1);
		s = s + (float)t1/t2;
	}
	return s;
}

int main ()
{
	int x, n;
	cout << "\n Nhap x: "; cin >> x;
	cout << " Nhap n: "; cin >> n;
	cout << " S(n) = " << Tinh_Tong (x, n);
	return 0;
}
