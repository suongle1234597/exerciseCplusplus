/*Lay ra chu so o vi tri k nao do (tinh tu trai sang phai) cua mot so nguyen duong.
vd: Nhap so tu nhien: 1960
Ban muon lay chu so o vi tri nao: k = 3
Chu so o vi tri thu 3 (tu trai sang phai) cua so 1960 la : 6  */

#include <iostream>
using namespace std;

int Lay_k (int n, int k)
{
	int i, j, m, dem = 0;
	m = n;	
	while (n > 0)
	{
		i = n % 10;
		n = n / 10;
		dem++;
	}
	
	while (m > 0)
	{
		j = m % 10;
		m = m / 10;
		dem--;
		if ((dem+1) == k) return j;
	}
}

int main ()
{
	int n, k;
	do
	{
		cout << "\n Nhap n: "; cin >> n;
	} while (n <= 0);
	cout << " Nhap k: "; cin >> k;
	cout << " Chu so o vi tri thu " << k << " (tu trai sang phai) la: " << Lay_k (n, k);
	return 0;
}
