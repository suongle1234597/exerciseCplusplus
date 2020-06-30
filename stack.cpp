#include<iostream>
using namespace std;

// Nh?p các s? nguyên theo co ch? stack cài d?t b?ng danh sách liên k?t
// khai báo c?u trúc 1 cái node
struct node
{
	int data;
	node *pNext;
};
typedef struct node NODE;

// khai báo c?u trúc 1 cái STACK
struct STACK
{
	NODE *pTop; // con tr? qu?n lý d?u stack
};


// hàm kh?i t?o 1 cái node 
NODE *KhoiTaoNode(int ps)
{
	NODE *p = new NODE; // Kh?i t?o vùng nh? cho cái node chu?n b? thêm vào danh sách
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = ps; // truy?n giá tr? ps vào cho cái data c?a cái node p
	p->pNext = NULL; // chua liên k?t d?n th?ng nào h?t
	return p;
}

// hàm kh?i t?o cái stack
void Init(STACK &s)
{
	s.pTop = NULL;
}

// ki?m tra xem stack có r?ng hay không
bool IsEmpty(STACK s)
{
	if (s.pTop == NULL)
	{
		return true; // stack chua luu ph?n t? nào
	}
	return false; // stack có ph?n t?
}

// hàm thêm 1 cái node p vào d?u stack
bool Push(STACK &s, NODE *p)
{
	// n?u danh sách r?ng
	if(IsEmpty(s) == true)
	{
		s.pTop = p;
	}
	else
	{
		p->pNext = s.pTop; // cho node p c?n thêm liên k?t d?n pTop
		s.pTop = p; // c?p nh?t l?i pTop chính là node v?a thêm vào
	}
	return true;
}

// hàm l?y ph?n t? d?u STACK - sau dó xóa di luôn
bool Pop(STACK &s, int &x)
{
	if (IsEmpty(s) == true)
	{
		return false;
	}
	else
	{
		NODE *tam = s.pTop;
		x = s.pTop->data; // luu l?i d? li?u bên trong node d?u danh sách tru?c khi xóa
		s.pTop = s.pTop->pNext;
		delete tam;
	}
	return true;
}

// hàm l?y ph?n t? d?u stack ra xem
bool Top(STACK s, int &x)
{
	if (IsEmpty(s) == true)
	{
		return false;
	}
	x = s.pTop->data;
	return true;
}


// thi?t k? menu thao tác trên danh sách liên k?t don
void Menu(STACK &s)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ======== QUAN LY STACK ========\n";
		cout << "\n1. Nhap phan tu cho STACK";
		cout << "\n2. Xuat STACK";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t =================== END  ==================\n";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			int x;
			cout << "\nNhap so nguyen: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			Push(s, p);
		}
		else if (luachon == 2)
		{
			while (IsEmpty(s) == false)
			{
				int x;
				Pop(s, x);
				cout << x << "  ";
			}
			system("pause");
		}
		else
		{
			break;
		}
	}
}


int main() {
	STACK s;
	Init(s);
	Menu(s);
	system("pause");
	return 0;
}
