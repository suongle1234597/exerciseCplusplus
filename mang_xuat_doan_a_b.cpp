/* Cho mang 1 chieu cac so nguyen. 
   Viet chuong trinh tim doan [a, b] sao cho doan nay chua moi gia tri trong mang. */
   
#include <iostream>   
using namespace std;

void TimDoan (int a[])
{
	int min = a[0], max = 0;
	for (int i = 0; i < 9; i++)
	{
		if (a[i] <= min) min = a[i];
		if (a[i] > max) max = a[i];
	}
	cout << " Doan [a,b] la: [" << min << "," << max << "]";
}

int main ()
{
	int a[9] = {3,6,8,1,4,2,6,7,2};
	TimDoan(a);
	return 0;
}
