#include<iostream>
#include<fstream>

using namespace std;

struct phanso
{
	int tuso;
	int mauso;
	phanso *p; //tao moi lien ket vs phan so khac
};
typedef struct phanso PHANSO;

void Nhap(PHANSO *&ps) {
	cout << "\nNhap tu so: "; cin >> ps->tuso;
	cout << "Nhap mau so: "; cin >> ps->mauso;
}

void Xuat(PHANSO *&ps) {
	cout << ps->tuso << "/" << ps->mauso << endl;
}

int main() {
//	PHANSO *cha;
//	PHANSO *m;
//	int luachon; 
//	cha = NULL; // danh sach chua ton tai bat ki phan so nao
//	while(true) {
//		system("cls");
//		cout << "\n=====================QUAN LY DANH SACH PHAN SO=====================\n";
//		cout << "\n1. Nhap danh sach phan so";
//		cout << "\n2. Xuat danh sach phan so";
//		cout << "\n0. Ket thuc";
//		cout << "\n===============================END=================================\n";
//		cout << "\n\nNhap lua chon: "; cin >> luachon;
//		if(luachon == 0) {
//			break;
//		}
//		else if(luachon == 1) {
//			cout << "\n\tNhap vao phan so\n";
//			PHANSO *x = new PHANSO(); // bat dau tao ra phan so x 
//			x->p = NULL;
//			Nhap(x);
//			
//			// them vao danh sach
//			if(cha == NULL) {
//				cha = x; // x la cha, nam dau danh sach
//				m = x;
//			}
//			else {
//				// them vao dau danh sach
////				x->p = cha; // B1. cho phan tu can them lien ket tro den dau danh sach thong qua dai ca
////				cha = x; // B2. cho cha tro den phan tu moi (cap nhat cha- tao moi lien ket)
//
//				//them vao cuoi danh sach
//				m->p = x;
//				m = x;
//			}
//			system("pause");
//		}
//		else if(luachon == 2) {
//			cout << "\n\tXuat danh sach phan so\n";
//			for(PHANSO *k = cha; k != NULL; k = k->p) {
//				Xuat(k);
//			}
//			system("pause");
//		}
//	}
//	
//	
//	// GIAI PHONG 
//	PHANSO *k;
//	while(cha != NULL) {
//		k = cha;
//		cha = cha->p;
//		delete k;
//	}
	
	
	PHANSO *A = new PHANSO;
	PHANSO *B = new PHANSO;
	PHANSO *C = new PHANSO;
	PHANSO *D = new PHANSO;
	PHANSO *cha;
	
	cout << "\n\tNhap cac phan so\n";
	Nhap(A);
	Nhap(B);
	Nhap(C);
	Nhap(D);
	
	cha = A; // nam cai phan so dau cua lien ket
	A->p = B; // tao moi lien ket tu A den B <=> cho con tro A tro den dia chi cua B
	B->p = C; // tao moi lien ket tu B den C <=> cho con tro B tro den dia chi cua C
	C->p = D; // tao moi lien ket tu C den D <=> cho con tro C tro den dia chi cua D
	D->p = NULL;
	
	// duyet danh sach
//	cout << "\n\tXuat cac phan so\n";
//	for(PHANSO *k = cha; k != NULL; k = k->p) {
//		Xuat(k);
//	}
//	
	// TIM KIEM CAC PHAN SO CO TU SO NHAP TU BAN PHIM
//	int x;
//	cout << "\nNhap tu so can tim kiem: ";
//	cin >> x;
//	
//	cout << "\n\tXuat cac phan so co tu so vua nhap vao\n";
//	for(PHANSO *k = cha; k != NULL; k = k->p) {
//		if(k->tuso == x) {
//			Xuat(k);
//		}
//	}
	
	// RUT GON CAC PHAN SO
	for(PHANSO *k = cha; k != NULL; k = k->p) {
		if(k->tuso < k->mauso) { 
			for(int i = 2; i <= k->tuso; i++) {
				if(k->tuso % i == 0 && k->mauso % i == 0) {
					k->tuso = k->tuso / i;
					k->mauso = k->mauso / i;
				}
			}
		}
		else {
			for(int i = 2; i <= k->mauso; i++) {
				if(k->tuso % i == 0 && k->mauso % i == 0) {
					k->tuso = k->tuso / i;
					k->mauso = k->mauso / i;
				}
			}
		}
	}
	
//	cout << "\n\tXuat cac phan so da duoc toi gian\n";
//	for(PHANSO *k = cha; k != NULL; k = k->p) {
//		Xuat(k);
//	}
	
	// TINH TONG CAC PHAN SO
//	PHANSO *sum = new PHANSO();
//	sum->tuso = cha->tuso;
//	sum->mauso = cha->mauso;
//	for(PHANSO *k = cha->p; k != NULL; k = k->p) {
//			if(sum->mauso == k->mauso) {
//				sum->tuso = sum->tuso + k->tuso;
//				sum->mauso= k->mauso;
//			}
//			else {
//				sum->tuso = (sum->mauso * k->tuso) + (sum->tuso * k->mauso);
//				sum->mauso = sum->mauso * k->mauso;
//			}
//	}
//	cout << "\nTong cac phan so la: "; Xuat(sum);
//	if(sum->tuso > sum->mauso) {
//		for(int i = 2; i < sum->mauso; i++) {
//			if(sum->tuso % i == 0 && sum->mauso % i == 0) {
//				cout << "=> " << sum->tuso / i << "/" << sum->mauso / i;
//				break;
//			}
//		}
//	}
//	else {
//		for(int i = 2; i < sum->tuso; i++) {
//			if(sum->tuso % i == 0 && sum->mauso % i == 0) {
//				cout << "=> " << sum->tuso / i << "/" << sum->mauso / i;
//				break;
//			}
//		}
//	}
	
	// SAP XEP CAC PHAN SO TANG DAN - chia ra lay float roi so sanh
//	PHANSO *tam = new PHANSO();
//	for(PHANSO *k = cha; k != NULL; k = k->p) {
//		for(PHANSO *m = k->p; m != NULL; m = m->p) {
//			if(((float)k->tuso/(float)k->mauso) > ((float)m->tuso/(float)m->mauso)) {
//					tam->tuso = k->tuso;
//					tam->mauso = k->mauso;
//					k->tuso = m->tuso;
//					k->mauso = m->mauso;
//					m->tuso = tam->tuso; 
//					m->mauso = tam->mauso; 
//			}
//
//		}
//	}
//	
//	for(PHANSO *k = cha; k != NULL; k = k->p) {
//		Xuat(k);
//	}
	
	// THEM PHAN SO X SAU PHAN SO B
//	PHANSO *X = new PHANSO();
//	cout << "\nNhap phan so X can them: ";
//	Nhap(X);
//	X->p = C;
//	B->p = X;
//	
//	for(PHANSO *k = cha; k != NULL; k = k->p) {
//		Xuat(k);
//	}
	
	//THEM PHAN SO X TRUOC PHAN SO A
//	PHANSO *X = new PHANSO();
//	cout << "\nNhap phan so X can them: ";
//	Nhap(X);
//	X->p = A;
//	cha = X;
//	for(PHANSO *k = cha; k != NULL; k = k->p) {
//		Xuat(k);
//	}
	
	//THEM PHAN SO X VAO VI TRI BAT KY
//	int vitri = 0, dem = 1;
//	PHANSO *X = new PHANSO();
//	
//	cout << "\nNhap vi tri can them vao sau (A-1, B-2, C-3, D-4): "; 
//	cin >> vitri;
//	cout << "\nNhap phan so X can them: ";
//	Nhap(X);
//	
//	for(PHANSO *k = cha; k != NULL; k = k->p) {
//		if(vitri == dem) {
//			X->p = k->p;
//			k->p = X;
//		}
//		dem++;
//	}
//	
//	cout << "\nDanh sach sau khi them\n";
//	for(PHANSO *k = cha; k != NULL; k = k->p) {
//		Xuat(k);
//	}

// XOA DAU DANH SACH
//	PHANSO *m = NULL;
//	m = A;
//	cha = B;
//	delete m;

// XOA CUOI DANH SACH
//	PHANSO *m = NULL;
//	for(PHANSO *k = cha; k != NULL; k = k->p) {
//		if(k->p->p == NULL) {
//			m = k->p;
//			delete m;
//			k->p = NULL;
//		}
//	}
	
	
	// XOA PHAN SO SAU PHAN SO M BAT KY

	PHANSO *m = new PHANSO;
	PHANSO *n, *a;
	
	cout << "\nNhap phan so can de xoa: "; 
	cin >> m->tuso;
	cin >> m->mauso;
	
	for(PHANSO *k = cha; k != NULL; k = k->p) {
		if(m->tuso == k->tuso && m->mauso == k->mauso && k->p != NULL) {
			n = k->p;
			k->p = n->p;
			delete n;
		}
	}

// XOA PHAN SO K
//
//	for(PHANSO *k = cha; k != NULL; k = k->p) {
//		if(m->tuso == k->tuso && m->mauso == k->mauso && k->p != NULL) {
//			a = k;
//			n = k->p;
//			k = k->p;
//			delete a;
//		}
//		else {
//			n = k;
//		}
//	}
	
	cout << "\nDanh sach sau khi xoa\n";
	for(PHANSO *k = cha; k != NULL; k = k->p) {
		Xuat(k);
	}
	
//	delete A;
	delete B;
	delete C;
	delete D; 
//	delete m;
//	delete n;
//	delete sum;
//	delete tam;
	
	return 0;
}
