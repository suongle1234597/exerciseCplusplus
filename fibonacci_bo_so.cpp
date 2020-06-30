/* Day Fibonacci la day so ma so tiep theo la tong cua hai so lien truoc. 
Day Fibonacci bat dau tu hai so F0 & F1. Gia tri ban dau cua F0 & F1 có the tuong ung là 0, 1 hoac 1, 1.
Cho cong thuc cua day Fibonacci nhu sau:
F(0) = F(1) = 1
F(n) = F(n-1) + F(n-2)
Ta co day Fibonacci nhu sau: 1 1 2 3 5 8 13 21 34 55 89 144....
Cho so nguyen khong am n, hay tinh Fn
VD: 
0 --> 1
1 --> 1
2 --> 2
5 --> 8
3 --> 3 */ 

#include <iostream>
using namespace std;

int Tinh (int n)
{
	int F0 = 1, F1 = 1, Fn;
	if (n == 0 || n == 1) Fn = F0;
	else
	{
	    for (int i = 2; i <= n; i++)
		{
			Fn = F0 + F1;
			F0 = F1;
			F1 = Fn;
		}
	}
	return Fn; 
}

int main ()
{
	int n, m;
	do
	{
		cout << "\n Nhap bo so test: "; cin >> m;
	} while (m < 0);
	for (int i = 1; i <= m; i++) {
		cout << " Nhap vi tri: "; cin >> n;
		cout << " Fn = " << Tinh (n);
		cout << endl;
	}
	return 0;
}
