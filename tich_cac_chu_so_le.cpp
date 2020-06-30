// Nhap vao so nguyen n (n>0, n la so chan. Tinh tich cac "chu so le" cua so nguyen duong n

#include <iostream>
using namespace std;
 
int main ()
{
	int n, i, t=1, dem=0;
	cout << "\n Nhap n: "; cin >> n;
	do
	{
		if ((n<=0 || n%2!=0))
		{
			cout << " Nhap lai n (n>0, n la so chan) : "; cin >> n;
		}
	} while ((n<=0 || n%2!=0));
	while (n>0)
	{
		i=n%10;
		n=n/10;
		if (i%2!=0) 
		{
			t=t*i;
			dem++;
		}
	}
	if (dem==0) cout << " Tich cac CHU SO LE cua so nguyen duong n la: 0";
	else cout << " Tich cac CHU SO LE cua so nguyen duong n la: " << t;
	return 0;
}	
