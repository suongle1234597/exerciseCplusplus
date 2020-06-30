// Tim cac so nguyen to nho hon so nguyen duong n cho truoc.

#include <iostream>
using namespace std;

bool KT_SNT (int n)
{
	bool KT_SNT = true;
	if (n < 2) return false;
	else if (n == 2) return true;
	else
	{
		for (int i = 2; i < n; i++)
		{
			if (n % i ==0) return false;
		}
	}
	return true;
} 

void TimSNT (int n)
{
	for (int i = 1; i < n; i++)
	{
		if (KT_SNT(i) == true) cout << i << " ";;
	}
}

int main ()
{
	int n;
	cout << "\n Nhap n: "; cin >> n;
	TimSNT (n);
	return 0;
}
