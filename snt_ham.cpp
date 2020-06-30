// Kiem tra so nguyen to - HAM

#include <iostream>
using namespace std;
 
// Kiem tra so nguyen to
bool Kiem_Tra_SNT (int n)
{
	// Ki thuat dat co hieu
	bool KT = true; // gia su n la snt
	if (n < 2)
	return false;
	else
	{
		if (n==2) return true;
		else
		{
			for (int i = 2; i < n; i++)
			{
				if (n % i == 0)
				{
					KT = false;
				    break;  
				}
			}
		}
	}
	return KT;
} 
 
int main ()
{
	int n;
	cout << "\n Nhap n: "; cin >> n;
	if (Kiem_Tra_SNT (n) == true) cout << " n la so nguyen to.";
	else cout << " n KHONG PHAI la so nguyen to.";
	return 0;
}	
