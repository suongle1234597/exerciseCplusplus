// Liet ke cac uoc cua n - HAM

#include <iostream>
using namespace std;

void Liet_Ke_Uoc (int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0) cout << i << " ";
	}
}

int main ()
{
	int n;
	cout << " \n Nhap n: "; cin >> n;
	Liet_Ke_Uoc (n);
	return 0;
}
