#include<iostream>
using namespace std;
#include<math.h>

// ============== Kh?i t?o c?u trúc cây nh? phân tìm ki?m các s? nguyên ==============

// khai báo c?u trúc 1 cái node
struct node
{
	int data;
	node *pLeft;
	node *pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

// hàm kh?i t?o 1 cái cây nh? phân tìm ki?m
void KhoiTaoCay(TREE &t)
{
	t = NULL;
}

// hàm thêm 1 cái node vào cây nh? phân tìm ki?m
void ThemNode(TREE &t, int x)
{
	// cây dang r?ng
	if (t == NULL)
	{
		NODE *p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p; // th?ng thêm vào cung chính là node g?c
	}
	else
	{
		if (t->data > x)
		{
			ThemNode(t->pLeft, x);
		}
		else if (t->data < x)
		{
			ThemNode(t->pRight, x);
		}
	}
}


// hàm duy?t cây theo NLR
void NLR(TREE t)
{
	// n?u cây r?ng
	if (t == NULL)
	{
		return;
	}
	else
	{
		cout << t->data << "  ";
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}

// hàm duy?t cây theo NRL
void NRL(TREE t)
{
	// n?u cây r?ng
	if (t == NULL)
	{
		return;
	}
	else
	{
		cout << t->data << "  ";
		NRL(t->pRight);
		NRL(t->pLeft);
	}
}

// hàm duy?t cây theo LNR
void LNR(TREE t)
{
	// n?u cây r?ng
	if (t == NULL)
	{
		return;
	}
	else
	{
		LNR(t->pLeft);
		cout << t->data << "  ";
		LNR(t->pRight);
	}
}

// hàm duy?t cây theo RNL
void RNL(TREE t)
{
	// n?u cây r?ng
	if (t == NULL)
	{
		return;
	}
	else
	{
		RNL(t->pRight);
		cout << t->data << "  ";
		RNL(t->pLeft);
	}
}

// hàm duy?t cây theo LRN
void LRN(TREE t)
{
	// n?u cây r?ng
	if (t == NULL)
	{
		return;
	}
	else
	{
		LRN(t->pLeft);		
		LRN(t->pRight);
		cout << t->data << "  ";
	}
}

// hàm duy?t cây theo RLN
void RLN(TREE t)
{
	// n?u cây r?ng
	if (t == NULL)
	{
		return;
	}
	else
	{
		RLN(t->pRight);
		RLN(t->pLeft);
		cout << t->data << "  ";
	}
}

// hàm ki?m tra s? chính phuong
bool Kiem_Tra_So_Chinh_Phuong(int x)
{
	int y = sqrt(x);
	return y * y == x ? true : false;
}

// hàm xu?t các ph?n t? là s? chính phuong
void Xuat_SCP(TREE t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		// chính là ph?n t? node
		if (Kiem_Tra_So_Chinh_Phuong(t->data) == true)
		{
			cout << t->data << "   ";
		}
		Xuat_SCP(t->pLeft);
		Xuat_SCP(t->pRight);
	}
}

void TimMAX(TREE t, int &max) {
	if(t == NULL) {
		return;
	}
	else {
		if(max < t->data) {
			max = t->data;
		}
		TimMAX(t->pLeft, max);
		TimMAX(t->pRight, max);
	}
}

//int TimMAX(TREE t) {
//	if(t == NULL) {
//		return t->data;
//	}
//	else {
//		if()
//	}
//}

void XuatPTNutLa(TREE t) {
	if(t == NULL) {
		return;
	}
	else {
		if(t->pLeft == NULL && t->pRight == NULL) {
			cout << t->data << " ";
		}
		XuatPTNutLa(t->pLeft);
		XuatPTNutLa(t->pRight);
	}
}

void XuatPTNut1Con(TREE t) {
	if(t == NULL) {
		return;
	}
	else {
		if((t->pLeft == NULL && t->pRight != NULL) || (t->pLeft != NULL && t->pRight == NULL)) {
			cout << t->data << " ";
		}
		XuatPTNut1Con(t->pLeft);
		XuatPTNut1Con(t->pRight);
	}
}

void XuatPTNut2Con(TREE t) {
	if(t == NULL) {
		return;
	}
	else {
		if(t->pLeft != NULL && t->pRight != NULL) {
			cout << t->data << " ";
		}
		XuatPTNut2Con(t->pLeft);
		XuatPTNut2Con(t->pRight);
	}
}

void TimNodeTheMang(TREE &x, TREE &y) {
	if(y->pLeft != NULL) {
		TimNodeTheMang(x, y->pLeft);
	}
	else {
		x->data = y->data;
		x = y;
		y = y->pRight;
	}
}

void TimNodeTheMangLeft(TREE &x, TREE &y) {
	if(y->pRight != NULL) {
		TimNodeTheMang(x, y->pRight);
	}
	else {
		x->data = y->data;
		x = y;
		y = y->pLeft;
	}
}

void XoaNode(TREE &t, int x) {
	if(x < t->data) {
		XoaNode(t->pLeft, x);
	}
	else if(x > t->data) {
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
//		if(t->pLeft != NULL && t->pRight != NULL) {
//			TREE y, z;
//			if(t->pLeft->pRight->pLeft == NULL) {
//				z = t->pLeft;
//				y = t->pLeft->pRight;
//				y = y->pRight;
//			}
//			else if(t->pLeft->pRight->pRight == NULL) {
//				z = t->pLeft;
//				y = t->pLeft->pRight;
//				y = y->pLeft;
//			}
//			else if(t->pRight->pLeft->pLeft == NULL) {
//				z = t->pRight;
//				y = t->pRight->pLeft;
//				y = y->pRight;
//			}
//			else if(t->pRight->pLeft->pRight == NULL) {
//				z = t->pRight;
//				y = t->pRight->pLeft;
//				y = y->pLeft;
//			}
//			t = y;
//		}
		else {
//			TimNodeTheMang(x, t->pRight); // tim node trai nhat cua cay con phai
			TimNodeTheMangLeft(x, t->pLeft);
		}
		delete x;
	}
}

int TimChieuCao(TREE t) {
	if(t == NULL) {
		return 0;
	}
	else {
		int x = TimChieuCao(t->pLeft);
		int y = TimChieuCao(t->pRight);
		if(x > y) {
			return x + 1;
		}
		else {
			return y + 1;
		}
	}
}

 // thi?t k? menu thao tác trên TREE
void Menu(TREE &t)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ======== QUAN LY TREE ========\n";
		cout << "\n1. Nhap phan tu cho cay nhi phan tim kiem";
		cout << "\n2. Xuat cay NLR";
		cout << "\n3. Xuat cay NRL";
		cout << "\n4. Xuat cay LNR";
		cout << "\n5. Xuat cay RNL";
		cout << "\n6. Xuat cay LRN";
		cout << "\n7. Xuat cay RLN";
		cout << "\n8. Xuat cac so chinh phuong";
		cout << "\n9. Tim max";
		cout << "\n10. Tim min;";
		cout << "\n11. Xuat cac phan tu la nut la";
		cout << "\n12. Xuat cac phan tu la nut 1 con";
		cout << "\n13. Xuat cac phan tu la nut 2 con";
		cout << "\n14. Xoa phan tu bat ki";
		cout << "\n15. Tim chieu cao cua cay";
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
			ThemNode(t, x);
		}
		else if (luachon == 2)
		{
			NLR(t);
			system("pause");
		}
		else if (luachon == 3)
		{
			NRL(t);
			system("pause");
		}
		else if (luachon == 4)
		{
			LNR(t);
			system("pause");
		}
		else if (luachon == 5)
		{
			RNL(t);
			system("pause");
		}
		else if (luachon == 6)
		{
			LRN(t);
			system("pause");
		}
		else if (luachon == 7)
		{
			RLN(t);
			system("pause");
		}
		else if (luachon == 8)
		{
			cout << "\n\n\t\t CAC SO CHINH PHUONG\n";
			Xuat_SCP(t);
			system("pause");
		}
		else if(luachon == 9) {
			int max = t->data;
			TimMAX(t, max);
			cout << max;
			system("pause");
		}
		else if(luachon == 10) {
			
		}
		else if(luachon == 11) {
			cout << "\nCac phan tu la nut la la: ";
			XuatPTNutLa(t);
			system("pause");
		}
		else if(luachon == 12) {
			cout << "\nCac phan tu la nut 1 con la: ";
			XuatPTNut1Con(t);
			system("pause");
		}
		else if(luachon == 13) {
			cout << "\nCac phan tu la nut 2 con la: ";
			XuatPTNut2Con(t);
			system("pause");
		}
		else if(luachon == 14) {
			int x;
			cout << "\n\tXoa phan tu bat ky";
			cout << "\nNhap phan tu can xoa: ";
			cin >> x;
			XoaNode(t, x);
			cout << "\n\tSau khi xoa: ";
			NLR(t);
			system("pause");
		}
		else if(luachon == 15) {
			int x;
			cout << "\n\tChieu cao cua cay la: " << TimChieuCao(t) << endl;
			system("pause");
		}
		else 
		{
			break;
		}
	}
}

int main()
{
	TREE t;
	KhoiTaoCay(t);
	Menu(t);

	system("pause");
	return 0;
}
