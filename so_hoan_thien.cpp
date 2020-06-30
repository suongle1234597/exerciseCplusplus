// Nhap vao so nguyen n (n>0). Kiem tra xem n co phai la so hoan thien hay khong.

#include <iostream>
using namespace std;
 
int main ()
{
	int n, m, i, sodaonguoc=0, s=0;
	cout << "\n Nhap n: "; cin >> n;
	do
	{
		if (n<0)
		{
			cout << " Nhap lai n (n>0) : "; cin >> n;
		}
	} while (n<0);
	for (i=1;i<n;i++)
	{
		if (n%i==0) 
		{
			s=s+i;
		}
	}
	if (n==s) cout << " n la so hoan thien.";
	else cout << " n KHONG PHAI la so hoan thien.";
	return 0;
}
