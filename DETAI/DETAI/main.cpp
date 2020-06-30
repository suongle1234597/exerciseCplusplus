#include "mylibary.h"

// Cay nhi phan Danh sach Mon hoc
struct MonHoc {
	char maMH[10];
	char tenMH[40];
};
typedef struct MonHoc MONHOC;

struct nodeMH{
	MONHOC monhoc;
	nodeMH *pLeft;
	nodeMH *pRight;
};
typedef struct nodeMH NODEMH;
typedef NODEMH *TREE;

//Tao 1 ds cau hoi thi
struct CH{
	int id;
	int chiso;
};
struct nodeCH{
	CH ch;
	struct nodeCH *pNext;
};
typedef nodeCH NODECH;

struct listCH{
	NODECH *pHead;
	NODECH *pTail;
	int sochthi = 0;
};
typedef struct listCH LISTCH;

// Danh sach Diem thi DSLKD
struct DiemThi{
	char maMH[10];
	float diem;
	LISTCH dschthi;
};
typedef struct DiemThi DIEMTHI;

struct nodeDiem{
	DIEMTHI dt;
	struct nodeDiem *pNext;
};
typedef nodeDiem NODEDIEM;

struct listDiem{
	NODEDIEM *pHead;
	NODEDIEM *pTail;
	int sldiemthi = 0;
};
typedef struct listDiem LISTDIEM;

// Khai bao Danh sach Sinh Vien danh sach lien ket don
struct SinhVien{
	char maSV[11];
	char ho[30];
	char ten[10];
	char phai[4];
	char password[11];
	LISTDIEM dsd;
};
typedef struct SinhVien SINHVIEN;

struct nodeSV{
	SINHVIEN sv;
	struct nodeSV *pNext;
};
typedef nodeSV NODESV;

struct listSV{
	NODESV *pHead;
	NODESV *pTail;
	int slsv = 0;
};
typedef struct listSV LISTSV;

// Khai bao mang con tro Danh sach lop
struct Lop{
	char maLop[10];
	char tenLop[20];
    LISTSV dssv;
};
typedef struct Lop LOP;

struct listLop{
	int n;
	LOP *nodeLop[MAXLOP];
};
typedef struct listLop LISTLOP;

// Mang con tro CAU HOI THI
struct CauHoi{
	int id;
	char maMH[10];
	char noiDung[61];
	char A[18];
	char B[18];
	char C[18];
	char D[18];
	char dapAn; 
};
typedef struct CauHoi CAUHOI;

struct ListCauHoi{
	int n;
	CauHoi *nodeCauHoi[MAXCAUHOI];
};
typedef struct ListCauHoi LISTCAUHOI;

//////////////////////////////////////////////////////////////////////////////////////
void SuaLop(LISTLOP &list);
void SuaSV(LISTLOP &listlop, int chiso);
void SuaMH(TREE &t);
void SuaCauHoi(LISTCAUHOI &list);
void GhiFileLop(LISTLOP &listlop);
void DocFileLop(LISTLOP &listlop);
void DocFileMH(TREE &t);
bool KiemTraMonHocTrongCauHoi(LISTCAUHOI listch, char mamh[]);
void KhoiTaoSV(LISTSV &l);
//////////////////////////////////GIAO DIEN DANG NHAP//////////////////////////////////////////////

bool LoginUsername(LISTLOP listlop, char username[], char password[]) {
	if(stricmp(username, "GV") == 0 && strcmp(password, "GV") == 0){
		SetColor(28);
		gotoxy(78, 33);
		cout << "Tai khoan GV dang dang nhap...";
		Sleep(1000);
		return true;
	}
	else if(stricmp(username, "GV") == 0 && strcmp(password, "GV") != 0){
		return false;
	}
	SetColor(28);
	for(int i = 0; i < listlop.n; i++) {
		for (NODESV *p = listlop.nodeLop[i]->dssv.pHead; p != NULL; p = p->pNext) {
			if (stricmp(username, p->sv.maSV) == 0 && strcmp(password, p->sv.password) == 0){
				char *notify = new char[100]; notify[0]='\0';
				strcat(notify,"Tai khoan ");
				strcat(notify, p->sv.ho);
				strcat(notify, " ");
				strcat(notify, p->sv.ten);
				strcat(notify, " dang dang nhap...");
				gotoxy(78, 33);
				SetColor(28);
				cout << notify;
				Sleep(1000);
				return true;
			}
			else if (stricmp(username, p->sv.maSV) == 0 && strcmp(password, p->sv.password) != 0){
				return false;
			}
		}
	}	
}

bool CheckUsername(LISTLOP listlop, char username[]) {
	if(stricmp(username, "GV") == 0){
		return true;
	}

	for(int i = 0; i < listlop.n; i++) 
		for (NODESV *p = listlop.nodeLop[i]->dssv.pHead; p != NULL; p = p->pNext) 
			if (stricmp(username, p->sv.maSV) == 0) return true;
	return false;
}

NODESV* Account(LISTLOP listlop, char username[]) {
	for(int i = 0; i < listlop.n; i++) 
		for (NODESV *p = listlop.nodeLop[i]->dssv.pHead; p != NULL; p = p->pNext) 
			if (stricmp(username, p->sv.maSV) == 0) return p;
}

void Login(LISTLOP listlop, char *account, NODESV *&p){
	SetColor(42);
	cout << endl;
	cout << endl;
	cout << endl;
	cout <<"\n\t\t\t\t\t\t\t\t\t          ____  _    _         _   _       _  __     __       " << endl;
	cout <<"\t\t\t\t\t\t\t\t\t         / __ \\| |  | |  /\\   | \\ | |     | | \\ \\   / /"<< endl;
    cout <<"\t\t\t\t\t\t\t\t\t        | |  | | |  | | /  \\  |  \\| |     | |  \\ \\_/ / "<< endl;
    cout <<"\t\t\t\t\t\t\t\t\t        | |  | | |  | |/ /\\ \\ | . ` |     | |   \\   /  "<< endl;
    cout <<"\t\t\t\t\t\t\t\t\t        | |__| | |__| / ____ \\| |\\  |     | |____| |   "<< endl;
    cout <<"\t\t\t\t\t\t\t\t\t         \\___\\_\\\\____/_/    \\_\\_| \\_|     |______|_| " << endl;
    cout << endl;
    cout <<"\t\t\t\t\t\t _______ _    _ _____       _______ _____            _____       _   _  _____ _    _ _____ ______ __  __ "<< endl;
    cout <<"\t\t\t\t\t\t|__   __| |  | |_   _|     |__   __|  __ \\     /\\   / ____|     | \\ | |/ ____| |  | |_   _|  ____|  \\/  |"<< endl;
    cout <<"\t\t\t\t\t\t   | |  | |__| | | |          | |  | |__) |   /  \\ | |          |  \\| | |  __| |__| | | | | |__  | \\  / |"<< endl;
    cout <<"\t\t\t\t\t\t   | |  |  __  | | |          | |  |  _  /   / /\\ \\| |          | . ` | | |_ |  __  | | | |  __| | |\\/| |"<< endl;
    cout <<"\t\t\t\t\t\t   | |  | |  | |_| |_         | |  | | \\ \\  / ____ \\ |____      | |\\  | |__| | |  | |_| |_| |____| |  | |"<< endl;
    cout <<"\t\t\t\t\t\t   |_|  |_|  |_|_____|        |_|  |_|  \\_\\/_/    \\_\\_____|     |_| \\_|\\_____|_|  |_|_____|______|_|  |_|"<< endl;
    cout <<"";
   
    VeKhung2Duong(73, 22, 3, 60, WHITE); //khung tren
	gotoxy(99,23);
	SetColor(RED);
	cout << "DANG NHAP";
	SetColor(15);
	VeKhung2Duong(73, 25, 11, 60, WHITE); // khung duoi
	
	gotoxy(78,28);	
	cout << "Ma sinh vien: "; 
	VeKhung1Duong(93, 27, 3, 35, WHITE);

	gotoxy(78,31);	
	cout << "Mat khau: "; 
	VeKhung1Duong(93, 30, 3, 35, WHITE);
	
	VeDuongThang(0, 47, 210, 196, DARKBLUE);
	VeDuongThang(0, 49, 210, 196, DARKBLUE);
	gotoxy(10, 48);
	SetColor(DARKBLUE);
	cout << "F1: An / hien mat khau   |    Dowm: Xuong   |   Up: Len   |  ESC: Thoat"; 
	char masv[11], mk[11], mkan[11];
	int table = 0, dem = 0, i = 0, j = 0, hienmk = 0;
	char c;
	masv[0]='\0'; mk[0]='\0';mkan[0]='\0';
	do{
		if(table == 0) {
			gotoxy(95 + strlen(masv) + 1, 28);
			c = getch();
		}
		else if(table == 1) {
			gotoxy(95 + strlen(mkan) + 1, 31);
			c = getch();
		}
		else {
			c = getch();
		}
		
		if(c == Enter || c == Down) {
			table++;
			if(table == 1) {
				SetColor(28);
				if(strlen(masv) == 0) {
					gotoxy(78, 33);
					cout << "Chua nhap ma sinh vien ! ";
					table = 0;
					Sleep(1000);
				}
				else if(CheckUsername(listlop, masv) == false){
					gotoxy(78, 33);
					cout << "Tai khoan khong ton tai. Vui long nhap lai !";
					table = 0;
					Clear(masv);
					gotoxy(95, 28);
					cout << "                           ";
					i = 0;
					gotoxy(96, 28); // nhay toi cho dau table de khoi thay dau cach ngay cho xoa chu
					Sleep(1000); // sleep cho thong bao hien 1s. neu bo o ngoai nhan enter se cham 1s
				}
				gotoxy(78, 33);
				cout << "                                                  ";
			}
			if(table == 2) {
				SetColor(28);
				if(strlen(mk) == 0) {
					gotoxy(78, 33);
					cout << "Chua nhap mat khau ! ";
					table = 1;
				}
				else if(LoginUsername(listlop, masv, mk) == false) {
					dem++;
					if(dem == 3) {
						gotoxy(78, 33);
						cout << "Ban da nhap sai mat khau 3 lan.";
						gotoxy(78, 34);
						cout << "Vui long nhap lai thong tin sau 5 phut !";
						Sleep(300000); //ms
						table = 0;
						Clear(masv);
						Clear(mk);
						Clear(mkan);
						gotoxy(95, 28);
						cout << "                         ";
						gotoxy(95, 31);
						cout << "                         ";
						i = 0;
						j = 0;
						gotoxy(96, 31);
					}
					else{
						gotoxy(78, 33);
						cout << "Mat khau khong dung. Vui long nhap lai !";
						table = 1;
						Clear(mk);
						Clear(mkan);
						gotoxy(95, 31);
						cout << "                         ";
						j = 0;
						gotoxy(96, 31);
					}
				}
				else if(LoginUsername(listlop, masv, mk) == true) {
					p = Account(listlop, masv);
					strcpy(account, masv);
					break;
				}
				Sleep(1000);
				gotoxy(78, 33);
				cout << "                                                  ";
				gotoxy(78, 34);
				cout << "                                                  ";
			}
		}
		else if (c == 0){
	    	c = getch();
	    	if (c == 59) {
	    		hienmk = (hienmk + 1) % 2;
			    if(hienmk == 1) {
					gotoxy(95 + 1, 31);
					cout << mk;
				} 
				else 
					if(table == 1) {
						gotoxy(95 + 1, 31);
						SetColor(WHITE);
						cout << mkan;
					}
			}
		}
		else if (c == 9) table = (table + 1) % 2;
		else if (c == Up) table = 0;
		else if (c == Left || c == Right) _getch(); // phim len xuong
    	else if (c == ESC) exit(0); 
    	else if (c == 8){ //backspace
       		if (table == 0) XoaTungKyTu(masv, i, 95, 28);
			else if (table == 1)
				if(strlen(mk) > 0) {
					gotoxy(95 + strlen(mk) + 1, 31);
       				cout << "\b \b";
       				BackSpace(mk);
       				BackSpace(mkan);
       				j--;
				}
		}
		else if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122) ){
			if (table == 0) {
				InHoa(c);
				NhapChuoi(masv, c, i, 95, 28);
			}
			else if (table == 1){
				SetColor(15);
				mk[j] = c;
				mk[j + 1] = '\0';
				
				mkan[j] = '*';
				mkan[j + 1] = '\0';
				gotoxy(95 + strlen(mkan), 31); //cho ki tu tiep theo o phia sau
				if(hienmk == 0) cout << '*';
				else cout << c;
				j++;
			}
   		}
	} while(1);
}

///////////////////////////////MANG CON TRO LOP///////////////////////////////////////

int TimKiemLop(LISTLOP list, char malop[]) {
  	for (int i = 0; i < list.n ; i++)
     	if (stricmp(list.nodeLop[i]->maLop, malop) == 0) return i; // khac -1 la tim thay
  	return -1;
}

void Selection_Sort(LISTLOP &list) {
	LOP *lopmin;
	int vitrimin;
	int i, j;
	for(i = 0; i < list.n - 1; i++) {
		lopmin = list.nodeLop[i];
		vitrimin = i;
		for(j = i + 1; j < list.n; j++) 
			if(strcmp(list.nodeLop[j]->maLop, lopmin->maLop) < 0) {
				lopmin = list.nodeLop[j];
				vitrimin = j;
			}
		// Doi cho 2 phan tu list.nodeLop[i] va list.nodeLop[vitrimin]
		lopmin = list.nodeLop[vitrimin];
		list.nodeLop[vitrimin] = list.nodeLop[i];
		list.nodeLop[i] = lopmin;
	}
}

void LietKeLop(LISTLOP list) {
 	for (int i = 0 ; i < list.n ; i++)
 	{	
	 	SetColor(WHITE);
 		gotoxy(18, 15 + i);
		cout << i + 1;
		gotoxy(25, 15 + i);
		cout << list.nodeLop[i]->maLop;
		gotoxy(70, 15 + i);
		cout << list.nodeLop[i]->tenLop;
 	}
}

void XoaLopBatKy(LISTLOP &list, char malop[]){
	int i = TimKiemLop(list ,malop);
   	if (i != -1)  
   	{ 			
		delete list.nodeLop[i];
     	for (int j = i + 1; j < list.n; j++)
       		list.nodeLop[j - 1] = list.nodeLop[j];
       	list.n--;  
	}
}

//int InsertOrder (LISTLOP &list, LOP lop){ //them co thu tu
//	int j, k;
//	if (list.n == MAXLOP ) return 0;
//	for (j=0; (j < list.n) && stricmp(list.nodeLop[j]->maLop, lop.maLop) < 0; j++ );
//	for ( k = list.n-1; k >=j  ; k--) 
//	   list.nodeLop[k+1]= list.nodeLop[k];
//	list.nodeLop[j]= new LOP;
//	*list.nodeLop[j]=lop; list.n++;
//	return 1;
//}

void XoaThongBaoLop() {
	Sleep(1000);
	gotoxy(135, 21);
	cout << "                                                  ";
	gotoxy(135, 22);
	cout << "                            ";
}

void NhapLop(LISTLOP &list){
	LOP lop;
	bool exit = false;
	char malop[10], tenlop[20];
	int table = 0, i = 0, j = 0;
	char c;
	malop[0]='\0'; tenlop[0]='\0';
	VeKhung1Duong(130, 12, 13, 60, WHITE); // khung nhap
	
	gotoxy(135, 15);
	cout << "Ma lop : ";
	VeKhung1Duong(150, 14, 3, 35, WHITE); //duong giua stt va ma lop
	
	gotoxy(135, 18);
	cout << "Ten lop : ";
	VeKhung1Duong(150, 17, 3, 35, WHITE); // duong giua ma lop va ten lop
	
	do{
		if(table == 0) {
			gotoxy(152 + strlen(malop) + 1, 15); 
			c = getch();
		}
		else if(table == 1) {
			gotoxy(152 + strlen(tenlop) + 1, 18);
			c = getch();
		}
		else {
			c = getch();
		}		
		
		if(c == Enter || c == Down) {
			table++;
			if(table == 1) {
				SetColor(28);
				if(strlen(malop) == 0) {
					gotoxy(135, 21);
					cout << "Chua nhap ma lop ! ";
					table = 0;
					XoaThongBaoLop();
				}
				else 
					if(TimKiemLop(list, malop) != -1) {
						gotoxy(135, 21);
						cout << "Ma lop da bi trung. Xin nhap lai !"; 
						Clear(malop);
						table = 0;
						gotoxy(152, 15);
						cout << "                           ";
						gotoxy(153, 15);
						i = 0;
						XoaThongBaoLop();
					}
			}
			else if(table == 2) {
				SetColor(28);
				if(strlen(tenlop) == 0) {
					gotoxy(135, 21);
					cout << "Chua nhap ten lop ! ";
					table = 1;
					XoaThongBaoLop();
				}
				else {
					gotoxy(135, 21);
					cout << "Ban co muon luu thong tin lop khong ?";
					gotoxy(135, 22);
					cout << "F2: Co | F3: Khong";
				}
			}
		}
		else if (c == 0) {
			c = getch();
			if(c == 60){ //phim F2
				if(list.n < MAXLOP) {
					strcpy(lop.maLop, malop);
					strcpy(lop.tenLop, tenlop);
					list.nodeLop[list.n]= new LOP;
    				*list.nodeLop[list.n] = lop;
    				KhoiTaoSV(list.nodeLop[list.n]->dssv);
    				list.n++;
    				XoaThongBaoLop();
					gotoxy(135, 21);
					SetColor(RED);
					cout << "Luu thanh cong !";
					gotoxy(152, 15);
					cout << "                           ";
					gotoxy(152, 18);
					cout << "                           ";
					gotoxy(153, 15);
					XoaThongBaoLop();
					Clear(malop); i = 0;
					Clear(tenlop); j = 0;
					LietKeLop(list);
					table = 0;
				}
				else if(list.n == MAXLOP) {
					gotoxy(135, 21);
					SetColor(RED);
					cout << "Bo nho day !";
					gotoxy(152, 15);
					cout << "                           ";
					XoaThongBaoLop();
					table = 0;
				}
			}
			else if(c == 61) {
				XoaThongBaoLop();
				gotoxy(135, 21);
				SetColor(RED);
				cout << "Luu khong thanh cong !";
				XoaThongBaoLop();
				table = 0;
			}
		} 
		else if(c == ESC) {
			VeKhung1Duong(130, 12, 13, 60, 0);
			exit = true;
		}
		else if (c == 9)	table = (table + 1) % 2;
		else if (c == Up) table = 0;
		else if (c == Left || c == Right) _getch();
    	else if (c == 8){ //backspace
       		if (table == 0) XoaTungKyTu(malop, i, 152, 15);
			else if (table == 1) XoaTungKyTu(tenlop, j, 152, 18);
		}
		else if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 32){
			if (table == 0 && i < 9 && c != 32) {
				InHoa(c);
				NhapChuoi(malop, c, i, 152, 15);
			}
			else if(table == 1) {
				if(j == 0 && c != 32) {
					InHoa(c);
					NhapChuoi(tenlop, c, j, 152, 18);
				} 
				else if(j > 0 && j < 19) {
					if(!(c == 32 && tenlop[j - 1] == 32)) {
						if(tenlop[j - 1] == 32)  InHoa(c);
						NhapChuoi(tenlop, c, j, 152, 18); 
					} 
				}
			}
   		}
	} while(!exit);
}

void XoaDSLOP() {
 	for (int i = 0 ; i < 30 ; i++)
 	{	
 		gotoxy(17, 15 + i);
		cout << "    ";
		gotoxy(24, 15 + i);
		cout << "                                   ";
		gotoxy(65, 15 + i);
		cout << "                                               ";
 	}
}

bool KiemTraLopCoSV(LISTLOP listlop, char malop[]) {
	for (int i = 0; i < listlop.n ; i++) {
		if(stricmp(listlop.nodeLop[i]->maLop, malop) == 0) 
			if(listlop.nodeLop[i]->dssv.slsv != 0) return true;
	}
	return false;
}

void XoaLop(LISTLOP &list) {
	bool exit = false;
	int i = 0, table = 0;
	char malop[10]; malop[0]='\0';
	SetColor(WHITE);
	VeKhung1Duong(130, 16, 8, 60, WHITE);
	gotoxy(135, 18);
	cout << "Nhap ma lop can xoa : ";
	VeKhung1Duong(162, 17, 3, 25, WHITE);
	char c;
	do {
		gotoxy(165 + strlen(malop) + 1, 18);
		c = getch();
		if(c == Enter) {
			table++;
			if(table == 1) {
				SetColor(28);
				if(strlen(malop) == 0) {
					gotoxy(135, 21);
					cout << "Chua nhap ma lop ! ";
					table = 0;
					Sleep(1000);
					gotoxy(135, 21);
					cout << "                                                  ";
				}
				else {
					if(TimKiemLop(list, malop) == -1) {
						gotoxy(135, 21);
						cout << "Ma lop khong ton tai. Xin nhap lai !"; 
						Clear(malop);
						table = 0;
						Sleep(1000);
						gotoxy(165, 18);
						cout << "              ";
						gotoxy(135, 21);
						cout << "                                                  ";
						i = 0;
					}
					else if(KiemTraLopCoSV(list, malop) == true) {
						gotoxy(135, 21);
						cout << "Lop da co sinh vien. Khong duoc xoa. Xin nhap lai !"; 
						Clear(malop);
						table = 0;
						Sleep(1000);
						gotoxy(165, 18);
						cout << "              ";
						gotoxy(135, 21);
						cout << "                                                    ";
						i = 0;
					}
					else {
						gotoxy(135, 21);
						cout << "Ban co thuc su muon xoa lop nay khong ?";
						gotoxy(135, 22);
						cout << "F2: Co | F3: Khong";
					}
				}
			}
		}
		else if (c == 0) {
			c = getch();
			if(c == 60){ //phim F2
				XoaLopBatKy(list, malop);
				gotoxy(135, 21);
				cout << "                                                  ";
				gotoxy(135, 22);
				cout << "                            ";
				gotoxy(135, 21);
				SetColor(RED);
				cout << "Xoa thanh cong !";
				gotoxy(165, 18);
				cout << "              ";
				gotoxy(166, 18);
				Clear(malop); i = 0;
				Sleep(1000);
				gotoxy(135, 21);
				cout << "                                                  ";
				table = 0;
				XoaDSLOP();
				LietKeLop(list);
			}
			else if(c == 61) { //Phim F3
				gotoxy(135, 21);
				cout << "                                                  ";
				gotoxy(135, 22);
				cout << "                            ";
				gotoxy(135, 21);
				SetColor(RED);
				cout << "Xoa khong thanh cong !";
				Sleep(1000);
				gotoxy(135, 21);
				cout << "                                                  ";
				table = 0;
			}
		} 
		else if(c == ESC) {
			VeKhung1Duong(130, 12, 13, 60, 0);
			exit = true;
		}
		else if (c == Left || c == Right|| c == Up || c == Down) _getch();
    	else if (c == 8){ //backspace
       		if (table == 0) XoaTungKyTu(malop, i, 165, 18);
		}
		else if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122) ){
			if (table == 0 && i < 9) {
				InHoa(c);
				NhapChuoi(malop, c, i, 165, 18);
			}
   		}
	} while(!exit);
}

void SuaLopBatKy(LISTLOP &list, char malop[], char tenlop[]) {
	int i = TimKiemLop(list, malop);
	if(i != -1) strcpy(list.nodeLop[i]->tenLop, tenlop);
}

void SuaThongTinLop(LISTLOP &list, char malop[]) {
	bool exit = false;
	char tenlop[20];
	tenlop[0] = '\0';
	strcpy(tenlop, list.nodeLop[TimKiemLop(list, malop)]->tenLop);
	int table = 1, i = 0, j = strlen(tenlop);
	VeKhung1Duong(130, 12, 13, 60, WHITE); // khung nhap
	
	gotoxy(135, 15);
	cout << "Ma lop : ";
	VeKhung1Duong(150, 14, 3, 35, WHITE);
	SetColor(RED);
	gotoxy(152 , 15); 
	cout << malop;
	
	SetColor(WHITE);
	gotoxy(135, 18);
	cout << "Ten lop : ";
	VeKhung1Duong(150, 17, 3, 35, WHITE);
	char c;
	do{
		if(table == 1) {
			gotoxy(152, 18); 
			cout << tenlop;
			gotoxy(152 + strlen(tenlop), 18);
			c = getch();
		}
		else {
			c = getch();
		}		
		
		if(c == Enter) {
			table++;
			if(table == 2) {
				SetColor(28);
				if(strlen(tenlop) == 0) {
					gotoxy(135, 21);
					cout << "Chua nhap ten lop ! ";
					table = 1;
					XoaThongBaoLop();
				}
				else {
				gotoxy(135, 21);
				cout << "Ban co muon sua thong tin lop khong ?";
				gotoxy(135, 22);
				cout << "F2: Co | F3: Khong";
				}
			}
		}
		else if (c == 0) {
			c = getch();
			if(c == 60){ //phim F2
				SuaLopBatKy(list, malop, tenlop);
				XoaThongBaoLop();
				gotoxy(135, 21);
				SetColor(RED);
				cout << "Sua thanh cong !";
				gotoxy(152, 15);
				cout << "                           ";
				gotoxy(152, 18);
				cout << "                           ";
				Clear(tenlop); j = 0;
				gotoxy(152, 18); //cho tro toi table 1, khong bi dang sau dau cach
				VeKhung1Duong(130, 12, 13, 60, 0);
				XoaDSLOP();
				LietKeLop(list);
				SuaLop(list);
				break;
			}
			else if(c == 61){
				XoaThongBaoLop();
				gotoxy(135, 21);
				SetColor(RED);
				cout << "Sua khong thanh cong !";
				XoaThongBaoLop();
				SetColor(WHITE);
				table = 1;
			}
		} 
		else if(c == ESC) {
			VeKhung1Duong(130, 12, 13, 60, 0);
			exit = true;
			SuaLop(list);
		}
		else if (c == Left || c == Right|| c == Up|| c == Down) _getch();
    	else if (c == 8){ //backspace
			if (table == 1) XoaTungKyTuCoSan(tenlop, j, 152, 18);
		}
		else if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 32)
			if(table == 1) {
				if(j == 0 && c != 32) {
					InHoa(c);
					NhapChuoiCoSan(tenlop, c, j, 152, 18);
				} 
				else if(j > 0 && j < 19) {
					if(!(c == 32 && tenlop[j - 1] == 32)) {
						if(tenlop[j - 1] == 32)  InHoa(c);
						NhapChuoiCoSan(tenlop, c, j, 152, 18); 
					} 
				}
			}
	} while(!exit);
}

void SuaLop(LISTLOP &list) {
	bool exit = false;
	int i = 0, table = 0;
	char malop[10]; malop[0]='\0';
	char c;
	SetColor(WHITE);
	VeKhung1Duong(130, 16, 8, 60, WHITE);
	gotoxy(135, 18);
	cout << "Nhap ma lop can sua : ";
	VeKhung1Duong(162, 17, 3, 25, WHITE);
	
	do {
		gotoxy(165 + strlen(malop) + 1, 18);
		c = getch();
		if(c == Enter) {
			table++;
			if(table == 1) {
				SetColor(28);
				if(strlen(malop) == 0) {
					gotoxy(135, 21);
					cout << "Chua nhap ma lop ! ";
					table = 0;
					Sleep(1000);
					gotoxy(135, 21);
					cout << "                                                  ";
				}
				else {
					if((TimKiemLop(list, malop) == -1)) {
						gotoxy(135, 21);
						cout << "Ma lop khong ton tai. Xin nhap lai !"; 
						Clear(malop);
						table = 0;
						Sleep(1000);
						gotoxy(165, 18);
						cout << "              ";
						gotoxy(135, 21);
						cout << "                                                  ";
						i = 0;
					}
					else{
						gotoxy(135, 21);
						cout << "Tim ma lop thanh cong !"; 
						Sleep(1000);
						SuaThongTinLop(list, malop);
						break;
					}
				}
			}
		} 
		else if(c == ESC) {
			VeKhung1Duong(130, 12, 13, 60, 0);
			exit = true;
		}
		else if (c == Left || c == Right|| c == Up || c == Down) _getch();
    	else if (c == 8){ //backspace
       		if (table == 0) XoaTungKyTu(malop, i, 165, 18);
		}
		else if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122) ){
			if (table == 0 && i < 9) {
				InHoa(c);
				NhapChuoi(malop, c, i, 165, 18);
			}
   		}
	} while(!exit);
}

void GiaoDienNhapLop(LISTLOP &list) {
	const int so_item = 3;
	const int x = 130;
	const int y = 27;
	const int rong = 3;
	const int dai = 12;
	bool exit = false;
  	char kytu;
  	int chon = 0;
  	int i, dem = 0; 
  	
	VeKhung2Duong(80, 3 + 3, 3, 50, WHITE);
	gotoxy(80 + 15, 3 + 1 + 3);
	SetColor(RED);
	cout << "      NHAP LOP";
	
	VeKhung1Duong(15, 12, 34, 100, WHITE); //khung danh sach
	VeDuongThang(16, 14, 98, 196, WHITE); //duong ngang giua
	VeDuongDoc(21, 13, 32, 179, WHITE);
	VeDuongDoc(60, 13, 32, 179, WHITE);
	
	gotoxy(17, 13);
	cout << "STT";
	
	gotoxy(35, 13);
	cout << "Ma lop";
	
	gotoxy(80, 13);
	cout << "Ten lop";
	
	string *item = new string[so_item];
	item[0] = "THEM";
	item[1] = "XOA";
	item[2] = "SUA";
		
	Normal();  
  	for (i = 0; i< so_item ; i++)
  	{ 
  		VeKhung1Duong(x + dem, y, rong, dai, WHITE);
		gotoxy(x + 4 + dem, y + 1);
		cout << item[i];
		dem+=24;
  	}
	dem = 0; //cho dem bang 0 de chon lai khong bi thay doi cho
	VeKhung1Duong(x + chon, y, rong, dai, BROWN);
  	HighLight();
  	gotoxy(x + 4 + chon, y + 1);
  	cout << item[chon];
  	
  	VeDuongThang(0, 47, 210, 196, DARKBLUE);
	VeDuongThang(0, 49, 210, 196, DARKBLUE);
	gotoxy(10, 48);
	SetColor(DARKBLUE);
	cout << "Right: Sang phai          |         Left: Sang trai         |         ESC: Quay lai"; 
	
//	Selection_Sort(list);
	LietKeLop(list);
	
	do {
 		kytu = getch();
  		if (kytu == 0) kytu = getch();
  		else if(kytu == Enter) {
  			if(chon == 0) {
  				NhapLop(list);
				gotoxy(130 + 8 , 27 + 1);
			}
			if(chon == 1) {
				XoaLop(list);
				gotoxy(130 + 31, 27 + 1);
			}
			if(chon == 2) {
				SuaLop(list);
				gotoxy(130 + 55, 27 + 1);
			}
		}
		else if (kytu == ESC) {
			exit = true;
		}
  		switch (kytu) {
    	case Right :if (chon + 1 < so_item)
  			{
  		        	Normal();
  			  		VeKhung1Duong(x + dem, y, rong, dai, WHITE);
  			  		gotoxy(x + 4 + dem, y + 1);
					cout << item[chon];
					dem+=24;
              		chon ++;
              		HighLight();
              		VeKhung1Duong(x + dem, y, rong, dai, BROWN);
					gotoxy(x + 4 + dem, y + 1);
					cout << item[chon];
  			}
  			break;
  		case Left :if (chon + 1 > 1)
  			  {
  			  		Normal();
  			  		VeKhung1Duong(x + dem, y, rong, dai, WHITE);
  			  		gotoxy(x + 4 + dem, y + 1);
					cout << item[chon];
					dem-=24;
              		chon --;
              		HighLight();
              		VeKhung1Duong(x + dem, y, rong, dai, BROWN);
					gotoxy(x + 4 + dem, y + 1);
					cout << item[chon];
  			  }
  			  break;
  		}  
  } while (!exit);
}

///////////////////////////////DSLKD SINH VIEN////////////////////////////////////////

//KHOI TAO DSLKD
void KhoiTaoSV(LISTSV &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

//khoi tao 1 node
NODESV *KhoiTaoNODESV(SINHVIEN x) {
	NODESV *p = new NODESV; //cap phat vung nho	 cho node p
	if(p == NULL) {
//		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->sv = x;
	p->pNext = NULL;
	return p;
}

void ThemVaoDauDSSV(LISTSV &l, NODESV *p) {
	if(l.pHead == NULL) { //danh sach dang rong
		l.pHead = l.pTail = p; // node dau node cuoi la p
	}
	else{
		p->pNext = l.pHead; //cho con tro can them la node p lien ket voi pHead	
		l.pHead = p; //cap nhat lai pHead la node p
	}
}

void ThemVaoCuoiDSSV(LISTSV &l, NODESV *p) {
	p->sv.dsd.pHead = NULL;
	if(l.pHead == NULL) { //danh sach dang rong
		l.pHead = l.pTail = p; // node dau node cuoi la p
	}
	else{
		l.pTail->pNext = p; //cho con tro pTail lien ket voi node p
		l.pTail = p; //cap nhat lai p la pTail
	}
}

void LietKeSV(LISTLOP listlop, int chiso) {
	int dem = 0;
	char tam[11]; tam[0] = '\0';
	if(listlop.nodeLop[chiso]->dssv.slsv == 0) return;
	for(NODESV *k = listlop.nodeLop[chiso]->dssv.pHead; k != NULL; k = k->pNext) {
		SetColor(WHITE);
		gotoxy(7, 15 + dem);
	 	cout << dem + 1;
	 	gotoxy(13, 15 + dem);
	 	cout << k->sv.maSV;
		gotoxy(33, 15 + dem);
		cout << k->sv.ho;
		gotoxy(70, 15 + dem);
		cout << k->sv.ten;
		gotoxy(90, 15 + dem);
		cout << k->sv.phai;
		gotoxy(105, 15 + dem);
		strcpy(tam, k->sv.password);
		cout << MaHoaPWD(tam);
		dem++;	
	}
}

void XoaDSSV() {
	int dem = 0;
	for (int i = 0; i < 30; i++) {
		SetColor(WHITE);
	 	gotoxy(7, 15 + dem);
		cout << "    ";
	 	gotoxy(13, 15 + dem);
	 	cout << "               ";
		gotoxy(33, 15 + dem);
		cout << "                               ";
		gotoxy(67, 15 + dem);
		cout << "               ";
		gotoxy(85, 15 + dem);
		cout << "             ";
		gotoxy(102, 15 + dem);
		cout << "                     ";
		dem++;
	}
}

void XoaDauSV(LISTSV &l) {
	if(l.pHead == NULL) {
		return;
	}
	NODESV *p = l.pHead; //node p la node se xoa
	l.pHead = l.pHead->pNext; // cap nhat lai pHead laf phan tu ke tiep
	delete p;
}

void XoaCuoiSV(LISTSV &l) {
	if(l.pHead == NULL) {
		return;
	}
	for(NODESV *k = l.pHead; k != NULL; k = k->pNext) {
		if(k->pNext == l.pTail) {
			delete l.pTail; // xoa di phan tu cuoi
			k->pNext == NULL; // cho con tro cua node cuoi tro toi null
			l.pTail = k; // cap nhat lai pTail
			return;
		}
	}
}

void XoaSVBatKy(LISTSV &l, char ma[]) {
	if(stricmp(l.pHead->sv.maSV, ma) == 0) {
		XoaDauSV(l);
		return;
	}
	if(stricmp(l.pTail->sv.maSV, ma) == 0) {
		XoaDauSV(l);
		return;
	}
	
	NODESV *g = new NODESV; // node g tro den node truoc node can xoa 
	for(NODESV *k = l.pHead; k != NULL; k = k->pNext) {
		if(stricmp(k->sv.maSV, ma) == 0) {
			g->pNext = k->pNext; // cap nhat lien ket cua node g voi node sau h
			delete k; // xoa node nam sau k
			return;
		}
		g = k; // cho node g tro den node k
	}
}

//void XoaSVBatKy(LISTSV &l, char ma[]) {
//	NODESV *p = l.pHead, *q;
//	if(stricmp(l.pHead->sv.maSV, ma) == 0) {
//		p = l.pHead;
//		l.pHead = p->pNext;
//		delete p; 
//	}
//	for(p = l.pHead; p->pNext != NULL && stricmp(p->pNext->sv.maSV, ma) != 0; p = p->pNext);
//	if(p->pNext != NULL) {
//		q = p->pNext;
//		p->pNext = q->pNext;
//		delete q;
//	}
//}

NODESV* TimKiemSV(LISTLOP listlop, char ma[]) {
	for (int i = 0; i < listlop.n ; i++) {
		for(NODESV *k = listlop.nodeLop[i]->dssv.pHead; k != NULL; k = k->pNext)
			if(stricmp(k->sv.maSV, ma) == 0) return k; //tim ra
	}
	return NULL;
}

bool KiemTraMaSVTrung(LISTLOP listlop, char ma[]) {
	for (int i = 0; i < listlop.n ; i++) {
		for(NODESV *k = listlop.nodeLop[i]->dssv.pHead; k != NULL; k = k->pNext)
			if(stricmp(k->sv.maSV, ma) == 0) return true; //tim ra
	}
	return false;
}

void ClearNhapSV(char masv[], char ho[], char ten[], char phai[], char mk[], char mkan[], int &j, int &k, int &l, int &m, int &n) {
	Clear(masv); j = 0;
	Clear(ho); k = 0;
	Clear(ten); l = 0;
	Clear(phai); m = 0;
	Clear(mk); n = 0;
	Clear(mkan); 
	gotoxy(152, 18);
	cout << "                                           ";
	gotoxy(152, 21);
	cout << "                                           ";
	gotoxy(152, 24);
	cout << "                                           ";
	gotoxy(152, 27);
	cout << "                                           ";
	gotoxy(152, 30);
	cout << "                                           ";
}

void XoaThongBaoSV() {
	Sleep(1000);
	gotoxy(133, 32);
	cout << "                                                        ";
	gotoxy(133, 33);
	cout << "                        ";
}

int NhapLopDSSV(LISTLOP listlop){
	bool exit = false;
	int i = 0, table = 0, chiso = 0;
	char malop[10]; malop[0]='\0';
	SetColor(WHITE);
	gotoxy(75, 9);
	cout << "Nhap ma lop : ";
	VeKhung1Duong(90, 8, 3, 45, WHITE);
	char c;
	do {
		gotoxy(100 + strlen(malop) + 1, 9);
		c = getch();
		if(c == Enter) {
			table++;
			if(table == 1) {
				SetColor(28);
				if(strlen(malop) == 0) {
					gotoxy(75, 11);
					cout << "Chua nhap ma lop ! ";
					table = 0;
					Sleep(1000);
					gotoxy(75, 11);
					cout << "                                                  ";
				}
				else {
					chiso = TimKiemLop(listlop, malop);
					if (chiso == -1){
						gotoxy(75, 11);
						cout << "Ma lop khong ton tai. Moi nhap lai !";
						i = 0;
						Clear(malop);
						gotoxy(75, 11);
						cout << "                                                  ";
						gotoxy(100 + 1, 9);
						table = 0;
					}
					else {
						VeKhung1Duong(75, 8, 4, 60, 0);
						return chiso;
					}
				}
			}
		}
		else if(c == ESC) {
			VeKhung1Duong(75, 8, 4, 60, 0);
			exit = true;
		}
		else if (c == Left || c == Right|| c == Up || c == Down) _getch();
    	else if (c == 8){ //backspace
       		if (table == 0) XoaTungKyTu(malop, i, 100, 9);
		}
		else if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
			if (table == 0 && i < 9) {
				InHoa(c);
				NhapChuoi(malop, c, i, 100, 9);
			}
   		}
	} while(!exit);
}

void NhapSV(LISTLOP &listlop, int chiso) {
	SINHVIEN sv;
	char masv[11], ho[30], ten[10], phai[4], mkan[11], mk[11];
	int table = 0, dem = 0, j = 0, k = 0, l = 0, m = 0, n = 0, hienmk = 0;
	char c;
	bool exit = false;
	masv[0]='\0'; ho[0]='\0'; ten[0]='\0'; phai[0]='\0'; mkan[0]='\0'; mk[0]='\0';

	VeKhung1Duong(130, 15, 21, 70, WHITE); //khung ngoai
	
	gotoxy(133, 18);
	cout << "Ma sinh vien : ";
	VeKhung1Duong(148, 17, 3, 50, WHITE);
	
	gotoxy(133, 21);
	cout << "Ho : ";
	VeKhung1Duong(148, 20, 3, 50, WHITE);
	
	gotoxy(133, 24);
	cout << "Ten : ";
	VeKhung1Duong(148, 23, 3, 50, WHITE);
	
	gotoxy(133, 27);
	cout << "Phai : ";
	VeKhung1Duong(148, 26, 3, 50, WHITE);
	
	gotoxy(133, 30);
	cout << "Password : ";
	VeKhung1Duong(148, 29, 3, 50, WHITE);
	
	do{
		if(table == 0) {
			gotoxy(152 + strlen(masv) + 1, 18);
			c = getch();
		}
		else if(table == 1) {
			gotoxy(152 + strlen(ho) + 1, 21);
			c = getch();
		}
		else if(table == 2) {
			gotoxy(152 + strlen(ten) + 1, 24);
			c = getch();
		}
		else if(table == 3) {
			gotoxy(152 + strlen(phai) + 1, 27);
			c = getch();
		}
		else if(table == 4) {
			gotoxy(152 + strlen(mk) + 1, 30);
			c = getch();
		}
		else {
			c = getch();
		}
		
		if(c == Enter || c == Down) { 
			table++;
			SetColor(RED);
			if(table == 1) {
				if(strlen(masv) == 0) {
					gotoxy(133, 32);
					cout << "Chua nhap ma sinh vien !";
					table = 0;
					XoaThongBaoSV();
				} 
				else{
					if(KiemTraMaSVTrung(listlop, masv) == true) {
						gotoxy(133, 32);
						cout << "Ma sinh vien da bi trung. Xin nhap lai !";
						gotoxy(152, 18);
						cout << "                                           ";
						gotoxy(153, 18);
						Clear(masv);
						table = 0;
						j = 0; 
						XoaThongBaoSV();
					}
				}
			}
			else if(table == 2) {
				if(strlen(ho) == 0) {
					gotoxy(133, 32);
					cout << "Chua nhap ho !";
					table = 1;
					XoaThongBaoSV();
				} 
			}
			else if(table == 3) {
				if(strlen(ten) == 0) {
					gotoxy(133, 32);
					cout << "Chua nhap ten !";
					table = 2;
					XoaThongBaoSV();
				} 
			}
			else if(table == 4) {
				if(strlen(phai) == 0) {
					gotoxy(133, 32);
					cout << "Chua nhap phai !";
					table = 3;
					XoaThongBaoSV();
				} 
				else {
					if(stricmp(phai, "Nam") != 0 && stricmp(phai, "Nu") != 0){
						gotoxy(133, 32);
						cout << "Nhap sai. Moi nhap lai phai (nam/nu) !"; 
						gotoxy(152, 27);
						cout << "                                           ";
						gotoxy(153, 27);
						Clear(phai);
						table = 3;
						m = 0;
						XoaThongBaoSV();
					}
				}
			}
			else if(table == 5) {
				if(strlen(mkan) == 0) {
					gotoxy(133, 32);
					cout << "Chua nhap mat khau !";
					table = 4;
					XoaThongBaoSV();
				} 	
				else {
				gotoxy(133, 32);
				cout << "Ban co muon luu thong tin sinh vien khong ?";
				gotoxy(133, 33);
				cout << "F2: Co | F3: Khong";
				}
			}		
		}
		else if (c == 0){
	    	c = getch();
	    	if (c == 59) {
	    		hienmk = (hienmk + 1) % 2;
				if (hienmk != 0) {
					gotoxy(152 + 1, 30);
					SetColor(WHITE);
					cout << mk;
				} 
				else{
					if(table == 4) {
						gotoxy(152 + 1, 30);
						SetColor(WHITE);
						cout << mkan;
					}
				}
			}	
	    	else if(c == 60){ //phim F2
				XoaThongBaoSV();
	    		strcpy(sv.maSV,masv);
				strcpy(sv.ho,ho);
				strcpy(sv.ten,ten);
				strcpy(sv.phai,phai);
				strcpy(sv.password,mk);
				NODESV *p = KhoiTaoNODESV(sv);
				ThemVaoCuoiDSSV(listlop.nodeLop[chiso]->dssv, p);
				listlop.nodeLop[chiso]->dssv.slsv++;
				gotoxy(133, 32);
				SetColor(RED);
				cout << "Luu thanh cong !";
				ClearNhapSV(masv, ho, ten, phai, mk, mkan, j, k, l, m, n);
				gotoxy(153, 18);
				XoaThongBaoSV();
				table = 0;
				XoaDSSV();
				LietKeSV(listlop, chiso);
			}
			else if(c == 61) {
				XoaThongBaoSV();
				gotoxy(133, 32);
				SetColor(RED);
				cout << "Luu khong thanh cong !";
				XoaThongBaoSV();
				table = 0;
			}
		}
		else if (c == Up) table --;
		else if (c == Left || c == Right) _getch(); // phim len xuong
    	else if (c == ESC) {
    		VeKhung1Duong(130, 12, 24, 70, 0);
    		exit = true;
		}
    	else if (c == Backspace){ //backspace
			if (table == 0) XoaTungKyTu(masv, j, 152, 18);
			else if (table == 1) XoaTungKyTu(ho, k, 152, 21);
			else if (table == 2) XoaTungKyTu(ten, l, 152, 24);
			else if (table == 3) XoaTungKyTu(phai, m, 152, 27);
			else if (table == 4)
				if(strlen(mk) > 0) {
					gotoxy(152 + strlen(mk) + 1, 30);
       				cout << "\b \b";
       				BackSpace(mk);
       				BackSpace(mkan);
       				n--;
				}
		}
		else if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 32){
			if (table == 0 && c != 32 && j < 10) {
				InHoa(c);
				NhapChuoi(masv, c, j, 152, 18);
			}
			else if (table == 1 && ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 32)){
				if(k == 0 && c != 32) {
					InHoa(c);
					NhapChuoi(ho, c, k, 152, 21);
				} 
				else if(k > 0 && k < 19) {
					if(!(c == 32 && ho[k - 1] == 32)) {
						if(ho[k - 1] == 32)  InHoa(c);
						NhapChuoi(ho, c, k, 152, 21);
					} 
				}
			}
			else if (table == 2 && c != 32 && l < 9 && ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))) {
				if(l == 0) InHoa(c);
				NhapChuoi(ten, c, l, 152, 24);
			}
			else if (table == 3 && c != 32 && m < 3) {
				if(m == 0) InHoa(c);
				NhapChuoi(phai, c, m, 152, 27);
			}
			else if (table == 4 && c != 32 && n < 10){
				gotoxy(152, 30);
				SetColor(15);
				mk[n] = c;
				mk[n + 1] = '\0';
				mkan[n] = '*';
				mkan[n + 1] = '\0';
				gotoxy(152 + strlen(mkan), 30);
				if(hienmk == 0) cout << '*';
				else cout << c;
				n++;
			}
   		}
	} while(!exit);
}

bool KiemTraSVCoDiem(LISTLOP listlop, char masv[]) {
	for (int i = 0; i < listlop.n ; i++) {
		for(NODESV *p = listlop.nodeLop[i]->dssv.pHead; p != NULL; p = p->pNext)
			if(stricmp(p->sv.maSV, masv) == 0) 
				if(p->sv.dsd.sldiemthi != 0) return true;
	}
	return false;
}

void XoaSV(LISTLOP &listlop, int chiso) {
	bool exit = false;
	int i = 0, table = 0;
	char masv[11], c; masv[0]='\0';
	SetColor(WHITE);
	VeKhung1Duong(130, 16, 8, 60, WHITE);
	gotoxy(135, 18);
	cout << "Nhap ma sinh vien can xoa : ";
	VeKhung1Duong(162, 17, 3, 25, WHITE);
	
	do {
		gotoxy(165 + strlen(masv) + 1, 18);
		c = getch();
		if(c == Enter) {
			table++;
			if(table == 1) {
				SetColor(28);
				if(strlen(masv) == 0) {
					gotoxy(135, 21);
					cout << "Chua nhap ma sinh vien ! ";
					table = 0;
					Sleep(1000);
					gotoxy(135, 21);
					cout << "                                                  ";
				}
				else {
					if(KiemTraMaSVTrung(listlop, masv) == false) {
						gotoxy(135, 21);
						cout << "Ma sinh vien khong ton tai. Xin nhap lai !"; 
						Clear(masv);
						table = 0;
						Sleep(1000);
						gotoxy(165, 18);
						cout << "              ";
						gotoxy(135, 21);
						cout << "                                                  ";
						i = 0;
					}
					else if(KiemTraSVCoDiem(listlop, masv) == true) {
						gotoxy(135, 21);
						cout << "Sinh vien nay da thi. Khong duoc xoa. Xin nhap lai !"; 
						Clear(masv);
						table = 0;
						Sleep(1000);
						gotoxy(165, 18);
						cout << "              ";
						gotoxy(135, 21);
						cout << "                                                    ";
						i = 0;
					}
					else {
						gotoxy(135, 21);
						cout << "Ban co thuc su muon xoa sinh vien nay khong ?";
						gotoxy(135, 22);
						cout << "F2: Co | F3: Khong";
						
					}
				}
			}
		}
		else if (c == 0) {
			c = getch();
			if(c == 60){ //phim F2
				Sleep(1000);
				gotoxy(135, 21);
				cout << "                                                  ";
				gotoxy(135, 22);
				cout << "                            ";
				XoaSVBatKy(listlop.nodeLop[chiso]->dssv, masv);
				listlop.nodeLop[chiso]->dssv.slsv--;
				gotoxy(135, 21);
				SetColor(RED);
				cout << "Xoa thanh cong !";
				gotoxy(165, 18);
				cout << "              ";
				Clear(masv); i = 0;
				Sleep(1000);
				gotoxy(135, 21);
				cout << "                                                  ";
				table = 0;
				XoaDSSV();
				LietKeSV(listlop, chiso);
			}
			else if(c == 61) { //Phim F3
				Sleep(1000);
				gotoxy(135, 21);
				cout << "                                                  ";
				gotoxy(135, 22);
				cout << "                            ";
				gotoxy(135, 21);
				SetColor(RED);
				cout << "Xoa khong thanh cong !";
				Sleep(1000);
				gotoxy(135, 21);
				cout << "                                                  ";
				table = 0;
			}
		} 
		else if(c == ESC) {
			exit = true;
			VeKhung1Duong(130, 12, 13, 60, 0);
		}
		else if (c == Left || c == Right|| c == Up || c == Down) _getch();
    	else if (c == 8){ //backspace
       		if (table == 0)	 XoaTungKyTu(masv, i, 165, 18);
		}
		else if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
			if (table == 0 && i < 10) {
				InHoa(c);
				NhapChuoi(masv, c, i, 165, 18);
			}
   		}
	} while(!exit);
}

void ClearSuaSV(char ho[], char ten[], char phai[], char mk[], char mkan[], int &k, int &l, int &m, int &n) {
	Clear(ho); k = 0;
	Clear(ten); l = 0;
	Clear(phai); m = 0;
	Clear(mk); n = 0;
	Clear(mkan); 
	gotoxy(152, 21);
	cout << "                                           ";
	gotoxy(152, 24);
	cout << "                                           ";
	gotoxy(152, 27);
	cout << "                                           ";
	gotoxy(152, 30);
	cout << "                                           ";
}

void SuaSVBatKy(LISTLOP &listlop, int chiso, char masv[], char ho[], char ten[], char phai[], char mk[]) {
	for(NODESV *k = listlop.nodeLop[chiso]->dssv.pHead; k != NULL; k = k->pNext)
		if(stricmp(k->sv.maSV, masv) == 0) {
			strcpy(k->sv.ho, ho);
			strcpy(k->sv.ten, ten);
			strcpy(k->sv.phai, phai);
			strcpy(k->sv.password, mk);
		} 
}

void SuaThongTinSV(LISTLOP &listlop, int chiso, char masv[]) {
	char ho[30], ten[10], phai[4], mkan[11], mk[11];
	int table = 1, k = 0, l = 0, m = 0, n = 0, hienmk = 0;
	char c;
	bool exit = false;
	strcpy(masv, TimKiemSV(listlop, masv)->sv.maSV);
	strcpy(ho, TimKiemSV(listlop, masv)->sv.ho);
	strcpy(ten, TimKiemSV(listlop, masv)->sv.ten);
	strcpy(phai, TimKiemSV(listlop, masv)->sv.phai);
	strcpy(mk, TimKiemSV(listlop, masv)->sv.password);	
	strcpy(mkan, TimKiemSV(listlop, masv)->sv.password);	
	
	k = strlen(ho); l = strlen(ten); m = strlen(phai); n = strlen(mk); 
	VeKhung1Duong(130, 15, 21, 70, WHITE); //khung ngoai
	
	gotoxy(133, 18);
	cout << "Ma sinh vien : ";
	VeKhung1Duong(148, 17, 3, 50, WHITE);
	
	SetColor(RED);
	gotoxy(152 , 18);
	cout << masv;
	
	SetColor(WHITE);
	gotoxy(133, 21);
	cout << "Ho : ";
	VeKhung1Duong(148, 20, 3, 50, WHITE);
	gotoxy(152, 21); 
	cout << ho;
	
	gotoxy(133, 24);
	cout << "Ten : ";
	VeKhung1Duong(148, 23, 3, 50, WHITE);
	gotoxy(152, 24); 
	cout << ten;
	
	gotoxy(133, 27);
	cout << "Phai : ";
	VeKhung1Duong(148, 26, 3, 50, WHITE);
	gotoxy(152, 27); 
	cout << phai;
	
	gotoxy(133, 30);
	cout << "Password : ";
	VeKhung1Duong(148, 29, 3, 50, WHITE);
	gotoxy(152, 30); 
	cout << MaHoaPWD(mkan);
	
	do{
		if(table == 1) {
			gotoxy(152 + strlen(ho), 21);
			c = getch();
		}
		else if(table == 2) {
			gotoxy(152 + strlen(ten), 24);
			c = getch();
		}
		else if(table == 3) {
			gotoxy(152 + strlen(phai), 27);
			c = getch();
		}
		else if(table == 4) {
			gotoxy(152 + strlen(mk), 30);
			c = getch();
		}
		else {
			c = getch();
		}
		
		if(c == Enter || c == Down) { 
			table++;
			SetColor(RED);
			if(table == 2) {
				if(strlen(ho) == 0) {
					gotoxy(133, 32);
					cout << "Chua nhap ho !";
					table = 1;
					XoaThongBaoSV();
				} 
			}
			else if(table == 3) {
				if(strlen(ten) == 0) {
					gotoxy(133, 32);
					cout << "Chua nhap ten !";
					table = 2;
					XoaThongBaoSV();
				} 
			}
			else if(table == 4) {
				if(strlen(phai) == 0) {
					gotoxy(133, 32);
					cout << "Chua nhap phai !";
					table = 3;
					XoaThongBaoSV();
				} 
				else {
					if(stricmp(phai, "Nam") != 0 && stricmp(phai, "Nu") != 0){
						gotoxy(133, 32);
						cout << "Nhap sai. Moi nhap lai phai (nam/nu) !"; 
						gotoxy(152, 27);
						cout << "                                           ";
						gotoxy(153, 27);
						Clear(phai);
						table = 3;
						m = 0;
						XoaThongBaoSV();
					}
				}
			}
			else if(table == 5) {
				if(strlen(mkan) == 0) {
					gotoxy(133, 32);
					cout << "Chua nhap mat khau !";
					table = 4;
					XoaThongBaoSV();
				} 	
				else {
				gotoxy(133, 32);
				cout << "Ban co muon luu thong tin sinh vien khong ?";
				gotoxy(133, 33);
				cout << "F2: Co | F3: Khong";
				}
			}		
		}
		else if (c == 0){
	    	c = getch();
	    	if (c == 59) {
	    		hienmk = (hienmk + 1) % 2; //bang 0 la mkan
				if (hienmk != 0) {
					gotoxy(152, 30);
					SetColor(WHITE);
					cout << mk;
				} 
				else{
					if(table == 4) {
						gotoxy(152, 30);
						SetColor(WHITE);
						cout << mkan;
					}
				}
			}	
	    	else if(c == 60){ //phim F2
				XoaThongBaoSV();
				SuaSVBatKy(listlop, chiso, masv, ho, ten, phai, mk);
				gotoxy(133, 32);
				SetColor(RED);
				cout << "Sua thanh cong !";
				XoaThongBaoSV();
				XoaDSSV();
				ClearSuaSV(ho, ten, phai, mk, mkan, k, l, m, n);
				VeKhung1Duong(130, 15, 21, 70, 0);
				LietKeSV(listlop, chiso);
				SuaSV(listlop, chiso);
				break;
			}
			else if(c == 61) {
				XoaThongBaoSV();
				gotoxy(133, 32);
				SetColor(RED);
				cout << "Sua khong thanh cong !";
				XoaThongBaoSV();
				table = 1;
			}
		}
		else if (c == Up) table --;
		else if (c == Left || c == Right) _getch(); // phim len xuong
    	else if (c == ESC) {
    		VeKhung1Duong(130, 12, 24, 70, 0);
    		exit = true;
    		SuaSV(listlop, chiso);
		}
    	else if (c == Backspace){ //backspace
			if (table == 1) XoaTungKyTuCoSan(ho, k, 152, 21);
			else if (table == 2) XoaTungKyTuCoSan(ten, l, 152, 24);
			else if (table == 3) XoaTungKyTuCoSan(phai, m, 152, 27);
			else if (table == 4)
				if(strlen(mk) > 0) {
					gotoxy(152 + strlen(mk), 30);
       				cout << "\b \b";
       				BackSpace(mk);
       				BackSpace(mkan);
       				n--;
				}
		}
		else if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 32){
			if (table == 1 && ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 32)){
				if(k == 0 && c != 32) {
					InHoa(c);
					NhapChuoiCoSan(ho, c, k, 152, 21);
				} 
				else if(k > 0 && k < 19) {
					if(!(c == 32 && ho[k - 1] == 32)) {
						if(ho[k - 1] == 32)  InHoa(c);
						NhapChuoiCoSan(ho, c, k, 152, 21);
					} 
				}
			}
			else if (table == 2 && c != 32 && l < 9 && ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))) {
				if(l == 0) InHoa(c);
				NhapChuoiCoSan(ten, c, l, 152, 24);
			}
			else if (table == 3 && c != 32 && m < 3) {
				if(m == 0) InHoa(c);
				NhapChuoiCoSan(phai, c, m, 152, 27);
			}
			else if (table == 4 && c != 32 && n < 10){
				gotoxy(152, 30);
				SetColor(15);
				mk[n] = c;
				mk[n + 1] = '\0';
				mkan[n] = '*';
				mkan[n + 1] = '\0';
				gotoxy(152 + strlen(mkan) - 1, 30);
				if(hienmk == 0) {
					cout << '*';
				}
				else cout << c;
				n++;
			}
   		}
	} while(!exit);
}

void SuaSV(LISTLOP &listlop, int chiso){
	bool exit = false;
	int i = 0, table = 0;
	char masv[11], c; masv[0]='\0';
	SetColor(WHITE);
	VeKhung1Duong(130, 16, 8, 60, WHITE);
	gotoxy(135, 18);
	cout << "Nhap ma sinh vien can sua : ";
	VeKhung1Duong(162, 17, 3, 25, WHITE);
	
	do {
		gotoxy(165 + strlen(masv) + 1, 18);
		c = getch();
		if(c == Enter) {
			table++;
			if(table == 1) {
				SetColor(28);
				if(strlen(masv) == 0) {
					gotoxy(135, 21);
					cout << "Chua nhap ma sinh vien ! ";
					table = 0;
					Sleep(1000);
					gotoxy(135, 21);
					cout << "                                                  ";
				}
				else {
					if(KiemTraMaSVTrung(listlop, masv) == false) {
						gotoxy(135, 21);
						cout << "Ma sinh vien khong ton tai. Xin nhap lai !"; 
						Clear(masv);
						table = 0;
						Sleep(1000);
						gotoxy(165, 18);
						cout << "              ";
						gotoxy(135, 21);
						cout << "                                                  ";
						i = 0;
					}
					else {
						gotoxy(135, 21);
						cout << "Da tim thay sinh vien nay !";
						Sleep(1000);
						SuaThongTinSV(listlop, chiso, masv);
						break;
					}
				}
			}
		}
		else if(c == ESC) {
			exit = true;
			VeKhung1Duong(130, 12, 13, 60, 0);
		}
		else if (c == Left || c == Right|| c == Up || c == Down) _getch();
    	else if (c == 8){ //backspace
       		if (table == 0)	 XoaTungKyTu(masv, i, 165, 18);
		}
		else if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122) ){
			if (table == 0 && i < 10) {
				InHoa(c);
				NhapChuoi(masv, c, i, 165, 18);
			}
   		}
	} while(!exit);
}

void GiaoDienNhapSV(LISTLOP &listlop){
	bool exit = false;
	const int so_item = 3;
	const int x = 130;
	const int y = 39;
	const int rong = 3;
	const int dai = 13;
	int chon = 0, chiso = 0;
  	int i, dem = 0; 
  	char kytu;
  	
	VeKhung2Duong(80, 3 + 2, 3, 50, WHITE);
	gotoxy(80 + 15, 3 + 3);
	SetColor(RED);
	cout << "NHAP SINH VIEN CUA LOP";
	
	VeKhung1Duong(5, 12, 34, 120, WHITE); //khung danh sach
	VeDuongThang(6, 14, 118, 196, WHITE); //duong ngang giua
	VeDuongDoc(11, 13, 32, 179, WHITE);
	VeDuongDoc(30, 13, 32, 179, WHITE);
	VeDuongDoc(65, 13, 32, 179, WHITE);
	VeDuongDoc(83, 13, 32, 179, WHITE);
	VeDuongDoc(100, 13, 32, 179, WHITE);
	
	gotoxy(7, 13);
	cout << "STT";
	gotoxy(15, 13);
	cout << "Ma sinh vien";
	gotoxy(48, 13);
	cout << "Ho";
	gotoxy(73, 13);
	cout << "Ten";
	gotoxy(90, 13);
	cout << "Phai";
	gotoxy(108, 13);
	cout << "Password";

	string *item = new string[so_item];
	item[0] = " THEM";
	item[1] = " XOA";
	item[2] = " SUA";
		
	Normal();  
	
  	for (i = 0; i < so_item ; i++)
  	{ 
  		VeKhung1Duong(x + dem, y, rong, dai, WHITE);
		gotoxy(x + 4 + dem, y + 1);
		cout << item[i];
		dem+=28;
  	}

	VeKhung1Duong(x + chon, y, rong, dai, BROWN);
  	HighLight();
  	gotoxy(x + 4 + chon, y + 1);
  	cout << item[chon];
  	
  	dem = 0;
  	VeDuongThang(0, 47, 210, 196, DARKBLUE);
	VeDuongThang(0, 49, 210, 196, DARKBLUE);
	gotoxy(10, 48);
	SetColor(DARKBLUE);
	cout << "F1: An / hien mat khau (luc nhap)	|	Right: Sang phai	|	Left: Sang trai	|	ESC: Quay lai";
	chiso = NhapLopDSSV(listlop);
	LietKeSV(listlop, chiso);
	gotoxy(139, 39 + 1);
	
	do {
 		kytu = getch();
  		if(kytu == Enter) {
  			if(chon == 0) {
				NhapSV(listlop, chiso);
				gotoxy(139, 39 + 1);
			}
			else if(chon == 1) {
				XoaSV(listlop, chiso);
				gotoxy(166, 39 + 1);
			}
			else if(chon == 2) {
				SuaSV(listlop, chiso);
				gotoxy(194, 39 + 1);
			}
		}
		else if(kytu == ESC) {
			exit = true;
		}
  		switch (kytu) {
    	case Right :if (chon + 1 < so_item)
  			{
  		        	Normal();
  			  		VeKhung1Duong(x + dem, y, rong, dai, WHITE);
  			  		gotoxy(x + 4 + dem, y + 1);
					cout << item[chon];
					dem+=28;
              		chon ++;
              		HighLight();
              		VeKhung1Duong(x + dem, y, rong, dai, BROWN);
					gotoxy(x + 4 + dem, y + 1);
					cout << item[chon];
  			}
  			break;
  		case Left :if (chon + 1 > 1)
  			  {
  			  		Normal();
  			  		VeKhung1Duong(x + dem, y, rong, dai, WHITE);
  			  		gotoxy(x + 4 + dem, y + 1);
					cout << item[chon];
					dem-=28;
              		chon --;
              		HighLight();
              		VeKhung1Duong(x + dem, y, rong, dai, BROWN);
					gotoxy(x + 4 + dem, y + 1);
					cout << item[chon];
  			  }
  			  break;
  		}  
  } while (!exit);	
}

///////////////////////////////CAY NHI PHAN MON HOC///////////////////////////////////

void KhoiTaoCay(TREE &t)
{
	t = NULL;
}

// ham them 1 cai node vao cay nhi phan tim kiem
void ThemNodeMH(TREE &t, MONHOC mh)
{
	// cay dang rong
	if (t == NULL)
	{
		NODEMH *p = new NODEMH;
		p->monhoc = mh;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p; // thang them vao cung chinh la node goc
	}
	else
	{
		if (stricmp(mh.maMH, t->monhoc.maMH) < 0)
		{
			ThemNodeMH(t->pLeft, mh);
		}
		else if (stricmp(mh.maMH, t->monhoc.maMH) > 0)
		{
			ThemNodeMH(t->pRight, mh);
		}
	}
}

// duyet theo NLR
void NLRThi(TREE t, int &dem)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		dem++;
		SetColor(WHITE);
		gotoxy(18, 14 + dem);
		cout << dem;
		gotoxy(25, 14 + dem);
		cout << t->monhoc.maMH;
		gotoxy(60, 14 + dem);
		cout << t->monhoc.tenMH;
		NLRThi(t->pLeft, dem);	
		NLRThi(t->pRight, dem);
	}
}

// duyet cay theo NRL
void NRL(TREE t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		cout << t->monhoc.maMH << "  " << endl;
		cout << t->monhoc.tenMH << "  " << endl;
		NRL(t->pRight);
		NRL(t->pLeft);
	}
}

// duyet cay theo LNR
void LNR(TREE t, int &dem)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		dem++;
		SetColor(WHITE);
		LNR(t->pLeft, dem);
		gotoxy(18, 14 + dem);
		cout << dem;
		gotoxy(25, 14 + dem);
		cout << t->monhoc.maMH;
		gotoxy(70, 14 + dem);
		cout << t->monhoc.tenMH;
		LNR(t->pRight, dem);
	}
}

void NLR(TREE t, int &dem)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		dem++;
		SetColor(WHITE);
		gotoxy(18, 14 + dem);
		cout << dem;
		gotoxy(25, 14 + dem);
		cout << t->monhoc.maMH;
		gotoxy(70, 14 + dem);
		cout << t->monhoc.tenMH;
		NLR(t->pLeft, dem);	
		NLR(t->pRight, dem);
	}
}

// duyet cay theo LRN
void LRN(TREE t, int &dem)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		LRN(t->pLeft, dem);		
		LRN(t->pRight, dem);
		SetColor(WHITE);
		gotoxy(18, 16 + dem);
		cout << dem + 1;
		gotoxy(25, 16 + dem);
		cout << t->monhoc.maMH;
		gotoxy(70, 16 + dem);
		cout << t->monhoc.tenMH;
		dem++;
	}
}

// duyet cay theo RLN
void RLN(TREE t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		RLN(t->pRight);
		RLN(t->pLeft);
		cout << t->monhoc.maMH << "  " << endl;
		cout << t->monhoc.tenMH << "  " << endl;
	}
}

NODEMH* TimKiemMH (TREE t, char mamh[]) {
	NODEMH *p;
	p = t; // p la nut goc
	while(p != NULL && stricmp(p->monhoc.maMH, mamh) != 0) {
		if(stricmp(p->monhoc.maMH, mamh) > 0) p = p->pLeft;
		else p = p->pRight;
	}
	return p; //tra ve NULL la khong tim thay
}

bool KiemTraMaMHTrung(TREE t, char ma[]) {
	if(t == NULL) {
		return false;
	}
	else {
		if(TimKiemMH(t, ma) != NULL) return true;  // trung
	} 
	return false;
}
bool KiemTraMaMHFile(char mamh[]) {
	TREE t;
	KhoiTaoCay(t);
	
	DocFileMH(t);
	if(KiemTraMaMHTrung(t, mamh) == true) return true;
	return false;
}
bool KiemTraDSMHRong(TREE t) {
	if(t == NULL) {
		return true;
	}
	return false;
}

void TimNodeTheMangMH(TREE &x, TREE &y) {
	if(y->pLeft != NULL) {
		TimNodeTheMangMH(x, y->pLeft);
	}
	else {
		x->monhoc = y->monhoc;
		x = y;
		y = y->pRight;
	}
}

void XoaMHBatKy (TREE &t, char ma[]) {
	if(t == NULL) {
		return;
	}
	else {
		if(stricmp(ma, t->monhoc.maMH) < 0) { //neu t->monhoc.maMH nho hon ma
			XoaMHBatKy(t->pLeft, ma);
		}
		else if(stricmp(ma, t->monhoc.maMH) > 0) {
			XoaMHBatKy(t->pRight, ma);
		}
		else { // ma mh trug
			NODEMH *X = t; // node X la node the mang
			if(t->pRight == NULL) {
				t = t->pLeft;
			}
			else if(t->pLeft == NULL) { //neu nhanh phai bang null -> la cay con phai
				t = t->pRight;
			}
			else TimNodeTheMangMH(X, t->pRight);
			delete X;
		}
	}
}
 


void ChoVaoMang(TREE t, MONHOC a[], int &somh) {
	if(t == NULL) {
		return;
	}
	else {
		ChoVaoMang(t->pLeft, a, somh);
		ChoVaoMang(t->pRight, a, somh);
		a[somh] = t->monhoc;
		somh++;		
	}
}

void XoaThongBaoMH() {
	Sleep(1000);
	gotoxy(135, 21);
	cout << "                                                  ";
	gotoxy(135, 22);
	cout << "                            ";
}

void NhapMH(TREE &t) {
	MONHOC mh;
	char mamh[10], tenmh[40], c;
	int table = 0, i = 0, j = 0, count = 0;;
	mamh[0]='\0'; tenmh[0]='\0';
	bool exit = false;
	VeKhung1Duong(130, 12, 13, 60, WHITE); // khung nhap
	
	gotoxy(135, 15);
	cout << "Ma mon hoc : ";
	VeKhung1Duong(150, 14, 3, 35, WHITE);
	
	gotoxy(135, 18);
	cout << "Ten mon hoc : ";
	VeKhung1Duong(150, 17, 3, 35, WHITE);
	
	do{
		if(table == 0) {
			gotoxy(152 + strlen(mamh) + 1, 15); 
			c = getch();
		}
		else if(table == 1) {
			gotoxy(152 + strlen(tenmh) + 1, 18);
			c = getch();
		}
		else {
			c = getch();
		}		
		
		if(c == Enter || c == Down) {
			table++;
			if(table == 1) {
				SetColor(28);
				if(strlen(mamh) == 0) {
					gotoxy(135, 21);
					cout << "Chua nhap ma mon hoc ! ";
					table = 0;
					XoaThongBaoMH();
				}
				else if(KiemTraMaMHTrung(t, mamh) == true) {
					gotoxy(135, 21);
					cout << "Ma mon hoc da bi trung. Xin nhap lai !"; 
					Clear(mamh); i = 0;
					table = 0;
					Sleep(1000);
					gotoxy(152, 15);
					cout << "                           ";
					gotoxy(153, 15);
					XoaThongBaoMH();
				}
			}
			else if(table == 2) {
				SetColor(28);
				if(strlen(tenmh) == 0) {
					gotoxy(135, 21);
					cout << "Chua nhap ten mon hoc ! ";
					table = 1;
					XoaThongBaoMH();
				}
				else {
					gotoxy(135, 21);
					cout << "Ban co muon luu thong tin mon hoc khong ?";
					gotoxy(135, 22);
					cout << "F2: Co | F3: Khong";
				}
			}
		}
		else if (c == 0) {
			c = getch();
			if(c == 60){ //phim F2
//	    		Chuan_Hoa(tenmh);
				XoaThongBaoMH();
	    		strcpy(mh.maMH, mamh);
				strcpy(mh.tenMH, tenmh);
				ThemNodeMH(t, mh);
				gotoxy(135, 21);
				SetColor(RED);
				cout << "Luu thanh cong !";
				gotoxy(152, 15);
				cout << "                           ";
				gotoxy(152, 18);
				cout << "                           ";
				gotoxy(153, 15);
				Clear(mamh); i = 0;
				Clear(tenmh); j = 0;
				XoaThongBaoMH();
				XoaDSLOP();
				table = 0;
				NLR(t, count);
				count = 0;
			}
			else if(c == 61) { //Phim F3
				XoaThongBaoMH();
				gotoxy(135, 21);
				SetColor(RED);
				cout << "Luu khong thanh cong !";
				table = 0;
				XoaThongBaoMH();
			}
		} 
		else if(c == ESC) {
			VeKhung1Duong(130, 12, 13, 60, 0);
			exit = true;
		}
		else if (c == 9)	table = (table + 1) % 2;
		else if (c == Up) table = 0;
		else if (c == Left || c == Right) _getch();
    	else if (c == 8){ //backspace
       		if (table == 0)	XoaTungKyTu(mamh, i, 152, 15); 
			else if (table == 1) XoaTungKyTu(tenmh, j, 152, 18); 
		}
		else if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 32){
			if (table == 0 && c != 32 && i < 9) {
				InHoa(c);
				NhapChuoi(mamh, c, i, 152, 15); 
			}
			else if (table == 1){
				if(j == 0 && c != 32) {
					InHoa(c);
					NhapChuoi(tenmh, c, j, 152, 18);
				} 
				else if(j > 0 && j < 39) {
					if(!(c == 32 && tenmh[j - 1] == 32)) NhapChuoi(tenmh, c, j, 152, 18);  
				}
			}
   		}
	} while(!exit);
}

void XoaMH(TREE &t, LISTCAUHOI listch) {
	bool exit = false;
	int i = 0, table = 0, count = 0;;
	char c;
	char mamh[10]; mamh[0]='\0';
	SetColor(WHITE);
	VeKhung1Duong(130, 16, 8, 65, WHITE);
	gotoxy(135, 18);
	cout << "Nhap ma mon hoc can xoa : ";
	VeKhung1Duong(162, 17, 3, 25, WHITE);
	
	do {
		gotoxy(165 + strlen(mamh) + 1, 18);
		c = getch();
		if(c == Enter) {
			table++;
			if(table == 1) {
				SetColor(28);
				if(strlen(mamh) == 0) {
					gotoxy(135, 21);
					cout << "Chua nhap ma mon hoc ! ";
					table = 0;
					Sleep(1000);
					gotoxy(135, 21);
					cout << "                                                  ";
				}
				else {
					if(KiemTraDSMHRong(t) == true) {
						gotoxy(135, 21);
						cout << "Danh sach rong !";
						Sleep(1000);
						VeKhung1Duong(130, 12, 13, 60, 0);
						break;
					}
					else if(TimKiemMH(t, mamh) == NULL) {
						gotoxy(135, 21);
						cout << "Ma mon hoc khong ton tai. Xin nhap lai !"; 
						Clear(mamh);
						table = 0;
						Sleep(1000);
						gotoxy(165, 18);
						cout << "                     ";
						gotoxy(135, 21);
						cout << "                                                          ";
						i = 0;
					}
					else if(KiemTraMonHocTrongCauHoi(listch, mamh) == true) {
						gotoxy(135, 21);
						cout << "Mon hoc nay da co cau hoi. Khong duoc xoa. Xin nhap lai !"; 
						Clear(mamh);
						table = 0;
						Sleep(1000);
						gotoxy(165, 18);
						cout << "                     ";
						gotoxy(135, 21);
						cout << "                                                         ";
						i = 0;
					}
					else{
						gotoxy(135, 21);
						cout << "Ban co thuc su muon xoa mon hoc khong ?";
						gotoxy(135, 22);
						cout << "F2: Co | F3: Khong";
					}
				}
			}
		}
		else if (c == 0) {
			c = getch();
			if(c == 60){ //phim F2
				Sleep(1000);
				gotoxy(135, 21);
				cout << "                                                  ";
				gotoxy(135, 22);
				cout << "                            ";
				XoaMHBatKy(t, mamh);
				gotoxy(135, 21);
				SetColor(RED);
				cout << "Xoa thanh cong !";
				gotoxy(165, 18);
				cout << "              ";
				gotoxy(166, 18);
				Clear(mamh); i = 0;
				Sleep(1000);
				gotoxy(135, 21);
				cout << "                                ";
				table = 0;
				XoaDSLOP();
				NLR(t, count);
				count = 0;
			}
			else if(c == 61) { //Phim F3
				Sleep(1000);
				gotoxy(135, 21);
				cout << "                                           ";
				gotoxy(135, 22);
				cout << "                            ";
				gotoxy(135, 21);
				SetColor(RED);
				cout << "Xoa khong thanh cong !";
				Sleep(1000);
				gotoxy(135, 21);
				cout << "                                      ";
				gotoxy(166, 18);
				table = 0;
			}
		} 
		else if(c == ESC) {
			exit = true;
			VeKhung1Duong(130, 12, 13, 65, 0);
		}
		else if (c == Left || c == Right|| c == Up || c == Down) _getch();
    	else if (c == 8){ //backspace
       		if (table == 0) XoaTungKyTu(mamh, i, 165, 18); 
		}
		else if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
			if (table == 0 && i < 9) {
				InHoa(c);
				NhapChuoi(mamh, c, i, 165, 18);
			}
   		}
	} while(!exit);
}

void SuaMHBatKy(TREE &t, char mamh[], char tenmh[]) {
	NODEMH *p;
	p = t; // p la nut goc
	while(p != NULL && stricmp(p->monhoc.maMH, mamh) != 0) {
		if(stricmp(p->monhoc.maMH, mamh) > 0) p = p->pLeft;
		else p = p->pRight;
	}
	if(stricmp(p->monhoc.maMH, mamh) == 0) strcpy(p->monhoc.tenMH, tenmh);
}

void LayTenMH(TREE &t, char mamh[], char tenmh[]) {
	NODEMH *p;
	p = t; 
	while(p != NULL && stricmp(p->monhoc.maMH, mamh) != 0) {
		if(stricmp(p->monhoc.maMH, mamh) > 0) p = p->pLeft;
		else p = p->pRight;
	}
	if(stricmp(p->monhoc.maMH, mamh) == 0) strcpy(tenmh, p->monhoc.tenMH);
}

void SuaThongTinMH(TREE &t, char ma[], char c) {
	char tenmh[40];
	tenmh[0] = '\0';
	LayTenMH(t, ma, tenmh);
	int table = 1, count = 0, i = 0, j = strlen(tenmh);
	bool exit = false;
	VeKhung1Duong(130, 12, 13, 60, WHITE); // khung nhap
	
	gotoxy(135, 15);
	cout << "Ma mon hoc : ";
	VeKhung1Duong(150, 14, 3, 35, WHITE);
	SetColor(RED);
	gotoxy(152 , 15); 
	cout << ma;
	
	SetColor(WHITE);
	gotoxy(135, 18);
	cout << "Ten mon hoc : ";
	VeKhung1Duong(150, 17, 3, 35, WHITE);
	
	do{
		if(table == 1) {
			gotoxy(152, 18); 
			cout << tenmh;
			gotoxy(152 + strlen(tenmh), 18);
			c = getch();
		}
		else {
			c = getch();
		}		
		
		if(c == Enter) {
			table++;
			if(table == 2) {
				SetColor(28);
				if(strlen(tenmh) == 0) {
					gotoxy(135, 21);
					cout << "Chua nhap ten mon hoc ! ";
					table = 1;
					XoaThongBaoMH();
				}
				else {
					gotoxy(135, 21);
					cout << "Ban co muon sua thong tin mon hoc khong ?";
					gotoxy(135, 22);
					cout << "F2: Co | F3: Khong";
				}
			}
		}
		else if (c == 0) {
			c = getch();
			if(c == 60){ //phim F2
				XoaThongBaoMH();
				SuaMHBatKy(t, ma, tenmh);
				gotoxy(135, 21);
				SetColor(RED);
				cout << "Sua thanh cong !";
				gotoxy(152, 15);
				cout << "                           ";
				gotoxy(152, 18);
				cout << "                           ";
				Clear(tenmh); j = 0;
				XoaThongBaoMH();
				VeKhung1Duong(130, 12, 13, 60, 0);
				XoaDSLOP();
				NLR(t, count);	
				SuaMH(t);
				break;
			}
			else if(c == 61) { //Phim F3
				XoaThongBaoMH();
				gotoxy(135, 21);
				SetColor(RED);
				cout << "Sua khong thanh cong !";
				XoaThongBaoMH();
				SetColor(WHITE);
				table = 1;
				gotoxy(153, 18);
			}
		} 
		else if(c == ESC) {
			VeKhung1Duong(130, 12, 13, 60, 0);
			exit = true;
			SuaMH(t);
		}
		else if (c == Left || c == Right|| c == Up|| c == Down) _getch();
    	else if (c == 8){ //backspace
			if (table == 1) XoaTungKyTuCoSan(tenmh, j, 152, 18);
		}
		else if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 32){
			if (table == 1){
				if(j == 0 && c != 32) {
					InHoa(c);
					NhapChuoiCoSan(tenmh, c, j, 152, 18);
				} 
				else if(j > 0 && j < 39) {
					if(!(c == 32 && tenmh[j - 1] == 32)) NhapChuoiCoSan(tenmh, c, j, 152, 18);  
				}
			}
   		}
	} while(!exit);
}

void SuaMH(TREE &t) {
	bool exit = false;
	int i = 0, table = 0;
	char mamh[10], c; mamh[0]='\0';
	SetColor(WHITE);
	VeKhung1Duong(130, 16, 8, 60, WHITE);
	gotoxy(135, 18);
	cout << "Nhap ma mon hoc can sua : ";
	VeKhung1Duong(162, 17, 3, 25, WHITE);
	
	do {
		gotoxy(165 + strlen(mamh) + 1, 18);
		c = getch();
		if(c == Enter) {
			table++;
			if(table == 1) {
				SetColor(28);
				if(strlen(mamh) == 0) {
					gotoxy(135, 21);
					cout << "Chua nhap ma mon hoc ! ";
					table = 0;
					Sleep(1000);
					gotoxy(135, 21);
					cout << "                                                  ";
				}
				else {
					if(KiemTraDSMHRong(t) == true) {
						gotoxy(135, 21);
						cout << "Danh sach rong !";
						Sleep(1000);
						VeKhung1Duong(130, 12, 13, 60, 0);
						break;
					}
					else if(KiemTraMaMHTrung(t, mamh) == false) {
						gotoxy(135, 21);
						cout << "Ma mon hoc khong ton tai. Xin nhap lai !"; 
						Clear(mamh);
						table = 0;
						Sleep(1000);
						gotoxy(165, 18);
						cout << "              ";
						gotoxy(135, 21);
						cout << "                                                  ";
						i = 0;
					}
					else if(KiemTraMaMHTrung(t, mamh) == true){
						gotoxy(135, 21);
						cout << "Tim ma mon hoc thanh cong !"; 
						Sleep(1000);
						SuaThongTinMH(t, mamh, c);
						break;
					}
				}
			}
		} 
		else if(c == ESC) {
			VeKhung1Duong(130, 12, 13, 60, 0);
			exit = true;
		}
		else if (c == Left || c == Right|| c == Up || c == Down) _getch();
    	else if (c == 8){ //backspace
       		if (table == 0)	 XoaTungKyTu(mamh, i, 165, 18); 
		}
		else if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122) ){
			if (table == 0 && i < 9) {
				InHoa(c);
				NhapChuoi(mamh, c, i, 165, 18);
			}
   		}
	} while(!exit);
}

void GiaoDienNhapMH(TREE &t, LISTCAUHOI listch) {
	const int so_item = 3;
	const int x = 130;
	const int y = 27;
	const int rong = 3;
	const int dai = 12;
	string *item = new string[so_item];
	int chon = 0;
  	int i, dem = 0; 
  	bool exit = false;
  	char kytu;
  	
	VeKhung2Duong(80, 3 + 3, 3, 50, WHITE);
	gotoxy(80 + 15, 3 + 1 + 3);
	SetColor(RED);
	cout << "    NHAP MON HOC";
	
	VeKhung1Duong(15, 12, 34, 100, WHITE); //khung danh sach
	VeDuongThang(16, 14, 98, 196, WHITE); //duong ngang giua
	VeDuongDoc(21, 13, 32, 179, WHITE);
	VeDuongDoc(60, 13, 32, 179, WHITE);
	
	gotoxy(17, 13);
	cout << "STT";
	
	gotoxy(35, 13);
	cout << "Ma mon hoc";
	
	gotoxy(80, 13);
	cout << "Ten mon hoc";

	item[0] = "THEM";
	item[1] = "XOA";
	item[2] = "SUA";
		
	Normal();  
	
  	for (i = 0; i< so_item ; i++)
  	{ 
  		VeKhung1Duong(x + dem, y, rong, dai, WHITE);
		gotoxy(x + 4 + dem, y + 1);
		cout << item[i];
		dem+=24;
  	}

	VeKhung1Duong(x + chon, y, rong, dai, BROWN);
  	HighLight();
  	gotoxy(x + 4 + chon, y + 1);
  	cout << item[chon];
  	dem = 0;
  	VeDuongThang(0, 47, 210, 196, DARKBLUE);
	VeDuongThang(0, 49, 210, 196, DARKBLUE);
	gotoxy(10, 48);
	SetColor(DARKBLUE);
	cout << "Right: Sang phai          |         Left: Sang trai         |         ESC: Quay lai"; 
	int count = 0;
	NLR(t, count);
	
	do {

 		kytu = getch();
  		if (kytu == 0) kytu = getch();
  		else if(kytu == Enter) {
  			if(chon == 0) {
				NhapMH(t);
				gotoxy(130 + 8 , 27 + 1);
			}
			if(chon == 1) {
				XoaMH(t, listch);
				gotoxy(130 + 31, 27 + 1);
			}
			if(chon == 2) {
				SuaMH(t);
				gotoxy(130 + 55, 27 + 1);
			}
		}
		else if (kytu == ESC) {
			exit = true;
		}
  		switch (kytu) {
    	case Right :if (chon + 1 < so_item)
  			{
  		        	Normal();
  			  		VeKhung1Duong(x + dem, y, rong, dai, WHITE);
  			  		gotoxy(x + 4 + dem, y + 1);
					cout << item[chon];
					dem+=24;
              		chon ++;
              		HighLight();
              		VeKhung1Duong(x + dem, y, rong, dai, BROWN);
					gotoxy(x + 4 + dem, y + 1);
					cout << item[chon];
  			}
  			break;
  		case Left :if (chon + 1 > 1)
  			{
  			  		Normal();
  			  		VeKhung1Duong(x + dem, y, rong, dai, WHITE);
  			  		gotoxy(x + 4 + dem, y + 1);
					cout << item[chon];
					dem-=24;
              		chon --;
              		HighLight();
              		VeKhung1Duong(x + dem, y, rong, dai, BROWN);
					gotoxy(x + 4 + dem, y + 1);
					cout << item[chon];
  			  }
  			  break;
  		}  
  		
  } while (!exit);
}

/////////////////////////////////DANH SACH LIEN KET DON DIEM//////////////////////////////////

void KhoiTaoDIEM(LISTDIEM &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

NODEDIEM *KhoiTaoNODEDIEM(DIEMTHI x) {
	NODEDIEM *p = new NODEDIEM; //cap phat vung nho	 cho node p
	if(p == NULL) {
		return NULL;
	}
	p->dt = x;
	p->pNext = NULL;
	return p;
}

//khoi tao 1 node
void ThemVaoDauDSDIEM(LISTDIEM &l, NODEDIEM *p) {
	if(l.pHead == NULL) { //danh sach dang rong
		l.pHead = l.pTail = p; // node dau node cuoi la p
	}
	else{
		p->pNext = l.pHead; //cho con tro can them la node p lien ket voi pHead	
		l.pHead = p; //cap nhat lai pHead la node p
	}
}

void ThemVaoCuoiDSDIEM(LISTDIEM &l, NODEDIEM *p) {
	p->dt.dschthi.pHead = NULL;
	if(l.pHead == NULL) { //danh sach dang rong
		l.pHead = l.pTail = p; // node dau node cuoi la p
	}
	else{
		l.pTail->pNext = p; //cho con tro pTail lien ket voi node p
		l.pTail = p; //cap nhat lai p la pTail
	}
}

/////////////////////////////////DANH SACH LIEN KET DON CAU HOI THI//////////////////////////////////

void KhoiTaoCH(LISTCH &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

NODECH *KhoiTaoNODECHTHI(CH x) {
	NODECH *p = new NODECH; //cap phat vung nho	 cho node p
	if(p == NULL) {
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->ch = x;
	p->pNext = NULL;
	return p;
}

void ThemVaoCuoiDSCHTHI(LISTCH &l, NODECH *p) {
	if(l.pHead == NULL) { //danh sach dang rong
		l.pHead = l.pTail = p; // node dau node cuoi la p
	}
	else{
		l.pTail->pNext = p; //cho con tro pTail lien ket voi node p
		l.pTail = p; //cap nhat lai p la pTail
	}
}

////////////////////////////////DANH SACH MANG CON TRO CAU HOI////////////////////////////////

void InsertOrderCauHoi (LISTCAUHOI &list, CAUHOI ch){
	int j, k;
	for (j = 0; j < list.n && list.nodeCauHoi[j]->id < ch.id; j++);
	for (k = list.n-1; k >= j; k--) 
		list.nodeCauHoi[k+1] = list.nodeCauHoi[k];
	list.nodeCauHoi[j]= new CauHoi;
	*list.nodeCauHoi[j]=ch; list.n++;
}

void LietKeCauHoi (LISTCAUHOI list) {
	 for (int i = 0 ; i < list.n; i++)
	 {
	 	SetColor(WHITE);
	 	gotoxy(18, 15 + i);
	 	cout << i + 1;
	 	gotoxy(24, 15 + i);
	 	cout << list.nodeCauHoi[i]->id;
	 	gotoxy(32, 15 + i);
	 	cout << list.nodeCauHoi[i]->maMH;
	 	gotoxy(46, 15 + i);
		cout << list.nodeCauHoi[i]->noiDung;
		gotoxy(112, 15 + i);
		cout << list.nodeCauHoi[i]->A;
		gotoxy(132, 15 + i);
		cout << list.nodeCauHoi[i]->B;
		gotoxy(152, 15 + i);
		cout << list.nodeCauHoi[i]->C;
		gotoxy(172, 15 + i);
		cout << list.nodeCauHoi[i]->D;
		gotoxy(194, 15 + i);
		cout << list.nodeCauHoi[i]->dapAn;
	 }
}

int SoLuongCHTheoMH(LISTCAUHOI listch, char mamh[]) {
	int soluong = 0;
	for (int i = 0; i < listch.n; i++) 
		if(stricmp(listch.nodeCauHoi[i]->maMH, mamh) == 0) soluong++;
	return soluong;
}

void DSCauHoiTheoMH(LISTCAUHOI listch, CH dsch[], char mamh[]) {
	int j = 1;
	for(int i = 0; i < listch.n; i++) 
		if(stricmp(listch.nodeCauHoi[i]->maMH, mamh) == 0) {
			dsch[j].id = listch.nodeCauHoi[i]->id;
			dsch[j].chiso = i;
			j++;
		}
}

int TimKiemCauHoi(LISTCAUHOI &list, int x) {
  for (int i =0; i < list.n ; i++)
     if (list.nodeCauHoi[i]->id == x) return i; // kiem ra
  return -1;
}

void XoaCauHoiBatKy(LISTCAUHOI &list, int id){
	int i = TimKiemCauHoi(list, id) ;
	delete  list.nodeCauHoi[i];
    for (int j = i + 1; j < list.n; j++)
     	list.nodeCauHoi[j-1] = list.nodeCauHoi[j];
    list.n--;  
}

Xoa_Thong_BaoCH() {
	Sleep(1000);
	gotoxy(75, 38);
	cout << "                                             ";
	gotoxy(75, 39);
	cout << "                   ";
}

void ClearNhapCH(char mamh[], char noidung[], char A[], char B[], char C[], char D[], char dapan[], int &i, int &j, int &k, int &l, int &m, int &n, int &e) {
	Clear(mamh); i = 0;
	Clear(noidung); j = 0;
	Clear(A); k = 0;
	Clear(B); l = 0;
	Clear(C); m = 0;
	Clear(D); n = 0;
	Clear(dapan); e = 0;
	gotoxy(80, 18);  
	cout << "                                                                  ";
	gotoxy(80, 21);
	cout << "                                                                  ";
	gotoxy(80, 24);
	cout << "                                                                  ";
	gotoxy(80, 27);
	cout << "                                                                  ";
	gotoxy(80, 30);
	cout << "                                                                  ";
	gotoxy(80, 33);
	cout << "                                                                  ";
	gotoxy(80, 36);
	cout << "                                                                  ";
}

int TimIDMax(LISTCAUHOI &list) {
	int max = 0;
  	for(int i = 0; i < list.n; i++) 
		if(max < list.nodeCauHoi[i]->id) {
			max = list.nodeCauHoi[i]->id;
		}
	return max;
}

int NhapCauHoi(TREE t, LISTCAUHOI &list) {
	CAUHOI ch;
	char mamh[10], noidung[61], A[18], B[18], C[18], D[18], dapan[2];
	int table = 1, dem = 0, i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, e = 0, id;
	char kytu;
	mamh[0]='\0'; noidung[0]='\0'; A[0]='\0'; B[0]='\0'; C[0]='\0'; D[0]='\0'; dapan[0]='\0';
	
	system("cls");
	VeKhung2Duong(80, 3 + 2, 3, 50, WHITE);
	gotoxy(80 + 15, 3 + 3);
	SetColor(RED);
	cout << "     NHAP CAU HOI";
	VeKhung1Duong(55, 12, 30, 100, WHITE); //khung ngoai
	
	gotoxy(60, 15);
	cout << "ID : ";
	VeKhung1Duong(75, 14, 3, 75, WHITE);
	
	gotoxy(60, 18);
	cout << "Ma mon hoc : ";
	VeKhung1Duong(75, 17, 3, 75, WHITE);
	
	gotoxy(60, 21);
	cout << "Noi dung : ";
	VeKhung1Duong(75, 20, 3, 75, WHITE);
	
	gotoxy(60, 24);
	cout << "Lua chon A : ";
	VeKhung1Duong(75, 23, 3, 75, WHITE);
	
	gotoxy(60, 27);
	cout << "Lua chon B : ";
	VeKhung1Duong(75, 26, 3, 75, WHITE);
	
	gotoxy(60, 30);
	cout << "Lua chon C : ";
	VeKhung1Duong(75, 29, 3, 75, WHITE);
	
	gotoxy(60, 33);
	cout << "Lua chon D : ";
	VeKhung1Duong(75, 32, 3, 75, WHITE);
	
	gotoxy(60, 36);
	cout << "Dap an (A->D): ";
	VeKhung1Duong(75, 35, 3, 75, WHITE);
	
	VeDuongThang(0, 47, 210, 196, DARKBLUE);
	VeDuongThang(0, 49, 210, 196, DARKBLUE);
	gotoxy(10, 48);
	SetColor(DARKBLUE);
	cout << "Down: Xuong   |   Up: Len   |   ESC: Quay lai";
	
	SetColor(RED);
	gotoxy(80, 15);
	id = TimIDMax(list) + 1;
	cout << id;
	
	do{
		if(table == 1) {
			gotoxy(80 + strlen(mamh) + 1, 18);
			kytu = getch();
		}
		else if(table == 2) {
			gotoxy(80 + strlen(noidung) + 1, 21);
			kytu = getch();
		}
		else if(table == 3) {
			gotoxy(80 + strlen(A) + 1, 24);
			kytu = getch();
		}
		else if(table == 4) {
			gotoxy(80 + strlen(B) + 1, 27);
			kytu = getch();
		}else if(table == 5) {
			gotoxy(80 + strlen(C) + 1, 30);
			kytu = getch();
		}else if(table == 6) {
			gotoxy(80 + strlen(D) + 1, 33);
			kytu = getch();
		}else if(table == 7) {
			gotoxy(80 + strlen(dapan) + 1, 36);
			kytu = getch();
		}
		else {
			kytu = getch();
		}
		
		if(kytu == Enter || kytu == Down) { 
			table++;
			SetColor(RED);
			if(table == 2) {
				if(strlen(mamh) == 0) {
					gotoxy(75, 38);
					cout << "Chua nhap ma mon hoc !";
					table = 1;
					Xoa_Thong_BaoCH();
				} 
				else {
					if(KiemTraMaMHTrung(t, mamh) == false) {
					gotoxy(75, 38);
					cout << "Ma mon hoc khong ton tai. Vui long nhap lai !";
					Clear(mamh);
					i = 0;
					gotoxy(80, 18);
					cout << "                                                ";
					table = 1;
					Xoa_Thong_BaoCH();
					}
				}
			}
			else if(table == 3 && strlen(noidung) == 0) {
				gotoxy(75, 38);
				cout << "Chua nhap noi dung cau hoi !";
				table = 2;
				Xoa_Thong_BaoCH();
			}
			else if(table == 4 && strlen(A) == 0) {
				gotoxy(75, 38);
				cout << "Chua nhap lua chon A !";
				table = 3;
				Xoa_Thong_BaoCH();
			}
			else if(table == 5 && strlen(B) == 0) {
				gotoxy(75, 38);
				cout << "Chua nhap lua chon B !";
				table = 4;
				Xoa_Thong_BaoCH();
			}
			else if(table == 6 && strlen(C) == 0) {
				gotoxy(75, 38);
				cout << "Chua nhap lua chon C !";
				table = 5;
				Xoa_Thong_BaoCH();
			}
			else if(table == 7 && strlen(D) == 0) {
				gotoxy(75, 38);
				cout << "Chua nhap lua chon D !";
				table = 6;
				Xoa_Thong_BaoCH();
			}
			else if(table == 8) {
				if(strlen(dapan) == 0) {
					gotoxy(75, 38);
					cout << "Chua nhap dap an !";
					table = 7;
					Xoa_Thong_BaoCH();
				} 	
				else {
					gotoxy(75, 38);
					cout << "Ban co muon luu cau hoi khong ?";
					gotoxy(75, 39);
					cout << "F2: Co | F3: Khong";
				}
			}
		}
		else if (kytu == 0){
	    	kytu = getch();
			if(kytu == 60){ //phim F2
				Xoa_Thong_BaoCH();
				if(list.n < MAXCAUHOI) {
					ch.id = id;
					strcpy(ch.maMH, mamh);
					strcpy(ch.noiDung, noidung);
					strcpy(ch.A, A);
					strcpy(ch.B, B);
					strcpy(ch.C, C);
					strcpy(ch.D, D);
					ch.dapAn = dapan[0];
					list.nodeCauHoi[list.n]= new CAUHOI;
    				*list.nodeCauHoi[list.n] = ch;
    				list.n++;
					gotoxy(75, 38);
					SetColor(RED);
					cout << "Luu thanh cong !";
					Sleep(1000);
					ClearNhapCH(mamh, noidung, A, B, C, D, dapan, i, j, k , l, m, n, e);
					Xoa_Thong_BaoCH();
					gotoxy(80, 15);
					id = TimIDMax(list) + 1;
					cout << id;
					table = 1;
				}
				else if(list.n == MAXCAUHOI) {
					Xoa_Thong_BaoCH();
					gotoxy(75, 38);
					SetColor(RED);
					cout << "Bo nho day !";
					table = 1;
				}
			}
			else if(kytu == 61) { //Phim F3
				Xoa_Thong_BaoCH();
				gotoxy(75, 38);
				SetColor(RED);
				cout << "Luu khong thanh cong !";
				table = 1;
				Xoa_Thong_BaoCH();
			}
		}
		else if (kytu == Up) {
			if(table > 0) table --;	
		}
		else if (kytu == Left || kytu == Right) _getch(); // phim len xuong
    	else if (kytu == ESC) return 1;
    	else if (kytu == Backspace){ //backspace
       		if (table == 1)	 XoaTungKyTu(mamh, i, 80, 18);
			else if (table == 2) XoaTungKyTu(noidung, j, 80, 21); 
			else if (table == 3) XoaTungKyTu(A, k, 80, 24); 
			else if (table == 4) XoaTungKyTu(B, l, 80, 27); 
			else if (table == 5) XoaTungKyTu(C, m, 80, 30); 
			else if (table == 6) XoaTungKyTu(D, n, 80, 33); 
			else if (table == 7) XoaTungKyTu(dapan, e, 80, 36); 
		}
		else if ((kytu >= 48 && kytu <= 57) || (kytu >= 65 && kytu <= 90) || (kytu >= 97 && kytu <= 122) || kytu == 32 || kytu == '+' || kytu == '-' || kytu == '*' || kytu == '/' || kytu == '.' || kytu == ',' || kytu == '?' || kytu == '!' || kytu == '"' || kytu == ':' || kytu == '='){
			if (table == 1 && kytu != 32 && i < 10 && ((kytu >= 48 && kytu <= 57) || (kytu >= 65 && kytu <= 90) || (kytu >= 97 && kytu <= 122)))  {
				InHoa(kytu);
				NhapChuoi(mamh, kytu, i, 80, 18); 
			}
			else if (table == 2){
				if(j == 0 &&  kytu != 32) {
					InHoa(kytu);
					NhapChuoi(noidung, kytu, j, 80, 21);
				}
				else if(j > 0 && j < 61) {
					if(!(kytu == 32 && noidung[j - 1] == 32))  NhapChuoi(noidung, kytu, j, 80, 21); 
				}
			}
			else if (table == 3){
				if(k == 0 && kytu != 32) {
					InHoa(kytu);
					NhapChuoi(A, kytu, k, 80, 24);
				} else if(k > 0 && k < 18) {
					if(!(kytu == 32 && A[k - 1] == 32)) NhapChuoi(A, kytu, k, 80, 24); 
				}
			}
			else if (table == 4){
				if(l == 0 && kytu != 32) {
					InHoa(kytu);
					NhapChuoi(B, kytu, l, 80, 27);
				} else if(l > 0 && l < 18) {
					if(!(kytu == 32 && B[l - 1] == 32)) NhapChuoi(B, kytu, l, 80, 27);
				}
			}
			else if (table == 5){
				if(m == 0 && kytu != 32) {
					InHoa(kytu);
					NhapChuoi(C, kytu, m, 80, 30);
				} else if(m > 0 && m < 18) {
					if(!(kytu == 32 && C[m - 1] == 32)) NhapChuoi(C, kytu, m, 80, 30);
				}
			}
			else if (table == 6){
				if(n == 0 && kytu != 32) {
					InHoa(kytu);
					NhapChuoi(D, kytu, n, 80, 33);
				}
			 else if(n > 0 && n < 18) {
			 		if(!(kytu == 32 && D[n - 1] == 32)) NhapChuoi(D, kytu, n, 80, 33);
			 	}
			}
			else if (table == 7 && kytu != 32 && e < 1){ 
				if(kytu == 'a' || kytu == 'A' || kytu == 'b' || kytu == 'B' || kytu == 'c' || kytu == 'C' || kytu == 'd' || kytu == 'D') {
					InHoa(kytu);
					NhapChuoi(dapan, kytu, e, 80, 36);
				}
				else{
					SetColor(RED);
					gotoxy(75, 38);
					cout << "Chi duoc nhap ky tu A->D !";
					Sleep(1000);
					Xoa_Thong_BaoCH();
				}
			}
   		}
	} while(1);
}

void XoaDSCauHoi () {
	 for (int i = 0 ; i < 26; i++)
	 {
	 	SetColor(WHITE);
	 	gotoxy(17, 15 + i);
	 	cout << "     ";
	 	gotoxy(23, 15 + i);
	 	cout << "       ";
	 	gotoxy(31, 15 + i);
	 	cout << "           ";
	 	gotoxy(44, 15 + i);
		cout << "                                                                  ";
		gotoxy(112, 15 + i);
		cout << "                 ";
		gotoxy(132, 15 + i);
		cout << "                 ";
		gotoxy(152, 15 + i);
		cout << "                 ";
		gotoxy(172, 15 + i);
		cout << "                 ";
		gotoxy(192, 15 + i);
		cout << "       ";
	 }
}

void XoaCauHoi(LISTCAUHOI &list){
	bool exit = false;
	int i = 0, table = 0, ID = 0;
	char id[5]; id[0]='\0';
	SetColor(WHITE);
	gotoxy(75, 9);
	cout << "Nhap id cau hoi can xoa : ";
	VeKhung1Duong(105, 8, 3, 30, WHITE);
	char c;
	do {
		gotoxy(110 + strlen(id) + 1, 9);
		c = getch();
		if(c == Enter) {
			table++;
			if(table == 1) {
				SetColor(28);
				if(strlen(id) == 0) {
					gotoxy(75, 11);
					cout << "Chua nhap ID cau hoi ! ";
					table = 0;
					Sleep(1000);
					gotoxy(75, 11);
					cout << "                                                                      ";
				}
				else {
					ID = atoi(id);
					if(TimKiemCauHoi(list, ID) == -1) {
						gotoxy(75, 11);
						cout << "ID khong ton tai. Xin nhap lai ! ";
						table = 0;
						Clear(id);
						i = 0;
						gotoxy(110, 9);
						cout << "                  ";
						gotoxy(111, 9);
						Sleep(1000);
						gotoxy(75, 11);
						cout << "                                                               ";
					}
					else {
						gotoxy(75, 11);
						cout << "Ban co thuc su muon xoa cau hoi nay khong ? F2: Co | F3: Khong";
					}
				}
			}
		}
		else if (c == 0) {
			c = getch();
			if(c == 60){ //phim F2
				Sleep(1000);
				gotoxy(75, 11);
				cout << "                                                                                              ";
				XoaCauHoiBatKy(list, ID);
				gotoxy(75, 11);
				SetColor(RED);
				cout << "Xoa thanh cong !";
				Clear(id); i = 0;
				gotoxy(110, 9);
				cout << "                  ";
				gotoxy(111, 9);
				Sleep(1000);
				gotoxy(75, 11);
				cout << "                           ";
				table = 0;
				XoaDSCauHoi();
				LietKeCauHoi(list);
			}
			else if(c == 61) { //Phim F3
				gotoxy(75, 11);
				cout << "                                                                                                  ";
				gotoxy(75, 11);
				SetColor(RED);
				cout << "Xoa khong thanh cong !";
				table = 0;
				Sleep(1000);
				gotoxy(75, 11);
				cout << "                         ";
			}
		} 
		else if(c == ESC) {
			VeKhung1Duong(75, 8, 4, 63, 0);
			exit = true;
		}
		else if (c == Left || c == Right|| c == Up || c == Down) _getch();
    	else if (c == 8){ //backspace
       		if (table == 0)	{
       			XoaTungKyTu(id, i, 110, 9);
			}
		}
		else if ((c >= 48 && c <= 57)){
			if (table == 0 && i < 4){
				NhapChuoi(id, c, i, 110, 9);
			}
   		}
	} while(!exit);
}

void ClearSuaCH(char noidung[], char A[], char B[], char C[], char D[], char dapan[], int &j, int &k, int &l, int &m, int &n, int &e) {
	Clear(noidung); j = 0;
	Clear(A); k = 0;
	Clear(B); l = 0;
	Clear(C); m = 0;
	Clear(D); n = 0;
	Clear(dapan); e = 0;
	gotoxy(80, 21);
	cout << "                                                                  ";
	gotoxy(80, 24);
	cout << "                                                                  ";
	gotoxy(80, 27);
	cout << "                                                                  ";
	gotoxy(80, 30);
	cout << "                                                                  ";
	gotoxy(80, 33);
	cout << "                                                                  ";
	gotoxy(80, 36);
	cout << "                                                                  ";
}

void SuaCauHoiBatKy(LISTCAUHOI &list, int id, char noidung[], char A[], char B[], char C[], char D[], char dapan) {
	int i = TimKiemCauHoi(list, id);
	if(i != -1) {
		strcpy(list.nodeCauHoi[i]->noiDung, noidung);
		strcpy(list.nodeCauHoi[i]->A, A);
		strcpy(list.nodeCauHoi[i]->B, B);
		strcpy(list.nodeCauHoi[i]->C, C);
		strcpy(list.nodeCauHoi[i]->D, D);
		list.nodeCauHoi[i]->dapAn = dapan;
	}
}

int SuaThongTinCauHoi(LISTCAUHOI &list, int id) {
	CAUHOI ch;
	char mamh[10], noidung[61], A[18], B[18], C[18], D[18], dapan[2];
	int table = 2, dem = 0, j = 0, k = 0, l = 0, m = 0, n = 0, e = 0;
	char kytu;
	mamh[0]='\0'; noidung[0]='\0'; A[0]='\0'; B[0]='\0'; C[0]='\0'; D[0]='\0'; dapan[0]='\0';
	strcpy(mamh, list.nodeCauHoi[TimKiemCauHoi(list, id)]->maMH);
	strcpy(noidung, list.nodeCauHoi[TimKiemCauHoi(list, id)]->noiDung);
	strcpy(A, list.nodeCauHoi[TimKiemCauHoi(list, id)]->A);
	strcpy(B, list.nodeCauHoi[TimKiemCauHoi(list, id)]->B);
	strcpy(C, list.nodeCauHoi[TimKiemCauHoi(list, id)]->C);
	strcpy(D, list.nodeCauHoi[TimKiemCauHoi(list, id)]->D);
	dapan[0] = list.nodeCauHoi[TimKiemCauHoi(list, id)]->dapAn;
	dapan[1] = '\0';
	
	j = strlen(noidung); k = strlen(A); l = strlen(B); m = strlen(C); n = strlen(D); e = strlen(dapan);
	
	system("cls");
	VeKhung2Duong(80, 3 + 2, 3, 50, WHITE);
	gotoxy(80 + 15, 3 + 3);
	SetColor(RED);
	cout << "     NHAP CAU HOI";
	VeKhung1Duong(55, 12, 30, 100, WHITE); //khung ngoai
	
	gotoxy(60, 15);
	cout << "ID : ";
	VeKhung1Duong(75, 14, 3, 75, WHITE);
	
	gotoxy(60, 18);
	cout << "Ma mon hoc : ";
	VeKhung1Duong(75, 17, 3, 75, WHITE);
	
	gotoxy(60, 21);
	cout << "Noi dung : ";
	VeKhung1Duong(75, 20, 3, 75, WHITE);
	
	gotoxy(60, 24);
	cout << "Lua chon A : ";
	VeKhung1Duong(75, 23, 3, 75, WHITE);
	
	gotoxy(60, 27);
	cout << "Lua chon B : ";
	VeKhung1Duong(75, 26, 3, 75, WHITE);
	
	gotoxy(60, 30);
	cout << "Lua chon C : ";
	VeKhung1Duong(75, 29, 3, 75, WHITE);
	
	gotoxy(60, 33);
	cout << "Lua chon D : ";
	VeKhung1Duong(75, 32, 3, 75, WHITE);
	
	gotoxy(60, 36);
	cout << "Dap an (A->D): ";
	VeKhung1Duong(75, 35, 3, 75, WHITE);
	
	VeDuongThang(0, 47, 210, 196, DARKBLUE);
	VeDuongThang(0, 49, 210, 196, DARKBLUE);
	gotoxy(10, 48);
	SetColor(DARKBLUE);
	cout << "Down: Xuong   |   Up: Len   |   ESC: Quay lai";
	
	SetColor(RED);
	gotoxy(80, 15);
	cout << id;
	gotoxy(80, 18);
	cout << mamh;
	SetColor(WHITE);
	gotoxy(80 , 21);
	cout << noidung;
	gotoxy(80 , 24);
	cout << A;
	gotoxy(80 , 27);
	cout << B;
	gotoxy(80 , 30);
	cout << C;
	gotoxy(80 , 33);
	cout << D;
	gotoxy(80 , 36);
	cout << dapan;
	
	do{
		if(table == 2) {
			gotoxy(80 + strlen(noidung), 21);
			kytu = getch();
		}
		else if(table == 3) {
			gotoxy(80 + strlen(A), 24);
			kytu = getch();
		}
		else if(table == 4) {
			gotoxy(80 + strlen(B), 27);
			kytu = getch();
		}else if(table == 5) {
			gotoxy(80 + strlen(C), 30);
			kytu = getch();
		}else if(table == 6) {
			gotoxy(80 + strlen(D), 33);
			kytu = getch();
		}else if(table == 7) {
			gotoxy(80 + strlen(dapan), 36);
			kytu = getch();
		}
		else {
			kytu = getch();
		}
		
		if(kytu == Enter || kytu == Down) { 
			table++;
			SetColor(RED);
			if(table == 3 && strlen(noidung) == 0) {
				gotoxy(75, 38);
				cout << "Chua nhap noi dung cau hoi !";
				table = 2;
				Xoa_Thong_BaoCH();
			}
			else if(table == 4 && strlen(A) == 0) {
				gotoxy(75, 38);
				cout << "Chua nhap lua chon A !";
				table = 3;
				Xoa_Thong_BaoCH();
			}
			else if(table == 5 && strlen(B) == 0) {
				gotoxy(75, 38);
				cout << "Chua nhap lua chon B !";
				table = 4;
				Xoa_Thong_BaoCH();
			}
			else if(table == 6 && strlen(C) == 0) {
				gotoxy(75, 38);
				cout << "Chua nhap lua chon C !";
				table = 5;
				Xoa_Thong_BaoCH();
			}
			else if(table == 7 && strlen(D) == 0) {
				gotoxy(75, 38);
				cout << "Chua nhap lua chon D !";
				table = 6;
				Xoa_Thong_BaoCH();
			}
			else if(table == 8) {
				if(strlen(dapan) == 0) {
					gotoxy(75, 38);
					cout << "Chua nhap dap an !";
					table = 7;
					Xoa_Thong_BaoCH();
				} 	
				else {
					gotoxy(75, 38);
					cout << "Ban co muon luu cau hoi khong ?";
					gotoxy(75, 39);
					cout << "F2: Co | F3: Khong";
					
				}
			}
		}
		else if (kytu == 0){
	    	kytu = getch();
			if(kytu == 60){ //phim F2
				Xoa_Thong_BaoCH();
				SuaCauHoiBatKy(list, id, noidung, A, B, C, D, dapan[0]);
				gotoxy(75, 38);
				SetColor(RED);
				cout << "Sua thanh cong !";
				ClearSuaCH(noidung, A, B, C, D, dapan, j, k , l, m, n, e);
				Xoa_Thong_BaoCH();
				return 1;
			}
			else if(kytu == 61) { //Phim F3
				Xoa_Thong_BaoCH();
				gotoxy(75, 38);
				SetColor(RED);
				cout << "Sua khong thanh cong !";
				Xoa_Thong_BaoCH();
				table = 2;
			}
		}
		else if (kytu == Up) {
			if(table > 0) table --;	
		}
		else if (kytu == Left || kytu == Right) _getch(); // phim len xuong
    	else if (kytu == ESC) return 1;
    	else if (kytu == Backspace){ //backspace
			if (table == 2) XoaTungKyTuCoSan(noidung, j, 80, 21); 
			else if (table == 3) XoaTungKyTuCoSan(A, k, 80, 24); 
			else if (table == 4) XoaTungKyTuCoSan(B, l, 80, 27); 
			else if (table == 5) XoaTungKyTuCoSan(C, m, 80, 30); 
			else if (table == 6) XoaTungKyTuCoSan(D, n, 80, 33); 
			else if (table == 7) XoaTungKyTuCoSan(dapan, e, 80, 36); 
		}	
		else if ((kytu >= 48 && kytu <= 57) || (kytu >= 65 && kytu <= 90) || (kytu >= 97 && kytu <= 122) || kytu == 32 || kytu == '+' || kytu == '-' || kytu == '*' || kytu == '/' || kytu == '.' || kytu == ',' || kytu == '?' || kytu == '!' || kytu == '"' || kytu == ':' || kytu == '='){
			if (table == 2){
				if(j == 0 &&  kytu != 32) {
					InHoa(kytu);
					NhapChuoiCoSan(noidung, kytu, j, 80, 21);
				}
				else if(j > 0 && j < 61) {
					if(!(kytu == 32 && noidung[j - 1] == 32))  NhapChuoiCoSan(noidung, kytu, j, 80, 21); 
				}
			}
			else if (table == 3){
				if(k == 0 && kytu != 32) {
					InHoa(kytu);
					NhapChuoiCoSan(A, kytu, k, 80, 24);
				} else if(k > 0 && k < 18) {
					if(!(kytu == 32 && A[k - 1] == 32)) NhapChuoiCoSan(A, kytu, k, 80, 24); 
				}
			}
			else if (table == 4){
				if(l == 0 && kytu != 32) {
					InHoa(kytu);
					NhapChuoiCoSan(B, kytu, l, 80, 27);
				} else if(l > 0 && l < 18) {
					if(!(kytu == 32 && B[l - 1] == 32)) NhapChuoiCoSan(B, kytu, l, 80, 27);
				}
			}
			else if (table == 5){
				if(m == 0 && kytu != 32) {
					InHoa(kytu);
					NhapChuoiCoSan(C, kytu, m, 80, 30);
				} else if(m > 0 && m < 18) {
					if(!(kytu == 32 && C[m - 1] == 32)) NhapChuoiCoSan(C, kytu, m, 80, 30);
				}
			}
			else if (table == 6){
				if(n == 0 && kytu != 32) {
					InHoa(kytu);
					NhapChuoiCoSan(D, kytu, n, 80, 33);
				}
			 else if(n > 0 && n < 18) {
			 		if(!(kytu == 32 && D[n - 1] == 32)) NhapChuoiCoSan(D, kytu, n, 80, 33);
			 	}
			}
			else if (table == 7 && kytu != 32 && e < 1){ 
				if(kytu == 'a' || kytu == 'A' || kytu == 'b' || kytu == 'B' || kytu == 'c' || kytu == 'C' || kytu == 'd' || kytu == 'D') {
					InHoa(kytu);
					NhapChuoiCoSan(dapan, kytu, e, 80, 36);
				}
				else{
					SetColor(RED);
					gotoxy(75, 38);
					cout << "Chi duoc nhap ky tu A->D !";
					Sleep(1000);
					Xoa_Thong_BaoCH();
				}
			}
   		}
	} while(1);
}

void SuaCauHoi(LISTCAUHOI &list){
	bool exit = false;
	int i = 0, table = 0, ID = 0, check = 0;
	char id[5]; id[0]='\0';
	SetColor(WHITE);
	gotoxy(75, 9);
	cout << "Nhap id cau hoi can sua : ";
	VeKhung1Duong(105, 8, 3, 30, WHITE);
	char c;
	do {
		gotoxy(110 + strlen(id) + 1, 9);
		c = getch();
		if(c == Enter) {
			table++;
			if(table == 1) {
				SetColor(28);
				if(strlen(id) == 0) {
					gotoxy(75, 11);
					cout << "Chua nhap ID cau hoi ! ";
					table = 0;
					Sleep(1000);
					gotoxy(75, 11);
					cout << "                                                                      ";
				}
				else {
					ID = atoi(id);
					if(TimKiemCauHoi(list, ID) == -1) {
						gotoxy(75, 11);
						cout << "ID khong ton tai. Xin nhap lai ! ";
						table = 0;
						Clear(id);
						i = 0;
						gotoxy(110, 9);
						cout << "                  ";
						gotoxy(111, 9);
						Sleep(1000);
						gotoxy(75, 11);
						cout << "                                                               ";
					}
					else {
						gotoxy(75, 11);
						cout << "Tim ID thanh cong !";
						Sleep(1000);
						check = 0;
						while(check == 0) {
							check = SuaThongTinCauHoi(list, ID);
						}
						break;
					}
				}
			}
		}
		else if(c == ESC) {
			VeKhung1Duong(75, 8, 4, 60, 0);
			exit = true;
		}
		else if (c == Left || c == Right|| c == Up || c == Down) _getch();
    	else if (c == 8){ //backspace
       		if (table == 0) XoaTungKyTu(id, i, 110, 9); 
		}
		else if ((c >= 48 && c <= 57)){
			if (table == 0 && i < 4) NhapChuoi(id, c, i, 110, 9); 
   		}
	} while(!exit);
}

void LietKeCauHoiTheoMonHoc(LISTCAUHOI list, char mamh[]) {
	int dem = 0;
  	for (int i = 0; i < list.n ; i++)
     	if (stricmp(list.nodeCauHoi[i]->maMH, mamh) == 0) {
     		SetColor(WHITE);
	 		gotoxy(18, 15 + dem);
	 		cout << dem + 1;
	 		gotoxy(24, 15 + dem);
		 	cout << list.nodeCauHoi[i]->id;
		 	gotoxy(32, 15 + dem);
		 	cout << list.nodeCauHoi[i]->maMH;
		 	gotoxy(46, 15 + dem);
			cout << list.nodeCauHoi[i]->noiDung;
			gotoxy(112, 15 + dem);
			cout << list.nodeCauHoi[i]->A;
			gotoxy(132, 15 + dem);
			cout << list.nodeCauHoi[i]->B;
			gotoxy(152, 15 + dem);
			cout << list.nodeCauHoi[i]->C;
			gotoxy(172, 15 + dem);
			cout << list.nodeCauHoi[i]->D;
			gotoxy(194, 15 + dem);
			cout << list.nodeCauHoi[i]->dapAn;
			dem++;
     	}
}

bool KiemTraMonHocTrongCauHoi(LISTCAUHOI list, char mamh[]) {
	for (int i =0; i < list.n ; i++)
		if (stricmp(list.nodeCauHoi[i]->maMH, mamh) == 0) return true; // kiem ra
  	return false;
}

void LietKeCH(LISTCAUHOI list){
	bool exit = false;
	int i = 0, table = 0;
	char mamh[10]; mamh[0]='\0';
	SetColor(WHITE);
	gotoxy(75, 9);
	cout << "Nhap ma mon hoc can liet ke :";
	VeKhung1Duong(105, 8, 3, 30, WHITE);
	char c;
	do {
		gotoxy(110 + strlen(mamh) + 1, 9);
		c = getch();
		if(c == Enter) {
			table++;
			if(table == 1) {
				SetColor(28);
				if(strlen(mamh) == 0) {
					gotoxy(75, 11);
					cout << "Chua nhap ma mon hoc cau hoi ! ";
					table = 0;
					Sleep(1000);
					gotoxy(75, 11);
					cout << "                                                                      ";
				}
				else {
					if(KiemTraMonHocTrongCauHoi(list, mamh) == false) {
						gotoxy(75, 11);
						cout << "Khong co cau hoi nao trong mon hoc nay. Xin nhap lai ! ";
						table = 0;
						Clear(mamh);
						i = 0;
						gotoxy(110, 9);
						cout << "                  ";
						gotoxy(111, 9);
						Sleep(1000);
						gotoxy(75, 11);
						cout << "                                                               ";
					}
					else {
						XoaDSCauHoi();
						LietKeCauHoiTheoMonHoc(list, mamh);
						SetColor(RED);
						gotoxy(75, 11);
						cout << "Xuat danh sach ! ";
						table = 0;
						Clear(mamh);
						i = 0;
						gotoxy(110, 9);
						cout << "                  ";
						
						gotoxy(111, 9);
						Sleep(1000);
						gotoxy(75, 11);
						cout << "                                                               ";		
					}
				}
			}
		}
		else if(c == ESC) {
			VeKhung1Duong(75, 8, 4, 63, 0);
			exit = true;
		}
		else if (c == Left || c == Right|| c == Up || c == Down) _getch();
    	else if (c == 8){ //backspace
       		if (table == 0)	{
       			XoaTungKyTu(mamh, i, 110, 9);
			}
		}
		else if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
			if (table == 0 && i < 9){
				NhapChuoi(mamh, c, i, 110, 9);
			}
   		}
	} while(!exit);
}

int GiaoDienNhapCauHoi(LISTCAUHOI &list){
	VeKhung2Duong(80, 3 + 2, 3, 50, WHITE);
	gotoxy(80 + 15, 3 + 3);
	SetColor(RED);
	cout << "    CAU HOI THI";
	
	VeKhung1Duong(15, 12, 30, 185, WHITE); //khung danh sach
	VeDuongThang(16, 14, 183, 196, WHITE); //duong ngang giua
	VeDuongDoc(22, 13, 28, 179, WHITE);
	VeDuongDoc(30, 13, 28, 179, WHITE);
	VeDuongDoc(43, 13, 28, 179, WHITE);
	VeDuongDoc(110, 13, 28, 179, WHITE);
	VeDuongDoc(130, 13, 28, 179, WHITE);
	VeDuongDoc(150, 13, 28, 179, WHITE);
	VeDuongDoc(170, 13, 28, 179, WHITE);
	VeDuongDoc(190, 13, 28, 179, WHITE);
	
	gotoxy(17, 13);
	cout << "STT";
	gotoxy(25, 13);
	cout << "ID";
	gotoxy(32, 13);
	cout << "Ma mon hoc";
	gotoxy(73, 13);
	cout << "Noi dung";
	gotoxy(120, 13);
	cout << "A";
	gotoxy(140, 13);
	cout << "B";
	gotoxy(160, 13);
	cout << "C";
	gotoxy(180, 13);
	cout << "D";
	gotoxy(192, 13);
	cout << "Dap an";

	const int so_item = 4;
	const int x = 60;
	const int y = 43;
	const int rong = 3;
	const int dai = 15;
	
	string *item = new string[so_item];
	item[0] = " THEM";
	item[1] = "  XOA";
	item[2] = "  SUA";
	item[3] = "LIET KE";
		
	Normal();  
	int chon = 0;
  	int i, dem = 0; 
  	for (i = 0; i < so_item ; i++)
  	{ 
  		VeKhung1Duong(x + dem, y, rong, dai, WHITE);
		gotoxy(x + 4 + dem, y + 1);
		cout << item[i];
		dem+=24;
  	}

	VeKhung1Duong(x + chon, y, rong, dai, BROWN);
  	HighLight();
  	gotoxy(x + 4 + chon, y + 1);
  	cout << item[chon];
  	char kytu;
  	dem = 0;
  	VeDuongThang(0, 47, 210, 196, DARKBLUE);
	VeDuongThang(0, 49, 210, 196, DARKBLUE);
	gotoxy(10, 48);
	SetColor(DARKBLUE);
	cout << "Right: Sang phai          |         Left: Sang trai         |         ESC: Quay lai"; 
	LietKeCauHoi(list);
	
	do {
 		kytu = getch();
  		if(kytu == Enter) {
  			return chon;
		}
		else if(kytu == ESC) {
			chon = 5;
			return chon;
		}
  		switch (kytu) {
    	case Right :if (chon + 1 < so_item)
  			{
  		        	Normal();
  			  		VeKhung1Duong(x + dem, y, rong, dai, WHITE);
  			  		gotoxy(x + 4 + dem, y + 1);
					cout << item[chon];
					dem+=24;
              		chon ++;
              		HighLight();
              		VeKhung1Duong(x + dem, y, rong, dai, BROWN);
					gotoxy(x + 4 + dem, y + 1);
					cout << item[chon];
  			}
  			break;
  		case Left :if (chon + 1 > 1)
  			  {
  			  		Normal();
  			  		VeKhung1Duong(x + dem, y, rong, dai, WHITE);
  			  		gotoxy(x + 4 + dem, y + 1);
					cout << item[chon];
					dem-=24;
              		chon --;
              		HighLight();
              		VeKhung1Duong(x + dem, y, rong, dai, BROWN);
					gotoxy(x + 4 + dem, y + 1);
					cout << item[chon];
  			  }
  			  break;
  		}  
  	} while (1);	
}

int ChonGiaoDienCauHoi(TREE t, LISTCAUHOI &list) {
	int chon = 0;
	char kytu;
	do {
		chon = GiaoDienNhapCauHoi(list);
		switch(chon) {
  			case 0: {
  				system("cls");
  				int check = 0;
  				while(check == 0) {
  					check = NhapCauHoi(t, list);
				}
				break;
			}
			case 1: {
  				XoaCauHoi(list);
				break;
			}
			case 2: {
				SuaCauHoi(list);
				break;
			}
			case 3: {
				LietKeCH(list);
				break;
			}
			case 5:
				return 1;
		}
	} while(1);
}

//////////////////////////////////THI///////////////////////////////////////////////////

void SwapCH(CH x, CH y)
{
 	CH tam = x;
 	x = y;
 	y = tam;
}

void RandomCauHoi(CH dsch[], int sochthi, int sochmh)
{
    srand(time(NULL));
    int r;
    for(int i = 1; i <= sochthi; i++) {
     	r = i + rand() % (sochmh - i + 1); //cong 1 de co phan tu cuoi cung
    	SwapCH(dsch[i], dsch[r]);
	}
}

void XoaThongBaoNhapTTThi() {
	Sleep(1000);
	gotoxy(115, 23);
	cout << "                                                    ";
}

void Thi1CauHoi(LISTCAUHOI listch, CH dsch[], int i, int *dapan) {
	SetColor(BLUE);
	gotoxy(59, 17);
	cout << i << ": ";
	gotoxy(62, 17);
	cout << "(ID: " << dsch[i].id << ") ";
	
	for(int j = 0; j < listch.n; j++) 
		if(dsch[i].chiso == j) {
			gotoxy(72, 17);
			cout << listch.nodeCauHoi[j]->noiDung;
			SetColor(WHITE);
			gotoxy(60, 23);
			cout << listch.nodeCauHoi[j]->A;
			gotoxy(115, 23);
			cout << listch.nodeCauHoi[j]->B;
			gotoxy(60, 27);
			cout << listch.nodeCauHoi[j]->C;
			gotoxy(115, 27);
			cout << listch.nodeCauHoi[j]->D;
			if(dapan[i] == 'A') {
				SetBGColor(15);
				gotoxy(60, 23);
				SetColor(RED);
				cout << listch.nodeCauHoi[j]->A;
			} else if(dapan[i] == 'B') {
				SetBGColor(15);
				gotoxy(115, 23);
				SetColor(RED);
				cout << listch.nodeCauHoi[j]->B;
			} else if(dapan[i] == 'C') {
				SetBGColor(15);
				gotoxy(60, 27);
				SetColor(RED);
				cout << listch.nodeCauHoi[j]->C;
			} else if(dapan[i] == 'D'){
				SetBGColor(15);
				gotoxy(115, 27);
				SetColor(RED);
				cout << listch.nodeCauHoi[j]->D;
			} 
		}
}

float TinhDiem(int soch, int socaudung, float diem) {
	diem = 10/(float)soch;
	diem *= socaudung;
	return diem;
}

void XoaHienCauHoi() {
	SetBGColor(0);
	gotoxy(62, 17);
	cout << "                                                                          ";
	gotoxy(72, 17);
	cout << "                              ";
	gotoxy(60, 23);
	cout << "                              ";
	gotoxy(115, 23);
	cout << "                              ";
	gotoxy(60, 27);
	cout << "                              ";
	gotoxy(115, 27);
	cout << "                              ";
}

int* Flag(int *flag, int soch) {
	for(int i = 1; i <= soch; i++) {
		flag[i] = 0;
	}
	return flag;
}

int Thi(LISTLOP &listlop, LISTCAUHOI listch, CH dsch[], int M, char mamh[], char tenmh[], int soch, int sophut, NODESV *&p) {
	DIEMTHI dt;
	system("cls");
	time_t now = time(0);
    struct tm  tstruct;
    char buf[50], buf1[50];
    int caudung = 0;
	int i = 1, gio = 0, phut = 0, giay = 0;
	float diem = 0;
	char kytu;
	int *dapan = new int[soch + 1]; // cap phat mang dong so nguyen de lay dap an cua tung cau
	int *flag = new int[soch + 1];
	Flag(flag, soch);
 	int da;
    tstruct = *localtime(&now); //khai bao tstruct theo struct tm  .struct tm: là struct dac biet dung cho TG
    
	VeKhung2Duong(80, 10, 3, 50, WHITE);
	gotoxy(80 + 10, 11);
	SetColor(RED);
	cout << "DE THI MON " << tenmh;
	SetColor(WHITE);
	strftime(buf, sizeof(buf), "Ngay thi: %d-%m-%Y", &tstruct); //dinh dang thoi gian duoc bieu dien trong cau truc timeptr 
	strftime(buf1, sizeof(buf1), "Thoi gian bat dau: %X", &tstruct); //sizeof kich thuoc toi da bo vao buf1// hh:mm:ss
	gotoxy(160, 11);
    cout << buf << endl;
    gotoxy(160, 12);
    cout << buf1 << endl;
    gotoxy(160, 13);
	cout << "Thoi gian thi: " << sophut << " phut";	
	
	VeKhung1Duong(52, 15, 5, 100, WHITE);
	
	SetColor(BLUE);
	gotoxy(55, 17);
	cout << "Cau ";
	SetColor(WHITE);
	gotoxy(55, 23);
	cout << "A: ";
	gotoxy(110, 23);
	cout << "B: ";
	gotoxy(55, 27);
	cout << "C: ";
	gotoxy(110, 27);
	cout << "D: ";
	
	VeDuongThang(0, 47, 210, 196, DARKBLUE);
	VeDuongThang(0, 49, 210, 196, DARKBLUE);
	gotoxy(10, 48);
	SetColor(DARKBLUE);
	cout << "Chon dap an: a: A   |   b: B    |   c: C    |   d: D    | 	 Left: Qua Trai    |	Right: Qua Phai   |   s: Dung thi   |   Enter: Nop bai";
	
	gio = sophut / 60;
	phut = sophut % 60;
	giay = 0;
	
	RandomCauHoi(dsch, soch, M); // danh sach, soch thi, soch mon hoc
	Thi1CauHoi(listch, dsch, i, dapan);
	
	do {
		while(!kbhit()) { //khong nhan phim tu ban phim thi chay
			SetColor(RED);
			if(gio == 0 && phut == 0 && giay == 0) break;
			if(giay > 0) giay--;
			else if(phut > 0) {
				giay = 59;
				phut--;
			} else if(gio > 0) {
				gio--;
				phut = 59;
				giay = 59;
			}
			if(gio < 10) {
				if(phut < 10) {
					if(giay < 10) {
						gotoxy(160, 14);
						cout << "0" << gio << " : 0" << phut << " : 0" << giay; 
					}
					else{
						gotoxy(160, 14);
						cout << "0" << gio << " : 0" << phut << " : " << giay; 
					}
				}
				else {
					gotoxy(160, 14);
					cout << "0" << gio << " : " << phut << " : " << giay; 
				}
			}
			else {
				if(phut < 10) {
					if(giay < 10) {
						gotoxy(160, 14);
						cout << gio << " : 0" << phut << " : 0" << giay; 
					}
					else{
						gotoxy(160, 14);
						cout << gio << " : 0" << phut << " : " << giay; 
					}
				}
				else {
					gotoxy(160, 14);
					cout << gio << " : " << phut << " : " << giay; 
				}
			}
			Sleep(980);
		}
		if(gio == 0 && phut == 0 && giay == 0) break;
	
		kytu = getch();
		switch(kytu) {
			case Right: {
				if(i < soch){
				XoaHienCauHoi();
				i++;
				Thi1CauHoi(listch, dsch, i, dapan);
				}
				break;
			}
			case Left: {
				if(i > 1){
				XoaHienCauHoi();
				i--;
				Thi1CauHoi(listch, dsch, i, dapan);
				}
				break;
			}
			default: {
				if(kytu == 'a' || kytu == 'A' || kytu == 'b' || kytu == 'B' || kytu == 'c' || kytu == 'C' || kytu == 'd' || kytu == 'D') {
					for(int j = 0; j < listch.n; j++) {
						if(dsch[i].chiso == j) {
							if(kytu == 'a' || kytu == 'A') {
								SetBGColor(15);
								gotoxy(60, 23);
								SetColor(RED);
								cout << listch.nodeCauHoi[j]->A;
								dapan[i] = 'A';
							}
							else{
								SetBGColor(0);
								gotoxy(60, 23);
								SetColor(WHITE);
								cout << listch.nodeCauHoi[j]->A;
							}
							if(kytu == 'b' || kytu == 'B') {
								SetBGColor(15);
								gotoxy(115, 23);
								SetColor(RED);
								cout << listch.nodeCauHoi[j]->B;
								dapan[i] = 'B';
							}
							else{
								SetBGColor(0);
								gotoxy(115, 23);
								SetColor(WHITE);
								cout << listch.nodeCauHoi[j]->B;
							}
							if(kytu == 'c' || kytu == 'C') {
								SetBGColor(15);
								gotoxy(60, 27);
								SetColor(RED);
								cout << listch.nodeCauHoi[j]->C;
								dapan[i] = 'C';
							}else{
								SetBGColor(0);
								gotoxy(60, 27);
								SetColor(WHITE);
								cout << listch.nodeCauHoi[j]->C;
							}
							if(kytu == 'd' || kytu == 'D') {
								SetBGColor(15);
								gotoxy(115, 27);
								SetColor(RED);
								cout << listch.nodeCauHoi[j]->D;
								dapan[i] = 'D';
							}else{
								SetBGColor(0);
								gotoxy(115, 27);
								SetColor(WHITE);
								cout << listch.nodeCauHoi[j]->D;
							}
							da = (int)listch.nodeCauHoi[j]->dapAn;
							
							if(da == dapan[i] && flag[i] == 0) {
								caudung = caudung + 1;
								flag[i] = 1; //co danh dau chon 1 lan r
							}
						}
					}	
				}
			}
			break;
		}	
		SetBGColor(0);
	} while(kytu != 's' && kytu != Enter);
	
	VeKhung1Duong(90, 35, 3, 30, BROWN);
	SetColor(WHITE);
	gotoxy(100, 36);
	cout << "NOP BAI";
	Sleep(1000);
	VeKhung1Duong(85, 35, 4, 40, WHITE);
	gotoxy(95, 36);
	SetColor(RED);
	cout << "SO CAU DUNG: " << caudung << "/" << soch;
	gotoxy(95, 37);
	cout << "DIEM: " << ceilf(TinhDiem(soch, caudung, diem) * 100) / 100; // lam tron len 2 chu so
	if(p != NULL) {
		strcpy(dt.maMH, mamh);
		dt.diem = ceilf(TinhDiem(soch, caudung, diem) * 100) / 100;
		NODEDIEM *q = KhoiTaoNODEDIEM(dt);
		ThemVaoCuoiDSDIEM(p->sv.dsd, q);
		p->sv.dsd.sldiemthi++; 
		for(int k = 1; k <= soch; k++) {
			NODECH *m = KhoiTaoNODECHTHI(dsch[k]);
			ThemVaoCuoiDSCHTHI(q->dt.dschthi, m);
			q->dt.dschthi.sochthi++;
		}
		GhiFileLop(listlop);
	}
	delete [] dapan;
	delete [] flag;
	delete [] dsch;
	Sleep(2000);
	return 1;
}

bool KiemTraSVDaThi(NODESV *p, char mamh[]) {
	if(p == NULL) return false;
	for(NODEDIEM *q = p->sv.dsd.pHead; q != NULL; q = q->pNext)
		if(stricmp(q->dt.maMH, mamh) == 0) return true;
	return false;
}

void GiaoDienThi(LISTLOP &listlop, TREE t, LISTCAUHOI listch, NODESV *p){
	VeKhung2Duong(80, 6, 3, 50, WHITE);
	gotoxy(100, 7);
	SetColor(RED);
	cout << "THI TRAC NGHIEM";
	VeKhung1Duong(110, 12, 14, 80, WHITE); //khung ngoai
	
	gotoxy(115, 15);
	cout << "Ma mon thi : ";
	VeKhung1Duong(130, 14, 3, 57, WHITE);
	
	gotoxy(115, 18);
	cout << "So cau hoi : ";
	VeKhung1Duong(130, 17, 3, 57, WHITE);
	
	gotoxy(115, 21);
	cout << "Thoi gian : ";
	VeKhung1Duong(130, 20, 3, 57, WHITE);
	
	VeKhung1Duong(15, 12, 34, 80, WHITE); //khung danh sach
	VeDuongThang(16, 14, 78, 196, WHITE); //duong ngang giua
	VeDuongDoc(21, 13, 32, 179, WHITE);
	VeDuongDoc(50, 13, 32, 179, WHITE);
	
	gotoxy(17, 13);
	cout << "STT";
	
	gotoxy(30, 13);
	cout << "Ma mon hoc";
	
	gotoxy(65, 13);
	cout << "Ten mon hoc";
	
	VeDuongThang(0, 47, 210, 196, DARKBLUE);
	VeDuongThang(0, 49, 210, 196, DARKBLUE);
	gotoxy(10, 48);
	SetColor(DARKBLUE);
	cout << "Down: Xuong   |   Up: Len    |   ESC: Quay lai";
	char mamh[10], soch[4], sophut[4], tenmh[40];
	int sch, sphut;
	int table = 0, dem = 0, i = 0, j = 0, k = 0, M = 0, check;
	CH *dsch;
	char c;
	bool exit = false;
	mamh[0]='\0'; soch[0]='\0'; sophut[0]='\0', tenmh[0] = '\0';
	NLRThi(t, dem);
	
	do{
		if(table == 0) {
			gotoxy(135 + strlen(mamh) + 1, 15);
			c = getch();
		}
		else if(table == 1) {
			gotoxy(135 + strlen(soch) + 1, 18);
			c = getch();
		}
		else if(table == 2) {
			gotoxy(135 + strlen(sophut) + 1, 21);
			c = getch();
		}
		else {
			c = getch();
		}
		
		if(c == Enter || c == Down) { 
			table++;
			SetColor(RED);
			if(table == 1) {
				if(strlen(mamh) == 0) {
					gotoxy(115, 23);
					cout << "Chua nhap ma mon thi !";
					table = 0;
					XoaThongBaoNhapTTThi();
				} 
				else {
					if(KiemTraMaMHTrung(t, mamh) == false) { //sai
					gotoxy(115, 23);
					cout << "Ma mon hoc khong ton tai. Vui long nhap lai !";
					Clear(mamh);
					i = 0;
					gotoxy(135, 15);
					cout << "                                              ";
					gotoxy(135 + 1, 15);
					table = 0;
					XoaThongBaoNhapTTThi();
					}
					else {
						if(p != NULL) {
							if(KiemTraSVDaThi(p, mamh) == true) {
								gotoxy(115, 23);
								cout << "Ban da thi mon nay roi. Moi nhap ma mon hoc khac !";
								Clear(mamh);
								i = 0;
								gotoxy(135, 15);
								cout << "                                              ";
								gotoxy(135 + 1, 15);
								table = 0;
								XoaThongBaoNhapTTThi();
							}
							else {
								LayTenMH(t, mamh, tenmh);
								M = SoLuongCHTheoMH(listch, mamh);
								dsch = new CH[M + 1];
							}
						}
						else {
							LayTenMH(t, mamh, tenmh);
							M = SoLuongCHTheoMH(listch, mamh);
							dsch = new CH[M + 1];
						}
					}
				}
			}
			else if(table == 2) {
				if(strlen(soch) == 0) {
					gotoxy(115, 23);
					cout << "Chua nhap so luong cau hoi thi !";
					table = 1;
					XoaThongBaoNhapTTThi();
				} 
				else {
					DSCauHoiTheoMH(listch, dsch, mamh);
					sch = atoi(soch);
					if(sch < 1 || sch > M) {
						gotoxy(115, 23);
						cout << "So luong cau hoi phai lon hon 0 va nho hon " << M + 1 << " !";
						Clear(soch);
						j = 0;
						gotoxy(135, 18);
						cout << "                                            ";
						gotoxy(135 + 1, 18);
						table = 1;
						XoaThongBaoNhapTTThi();
					}
				}
			}
			else if(table == 3) {
				if(strlen(sophut) == 0) {
					gotoxy(115, 23);
					cout << "Chua nhap thoi gian thi !";
					table = 2;
					XoaThongBaoNhapTTThi();
				} 
				else {
					sphut = atoi(sophut);
					gotoxy(115, 23);
					cout << "BAT DAU THI !";
					XoaThongBaoNhapTTThi();
					
					check = 0;
					while(check == 0) {
						check = Thi(listlop, listch, dsch, M, mamh, tenmh, sch, sphut, p);
					}
					break;
				}
			}			
		}
		else if (c == Up) table --;
		else if (c == Left || c == Right) _getch(); // phim len xuong
    	else if (c == ESC) { 
    		exit = true;
		} 
    	else if (c == Backspace){ //backspace
       		if (table == 0) XoaTungKyTu(mamh, i, 135, 15);
			else if (table == 1) XoaTungKyTu(soch, j, 135, 18); 
			else if (table == 2) XoaTungKyTu(sophut, k, 135, 21); 
		}
		else if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
			if (table == 0 && i < 9) {
				InHoa(c);
				NhapChuoi(mamh, c, i, 135, 15);
			}
			else if (table == 1 && (c >= 48 && c <= 57) && j < 3) NhapChuoi(soch, c, j, 135, 18);
			else if (table == 2 && (c >= 48 && c <= 57) && k < 3) NhapChuoi(sophut, c, k, 135, 21);
   		}
	} while(!exit);
}

///////////////////////////////////////IN CAU HOI DA THI/////////////////////////////
void InCHDaThi(LISTLOP listlop, LISTCAUHOI listch, char masv[], char mamh[], char tenmh[]) {
	int dem = 0;
	SetColor(RED);
	gotoxy(80 + 15, 10);
	cout << "MON " << tenmh;
	VeKhung1Duong(15, 12, 34, 175, WHITE); //khung danh sach
	VeDuongThang(16, 14, 173, 196, WHITE); //duong ngang giua
	VeDuongDoc(22, 13, 32, 179, WHITE);
	VeDuongDoc(30, 13, 32, 179, WHITE);
	VeDuongDoc(100, 13, 32, 179, WHITE);
	VeDuongDoc(120, 13, 32, 179, WHITE);
	VeDuongDoc(140, 13, 32, 179, WHITE);
	VeDuongDoc(160, 13, 32, 179, WHITE);
	VeDuongDoc(180, 13, 32, 179, WHITE);
	
	gotoxy(17, 13);
	cout << "STT";
	gotoxy(25, 13);
	cout << "ID";
	gotoxy(63, 13);
	cout << "Noi dung";
	gotoxy(110, 13);
	cout << "A";
	gotoxy(130, 13);
	cout << "B";
	gotoxy(150, 13);
	cout << "C";
	gotoxy(170, 13);
	cout << "D";
	gotoxy(182, 13);
	cout << "Dap an";
	
	for(int i = 0; i < listlop.n; i++) 
		for(NODESV *p = listlop.nodeLop[i]->dssv.pHead; p != NULL; p = p->pNext)
			if(stricmp(p->sv.maSV, masv) == 0) 
				for(NODEDIEM *q = p->sv.dsd.pHead; q != NULL; q = q->pNext)
					if(stricmp(q->dt.maMH, mamh) == 0) 
						for(NODECH *k = q->dt.dschthi.pHead; k != NULL; k = k->pNext) {
						 	for(int j = 0; j < listch.n; j++) 
							 	if(k->ch.chiso == j) {
							 		SetColor(WHITE);
								 	gotoxy(18, 15 + dem);
								 	cout << dem + 1;
								 	gotoxy(24, 15 + dem);
								 	cout << k->ch.id;
							 		gotoxy(32, 15 + dem);
								 	cout << listch.nodeCauHoi[j]->noiDung;
								 	gotoxy(102, 15 + dem);
									cout << listch.nodeCauHoi[j]->A;
									gotoxy(122, 15 + dem);
									cout << listch.nodeCauHoi[j]->B;
									gotoxy(142, 15 + dem);
									cout << listch.nodeCauHoi[j]->C;
									gotoxy(162, 15 + dem);
									cout << listch.nodeCauHoi[j]->D;
									gotoxy(182, 15 + dem);
									cout << listch.nodeCauHoi[j]->dapAn;
									dem++;
								 }
						}
}

bool KiemTraSVDaThiMonHoc(LISTLOP listlop, char masv[], char mamh[]) {
	for (int i = 0; i < listlop.n; i++)
		for(NODESV *p = listlop.nodeLop[i]->dssv.pHead; p != NULL; p = p->pNext)
			if(stricmp(p->sv.maSV, masv) == 0) 
				for(NODEDIEM *q = p->sv.dsd.pHead; q != NULL; q = q->pNext)
					if(stricmp(q->dt.maMH, mamh) == 0) return true;
	return false;
}

void XoaThongBaoInCHDaThi() {
	Sleep(1000);
	gotoxy(70, 23);
	cout << "                                                  ";
}

void GiaoDienInCauHoiDaThi(LISTLOP listlop, TREE t, LISTCAUHOI listch) {
	char masv[11], mamh[10], tenmh[40];
	int table = 0, i = 0, j= 0;
	char c;
	bool exit = false;
	masv[11]='\0'; mamh[0]='\0'; tenmh[0]='\0';
	VeKhung2Duong(80, 3 + 2, 3, 50, WHITE);
	gotoxy(80 + 15, 3 + 3);
	SetColor(RED);
	cout << "IN CAU HOI DA THI";
	
	VeKhung1Duong(62, 15, 11, 80, WHITE); //khung ngoai
	
	gotoxy(70, 18);
	cout << "Ma sinh vien : ";
	VeKhung1Duong(88, 17, 3, 50, WHITE);
	
	gotoxy(70, 21);
	cout << "Ma mon hoc : ";
	VeKhung1Duong(88, 20, 3, 50, WHITE);
	
  	VeDuongThang(0, 47, 210, 196, DARKBLUE);
	VeDuongThang(0, 49, 210, 196, DARKBLUE);
	gotoxy(10, 48);
	SetColor(DARKBLUE);
	cout << "	ESC: Quay lai";
	do{
		if(table == 0) {
			gotoxy(98 + strlen(masv) + 1, 18);
			c = getch();
		}
		else if(table == 1) {
			gotoxy(98 + strlen(mamh) + 1, 21);
			c = getch();
		}
		else {
			c = getch();
		}
		
		if(c == Enter || c == Down) { 
			table++;
			SetColor(RED);
			if(table == 1) {
				SetColor(28);
				if(strlen(masv) == 0) {
					gotoxy(70, 23);
					cout << "Chua nhap ma sinh vien ! ";
					table = 0;
					XoaThongBaoInCHDaThi();
				}
				else {
					if(KiemTraMaSVTrung(listlop, masv) == false) {
						gotoxy(70, 23);
						cout << "Ma sinh vien khong ton tai. Xin nhap lai !";
						gotoxy(98, 18);
						cout << "                                     ";
						gotoxy(99, 18);
						Clear(masv);
						table = 0;
						i = 0; 
						XoaThongBaoInCHDaThi();
					}
					else if(KiemTraSVCoDiem(listlop, masv) == false) {
						gotoxy(70, 23);
						cout << "Sinh vien nay chua thi. Xin nhap lai !";
						gotoxy(98, 18);
						cout << "                                     ";
						gotoxy(99, 18);
						Clear(masv);
						table = 0;
						i = 0; 
						XoaThongBaoInCHDaThi();
					}
				}
			}
			else if(table == 2) {
				if(strlen(mamh) == 0) {
					gotoxy(70, 23);
					cout << "Chua nhap ma mon hoc ! ";
					table = 1;
					XoaThongBaoInCHDaThi();
				}
				else if(KiemTraMaMHTrung(t, mamh) == false) {
						gotoxy(70, 23);
						cout << "Ma mon hoc khong ton tai. Xin nhap lai !"; 
						Clear(mamh);
						table = 1;
						j = 0;
						Sleep(1000);
						gotoxy(98, 21);
						cout << "                           ";
						gotoxy(99, 21);
						XoaThongBaoInCHDaThi();
				}
				else if(KiemTraSVDaThiMonHoc(listlop, masv, mamh) == false) {
					gotoxy(70, 23);
					cout << "Sinh vien nay chua thi mon nay. Xin nhap lai !";
					gotoxy(98, 21);
					cout << "                                     ";
					gotoxy(99, 21);
					Clear(mamh);
					table = 1;
					j = 0; 
					XoaThongBaoInCHDaThi();
				}
				else {
					LayTenMH(t, mamh, tenmh);
					InCHDaThi(listlop, listch, masv, mamh, tenmh);
				}
			}		
		}
		else if (c == Up) table --;
		else if (c == Left || c == Right) _getch(); // phim len xuong
    	else if (c == ESC) {
    		exit = true;
		}
    	else if (c == Backspace){ //backspace
			if (table == 0) XoaTungKyTu(masv, i, 98, 18);
			else if (table == 1) XoaTungKyTu(mamh, j, 98, 21);
		}
		else if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
			if (table == 0 && i < 10) {
				InHoa(c);
				NhapChuoi(masv, c, i, 98, 18);
			}
			else if (table == 1 && j < 9) {
				InHoa(c);
				NhapChuoi(mamh, c, j, 98, 21);
			} 
   		}
	} while(!exit);

}
///////////////////////////////////////IN BANG DIEM/////////////////////////////////

void XoaThongBaoInBangDiem() {
	Sleep(1000);
	gotoxy(133, 23);
	cout << "                                              ";
}

void LietKeDiem(LISTLOP listlop, int chiso, char mamh[]) {
	int dem = 0;
	NODEDIEM *q;
	for(NODESV *p = listlop.nodeLop[chiso]->dssv.pHead; p != NULL; p = p->pNext) {
		SetColor(WHITE);
		gotoxy(7, 15 + dem);
	 	cout << dem + 1;
	 	gotoxy(13, 15 + dem);
	 	cout << p->sv.maSV;
		gotoxy(33, 15 + dem);
		cout << p->sv.ho;
		gotoxy(70, 15 + dem);
		cout << p->sv.ten;
		gotoxy(90, 15 + dem);
		cout << p->sv.phai;
		
		for(q = p->sv.dsd.pHead; q != NULL; q = q->pNext)
			if(stricmp(q->dt.maMH, mamh) == 0) {
				gotoxy(105, 15 + dem);
				cout << q->dt.diem;
				break;
			}
		if (q == NULL) {
			gotoxy(105, 15 + dem);
			cout << "Chua thi";
		}
		dem++;	
	}
}

void GiaoDienInBangDiem(LISTLOP listlop, TREE t) {
	char malop[10], mamh[10];
	int table = 0, i = 0, j= 0, chiso = 0;
	char c;
	bool exit = false;
	malop[0]='\0'; mamh[0]='\0';
	VeKhung2Duong(80, 3 + 2, 3, 50, WHITE);
	gotoxy(80 + 15, 3 + 3);
	SetColor(RED);
	cout << "IN BANG DIEM";
	
	VeKhung1Duong(5, 12, 34, 120, WHITE); //khung danh sach
	VeDuongThang(6, 14, 118, 196, WHITE); //duong ngang giua
	VeDuongDoc(11, 13, 32, 179, WHITE);
	VeDuongDoc(30, 13, 32, 179, WHITE);
	VeDuongDoc(65, 13, 32, 179, WHITE);
	VeDuongDoc(83, 13, 32, 179, WHITE);
	VeDuongDoc(100, 13, 32, 179, WHITE);
	
	gotoxy(7, 13);
	cout << "STT";
	gotoxy(15, 13);
	cout << "Ma sinh vien";
	gotoxy(48, 13);
	cout << "Ho";
	gotoxy(73, 13);
	cout << "Ten";
	gotoxy(90, 13);
	cout << "Phai";
	gotoxy(108, 13);
	cout << "Diem";
	
	VeKhung1Duong(130, 15, 11, 70, WHITE); //khung ngoai
	
	gotoxy(133, 18);
	cout << "Ma lop : ";
	VeKhung1Duong(148, 17, 3, 50, WHITE);
	
	gotoxy(133, 21);
	cout << "Ma mon hoc : ";
	VeKhung1Duong(148, 20, 3, 50, WHITE);
	
  	VeDuongThang(0, 47, 210, 196, DARKBLUE);
	VeDuongThang(0, 49, 210, 196, DARKBLUE);
	gotoxy(10, 48);
	SetColor(DARKBLUE);
	cout << "	ESC: Quay lai";
	do{
		if(table == 0) {
			gotoxy(152 + strlen(malop) + 1, 18);
			c = getch();
		}
		else if(table == 1) {
			gotoxy(152 + strlen(mamh) + 1, 21);
			c = getch();
		}
		else {
			c = getch();
		}
		
		if(c == Enter || c == Down) { 
			table++;
			SetColor(RED);
			if(table == 1) {
				SetColor(28);
				if(strlen(malop) == 0) {
					gotoxy(133, 23);
					cout << "Chua nhap ma lop ! ";
					table = 0;
					XoaThongBaoInBangDiem();
				}
				else {
					chiso = TimKiemLop(listlop, malop);
					if(chiso == -1) {
						gotoxy(133, 23);
						cout << "Ma lop khong ton tai. Xin nhap lai !"; 
						Clear(malop);
						table = 0;
						gotoxy(152, 18);
						cout << "                              ";
						gotoxy(153, 18);
						i = 0;
						XoaThongBaoInBangDiem();
					}
				}
					
			}
			else if(table == 2) {
				if(strlen(mamh) == 0) {
					gotoxy(133, 23);
					cout << "Chua nhap ma mon hoc ! ";
					table = 1;
					XoaThongBaoInBangDiem();
				}
				else if(KiemTraMaMHTrung(t, mamh) == false) {
						gotoxy(133, 23);
						cout << "Ma mon hoc khong ton tai. Xin nhap lai !"; 
						Clear(mamh);
						table = 1;
						j = 0;
						Sleep(1000);
						gotoxy(152, 21);
						cout << "                           ";
						gotoxy(153, 21);
						XoaThongBaoInBangDiem();
					}
				else {
					LietKeDiem(listlop, chiso, mamh);
				}
			}		
		}
		else if (c == Up) table --;
		else if (c == Left || c == Right) _getch(); // phim len xuong
    	else if (c == ESC) {
    		exit = true;
		}
    	else if (c == Backspace){ //backspace
			if (table == 0) XoaTungKyTu(malop, i, 152, 18);
			else if (table == 1) XoaTungKyTu(mamh, j, 152, 21);
		}
		else if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
			if (table == 0 && i < 9) {
				InHoa(c);
				NhapChuoi(malop, c, i, 152, 18);
			}
			else if (table == 1 && j < 9) {
				InHoa(c);
				NhapChuoi(mamh, c, j, 152, 21);
			}
   		}
	} while(!exit);
}
///////////////////////////////////////DOC - GHI FILE/////////////////////////////////

void GhiFileLop(LISTLOP &listlop) {
	ofstream fileout;
 	fileout.open("LOP.txt", ios_base::in);
 	int dem1 = 0, dem2 = 0;
 	if(!fileout.fail()) {
 		fileout << listlop.n << endl;
 		for (int i = 0; i < listlop.n; i++) {
 			fileout << listlop.nodeLop[i]->maLop << endl;
 			fileout << listlop.nodeLop[i]->tenLop << endl;
 			
 			fileout << listlop.nodeLop[i]->dssv.slsv;
 			if(!(i == listlop.n - 1 && listlop.nodeLop[i]->dssv.slsv == 0)) fileout << endl;
 			
 			dem1 = 0;
 			if(listlop.nodeLop[i]->dssv.slsv != 0) {
 				for(NODESV *p = listlop.nodeLop[i]->dssv.pHead; p != NULL; p = p->pNext) {
					fileout << p->sv.maSV << endl;
			        fileout << p->sv.ho << endl;
			        fileout << p->sv.ten << endl;
			        fileout << p->sv.phai << endl;
			        fileout << p->sv.password << endl;
			        
			        fileout << p->sv.dsd.sldiemthi;
			        dem1++;
			        
			        if(!(dem1 == listlop.nodeLop[i]->dssv.slsv && p->sv.dsd.sldiemthi == 0 && i == listlop.n - 1)) fileout << endl;
			        
			        dem2 = 0;
			        if(p->sv.dsd.sldiemthi != 0)
				        for(NODEDIEM *q = p->sv.dsd.pHead; q != NULL; q = q->pNext) {
							fileout << q->dt.maMH << endl;
					        fileout << q->dt.diem << endl;
					        
					        fileout << q->dt.dschthi.sochthi;
					        dem2++;
			        
			        		if(!(dem2 == listlop.nodeLop[i]->dssv.slsv && p->sv.dsd.sldiemthi == 0 && q->dt.dschthi.sochthi == 0 && i == listlop.n - 1)) fileout << endl;
					        for(NODECH *k = q->dt.dschthi.pHead; k != NULL; k = k->pNext) {
					        	fileout << k->ch.id << endl;
					        	fileout << k->ch.chiso;
					        	
					        	if(i < listlop.n - 1) fileout << endl;
							}
						}
				}
			 }
 			
		}
	}
	fileout.close();
}

void DocFileLop(LISTLOP &listlop) {
	ifstream filein;
	filein.open("LOP.txt", ios_base::in);
	LOP lop;
	SinhVien sv;
	DIEMTHI dt;
	CH ch;
	if(filein.fail()) return;
	while(!filein.eof()) {
		filein>>listlop.n;
		filein.ignore();
		for (int i = 0; i < listlop.n; i++) {
			filein.getline(lop.maLop, 10);
			filein.getline(lop.tenLop, 20);
			lop.dssv.pHead = NULL;
			listlop.nodeLop[i]=new LOP;
			*listlop.nodeLop[i]=lop;
				
			filein>>listlop.nodeLop[i]->dssv.slsv;
			filein.ignore();
			for(int j = 0; j < listlop.nodeLop[i]->dssv.slsv; j++) {
				filein.getline(sv.maSV, 11);
				filein.getline(sv.ho, 30);
				filein.getline(sv.ten, 10);
				filein.getline(sv.phai, 4);
				filein.getline(sv.password, 11);
				NODESV *p = KhoiTaoNODESV(sv);
				ThemVaoCuoiDSSV(listlop.nodeLop[i]->dssv, p);
				
				filein >> p->sv.dsd.sldiemthi;
				filein.ignore();
				for(int k = 0; k < p->sv.dsd.sldiemthi; k++) {
					filein.getline(dt.maMH, 10);
					filein >> dt.diem;
					filein.ignore();
					NODEDIEM *q = KhoiTaoNODEDIEM(dt);
					ThemVaoCuoiDSDIEM(p->sv.dsd, q);
						
					filein >> q->dt.dschthi.sochthi;
					filein.ignore();
					for(int m = 0; m < q->dt.dschthi.sochthi; m++) {
						filein >> ch.id;
						filein.ignore();
						filein >> ch.chiso;
						filein.ignore();
						NODECH *x = KhoiTaoNODECHTHI(ch);
						ThemVaoCuoiDSCHTHI(q->dt.dschthi, x);
					}
				}
			}
		}
	}
	filein.close();
}

void DuyetFileMH(TREE t, ofstream &fileout)
{
    if(t!=NULL)
    {
        fileout << t->monhoc.maMH << endl;
        fileout << t->monhoc.tenMH << endl;
        DuyetFileMH(t->pLeft, fileout);
        DuyetFileMH(t->pRight, fileout);
    }
}

void GhiFileMH(TREE &t) {
	ofstream fileout;
	fileout.open("MONHOC.txt", ios_base::in);
	if(!fileout.fail()) {
		DuyetFileMH(t, fileout);
		fileout.close();
	}
}

void DocFileMH(TREE &t) {
	ifstream filein;
	filein.open("MONHOC.txt", ios_base::in);
	if(filein.fail()) return;
	else {
		while(!filein.eof()) {
			MONHOC mh;
			filein.getline(mh.maMH,10);
			filein.getline(mh.tenMH,40);
			if(filein == NULL) {
	        	break;
	    	}
			ThemNodeMH(t, mh);
		}
		filein.close();
	}
}

void GhiFileCauHoi(LISTCAUHOI &list) {
	ofstream fileout;
 	fileout.open("CAUHOI.txt", ios_base::in);
 	if(!fileout.fail()) {
 		fileout << list.n << endl;
 		for (int i = 0; i < list.n; i++) {
 			fileout << list.nodeCauHoi[i]->id << endl;
 			fileout << list.nodeCauHoi[i]->maMH << endl;
 			fileout << list.nodeCauHoi[i]->noiDung << endl;
 			fileout << list.nodeCauHoi[i]->A << endl;
 			fileout << list.nodeCauHoi[i]->B << endl;
 			fileout << list.nodeCauHoi[i]->C << endl;
 			fileout << list.nodeCauHoi[i]->D << endl;
 			fileout << list.nodeCauHoi[i]->dapAn;
 			
 			if(i < list.n - 1) fileout << endl;
		}
		fileout.close();
	}
}

void DocFileCauHoi(LISTCAUHOI &list) {
	ifstream filein;
	filein.open("CAUHOI.txt", ios_base::in);
	CauHoi ch;
	if(filein.fail()) return;
	while(!filein.eof()) {
		filein >> list.n;
		filein.ignore();
		for (int i = 0; i < list.n; i++) {
			filein >> ch.id;
			filein.ignore();
			filein.getline(ch.maMH, 10);
			filein.getline(ch.noiDung, 61);
			filein.getline(ch.A, 18);
			filein.getline(ch.B, 18);
			filein.getline(ch.C, 18);
			filein.getline(ch.D, 18);
			filein >> ch.dapAn;
			filein.ignore();
 			list.nodeCauHoi[i] = new CauHoi;
 			*list.nodeCauHoi[i] = ch;
		}
	}
	filein.close();
}

/////////////////////////////////////////////GIAI PHONG VUNG NHO///////////////////////////////////////////////////////
void GiaiPhongDSLOP(LISTLOP &listlop) {
	for(int i = 0; i < listlop.n; i++) {
		if(listlop.nodeLop[i]->dssv.slsv != 0) 
			for(NODESV *p = listlop.nodeLop[i]->dssv.pHead; p != NULL; p = p->pNext) {
				if(p->sv.dsd.sldiemthi != 0)
					for(NODEDIEM *q = p->sv.dsd.pHead; q != NULL; q = q->pNext) {
						for(NODECH *k = q->dt.dschthi.pHead; k != NULL; k = k->pNext) 
							delete k;
						delete q;
					}
				delete p;	
			}
		delete listlop.nodeLop[i];
	}
}

void GiaiPhongDSMH(TREE &t)
{
    if(t == NULL) return;
    GiaiPhongDSMH(t->pLeft);
    GiaiPhongDSMH(t->pRight);
    delete t;
}

void GiaiPhongDSCAUHOI(LISTCAUHOI &listch) {
	for(int i = 0; i < listch.n; i++) delete listch.nodeCauHoi[i];
}
/////////////////////////////////////////////MENU GIAO VIEN////////////////////////////////////////////////////////////

int MenuGiaoVien() {
	const int so_item = 8;
	const int x = 80;
	const int y = 3;
	const int rong = 3;
	const int dai = 50;
	bool exit = false;
	
	string *item = new string[so_item];
	item[0] = "       NHAP LOP";
	item[1] = "   NHAP SINH VIEN";
	item[2] = "     NHAP MON HOC";
	item[3] = "   NHAP CAU HOI THI";
	item[4] = "       THI THU";
	item[5] = "  IN CAU HOI DA THI";
	item[6] = "    IN BANG DIEM";
	item[7] = "      DANG XUAT";
		
	Normal();
   	system("cls");   
	int chon = 0;
  	int i, dem = 0; 
  	for ( i = 0; i< so_item ; i++)
  	{ 
  		VeKhung1Duong(x, y + dem, rong, dai, WHITE);
		gotoxy(x + 15, y + 1 + dem);
		cout << item[i];
		dem+=5;
  	}

	VeKhung1Duong(x, y + chon, rong, dai, BROWN);
  	HighLight();
  	gotoxy(x + 15,y + 1 + chon);
  	cout << item[chon];
  	char kytu;
  	dem = 0;
  	VeDuongThang(0, 47, 210, 196, DARKBLUE);
	VeDuongThang(0, 49, 210, 196, DARKBLUE);
	gotoxy(10, 48);
	SetColor(DARKBLUE);
	cout << "Down: Xuong          |         Up: Len"; 
	do {
 		kytu = getch();
  		if (kytu == 0) kytu = getch();
  		else if(kytu == Enter) {
  			return chon;
		}
  		switch (kytu) {
    	case Up :if (chon + 1 > 1)
  			{
  		        	Normal();
  			  		VeKhung1Duong(x, y + dem, rong, dai, WHITE);
					gotoxy(x + 15, y + 1 + dem);
					cout << item[chon];	
					dem-=5;
              		chon --;
              		HighLight();
              		VeKhung1Duong(x, y + dem, rong, dai, BROWN);
					gotoxy(x + 15, y + 1 + dem);
					cout << item[chon];
  			}
  			break;
  		case Down :if (chon + 1 < so_item)
  			  {
  			  		Normal();
  			  		VeKhung1Duong(x, y + dem, rong, dai, WHITE);
					gotoxy(x + 15, y + 1 + dem);
					cout << item[chon];	
					dem+=5;
              		chon ++;
              		HighLight();
              		VeKhung1Duong(x, y + dem, rong, dai, BROWN);
					gotoxy(x + 15, y + 1 + dem);
					cout << item[chon];
  			  }
  			  break;
  		}  
  } while (1);
}

/////Menu Giao Vien
void Chon(LISTLOP &listlop, TREE &t, LISTCAUHOI &listch) {
	bool exit = false;
	const int x = 80;
	const int y = 3;
	const int rong = 3;
	const int dai = 50;
	int chon = 0;
	NODESV *p = NULL;
	
	do {
		chon = MenuGiaoVien();
		switch(chon) {
  			case 0: {
  				system("cls");
				GiaoDienNhapLop(listlop);
				GhiFileLop(listlop);
				break;
			}
			case 1: {
				system("cls");
				GiaoDienNhapSV(listlop);
				GhiFileLop(listlop);
				break;
			}
			case 2: {
				system("cls");
				GiaoDienNhapMH(t, listch);
				GhiFileMH(t);
				break;
			}
			case 3: {
				system("cls");
				int check = 0;
				while (check == 0) {
					check = ChonGiaoDienCauHoi(t, listch);	
				}
				GhiFileCauHoi(listch);
				break;
			}
			case 4: {
				system("cls");
				GiaoDienThi(listlop, t, listch, p);
				break;
			}
			case 5: {
				system("cls");
				GiaoDienInCauHoiDaThi(listlop, t, listch);	
				break;
			}
			case 6: {
				system("cls");
				GiaoDienInBangDiem(listlop, t);	
				break;
			}
			case 7: {
				exit = true;
				break;
			}
		}
	} while(!exit);
}

int main() {
	LISTLOP listlop;
	listlop.n = 0;
	
	TREE t;
	KhoiTaoCay(t);
	DocFileMH(t);
	
	LISTCAUHOI listch;
	listch.n = 0;
	
	DocFileCauHoi(listch);
	
	resizeConsole(1500,800);
	char *account = new char[16];
 	NODESV *p = NULL;
 	DocFileLop(listlop);
	
	LOGIN: 
	Login(listlop, account, p); 
	if (stricmp(account, "GV") == 0){
		system("cls");
		Chon(listlop, t, listch);
		system("cls");
		goto LOGIN;
	} else {
		system("cls");
		GiaoDienThi(listlop, t, listch, p);
		GhiFileLop(listlop);
		system("cls");
		goto LOGIN;
	}

	GiaiPhongDSLOP(listlop);
	GiaiPhongDSMH(t);
	GiaiPhongDSCAUHOI(listch);
	getch();
}
