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
	int sldiemthi = 0;
};
typedef struct listDiem LISTDIEM;

struct SinhVien{
	char maSV[16];
	char ho[30];
	char ten[10];
	char phai[4];
	char password[20];
	LISTDIEM dsd;
};

struct nodeSV{
	SinhVien sv;
	struct nodeSV *pNext;
};
typedef nodeSV NODESV;

struct listSV{
	NODESV *pHead;
	NODESV *pTail;
	int slsv = 0;
};
typedef struct listSV LISTSV;

void KhoiTaoSV(LISTSV &l);

struct Lop{
	char maLop[16];
	char tenLop[20];
    LISTSV dssv;
};
typedef struct Lop LOP;

struct ListLop{
	int n;
	Lop *nodeLop[MAXLOP];
};
typedef struct ListLop LISTLOP;

struct MonHoc {
	char maMH[10];
	char tenMH[30];

};
typedef struct MonHoc MONHOC;

struct nodeMH{
	MONHOC monhoc;
	nodeMH *pLeft;
	nodeMH *pRight;
};
typedef struct nodeMH NODEMH;
typedef NODEMH *TREE;


void KhoiTaoCay(TREE &t)
{
	t = NULL;
}

// ham them 1 cai node vao cay nhi phan tim kiem
void ThemNodeMH(TREE &t, MONHOC mh)
{
	// cay dang rong
	if (t == NULL)
	{
		NODEMH *p = new NODEMH;
		p->monhoc = mh;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p; // thang them vao cung chinh la node goc
	}
	else
	{
		if (t->monhoc.maMH > mh.maMH)
		{
			ThemNodeMH(t->pLeft, mh);
		}
		else if (t->monhoc.maMH < mh.maMH)
		{
			ThemNodeMH(t->pRight, mh);
		}
	}
}

// duyet theo NLR
void NLR(TREE t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		cout << t->monhoc.maMH << "  " << endl;
		cout << t->monhoc.tenMH << "  " << endl;
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}

// duyet cay theo NRL
void NRL(TREE t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		cout << t->monhoc.maMH << "  " << endl;
		cout << t->monhoc.tenMH << "  " << endl;
		NRL(t->pRight);
		NRL(t->pLeft);
	}
}

// duyet cay theo LNR
void LNR(TREE t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		LNR(t->pLeft);
		cout << t->monhoc.maMH << "  " << endl;
		cout << t->monhoc.tenMH << "  " << endl;
		LNR(t->pRight);
	}
}

// duyet theo RNL
void RNL(TREE t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		RNL(t->pRight);
		cout << t->monhoc.maMH << "  " << endl;
		cout << t->monhoc.tenMH << "  " << endl;
		RNL(t->pLeft);
	}
}

// duyet cay theo LRN
void LRN(TREE t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		LRN(t->pLeft);		
		LRN(t->pRight);
		cout << t->monhoc.maMH << "  " << endl;
		cout << t->monhoc.tenMH << "  " << endl;
	}
}

// duyet cay theo RLN
void RLN(TREE t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		RLN(t->pRight);
		RLN(t->pLeft);
		cout << t->monhoc.maMH << "  " << endl;
		cout << t->monhoc.tenMH << "  " << endl;
	}
}

NODEMH* TimKiemMH (TREE t, char mamh[]) {
	NODEMH *p;
	p = t; // p la nut goc
	while(p != NULL && strcmp(p->monhoc.maMH, mamh) != 0) {
		if(strcmp(p->monhoc.maMH, mamh) > 0) p = p->pLeft;
		else p = p->pRight;
	}
	return (p);
}

void NhapMH(TREE &t, MONHOC &mh) {
	fflush(stdin);
	do{
		fflush(stdin);
		cout << "\nNhap ma mon hoc: "; gets(mh.maMH);
		if(TimKiemMH(t, mh.maMH) != NULL) {
			cout << "\nMa mh da bi trung. Xin nhap lai: "; 
		}
	} while(TimKiemMH(t, mh.maMH) != NULL);
	fflush(stdin);
	cout << "\nNhap ten mon hoc: "; gets(mh.tenMH);
}

void TimNodeTheMangMH(TREE &x, TREE &y) {
	if(y->pLeft != NULL) {
		TimNodeTheMangMH(x, y->pLeft);
	}
	else {
		x->monhoc = y->monhoc;
		x = y;
		y = y->pRight;
	}
}

void TimNodeTheMangLeftMH(TREE &x, TREE &y) {
	if(y->pRight != NULL) {
		TimNodeTheMangMH(x, y->pRight);
	}
	else {
		x->monhoc = y->monhoc;
		x = y;
		y = y->pLeft;
	}
}

void XoaMHBatKy (TREE &t, char ma[]) {
	if(t == NULL) {
		return;
	}
	else {
		if(strcmp(t->monhoc.maMH, ma) < 0) { //neu t->monhoc.maMH nho hon ma
			XoaMHBatKy(t->pLeft, ma);
		}
		else if(strcmp(t->monhoc.maMH, ma) > 0) {
			XoaMHBatKy(t->pRight, ma);
		}
		else {
			NODEMH *X = t; // node X la node the mang
			if(t->pLeft == NULL) { //neu nhanh phai bang null -> la cay con phai
				t = t->pRight;
			}
			else if(t->pRight == NULL) {
				t = t->pLeft;
			}
			else{
				TimNodeTheMangLeftMH(X, t->pLeft);
			}
			delete X;
		}
	}
}

void ChoVaoMang(TREE t, MONHOC a[], int &somh) {
	if(t == NULL) {
		return;
	}
	else {
		ChoVaoMang(t->pLeft, a, somh);
		ChoVaoMang(t->pRight, a, somh);
		a[somh] = t->monhoc;
		somh++;
			
	}
}
void DuyetFileMH(TREE t, ofstream &fileout)
{
    if(t!=NULL)
    {
        DuyetFileMH(t->pRight, fileout);
        fileout << t->monhoc.maMH << endl;
        fileout << t->monhoc.tenMH << endl;
        DuyetFileMH(t->pLeft, fileout);
    }
}
void GhiFileMH(TREE &t) {
	ofstream fileout;
	fileout.open("D:\\HT C++\\MONHOC.txt", ios_base::in);
	if(!fileout.fail()) {
		DuyetFileMH(t, fileout);
		fileout.close();
	}
}

void DocFileMH(TREE &t) {
	ifstream filein;
	filein.open("D:\\HT C++\\MONHOC.txt", ios_base::in);
	MONHOC mh;
	if(filein.fail()) return;
	else {
		while(!filein.eof()) {
			filein.getline(mh.maMH,10);
			filein.getline(mh.tenMH,40);
			ThemNodeMH(t, mh);
			if(filein == NULL) {
	        	break;
	    	}
		}
	}
	filein.close();
}
bool KiemTraMaMHTrung(TREE t, char ma[]) {
	if(t == NULL) {
		return false;
	}
	else {
		if(TimKiemMH(t, ma) != NULL) return true;  // trung
	} 
	return false;
}
bool KiemTraMaMHFile(char mamh[]) {
	TREE t;
	KhoiTaoCay(t);
	
	DocFileMH(t);
	if(KiemTraMaMHTrung(t, mamh) == true) return true;
	return false;
}

int TimKiemLop(LISTLOP &list, char *malop) {
  	for (int i = 0; i < list.n ; i++)
     	if (strcmp(list.nodeLop[i]->maLop, malop) == 0) return i;
  	return -1;
}

int NhapLop(LISTLOP &list, LOP &lop) {
	fflush(stdin);
	do {
		cout << "Nhap ma lop: "; gets(lop.maLop);
		if(TimKiemLop(list, lop.maLop) != -1) {
			cout << "\nMa lop bi trung. Moi nhap lai !";
		}
	} while(TimKiemLop(list, lop.maLop) != -1);

	cout << "Nhap ten lop: "; gets(lop.tenLop);
}

void NhapDSLop (LISTLOP &list, int n){
 	LOP lop;
 	if (n == 0) 
	 	while (list.n > 0){
	 	   delete list.nodeLop[list.n-1];
	       list.n-- ;
	   	}

 	while (list.n < 5)
 	{  
 		NhapLop(list, lop);
    	list.nodeLop[list.n]= new LOP;
    	*list.nodeLop[list.n] = lop;
    	list.n++;
 	}
 	if(list.n == MAXLOP) cout << "\nBo nho day";
}

void LietKeLop (ListLop list) {
 	cout << "\nDanh sach lop";

 	for (int i = 0 ; i < list.n ; i++)
 	{
 		cout << "\nMa lop: " << list.nodeLop[i]->maLop;
		cout << "\nTen lop: " << list.nodeLop[i]->tenLop;
 	}
}

void XoaLop(LISTLOP &list, char malop[]){
	int i = TimKiemLop(list ,malop) ;
   	if (i == -1) cout << "Ma lop khong co trong danh sach";
   	else  
   	{ 
		delete  list.nodeLop[i];
     	for (int j = i + 1; j < list.n; j++)
       		list.nodeLop[j-1] = list.nodeLop[j];
       	list.n--;  
	}
}

void GhiFileLop(LISTLOP listlop) {
	ofstream fileout;
 	fileout.open("D:\\HT C++\\LOP.txt", ios_base::in);
 	int dem = 0;
 	if(!fileout.fail()) {
 		fileout << listlop.n << endl;
 		for (int i = 0; i < listlop.n; i++) {
 			fileout << listlop.nodeLop[i]->maLop << endl;
 			fileout << listlop.nodeLop[i]->tenLop << endl;
 			
 			fileout << listlop.nodeLop[i]->dssv.slsv;
 			if(!(i == listlop.n - 1 && listlop.nodeLop[i]->dssv.slsv == 0)) fileout << endl;
 			
 			for(NODESV *p = listlop.nodeLop[i]->dssv.pHead; p != NULL; p = p->pNext) {
				fileout << p->sv.maSV << endl;
		        fileout << p->sv.ho << endl;
		        fileout << p->sv.ten << endl;
		        fileout << p->sv.phai << endl;
		        fileout << p->sv.password << endl;
		        dem++;
		        
		        fileout << p->sv.dsd.sldiemthi;
		        if(!(dem == listlop.nodeLop[i]->dssv.slsv && p->sv.dsd.sldiemthi == 0)) fileout << endl;
		        for(NODEDIEM *q = p->sv.dsd.pHead; q != NULL; q = q->pNext) {
					fileout << q->dt.maMH << endl;
			        fileout << q->dt.diem;
			        if(i < listlop.n - 1) fileout << endl;
				}
			}
		}
	}
	fileout.close();
}

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

void ThemVaoCuoiDSDIEM(LISTDIEM &l, NODEDIEM *p) {
	if(l.pHead == NULL) { //danh sach dang rong
		l.pHead = l.pTail = p; // node dau node cuoi la p
	}
	else{
		l.pTail->pNext = p; //cho con tro pTail lien ket voi node p
		l.pTail = p; //cap nhat lai p la pTail
	}
}
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
void ThemVaoCuoiDSSV(LISTSV &l, NODESV *p) {
	p->sv.dsd.pHead = NULL;
	if(l.pHead == NULL) { //danh sach dang rong
		l.pHead = l.pTail = p; // node dau node cuoi la p
	}
	else{
		l.pTail->pNext = p; //cho con tro pTail lien ket voi node p
		l.pTail = p; //cap nhat lai p la pTail
	}
}
void DocFileLop(LISTLOP &listlop) {
	ifstream filein;
	filein.open("D:\\HT C++\\LOP.txt", ios_base::in);
	LOP lop;
	SinhVien sv;
	DIEMTHI dt;
	if(filein.fail()) return;
		while(!filein.eof()) {
			filein>>listlop.n;
			for (int i = 0; i < listlop.n; i++) {
				
				filein>>lop.maLop;
				filein>>lop.tenLop; 
				lop.dssv.pHead = NULL;
				listlop.nodeLop[i]=new LOP;
				*listlop.nodeLop[i]=lop;
				
				filein>>listlop.nodeLop[i]->dssv.slsv;
				for(int j = 0; j < listlop.nodeLop[i]->dssv.slsv; j++) {
					filein>>sv.maSV;
					filein>>sv.ho;
					filein>>sv.ten;
					filein>>sv.phai;
					filein>>sv.password;
					NODESV *p = KhoiTaoNODESV(sv);
					ThemVaoCuoiDSSV(listlop.nodeLop[i]->dssv, p);
				
					filein>>p->sv.dsd.sldiemthi;
					for(int k = 0; k < p->sv.dsd.sldiemthi; k++) {
						filein >> dt.maMH;
						filein >> dt.diem;
						NODEDIEM *q = KhoiTaoNODEDIEM(dt);
						ThemVaoCuoiDSDIEM(p->sv.dsd, q);
					}
				}
//			if(filein == NULL) break;
		}
	}
	filein.close();
}

int InsertOrder (LISTLOP &list, LOP lop){ //them co thu tu
	int j, k;
	if (list.n == MAXLOP ) return 0;
	for (j=0; (j < list.n) && strcmp(list.nodeLop[j]->maLop, lop.maLop) < 0; j++ );
	for ( k = list.n-1; k >= j; k--) 
	   list.nodeLop[k+1]= list.nodeLop[k];
	list.nodeLop[j]= new LOP;
	*list.nodeLop[j]=lop; list.n++;
	return 1;
}

//KHOI TAO DSLKD
void KhoiTaoSV(LISTSV &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

//khoi tao 1 node


void ThemVaoDauDSSV(LISTSV &l, NODESV *p) {
	if(l.pHead == NULL) { //danh sach dang rong
		l.pHead = l.pTail = p; // node dau node cuoi la p
	}
	else{
		p->pNext = l.pHead; //cho con tro can them la node p lien ket voi pHead	
		l.pHead = p; //cap nhat lai pHead la node p
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

//bool KiemTraMaLopFile(char malop[]) {
//	LISTLOP list;
//	list.n = 0;
//	
//	DocFileLop(list);
//	if(TimKiemLop(list, malop) != -1) return true;
//	return false;
//}

void NhapSV(LISTSV &l, SinhVien &sv) {
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
//	cout << "\nMalop: " << sv.maLop;
	cout << "\nMasv: " << sv.maSV;
	cout << "\nHo: " << sv.ho;
	cout << "\nTen: " << sv.ten;
	cout << "\nPhai: " << sv.phai;
	cout << "\nPassword: " << sv.password;
}

void XuatDSSV(LISTSV l) {
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
//			filein.getline(sv.maLop,16);
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

///////////////DIEM////////////////////


//KHOI TAO DSLKD
void KhoiTaoDIEM(LISTDIEM &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

//khoi tao 1 node
void ThemVaoDauDSDIEM(LISTDIEM &l, NODEDIEM *p) {
	if(l.pHead == NULL) { //danh sach dang rong
		l.pHead = l.pTail = p; // node dau node cuoi la p
	}
	else{
		p->pNext = l.pHead; //cho con tro can them la node p lien ket voi pHead	
		l.pHead = p; //cap nhat lai pHead la node p
	}
}

void XuatDIEM(DIEMTHI dt) {
	cout << "\nMa mon: " << dt.maMH;
	cout << "\nDiem: " << dt.diem;
}

void NhapDIEM(DIEMTHI &dt) {
	fflush(stdin);
	cout << "\nNhap ma mon: "; gets(dt.maMH);
	cout << "\nNhap diem: "; cin >> dt.diem;
}

void TimKiemDIEM(LISTDIEM &l, char mamh[]) {
	for(NODEDIEM *k = l.pHead; k != NULL; k = k->pNext) {
		if(strcmp(k->dt.maMH, mamh) == 0) {
			XuatDIEM(k->dt);
		}
	}
//	return NULL;
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
int main()  {
	TREE t;
	KhoiTaoCay(t);
	LISTLOP listlop;
	LOP lop;
	listlop.n = 0;
	LISTSV l;
	KhoiTaoSV(l);
	LISTDIEM listdiem;
	KhoiTaoDIEM(listdiem);
	int  n, m, dem = 0;
	SinhVien sv;
	DIEMTHI dt;
	char ma[16];
	char maLop[16], monhoc[10];
	
//	NhapDSLop(listlop, 0);
//	do {
//		cout << "\nNhap ma lop: "; gets(maLop);
//		if(TimKiemLop(listlop, maLop) == -1) {
//			cout << "\nMa lop khong co trong danh sach. Moi nhap lai !";
//		}
//	} while(TimKiemLop(listlop, maLop) == -1);
//	
//	cout << "\nNhap so luong SV can them: ";
//	cin >> n;
//	for(int i = 0; i < listlop.n; i++) {
//		if(strcmp(listlop.nodeLop[i]->maLop, maLop) == 0) {
//			for(int j = 0; j < n; j++) {
//				NhapSV(l, sv);
//				NODESV *p = KhoiTaoNODESV(sv);
//				ThemVaoCuoiDSSV(listlop.nodeLop[i]->dssv, p);
//				listlop.nodeLop[i]->dssv.slsv++;
//				cout << "\nNhap so luong mon thi: ";
//				cin >> m;
//				for(int k = 0; k < m; k++) {
//					NhapDIEM(dt);
//					NODEDIEM *q = KhoiTaoNODEDIEM(dt);
//					ThemVaoCuoiDSDIEM(p->sv.dsd, q);
//					p->sv.dsd.sldiemthi++; 
//					
//				}
//				
//			}
//			break;
//		}	
//	}
//	
//	GhiFileLop(listlop);
	
	DocFileLop(listlop);
	LietKeLop(listlop);
	do {
		cout << "\nNhap ma lop: "; gets(maLop);
		if(TimKiemLop(listlop, maLop) == -1) {
			cout << "\nMa lop khong co trong danh sach. Moi nhap lai !";
		}
	} while(TimKiemLop(listlop, maLop) == -1);
	cout << "\nNhap mon hoc: "; gets(monhoc);
	DIEMTHI diemtam;
	NODEDIEM *q;
	diemtam.diem = 0;
	strcpy (diemtam.maMH, monhoc);
	for(int i = 0; i<listlop.n; i++)
		if(stricmp(listlop.nodeLop[i]->maLop, maLop) == 0) {
			for(NODESV *p = listlop.nodeLop[i]->dssv.pHead; p != NULL; p = p->pNext) {
					XuatSV(p->sv);
					for(q = p->sv.dsd.pHead; q != NULL; q = q->pNext)
						if(strcmp(q->dt.maMH, monhoc) == 0) {
							XuatDIEM(q->dt);
							break;
						}
					if (q == NULL) XuatDIEM(diemtam);
			}
			break;
		}
		
	return 0;
}
