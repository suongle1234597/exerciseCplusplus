// Nhap vao mang co n phan tu. Xuat ra phan tu xuat hien nhieu nhat va xuat ra dia chi do

#include <iostream>
#define MAX 100

using namespace std;

void Nhap_Mang(int *a, int n) {
	for(int i = 0; i < n; i++) {
		cout << "Nhap phan tu a[" << i << "] : ";
		cin >> a[i];
	}
}

void Tim_PT_Doc_Lap (int *a, int n, int tam[], int &m) {
	m = 0;
	for (int i = 0; i < n; i++)
	{
		bool KT = true; // gia su i la so doc lap
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[i] == a[j])
			{
				KT = false;
				break;
			}
			
		}
		if (KT == true)
		{
		    tam[m] = a[i];
		    m++; 
		}
	}
}

void Dem_SLXH(int *a, int n, int tam[], int m, int tam2[], int &m2) {
	int dem;
	m2 = 0;
	for (int i = 0; i < m; i++)
	{
		dem = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[j] == tam[i]) dem++;
		}
		tam2[m2] = dem;
		m2++;	
    }
}

void Tim_PT_Co_SLXH_Max (int tam[], int m, int tam2[] , int m2, int tam3[], int &m3)
{
	int max = tam2[0];
	for (int i = 0; i < m2; i++)
	{
		if (tam2[i] > max) {
			max = tam2[i];
		}
	}
	
	m3 = 0;
	for (int i = 0; i < m2; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (max == tam2[i] && i == j) 
			{
				tam3[m3] = tam[j];
				m3++;
				break;
			}
		}
    }
}

void Lay_Dia_Chi(int *a, int n, int tam3[], int m3) {
	for(int i = 0; i < m3; i++) {
		for(int j = 0; j < n; j++) {
			if(tam3[i] == a[j]) {
				cout << "a[" << j << "] : "<<a[j] << " : " << &a[j] << endl;
			}
		}
	}
}

int main ()
{
	int n;
	int tam[MAX], m, tam2[MAX], m2, tam3[MAX], m3;
	cout << "\n Nhap n: "; cin >> n;
	int *a = new int [n];
	cout << "\n\t NHAP MANG\n";
	Nhap_Mang (a, n);
	cout << "\n\t SO LAN XUAT HIEN CUA CAC PHAN TU\n";
	Tim_PT_Doc_Lap(a, n, tam, m);
	Dem_SLXH(a, n, tam, m, tam2, m2);
    Tim_PT_Co_SLXH_Max (tam, m, tam2, m2, tam3, m3);
    Lay_Dia_Chi(a, n, tam3, m3);
	return 0;
} 	

