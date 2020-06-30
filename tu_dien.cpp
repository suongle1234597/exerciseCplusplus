#include<iostream>
#include<string>
#include<fstream>
#include "mydic.h"
using namespace std;


bool ghifile  = false;//bien kiem tra xem co thay doi trong bai hay khong

const int sl_DStu = 16;
const int soluachon = 8;			//so loai tu
const int x = 20, y = 6;			// vi tri toa do cua nhap loai tu
const int nghiaMax = 5;			//toi da co 5 vi du
const int Enter = 13;
const int Esc = 27;
const int Down = 80;
const int Up = 72;
const int Left = 75;
const int Right = 77;
const int Tab = 9;
const int Delete = 127;
const int Backspace = 8;

//-------------danh sach lien ket don----------//
struct Vidu
{
	string vidu;
};
struct Node
{  
	Vidu Info ;
    struct Node *next ;
};
typedef   Node  *PTR;

//------------danh sach lien ket kep--------------//
struct Tu 
{
	string tu; 
	string loaitu;
	string nghiatu[nghiaMax]; 
	PTR vd;
};
struct node
{
   Tu info;
   struct node *left, *right;
};
typedef struct node *NODEPTR;

//--------------cau truc mang bam----------------//
struct hashnode
{
	NODEPTR head = NULL;
	NODEPTR tail = NULL;  
};

//----------------------DANH SACH LIEN KET DON-------------------------//
//ham khoi tao danh sach vi du, de chuong trinh hieu la danh sach chua co vi du
 void KhoiTaoVD(PTR &First)
{
   First = NULL;
}
//hàm cap phat vung nho cho vi du
PTR NewNodeVD(PTR &First){
	PTR p = new Node;
	return p;
}

//ham them mot vi du moi voa dau danh sách
PTR ThemdauVD(PTR &First, Vidu vidu){
	PTR p;
	p = new Node;
	p->Info = vidu;
	p->next = First;
	First = p;
	return p;
}
//ham them moi mot vidu  sau node p
PTR ThemsauVD(PTR p, Vidu vidu)
{
   PTR q;
   if(p == NULL)
		return NULL;
   else
   { 
   	  q = new Node;
      q->Info = vidu;
      q->next = p->next;
      p->next = q;
   }
   return p;
}

//----------------------------danh sach lien ket kep----------------//

//ham khoi tao danh sach de cho chuong trinh hieu la ds chua co phan tu
void KhoiTao(NODEPTR &First)
{
   First = NULL;
}
//ham them tu vao dau danh sach lien ket kep
NODEPTR ThemDau(NODEPTR &First, Tu Tuthem)
{
   NODEPTR p;
   p = new node;
   p->info = Tuthem;
   if(First == NULL)  // truong hop danh sach rong
      p->right = NULL;
   else
   {
      // tao lien ket giua p va First
      p->right = First;
      First->left = p;
	}
     First = p;
     p->left = NULL;
	 return p;
}

//ham them mot tu moi sau nut p
NODEPTR ThemSau(NODEPTR p, Tu Tuthem)
{
   NODEPTR q, r;  //q la nut can them vao, p la nut truoc q, r la nut sau q
   if(p == NULL)
      return NULL;
   else
   {
      q = new node;
      q->info = Tuthem;
      r = p->right;
      // tao hai lien ket giua r va q
      r->left = q;
      q->right = r;
      // tao hai lien ket giua p va q
      q->left = p;
      p->right = q;
      return q;
   }
   
}

//ham them mot tu moi truoc nut p
NODEPTR ThemTruoc(NODEPTR &First, NODEPTR p, Tu TuThem ){
	NODEPTR q, r;  // q la nut can them vao, p la nut sau, r la nut truoc
	if(p == NULL)
      return NULL;
   else
   {
      if(p == First)  // them nut vao dau danh sach
		 ThemDau(First, TuThem);
      else
      {
		 q =new node;
		 q->info = TuThem;
		 r = p->left;
		 // tao hai lien ket giua r va q
		 r->right = q;
		 q->left = r;
		 // tao hai lien ket giua p va q
		 q->right = p;
		 p->left = q;
      }
	}
	return q;
	
}

//ham them mot tu moi vao cuoi danh sach
void ThemCuoi(NODEPTR &First, Tu Tuthem){
	NODEPTR q;
	q = new node;
	q->info = Tuthem;
	q->right = NULL;
	q->left = First;
	First->right = q;
}

//xoa nut o dau danh sach
void Delete_first(NODEPTR &First)
{
   NODEPTR p;//p la nut cn xoa
   if(First != NULL)
   {
      p = First;  // p la nut can xoa
      
      if(First->right == NULL)  // truong hop danh sach co mot nut
		First = NULL;
		
      else
      {
		First = p->right;
		First->left = NULL;
      }
      delete p;
   }
}

//xoa nut o cuoi danh sach
void delete_last( NODEPTR &First, NODEPTR p){
	if(First!=NULL)
	{
		if(p->right == NULL){
			NODEPTR q;//q la nut truoc p, p la nut can xoa
			q = p->left;
			q->right = p->right;
			delete p;
		}
	}
}

//xoa nut co dia chi p
void Delete_node(NODEPTR &First, NODEPTR p)
{
   NODEPTR q, r;
   
   if(p != NULL){//neu nut can xoa khong rong
   	
      if(First != NULL)//neu danh sach khong rong
      {
      	//xoa dau danh sach
		 if(p == First){  // truong hop xoa nut dau
		 	
		     Delete_first(First);
		 }
		 // ------xoa nut co dia chi p------
		 else if(p->right!=NULL){
		 	q = p->left;   // q la nut truoc
		    r = p->right;  // r la nut sau
		    // tao hai lien ket giua q va r
		    r->left = q;
		    q->right = r;
		    delete p;
		 }
		 else
		 {
			delete_last(First, p);
		 }
      }
   }
}

//-----------------hashnode---------------//

//ham tim vi tri thich hop de them tu vao danh sach
void bamThem(hashnode *Tudien, Tu tu){
	
	int vitri = (int)tu.tu[0] - 97;// vitri la bien dung de xet xem tu dien nam o vi tri thu may
	NODEPTR p;
	p = Tudien[vitri].head;
	if( p == NULL||tu.tu < p->info.tu){// neu danh sach rong hoac tu can them be hon tu dau tien
		ThemDau(Tudien[vitri].head, tu);
		return;
	}
	else{
		while(p->right != NULL)//neu tu dien co nhieu hon mot tu
		{
			if(tu.tu > p->right->info.tu){
				p=p->right;	
			}
			else{
				ThemSau(p,tu);
				return;	
			}
		}
		ThemCuoi(p, tu);//neu tu dien chi co mot tu thì thêm cuoi danh sách
		return;
	}
}

//ham tim tu co trong danh sach hay khong, co tra ve dia chi tu, khong tra ve NULL
NODEPTR bamTim( hashnode *Tudien, string tu){
	
	int vitri = (int)tu[0] - 97;//lay ky tu dau cua tu de xet xem tu do se nam trong ds tu nao
	if(vitri < 0)//neu ky tu dau cua tu khong hop le
		return NULL;
		
	NODEPTR p;
	p = Tudien[vitri].head;// con tro p tro toi  danh sach thu vi tri de tim
	
	if(p == NULL)
		return NULL;
	else if(tu == p->info.tu)
		return p;
	else{
		while(p->right!=NULL)
		{
			if(tu != p->right->info.tu){
				p = p->right;	
			}
			else{
				p = p->right;	
				return p;
			}
		}
	}
	return NULL;
}

//ham kiem tra xem tung ki tu cua string tu co trung voi tu trong DS hay khong
//dung de kiem tra tu nhap trong khung tim kiem
//neu co tu(trong danh sach) trung voi tung ky tu vua nhap thi tra ve true, nguoc lai false
bool kt_tim_tu(NODEPTR p, string tu){
	
	if(tu.length() > p->info.tu.length())
		return false;
	else{
		for(int i=0; i<tu.length(); i++){
			
			if(tu[i] != p->info.tu[i])
				return false;
		}
		return true;
	}
}

//ham timtu su dung trong thanh tim kiem
//ham tra ve dia chi cua tu co cac ky tu dau trung voi cac ky tu nhap tu ban phim
NODEPTR timtu( hashnode *Tudien, string tu){
	
	int vitri = (int)tu[0] - 97;		//lay ky tu dau cua chuoi-97 de xet nan trong ds bao nhieu
	if(vitri < 0) 	//neu ky tu dau cua chuoi khong hop le
		return NULL;
		
	NODEPTR p;
	p = Tudien[vitri].head;
	
	{
		while(p != NULL)
		{
			if(kt_tim_tu(p, tu)){	//neu tim thay tu co cac ky tu dau 
				return p;			//trung voi ky tu cua chuoi vua nhap thi tra ve dia chi cua tu do
			}
				p=p->right;
		}
	}
	return NULL;
}

//ham nhap loai tu
string chonloaitu(Tu tu)
{
	string loaitu [soluachon];
	loaitu[0] = "noun         ",
	loaitu[1] = "verb         ",
	loaitu[2] = "adverb       ",
	loaitu[3] = "adjective    ",
	loaitu[4] = "Pronouns     ",//dai tu
	loaitu[5] = "Prepositions ",//gioi tu
	loaitu[6] = "Conjunctions ",//lien tu
	loaitu[7] = "Interjections",//than tu"
	setcolor(7);
	int chon =0;
	for (int i=0; i< soluachon ; i++)
  	{ 
		gotoxy(x+15, (y+1) +i);
    	cout << loaitu[i];
  	}
  	setcolor(79);
  	gotoxy(x+15, (y+1)+chon);
  	cout << loaitu[chon];
  	char kytu;
	do {
  	kytu = getch();
  	if (kytu==0) kytu = getch();
	 	 switch (kytu) {
			    case Up :	{
					if (chon+1 > 1)
					  {
					  		setcolor(7);
			      			gotoxy(x+15, (y+1)+chon);
			      			cout << loaitu[chon];
			          		chon --;
			          		setcolor(79);
			              	gotoxy(x+15, (y+1)+chon);
			              	cout << loaitu[chon];
						
					  }
					  break;
				}
			  	case Down :{
			  		if (chon+1 < soluachon)
		  			  {
		  			  	setcolor(7);
		              	gotoxy(x+15, (y+1)+chon);
		              	cout << loaitu[chon];
		              	chon ++;
		              	setcolor(79);
		              	gotoxy(x+15, (y+1)+chon);
		              	cout << loaitu[chon];
		  			  }
		  			  break;
		  		}
		  		
			  	case 13 : {
			  		setcolor(7);
			  		tu.loaitu = loaitu[chon];
			  		
			  		//in ra khoang trang hinh chu nhat de de len khung chon loai tu
			  		for(int i = 0; i < 9; i++){
			  			gotoxy(x+15, y+2+i);
			  			for(int j = 0; j < 15; j++)
			  				cout << " ";
			  		}
			  		return tu.loaitu;
			  	}
			  	
		  }  // end switch
	} while (1);
	
}

//ham nhap vi du 
void nhapVD(PTR &First){
	
	Vidu VD;
	KhoiTaoVD(First);
	
	PTR p = First;
	
	for(int i = 0; i < 5; i++){
		gotoxy(x, y+7+i);
		cout<<"nhap vi du "<< i+1 << ": ";
		chuanhoachuoi(VD.vidu, x+15, y+7+i);
		
		if(VD.vidu.length() == 0){//neu chua nhap vi du,thi viec nhap se ket thuc
			p=NULL;
			break;	
		}
		else{
			if(i==0)
				p= ThemdauVD(First, VD);
				
			else {
				ThemsauVD(p, VD);
				p=p->next;
			}
		}
	}
}
//ham them mot tu moi vao danh sach 
void NhapTu(hashnode *Tudien, Tu tu)
{
	setcolor(7);
	gotoxy(x, y);
	cout << "nhap Tu: ";
	NODEPTR p;
	while( tu.tu.length() ==  0){
		string t = chinhanchu(tu.tu,x+10,y);
		if(tu.tu.length() == 0){//neu chua nhap tu
		
			gotoxy(x+70, y);
			setcolor(12);
			cout << "\aban chua nhap tu!";
			setcolor(7);
		}
		else{ 			//neu da nhap tu
		
			gotoxy(x+70, y);
			cout << "                   ";//xoa dong thong bao
			p = bamTim(Tudien, tu.tu); //kiem tra xem tu da cos trong ds chua, chua co tra ve NULL
		
			if(p != NULL){     //neu tu da ton tai trong danh sach
								//neu tu da co trong danh sach thi xoa chuoi vua nhap
				//in ra khoang trang de len ky tu vua nhap
				for(int i = 0; i < tu.tu.length() + 1; i++){
					gotoxy(x+11+i, y);
					cout << " ";
				}
					
				tu.tu = "";//gan tu = 0 de nhap lai
				gotoxy(x+70, y);   
				setcolor(12);
				cout << "\aTu da co trong danh sach";	//xuat ra thong bao
				setcolor(7);
			}
			else{//neu tu chua co trong danh sach
				gotoxy(x+70, y);
				cout << "                            ";
			}
		}
	}
	gotoxy(x, y+1);
	cout << "chon loai tu: ";
	tu.loaitu = chonloaitu(tu);
	gotoxy(x+15, y+1);
	cout << tu.loaitu;
	for(int i = 0; i < nghiaMax; i++)
	{
		gotoxy(x, y+2+i);
		cout << "nhap nghia "<< i+1 <<": ";
	
		while(tu.nghiatu[0].length() == 0){// neu chua nhap nghia thu nhat thi con lap
			
			chinhanchu(tu.nghiatu[0], x+15, y+2+i);
			if(tu.nghiatu[0].length() == 0){
				setcolor(12);
				gotoxy(x+70,y+2);
				cout << "\aban chua nhap nghia!";
				setcolor(7);
			}
			else{
				gotoxy(x+70,y+2);
				cout << "                                   ";
			}
		}
		if(i != 0){
			chinhanchu(tu.nghiatu[i], x+15, y+2+i);
		}
	}
	gotoxy(x, y+7);
	nhapVD(tu.vd);
		
	bamThem(Tudien, tu);//sau khi nhap xong goi ham bam them de xet xem tu do nam o vi tri nao trong ds
}

//ham xuat ra thong tin cua tu can xem
NODEPTR xuattu(hashnode *Tudien, NODEPTR p){
	if(p == NULL){
		gotoxy(x+70,y);
		setcolor(12);
		cout << "tu nay khong co trong DS!"<<endl;
		setcolor(7);
		return NULL;//tu nay khong co trong danh sach
	}
	gotoxy(x-5, y);
	cout << "Tu: "<< p->info.tu;
	gotoxy(x-5, y+1);
	cout << "Loai tu: " << p->info.loaitu;
	int t=1;
	for(int i = 0; i < nghiaMax; i++){
		if(p->info.nghiatu[i].length() != 0){
			gotoxy(x-5, y+2+t);
			cout << "Nghia "<<t<<": "<<p->info.nghiatu[i]<<endl;
			t++;	
		}	
	}
	int stt = 1;
	PTR q = p->info.vd;
	if(q != NULL)
	{
		while(q != NULL){
			gotoxy(x-5, y+1+t+stt);
			cout << "vi du " << stt << ": " << q->Info.vidu << endl;
			stt++;
			q = q->next;
		}
	}
	
	return p;
}

//ham kiem tra xem nguoi dung co muon xoa tu hay khong
bool KTxoaTu(NODEPTR &tu) {
	
	// xoa nhan cua trang xem tu
	for(int i = 0; i < 100; i++){
		gotoxy(10+i, 25);
		cout<<" ";
	}
	
	setcolor(12);
	gotoxy(12, 22);
	cout << "\aBan co chac muon xoa tu \"" << tu->info.tu << "\" khong?";
	gotoxy(12, 23);
	cout << "Enter: xoa";
	gotoxy(30, 23);
	cout << "Esc: quay lai";
	int key = 0;
	while(key != Enter && key != Esc) 
		key = getch();
	if(key == Enter) 
		return true;
	else if(key == Esc) 
		return false;
	setcolor(7);
}

//tra ve dia chi danh sach dau tien khong rong
NODEPTR tim_ds_dau(hashnode *Tudien, NODEPTR p){
	
	for(int i = 0; i < 26; i++) {
		if( Tudien[i].head != NULL) {//neu tim ra duoc danh sach khong rong thi gan cho p va ket thuc
			p = Tudien[i].head;
			return p;
		}
	}
	return NULL;
}

//----------------------------------------------------------------
//------------------ghi doc file----------------
void chenVdVaoDauDs(PTR &first, string vidu) {
	// tao not moi trung gian
	PTR p = new Node;
	p->Info.vidu = vidu;
	p->next = NULL;
	// truong hop ds chua co phan tu nao
	if (first == NULL) {
		first = p;
	} else {
		// truong hop ds da co it nhat 1 phan tu
		p->next = first;
		first = p;
	}
}

// chen 1 tu vao cuoi ds tu dien
void chenTuVaoCuoiTd(hashnode *&Tudien, NODEPTR p) {
	// xac dinh xem tu nay thuoc
	// tap tu dien nao
	int i = (int )p->info.tu[0]-97;
	
	// truong hop tap tu dien chua co tu nao
	if (Tudien[i].head == NULL) {
		Tudien[i].head = Tudien[i].tail = p;
	} else {
		// truong hop tap tu dien da co it nhat 1 tu
		Tudien[i].tail->right = p;
		p->left = Tudien[i].tail;
		Tudien[i].tail = p;
	}
}

/* cac ham xu ly tap tin */
NODEPTR chuyendoi(string dong) {
	
	NODEPTR p = new node();
	int i, pos;
	i = 0;
	
	// about/pho tu/khoang chung;sap;gan;/He is about to die;We're about to start;How about this?;
	
	// tach tu
	string tu = "";
	while (dong[i] != '#') {tu += dong[i++];}
	i++;
	p->info.tu = tu;
	
	// tach loai tu
	string loai = "";
	while (dong[i] != '#') {loai += dong[i++];}
	i++;
	p->info.loaitu = loai;
	
	// tach nghia
	string nghia = ""; pos = 0;
	while (dong[i] != '#') {
		nghia += dong[i];
		i++; 
		// nghia moi
		if (dong[i] == ';') { 
			p->info.nghiatu[pos++] = nghia;
			nghia = "";
			i++;
		}
	}
	i++;
	
	// tach vi du
	p->info.vd = NULL;
	string vidu = "";
	while (dong[i] != '#') {
		vidu += dong[i++];
		if (dong[i] == ';') {
			chenVdVaoDauDs(p->info.vd, vidu);
			vidu = "";
			i++;	
		}
	}	
	return p;
}

// doc tap tin tung dong mot
void docFile(hashnode *&Tudien) {
	ifstream fi("DL.txt"); // tim tap tin
	string dong;
	
	if (fi.is_open()) { // mo tap tin, kiem tra tap tin co ton tai hay khong...
		while (getline(fi, dong)) {
			//cout << dong << endl;
			if (dong == "") continue;
			NODEPTR p = chuyendoi(dong);
			chenTuVaoCuoiTd(Tudien, p);
			
		}
		fi.close(); // dong tap tin
	}
}
//----------------------ghi file------------
void ghiFile(hashnode *&Tudien) {
	ofstream fo("DL.txt");
	if(fo.is_open()) {
		
		for (int i = 0; i < 26; i++) {
			NODEPTR p = Tudien[i].head;
			if (p == NULL) continue;
			while (p != NULL) {
				fo << p->info.tu << "#";
				fo << p->info.loaitu << "#";
				
				for (int i = 0; i < nghiaMax; i++) {
					if (p->info.nghiatu[i] == "") break;
					fo << p->info.nghiatu[i] << ";";
				}
				fo << "#";
				
				PTR vd = p->info.vd;
				while (vd != NULL) {
					fo << vd->Info.vidu << ";";
					vd = vd->next;
				}
				fo << "#\n";
				p = p->right;
			}
		}
		
		fo.close();
	}
}
//------------------------ket thuc ghi doc file-----------------------------
//ham tim tu phia truoc 1 nut p
NODEPTR Tuphiatruoc(hashnode *Tudien, NODEPTR p){
	if(p==NULL)					//neu nut rong
		return NULL;			//tra ve NULL
	else{ 	
		NODEPTR q = p->left;					
		if(q != NULL)	{	//neu nut phia truoc khong rong
			return q;
		}		// tra ve dia chi cua nut phia truoc
		
		if(q == NULL){					//neu nut phia truoc rong, co nghia nut p dang o dau danh sach
			int vitri = (int)p->info.tu[0]-97;//lay  ky tu dau tien xet xem p dang ow mang bam thu may
			if(vitri > 0){
				while(vitri != 0){
					if(Tudien[vitri-1].tail != NULL)	{
						return Tudien[vitri-1].tail;
					}
					else{
						vitri--;	
					}	
					if(vitri == 0)
						return NULL;
				}
				return NULL;
			}
			else
				return NULL;
		}
	}
}

//ham tim tu phia sau cua mot tu
NODEPTR Tuphiasau(hashnode *Tudien, NODEPTR p){
	if(p == NULL)//neu nut rong
		return NULL;//tra ve NULL
	else{ //nguoc lai
		NODEPTR q = p->right;
		if(q != NULL)//neu nut phia sau khong rong
			return q;		// tra ve dia chi cua nut phia sau
		if(q == NULL){		//neu nut phia sau rong, co nghia nut dang o cuoi danh sach
			int vitri = (int)p->info.tu[0]-97;//lay  ky tu dau tien xet xem p dang o mang bam thu may
			if(vitri<25){
				while(vitri != 26){
					if(Tudien[vitri+1].head != NULL)// neu danh sach phia sau khong rong
						return Tudien[vitri+1].head;
					else
						vitri++;
					if(vitri == 25)
						return NULL;
				}
				return NULL;
			}
				return NULL;
		}
	}
}

//xuat ra mot tu (in ra ky tu " ")de khi goi ham co 
//the doi mau thanh sang khi in ra khung tim kiem
void xuattu_comau(NODEPTR p){
	if(p != NULL){
		cout << p->info.tu;
		for(int i = p->info.tu.length(); i < boxs; i++)
			cout << " ";
	}	
}

//xuat ra mot tu trong ds de in ra khung ket qua tim kiem
void xuattu_khongmau(NODEPTR p){
	if(p != NULL){
		cout << p->info.tu;
	}	
}

//hàm sua tu 
void SuaTu(hashnode *Tudien, NODEPTR p){
	system("cls");
	//----xuat ra noidung tu dang xem----//
	khungthemtu();
	nhan_quaylaiTT();
	xuattu(Tudien, p);
	
	string tu=p->info.tu;
	
	int kytu = 0;
	bool ktsuatu = false;// bien kiem tra xem co sua tu khong
	NODEPTR q = NULL;
	
	setcolor(15);
	gotoxy(x-1+p->info.tu.length(), y);
	
	while(kytu != Esc){
		
	
		tudau:
		kytu = getch();
		switch(kytu){
			case Backspace:{
				ktsuatu = true;
				if(p->info.tu.length()>0)
	        	{
	        		gotoxy(x-1+p->info.tu.length()-1,y);
	        		cout << " ";
		        	p->info.tu.erase(p->info.tu.length()-1, 1);
//		  string str;      	str.erase(int pos, int n); //xóa n ku tu tu vi trí pos
		        	p->info.tu[p->info.tu.length()] = '\0';
	        	}
				break;
			}
			case Enter:{
				if(p->info.tu == ""){
					gotoxy(x-1, y+20);
					cout << "ban chua nhap tu";
				}
				else{
					NODEPTR q;
					q = timtu(Tudien, p->info.tu);
					if(q != NULL){
						gotoxy(x-1,y+20);
						cout<<"tu nay da ton tai moi ban nhap tu khac";
					}
					else{
						gotoxy(x-1,y);
						cout<<p->info.tu;
						gotoxy(x+4,y+1);
						p->info.loaitu = chonloaitu(p->info);
						gotoxy(x+4,y+1);
						cout<<p->info.loaitu;
						cout<<"               ";
						gotoxy(x+4+p->info.nghiatu[0].length(),y+3);
						int kitu1 = 0;
						
						while(kitu1 != Enter){
							tudau1:
							kitu1 = getch();
							gotoxy(x+4+p->info.nghiatu[0].length(), y+3);
							switch(kitu1){
								case 8:{
									if(p->info.nghiatu[0].length() > 0)
						        	{
						        		gotoxy(x+4+p->info.nghiatu[0].length()-1,y+3);
						        		cout << " ";
							        	p->info.nghiatu[0].erase(p->info.nghiatu[0].length()-1,1);
							        	p->info.nghiatu[0][p->info.nghiatu[0].length()] ='\0';
						        	}
						        	break;
								}
								case Enter:{
									if(p->info.nghiatu[0].length()==0){
										gotoxy(x+4,y+22);
										cout << "ban chua nhap vi du";
										goto tudau1;
									}
									else{
											gotoxy(x+4,y+3);
									cout << p->info.nghiatu[0];
									}
								
									break;
								}
								case Esc:{
									
									break;
								}
								default:{
									if((kitu1 > 96 && kitu1 < 123) || (kitu1 > 64 && kitu1 < 91) || (kitu1 == 32) || (kitu1 == 39) || (kitu1 == 45)){
										gotoxy(x+4+p->info.nghiatu[0].length()-1,y+3);
	//										ktsuatu = true;
										p->info.nghiatu[0] += (char)kitu1;
										p->info.nghiatu[0][p->info.nghiatu[0].length()] ='\0';
										gotoxy(x+4+p->info.nghiatu[0].length()-1,y+3);
										cout << (char)kitu1;
									}
								}
							}
						}	
					}
				}
				break;
			}
			case Esc:{
				break;
			}
			default:{
				if((kytu > 96 && kytu < 123) || (kytu > 64 && kytu < 91) || (kytu == 32) || (kytu == 39) || (kytu == 45)){
					gotoxy(x-1+p->info.tu.length()-1, y);
					ktsuatu = true;
					p->info.tu += (char)kytu;
					p->info.tu[p->info.tu.length()] ='\0';
					gotoxy(x-1+p->info.tu.length()-1, y);
					cout << (char)kytu;
				}
			}
		}
	}
}

//ham hien ra danh sach tu tim duoc trong khung tim tu
void DStu_timduoc(hashnode *Tudien, NODEPTR p, int vitrisang){
	if(p == NULL){//neu node tim duoc rong
		for(int i = 0 ; i < sl_DStu; i++){ //xoa toan bo danh sach tu da tim duoc
			gotoxy(boxx+1, boxy + 3+i);
			for(int j = 0; j < boxs; j++)
				cout << " ";
		}
	}
	if(p != NULL){
		//xoa toan bo danh sach tu da tim duoc
		for(int i = 0 ; i < sl_DStu; i++){ 
			gotoxy(boxx+1, boxy + 3+i);
			for(int j = 0; j < boxs; j++)
				cout<<" ";
		}	
		
		NODEPTR q,r;
		q = p;
		if(vitrisang != 0){

			for(int i = vitrisang-1 ; i >= 0; i-- ){
				setcolor(7);
				gotoxy(boxx+1, boxy + 3+  i);
				q = Tuphiatruoc(Tudien, q);
				xuattu_khongmau(q);	
				
			}
		}
		gotoxy(boxx+1, boxy + 3+ vitrisang);
		setcolor(79);
		xuattu_comau(p);
		setcolor(7);
		r = p;
		for(int i = vitrisang + 1 ; i < sl_DStu; i++ ){
			setcolor(7);
			gotoxy(boxx+1, boxy + 3 +i);
			r = Tuphiasau(Tudien, r);
			xuattu_khongmau(r);
		}	
	}
}

//ham de trong danh sach co bao nhieu tu
int demSLtu(hashnode *Tudien) {
	int sl = 0;
	NODEPTR p;
	for (int i = 0; i < 26; i++) {
		p = Tudien[i].head;
		if (p == NULL) 
			continue;
		else{
			while (p != NULL) {
				sl++;
				p = p->right;
			}
		}
	}
	return sl;
}

void menu(hashnode *Tudien) { //Ham khung nhap tu khoa va ket qua tim kiem
	NODEPTR p = NULL;
	bool thaydoi = false;//bien kiem tra xem da nhap vao khung tim kiem chua
	string intext = "";
	short dem = 0; //dem soluong ky tu nhap vao
	int keyhit = 0; //bat ky tu nhap vao
	short sang = 0; //vi tri thanh sang trong khung nhap tu
	short kt = 0;
	string str = "";
	while(true) {
		int sltu = demSLtu(Tudien);
		gotoxy(x, 26);
		cout << "\nso luong tu: "<< sltu;
		nhan_trangchu();
		khungtrangchu();
		
		//p =	tim_ds_dau(Tudien, p);
		if(thaydoi == true) {
			string str = chuanchuoi(intext);
			if(str == "") //neu chua nhap trong khung tim kiem
				p = tim_ds_dau(Tudien, p);
			else	//neu da nhaptrong khung tim kiem 
				p = timtu(Tudien, str);	
		}
		
		DStu_timduoc(Tudien, p,sang); //Hien thi ket qua tim kiem
		
		gotoxy(x+5+dem, y);
		keyhit = getch();
		switch (keyhit) {
			case 8:{//backspace
				if(dem > 0 ) {
					dem--;
					intext = intext.substr(0, intext.size() - 1); //Xoa ky tu cuoi trong string
					gotoxy(x+5,y);
					cout << intext;
					for(int i = 1; i < boxs - 11 - dem; i++) cout << " ";
				}
				break;
			}
		    case Enter: {// xem thong tin cua tu hien tai
		   	 	if(p != NULL)
				{
		   	 		int vitri = (int)p->info.tu[0]-97;
					khungthemtu();
					nhan_trangxemtu();
					xuattu(Tudien, p);
					int kytu;
					while(1){
						kytu = getch();
			    		if(kytu == Backspace){ //neu sua tu
							
			    			system("cls");
			    			sang = 0;
	    					thaydoi = true;
	    					for(int i = 0; i < intext.length(); i++)
	    					{
	    						gotoxy(x+5+i, y);
	    						cout << " ";
	    					}
	    					dem = 0;
	    					str = "";
	    					intext = "";
	    					gotoxy(x+5,y);
			    			SuaTu(Tudien, p);
							ghifile  = true;// bat bien kiem tra len true deghi file
							break;	
						}
						if(kytu == 224){
							sang = 0;
							kytu = 256 + getch();
							if(kytu == 339){// nut DELETE
							
				    			if(KTxoaTu(p) == true) {
				    				ghifile  = true;// bat bien kiem tra len true deghi file
			    					Delete_node(Tudien[vitri].head, p);
			    					sang = 0;
			    					thaydoi = true;
			    					for(int i = 0; i < intext.length(); i++)
			    					{
			    						gotoxy(x+5+i,y);
			    						cout << " ";
			    					}
			    					dem = 0;
			    					str = "";
			    					intext = "";
			    					gotoxy(x+5, y);
			    					system("cls");
									break;
								}
								else
									break;
							}
						}
						if(kytu == Esc){
							system("cls");
							break;
						}
					}
		   	 	}
		   	 	break;
			}
			case Tab:{	//them tu 
				system("cls");
				Tu tu;
				khungthemtu();
				nhan_quaylaiTT();
				NhapTu(Tudien,tu);
				system("cls");
				thaydoi = true;//bat bien thay doi de luw
				ghifile  = true;// bat bien kiem tra len true deghi file
				break;
			}
			case Esc: {		// thoat chuong trinh
				system("cls");
				return;
			}
			case 224:{// UP down
				int c = getch();
				if( c == Up){
					if(kt > 0)
					{
						kt--;
						sang--;
						if(sang<0)
							sang = 0;
						if(Tuphiatruoc(Tudien,p) != NULL)
							p = Tuphiatruoc(Tudien,p);
						else
							break;
					}
				}
				if(c == Down){
					if(kt < sltu-1)
					{
						sang++;
						kt++;
						if(sang >= 16)
							sang = 0;
						if(Tuphiasau(Tudien,p) != NULL)
							p = Tuphiasau(Tudien,p);
						else
							break;
					}
				}
				thaydoi = false;
				break;
			}
			default: {
				if((keyhit > 96 && keyhit < 123) || (keyhit > 64 && keyhit < 91) || (keyhit == 32) || (keyhit == 39) || (keyhit == 45)) {
					sang = 0;
					dem++;
					intext += char(keyhit);
					thaydoi = true;
					gotoxy(x+5,y);
					for (int i = 0; i < dem; i++) cout << intext[i];
					
				}
			}
		}
    }
    
}
int main()
{
	hashnode *Tudien = new hashnode[26];
	
	for(int i = 0; i < 26; i++) {
		Tudien[i].tail = NULL;
		Tudien[i].head = NULL;
	}
	docFile(Tudien);
	menu(Tudien);
	//neu cothay doi trong bo nho thi se bat dau ghi file
	if(ghifile == true){
		gotoxy(50, 10);
		setcolor(12);
		cout << "DU LIEU THAY DOI, DA GHI FILE" << endl;
		ghiFile(Tudien);
		setcolor(7);
	}
	delete []Tudien;
	return 0;
}
