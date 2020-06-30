#include <iostream>
using namespace std;

int Tinh_Tong(int n) {
	if(n == 1) {
		return 1;
	}
	return Tinh_Tong(n - 1) + n;
}

int main() {
	int n;
	cout << "\nNhap n: ";
	cin >> n;
	cout << "Tong la: " << Tinh_Tong(n);
	return 0;
}
