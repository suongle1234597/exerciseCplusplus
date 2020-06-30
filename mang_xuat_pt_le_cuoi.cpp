// Cho mang 1 chieu so nguyen. Viet chuong trinh tim gia tri LE cuoi cung trong mang

#include <iostream>
using namespace std;

bool KT_so_le (int n)
{
	if (n % 2 != 0) return true;
	else return false;
}

void XuatMang (int a[])
{
	int s = 0;
	for (int i = 4; i >= 0; i--)
	{
		if (KT_so_le(a[i]) == true) 
		{
			cout << "\n Phan tu le cuoi cung cua mang la: " << a[i];
			break;
		}
	}
}

int main ()
{
	int a[5] = {1, 2, 3, 4, 5};
	XuatMang (a);
	return 0;
}
