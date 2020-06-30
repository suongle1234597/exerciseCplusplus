/* String: Ki_Thuat_Lap_Trinh*/

#include <iostream>
#include <string>
using namespace std;

void Xoa_Khoang_Trang_O_Dau(string &str) {
	while (str[0] == 32) { // khoang trang la 32
	//xoa ki tu tai vi tri 0. begin() lay ki tu dau tien
		str.erase(str.begin() + 0); // xoa n ki tu ke tu vi tri (str.begin() + 0), k co gia tri n	thi tat ca cac ki tu cua str thi vi tri (str.begin() + 0) tro di se bi xoa
	}
}

void Xoa_Khoang_Trang_O_Cuoi(string &str) {
	while (str[str.length() - 1] == 32) {
		str.erase(str.begin() + (str.length() - 1));
	}
}

void Xoa_Nhieu_Khoang_Trang(string &str) {
	for(int i = 0; i < str.length() - 1; i++) {
		if(str[i] == 32 && str[i + 1] == 32) {
			str.erase(str.begin() + i);
			i--; 
		}
	}
}

void Chu_Dau_La_Chu_Hoa(string &str) {
	if (str[0] >= 'a' && str[0] <= 'z') str[0] = str[0] - 32;
	for (int i = 1; i < str.length(); i++) {
 		if (str[i] == 32) {
 			str[i + 1] = str[i + 1] - 32;
 			i++;
		}
 		else {
 			if (str[i] >= 'A' && str[i] <= 'Z') {
 				str[i] = str[i] + 32;
			}
		}
	}
}

void ChuanHoa(string &str) {
	Xoa_Khoang_Trang_O_Dau(str);
	Xoa_Khoang_Trang_O_Cuoi(str);
	Xoa_Nhieu_Khoang_Trang(str);
	Chu_Dau_La_Chu_Hoa(str);
}

int main () {
	string str;
	cout << " Nhap chuoi: "; getline(cin,str);
	ChuanHoa(str);
	cout << " Xuat chuoi: " << str;
	return 0;
}


