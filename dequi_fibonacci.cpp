#include <iostream>
using namespace std;

int Tinh(int n) {
	if(n == 0 || n == 1) {
//		cout << "1 ";
		return 1;
	}
//	cout << Tinh(n);
	return Tinh(n - 1) + Tinh(n - 2);
}

int main() {
	int n;
	cout << "\nNhap n: ";
	cin >> n;
	cout << "So fibonacci la: " << Tinh(n);
	return 0;
}
