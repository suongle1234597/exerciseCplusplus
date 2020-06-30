// Nhap vao mot so nguyen duong n (n>=10). Tim chu so lon nhat trong n.

#include <iostream>
using namespace std;

int TimMax (int n)
{
	int i, max = 0;
	while (n>=10)
	{
		i = n % 10;
		n = n / 10;
		if (i >= max) max=i;
	}
	return max;
}

int main ()
{
	int n;
	do
	{
		cout << "\n Nhap n: "; cin >> n;
	} while (n<10);
	cout << " Chu so lon nhat trong n la: " << TimMax (n);
	return 0;
}
