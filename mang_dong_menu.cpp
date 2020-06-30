/* Cho so nguyen duong n va day so nguyen a1, a2, …, an. Hay thuc hien cac yeu cau sau: 
+ Tinh tong cac so doi xung.
+ Xoa cac phan tu la so doi xung.
+ Them phan tu 0 vao truoc cac so le.
+ Xuat ra cac so nguyen to.
+ Sap xep so nguyen tu tang dan, cac phan tu khac(khong phai so nguyen to) giu nguyen vi tri.
+ Tim gia tri le cuoi cung trong mang.
+ Kiem tra xem mang co toan phan tu la so chan hay khong ?
+ Dem so luong cac gia tri khac nhau trong day so tren.
+ Tinh tong cac gia tri khac nhau trong day so tren.*/

#include <iostream>
using namespace std;

void NhapMang (int *a, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << " Nhap phan tu thu a[" << i << "] : ";
		cin >> a[i];
	}
}

void XuatMang (int *a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

void Cap_Phat_Lai_Vung_Nho (int *&a, int sl_moi, int sl_cu) {
	int *tam = new int[sl_cu];
	for (int i = 0; i < sl_cu; i++) {
		tam[i] = a[i];
	}
	delete[] a;
	
	a = new int[sl_moi];
	for (int i = 0; i < sl_cu; i++) {
		a[i] = tam[i];
	}
	delete[] tam;
}

bool KT_So_Doi_Xung (int n) {
	int tam, sodaonguoc = 0;
	tam = n;
	while (tam > 0) {
		sodaonguoc = (sodaonguoc * 10) + (tam % 10);
		tam /= 10;
	}
	if (n == sodaonguoc && n > 10) return true;
	else return false;
}

int Tong_So_Doi_Xung(int *a, int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		if(KT_So_Doi_Xung(a[i]) == true) tong += a[i];
	}
	return tong;
}

void Xoa(int *&a, int &n, int vt) {
	for (int i = vt + 1; i < n; i++) {
		a[i - 1] = a[i];
	} 
	n--;
	Cap_Phat_Lai_Vung_Nho (a, n, n);
}

void Xoa_PT_So_Doi_Xung(int *&a, int &n) {
	for(int i = 0; i < n; i++) {
		if (KT_So_Doi_Xung(a[i]) == true) {
			Xoa (a, n, i);
			i--;
		}
	}
}

void Them(int a[], int &n, int vt, int x) {
	for (int i = n - 1; i >= vt; i++) {
		a[i + 1] = a[i];
 	}
 	a[vt] = x;
 	n++;
 	Cap_Phat_Lai_Vung_Nho(a, n + 1, n);
} 

void Them_PT_0_Vao_Truoc_So_Le(int *&a, int &n) {
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 != 0) {
			Them (a, n, i - 1, 0);
			i++;
		}
	}
}

bool KT_SNT(int n) {
	bool KT = true;
	if(n < 2) return false;
	else if(n == 2) return true;
	else {
		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				KT = false;
				break;
			}
		}
		if (KT == true) return true;
		else return false;
	}
}

void Xuat_SNT(int *a, int n) {
	for (int i = 0; i < n; i++) {
		if (KT_SNT(a[i]) == true) cout << a[i] << " ";
	}
}

void Sap_Xep(int *a, int n) {
	int tam;
	for (int i = 0; i < n; i++) {
		if (a[i] > a[i + 1]) {
			tam = a[i];
			a[i] = a[i + 1];
			a[i + 1] = tam;
		}
	}
}

void Sap_Xep_SNT(int *a, int n) {
	int dem = 0;
	for(int i = 0; i < n; i++) {
		if (KT_SNT(a[i]) == true) {
			tam[m] = a[i];
			m++;
		}
	}
	Sap_Xep(tam, m);
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(j == dem) a[i] = tam[j];
		}
		dem++;
	}
}

int main () {
	int *a;
	int n, luachon;
	
	while(true)
	{
		system("cls"); // lenh xoa mang hinh
		cout << "\n\tMENU MANG DONG\n";
        cout << "\n1.Nhap mang. ";
    	cout << "\n2.Tinh tong cac so doi xung.";
     	cout << "\n3.Xoa cac phan tu la so doi xung.";
     	cout << "\n4.Them phan tu 0 vao truoc cac so le.";
    	cout << "\n5.Xuat ra cac so nguyen to.";
	cout << "\n6.Sap xep so nguyen to tang dan, cac phan tu khac(khong phai so nguyen to) giu nguyen vi tri.";
	cout << "\n7.Tim gia tri le cuoi cung trong mang.";
	cout << "\n8.Kiem tra xem mang co toan phan tu la so chan hay khong ?";
	cout << "\n9.Dem so luong cac gia tri khac nhau trong day so tren.";
	cout << "\n10.Tinh tong cac gia tri khac nhau trong day so tren.";
	cout << "\n0.Thoat khoi menu.";
	cout << "\n===============================================\n";
	
	cout << "\nNhap lua chon: "; cin >> luachon;
	
	switch (luachon) {
		case 0:
			{
				break;
			}
		case 1: {
			do {
		        cout << " Nhap n: "; cin >> n;
		        if (n <= 0) cout << " Xin nhap lai n." << endl; 
	        } while (n <= 0);
	        a = new int[n];
			NhapMang(a, n);
			break;
		}
		case 2: {
			cout << " Tong cac so doi xung la: " << Tong_So_Doi_Xung(a, n);
			break;
		}
		case 3: {
			cout << " Mang sau khi XOA la: ";
			Xoa_PT_So_Doi_Xung(a, n);
			XuatMang(a, n);
			break;
		}
		case 4: {
			cout << " Mang sau khi THEM la: ";
			XuatMang(a, n);
			Them_PT_0_Vao_Truoc_So_Le(a, n);
			break;
		}
		case 5: {
			cout << " Cac so nguyen to cua mang la: ";
			Xuat_SNT(a, n);
			break;
		}	
		case 6: {
			cout << " Sap xep cac so nguyen to trong mang: ";
			Sap_Xep_SNT(a, n);
			break;
		}	
		case 7: {
			cout << " Tim gia tri le trong mang: ";
			
			break;
		}
		default: {
			cout << "\nLua chon cua ban khong dung!";
			break;
		}
	}	
	}
	
	
	return 0;
	
}
