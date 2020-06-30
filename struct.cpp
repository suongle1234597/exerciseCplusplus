/* Struct: la kieu du lieu do nuoi lap trinh vien dinh nghia
Cu phap:
struct <ten struct>
{
// thanh phan cua struct
<kieu du lieu 1> <ten thanh phan 1>;
<kieu du lieu 2> <ten thanh phan 2>;
}
Viet chuong trinh luu tru thong tin
- Ho ten
- Nam sinh
- Dia chi
- SDT


*/

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

// khai bao cau truc
struct crush {
	string hoten;
	int namsinh;
	string diachi;
	string sdt;
};
typedef struct crush CRUSH; // dinh nghia lai struct crush thanh CRUSH

// ham nhap thong tin cua crush
void Nhap_Thong_Tin_1_Crush(CRUSH &cr) {
	fflush(stdin); //cr.ignore();
	cout << "\n Nhap ho ten: ";
	getline(cin, cr.hoten);
	cout << " Nhap nam sinh: ";
	cin >> cr.namsinh;
	fflush(stdin); //cin.ignore();  xoa bo nho dem <=> khong bi troi lenh
	cout << " Nhap dia chi: ";
	getline(cin, cr.diachi);
	cout << " Nhap so dien thoai: ";
	getline(cin, cr.sdt); 
}

// ham xuat thong tin
void Xuat_Thong_Tin_1_Crush(CRUSH &cr) {
	cout << "\n Ho ten: " << cr.hoten;
	cout << "\n Nam sinh: " << cr.namsinh;
	cout << "\n Dia chi: " << cr.diachi;
	cout << "\n So dien thoai: " << cr.sdt;
}

// ham nhap danh sach crush
void Nhap_Danh_Sach_Crush(CRUSH ds[], int n) {
	for(int i = 0; i < n; i++) {
		cout << "\n\tNhap thong tin crush thu " << i + 1;
		Nhap_Thong_Tin_1_Crush(ds[i]);
	}
}

// ham xuat danh sach crush
void Xuat_Danh_Sach_Crush(CRUSH ds[], int n) {
	for(int i = 0; i < n; i++) {
		cout << "\n\tTHONG TIN CRUSH THU " << i + 1;
		Xuat_Thong_Tin_1_Crush(ds[i]);
	}
}

// ham tim kiem ho ten crush
CRUSH Tim_Kiem_Ho_Ten (CRUSH ds[], int n, string hoten) {
	CRUSH tam;
	tam.hoten = " ";
	tam.namsinh = 0;
	tam.diachi = " ";
	tam.sdt = " ";
	for(int i = 0; i < n; i++) {
		if(stricmp((char *)ds[i].hoten.c_str(), (char *)hoten.c_str()) == 0) { // ep kieu thanh kieu char de so sanh 2 chuoi
			return ds[i];
		}
    }
    return tam;
}

// ham hoan vi
//void Hoan_Vi (CRUSH &x, CRUSH &t) {
//	CRUSH tam = x; 
//	x = t; 
//	t = tam;
//}

// ham sap xep nam sinh
void Sap_Xep_Nam_Sinh (CRUSH ds[], int n) {
	CRUSH tam;
	for(int  i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if(ds[i].namsinh < ds[j].namsinh) {
				tam = ds[i]; 
				ds[i] = ds[j]; 
				ds[j] = tam;
			}
		}
	}
}

int main() {
	int a;
//	CRUSH cr_1;
//	Nhap_Thong_Tin_1_Crush(cr_1);
//	Xuat_Thong_Tin_1_Crush(cr_1);

	CRUSH ds_crush[100];
	int n;
	
	cout << "\n Nhap so luong crush: "; 
	cin >> n;
	
	cout << "\n\tNHAP DANH SACH CRUSH: " ;
	Nhap_Danh_Sach_Crush(ds_crush, n);
	
	cout << "\n\tXUAT DANH SACH CRUSH: ";
	Xuat_Danh_Sach_Crush(ds_crush, n);
//	string hoten;
//	cout << "\n Nhap ho ten can tim kiem: ";
//	getline(cin, hoten);
//	CRUSH x = Tim_Kiem_Ho_Ten(ds_crush, n, hoten);
//	cout << "\n\tXUAT THONG TIN CRUSH CAN TIM KIEM: ";
//	
//	if(x.namsinh == 0) {
//		cout << "\n\tTHONG TIN CRUSH KHONG TON TAI.";
//	}
//	else {
//		Xuat_Thong_Tin_1_Crush(x);
//	}

	cout << "\n\tDANH SACH CRUSH DA SAP XEP: ";
	Sap_Xep_Nam_Sinh(ds_crush, n);
	Xuat_Danh_Sach_Crush(ds_crush, n);
	return 0;
}
