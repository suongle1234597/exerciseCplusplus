/* *** Cong ty dich vu thu cung BA CON SOI dang co nhu cau xay dung ung dung quan ly cac loai thu cung xuyen quoc gia la cho va meo
  - Voi thong tin cua moi con vat gom:
   + Nickname thu cung, can nang, do hot (kieu so nguyen 4 byte)
Ðe giup phat trien toan dien cho cac loai thu cung thi cong ty cung cap them cac loai thuc an can thiet nhu loai xuong ua thich 
danh cho cho, va loai sua ua thich danh cho meo.
*** Thuc hien cac thao tac hang ngay tai cua hang
  1. Nhap - xuat thong tin cac loai thu cung.
  2. Xuat danh sach thong tin thu cung X(cho hoac meo) theo giong loai(VN, Nhat, My...)
  3. Tinh tong gia ban cua tung loai thu cung.
  4. Tim thu cung co gia ban cao nhat.
  5. Sap xep giam dan can nang cua thu cung.

Biet:
 + Gia ban cua 1 thu cung cho = 200000 * do hot
 + Gia ban cua 1 thu cung meo = 150000 * do hot
 + Can nang don vi la kg */

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


// CLASS CHA - THUCUNG
class ThuCung {
	protected: 
		string nickname;
		int can_nang;
		int do_hot;
		string giong_loai;
		
	public:
		int Getter_CanNang() {
			return can_nang;
		}
		
		string Getter_GiongLoai() {
			return giong_loai;
		}
		
		void Nhap();
		void Xuat();
		
		ThuCung();
		~ThuCung();
};

void ThuCung::Nhap() {
	fflush(stdin);
	cout << "\nNhap nickname: "; getline(cin, nickname);
	cout << "Nhap can nang: "; cin >> can_nang;
	cout << "Nhap do hot: "; cin >> do_hot;
	fflush(stdin);
	do {
		cout << "Nhap giong loai: "; getline(cin, giong_loai);
	} while (giong_loai != "Viet Nam" && giong_loai != "Nhat" && giong_loai != "My");
}

void ThuCung::Xuat() {
	cout << "\nNickname: " << nickname;
	cout << "\nCan nang: " << can_nang << " kg";
	cout << "\nDo hot: " << do_hot;
	cout << "\nGiong loai: " << giong_loai;
}

ThuCung::ThuCung() {
}

ThuCung::~ThuCung() {
}


// CLASS CON - CHO
class Cho : public ThuCung {
	private:
		string loai_xuong_ua_thich;
	public:
		void Nhap();
		void Xuat();
		float Tinh_gia_ban();
		
		Cho();
		~Cho();
};

void Cho::Nhap() {
	ThuCung::Nhap();
	fflush(stdin);
	cout << "Nhap loai xuong ua thich: "; getline(cin, loai_xuong_ua_thich);
}

void Cho::Xuat() {
	ThuCung::Xuat();
	cout << "\nLoai xuong ua thich: " << loai_xuong_ua_thich;
}

float Cho::Tinh_gia_ban() {
	return (200000 * do_hot);
}

Cho::Cho() {
}

Cho::~Cho() {
}

// CLASS CON - MEO
class Meo : public ThuCung {
	private:
		string loai_sua_ua_thich;
	public:
		void Nhap();
		void Xuat();
		float Tinh_gia_ban();
		
		Meo();
		~Meo();
};

void Meo::Nhap() {
	ThuCung::Nhap();
	fflush(stdin);
	cout << "Nhap loai sua ua thich: "; getline(cin, loai_sua_ua_thich);
}

void Meo::Xuat() {
	ThuCung::Xuat();
	cout << "\nLoai sua ua thich: " << loai_sua_ua_thich;
}

float Meo::Tinh_gia_ban() {
	return (150000 * do_hot);
}

Meo::Meo() {
}

Meo::~Meo() {
}

void SapXep(Cho *ds_cho[], int n) {
	Cho *tam = new Cho();
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(ds_cho[i]->Getter_CanNang() < ds_cho[j]->Getter_CanNang()) {
				tam = ds_cho[i];
				ds_cho[i] = ds_cho[j];
				ds_cho[j] = tam;
			}
		}
	}
}

void SapXep(Meo *ds_meo[], int m) {
	Meo *tam = new Meo();
	for(int i = 0; i < m; i++) {
		for(int j = i + 1; j < m; j++) {
			if(ds_meo[i]->Getter_CanNang() < ds_meo[j]->Getter_CanNang()) {
				tam = ds_meo[i];
				ds_meo[i] = ds_meo[j];
				ds_meo[j] = tam;
			}
		}
	}
}

void Menu(Cho *ds_cho[], Meo *ds_meo[], int n, int m) {
	int chon;
	while(true) {
		system("cls");
		cout << "\n========================QUAN LY THU CUNG==============================";
		cout << "\n1. Nhap thong tin thu cung la cho";
		cout << "\n2. Nhap thong tin thu cung la meo";
		cout << "\n3. Xuat thong tin thu cung la cho";
		cout << "\n4. Xuat thong tin thu cung la meo";
		cout << "\n5. Xuat thong tin thu cung theo giong loai";
		cout << "\n6. Tinh tong gia ban cua tung loai thu cung";
		cout << "\n7. Tim thu cung co gia ban cao nhat";
		cout << "\n8. Sap xep giam dan can nang cua thu cung";
		cout << "\n0. Thoat";
		cout << "\n==============================END=====================================";
		
		cout << "\nNhap lua chon: ";
		cin >> chon;
		
		if(chon == 0) {
			break;
		}
		else if(chon == 1) {
			Cho *cho = new Cho();
			cout << "\n\tNhap thong tin thu cung la cho";
			cho->Nhap();
			
			ds_cho[n] = cho;
			n++;
		}
		else if(chon == 2) {
			Meo *meo = new Meo();
			cout << "\n\tNhap thong tin thu cung la meo";
			meo->Nhap();
			
			ds_meo[m] = meo;
			m++;
		}
		else if(chon == 3) {
			cout << "\n\tXuat thong tin thu cung la cho";
			for(int i = 0; i < n; i++) {
				cout << "\nXuat thong tin thu cung cho thu: " << i + 1;
				ds_cho[i]->Xuat();
				cout << "\nGia ban: " << ds_cho[i]->Tinh_gia_ban() << endl;
			}
			system("pause");
		}
		else if(chon == 4) {
			cout << "\n\tXuat thong tin thu cung la meo";
			for(int i = 0; i < m; i++) {
				cout << "\nXuat thong tin thu cung meo thu: " << i + 1;
				ds_meo[i]->Xuat();
				cout << "\nGia ban: " << ds_meo[i]->Tinh_gia_ban() << endl;
			}
			system("pause");
		}
		else if(chon == 5) {
			string loai;
			cout << "\n\tXuat thong tin thu cung theo giong loai";
			fflush(stdin);
			cout << "\nNhap giong loai muon xuat: ";
			getline(cin, loai);
			
			for(int i = 0; i < n; i++) {
				if(loai == ds_cho[i]->Getter_GiongLoai()) {
					ds_cho[i]->Xuat(); 
					cout << endl;
				}
			}
			
			for(int i = 0; i < m; i++) {
				if(loai == ds_meo[i]->Getter_GiongLoai()) {
					ds_meo[i]->Xuat(); 
					cout << endl;
				}
			}
			system("pause");
		}
		else if(chon == 6) {
			float sum1 = 0, sum2 = 0;
			cout << "\n\tTong gia ban cua tung loai thu cung";
			
			for(int i = 0; i < n; i++) {
				sum1 += ds_cho[i]->Tinh_gia_ban();
			}
			
			for(int i = 0; i < m; i++) {
				sum2 += ds_meo[i]->Tinh_gia_ban();
			}
			
			cout << "\nTong gia ban cua thu cung cho la: " << sum1;
			cout << "\nTong gia ban cua thu cung meo la: " << sum2;
			
			system("pause");
		}
		else if(chon == 7) {
			float max1, max2;
			int vt1, vt2;
			int i, j;
			cout << "\n\tThu cung co gia ban cao nhat la: ";
			
			max1 = ds_cho[0]->Tinh_gia_ban();
			for(i = 1; i < n; i++) {
				if(ds_cho[i]->Tinh_gia_ban() > max1) {
					max1 = ds_cho[i]->Tinh_gia_ban();
					vt1 = i;
				}
			}
			
			
			max2 = ds_meo[0]->Tinh_gia_ban();
			for(j = 1; j < m; j++) {
				if(ds_meo[j]->Tinh_gia_ban() > max2) {
					max2 = ds_meo[j]->Tinh_gia_ban();
					vt2 = j;
				}
			}
			
			if(max1 > max2) {
				ds_cho[vt1]->Xuat();
			}
			else if(max1 == max2) {
				ds_cho[vt1]->Xuat();
				ds_meo[vt2]->Xuat();
			}
			else {
				ds_meo[vt2]->Xuat();
			}
			
			system("pause");
		}
		else if(chon == 8) {
			cout << "\n\tSap xep giam dan can nang cua thu cung";
			SapXep(ds_cho, n);
			SapXep(ds_meo, m);
			
			for(int i = 0; i < n; i++) {
				ds_cho[i]->Xuat(); 
				cout << endl;
			}
			
			for(int i = 0; i < m; i++) {
				ds_meo[i]->Xuat(); 
				cout << endl;
			}
			
			system("pause");
		}
		else {
			cout << "\nLua chon khong hop le!";
			system("pause");
		}
	}	
	if(n > 0) {
		for(int i = 0; i < n; i++) {
			delete ds_cho[i];
		}
	}
	if(m > 0) {
		for(int i = 0; i < m; i++) {
			delete ds_meo[i];
		}
	}
}

int main() {
	Cho *ds_cho[100];
	Meo *ds_meo[100];
	
	int n = 0;
	int m = 0;
	Menu(ds_cho, ds_meo, n, m);
	
	return 0;
}
