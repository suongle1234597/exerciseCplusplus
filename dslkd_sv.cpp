#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <fstream>
#define Enter 13
#define ESC 27
#define Backspace 8
#define MAXLOP 500

#define PASSWORD "abcdef"

using namespace std;

struct SinhVien{
	char maSV[16];
	char ho[30];
	char ten[10];
	char phai[4];
	char password[20];
	char maLop[16];
};

struct nodeSV{
	SinhVien sv;
	struct nodeSV *pNext;
};
typedef nodeSV NODESV;

struct listSV{
	NODESV *pHead;
	NODESV *pTail;
};
typedef struct listSV LISTSV;

//KHOI TAO DSLKD
void KhoiTaoSV(LISTSV &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

//khoi tao 1 node
NODESV *KhoiTaoNODESV(SinhVien x) {
	NODESV *p = new NODESV; //cap phat vung nho	 cho node p
	if(p == NULL) {
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->sv = x;
	p->pNext = NULL;
	return p;
}

void ThemVaoDauDSSV(LISTSV &l, NODESV *p) {
	if(l.pHead == NULL) { //danh sach dang rong
		l.pHead = l.pTail = p; // node dau node cuoi la p
	}
	else{
		p->pNext = l.pHead; //cho con tro can them la node p lien ket voi pHead	
		l.pHead = p; //cap nhat lai pHead la node p
	}
}

void ThemVaoCuoiDSSV(LISTSV &l, NODESV *p) {
	if(l.pHead == NULL) { //danh sach dang rong
		l.pHead = l.pTail = p; // node dau node cuoi la p
	}
	else{
		l.pTail->pNext = p; //cho con tro pTail lien ket voi node p
		l.pTail = p; //cap nhat lai p la pTail
	}
}

void XoaDauSV(LISTSV &l) {
	if(l.pHead == NULL) {
		return;
	}
	NODESV *p = l.pHead; //node p la node se xoa
	l.pHead = l.pHead->pNext; // cap nhat lai pHead laf phan tu ke tiep
	delete p;
}

void XoaCuoiSV(LISTSV &l) {
	if(l.pHead == NULL) {
		return;
	}
	for(NODESV *k = l.pHead; k != NULL; k = k->pNext) {
		if(k->pNext == l.pTail) {
			delete l.pTail; // xoa di phan tu cuoi
			k->pNext == NULL; // cho con tro cua node cuoi tro toi null
			l.pTail = k; // cap nhat lai pTail
			return;
		}
	}
	NODESV *p = l.pHead; //node p la node se xoa
	l.pHead = l.pHead->pNext; // cap nhat lai pHead laf phan tu ke tiep
	delete p;
}

void XoaSVBatKy(LISTSV &l, char ma[]) {
	if(strcmp(l.pHead->sv.maSV, ma) == 0) {
		XoaDauSV(l);
		return;
	}
	if(strcmp(l.pTail->sv.maSV, ma) == 0) {
		XoaDauSV(l);
		return;
	}
	
	NODESV *g = new NODESV; // node g tro den node truoc node can xoa 
	for(NODESV *k = l.pHead; k != NULL; k = k->pNext) {
		if(strcmp(k->sv.maSV, ma) == 0) {
			g->pNext = k->pNext; // cap nhat lien ket cua node g voi node sau h
			delete k; // xoa node nam sau k
			return;
		}
		g = k; // cho node g tro den node k
	}
}

void GiaiPhongDSSV(LISTSV &l) {
	for(NODESV *k = l.pHead; k != NULL; k = k->pNext) {
		delete k;
	}
}

void XoaToanBoDSSV(LISTSV &l) {
	NODESV *k;
	while(l.pHead != NULL) {
		k = l.pHead;
		l.pHead = l.pHead->pNext;
		GiaiPhongDSSV(l);
	}
}

bool KiemTraMaSVTrung(LISTSV &l, char *ma) {
	if(l.pHead == NULL) return false; 
	for(NODESV *k = l.pHead; k != NULL; k = k->pNext) {
		if(strcmp(k->sv.maSV, ma) == 0) {
			return true;
		}
	}
	return false;
}

void NhapSV(LISTSV &l, SinhVien &sv) {
//	fflush(stdin);
//	do{
//		cout << "\nNhap ma lop: "; gets(sv.maLop);
//		if(KiemTraMaLopFile(sv.maLop) == false) {
//			cout << "\nMa lop k ton tai. Xin nhap lai: ";
//		}
//	} while(KiemTraMaLopFile(sv.maLop) == false);
	
	fflush(stdin);
	do{
		cout << "\nNhap masv: "; gets(sv.maSV);
		if(KiemTraMaSVTrung(l, sv.maSV) == true) {
			cout << "\nMa sv da bi trung. Xin nhap lai: "; gets(sv.maSV);
		}
	} while(KiemTraMaSVTrung(l, sv.maSV) == true);
	
	cout << "Nhap ho: "; gets(sv.ho);
	cout << "Nhap ten: "; gets(sv.ten);
	do{
		cout << "Nhap phai: "; gets(sv.phai);
		if((strcmp(sv.phai, "Nam") != 0 && strcmp(sv.phai, "nam") != 0 && strcmp(sv.phai, "Nu") != 0 && strcmp(sv.phai, "nu") != 0)){
			cout << "Nhap sai. Moi nhap lai phai (nam/nu)\n"; 	
		}
	} while((strcmp(sv.phai, "Nam") != 0 && strcmp(sv.phai, "nam") != 0 && strcmp(sv.phai, "Nu") != 0 && strcmp(sv.phai, "nu") != 0));
	fflush(stdin);
	cout << "Nhap password: "; gets(sv.password);
}

void XuatSV(SinhVien sv) {
	cout << "\nMasv: " << sv.maSV;
	cout << "\nHo: " << sv.ho;
	cout << "\nTen: " << sv.ten;
	cout << "\nPhai: " << sv.phai;
	cout << "\nPassword: " << sv.password;
}

void XuatDSSV(LISTSV l, SinhVien sv) {
	for(NODESV *k = l.pHead; k != NULL; k = k->pNext) {
		XuatSV(k->sv);
	}
}

LISTSV TimKiem(LISTSV &l, char ma[]) {
	for(NODESV *k = l.pHead; k != NULL; k = k->pNext) {
		if(strcmp(k->sv.maSV, ma) == 0) {
			XuatSV(k->sv);
		}
	}
//	return NULL;
}

void SuaThongTin(LISTSV &l, char ma[]) {
	TimKiem(l, ma);
}

void DocFileSV(LISTSV &l) {
	ifstream filein;
	SinhVien sv;
	filein.open("D:\\HT C++\\SINHVIEN.txt", ios_base::in);
	
	if(filein.fail()) return;
	else{
		while(!filein.eof()) {
			filein.getline(sv.maSV,16);
			filein.getline(sv.ho,30);
			filein.getline(sv.ten,10);
			filein.getline(sv.phai,4);
			filein.getline(sv.password,20);
			NODESV *p = KhoiTaoNODESV(sv);
			if(filein == NULL) {
	        	break;
	    	}
			ThemVaoCuoiDSSV(l, p);
		}
		filein.close();
	}
}

void DuyetFileSV(LISTSV &l, ofstream &fileout)
{
	if(l.pHead == NULL) return; 
	for(NODESV *k = l.pHead; k != NULL; k = k->pNext) {
		fileout << k->sv.maSV << endl;
        fileout << k->sv.ho << endl;
        fileout << k->sv.ten << endl;
        fileout << k->sv.phai << endl;
        fileout << k->sv.password << endl;
	}
}

void GhiFileSV(LISTSV &l) {
	ofstream fileout;
	fileout.open("D:\\HT C++\\SINHVIEN.txt", ios_base::in);
	if(!fileout.fail()) {
		DuyetFileSV(l, fileout);
		fileout.close();
	}
}

int main()  {
	LISTSV l;
	KhoiTaoSV(l);
	int n, dem = 0;
	SinhVien sv;
	char ma[16];
//	cout << "\nNhap so luong SV can them: ";
//	cin >> n;
//	for(int i = 0; i < n; i++) {
//		cout << "\nNhap sv thu: " << i + 1;
//		NhapSV(l, sv);
//		NODESV *p = KhoiTaoNODESV(sv);
//		ThemVaoCuoiDSSV(l, p);
//	}
//	cout << "\nDANH SACH LIEN KET DON\n";
//	XuatDSSV(l, sv);
//	
//	cout << endl;
//	cout << "\nNhap msv can xoa: "; gets(ma);
//	
//	cout << "\nDanh sach sau khi xoa : \n";
//	XoaSVBatKy(l, ma);
//	XuatDSSV(l, sv);

//	cout << "\nNhap msv can tim: "; gets(ma);
//	TimKiem(l, ma);
	
	
//	GhiFileSV(l);
//	ifstream filein;
//	filein.open("D:\\HT C++\\SINHVIEN.txt", ios_base::in);
	DocFileSV(l);
	XuatDSSV(l, sv);
	GiaiPhongDSSV(l);
	return 0;
}
