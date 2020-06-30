/*
Luat choi nhu sau: Nguoi nhap vao ky tu tuong ung:
'B' hay 'b' => Bua
'O' hay 'o' => Bao
'K' hay 'k' => keo

Sau do May se random ra ky tu bat ki (co the la bua hoac bao hoac keo). Sau do 
tinh ket qua chung cuoc (nguoi thang hay may thang).

Goi y: Tham khao cach Random so nguyen trong 1 doan nao do, ta co the quy uoc 
vd: so 1 => bua, 2 => bao, 3 => keo. Roi tinh thong thua giua nguoi & may theo nguyen tac nhu ngoai doi:

- Bua thang keo nhung thua bao
- Bao thang bua nhung thua keo
- Keo thong bao nhung thua bua. */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

void KiemTra (char nguoi[1])
{
	srand(time(NULL));
	int i, number[3];
	char Bua = 'b', Bao = 'o', Keo = 'k';
	for (i = 1; i <= 3; i++)
	{
		number[i] = 1 + rand()%(3);  
}
		if (number[i] == 1)
		{
			if (nguoi[1] == Bua)
			{
				cout << " May ra Bua. Ban va may hoa";
			}
			else if (nguoi[1] == Bao) cout << " May ra Bua. Ban thang";
			else cout << " May ra Bua. May thang";
		}
		else if (number[i] == 2)
		{
			if (nguoi[1] == Bao)
			{
				cout << " May ra Bao. Ban va may hoa";
			}
			else if (nguoi[1] == Keo) cout << " May ra Bao. Ban thang";
			else cout << " May ra Bao. May thang";
		}
		else
		{
			if (nguoi[1] == Keo)
			{
				cout << " May ra Keo. Ban va may hoa";
			}
			else if (nguoi[1] == Bua) cout << " May ra Keo. Ban thang";
			else cout << " May ra Keo. May thang";
		}
}

int main ()
{
	char nguoi[1];
	char Bua = 'b', Bao = 'o', Keo = 'k';
	cout << "\n TRO CHOI KEO BUA BAO";
	cout << "\n Ban nhap 'b' = Bua, 'o' = Bao, 'k' = Keo";
	cout << "\n Moi ban choi: "; cin >> nguoi[1];
	KiemTra (nguoi);
	return 0;	
}
