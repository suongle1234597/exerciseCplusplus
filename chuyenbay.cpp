#include <iostream>
#include <string.h>

using namespace std;

struct ngaybay {
	int ngay;
	int thang;
	int nam;
}; typedef struct ngaybay NGAYBAY;

void Nhap_Ngay_Bay(NGAYBAY &nb) {
	cout << "Nhap Ngay: "; cin >> nb.ngay;
	cout << "Nhap Thang: "; cin >> nb.thang;
	cout << "Nhap Nam: "; cin >> nb.nam;
}

void Xuat_Ngay_Bay(NGAYBAY &nb) {
	cout << "Ngay: " << nb.ngay;
	cout << "Thang: " << nb.thang;
	cout << "Nam: " << nb.nam;
}

struct giobay{
	int gio;
	int phut;
	int giay;
}; typedef struct giobay GIOBAY;

void Nhap_Gio_Bay(GIOBAY &gb) {
	cout << "Nhap gio: "; cin >> gb.gio;
	cout << "Nhap phut: "; cin >> gb.phut;
	cout << "Nhap giay: "; cin >> gb.giay;
}

void Xuat_Gio_Bay(GIOBAY &gb) {
	cout << "Gio: " << gb.gio;
	cout << "Phut: " << gb.phut;
	cout << "Giay: " << gb.giay;
}

struct chuyenbay {
	string ma;
	NGAYBAY ngay;
	GIOBAY gio;
	string noidi;
	string noiden;
	
}; typedef struct chuyenbay CHUYENBAY;

void Nhap_Thong_Tin_1_Chuyen_Bay(CHUYENBAY &cb) {
	cout << "Nhap ma: "; cin >> cb.ma;
	Nhap_Ngay_Bay(cb.ngay);
	Nhap_Gio_Bay(cb.gio);
	cout << "Nhap noi di: "; cin >> cb.noidi;
	cout << "Nhap noi den: "; cin >> cb.noiden;
}

void Xuat_Thong_Tin_1_Chuyen_Bay(CHUYENBAY &cb) {
	cout << "Ma: " << cb.ma;
	Xuat_Ngay_Bay(cb.ngay);
	Xuat_Gio_Bay(cb.gio);
	cout << "Noi di: " << cb.noidi;
	cout << "Noi den: " << cb.noiden;
}

struct danhsach {
	CHUYENBAY ds_cb[100];
	int n;
}; typedef struct danhsach DANHSACH;

void Nhap_DS_Chuyen_Bay(DANHSACH &ds) {
	for(int i = 0; i < ds.n; i++) {
		cout << "Nhap thong tin chuyen bay thu: " << i + 1;
		Nhap_Thong_Tin_1_Chuyen_Bay(ds.ds_cb[i]);
	}
}

void Xuat_DS_Chuyen_Bay(DANHSACH &ds) {
	for(int i = 0; i < ds.n; i++) {
		cout << "Thong tin chuyen bay thu: " << i + 1;
		Xuat_Thong_Tin_1_Chuyen_Bay(ds.ds_cb[i]);
	}
}



int main() {
	DANHSACH ds;
	int luachon;
	cout << "\n1. Nhap danh sach cac chuyen bay";
	cout << "\n2. Xuat danh sach cac chuyen bay";
	cout << "\n3. Xoa chuyen bay co ma chuyen bay bat ki";
	


4. Them chuyen bay moi vao danh sach chuyen bay  
5. Tim kiem thong tin chuyen bay co gio bay X trong ngay bay
	do {
		
	} while (luachon != 0);
	
	return 0;
}
