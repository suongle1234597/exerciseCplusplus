#include<iostream>
using namespace std;
#include<string> // thu vi?n h? tr? các hàm thao tác chu?i string

int main()
{
	/*string str;
	cout << "\nNhap chuoi: ";
	getline(cin, str); // nh?n kí t? kho?ng tr?ng
	cout << "\nChuoi nhan duoc la: " << str;
	cout << "\nDo dai chuoi: " << str.length(); */

	//string s1 = "lap";
	//string s2 = "trinh";
	//cout << s1 + " " + s2;
	//string s3 = s1 + ' ' + s2;
	//cout << s3;
	//stricmp((char *)s1.c_str(),(char *) s2.c_str());
	// hàm c._str(): hàm chuy?n chu?i string sang chu?i ký t?
	/*for (int i = 0; i < s1.length(); i++)
	{
		cout << s1[i] << endl;
	}*/

	string str;
	cout << "\nNhap chuoi: ";
	getline(cin, str);
	cout << "\nChuoi nhan duoc la:" << str;
	cout << "\nDo dai chuoi : " << str.length();

	/* =============== XÓA ============= */
	//str.erase(2, 3); // str.erase(x, y); // Xóa di y ký t? b?t d?u t?i v? trí x.
	//cout << "\nChuoi sau khi xoa:" << str;
	//cout << "\nDo dai sau khi xoa:" << str.length();

	//str.erase(str.begin() + x); // Xóa di ký t? t?i v? trí x.
	/*str.erase(str.begin() + 3);
	cout << "\nChuoi sau khi xoa:" << str;
	cout << "\nDo dai sau khi xoa:" << str.length();*/

	/* =============== THÊM ============= */
	/*str.push_back('T');
	cout << "\nChuoi sau khi them:" << str;
	cout << "\nDo dai sau khi them:" << str.length();*/

	//str.insert(x, "y"); // Thêm chu?i y vào v? trí x.
	/*str.insert(2, "lap trinh");
	cout << "\nChuoi sau khi them:" << str;
	cout << "\nDo dai sau khi them:" << str.length();*/

	//str.insert(str.begin() + x, 'y'); // Thêm ký t? y vào v? trí x.
	str.insert(str.begin() + 2 , 'y');
	cout << "\nChuoi sau khi them:" << str;
	cout << "\nDo dai sau khi them:" << str.length();

	return 0;
}
