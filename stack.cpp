#include<iostream>
using namespace std;

// Nh?p c�c s? nguy�n theo co ch? stack c�i d?t b?ng danh s�ch li�n k?t
// khai b�o c?u tr�c 1 c�i node
struct node
{
	int data;
	node *pNext;
};
typedef struct node NODE;

// khai b�o c?u tr�c 1 c�i STACK
struct STACK
{
	NODE *pTop; // con tr? qu?n l� d?u stack
};


// h�m kh?i t?o 1 c�i node 
NODE *KhoiTaoNode(int ps)
{
	NODE *p = new NODE; // Kh?i t?o v�ng nh? cho c�i node chu?n b? th�m v�o danh s�ch
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = ps; // truy?n gi� tr? ps v�o cho c�i data c?a c�i node p
	p->pNext = NULL; // chua li�n k?t d?n th?ng n�o h?t
	return p;
}

// h�m kh?i t?o c�i stack
void Init(STACK &s)
{
	s.pTop = NULL;
}

// ki?m tra xem stack c� r?ng hay kh�ng
bool IsEmpty(STACK s)
{
	if (s.pTop == NULL)
	{
		return true; // stack chua luu ph?n t? n�o
	}
	return false; // stack c� ph?n t?
}

// h�m th�m 1 c�i node p v�o d?u stack
bool Push(STACK &s, NODE *p)
{
	// n?u danh s�ch r?ng
	if(IsEmpty(s) == true)
	{
		s.pTop = p;
	}
	else
	{
		p->pNext = s.pTop; // cho node p c?n th�m li�n k?t d?n pTop
		s.pTop = p; // c?p nh?t l?i pTop ch�nh l� node v?a th�m v�o
	}
	return true;
}

// h�m l?y ph?n t? d?u STACK - sau d� x�a di lu�n
bool Pop(STACK &s, int &x)
{
	if (IsEmpty(s) == true)
	{
		return false;
	}
	else
	{
		NODE *tam = s.pTop;
		x = s.pTop->data; // luu l?i d? li?u b�n trong node d?u danh s�ch tru?c khi x�a
		s.pTop = s.pTop->pNext;
		delete tam;
	}
	return true;
}

// h�m l?y ph?n t? d?u stack ra xem
bool Top(STACK s, int &x)
{
	if (IsEmpty(s) == true)
	{
		return false;
	}
	x = s.pTop->data;
	return true;
}


// thi?t k? menu thao t�c tr�n danh s�ch li�n k?t don
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
