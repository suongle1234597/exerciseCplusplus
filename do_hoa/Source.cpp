#include<iostream>
using namespace std;
#include"myLib.h"

int main()
{
	/* ========================= XỬ LÝ 1 ========================= */
	int i = 0;
	int x = 10;
	int y = 0;
	while (true)
	{
		gotoXY(x, y);

		SetColor(i);
		i++;
		if (i >= 16)
		{
			i = 0;
		}

		cout << "HOC LAP TRINH THAT DE QUA DI AHIHI";
		y++; // tọa độ trục tung tăng lên vì đang cho vật thể hướng xuống
		Sleep(200);
	}


	/* ========================= XỬ LÝ 2 ========================= */
	//int i = 0;
	//int x = 10; // tọa độ x ban đầu của vật thể
	//int y = 0; // tọa độ y ban đầu của vật thể
	//int check = 0; // 0: đụng biên trên và đang đi xuống, 1: đụng biên dưới và đang đi lên
	//while (true)
	//{
	//	system("cls"); // xóa tất cả những gì trên màn hình
	//	gotoXY(x, y); // di chuyển vật thể đến tọa độ x và y trên console

	//	// BƯỚC 1: kiểm tra xem cái vật thể đang hướng chiều nào
	//	if (y == 0)
	//	{
	//		check = 0;
	//	}
	//	else if (y == 25)
	//	{
	//		check = 1;
	//	}
	//	// BƯỚC TIẾP CỦA BƯỚC 1: kiểm tra cái check để xét tọa độ y
	//	if (check == 0)
	//	{
	//		y++;
	//	}
	//	else if (check == 1)
	//	{
	//		y--;
	//	}


	//	// in chữ theo màu i
	//	SetColor(i);
	//	i++;
	//	if (i >= 16)
	//	{
	//		i = 0;
	//	}

	//	cout << "HOC LAP TRINH THAT DE QUA DI AHIHI";
	//	Sleep(100);
	//}


	/* ========================= XỬ LÝ 3 ========================= */
	//int i = 0; // màu của những gì hiện lên màn hình
	//int x = 10;
	//int y = 0;
	//// 0: đụng biên trên và đang đi xuống, 1: đụng biên dưới và đang đi lên
	//// 2: đụng biên trái và đang đi qua phải; 3: đụng biên phải và đang đi qua trái
	//int check = 0;
	//while (true)
	//{
	//	system("cls");
	//	gotoXY(x, y);

	//	// BƯỚC 1: XỬ LÝ PHÍM ĐIỀU KHIỂN LÀ PHÍM ĐƠN
	//	if (kbhit()) // kiểm tra xem người dùng có đang nhấn phím gì hay không
	//	{
	//		char kitu = getch();
	//		if (kitu == 'W' || kitu == 'w') // phím lên bằng w
	//		{
	//			check = 1;
	//		}
	//		else if (kitu == 's' || kitu == 'S') // phím xuống bằng s
	//		{
	//			check = 0;
	//		}
	//	}


	//	// BƯỚC TIẾP CỦA BƯỚC 1: kiểm tra cái check để xét tọa độ y
	//	if (check == 0)
	//	{
	//		y++;
	//	}
	//	else if (check == 1)
	//	{
	//		y--;
	//	}

	//	// kiểm tra xem nó có đang vượt ra khỏi 2 cái biên trên và dưới hay không
	//	if (y == 0)
	//	{
	//		check = 0;
	//	}
	//	else if (y == 25)
	//	{
	//		check = 1;
	//	}

	//	// in chữ theo màu i
	//	SetColor(i);
	//	i++;
	//	if (i >= 16)
	//	{
	//		i = 0;
	//	}
	//	cout << "HOC LAP TRINH THAT DE QUA DI AHIHI";
	//	Sleep(100);
	//}

	/* ========================= XỬ LÝ 4 ========================= */
	//int i = 0;
	//int x = 10;
	//int y = 0;
	//// 0: đụng biên trên và đang đi xuống, 1: đụng biên dưới và đang đi lên
	//// 2: đụng biên trái và đang đi qua phải; 3: đụng biên phải và đang đi qua trái
	//int check = 0;
	//while (true)
	//{
	//	system("cls");
	//	gotoXY(x, y);

	//	// nhấn vào phím chức năng: lên - xuống - trái - phải - PHÍM KÉP
	//	if (kbhit()) // hàm kbhit() là hàm xem người dùng có nhấn phím nào trong lúc chương trình đang chạy hay không
	//	{
	//		char c = getch();
	//		if (c == -32)
	//		{
	//			c = getch();
	//			if (c == 72) // mã ascii mũi tên lên
	//			{
	//				check = 1;
	//			}
	//			else if (c == 80) // mã ascii mũi tên xuống
	//			{
	//				check = 0;
	//			}
	//			else if (c == 75) // mã ascii mũi tên trái
	//			{
	//				check = 3;
	//			}
	//			else if (c == 77) // mã ascii mũi tên phải
	//			{
	//				check = 2;
	//			}
	//		}
	//	}


	//	// BƯỚC TIẾP CỦA BƯỚC 1: kiểm tra cái check để xét tọa độ y
	//	if (check == 0)
	//	{
	//		y++;
	//	}
	//	else if (check == 1)
	//	{
	//		y--;
	//	}
	//	else if (check == 2)
	//	{
	//		x++;
	//	}
	//	else if (check == 3)
	//	{
	//		x--;
	//	}

	//	// kiểm tra xem nó có đang vượt ra khỏi 2 cái biên trên và dưới hay không
	//	if (y == 0)
	//	{
	//		check = 0;
	//	}
	//	else if (y == 25)
	//	{
	//		check = 1;
	//	}
	//	else if (x == 0)
	//	{
	//		check = 2;
	//	}
	//	else if (x == 80)
	//	{
	//		check = 3;
	//	}

	//	// in chữ theo màu i
	//	SetColor(i);
	//	i++;
	//	if (i >= 16)
	//	{
	//		i = 0;
	//	}
	//	cout << "HOC LAP TRINH THAT DE QUA DI AHIHI";
	//	Sleep(100);
	//}
	system("pause");
}