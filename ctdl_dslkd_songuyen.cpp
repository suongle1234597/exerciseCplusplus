#include <iostream>
using namespace std;

// nhap danh sach lien ket don cac so nguyen
// khai bao mot cai node

struct node {
	int data; // du lieu cua 1 cai node trong danh sach lien ket don
	node *pNext; // con tro dung de lien ket voi cai node khac
};
typedef struct node NODE;
 
// ham khoi tao 1 cai node
NODE *KhoiTaoNode(int x) {
	NODE *p = new NODE;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat";
		return NULL;
	}
	p->data = x; // th�m gi� tr? x v�o data c?a c�i node
	p->pNext = NULL; // node p chua c� k?t n?i v?i th?ng n�o h?t
	return p;
}

// h�m th�m 1 c�i node p v�o d?u danh s�ch
void ThemDau(NODE *&pHead, NODE *p)
{
	// danh s�ch r?ng
	if (pHead  == NULL)
	{
		pHead = p; // ph?n t? p c?n th�m cung ch�nh l� pHead; 
	}
	else
	{
		p->pNext = pHead; // cho node p li�n k?t v?i node d?u danh s�ch
		pHead = p; // c?p nh?t l?i pHead ch�nh l� th?ng p v?a th�m v�o 
	}
}
// h�m xu?t danh s�ch li�n k?t don

// Them cuoi
void ThemCuoi(NODE *&pHead, NODE *p) {
	if(pHead == NULL) {
		pHead = p;
	}
	else {
//		k->pNext = p;
//		k = p;
	}
}

void Xuat_Danh_Sach(NODE *&pHead)
{
	for (NODE *k = pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << "  ";
	}
}

// h�m t�m max
int Tim_Max(NODE *pHead)
{
	int max = pHead->data;
	for (NODE *k = pHead->pNext; k != NULL; k = k->pNext)
	{
		if (k->data > max)
		{
			max = k->data;
		}
	}
	return max;
}

void XoaPT(NODE *&pHead, int x) 
{
	NODE *a, *n;
	for (NODE *k = pHead->pNext; k != NULL; k = k->pNext)
	{
		if (k->data == x)
		{
			a = k;
			n = k->pNext;
			k = k->pNext;
			delete a;
		}
		else {
			n = k;
		}
	}
	
	for (NODE *k = pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << "  ";
	}
}

void XoaPTTrung(NODE *&pHead)
{
	
}

// Giai phong
void GiaiPhong(NODE *&pHead) {
	NODE *k;
	while(pHead != NULL) {
		k = pHead;
		pHead = pHead->pNext;
		delete k;
	}
}

// thi?t k? menu
void Menu(NODE *pHead, NODE *k)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ========== QUAN LY DANH SACH ==========\n";
		cout << "\n1. Nhap phan tu";
		cout << "\n2. Xuat danh sach";
		cout << "\n3. Tim max";
		cout << "\n4. Xoa phan tu bi trung";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t ================= END =================\n";

		int luachon;

		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 0)
		{
			break;
		}
		else if (luachon == 1)
		{
			// BU?C 1: kh?i t?o ra 1 c�i node d? th�m v�o danh s�ch
			int x;
			cout << "\nNhap phan tu can them: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			// BU?C 2: g?i l?i h�m th�m d? th�m node v�o danh s�ch
			ThemDau(pHead, p);
			
//			ThemCuoi(pHead, k, p);
		}
		else if (luachon == 2)
		{
			cout << "\n\n\t\t DANH SACH LIEN KET DON CAC SO NGUYEN\n";
			Xuat_Danh_Sach(pHead);
			system("pause");

		}
		else if (luachon == 3)
		{
			cout << "\n\n\t\t PHAN TU MAX LIEN KET DON CAC SO NGUYEN\n" << Tim_Max(pHead);
			system("pause");
		}
		else if(luachon == 4)
		{
			cout << "\n\t Xoa phan tu bi trung";
			cout << "\nDanh sach truoc khi xoa: ";
			Xuat_Danh_Sach(pHead);
			cout << "\nDanh sach sau khi xoa: ";
			XoaPT(pHead, 2);
//			Xuat_Danh_Sach(pHead);
			system("pause");
		}
	}
	GiaiPhong(pHead);
//	Xuat_Danh_Sach(pHead); //kiem tra xem giai phong duoc chua
}
int main()
{

	NODE *pHead = NULL; // con tr? d? qu?n l� d?u danh s�ch <=> danh s�ch dang r?ng
	NODE *k = NULL;
	Menu(pHead, k);

	system("pause");
	return 0;
}
