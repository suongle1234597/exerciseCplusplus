#include<iostream>
#include<math.h>
using namespace std;

struct node
{
	int data;
	node *pLeft;
	node *pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

void KhoiTaoCay(TREE &t)
{
	t = NULL;
}

void ThemNode(TREE &t, int x)
{
	if (t == NULL)
	{
		NODE *p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p; 
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

void XuatPTNutLa(TREE t, int &dem) {
	if(t == NULL) {
		return;
	}
	else {
		if(t->pLeft == NULL && t->pRight == NULL) {
			//cout << t->data << " ";
			dem++;
		}
		XuatPTNutLa(t->pLeft, dem);
		XuatPTNutLa(t->pRight, dem);
	}
}

void TimNodeCha (TREE t, int x)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (x == t->pRight->data)
		{
			cout << "\nNode cha la: " << t->data;
		}
		else if(x == t->pLeft->data)
		{
			cout << "\nNode cha la: " << t->data;
		}
		
		TimNodeCha(t->pLeft, x);
		TimNodeCha(t->pRight, x);
	}
}

void TimNodeCon(TREE t, int x)
{
		if (t == NULL)
	{
		return;
	}
	else
	{
		if (x == t->data)
		{
			if(t->pLeft != NULL) cout << "Nut con trai la: " << t->pLeft->data;
			else if(t->pRight != NULL) cout << "Nut con phai la: " << t->pRight->data;
			else if(t->pLeft != NULL && t->pRight != NULL) 
			{
				cout << "Nut con trai la: " << t->pLeft->data;
				cout << "Nut con phai la: " << t->pRight->data;
			} 
			else
			{
				cout << "Node vua them khong co node con!";
			}
		}
		
		TimNodeCon(t->pLeft, x);
		TimNodeCon(t->pRight, x);
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

void RNL(TREE t)
{
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

void Menu(TREE &t)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ======== CHUONG TRINH CAY NHI PHAN TIM KIEM ========\n";
		cout << "\n1. Nhap chuoi so nguyen cho cay nhi phan tim kiem";
		cout << "\n2. Xuat so luong cac phan tu la nut la";
		cout << "\n3. Nhap vao so nguyen. Xac dinh node cha va node con cua no";
		cout << "\n4. Tim chieu cao cua cay";
		cout << "\n5. Duyet cay theo thu tu RNL";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t =================== END  ==================\n";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon == 0)
		{
			break;
		}
		else if (luachon == 1)
		{
			int x;
			cout << "\nNhap phan tu cho chuoi so: ";
			cin >> x;
			ThemNode(t, x);
		}
		else if (luachon == 2)
		{
			int dem = 0;
			XuatPTNutLa(t, dem);
			cout << "\nSo luong cac phan tu nut la la: " << dem;
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			cout << "\nNhap mot so nguyen: ";
			cin >> x;
			ThemNode(t, x); 
			//TimNodeCha(t, x);
			//TimNodeCon(t, x);
			system("pause");
		}
		else if (luachon == 4)
		{
			cout << "\nChieu cao cua cay la: " << TimChieuCao(t);
			system("pause");
		}
		else if (luachon == 5)
		{
			cout << "\nDuyet cay theo thu tu RNL: ";
			RNL(t);
			system("pause");
		}
		else 
		{
			cout << "Lua chon nay khong dung!";
			system("pause");
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
