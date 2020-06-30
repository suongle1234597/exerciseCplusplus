/* DOI VO
- Nha ban A có n doi vo, moi ngay ban A mang 1 doi, mang xong thi vut bo.
- Cu m ngay thi me ban A mua them cho A mot doi vo moi.
- Hoi ban A mang vo bao nhieu ngay thi het vo de mang.
vd1:
INPUT: m = 2, n = 2
OUTPUT: 3
vd2: INPUT: m = 3, n = 9
OUTPUT: 13
*/

#include <iostream>
using namespace std;
 
int TinhNgay (int n, int m)
{
	int j, a=1, dem=0;
		for (int i=1; i<=n; i++)
	{
		if ((i-a+1)==m) 
		{
			dem++;
			a=i;
		}
	}
	return n+dem;
} 
int main ()
{
	int n, m;
	cout << "\n Nhap n: "; cin >> n;
	cout << " Nhap m: "; cin >> m;
	do
	{
		if (n<0 || m<0 )
		{
			cout << " Nhap lai n (n>0) : "; cin >> n;
			cout << " Nhap lai m (m>0) : "; cin >> m;
		}
	} while (n<0 || m<0); 
	cout << " A mang vo " << TinhNgay (n, m) << " ngay thi het vo de mang.";
	return 0;
}	
