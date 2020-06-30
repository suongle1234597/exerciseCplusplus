#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>


using namespace std;

class Xe {
	protected:
		string ho_ten;
		float so_gio_thue;
	public: 
		void Nhap(); 
		void Xuat(); 
		float Tinh_Tien_Thue(); 
		
		Xe();
		~Xe();
};

void Xe::Nhap() {
	fflush(stdin);
	cout << "\nNhap ho ten nguoi thue: "; getline(cin, ho_ten);
	cout << "Nhap so gio thue: "; cin >> so_gio_thue;
}

void Xe::Xuat() {
	cout << "\nHo ten nguoi thue: " << ho_ten;
	cout << "\nSo gio thue: " << so_gio_thue;
}

Xe::Xe() {
}

Xe::~Xe() {
}

class XeDap : public Xe {
	public:
		void Nhap();
		void Xuat();
		float Tinh_Tien_Thue();
		
		XeDap();
		~XeDap();
};

void XeDap::Nhap() {
	Xe::Nhap();
}

void XeDap::Xuat() {
	Xe::Xuat();
}

float XeDap::Tinh_Tien_Thue() {
	float tien_thue;
	if(so_gio_thue < 10) {
		tien_thue = so_gio_thue * 10000;
	}
	else {
		tien_thue = so_gio_thue * 8000;
	}
	return tien_thue;
}

XeDap::XeDap() {
}

XeDap::~XeDap() {
}

class XeMay: public Xe {
	private:
		int loai_xe;
		string bien_so;
	public:
		void Nhap();
		void Xuat();
		float Tinh_Tien_Thue();
		
		int Getter_LoaiXe() {
			return loai_xe;
		}
		
		int Setter_LoaiXe() {
			return loai_xe;
		}
		
		XeMay();
		~XeMay();
};

void XeMay::Nhap() {
	Xe::Nhap();
	do {
		cout << "Nhap loai xe: "; cin >> loai_xe;
	} while (loai_xe != 100 && loai_xe != 250);
	
	fflush(stdin);
	cout << "Nhap bien so: "; getline(cin, bien_so);
}

void XeMay::Xuat() {
	Xe::Xuat();
	cout << "\nLoai xe: " << loai_xe;
	cout << "\nBien so: " << bien_so;
}

float XeMay::Tinh_Tien_Thue() {	
	float tien_thue;
	if(so_gio_thue < 10) {
		if(loai_xe == 100) {
			tien_thue = so_gio_thue * 150000;
		}
		else {
			tien_thue = so_gio_thue * 200000;
		}
	}
	else {
		tien_thue = so_gio_thue * 100000;
	}
	return tien_thue;
}

XeMay::XeMay() {
}

XeMay::~XeMay() {
}


class QuanLyXe {
	private:
		vector <XeDap> ds_xd; // sieu mang dong
		vector <XeMay> ds_xm;
	public: 
		void Nhap();
		void Xuat();
		
		QuanLyXe();
		~QuanLyXe();
};

void QuanLyXe::Nhap() {
	int chon;
	cout << "\n========================NHAP THONG TIN XE========================";
	cout << "\n1. Nhap thong tin xe dap";
	cout << "\n2. Nhap thong tin xe may";
	cout << "\n0. Thoat";
	
	do {
		cout << "\nNhap lua chon: ";
		cin >> chon;
		
		switch(chon) {
			system("cls");
			case 1: {
				XeDap xd;
				xd.Nhap();
				ds_xd.push_back(xd);
				break;
			}
			case 2: {
				XeMay xm;
				xm.Nhap();
				ds_xm.push_back(xm);
				break;
			}
		}
	} while(chon != 0);
}

void QuanLyXe::Xuat() {
	int tong = 0;
	int tong_xm = 0;
	cout << "\n========================XUAT THONG TIN XE========================";
	cout << "\n\tThong tin xe dap";
	for(int i = 0; i < ds_xd.size(); i++) {
		cout << "\nThong tin xe dap thu: " << i + 1;
		ds_xd[i].Xuat();
		cout << "\nTien thue: " << ds_xd[i].Tinh_Tien_Thue();
		tong += ds_xd[i].Tinh_Tien_Thue();
	}
	
	cout << "\n\tThong tin xe may";
	for(int i = 0; i < ds_xm.size(); i++) {
		cout << "\nThong tin xe may thu: " << i + 1;
		ds_xm[i].Xuat();
		cout << "\nTien thue: " << ds_xm[i].Tinh_Tien_Thue();
		tong += ds_xm[i].Tinh_Tien_Thue();
	} 
	
	cout << "\nTong tien thue: " << tong;
	
	for(int i = 0; i < ds_xm.size(); i++) {
		if(ds_xm[i].Getter_LoaiXe() == 250) {
			tong_xm += ds_xm[i].Tinh_Tien_Thue();
		}
	}
	cout << "\nTong tien thue may phan khoi 250: " << tong_xm;
}



QuanLyXe::QuanLyXe() {
}

QuanLyXe::~QuanLyXe() {
}

int main() {
	QuanLyXe *quanly = new QuanLyXe;
	quanly->Nhap();
	quanly->Xuat();
	
	delete(quanly);
	return 0;
}
