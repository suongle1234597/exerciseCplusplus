//Bai 1. Viet chuong trinh giai phuong trinh bac 2 có dang: ax^2 + bx + c = 0

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a, b, c;
    cout << "\n Nhap a: "; cin >> a;
    cout << " Nhap b: "; cin >> b;
    cout << " Nhap c: "; cin >> c;
    cout << " Phuong trinh bac hai co dang: " << a << "x^2 + " << b << "x + " << c << " = 0";
    if (a==0)
    {
        if (b==0)
        {
            if(c==0) cout << "\n Phuong trinh vo so nghiem";
            else cout << "\n Phuong trinh vo nghiem";
        }
        else 
        {
            if(c==0) cout << "\n Phuong trinh co nghiem la: 0" ;
            else cout << "\n Phuong trinh co nghiem la: " << -(float)c/b;
        }
    }
    else
    {
        float denta;
        denta=b*b-4*a*c;
        if (denta==0) cout << "\n Phuong trinh co nghiem kep x1 = x2 = " << -(float)b/(2*a);
        else if (denta>0)
        {
            cout << "\n Phuong trinh co nghiem x1 = " << (float)(-b+sqrt(denta))/(2*a);
            cout << "\n Phuong trinh co nghiem x2 = " << (float)(-b-sqrt(denta))/(2*a);
        }
        else cout << "\n Phuong trinh vo nghiem";
    } 
    return 0;
}
