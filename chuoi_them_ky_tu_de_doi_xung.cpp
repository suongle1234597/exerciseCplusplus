/* Cho xau ky tu s chi gom cac ky tu Latinh in hoa va in thuong (‘A’, …, ’Z’ và ‘a’,…,’z’). 
Hay tim cach them it ky tu nhat vao cuoi xau de duoc xau doi xong.

* Du lieu vao *

Mot dong duy nhat chua xau s.

* Du lieu ra *

Xau ky tu doi xung sau khi da them it nhat cac ky tu vao cuoi xau s.

Vi du: 

Du lieu vao:
xyz
Du lieu ra:
xyzyx
Gioi han: 1 = |s| = 5.105.*/

#include <iostream>
#include <string.h>
#include <stdio.h>
#define MAX 100
using namespace std;

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

bool Kiem_Tra_Doi_Xung(char s[]) {
	int n = strlen(s);
	int dem = 0;
	int tam[MAX], m = 0;
    for (int i = 0; i < n/2 + 1; i++) {
    	for (int j = n - 1; j >= (n/2 + 1); j--) {
    		if(s[i] == s[j] && dem == i) return true;
    		dem++;
		}
	}
	return false;
}

void Tao_Chuoi_Doi_Xung(char s[]) {
	int n = strlen(s);
	int lap1 = 0, lap2 = 0;
	
	for (int i = n/2; i < n; i++) {
		lap1++;
    	for (int j = n/2; j >= 0; j--) { 
    		lap2++;
    		if((s[i] == s[j] && s[i + 1] != s[j + 1] && lap1 == lap2) ) {
    		Them(s, j, s[j + 1]);
    		j++;	
    		}
    		
		}
		
    }
//cout << char(a[i]);
//    }
//    cout << endl;
//    for (int i = 0; i < m; i++) {
//    	cout << char(tam[i]);
//	}
    
	
}


using namespace std;

int main() {
	char s[30];
	cout << " Nhap chuoi: "; gets(s);
	Tao_Chuoi_Doi_Xung(s);
//	if(Kiem_Tra_Doi_Xung(s) == true) cout << "dx";
//	else cout << "k";
	cout << " Xuat chuoi: " << s;
	return 0;
}
