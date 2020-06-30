/* Viet chuong trinh kiem tra xem so nguyen duong n co phai la so "sieu nguyen to" hay khong.
   So sieu nguyen to la so nguyen to ma khi loai bo mot so tuy y so ben phai cua no thi phan con lai van tao thanh mot so nguyen to*/
   
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

bool KiemTra (int n)
{
	int i;
	while (n>0)
	{
		if (KT_SNT(n) == true) 
		n = n / 10;
		else return false;
	}
	return true;
}

int main ()
{
 	int n;
 	cout << "\n Nhap n: "; cin >> n;
 	if (KiemTra (n) == true) cout << " n la so sieu nguyen to.";
 	else cout << " n KHONG PHAI la so sieu nguyen to.";
 	return 0;
}
