void GhiFileLop(LISTLOP &list) {
	ofstream fileout;
 	fileout.open("LOP.txt", ios_base::in);
 	if(!fileout.fail()) {
 		for (int i=0; i < list.n; i++) {
 			fileout << list.nodeLop[i]->maLop << endl;
 			fileout << list.nodeLop[i]->tenLop << endl;
		}
		fileout.close();
	}
}

void DocFileLop(LISTLOP &list) {
	ifstream filein;
	filein.open("LOP.txt", ios_base::in);
	LOP lop;
	if(filein.fail()) return;
	else {
		list.n = 0;
		while(!filein.eof()) {
			filein.getline(lop.maLop,16);
			filein.getline(lop.tenLop,30);
 			list.nodeLop[list.n]=new LOP;
 			*list.nodeLop[list.n]=lop;
 			list.n ++;
			if(filein == NULL) {
				list.n--;
	        	break;
	    	}
		}
	}
	filein.close();
}

void DuyetFileSV(LISTSV &l, ofstream &fileout)
{
	if(l.pHead == NULL) return; 
	for(NODESV *k = l.pHead; k != NULL; k = k->pNext) {
		fileout << k->sv.maSV << endl;
        fileout << k->sv.ho << endl;
        fileout << k->sv.ten << endl;
        fileout << k->sv.phai << endl;
        fileout << k->sv.password << endl;
	}
}

void GhiFileSV(LISTSV &l) {
	ofstream fileout;
	fileout.open("SINHVIEN.txt", ios_base::in);
	if(!fileout.fail()) {
		DuyetFileSV(l, fileout);
		fileout.close();
	}
}

void DocFileSV(LISTSV &l) {
	ifstream filein;
	SinhVien sv;
	filein.open("SINHVIEN.txt", ios_base::in);
	
	if(filein.fail()) return;
	else{
		while(!filein.eof()) {
			filein.getline(sv.maSV,16);
			filein.getline(sv.ho,30);
			filein.getline(sv.ten,10);
			filein.getline(sv.phai,4);
			filein.getline(sv.password,20);
			NODESV *p = KhoiTaoNODESV(sv);
			if(filein == NULL) {
	        	break;
	    	}
			ThemVaoCuoiDSSV(l, p);
		}
		filein.close();
	}
}
