// Chuoi

#include<iostream>
#include <stdio.h>
using namespace std;
#include<string.h> // thu vien ho tro dung cac ham cua chuoi ki tu
//#pragma warning(disable: 4996) // bo qua loi cu phap version

/*
Ki tu: tong chu cai rieng biet tren ban phim
'a', 'b', 'c'
Chuoi la tap hop mot hoac nhieu ki tu
"lap trinh" ==>
'l'
'a'
'p'
' '
't'
'r'
'i'
'n'
'h'

chuoi ban chat la mang 1 chieu cac ki tu va nam lien tiep nhau trong bo nho may tinh
char str[100]; // khai bao chuoi ki tu chua toi da 99 ki tu
ASCII: ma so nguyen
'A': 65
'B': 66
...
'Z': 90
'a': 97
'b': 98
...
'z': 122

*/

// do lai ham lay do dai chuoi
int STRLEN(char s[])
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return i;
}

// ham them 1 ki tu vao vi tri bat ki trong chuoi
void Them(char s[], int vt, char x)
{
	int n = strlen(s);
	for (int i = strlen(s) - 1; i >= vt; i--)
	{
		s[i + 1] = s[i];
	}
	s[vt] = x;
	s[n + 1] = '\0';
}

// ham xoa 1 ki tu tai vi tri bat ki trong chuoi
void Xoa(char s[], int vt)
{
	int n = strlen(s);
	for (int i = vt + 1; i < n; i++)
	{
		s[i - 1] = s[i];
	}
	s[n - 1] = '\0';
}
int main()
{
	/*char s[20];
	cout << "\nNhap chuoi: ";
	gets(s);
	cout << "\nChuoi nhan duoc: " << s;
	cout << "\nDo dai chuoi: " << STRLEN(s);*/

	//char hoten[30];
	//int namsinh;
	//
	//cout << "\nNhap nam sinh: ";
	//cin >> namsinh;
	//cin.ignore();//fflush(stdin); 
	//cout << "\nNhap ho ten: ";
	//gets(hoten);

	//cout << "\nHo ten:" << hoten;
	//cout << "\nNam sinh:" << namsinh;

	//char s[30] = "lap trinh";
	/*char s[30];
	cout << "\nNhap chuoi: ";
	gets(s);
	Them(s, 2, 'x');
	cout << "\nChuoi sau khi them: " << s;
	cout << "\nDo dai chuoi: " << strlen(s);*/

	char s[30];
	cout << "\nNhap chuoi: ";
	gets(s);
	Xoa(s, 2);
	cout << "\nChuoi sau khi xoa: " << s;
	cout << "\nDo dai chuoi: " << strlen(s);

	return 0;
}
