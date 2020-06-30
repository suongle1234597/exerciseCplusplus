/*Bai 3. Nhap vao 1 so nguyen duong n co dung 3 chu so. Viet chuong trinh tinh tong tat ca cac chu so
VD: n = 123
==> 1 + 2 + 3 = 6 
*/

#include <iostream>
using namespace std;
 
int main ()
{
	int n, i, s=0;
	cout << "\n Nhap n: "; cin >> n;
	while (n>0)
	{
		i=n%10;
		n=n/10;
		s=s+i;
	}
	cout << " Tong tat ca cac chu so cua n la: " << s;
	return 0;
}
