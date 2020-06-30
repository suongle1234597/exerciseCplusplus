// So chinh phuong - HAM

#include <iostream>
using namespace std;

bool Kiem_Tra (int n)
{
	bool KT = true;
	for (int i = 1; i <= n; i++)
	{
		if(i*i == n) return true;
	}
	return false;
}
int main ()
{
	int n;
	cout << "\n Nhap n: "; cin >> n;
	if (Kiem_Tra (n) == true) cout << " n la so chinh phuong.";
	else cout << " n KHONG PHAI la so chinh phuong.";
	return 0;
}
