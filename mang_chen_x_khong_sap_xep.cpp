/* Cho day a gom n so nguyen co thu tu tang dan. Nhap vao 1 phan tu nguyen X.
   Viet chuong trinh chen X vao day so sao cho day van co thu tu tang dan (khong sap xep)*/ 
   
#include <iostream>
#define MAX 100
using namespace std;

void NhapMang (int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " Nhap phan tu a[" << i << "] : "; cin >> n;
	}
}

void XuatMang (int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

void SapXep (int a[], int n) {
	int tam;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[i+1]) {
				tam = a[i];
				a[i] = a[i+1];
				a[i+1] = tam;
			}
		}
    }
}

void Them (int a[], int &n, int vt, int x) {
	for (int i = n - 1; i >= vt; i--) {
		a[i + 1] = a[i];
	}
	a[vt] = x;
	n++;
}

void ThemXVaoDaySo (int a[], int &n, int x) {
	SapXep(a, n);
	for (int i = 0; i < n; i++) {
		if(x >= a[i]) {
			Them(a, n, i + 1, x);
			i++;
		}
	}
}

int main() {
	int a[MAX];
	int n, x;
	cout << "\n Nhap n: "; cin >> n;
	cout << "\n\tNHAP MANG\n";
	NhapMang (a, n);
	cout << " Nhap x: "; cin >> x;
	cout << "\n\tXUAT MANG SAU KHI THEM X\n";
	ThemXVaoDaySo(a, n, x);
	XuatMang (a, n);
	return 0;
}   
