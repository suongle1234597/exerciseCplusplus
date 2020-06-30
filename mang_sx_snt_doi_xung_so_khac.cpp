// // Cho mang 1 chieu cac so nguyen. Viet chuong trinh xoa cac phan tu la so doi xung.

#include <iostream>
#include <math.h>
#define MAX 100
using namespace std;

void NhapMang (int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " Nhap phan tu a[" << i << "] : ";
		cin >> a[i];
	}
}

void XuatMang (int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

bool KT_doi_xung (int n)
{
	int sodaonguoc = 0;
	int m = n;
	while (m != 0)
	{
		sodaonguoc = (sodaonguoc * 10) + (m % 10);
		m = m / 10;
	}
	if (n == sodaonguoc && n > 10) return true;
	else return false;
}

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

void Sap_Xep(int a[], int n) 
{
	int i = 0, j = n - 1, tam, tam1;
	do{
		while(Kiem_Tra_SNT(a[i]) == true) {
			if(KT_doi_xung(a[i]) == true) {
				tam1 = a[i];
			}
			else {
				i++;
			}
			
		}
		while(KT_doi_xung(a[j]) == false && Kiem_Tra_SNT(a[j]) == false) j--;
		if(i <= j) {
			tam = a[i];
			a[i] = a[j];
			a[j] = tam;
			i++; j--;
		}
		a[i + 1] = tam1;
	} while(i<=j);
}
 
int main ()
{
	int a[MAX], n;
	cout << "\n Nhap n:"; cin >> n;
	cout << "\n\t NHAP MANG\n";
	NhapMang (a, n);
	Sap_Xep(a, n);
	cout << "\n\t MANG SAU KHI SAP XEP\n";
	XuatMang (a, n);
	return 0;
}
