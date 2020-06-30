#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
 
struct hanghoa {
	int ma;
	string ten;
	string dvt;
	int soluongton;
	float VAT;
};
typedef struct hanghoa HANGHOA;

//Nhap thong tin hang hoa
void Nhap(HANGHOA &hang) {
	cout << "\nNhap ma hang hoa: "; cin >> hang.ma;
	fflush(stdin);
	cout << "Nhap ten hang hoa: "; getline(cin, hang.ten);
	cout << "Nhap don vi tinh: "; getline(cin, hang.dvt); 
	cout << "Nhap so luong ton: "; cin >> hang.soluongton;
	fflush(stdin);
	cout << "Nhap phan tram thue VAT: "; cin >> hang.VAT; 
} 

void Xuat(HANGHOA hang) {
	cout << "\nMa hang hoa: " << hang.ma;
	cout << "\nTen hang hoa: " << hang.ten;
	cout << "\nDon vi tinh: " << hang.dvt; 
	cout << "\nSo luong ton: " << hang.soluongton;
	cout << "\nPhan tram thue VAT: " << hang.VAT; 
} 

struct node {
	HANGHOA data;
	node *pLeft;
	node *pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

void KhoiTaoCay(TREE &t) {
	t = NULL;
}

void ThemNode(TREE &t, HANGHOA x) {
	if(t == NULL) {
		NODE *p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else {
		if(x.ma > t->data.ma) {
			ThemNode(t->pRight, x);
		}
		else if(x.ma < t->data.ma){
			ThemNode(t->pLeft, x);
		}
	}
}

// duyet cay NODE LEFT RIGHT
void NLR(TREE t) {
	if(t == NULL) {
		return;
	}
	else {
		Xuat(t->data);
		cout << endl;
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}

// duyet cay NODE RIGHT LEFT
void NRL(TREE t) {
	if(t == NULL) {
		return;
	}
	else {
		Xuat(t->data);
		cout << endl;
		NRL(t->pRight);
		NRL(t->pLeft);
	}
}

// duyet cay LEFT NODE RIGHT
void LNR(TREE t) {
	if(t == NULL) {
		return;
	}
	else {
		LNR(t->pLeft);
		Xuat(t->data);
		cout << endl;
		LNR(t->pRight);
	}
}

// duyet cay RIGHT NODE LEFT
void RNL(TREE t) {
	if(t == NULL) {
		return;
	}
	else {
		RNL(t->pRight);
		Xuat(t->data);
		cout << endl;
		RNL(t->pLeft);
	}
}

// duyet cay LEFT RIGHT NODE
void LRN(TREE t) {
	if(t == NULL) {
		return;
	}
	else {
		LRN(t->pLeft);
		LRN(t->pRight);
		Xuat(t->data);
		cout << endl;
	}
}

// duyet cay RIGHT LEFT NODE
void RLN(TREE t) {
	if(t == NULL) {
		return;
	}
	else {
		RLN(t->pRight);
		RLN(t->pLeft);
		Xuat(t->data);
		cout << endl;
	}
}

void TimKiem (TREE t, int x) {
	if(t == NULL) {
		return;
	}
	else {
		if(x == t->data.ma) {
			Xuat(t->data);
		}
		TimKiem(t->pLeft, x);
		TimKiem(t->pRight, x);
	}
}

void ChoVaoMang(TREE t, HANGHOA a[], int &n) {
	if(t == NULL) {
		return;
	}
	else {
		a[n] = t->data;
		n++;
		ChoVaoMang(t->pLeft, a, n);
		ChoVaoMang(t->pRight, a, n);
	}
}

void SapXepMang(TREE t, HANGHOA a[], int n) {
	HANGHOA tam;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(a[i].soluongton < a[j].soluongton) {
				tam = a[i];
				a[i] = a[j];
				a[j] = tam;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		Xuat(a[i]);
		cout << endl;
	}
}

//void TongTonKho(TREE t, int sum) {
//	if(t == NULL) {
//		return;
//	}
//	else {
//		sum = sum + t->data.soluongton;
////		cout << sum;
//		TongTonKho(t->pLeft, sum);
//		TongTonKho(t->pRight, sum);
//	}
//}

void TongTonKho(HANGHOA a[], int n) {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		sum = sum + a[i].soluongton;
	}
	cout << " " << sum << endl;
}

//void InTonKhoMAX(HANGHOA a[], int n) {
//	HANGHOA tam = a[0];
//	int max = a[0].soluongton;
//	for(int i = 0; i < n; i++) {
//		if(max < a[i].soluongton) {
//			tam = a[i];
//			max = a[i].soluongton;
//		}
//	}
//	
//	for(int i = 0; i < n; i++) {
//		if(max == a[i].soluongton) {
//			Xuat(a[i]);
//			cout << endl;
//		}
//	}
//}

void TimMAX(TREE t, int &max) {
	if(t == NULL) {
		return;
	}
	else {
		if(max < t->data.soluongton) {
			max = t->data.soluongton;
		}
		TimMAX(t->pLeft, max);
		TimMAX(t->pRight, max);
	}
}

void InTonKhoMIN(HANGHOA a[], int n) {
	HANGHOA tam = a[0];
	int min = a[0].soluongton;
	for(int i = 0; i < n; i++) {
		if(min > a[i].soluongton) {
			tam = a[i];
			min = a[i].soluongton;
		}
	}
	
	for(int i = 0; i < n; i++) {
		if(min == a[i].soluongton) {
			Xuat(a[i]);
			cout << endl;
		}
	}
}

void Menu(TREE &t, HANGHOA &hang) {
	int luachon;
	HANGHOA a[100];
	int n = 0;
	do {
		system("cls");
		cout << "\n========================QUAN LY HANG HOA========================\n";
		cout << "\n1. Nhap hang hoa";
		cout << "\n2. Xuat hang hoa";
		cout << "\n3. Tim kiem hang hoa co ma bat ki";
		cout << "\n4. Xuat ra cac hang hoa giam dan theo so luong ton";
		cout << "\n5. Tinh tong luong ton kho dang quan ly";
		cout << "\n6. In danh sach cac hang hoa co luong ton kho lon nhat";
		cout << "\n7. In danh sach cac hang hoa co luong ton kho nho nhat";
		cout << "\n0. Thoat";
		cout << "\n==============================HET===============================\n";
		cout << "\nNhap lua chon: ";
		cin >> luachon;
		switch(luachon) {
			case 1: {
				cout << "\n\t Nhap thong tin hang hoa";
				Nhap(hang);
				ThemNode(t, hang);
				break;
			}
			case 2: {
				int chon;
				while (true) {
					system("cls");
					cout << "\n\tXuat hang hoa theo 6 cach duyet";
					cout << "\n1. Xuat cay NLR";
					cout << "\n2. Xuat cay NRL";
					cout << "\n3. Xuat cay LNR";
					cout << "\n4. Xuat cay RNL";
					cout << "\n5. Xuat cay LRN";
					cout << "\n6. Xuat cay RLN";
					cout << "\n0. Tro lai";
					cout << "\nMoi ban chon: ";
					cin >> chon;
					if(chon == 0) {
						break;
					}
					else if (chon == 1)
					{ 
						cout << "\nXuat cay NODE LEFT RIGHT";
						NLR(t);
						system("pause");
					}
					else if (chon == 2)
					{
						cout << "\nXuat cay NODE RIGHT LEFT";
						NRL(t);
						system("pause");
					}
					else if (chon == 3)
					{
						cout << "\nXuat cay LEFT NODE RIGHT";
						LNR(t);
						system("pause");
					}
					else if (chon == 4)
					{
						cout << "\nXuat cay RIGHT NODE LEFT";
						RNL(t);
						system("pause");
					}
					else if (chon == 5)
					{
						cout << "\nXuat cay LEFT RIGHT NODE";
						LRN(t);
						system("pause");
					}
					else if (chon == 6)
					{
						cout << "\nXuat cay RIGHT LEFT NODE";
						RLN(t);
						system("pause");
					}
					else {
						cout << "Lua chon sai. Moi chon lai!";
						system("pause");
					}
				}
				break;
			}
			case 3: {
				int x;
				cout << "\n\tTim kiem hang hoa co ma bat ki";
				cout << "\nNhap ma can tim kiem: ";
				cin >> x;
				TimKiem(t, x);
				system("pause");
				break;
			}
			case 4: {
				n = 0;
				cout << "\n\tXuat ra cac hang hoa giam dan theo so luong ton";
				ChoVaoMang(t, a, n);
				SapXepMang(t, a, n);
				system("pause");
				break;
			}
			case 5: {
				cout << "\n\tTong luong ton kho dang quan ly: ";  
//				ChoVaoMang(t, a, n);
				TongTonKho(a, n);
				system("pause");
				break;
			}
			case 6: {
				cout << "\n\tDanh sach cac hang hoa co luong ton kho lon nhat";
//				ChoVaoMang(t, a, n);
				InTonKhoMAX(a, n);
				system("pause");
				break;
			}
			case 7: {
				cout << "\n\tDanh sach cac hang hoa co luong ton kho nho nhat";
//				ChoVaoMang(t, a, n);
				InTonKhoMIN(a, n);
				system("pause");
				break;
			}
			case 0: {
				break;
			}
			default: {
				cout << "\nLua chon khong hop le!. Moi chon lai";
				system("pause");
				break;
			}
		}
	} while (luachon != 0);
	
}
int main() {
	TREE t;
	HANGHOA hang;
	KhoiTaoCay(t);
	Menu(t, hang);
	return 0;
}

