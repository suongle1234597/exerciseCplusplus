#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

// Danh sach Diem thi DSLKD
struct DiemThi{
	char maMH[10];
	float diem;
};
typedef struct DiemThi DIEMTHI;

struct nodeDiem{
	DIEMTHI dt;
	struct nodeDiem *pNext;
};
typedef nodeDiem NODEDIEM;

struct listDiem{
	NODEDIEM *pHead;
	NODEDIEM *pTail;
};
typedef struct listDiem LISTDIEM;

//KHOI TAO DSLKD
void KhoiTaoDIEM(LISTDIEM &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

//khoi tao 1 node
NODEDIEM *KhoiTaoNODEDIEM(DIEMTHI x) {
	NODEDIEM *p = new NODEDIEM; //cap phat vung nho	 cho node p
	if(p == NULL) {
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->dt = x;
	p->pNext = NULL;
	return p;
}

void ThemVaoDauDSDIEM(LISTDIEM &l, NODEDIEM *p) {
	if(l.pHead == NULL) { //danh sach dang rong
		l.pHead = l.pTail = p; // node dau node cuoi la p
	}
	else{
		p->pNext = l.pHead; //cho con tro can them la node p lien ket voi pHead	
		l.pHead = p; //cap nhat lai pHead la node p
	}
}

void ThemVaoCuoiDSDIEM(LISTDIEM &l, NODEDIEM *p) {
	if(l.pHead == NULL) { //danh sach dang rong
		l.pHead = l.pTail = p; // node dau node cuoi la p
	}
	else{
		l.pTail->pNext = p; //cho con tro pTail lien ket voi node p
		l.pTail = p; //cap nhat lai p la pTail
	}
}

void GiaiPhongDSDIEM(LISTDIEM &l) {
	for(NODEDIEM *k = l.pHead; k != NULL; k = k->pNext) {
		delete k;
	}
}

void XoaToanBoDSDIEM(LISTDIEM &l) {
	NODEDIEM *k;
	while(l.pHead != NULL) {
		k = l.pHead;
		l.pHead = l.pHead->pNext;
		GiaiPhongDSDIEM(l);
	}
}

void XuatDIEM(DIEMTHI dt) {
	cout << "\nMa mon: " << dt.maMH;
	cout << "\nDiem: " << dt.diem;
}
void XuatDSDIEM(LISTDIEM l, DIEMTHI dt) {
	for(NODEDIEM *k = l.pHead; k != NULL; k = k->pNext) {
		XuatDIEM(k->dt);
	}
}

void DocFileDIEM(LISTDIEM &l) {
	ifstream filein;
	DIEMTHI dt;
	filein.open("D:\\HT C++\\DIEMTHI.txt", ios_base::in);
	
	if(filein.fail()) return;
	else{
		while(!filein.eof()) {
			filein.getline(dt.maMH,10);
			filein >> dt.diem;
			NODEDIEM *p = KhoiTaoNODEDIEM(dt);
			if(filein == NULL) {
	        	break;
	    	}
			ThemVaoCuoiDSDIEM(l, p);
		}
		filein.close();
	}
}

void DuyetFileDIEM(LISTDIEM &l, ofstream &fileout)
{
	if(l.pHead == NULL) return; 
	for(NODEDIEM *k = l.pHead; k != NULL; k = k->pNext) {
		fileout << k->dt.maMH << endl;
        fileout << k->dt.diem << endl;
	}
}

void GhiFileDIEM(LISTDIEM &l) {
	ofstream fileout;
	fileout.open("D:\\HT C++\\DIEMTHI.txt", ios_base::in);
	if(!fileout.fail()) {
		DuyetFileDIEM(l, fileout);
		fileout.close();
	}
}

int main() {
	LISTDIEM listdiem;
	KhoiTaoDIEM(listdiem);
	DIEMTHI dt;
	
	int n;
	cout << "Nhap so luong diem: "; cin >> n;
	for(int i = 0; i < n; i++) {
		cout << "\nNhap ma mon hoc: "; cin >> dt.maMH;
		cout << "\nNhap diem: "; cin >> dt.diem;
		NODEDIEM *p = KhoiTaoNODEDIEM(dt);
		ThemVaoCuoiDSDIEM(listdiem, p);
	}
	XuatDSDIEM(listdiem, dt);
}
