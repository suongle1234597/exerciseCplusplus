#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <fstream>
#include <windows.h>
#define MAXLOP 500
using namespace std;

// Mang con tro DANH SACH LOP
struct Lop{
	char maLop[16];
	char tenLop[20];
//    LISTSV dssv ;
};
typedef struct Lop LOP;

struct ListLop{
	int n;
	Lop *nodeLop[MAXLOP];
};
typedef struct ListLop LISTLOP;

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

void GhiFileLop(LISTLOP &list, ofstream &fileout) {
 	fileout.open("LOP.txt", ios_base::in);
 	if(!fileout.fail()) {
 		for (int i=0; i < list.n; i++) {
 			fileout << list.nodeLop[i]->maLop << endl;
 			fileout << list.nodeLop[i]->tenLop << endl;
		}
		fileout.close();
	}
}

void DocFileLop(LISTLOP &list, ifstream &filein) {
	LOP lop;
	if(filein.fail()) return;
	else {
		list.n = 0;
		while(!filein.eof()) {
			filein.getline(lop.maLop,16);
			filein.getline(lop.tenLop,30);
 			list.nodeLop[list.n]=new LOP;
 			*list.nodeLop[list.n]=lop;
 			list.n ++;
			if(filein == NULL) {
				list.n--;
	        	break;
	    	}
		}
	}
	filein.close();
}

int InsertOrder (LISTLOP &list, LOP lop){ //them co thu tu
	int j, k;
	if (list.n == MAXLOP ) return 0;
	for (j=0; (j < list.n) && strcmp(list.nodeLop[j]->maLop, lop.maLop) < 0; j++ );
	for ( k = list.n-1; k >=j  ; k--) 
	   list.nodeLop[k+1]= list.nodeLop[k];
	list.nodeLop[j]= new LOP;
	*list.nodeLop[j]=lop; list.n++;
	return 1;
}

int main() {
	int n;
	LISTLOP list;
	LOP lop;
	list.n = 0;
	char ma[16];
	
	ofstream fileout;
	
//	NhapDSLop(list, 0);
	GhiFileLop(list, fileout);
	
//cout << "\nNhap n: "; cin >> n;
//	for(int i = 0; i < n; i++) {
//		NhapLop(list, lop);
//		InsertOrder(list, lop);
//	}
	ifstream filein;
	filein.open("LOP.txt", ios_base::in);
	DocFileLop(list, filein);
	
	LietKeLop(list);
	cout << "\nNhap ma lop can xoa: "; gets(ma);
	XoaLop(list, ma);
	LietKeLop(list);
	return 0;
}

