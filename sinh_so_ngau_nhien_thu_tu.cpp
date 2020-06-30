//#include <iostream>
//#include <cstdlib> // for rand() and srand()
//#include <ctime> // for time()
//using namespace std;
//
//unsigned int Random() {	// ham tao ngau nhien so tu 100 -> 999
//	unsigned int a;
//	srand(time(0));
////	for( int i = 1; i < 10; i++)
////	{
//		a = rand() % 10 + 1;	
////	} 	
//    return a;
//}
////int random(int max) {
////	int r;
////	for(int i = 1; i < max; ++i) {
////		r = rand(i, max) %10 + 1;
////	
////	}
////	return r;
////}
//
//int RandomKhongTrung(int a[], int max) {
//	int j = 0, t = Random();
//    for (int i = 0; i < max; i++) {
//        if(t == a[i]) {
//        	swap(a[i], a[j]); 
//			j++;
//		}
//    }
//    
//}
//void Xuat_ramdom(int a[], int n) {
//    for (int i = 0; i < n; i++) {
//        cout << a[i] << endl;
//    }
//    cout << endl;
//}
//int main()
//{
//	int a[10];
//	int n = 10;
////	RandomKhongTrung(a, n);
////	Xuat_ramdom(a, n);
//	cout << Random();
//	return 0;
//}


//#include <iostream>
//#include <algorithm>
//
// using namespace std;
//const int MAX = 2000;
// 
//int arr[MAX];
// 
//int main(){
//    int minN = 1;
//    int maxN = 20;
//    int a;
//    int N = maxN - minN + 1;
//    for(int i = minN; i <= maxN; ++i){
//        arr[i - minN] = i;
//    }
////    random_shuffle(arr, arr + N);
////	a = rand() % 10 + 1;
//    
//    int take = 10;
//    for(int i = 0; i < take; ++i){
//    	a = rand() % 10 + 1;
//        cout << a << " ";
//    }
//}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
 
void rd(int a[], int minN, int maxN) {
	for(int i = minN; i < maxN; ++i) {
		a[i - minN + 1] = i;
//		cout << a[i] << " ";
	}
}

void hd(int a[], int r, int maxN) {
	int j = 1;
	for(int i = 1; i < maxN; i++) {
		if(r == a[i]) {
			swap(a[i], a[j]);
			j++;
		}
	}
}
//int random(int minN, int maxN){
//    return minN + rand() % (maxN + 1 - minN);
//}
 
void HoanDoi(int &a, int &b) {
	int tam = a;
	a = b;
	b = tam;
}

int main(){
    srand((int)time(NULL));
    int r, minN = 1, maxN = 10;
    int a[10];
    int j = 1;
    rd(a, minN, maxN);
    r = minN + rand() % (maxN + 1 - minN);
    cout << r;
	for(int i = 1; i < maxN; i++) {
		if(r == a[i]) {
			HoanDoi(a[i], a[j]);
			j++;
		}
//		cout << r << " ";
		cout << " "<< a[i] << " ";
	} 
}
