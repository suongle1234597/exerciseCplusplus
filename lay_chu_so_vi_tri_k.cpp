/* Lay ra chu so o vi tri k nao do (tinh tu phai sang trai) cua mot so nguyen duong.
 vd: Nhap so tu nhien: 1969
Ban muon lay chu so o vi tri nao thu: k = 3
Chu so o vi tri thu 3 (tu phai sang trai) cua so 1969 la : 9 */

#include <iostream>
using namespace std;

int Lay_k (int n, int k)
{
	int i, dem = 0;
	while (n > 0)
	{
		i = n % 10;
		n = n / 10;
		dem++;
		if (dem == k) return i;
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
	cout << " Chu so o vi tri thu " << k << " (tu phai sang trai) la: " << Lay_k (n, k);
	return 0;
}
