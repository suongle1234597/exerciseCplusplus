#include <iostream>
using namespace std;

struct node {
	int data;
	node *pNext;
};
typedef struct node NODE;

struct STACK {
	NODE *pTop;
};

NODE *KhoiTaoNode (int ps){
	NODE *p = new NODE;
	if(p == NULL) {
		cout << "Khong du bo nho de cap phat";
		return NULL;
	}
	p->data = ps;
	p->pNext = NULL;
	return p;
}

void Init(STACK &s) {
	s.pTop = NULL;
}

bool IsEmpty(STACK s)
{
	if (s.pTop == NULL)
	{
		return true;
	}
	return false;
}

bool Push(STACK &s, NODE *p) {
	if(IsEmpty(s) == true) {
		s.pTop = p;
	}
	else {
		p->pNext = s.pTop;
		s.pTop = p;
	}
	return true;
}

bool Pop(STACK &s, int &x) {
	if (IsEmpty(s) == true)
	{
		return false;
	}
	else
	{
		NODE *tam = s.pTop;
		x = s.pTop->data; 
		s.pTop = s.pTop->pNext;
		delete tam;
	}
	return true;
}

bool Top(STACK s, int &x)
{
	if (IsEmpty(s) == true)
	{
		return false;
	}
	x = s.pTop->data;
	return true;
}

bool PopThapLuc(STACK &s, char &t) {
	if (IsEmpty(s) == true)
	{
		return false;
	}
	else
	{
		NODE *tam = s.pTop;
		t = s.pTop->data; 
		s.pTop = s.pTop->pNext;
		delete tam;
	}
	return true;
}

void Menu (STACK &s) {
	int luachon;
	while(true) {
		system("cls");
		cout << "\n===================CHUYEN DOI HE SO===================\n";
		cout << "\n1. Chuyen he thap phan sang nhi phan";
		cout << "\n2. Chuyen he thap phan sang bat phan";
		cout << "\n3. Chuyen he thap phan sang thap luc phan";
		cout << "\n0. Thoat";
		cout << "\n=========================XONG=========================\n";
		cout << "\nNhap lua chon: "; cin >> luachon;
		if(luachon == 0) {
			break;
		}
		else if(luachon == 1) {
			int x, i;
			cout << "\nNhap co so he thap phan: "; 
			cin >> x;
			while(x > 0) {
				i = x % 2;
				x = x / 2;
				NODE *p = KhoiTaoNode(i);
				Push(s, p);
			}
			
			while (IsEmpty(s) == false)
			{
				int x;
				Pop(s, x);
				cout << x << "  ";
			}
			system("pause");
		}
		else if(luachon == 2) {
			int x, i;
			cout << "\nNhap co so he thap phan: "; 
			cin >> x;
			while(x > 0) {
				i = x % 8;
				x = x / 8;
				NODE *p = KhoiTaoNode(i);
				Push(s, p);
			}
			
			while(IsEmpty(s) == false) {
				int x;
				Pop(s, x);
				cout << x << " ";
			}
			system("pause");
		}
		else if(luachon == 3) {
			int x, i;
			
			char t;
			cout << "\nNhap co so he thap phan: "; 
			cin >> x;
			while(x > 0) {
				i = x % 16;
				x = x / 16; 
				if(i >= 0 && i <= 9) {
					int dem = 0;
					for(int k = 48; k <= 57; k++) {
						if(dem == i) {
							t = (char) k;
							break;
						}
						dem++;
					}
				}
				
				else {
					int dem1 = 10;
					for(int k = 65; k <= 70; k++) {
						if(dem1 == i) {
							t = (char) k;
							break;
						}
						dem1++;
					}
				}
 				
				NODE *p = KhoiTaoNode(t);
				Push(s, p);
			}
			
			while(IsEmpty(s) == false) {
				char x;
				PopThapLuc(s, x);
				cout << x << " ";
			}
			system("pause");
		}
		else {
			cout << "Lua chon khong phu hop. Moi nhap lai!";
			system("pause");
		}
	}
}

int main() {
	STACK s;
	Init(s);
	Menu(s);
	return 0;
}
