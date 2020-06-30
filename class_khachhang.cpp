#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>

using namespace std;


class KhachHang {
	protected:
		int ma_kh;
		string ho_ten;
		string ngay_sinh;
	public:
		virtual void Nhap();
		virtual void Xuat();
		virtual float Diem_So() = 0;

		int Getter_MaKH() {
			return ma_kh;
		}
		
		KhachHang();
		~KhachHang();
};

void KhachHang::Nhap() {
	cout << "Nhap ma khach hang: "; cin >> ma_kh;
	fflush(stdin);
	cout << "Nhap ho ten: "; getline(cin, ho_ten);
	cout << "Nhap ngay sinh: "; getline(cin, ngay_sinh);
}

void KhachHang::Xuat() {
	cout << "\nHo ten: " <<  ho_ten;
	cout << "\nNgay sinh: " << ngay_sinh;
}

KhachHang::KhachHang() {
}

KhachHang::~KhachHang() {
}


// CLASS KHACH HANG THUONG XUYEN
class KhachHang_ThuongXuyen : public KhachHang {
	private:
		int nam_tham_gia;
	public:
		void Nhap();
		void Xuat();
		float Diem_So();
		
		KhachHang_ThuongXuyen();
		~KhachHang_ThuongXuyen();
};

void KhachHang_ThuongXuyen::Nhap() {
	KhachHang::Nhap();
	cout << "Nhap nam tham gia: "; cin >> nam_tham_gia;
}

void KhachHang_ThuongXuyen::Xuat() {
	KhachHang::Xuat();
	cout << "\nNam tham gia: " << nam_tham_gia << endl;
}

float KhachHang_ThuongXuyen::Diem_So() {
	return ((2018 - nam_tham_gia) * 10);
}

KhachHang_ThuongXuyen::KhachHang_ThuongXuyen() {
}

KhachHang_ThuongXuyen::~KhachHang_ThuongXuyen() {
}

// CLASS KHACH HANG VIP
class KhachHang_VIP : public KhachHang {
	private:
		float so_tien_da_mua;
	public:
		void Nhap();
		void Xuat();
		float Diem_So();
		
		KhachHang_VIP();
		~KhachHang_VIP();
};

void KhachHang_VIP::Nhap() {
	KhachHang::Nhap();
	cout << "Nhap so tien da mua: "; cin >> so_tien_da_mua;
}

void KhachHang_VIP::Xuat() {
	KhachHang::Xuat();
	cout << "\nSo tien da mua: " << so_tien_da_mua << endl;
}

float KhachHang_VIP::Diem_So() {
	return (so_tien_da_mua/100000);
}

KhachHang_VIP::KhachHang_VIP() {
}

KhachHang_VIP::~KhachHang_VIP() {
}



// CLASS PHIEU MUA HANG
class Phieu_Mua_Hang {
	protected:
		int ma_phieu;
		int ma_khach;
		string ngay_het_han;
		bool KT; // true = phieu vang
		int kt;
	public:
		int Getter_MaKHACH() {
			return ma_khach;
		}
		
		int Getter_KT() {
			return KT;
		}
		
		void Setter_KT(bool kt) {
			KT = kt;
		}
		
		int Getter_KiemTra() {
			return kt;
		}
		
		void Setter_KiemTra(int kiemtra) {
			kt = kiemtra;
		}
		
		virtual float Gia_Tri(vector <KhachHang *> dskh) = 0;
		void Nhap();
		void Xuat();
		
		Phieu_Mua_Hang();
		~Phieu_Mua_Hang();
};

void Phieu_Mua_Hang::Nhap() {
	cout << "Nhap ma phieu: "; cin >> ma_phieu;
	cout << "Nhap ma khach hang: "; cin >> ma_khach;
	fflush(stdin);
	cout << "Nhap ngay het han: "; getline(cin, ngay_het_han);
}

void Phieu_Mua_Hang::Xuat() {
	cout << "\nMa phieu: " << ma_phieu;
	cout << "\nMa khach: " << ma_khach;
	cout << "\nNgay het han: " << ngay_het_han << endl;
}

Phieu_Mua_Hang::Phieu_Mua_Hang() {
}

Phieu_Mua_Hang::~Phieu_Mua_Hang() {
}

class Phieu_Chuan : public Phieu_Mua_Hang {
	public: 
		void Nhap();
		void Xuat();
		float Gia_Tri(vector <KhachHang *>dskh);
		
		Phieu_Chuan();
		~Phieu_Chuan();
};

void Phieu_Chuan::Nhap() {
	Phieu_Mua_Hang::Nhap();
}

void Phieu_Chuan::Xuat() {
	Phieu_Mua_Hang::Xuat();
}

float Phieu_Chuan::Gia_Tri(vector <KhachHang *>dskh) {
	for(int i = 0; i < dskh.size(); i++) {
		if(ma_khach == dskh[i]->Getter_MaKH()) {
			return (dskh[i]->Diem_So() * 10000);
		}
	}
}

Phieu_Chuan::Phieu_Chuan() {
}

Phieu_Chuan::~Phieu_Chuan() {
}

class Phieu_Bac : public Phieu_Mua_Hang {
	public: 
		void Nhap();
		void Xuat();
		float Gia_Tri(vector <KhachHang *>dskh);
		
		Phieu_Bac();
		~Phieu_Bac();
};

void Phieu_Bac::Nhap() {
	Phieu_Mua_Hang::Nhap();
}

void Phieu_Bac::Xuat() {
	Phieu_Mua_Hang::Xuat();
}

float Phieu_Bac::Gia_Tri(vector <KhachHang *>dskh) {
	for(int i = 0; i < dskh.size(); i++) {
		if(ma_khach == dskh[i]->Getter_MaKH()) {
			return (dskh[i]->Diem_So() * 15000);
		}
	}
}

Phieu_Bac::Phieu_Bac() {
}

Phieu_Bac::~Phieu_Bac() {
}

class Phieu_Vang : public Phieu_Mua_Hang {
	public: 
		void Nhap();
		void Xuat();
		float Gia_Tri(vector <KhachHang *>dskh);
		
		Phieu_Vang();
		~Phieu_Vang();
};

void Phieu_Vang::Nhap() {
	Phieu_Mua_Hang::Nhap();
}

void Phieu_Vang::Xuat() {
	Phieu_Mua_Hang::Xuat();
}

float Phieu_Vang::Gia_Tri(vector <KhachHang *>dskh) {
	for(int i = 0; i < dskh.size(); i++) {
		if(ma_khach == dskh[i]->Getter_MaKH()) {
			if(dskh[i]->Diem_So() < 200) {
				return (dskh[i]->Diem_So() * 25000);
			}
			else {
				return (dskh[i]->Diem_So() * 40000);
			}
		}
	}
}

Phieu_Vang::Phieu_Vang() {
}

Phieu_Vang::~Phieu_Vang() {
}

// CLASS QUAN LY
class QuanLy {
	private:
		vector <KhachHang *> dskh;
		vector <Phieu_Mua_Hang *> dsphieu;
	public:
		void NhapDSKH();
		void XuatDSKH();
		void SapXep();
		void Menu();
		
		QuanLy();
		~QuanLy();
};

void QuanLy::NhapDSKH() {
	int luachon;
	do {
		system("cls");
		cout << "\n=====================Nhap thong tin khach hang=====================";
		cout << "\n1. Khach hang thuong xuyen";
		cout << "\n2. Khach hang VIP";
		cout << "\n0. Thoat";
		cout << "\n==============================XONG=================================\n";
		cout << "\nNhap loai khach hang can chon: ";
		cin >> luachon;
		if(luachon == 1) {
			KhachHang_ThuongXuyen *kh_tx = new KhachHang_ThuongXuyen;
			kh_tx->Nhap();
			dskh.push_back(kh_tx);
		}
		else if(luachon == 2) {
			KhachHang_VIP *kh_vip = new KhachHang_VIP;
			kh_vip->Nhap();
			dskh.push_back(kh_vip);
		}
		else if(luachon > 2){
			cout << "Lua chon khong dung!";
		}
	} while(luachon != 0);
}

void QuanLy::XuatDSKH() {
	cout << "\n=====================Xuat thong tin khach hang=====================";
	for(int i = 0; i < dskh.size(); i++) {
		cout << "\nXuat thong tin khach hang thu: " << i + 1;
		dskh[i]->Xuat();
	}
}

void QuanLy::SapXep() {
	Phieu_Mua_Hang *phieu;
	for(int i = 0; i < dsphieu.size(); i++) {
		for(int j = i + 1; j < dsphieu.size(); j++) {
			if(dsphieu[j]->Gia_Tri(dskh) > dsphieu[i]->Gia_Tri(dskh)) {
				phieu = dsphieu[i];
				dsphieu[i] = dsphieu[j];
				dsphieu[j] = phieu;
			}
		}
	}
}

void QuanLy::Menu() {
	int chon, giatri;
	do {
		system("cls");
		cout << "\n=====================QUAN LY PHIEU MUA HANG=====================";
		cout << "\n1. Nhap danh sach phieu mua hang";
		cout << "\n2. Xuat danh sach phieu mua hang";
		cout << "\n3. In danh sach thu tu gia tri giam dan cua phieu mua hang";
		cout << "\n4. Tim va in ra cac phieu mua hang co gia tri nam trong khoang cho truoc";
		cout << "\n5. Xuat ra danh sach phieu vang";
		cout << "\n6. Xuat ra danh sach phieu mua hang nhap tu ban phim";
		cout << "\n0. Thoat";
		cout << "\n===============================END==============================\n";
		cout << "\nNhap lua chon: ";
		cin >> chon;
		switch (chon) {
			case 1: {
				cout << "\n\tNhap thong tin phieu mua hang";
				cout << "\n1.1. Phieu chuan";
				cout << "\n1.2. Phieu bac";
				cout << "\n1.3. Phieu vang";
				cout << "\nNhap loai phieu can chon: ";
				cin >> chon;
				if(chon == 1) {
					Phieu_Chuan *pc = new Phieu_Chuan;
					pc->Nhap();
					dsphieu.push_back(pc);
					pc->Setter_KiemTra(1);
				}
				else if(chon == 2) {
					Phieu_Bac *pb = new Phieu_Bac;
					pb->Nhap();
					dsphieu.push_back(pb);
					pb->Setter_KiemTra(2);
				}
				else if(chon == 3) {
					Phieu_Vang *pv = new Phieu_Vang;
					pv->Nhap();
					dsphieu.push_back(pv);
					pv->Setter_KT(true);
					pv->Setter_KiemTra(3);
				}
				else {
					break;
				}
				break;
			}
			case 2: {
				cout << "\n\tXuat thong tin phieu mua hang";
				for(int i = 0; i < dsphieu.size(); i++) {
					cout << "\nXuat thong tin phieu mua hang thu: " << i + 1;
					dsphieu[i]->Xuat();
					cout << "Gia tri phieu: " << (size_t)dsphieu[i]->Gia_Tri(dskh);
					for(int j = 0; j < dskh.size(); j++) {
						if(dskh[j]->Getter_MaKH() == dsphieu[i]->Getter_MaKHACH()) {
							dskh[j]->Xuat();
						}
					}	
				} 
				
				system("pause");
				break;
			}
			case 3: {
				cout << "\n\tDanh sach thu tu gia tri giam dan cua phieu mua hang";
				SapXep();
				for(int i = 0; i < dsphieu.size(); i++) {
					cout << "\nXuat thong tin phieu mua hang thu: " << i + 1;
					dsphieu[i]->Xuat();
					cout << "Gia tri phieu: " << (size_t)dsphieu[i]->Gia_Tri(dskh);
					for(int j = 0; j < dskh.size(); j++) {
						if(dskh[j]->Getter_MaKH() == dsphieu[i]->Getter_MaKHACH()) {
							dskh[j]->Xuat();
						}
					}	
				} 
				system("pause");
				break;
			}
			case 4: {
				cout << "\n\tIn ra cac phieu mua hang co gia tri nam trong khoang cho truoc";
				float a, b;
				cout << "\nNhap gia tri min: "; cin >> a;
				cout << "\nNhap gia tri max: "; cin >> b;
				for(int i = 0; i < dsphieu.size(); i++) {
					if(dsphieu[i]->Gia_Tri(dskh) >= a && dsphieu[i]->Gia_Tri(dskh) <= b) {
						cout << "\nXuat thong tin phieu mua hang ";
						dsphieu[i]->Xuat();
						cout << "Gia tri phieu: " << (size_t)dsphieu[i]->Gia_Tri(dskh);
						for(int j = 0; j < dskh.size(); j++) {
							if(dskh[j]->Getter_MaKH() == dsphieu[i]->Getter_MaKHACH()) {
								dskh[j]->Xuat();
							}
						}
					}
				} 
				system("pause");
				break;
			}
			case 5: {
				cout << "\n\tDanh sach phieu vang";
				for(int i = 0; i < dsphieu.size(); i++) {
					if(dsphieu[i]->Getter_KT() == true) {
						cout << "\nXuat thong tin phieu mua hang thu: " << i + 1;
						dsphieu[i]->Xuat();
						cout << "Gia tri phieu: " << dsphieu[i]->Gia_Tri(dskh);
						for(int j = 0; j < dskh.size(); j++) {
							if(dskh[j]->Getter_MaKH() == dsphieu[i]->Getter_MaKHACH()) {
								dskh[j]->Xuat();
							}
						}
					}
				} 
				system("pause");
				break;
			}
			case 6: {
				cout << "\n\tDanh sach phieu mua hang nhap tu ban phim";
				int phieu;
				cout << "\nNhap '1' - phieu chuan";
				cout << "\nNhap '2' - phieu bac";
				cout << "\nNhap '3' - phieu vang";
				cout << "\nNhap phieu mua hang can xuat: "; cin >> phieu;
				for(int i = 0; i < dsphieu.size(); i++) {
					if(dsphieu[i]->Getter_KiemTra() == phieu) {
						cout << "\nXuat thong tin phieu mua hang thu: " << i + 1;
						dsphieu[i]->Xuat();
						cout << "Gia tri phieu: " << (size_t)dsphieu[i]->Gia_Tri(dskh);
						for(int j = 0; j < dskh.size(); j++) {
							if(dskh[j]->Getter_MaKH() == dsphieu[i]->Getter_MaKHACH()) {
								dskh[j]->Xuat();
							}
						}
					}
				} 
				
				system("pause");
				break;
			}
		}
	} while(chon != 0);
}

QuanLy::QuanLy() {
}

QuanLy::~QuanLy() {
}

int main() {
	QuanLy *quanly = new QuanLy();
	quanly->NhapDSKH();
//	quanly->XuatDSKH();
	quanly->Menu();
	delete (quanly);
	return 0;
}
