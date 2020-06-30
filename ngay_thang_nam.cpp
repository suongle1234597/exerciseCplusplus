/* Dong thoi gian - Cho 2 bo ngay thang nam co dinh dang nhu sau: dd/mm/yyyy (1/1/1970 - 31/12/2050)
   Tinh so ngay trong 2 ngay do, thu tu ngay khong quan trong 
vd: 20/11/2015 - 21/11/2015 -> 1 ngay
    02/01/2016 - 21/11/2015 -> 42 ngay */ 

#include <iostream>
using namespace std;

bool KiemTra(int ngay, int thang, int nam) {
	if ((nam % 100 != 0 && nam % 4 == 0) || (nam % 400 == 0) || (ngay > 1 && thang > 1 && nam > 1970) || (ngay < 31 && thang < 12 && nam < 2050)) {
		if(thang==2) {
			if(ngay<=29) return true;
		}
		else if(thang==4 || thang==6 || thang==9 || thang==11) {
			if(ngay<=30) return true;
		}
		else {
			if(ngay<=31) return true;
	    }
	}
	else if ((nam % 100 == 0 && nam % 4 != 0) || (nam % 400 != 0) || (ngay > 1 && thang > 1 && nam > 1970) || (ngay < 31 && thang < 12 && nam < 2050)) {
		if(thang==2) {
			if(ngay<=28) return true; 
		}
		else if(thang==4 || thang==6 || thang==9 || thang==11) {
			if(ngay<=30) return true; 
		}
		else if(ngay<=31) return true; 
	}
	else return false;
}

bool KT_Nam_Nhuan (int nam) {
	if ((nam % 100 != 0 && nam % 4 == 0) || (nam % 400 == 0)) return true;
	else return false;
}

void HoanDoi (int ngayd, int thangd, int namd, int ngays, int thangs, int nams) {
	int tam1, tam2, tam3;
	// Hoan doi ngay
	tam1 = ngayd;
	ngayd = ngays;
	ngays = tam1;
	// Hoan doi thang
	tam2 = thangd;
	thangd = thangs;
	thangs = tam2;
	// Hoan doi nam
	tam3 = namd;
	namd = nams;
	nams = tam3;		
}

int TinhNgay(int ngayd, int thangd, int namd, int ngays, int thangs, int nams) {
	int dem = 0;
	if (namd = nams && thangd == thangs) {
		if (ngayd <= ngays) dem = ngays - ngayd;
		else dem = ngayd - ngays;
	}
	else {
		if (namd > nams) HoanDoi(ngayd, thangd, namd, ngays, thangs, nams);
		for (int i = thangd; i <= 12; i++) {
			if(i == 2) {
				for (int j = 1; j <= 28; j++) dem++;
			}
	    	else if(i == 4 || i == 6 || i == 9 || i == 11) {
        		for (int j = 1; j <= 30; j++) dem++;
			}
			else {
				for (int j = 1; j <= 31; j++) dem++;
			}
		}
    	for (int i = 1; i <= thangs; i++) {
        	if(i == 2) {
	    		for (int j = 1; j <= 28; j++) dem++;
			}
	    	else if(i == 4 || i == 6 || i == 9 || i == 11) {
	    		for (int j = 1; j <= 30; j++) dem++;
			}
			else {
				for (int j = 1; j <= 31; j++) dem++;
			}
    	}
//    	if (nams - namd > 1) {
//       		for (int i = namd; i <= nams; i++) {
//       	   		if(KT_Nam_Nhuan(i) == true) dem = dem + 366;
//       	   		else dem = dem + 365;
//	   		}	
//    	}
    	return dem;
	}
}

int main () {
	int ngayd, thangd, namd, ngays, thangs, nams;
	do {
		cout << " Nhap ngay ban dau: "; cin >> ngayd;
	    cout << " Nhap thang ban dau: "; cin >> thangd;
	    cout << " Nhap nam ban dau: "; cin >> namd;
	    
	    if (KiemTra(ngayd, thangd, namd) == false) cout << " Xin nhap lai ngay, thang, nam hop le!";
	} while (KiemTra(ngayd, thangd, namd) == false);
	
	do {
		cout << " Nhap ngay sau: "; cin >> ngays;
	    cout << " Nhap thang sau: "; cin >> thangs;
	    cout << " Nhap nam sau: "; cin >> nams;
	    
	    if (KiemTra(ngays, thangs, nams) == false) cout << " Xin nhap lai ngay, thang, nam hop le!";
	} while (KiemTra(ngays, thangs, nams) == false);
	
	cout << TinhNgay (ngayd, thangd, namd, ngays, thangs, nams) << " ngay.";
	return 0;
}
