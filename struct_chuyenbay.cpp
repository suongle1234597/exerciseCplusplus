/* Hay khai bao kieu du lieu de bieu dien thong tin cua 1 chuyen bay. Biet rang mot chuyen bay gom nhung thong tin sau:
- Ma chuyen bay: chuoi toi da 5 ki tu
- Ngay bay: chuoi string (dd/mm/yyyy)
- Gio bay: chuoi string (hh/pp/gg)
- Noi di: chuoi toi da 20 ki tu
- Noi den: chuoi toi da 20 ki tu
1. Nhap danh sach cac chuyen bay
2. Xuat danh sach cac chuyen bay
3. Xoa chuyen bay co ma chuyen bay bat ki
4. Them chuyen bay moi vao danh sach chuyen bay  
5. Tim kiem thong tin chuyen bay co gio bay X trong ngay bay Y */

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

// khai bao cau truc ngay bay
struct NgayBay {
	int ngay;
	int thang;
	int nam;
};
typedef struct NgayBay NGAYBAY;

void Nhap_Thong_Tin_Ngay_Bay(NGAYBAY &nb) {
	cout << " Nhap ngay bay: ";
	cin >> nb.ngay;
	cout << " Nhap thang bay: ";
	cin >> nb.thang;
	cout << " Nhap nam bay: ";
	cin >> nb.nam;
}

void Xuat_Thong_Tin_Ngay_Bay(NGAYBAY nb) {
	cout << nb.ngay << "/" << nb.thang << "/" << nb.nam;
}

// khai bao cau truc gio bay
struct ThoiGianBay {
	int giay;
	int phut;
	int gio;
};
typedef struct ThoiGianBay THOIGIANBAY;

void Nhap_Thoi_Gian_Bay(THOIGIANBAY &gb) {
	cout << " Nhap gio bay: ";
	cin >> gb.gio;
	cout << " Nhap phut bay: ";
	cin >> gb.phut;
	cout << " Nhap giay bay: ";
	cin >> gb.giay;
}

void Xuat_Thoi_Gian_Bay(THOIGIANBAY gb) {
	cout << gb.gio << ":" << gb.phut << ":" << gb.giay;
}

// khai bao cau truc 1 chuyen bay
struct ChuyenBay {
	string ma;
	NGAYBAY ngaybay;
	THOIGIANBAY giobay;
	string noidi;
	string noiden;
};
typedef struct ChuyenBay CHUYENBAY;

bool Kiem_Tra_Nhap_Ma(DANHSACH &ds, string ma) {
	for(int i = 0; i < ds.n; i++) {
		if(stricmp((char *)ds.ds_cb[i].ma.c_str(), (char *)ma.c_str()) == 0) {
			return true;
		}
	}
	return false;
}

// nhap thong tin 1 chuyen bay
void Nhap_Thong_Tin_1_Chuyen_Bay(CHUYENBAY &cb) {
	fflush(stdin);
	do {
		cout << "\n Nhap ma chuyen bay: "; 
		getline(cin, cb.ma);
	} while (Kiem_Tra_Nhap_Ma(cb, cb.ma) == true);
	Nhap_Thong_Tin_Ngay_Bay(cb.ngaybay);
	Nhap_Thoi_Gian_Bay(cb.giobay);
	fflush(stdin);
	cout << " Nhap noi di: "; 
	getline(cin, cb.noidi);
	fflush(stdin);
	cout << " Nhap noi den: "; 
	getline(cin, cb.noiden);
}

void Xuat_Thong_Tin_1_Chuyen_Bay(CHUYENBAY cb) {
	cout << "\n Ma chuyen bay: " << cb.ma;
	cout << "\n Ngay bay: ";
	Xuat_Thong_Tin_Ngay_Bay(cb.ngaybay);
	cout << "\n Gio bay: ";
	Xuat_Thoi_Gian_Bay(cb.giobay);
	cout << "\n Noi di: " << cb.noidi;
	cout << "\n Noi den: " << cb.noiden;
}

struct DanhSach {
	CHUYENBAY ds_cb[100];
	int n;
};
typedef struct DanhSach DANHSACH;

// nhap danh sach chuyen bay
void Nhap_Danh_Sach_Chuyen_Bay(DANHSACH &ds) {
	for (int i = 0; i < ds.n; i++) {
		cout << "\n Nhap chuyen bay thu: " << i + 1;
		Nhap_Thong_Tin_1_Chuyen_Bay(ds.ds_cb[i]);
	}
}

void Xuat_Danh_Sach_Chuyen_Bay(DANHSACH ds) {
	for (int i = 0; i < ds.n; i++) {
		cout << "\n Chuyen bay thu: " << i + 1;
		Xuat_Thong_Tin_1_Chuyen_Bay(ds.ds_cb[i]);
	}
}

// xoa 1 phan tu bat ky trong danh sach chuyen bay
void Xoa(DANHSACH &ds, int vt) {
	for(int i = vt + 1; i < ds.n; i++) {
		ds.ds_cb[i + 1] = ds.ds_cb[i];
	}
	ds.n--;
}

// xoa 1 chuyen bay co ma bat ky
void Xoa_Theo_Ma(DANHSACH &ds, string ma) {
	for (int i = 0; i < ds.n; i++) {
		if(stricmp((char *)ds.ds_cb[i].ma.c_str(), (char *)ma.c_str()) == 0) {
			Xoa(ds, i); // vi moi chuyen bay co 1 ma bat ky nen khong co i--
			break;
		}
	}
}

void SapXep(DANHSACH &ds) { 
	CHUYENBAY tam;
	for(int i = 0; i < ds.n; i++) {
		for(int j = i + 1; j < ds.n; j++) {
			if(ds.ds_cb[i].ngaybay.nam > ds.ds_cb[j].ngaybay.nam) {
				tam = ds.ds_cb[i];
				ds.ds_cb[i] = ds.ds_cb[j];
				ds.ds_cb[j] = tam;
			}
			else {
				if(ds.ds_cb[i].ngaybay.thang > ds.ds_cb[j].ngaybay.thang) {
					tam = ds.ds_cb[i];
					ds.ds_cb[i] = ds.ds_cb[j];
					ds.ds_cb[j] = tam;
				}
				else {
					if(ds.ds_cb[i].ngaybay.ngay > ds.ds_cb[j].ngaybay.ngay) {
						tam = ds.ds_cb[i];
						ds.ds_cb[i] = ds.ds_cb[j];
						ds.ds_cb[j] = tam;
				    }
				}
			}
		}
	}
}

void Them(DANHSACH &ds, int vt, CHUYENBAY cb) {
	for (int i = ds.n - 1; i >= vt; i--) {
		ds.ds_cb[i + 1] = ds.ds_cb[i];
	}
	ds.ds_cb[vt] = cb;
	ds.n ++;
}

void TimKiem(DANHSACH &ds, THOIGIANBAY gio, NGAYBAY ngay) {
	for(int i = 0; i < ds.n; i++) {
		if(ds.ds_cb[i].giobay.gio == gio.gio && ds.ds_cb[i].ngaybay.ngay == ngay.ngay && ds.ds_cb[i].ngaybay.thang == ngay.thang && ds.ds_cb[i].ngaybay.nam == ngay.nam) {
			Xuat_Thong_Tin_1_Chuyen_Bay(ds.ds_cb[i]);
		}  
	}
}

int main() {
	DANHSACH ds;
	cout << " Nhap so luong chuyen bay: ";
	cin >> ds.n;
	cout << "\n\tNHAP DANH SACH CHUYEN BAY\n";
	Nhap_Danh_Sach_Chuyen_Bay(ds);
//	cout << "\n\tXUAT DANH SACH CHUYEN BAY\n";
//	Xuat_Danh_Sach_Chuyen_Bay(ds);
	
//	string ma;
//	cout << "\n Nhap ma can xoa: ";
//	getline(cin, ma);
//	Xoa_Theo_Ma(ds, ma);
//	cout << "\n\tDANH SACH SAU KHI SAP XEP\n";
//	SapXep(ds);

//	CHUYENBAY x;
//	cout << "\n Nhap chuyen bay can them: ";
//	Nhap_Thong_Tin_1_Chuyen_Bay(x);
//	cout << "\n\tDANH SACH SAU KHI THEM\n";
//	Them(ds, ds.n, x);
//	Xuat_Danh_Sach_Chuyen_Bay(ds);

	NGAYBAY ngay;
	THOIGIANBAY gio;
	cout << "\n\tNhap ngay va gio can tim kiem";
	Nhap_Thoi_Gian_Bay(gio);
	Nhap_Thong_Tin_Ngay_Bay(ngay);
	cout << "\n\tTIM KIEM\n";
	TimKiem(ds, gio, ngay);
	return 0;
}
