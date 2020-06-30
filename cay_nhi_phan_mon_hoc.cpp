#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <fstream>

using namespace std;// Cay nhi phan Danh sach Mon hoc
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
void DocFileMH(TREE &t, ifstream &filein) {
	if(filein.fail()) return;
	else {
		while(!filein.eof()) {
			MONHOC mh;
			filein.getline(mh.maMH,10);
			filein.getline(mh.tenMH,30);
			ThemNodeMH(t, mh);
			if(filein == NULL) {
	        	break;
	    	}
		}
		filein.close();
	}
}
void GhiFileMH(TREE &t, ofstream &fileout) {
	fileout.open("D:\\HT C++\\MONHOC.txt", ios_base::in);
	if(!fileout.fail()) {
		DuyetFileMH(t, fileout);
		fileout.close();
	}
}
//void GiaiPhongDSMH(TREE t)
//{
//    if ( t == NULL )
//        return;
//    GiaiPhongDSMH( t->left );
//    GiaiPhongDSMH( t->right );
//    free( t );
//}

int main() {
	TREE t;
	MONHOC mh, a[100];
	int somh = 0;
	KhoiTaoCay(t);
	int n;
	char ma[10];
	cout << "\nNhap so luong mon hoc: "; cin >> n;
	for(int i = 0; i < n; i++) {
		NhapMH(t, mh);
		ThemNodeMH(t, mh);
	}
	LNR(t);
	fflush(stdin);
//	cout << "\nNhap ma can tim: " ; gets(ma);
//	TimKiemMH(t, ma);
////	
////	XoaMHBatKy(t, ma);

//	RNL(t);

//	ChoVaoMang(t, a, somh);
//	cout << "\nXuat mang: ";
//	for(int i = 0; i < somh; i++) {
//		cout << a[i].maMH << "  " << endl;
//		cout << a[i].tenMH << "  " << endl;
//	}
//	ofstream fileout;
//	GhiFileMH(t, fileout);

//	ifstream filein;
//	filein.open("D:\\HT C++\\MONHOC.txt", ios_base::in);
//	DocFileMH(t, filein);
////	NLR(t);
//	RNL(t);
	
	
	return 0;
}
