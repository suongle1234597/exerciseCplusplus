#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

struct node {
	int data;
	node *pNext;
};
typedef struct node NODE;

struct STACK {
	NODE *pTop;
};

struct QUEUE {
	NODE *qTop;
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
	else {
		if(s.pTop != ')') {
			NODE *tam = s.pTop;
			x = s.pTop->data; 
			s.pTop = s.pTop->pNext;
			delete tam;
		}
		else {
			return false;
		}
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

// CAI DAT QUEUE	
void Init_Q(QUEUE &q) {
	q.qTop = NULL;
}

bool IsEmpty_Q(QUEUE q)
{
	if (q.qTop == NULL)
	{
		return true;
	}
	return false;
}

bool Push_Q(QUEUE &q, NODE *p) {
	if(IsEmpty_Q(q) == true) {
		q.qTop = p;
	}
	else {
		p->pNext = q.qTop;
		q.qTop = p;
	}
	return true;
}

bool Pop_Q(QUEUE &q, int &x) {
	if (IsEmpty_Q(q) == true)
	{
		return false;
	}
	else
	{
		NODE *tam = q.qTop;
		x = q.qTop->data; 
		q.qTop = q.qTop->pNext;
		delete tam;
	}
	return true;
}

bool Top_Q(QUEUE q, int &x)
{
	if (IsEmpty_Q(q) == true)
	{
		return false;
	}
	x = q.qTop->data;
	return true;
}

bool KiemTra (string str) {
	for(int i = 0; i < str.length() - 1; i++) {
		if(!((str[i] >= 40 && str[i] <= 43) || (str[i] <= 57 && str[i] >= 47) || str[i] == 45)) {
			cout << "\nNhap bieu thuc khong dung";
			return false;
		}
	}
	return true;
}

void ChoVaoSTACK(STACK &s, string &x) {
	if(x == '+' || x == '-') {
		NODE *p = KhoiTaoNode(x);
		Push(s, p);
		}
	}
}

void ChoVaoQUEUE(QUEUE &q, string &str) {
	for(int i = 0; i < str.length() - 1; i++) {
		
	}
}

void ChuyenThanhBTHauTo (STACK &s, QUEUE &q, string &str) {
	for(int i = 0; i < str.length() - 1; i++) {
		if(str[i] == '(') { // cho vao stack
			NODE *p = new KhoiTaoNode(str[i]);
			Push(s, p);
		}
		else if (str[i] == ')') {
			Pop(s, x);
		}
		else { // cho vao queue
			
		}
	}
}


void Menu(STACK &s, QUEUE &q) {
	string x;
	cout << "\n======================KY PHAP BA LAN======================\n";
	do {
		cout << "Nhap bieu thuc: ";
		getline(cin, x);
		if(KiemTra(x) == false) {
			cout << "\nMoi nhap lai: ";
			getline(cin, x);
		}
	} while(KiemTra(x) == false);
	
	
}
 
int main() {
	STACK s;
	Init(s);
	QUEUE q;
	Init_Q(q);
	Menu (s, q);
	return 0;
}
