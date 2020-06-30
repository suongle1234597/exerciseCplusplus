#include"DanhSachPhanSo.h"

int main()
{
	ifstream filein;
	DANHSACH ds;
	filein.open("C:\\Users\\DELL\\Desktop\\INPUT.TXT", ios_base::in);
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
