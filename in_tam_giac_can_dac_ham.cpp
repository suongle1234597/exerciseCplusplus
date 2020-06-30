/* Viet ham in ra tam giac can voi chieu cao h
Vi du: h=4
                      *
                    * * *
                  * * * * *
                * * * * * * *                 */
                
#include <iostream>
using namespace std;

void TamGiacCan (int h)
{
	for (int i=1; i<=h; i++)
	{
		for (int j=1; j<=(2*h-1); j++)
		{
			if (j>=h-i+1 && j<=h+i-1)
			cout << "* ";
			else cout << "  ";
		}
		cout << endl;
	} 
}
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
	TamGiacCan (h);
	return 0;
}
                
