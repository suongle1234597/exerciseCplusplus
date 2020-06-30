#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
 
void swap(int &x, int &y)
{
 	int tam;
 	tam = x;
 	x = y;
 	y = tam;
}
int main()
{
 	srand(time(NULL));
 	int a[31];
 	for(int i = 1; i < 31; i++)
 	{
 		a[i] = i;
 	}
 	
 	for(int i = 1; i < 31; i++)
 	{
 		int r = i + (rand() % (31 - i));
 		cout << a[r] << endl;
 		swap(a[i], a[r]);
 	}
 	return 0;
 }
