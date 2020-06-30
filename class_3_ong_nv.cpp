#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 100

using namespace std;

// CLASS NHAN VIEN SUA ONG NUOC

class NhanVienSuaOngNuoc {
private:
	string hoten;
	int tuoi;
	string gioi_tinh;
	string dia_chi;
	string sdt;
	float chieu_cao;
	float can_nang;
	float so_gio_sua;
	
public:
	void Nhap();
	void Xuat();
	float Tinh_Tien_Luong();
	
	NhanVienSuaOngNuoc();
	~NhanVienSuaOngNuoc();
};

void NhanVienSuaOngNuoc::Nhap() {
	fflush(stdin);
	cout << "\nNhap ho ten: ";
	getline(cin, hoten);
	cout << "Nhap tuoi: ";
	cin >> tuoi;
	fflush(stdin);
	cout << "Nhap gioi tinh: ";
	getline(cin, gioi_tinh);
	cout << "Nhap dia chi: ";
	getline(cin, dia_chi);
	fflush(stdin);
	cout << "Nhap so dien thoai: ";
	getline(cin, sdt);
	cout << "Nhap chieu cao: ";
	cin >> chieu_cao;
	cout << "Nhap can nang: ";
	cin >> can_nang;
	cout << "Nhap so gio sua: ";
	cin >> so_gio_sua;
}

void NhanVienSuaOngNuoc::Xuat() {
	cout << "\nHo ten: " << hoten;
	cout << "\nTuoi: " << tuoi;
	cout << "\nGioi tinh: " << gioi_tinh;
	cout << "\nDia chi: " << dia_chi;
	cout << "\nSo dien thoai: " << sdt;
	cout << "\nChieu cao: " << chieu_cao;
	cout << "\nCan nang: " << can_nang;
	cout << "\nSo gio sua: " << so_gio_sua;
}

float NhanVienSuaOngNuoc::Tinh_Tien_Luong() {
	return so_gio_sua * 50000;
}

NhanVienSuaOngNuoc::NhanVienSuaOngNuoc() {
}

NhanVienSuaOngNuoc::~NhanVienSuaOngNuoc() {
}

// CLASS NHAN VIEN GIAO HANG

class NhanVienGiaoHang {
private:
	string hoten;
	int tuoi;
	string gioi_tinh;
	string dia_chi;
	string sdt;
	float chieu_cao;
	float can_nang;
	int so_hang_giao;
	
public:
	void Nhap();
	void Xuat();
	float Tinh_Tien_Luong();
	
	NhanVienGiaoHang();
	~NhanVienGiaoHang();
};

void NhanVienGiaoHang::Nhap() {
	fflush(stdin);
	cout << "Nhap ho ten: ";
	getline(cin, hoten);
	cout << "Nhap tuoi: ";
	cin >> tuoi;
	fflush(stdin);
	cout << "Nhap gioi tinh: ";
	getline(cin, gioi_tinh);
	cout << "Nhap dia chi: ";
	getline(cin, dia_chi);
	fflush(stdin);
	cout << "Nhap so dien thoai: ";
	getline(cin, sdt);
	cout << "Nhap chieu cao: ";
	cin >> chieu_cao;
	cout << "Nhap can nang: ";
	cin >> can_nang;
	cout << "Nhap so hang giao: ";
	cin >> so_hang_giao;
}

void NhanVienGiaoHang::Xuat() {
	cout << "\nHo ten: " << hoten;
	cout << "\nTuoi: " << tuoi;
	cout << "\nGioi tinh: " << gioi_tinh;
	cout << "\nDia chi: " << dia_chi;
	cout << "\nSo dien thoai: " << sdt;
	cout << "\nChieu cao: " << chieu_cao;
	cout << "\nCan nang: " << can_nang;
	cout << "\nSo hang giao: " << so_hang_giao;
}

float NhanVienGiaoHang::Tinh_Tien_Luong() {
	return so_hang_giao * 33500;
}

NhanVienGiaoHang::NhanVienGiaoHang() {
}

NhanVienGiaoHang::~NhanVienGiaoHang() {
}


// CLASS NHAN VIEN XE OM

class NhanVienXeOm {
private:
	string hoten;
	int tuoi;
	string gioi_tinh;
	string dia_chi;
	string sdt;
	float chieu_cao;
	float can_nang;
	int so_gio_chay;
	
public:
	void Nhap();
	void Xuat();
	float Tinh_Tien_Luong();
	
	NhanVienXeOm();
	~NhanVienXeOm();
};

void NhanVienXeOm::Nhap() {
	fflush(stdin);
	cout << "Nhap ho ten: ";
	getline(cin, hoten);
	cout << "Nhap tuoi: ";
	cin >> tuoi;
	fflush(stdin);
	cout << "Nhap gioi tinh: ";
	getline(cin, gioi_tinh);
	cout << "Nhap dia chi: ";
	getline(cin, dia_chi);
	fflush(stdin);
	cout << "Nhap so dien thoai: ";
	getline(cin, sdt);
	cout << "Nhap chieu cao: ";
	cin >> chieu_cao;
	cout << "Nhap can nang: ";
	cin >> can_nang;
	cout << "Nhap so gio chay: ";
	cin >> so_gio_chay;
}

void NhanVienXeOm::Xuat() {
	cout << "\nHo ten: " << hoten;
	cout << "\nTuoi: " << tuoi;
	cout << "\nGioi tinh: " << gioi_tinh;
	cout << "\nDia chi: " << dia_chi;
	cout << "\nSo dien thoai: " << sdt;
	cout << "\nChieu cao: " << chieu_cao;
	cout << "\nCan nang: " << can_nang;
	cout << "\nSo gio chay: " << so_gio_chay;
}

float NhanVienXeOm::Tinh_Tien_Luong() {
	return so_gio_chay * 10000;
}

NhanVienXeOm::NhanVienXeOm() {
}

NhanVienXeOm::~NhanVienXeOm() {
}


// Ham tinh tong tien luong cua cac nhan vien sua ong nuoc
double Tong_Tien_Luong_NV_Sua_Ong_Nuoc(NhanVienSuaOngNuoc ds[], int n) {
	double sum = 0;
	for(int i = 0; i < n; i++) {
		sum += ds[i].Tinh_Tien_Luong();
	}
	return sum;
}

// Ham tinh tong tien luong cua cac nhan vien giao hang
double Tong_Tien_Luong_NV_Giao_Hang(NhanVienGiaoHang ds[], int n) {
	double sum = 0;
	for(int i = 0; i < n; i++) {
		sum += ds[i].Tinh_Tien_Luong();
	}
	return sum;
}

// Ham tinh tong tien luong cua cac nhan vien xe om
double Tong_Tien_Luong_NV_Xe_Om(NhanVienXeOm ds[], int n) {
	double sum = 0;
	for(int i = 0; i < n; i++) {
		sum += ds[i].Tinh_Tien_Luong();
	}
	return sum;
}

// Ham hoan vi 2 doi tuong nhan vien sua ong nuoc
//void Hoan_Vi_NV_Sua_Ong_Nuoc (NhanVienSuaOngNuoc &x, NhanVienSuaOngNuoc &y){
//	NhanVienSuaOngNuoc tam = x;
//	x = y; 
//	y = tam;
//}


void Thong_Ke_Cac_NV_Sua_Ong_Nuoc_Giam_Dan_Theo_Luong(NhanVienSuaOngNuoc ds[], int n) {
	NhanVienSuaOngNuoc tam;
	for(int i = 0 ; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(ds[i].Tinh_Tien_Luong() < ds[j].Tinh_Tien_Luong()) {
			tam = ds[i];
			ds[i] = ds[j];
			ds[j] = tam;
			}	
		}
	}
}

void Thong_Ke_Cac_NV_Giao_Hang_Giam_Dan_Theo_Luong(NhanVienGiaoHang ds[], int n) {
	NhanVienGiaoHang tam;
	for(int i = 0 ; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(ds[i].Tinh_Tien_Luong() < ds[j].Tinh_Tien_Luong()) {
			tam = ds[i];
			ds[i] = ds[j];
			ds[j] = tam;
			}	
		}
	}
}

void Thong_Ke_Cac_NV_Xe_Om_Giam_Dan_Theo_Luong(NhanVienXeOm ds[], int n) {
	NhanVienXeOm tam;
	for(int i = 0 ; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(ds[i].Tinh_Tien_Luong() < ds[j].Tinh_Tien_Luong()) {
			tam = ds[i];
			ds[i] = ds[j];
			ds[j] = tam;
			}	
		}
	}
}

void Menu(NhanVienSuaOngNuoc ds_nv_son[], NhanVienGiaoHang ds_nv_gh[], NhanVienXeOm ds_nv_xo[], int n, int m, int l) {
	int luachon;
	while(true) {
		cout << "\n=====================CHUONG TRINH QUAN LY=====================\n";
		cout << "\n1. Nhap thong tin nhan vien sua ong nuoc";
		cout << "\n2. Nhap thong tin nhan vien giao hang";
		cout << "\n3. Nhap thong tin nhan vien xe om";
		cout << "\n4. Xuat danh sach thong tin nhan vien sua ong nuoc";
		cout << "\n5. Xuat danh sach thong tin nhan vien giao hang";
		cout << "\n6. Xuat danh sach thong tin nhan vien xe om";
		cout << "\n7. Tinh tong tien cong ty phai tra hang thang";
		cout << "\n8. Thong ke nhan vien sua ong nuoc giam dan theo luong";
		cout << "\n9. Thong ke nhan vien giao hang giam dan theo luong";
		cout << "\n10. Thong ke nhan vien xe om giam dan theo luong";
		cout << "\n0. Thoat";
		cout << "\n\t=====================END=====================\n";
		
		cout << "\nNhap lua chon: ";
		cin >> luachon;
		
		if(luachon == 1) {
			NhanVienSuaOngNuoc nv_son;
			cout << "\n\tNhap thong tin nhan vien sua ong nuoc\n";
			nv_son.Nhap();
			
			// them doi tuong gia tri nhan vien sua ong nuoc vao danh sach ds_nv_son
			ds_nv_son[n] = nv_son;
			n++;
		}
		else if(luachon == 2) {
			NhanVienGiaoHang nv_gh;
			cout << "\n\tNhap thong tin nhan vien giao hang\n";
			nv_gh.Nhap();
			
			// them doi tuong gia tri nhan vien giao hang vao danh sach ds_nv_gh
			ds_nv_gh[m] = nv_gh;
			m++;
		}
		else if(luachon == 3) {
			NhanVienXeOm nv_xo;
			cout << "\n\tNhap thong tin nhan vien xe om\n";
			nv_xo.Nhap();
			
			// them doi tuong gia tri nhan vien xe om vao danh sach ds_nv_xo
			ds_nv_xo[l] = nv_xo;
			l++;
		}
		else if(luachon == 4) {
			cout << "\n\tDanh sach thong tin nhan vien sua ong nuoc\n";
			for(int i = 0; i < n; i++) {
				cout << "\nXuat thong tin nhan vien thu: " << i + 1;
				ds_nv_son[i].Xuat();
			}
			cout << "\nTong tien luong nhan vien sua ong nuoc: " << (size_t)Tong_Tien_Luong_NV_Sua_Ong_Nuoc(ds_nv_son, n);
			
		}
		else if(luachon == 5) {
			cout << "\n\tDanh sach thong tin nhan vien giao hang\n";
			for(int i = 0; i < n; i++) {
				cout << "\nXuat thong tin nhan vien thu: " << i + 1;
				ds_nv_gh[i].Xuat();
			}
			cout << "\nTong tien luong nhan vien giao hang: " << (size_t)Tong_Tien_Luong_NV_Giao_Hang(ds_nv_gh, m);
		}
		else if(luachon == 6) {
			cout << "\n\tDanh sach thong tin nhan vien xe om\n";
			for(int i = 0; i < n; i++) {
				cout << "\nXuat thong tin nhan vien thu: " << i + 1;
				ds_nv_xo[i].Xuat();
			}
			cout << "\nTong tien luong nhan vien xe om: " << (size_t)Tong_Tien_Luong_NV_Xe_Om(ds_nv_xo, l);
		}
		else if(luachon == 7) {
			cout << "\nTong tien luong: " << (size_t)(Tong_Tien_Luong_NV_Sua_Ong_Nuoc(ds_nv_son, n) + Tong_Tien_Luong_NV_Giao_Hang(ds_nv_gh, m) + Tong_Tien_Luong_NV_Xe_Om(ds_nv_xo, l));
		}
		else if(luachon == 8) {
			Thong_Ke_Cac_NV_Sua_Ong_Nuoc_Giam_Dan_Theo_Luong(ds_nv_son, n);
			for(int i = 0; i < n; i++) {
				cout << "\nXuat thong tin nhan vien thu: " << i + 1;
				ds_nv_son[i].Xuat();
			}
		}
		else if(luachon == 9) {
			Thong_Ke_Cac_NV_Giao_Hang_Giam_Dan_Theo_Luong(ds_nv_gh, n);
			for(int i = 0; i < n; i++) {
				cout << "\nXuat thong tin nhan vien thu: " << i + 1;
				ds_nv_gh[i].Xuat();
			}
		}
		else if(luachon == 10) {
			Thong_Ke_Cac_NV_Xe_Om_Giam_Dan_Theo_Luong(ds_nv_xo, n);
			for(int i = 0; i < n; i++) {
				cout << "\nXuat thong tin nhan vien thu: " << i + 1;
				ds_nv_xo[i].Xuat();
			}
		}
		else if(luachon == 0) {
			break;
		}
		else {
			cout << "\nLua chon khong hop le!";
		}
	}
}

int main() {
//	NhanVienSuaOngNuoc ds_nv_son[MAX]; // mang 1 chieu danh sach nhan vien sua ong nuoc. Moi mot phan tu la mot doi tuong gia tri
//	NhanVienGiaoHang ds_nv_gh[MAX];
//	NhanVienXeOm ds_nv_xo[MAX];
//	
//	int n = 0; // so luong nhan vien sua ong nuoc
//	int m = 0; // so luong nhan vien giao hang
//	int l = 0; // so luong nhan vien xe om
//	
//	Menu(ds_nv_son, ds_nv_gh, ds_nv_xo, n, m, l);

	NhanVienSuaOngNuoc nv_a; // doi tuong gia tri - vung nho stack
	NhanVienSuaOngNuoc *nv = new NhanVienSuaOngNuoc(); // doi tuong con tro -  vung nho heap //dau ngoac khoi tao constractor default truyen tham so
	nv->Nhap();
	nv->Xuat();
	
	delete(nv);
	return 0;
}
