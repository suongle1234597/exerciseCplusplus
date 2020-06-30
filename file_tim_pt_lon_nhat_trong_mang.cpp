/* Doc cac so nguyen tu file INPUT.TXT biet
+ Dong dau tien la 1 so nguyen bieu dien so luong cac so nguyen can doc
+ Dong thu 2 la 1 day cac so nguyen can doc
VD: INPUT.TXT
5
1 49 7 878 9656
=== Yeu cau ===
- Tim phan tu lon nhat trong mang so nguyen do va ghi vao file KETQUA.TXT. */

#include<iostream>
using namespace std;
#include<fstream>

// hàm d?c d? li?u t? file
void Doc_File(int a[], int n, ifstream &filein)
{
	for (int i = 0; i < n; i++)
	{
		filein >> a[i];
	}
}
// hàm xu?t m?ng
void Xuat_Mang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
}
int main()
{
	int a[100];
	int n = 0;
	ifstream filein;
	//filein.open("C:\\Users\\THIEN TAM\\Desktop\\INPUT.TXT",ios::in);
	filein.open("INPUT.TXT", ios::in);
	if (filein.fail() == true)
	{
		cout << "\nMo file khong thanh cong";
		return 0;
	}
	
	/* CHO TRU?C S? LU?NG PH?N T? C?A FILE */ 
	filein >> n;
	Doc_File(a, n, filein);
	cout << "\n\t XUAT MANG\n";
	Xuat_Mang(a, n);
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	ofstream fileout;
	fileout.open("KETQUA.TXT", ios::out);
	fileout << max;
	fileout.close();


	/* KHÔNG CHO TRU?C S? LU?NG PH?N T? C?A FILE */
	/*int i = 0;
	while (filein.eof() == false)
	{
		filein >> a[i];
		i++;
		n++;
	}
	cout << "\n\t XUAT MANG\n";
	Xuat_Mang(a, n);*/

	filein.close();
	return 0;
}
