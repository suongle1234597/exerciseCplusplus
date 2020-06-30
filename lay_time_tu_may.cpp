#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

using namespace std;
const string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now); //khai bao tstruct theo struct tm  .struct tm: là struct dac biet dung cho TG
    strftime(buf, sizeof(buf), "Ngay thi: %d-%m-%Y \nThoi gian bat dau: %X", &tstruct);

    return buf;
}

int main() {
	time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    int sophut, i = 0, j = 0;
    tstruct = *localtime(&now); //khai bao tstruct theo struct tm  .struct tm: là struct dac biet dung cho TG
    strftime(buf, sizeof(buf), "Ngay thi: %d-%m-%Y \nThoi gian bat dau: %X", &tstruct);
    cout << buf << endl;
    cout << "\nNhap so phut thi: "; cin >> sophut;
//    if((tstruct.tm_min + sophut) < 60) {
//    	cout << "Thoi gian ket thuc: "<< tstruct.tm_hour << ":";
//   		cout << sophut + tstruct.tm_min << ":";
//   		cout <<  tstruct.tm_sec << endl;
//	} else{
//		i = (tstruct.tm_min + sophut) % 60;
//		j = (tstruct.tm_min + sophut) / 60;
//		cout << "Thoi gian ket thuc: "<< j + tstruct.tm_hour << ":";
//   		cout << i << ":";
//   		cout << tstruct.tm_sec << endl;
//	}
	
	
    return 0;
}
