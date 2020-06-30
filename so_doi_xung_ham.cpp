// So doi xung - HAM

#include <iostream>
using namespace std;

bool Kiem_Tra (int n)
{
	int i, m, sodaonguoc = 0;
	m = n;
	while (n > 0)
	{
		sodaonguoc = sodaonguoc*10 + (n%10);
		n=n/10;
	}
	if (sodaonguoc == m) return true;
	else return false;
}

int TongCacChuSoCuaMotSo(int n) {
        int i, tong = 0;
        while(n > 0) {
            i = n % 10;
            n = n / 10;
            tong = tong + i;
        }
        return tong;
}
    
int main ()
{
	int n;
	cout << "\n Nhap n: "; cin >> n;
	do
	{
		if (n <= 0)
		{
			cout << " Nhap lai n: "; cin >> n;
		}
	} while (n <= 0);
//	if (Kiem_Tra(TongCacChuSoCuaMotSo(n)) == true) cout << " n la so doi xung.";
//	else cout << " n KHONG PHAI so doi xung.";
	cout << TongCacChuSoCuaMotSo(n);
	return 0;
}
