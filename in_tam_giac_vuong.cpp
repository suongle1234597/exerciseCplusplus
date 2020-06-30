/* Viet ham in ra tam giac vuong voi chieu cao h
Vi du: h=4
* * * *
* * *
* *
*                                                 */

#include <iostream>
using namespace std;

int main ()
{
	int h;
	cout << "\n Nhap chieu cao h: "; cin >> h;
	do
	{
		if (h<0)
		{
			cout << " Nhap lai h (h>0) : "; cin >> h;
		}
	} while (h<0);
	for (int i=1; i<=h; i++)
	{
		for (int j=i; j<=h; j++) 
		{
			cout << "* ";
		}
		cout << endl;
	} 
	/*	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j>=n-i+1)
			cout << "* ";
		}    
		    cout << endl;
	}*/
	
	/*	for (int i=1; i<=h; i++)
	{
		for (int j=1; j<h; j++)
		{
			if (j>=h-i+1)
			cout << "*";
			else cout << " ";
		}
		for (int j=h+1; j<h+1; j++)
		cout << "*";
		cout << endl;
	}*/
	
	return 0;
}

