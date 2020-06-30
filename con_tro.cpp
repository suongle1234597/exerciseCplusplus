// Con tro

#include <iostream>
#include <stdlib.h> // dung thu vien nay cap phat bo nho cho con tro
using namespace std;
/* Bien co 2 thanh phan:
+ Dia chi - phan biet giua cac bien
+ Vung nho: chua gia tri
   Bien con tro co 3 tp:
+ Dia chi - phan biet giua cac bien
+ Vung nho: chua gia tri
+ Mien gia tri: dia chi cua bien con tro se tro den
Do lon cua con tro 32bit: 4 byte - 64bit: 8 byte  */

int main ()
{
	
//	int a = 10;
//	int *b; // khai bao bien CON TRO
//	b = &a; // cho con tro b tro den bien a (&a lay dia chi cua bien a) 
//	
//	cout << " \nGia tri cua bien a: " << a; 
//	cout << " \nDia chi cua bien a: " << &a;
//	cout << " \nGia tri con tro b: " << *b;
//	cout << " \nDia chi con tro b: " << &b;
//	cout << " \nMien gia tri cua con tro b: " << b; 
    
//	  void *b; // khai bao con tro VO KIEU
//    float a = 7;
//    b = &a;
//    cout << " Gia tri cua con tro b: " << *(float*)b;

// CAP PHAT VUNG NHO CHO CON TRO (heap segment) - cu phap cua c: dung 3 ham de cap phat
    // DUNG HAM MALLOC
//	  int *a; // chua he co vung nho de chua gia tri
//    a = (int *)malloc(sizeof(int *)); // sizeof (int *) do lon cua con tro tuy may
//    *a = 10;
//    cout << " Gia tri cua con tro a: " << *a;
    
    // DUNG HAM CALLOC
//	  int *a; // chua he co vung nho de chua gia tri
//    a = (int *)calloc(1, sizeof(int *)); // cap phat xong cho gia tri la 0
//    cout << " Gia tri cua con tro a: " << *a;

//    // DUNG HAM REALLOC
//	int *a; // chua he co vung nho de chua gia tri
//	a = (int *)realloc(NULL, 1 * sizeof(int *)); // cap phat 1 vung nho moi cho con tro a
//    *a = 10;
//    cout << " \nGia tri cua con tro : " << *a;
//    cout << " \nMien gia tri cua con tro a: " << a;
//    
//    // cu phap cap phat lai vung nho cho con tro
//    a = (int *)realloc(a, 1 * sizeof(int *)); // cap phat lai 1 vung nho cho con tro a
//    cout << " \nGia tri cua con tro : " << *a;
//    cout << " \nMien gia tri cap phat lai: " << a;
//    free(a); // giai phong vung nho cho con tro

// CAP PHAT VUNG NHO CHO CON TRO (heap segment) - cu phap cua c: dung 3 ham de cap phat
     int *a;
     a = new int;
	 *a = 10;
	 cout << " Gia tri cua con tro: " << *a; 
	 delete a; // giai phong vung nho

    return 0;
}
