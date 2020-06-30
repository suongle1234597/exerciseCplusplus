/* Viet chuong trinh lap di lap lai cac cong viec sau:
- Nhap vao mot ky tu tren ban phim.
- Neu la ky tu thuong thi in ra chinh no va ky tu HOA tuong ung.
- Neu la ky tu HOA thi in ra chinh no va ky tu thuong tuong ung.
- Neu la ky tu so thi in ra chinh no.
- Neu la mot ky tu dieu khien(enter, esc...) thi ket thuc chuong trinh*/

#include <iostream>
#include<string>
using namespace std;

void In (char kytu)
{
	int i, n = 265;
	char t;
	do
	{
		if (kytu >= 97 && kytu <= 122)
		{
			t = kytu - 32;
			cout << char (t);
			break;
		}
	    else if (kytu >= 65 && kytu <= 90)
	    {
	      	t = kytu + 32;
  	  		cout << char (t);
  	  		break;
	    } 
	    else if (kytu >= 48 && kytu <= 57)
	    {
		    cout << kytu;
		    break;
	    } 
	} while (kytu == 13 || kytu == 32 || kytu == 8 || kytu == 27 || kytu == 9 || kytu == 17);
}

int main ()
{
	char kytu;
	cout << "\n Nhap vao mot ky tu: "; cin >> kytu;
	In (kytu);
	return 0;
}
