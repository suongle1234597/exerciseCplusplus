#include <iostream>
#include <fstream>

using namespace std;

struct ngay {
	int ngay;
	int thang;
	int nam;
};
typedef struct ngay NGAY;

void Nhap_Ngay(NGAY &ngay) {
	cout << "Nhap ngay: "; cin >> ngay.ngay;
	cout << "Nhap thang: "; cin >> ngay.thang;
	cout << "Nhap nam: "; cin >> ngay.nam;
}

struct sinhvien {
	string hoten;
	int msv;
	NGAY ngaysinh;
};
typedef struct sinhvien SINHVIEN;
 
void Nhap_Thong_Tin_1_Sinh_Vien(SINHVIEN &sv) {
	fflush(stdin);
	cout << "Nhap ho ten: ";
	getline(cin, sv.hoten);
	Nhap_Ngay(sv.ngaysinh);
}

int main() {
	
}
