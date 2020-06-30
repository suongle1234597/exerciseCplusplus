#include<iostream>
using namespace std;
int main()
{
	int a = 10;
	int *b; // khai bao bien CON TRO
	b = &a; // cho con tro b tro den bien a (&a lay dia chi cua bien a) 
	
	cout << " \nGia tri cua bien a: " << a; 
	cout << " \nDia chi cua bien a: " << &a;
	cout << " \nGia tri con tro b: " << *b;
	cout << " \nDia chi con tro b: " << &b;
	cout << " \nMien gia tri cua con tro b: " << b; 
	
	return 0;
}
