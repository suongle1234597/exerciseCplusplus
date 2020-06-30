#include<iostream>
using namespace std;
#include<math.h>

// ============== Kh?i t?o c?u tr�c c�y nh? ph�n t�m ki?m c�c s? nguy�n ==============

// khai b�o c?u tr�c 1 c�i node
struct node
{
	int key;
	int data;
	node *pLeft;
	node *pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

// h�m kh?i t?o 1 c�i c�y nh? ph�n t�m ki?m
void KhoiTaoCay(TREE &t)
{
	t = NULL;
}

// h�m th�m 1 c�i node v�o c�y nh? ph�n t�m ki?m
void ThemNode(TREE &t, int x, int a)
{
	// c�y dang r?ng
	if (t == NULL)
	{
		NODE *p = new NODE;
		p->key = x;
		p->data = a;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p; // th?ng th�m v�o cung ch�nh l� node g?c
	}
	else
	{
		if (t->key > x)
		{
			ThemNode(t->pLeft, x, a);
		}
		else if (t->key < x)
		{
			ThemNode(t->pRight, x, a);
		}
	}
}


// h�m duy?t c�y theo NLR
void NLR(TREE t)
{
	// n?u c�y r?ng
	if (t == NULL)
	{
		return;
	}
	else
	{
		cout << t->key << "  ";
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}

// h�m duy?t c�y theo NRL
void NRL(TREE t)
{
	// n?u c�y r?ng
	if (t == NULL)
	{
		return;
	}
	else
	{
		cout << t->key << "  ";
		NRL(t->pRight);
		NRL(t->pLeft);
	}
}

// h�m duy?t c�y theo LNR
void LNR(TREE t)
{
	// n?u c�y r?ng
	if (t == NULL)
	{
		return;
	}
	else
	{
		LNR(t->pLeft);
		cout << t->key << "  ";
		LNR(t->pRight);
	}
}

// h�m duy?t c�y theo RNL
void RNL(TREE t)
{
	// n?u c�y r?ng
	if (t == NULL)
	{
		return;
	}
	else
	{
		RNL(t->pRight);
		cout << t->key << "  ";
		RNL(t->pLeft);
	}
}

// h�m duy?t c�y theo LRN
void LRN(TREE t)
{
	// n?u c�y r?ng
	if (t == NULL)
	{
		return;
	}
	else
	{
		LRN(t->pLeft);		
		LRN(t->pRight);
		cout << t->key << "  ";
	}
}

// h�m duy?t c�y theo RLN
void RLN(TREE t)
{
	// n?u c�y r?ng
	if (t == NULL)
	{
		return;
	}
	else
	{
		RLN(t->pRight);
		RLN(t->pLeft);
		cout << t->key << "  ";
	}
}

void TimNodeTheMang(TREE &x, TREE &y) {
	if(y->pLeft != NULL) {
		TimNodeTheMang(x, y->pLeft);
	}
	else {
		x->key = y->key;
		x = y;
		y = y->pRight;
	}
}

void TimNodeTheMangLeft(TREE &x, TREE &y) {
	if(y->pRight != NULL) {
		TimNodeTheMang(x, y->pRight);
	}
	else {
		x->key = y->key;
		x = y;
		y = y->pLeft;
	}
}

void XoaNode(TREE &t, int x) {
	if(x < t->key) {
		XoaNode(t->pLeft, x);
	}
	else if(x > t->key) {
		XoaNode(t->pRight, x);
	}
	else {
		TREE x = t;
		if(t->pLeft == NULL) {
			t = t->pRight;
		}
		else if(t->pRight == NULL) {
			t = t->pLeft;
		}
		else {
			TimNodeTheMangLeft(x, t->pLeft);
		}
		delete x;
	}
}

int main()
{
	TREE t;
	KhoiTaoCay(t);
	int n;
	int key, data, x;
	cout << "\nNhap so luong so nguyen: "; cin >> n;
	
	for(int i = 0; i < n; i++) {
		cout << "\nNhap khoa: "; cin >> key;
		cout << "\nNhap so nguyen: "; cin >> data;
		ThemNode(t, key, data);
	}
	cout << "\nNhap x: "; cin >> x;
	NODE *p;
	p = t; // p la nut goc
	if(p == NULL) {
		cout << "\nCay rong!";
	}
	while(p != NULL) {
		if(p->data > x) p = p->pLeft;
		else if(p->data < x) p = p->pRight;
		else XoaNode(t, x);
	}
	NLR(t);
	system("pause");
	return 0;
} 
