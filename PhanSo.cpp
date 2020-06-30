#include"PhanSo.h"


// hàm đọc 1 phân số
void Doc_Phan_So(PHANSO &ps, ifstream &filein)
{
	filein >> ps.tuso;
	filein.seekg(1, ios_base::cur);
	filein >> ps.mauso;
}
// hàm xuất phân số
void Xuat_Phan_So(PHANSO ps)
{
	cout << ps.tuso << "/" << ps.mauso;
}


// hàm tìm UCLN
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

// hàm rút gọn 1 phân số
void Rut_Gon_Phan_So(PHANSO &ps)
{
	int ucln = Tim_UCLN(ps.tuso, ps.mauso);
	ps.tuso = ps.tuso / ucln;
	ps.mauso = ps.mauso / ucln;
}
