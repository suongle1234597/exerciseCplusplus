// Nhap vao so nguyen n (n>0). Kiem tra xem n co phai la so doi xung hay khong.

#include <iostream>
using namespace std;
 
int main ()
{
	int n, m, i, sodaonguoc=0;
	cout << "\n Nhap n: "; cin >> n;
	do
	{
		if (n<0)
		{
			cout << " Nhap lai n (n>0) : "; cin >> n;
		}
	} while (n<0);
	m=n; 
	while (n>0)
	{
		sodaonguoc=sodaonguoc*10+(n%10);
		n=n/10;
	}
	if (m==sodaonguoc) cout << " n la so doi xung.";
	else cout << " n KHONG PHAI la so doi xung.";
	return 0;
}	
