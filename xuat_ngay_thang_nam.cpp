/*Bai 2. Nhap vao thang va nam. Xuat ra so ngay cua tháng dó
Chu y:
- Nam nhuan la nam chia het cho 4 va khong chia het cho 100, hoac la chia het cho 400
- Nhung thang co
+ 30 ngay: 4 6 9 11
+ 31 ngay: 1 3 5 7 8 10 12
- Thang 2 la thang dac biet
+ 28 ngay: nam khong nhuan
+ 29 ngay: nam nhuan*/

#include <iostream>
using namespace std;

int main ()
{
	int thang, nam;
	cout << "\n Nhap thang: "; cin >> thang; 
	do
	{
		if (thang<=0 || thang>12)
		{
			cout << " Xin nhap lai thang: "; cin >> thang;
		}
	} while (thang<=0 || thang>12);
	cout << " Nhap nam: "; cin >> nam;
	if ((nam%4==0 && nam%100!=0) || nam%400==0)
	{
		if (thang==2) cout << " Thang 2 co 29 ngay.";
		else if (thang==4 || thang==6 || thang==9 || thang==11) cout << " Thang nay co 30 ngay.";
		else cout << " Thang nay co 31 ngay.";
	}
	else
	{
		if (thang==2) cout << " Thang 2 co 28 ngay.";
		else if (thang==4 || thang==6 || thang==9 || thang==11) cout << " Thang nay co 30 ngay.";
		else cout << " Thang nay co 31 ngay.";
	}
	return 0;
}
