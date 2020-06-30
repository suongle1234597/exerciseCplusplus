#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class sinhvien {
	// thuoc tinh
	private: 
		string hoten;
		string masv; 
		float diemtoan;
		float diemly;
		
	// phuong thuc
	public: 
		void Nhap_Thong_Tin();
		void Xuat_Thong_Tin();
	
	// co che dong goi GETTER va SETTER (tra ve du lieu va thay doi du lieu)
	// geter ho ten
	string Getter_Hoten() {
		return hoten;
	}
	
	//setter ho ten
	void Setter_Hoten(string HOTEN) {
		hoten = HOTEN;
	}
	
	
	//ham tao va ham huy
	sinhvien();
	~sinhvien();
	
};

void sinhvien::Nhap_Thong_Tin() {
	cout << "\nNhap ho ten: ";
	getline(cin, hoten);
	cout << "\nNhap ma so sinh vien: ";
	getline(cin, masv);
	cout << "\nNhap diem toan: ";
	cin >> diemtoan;
	cout << "\nNhap diem ly: ";
	cin >> diemly;
}

void sinhvien::Xuat_Thong_Tin() {
	cout << "\nHo ten: " << hoten;
	cout << "\nMa so sinh vien: " << masv;
	cout << "\nDiem toan: " << diemtoan;
	cout << "\nDiem ly: " << diemly;
}

sinhvien::sinhvien() {
}

sinhvien::~sinhvien() {
}

int main() {
	sinhvien nva;
	
	cout << "\nNhap thong tin sinh vien: ";
	nva.Nhap_Thong_Tin();
	
	nva.Setter_Hoten("Nguyen Van A");
	
	cout << "\nXuat thong tin sinh vien: ";
	nva.Xuat_Thong_Tin();
	
	return 0;
}
