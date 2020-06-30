// MANG DONG

#include <iostream>
#include <stdlib.h>
#define MAX 100
using namespace std;

void NhapMang (int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " Nhap phan tu a[" << i << "] : ";
		cin >> a[i];
	}
}

void XuatMang (int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

void Them (int *a, int &n, int vt, int x)
{
	for (int i = n - 1; i >= vt; i--)
	{
		a[i + 1] = a[i];
	}
	a[vt] = x;
	n++;
}

void Xoa (int *a, int &n, int vt)
{
	for (int i = vt + 1; i < n; i++)
	{
		a[i - 1] = a[i];
	}
	n--; 
}

// xay dung lai ham realloc ben c
void Cap_Phat_Lai_Vung_Nho (int *&a, int sl_moi, int sl_cu)
{
	//B1: Do het tat ca cac pt cua mang ban dau sang mang tam
	int *tam = new int [sl_cu];
	for (int i = 0; i < sl_cu; i++) 
	{
		tam[i] = a[i]; // gan tat ca cac phan tu a sang mang tam giu gium 
	}
	//B2: Tao vung nho moi
	delete[] a; // giai phong vung nho cu khong dung nua
	a = new int[sl_moi];
	//B3: Do het tat ca nhung phan tu ma chua trong mang tam sang lai mang a
	for (int i = 0; i < sl_cu; i++)
	{
		a[i] = tam[i]; // gan tung phan tu mang tam sang mang a
	}
	delete[] tam;
}

int main ()
{
	int *a; // khai bao con tro de quan ly cai mang
	int n;
	do
	{
		cout << "\n Nhap so luong phan tu can dung: ";
		cin >> n;
		if (n <= 0)
		{
			cout << "\n So luong phan tu khong hop le!";
		}
	} while (n <= 0);
	
	a = new int [n]; // cap phat mang dong co n phan tu

	cout << "\n\t NHAP MANG\n";
	NhapMang (a, n);
	cout << "\n\t XUAT MANG\n";
	XuatMang (a, n);
//    // truoc khi them se noi rong ra 1 o
//	  Cap_Phat_Lai_Vung_Nho (a, n + 1, n);
//    Them (a, n, 2, 10);
    Xoa (a, n, 3);
    // sau khi xoa thi thu hep vung nho lai 1 o
    Cap_Phat_Lai_Vung_Nho (a, n, n);
    cout << "\n\t MANG SAU KHI XOA\n";
    XuatMang (a, n);
	
	// dung malloc de cap phat vung nho cho con tro
//	a = (int *) malloc (n * sizeof(int *));
	
	// dung calloc de cap phat vung nho cho con tro
//	a = (int *) calloc (n,  sizeof(int *));

    // dung realloc de cap phat vung nho cho con tro
//	a = (int *) realloc (NULL, n * sizeof(int *));
//	cout << "\n\t NHAP MANG\n";
//	NhapMang (a, n);
//	cout << "\n\t XUAT MANG\n";
//	XuatMang (a, n);
//	// truoc khi them mot phan tu vao mang dong phai noi rong ra 1 o
////	a = (int *) realloc (a, (n + 1) * sizeof(int *));
////	Them (a, n, 2, 10);
//    a = (int *) realloc (a, n * sizeof (int *));
//    Xoa (a, n, 2);
//	cout << "\n\t XUAT MANG\n";
//	XuatMang (a, n);
//	free (a); // giai phong mang dong <=> giai phong con tro
	return 0;
}
