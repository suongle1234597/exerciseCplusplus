#include<iostream>
using namespace std;
#include<fstream>
#include "PhanSo.h"

// khai b�o c?u tr�c ph�n s?
struct phanso
{
	int tuso;
	int mauso;
};
typedef struct phanso PHANSO;
// h�m d?c 1 ph�n s?
void Doc_Phan_So(PHANSO &ps, ifstream &filein)
{
	filein >> ps.tuso;
	filein.seekg(1, 1);
	filein >> ps.mauso;
}
// h�m xu?t ph�n s?
void Xuat_Phan_So(PHANSO ps)
{
	cout << ps.tuso << "/" << ps.mauso;
}

// khai b�o c?u tr�c danh s�ch ph�n s?
struct danhsach
{
	PHANSO ds_ps[100];
	int n;
};
typedef struct danhsach DANHSACH;

// h�m d?c danh s�ch ph�n s?
void Doc_Danh_Sach_Phan_So(DANHSACH &ds, ifstream &filein)
{ 
	for (int i = 0; i < ds.n; i++)
	{
		Doc_Phan_So(ds.ds_ps[i], filein);
	}
}

// h�m xu?t danh s�ch ph�n s?
void Xuat_Danh_Sach_Phan_So(DANHSACH ds)
{
	for (int i = 0; i < ds.n; i++)
	{
		Xuat_Phan_So(ds.ds_ps[i]);
		cout << endl;
	}
}

// h�m t�m UCLN
int Tim_UCLN(int a, int b)
{
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else if (a < b)
		{
			b = b - a;
		}
	}
	return a;
}

// h�m r�t g?n 1 ph�n s?
void Rut_Gon_Phan_So(PHANSO &ps)
{
	int ucln = Tim_UCLN(ps.tuso, ps.mauso);
	ps.tuso = ps.tuso / ucln;
	ps.mauso = ps.mauso / ucln;
}

// h�m r�t g?n nhi?u ph�n s? 
void Rut_Gon_Danh_Sach_Phan_So(DANHSACH &ds)
{
	for (int i = 0; i < ds.n; i++)
	{
		Rut_Gon_Phan_So(ds.ds_ps[i]);
	}
}
// h�m luu danh s�ch ph�n s? sau khi rut gon v�o file RUTGONPHANSO.TXT
void Ghi_File_Phan_So_Rut_Gon(DANHSACH ds, ofstream &fileout)
{
	fileout << ds.n << endl;
	for (int i = 0; i < ds.n; i++)
	{
		fileout << ds.ds_ps[i].tuso << "/" << ds.ds_ps[i].mauso << endl;
	}
}
int main()
{
	ifstream filein;
	DANHSACH ds;
	filein.open("INPUT.TXT", ios_base::in);
	if (filein.fail() == true)
	{
		cout << "\nFile khong ton tai";
		system("pause");
		return 0;
	}
	filein >> ds.n;
	Doc_Danh_Sach_Phan_So(ds, filein);
	cout << "\n\n\t\t DANH SACH PHAN SO\n";
	Xuat_Danh_Sach_Phan_So(ds);

	ofstream fileout;
	fileout.open("RUTGONPHANSO.TXT", ios_base::out);
	Rut_Gon_Danh_Sach_Phan_So(ds);
	Ghi_File_Phan_So_Rut_Gon(ds, fileout);
	filein.close();
	return 0;
}
