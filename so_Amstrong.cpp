/* Kiem tra so nguyen duong n co phai so Amstrong
   vd: 153 la so Amstrong vi 1^3 + 5^3 +3^3 = 153
       1634 la so Amstrong vi 1^4+6^4+3^4+4^4 = 1634 */

#include <iostream>
#include <math.h>
using namespace std;

bool KiemTra (int n)
{
	int i, j, k, m, dem = 0, s = 0;
	m = n;
	k = n;
	while (n > 0)
	{
		n = n / 10;
		dem++;
	}
	while (m > 0)
	{
		j = m % 10;
		m = m / 10;
		s = s + pow (j, dem);
	}
	
	if (s == k) return true;
	else return false;
}

int main ()
{
	int n;
	do
	{
		cout << "\n Nhap n: "; cin >> n;
	} while (n <= 0);
	if (KiemTra (n) == true) cout << " n la so Amstrong.";
	else cout << " n KHONG PHAI la so Amstrong.";
	return 0;
}
