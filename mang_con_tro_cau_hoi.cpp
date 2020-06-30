#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#define MAXCAUHOI 2000

using namespace std;

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

struct CH{
	int id;
	int chiso;
};

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
		if (strcmp(mh.maMH, t->monhoc.maMH) < 0)
		{
			ThemNodeMH(t->pLeft, mh);
		}
		else if (strcmp(mh.maMH, t->monhoc.maMH) > 0)
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
		if(stricmp(mamh, p->monhoc.maMH) < 0) p = p->pLeft;
		else p = p->pRight;
	}
	return (p);
}

bool KiemTraMaMHTrung(TREE t, char ma[]) {
	if(t == NULL) {
		return false;
	}
	else {
		if(TimKiemMH(t, ma) != NULL) return true; 
	} 
	return false;
}

void NhapMH(TREE &t, MONHOC &mh) {
	fflush(stdin);
	do{
		fflush(stdin);
		cout << "\nNhap ma mon hoc: "; gets(mh.maMH);
		if(KiemTraMaMHTrung(t, mh.maMH) == true) {
			cout << "\nMa mh da bi trung. Xin nhap lai: "; 
		}
	} while(KiemTraMaMHTrung(t, mh.maMH) == true);
	
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

void DocFileMH(TREE &t) {
	ifstream filein;
	filein.open("D:\\HT C++\\MONHOC.txt", ios_base::in);
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

// Mang con tro CAU HOI THI//////////////////////////////////////////////////
struct CauHoi{
	int id = 1;
	char maMH[16];
	char noiDung[61];
	char A[18];
	char B[18];
	char C[18];
	char D[18];
	char dapAn[2];
};
typedef struct CauHoi CAUHOI;

struct ListCauHoi{
	int n;
	CAUHOI *nodeCauHoi [MAXCAUHOI];
};
typedef struct ListCauHoi LISTCAUHOI;

bool KiemTraMaMHFile(char mamh[]) {
	TREE t;
	KhoiTaoCay(t);
	
	DocFileMH(t);
	if(KiemTraMaMHTrung(t, mamh) == true) return true;
	return false;
}

void Swap(int &x, int &y)
{
 	int tam;
 	tam = x;
 	x = y;
 	y = tam;
}

//int Random() {
//	srand(time(NULL));
// 	int b, r, k;
// 	if(j == 1) j = 2;
// 	k = j - 1;
//	for(int i = k; i < MAXCAUHOI; i++)
// 	{
// 		r = i + (rand() % (MAXCAUHOI - i));
// 		b = a[r];
//		Swap(a[i], a[r]);
// 		j++;
// 		break;
// 	}
// 	return b;
//}

//void SwapID(int id) {
// 	for(int i = j; i < MAXCAUHOI; i++)
// 	{
// 		if(a[i] == id) {
// 			Swap(a[i], a[j]);
// 			j++;
//		}
// 	}
//}

void InsertOrderCauHoi (LISTCAUHOI &list, CauHoi ch){
	int j, k;
	for (j = 0; j < list.n && list.nodeCauHoi[j]->id < ch.id; j++);
	for ( k = list.n-1; k >= j; k--) 
		list.nodeCauHoi[k+1] = list.nodeCauHoi[k];
	list.nodeCauHoi[j]= new CauHoi;
	*list.nodeCauHoi[j]=ch; list.n++;
}


int TimIDMax(LISTCAUHOI &list) {
	int max = 0;
  	for(int i = 0; i < list.n; i++) 
		if(max < list.nodeCauHoi[i]->id) {
			max = list.nodeCauHoi[i]->id;
		}
	return max;
}

void NhapCauHoi(LISTCAUHOI &list, CauHoi &cauhoi) {
	fflush(stdin);
	do {
		cout << "\nNhap ma mon hoc: "; gets(cauhoi.maMH);
		if(KiemTraMaMHFile(cauhoi.maMH) == false) {
			cout << "\nMa mon hoc khong ton tai. Moi nhap lai !";
		}
	} while(KiemTraMaMHFile(cauhoi.maMH) == false);
	cauhoi.id = TimIDMax(list) + 1;
	cout << "Nhap noi dung: "; gets(cauhoi.noiDung);
	cout << "Nhap A: "; gets(cauhoi.A);
	cout << "Nhap B: "; gets(cauhoi.B);
	cout << "Nhap C: "; gets(cauhoi.C);
	cout << "Nhap D: "; gets(cauhoi.D);
	cout << "Nhap dap an: "; gets(cauhoi.dapAn);
//	InsertOrderCauHoi(list, cauhoi);
}

void NhapDSCH (LISTCAUHOI &list, int flag){
 	CauHoi ch;
	if (flag == 0) 
	 	while (list.n > 0){
	 	   delete list.nodeCauHoi[list.n-1];
	       list.n-- ;
	   }
	
	 while (list.n < 6)
	 {  
	 	NhapCauHoi(list, ch);
	    list.nodeCauHoi[list.n]= new CauHoi;
	    *list.nodeCauHoi[list.n]=ch;
	    list.n++;
	 }
 	if (list.n == MAXCAUHOI) cout << "Danh sach day";
}

void XuatCauHoi(LISTCAUHOI &list, CauHoi &cauhoi) {
	cout << "\nMa mon hoc: " << cauhoi.maMH;
	cout << "\nID: " << cauhoi.id;
	cout << "\nNoi dung: " << cauhoi.noiDung;
	cout << "\nA: " << cauhoi.A;
	cout << "\nB: " << cauhoi.B;
	cout << "\nC: " << cauhoi.C;
	cout << "\nD: " << cauhoi.D;
	cout << "\nDap an: " << cauhoi.dapAn;
}

void LietKeCauHoi (ListCauHoi list) {
	 for (int i = 0 ; i < list.n; i++)
	 {
	 	cout << "\nMa mon hoc: " << list.nodeCauHoi[i]->maMH;
	 	cout << "\nID: " << list.nodeCauHoi[i]->id;
		cout << "\nNoi dung: " << list.nodeCauHoi[i]->noiDung;
		cout << "\nA: " << list.nodeCauHoi[i]->A;
		cout << "\nB: " << list.nodeCauHoi[i]->B;
		cout << "\nC: " << list.nodeCauHoi[i]->C;
		cout << "\nD: " << list.nodeCauHoi[i]->D;
		cout << "\nDap an: " << list.nodeCauHoi[i]->dapAn;
	 }
}

void LietKeCauHoiThi (CAUHOI ch[], int soch) {
	 for (int i = 0 ; i < soch; i++)
	 {
	 	cout << "\nMa mon hoc: " << ch[i].maMH;
	 	cout << "\nID: " << ch[i].id;
		cout << "\nNoi dung: " << ch[i].noiDung;
		cout << "\nA: " << ch[i].A;
		cout << "\nB: " << ch[i].B;
		cout << "\nC: " << ch[i].C;
		cout << "\nD: " << ch[i].D;
		cout << "\nDap an: " << ch[i].dapAn;
	 }
}

void LietKeCauHoiTheoMonHoc(LISTCAUHOI list, CH dsch[], int n) {
	for (int i = 1 ; i <= n; i++) {
		cout << "\nID: " << dsch[i].id;
		for(int j = 0; j < list.n; j++) 
			if(dsch[i].chiso == j) {
				cout << "\nNoi dung: " << list.nodeCauHoi[j]->noiDung;
				cout << "\nA: " << list.nodeCauHoi[j]->A;
				cout << "\nB: " << list.nodeCauHoi[j]->B;
				cout << "\nC: " << list.nodeCauHoi[j]->C;
				cout << "\nD: " << list.nodeCauHoi[j]->D;
				cout << "\nDap an: " << list.nodeCauHoi[j]->dapAn;
			}
	}
}

int TimKiemCauHoi(LISTCAUHOI &list, int x) {
  for (int i =0; i < list.n ; i++)
     if (list.nodeCauHoi[i]->id == x) return i;
  return -1;
}

void XoaCauHoi(LISTCAUHOI &list, int id){
	int i = TimKiemCauHoi(list, id) ;
   	if (i == -1) cout << "ID cau hoi khong co trong danh sach";
   	else  
   	{ 
		delete  list.nodeCauHoi[i];
     	for (int j = i + 1; j < list.n; j++)
       		list.nodeCauHoi[j-1] = list.nodeCauHoi[j];
       	list.n--;  
	}
}

void SwapCH(CH x, CH y)
{
 	CH tam = x;
 	x = y;
 	y = tam;
}

void RandomCauHoi(CH dsch[], int sochthi, int sochmh)
{
    srand(time(NULL));
    int m = 0, r;
    for(int i = 1; i <= sochthi; i++) {
     	r = i + rand() % (sochmh - i + 1); //cong 1 de co phan tu cuoi cung
    	SwapCH(dsch[i], dsch[r]);
	}
} 

void GhiFileCauHoi(LISTCAUHOI &list) {
	ofstream fileout;
 	fileout.open("D:\\HT C++\\CAUHOI.txt", ios_base::in);
 	if(!fileout.fail()) {
 		for (int i=0; i < list.n; i++) {
 			fileout << list.nodeCauHoi[i]->maMH << endl;
 			fileout << list.nodeCauHoi[i]->id << endl;
 			fileout << list.nodeCauHoi[i]->noiDung << endl;
 			fileout << list.nodeCauHoi[i]->A << endl;
 			fileout << list.nodeCauHoi[i]->B << endl;
 			fileout << list.nodeCauHoi[i]->C << endl;
 			fileout << list.nodeCauHoi[i]->D << endl;
 			fileout << list.nodeCauHoi[i]->dapAn << endl;
		}
		fileout.close();
	}
}

void DocFileCauHoi(LISTCAUHOI &list) {
	ifstream filein;
	filein.open("D:\\HT C++\\CAUHOI.txt", ios_base::in);
	CauHoi ch;
	if(filein.fail()) return;
	else {
		list.n = 0;
		
		while(!filein.eof()) {
			filein >> ch.maMH;
			filein >> ch.id;
			filein >> ch.noiDung;
			filein >> ch.A;
			filein >> ch.B;
			filein >> ch.C;
			filein >> ch.D;
			filein >> ch.dapAn;
 			list.nodeCauHoi[list.n] = new CauHoi;
 			*list.nodeCauHoi[list.n] = ch;
 			list.n ++;
			if(filein == NULL) {
				list.n--;
	        	break;
	    	}
		}
	}
	filein.close();
}

int SoLuongCHTheoMH(LISTCAUHOI listch, char mamh[]) {
	int soluong = 0;
	for(int i = 0; i < listch.n; i++) 
		if(strcmp(listch.nodeCauHoi[i]->maMH, mamh) == 0) soluong++;
	return soluong;
}

void DSCauHoiTheoMH(LISTCAUHOI listch, CH dsch[], char mamh[]) {
	int j = 1;
	for(int i = 0; i < listch.n; i++) 
		if(stricmp(listch.nodeCauHoi[i]->maMH, mamh) == 0) {
			dsch[j].id = listch.nodeCauHoi[i]->id;
			dsch[j].chiso = i;
			j++;
		}
}

int main() {
	TREE t;
	KhoiTaoCay(t);
	MONHOC mh;
	
	LISTCAUHOI listch;
	listch.n = 0;
	CAUHOI ch;
	int n = 0, soch;
	char mamh[16];
	
// 	for(int i = 1; i < MAXCAUHOI; i++) a[i] = i;
	

	DocFileCauHoi(listch);	
//	NhapDSCH(listch, 0);
//	LietKeCauHoi (listch);
//		GhiFileCauHoi(listch);
//	cout << "\nNhap so luong cau hoi: "; cin >> n;
	
	//Tim max + 1
	cout << "\nNhap ma mon hoc: "; gets(mamh);
	cout << "\nNhap so luong cau hoi: "; cin >> soch;
	int M = SoLuongCHTheoMH(listch, mamh);
	CH *dsch = new CH[M + 1]; //chay tu 1
	DSCauHoiTheoMH(listch, dsch, mamh);
	
	LietKeCauHoiTheoMonHoc(listch, dsch, M);
	RandomCauHoi(dsch, soch, M);
	cout << "\n\nRANDOM: ";
	LietKeCauHoiTheoMonHoc(listch, dsch, soch);
	return 0;
}

