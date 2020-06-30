#include "myLib.h"


// Xóa màn hình
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0, 0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

//// Di chuyển con trỏ console đến vị trí có tọa độ (x, y)
//void gotoXY(int x, int y)
//{
//	COORD coord;
//	coord.X = x;
//	coord.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}

// Lấy tọa độ x hiện tại của con trỏ console
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}

// Lấy tọa độ y hiện tại của con trỏ console
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}

//// Xóa con trỏ nháy
//void noCursorType()
//{
//	CONSOLE_CURSOR_INFO info;
//	info.bVisible = FALSE;
//	info.dwSize = 20;
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
//}

// Đổi màu chữ
//// Tham số: Mã màu
//void setTextColor(int color)
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
//}

// Lấy nút bàn phím do người dùng bấm
// Trả về: Mã của phím
int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}

	return KEY_NONE;
}

// Di chuyển con trỏ console đến vị trí có tọa độ (x, y)
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Đặt màu cho chữ muốn in lên màn hình
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

// Đặt màu nền cho chữ muốn in lên màn hình
void SetBGColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

// Thiết lập chế độ hiển thị, có fullscreen hay không
BOOL NT_SetConsoleDisplayMode(HANDLE hOutputHandle, DWORD dwNewMode)
{
	typedef BOOL(WINAPI *SCDMProc_t) (HANDLE, DWORD, LPDWORD);
	SCDMProc_t SetConsoleDisplayMode;
	HMODULE hKernel32;
	BOOL bFreeLib = FALSE, ret;
	const char KERNEL32_NAME[] = "kernel32.dll";

	hKernel32 = GetModuleHandleA(KERNEL32_NAME);
	if (hKernel32 == NULL)
	{
		hKernel32 = LoadLibraryA(KERNEL32_NAME);
		if (hKernel32 == NULL)
			return FALSE;

		bFreeLib = true;
	}

	SetConsoleDisplayMode =
		(SCDMProc_t)GetProcAddress(hKernel32, "SetConsoleDisplayMode");
	if (SetConsoleDisplayMode == NULL)
	{
		SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
		ret = FALSE;
	}
	else
	{
		DWORD tmp;
		ret = SetConsoleDisplayMode(hOutputHandle, dwNewMode, &tmp);
	}

	if (bFreeLib)
		FreeLibrary(hKernel32);

	return ret;
}

// Đặt chế độ FullScreen
void setFullScreen()
{
	NT_SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), 1);
}

// Thoát khỏi fullscreen
void exitFullScreen()
{
	NT_SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), 0);
}

// Ẩn hiện con trỏ nhấp nháy trong cửa sổ Console
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

//// Xóa toàn bộ nội dung cửa sổ console - chôm từ MSDN
//void clrscr()
//{
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Lấy handle cửa sổ console hiện hành
//	COORD coordScreen = { 0, 0 };    // home for the cursor 
//	DWORD cCharsWritten;
//	CONSOLE_SCREEN_BUFFER_INFO csbi;
//	DWORD dwConSize;
//
//	// Get the number of character cells in the current buffer. 
//
//	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
//		return;
//	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
//
//	// Fill the entire screen with blanks.
//
//	if (!FillConsoleOutputCharacter(hConsole, (TCHAR) ' ',
//		dwConSize, coordScreen, &cCharsWritten))
//		return;
//
//	// Get the current text attribute.
//
//	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
//		return;
//
//	// Set the buffer's attributes accordingly.
//
//	if (!FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
//		dwConSize, coordScreen, &cCharsWritten))
//		return;
//
//	// Put the cursor at its home coordinates.
//
//	SetConsoleCursorPosition(hConsole, coordScreen);
//}

// Kiểm tra xem phím nào được nhấn, trả về true nếu phím đó đã được nhấn xuống
bool checkKey(int key)
{
	return GetAsyncKeyState(key);
}

// Hàm thay đổi kích cỡ của khung cmd với tham số truyền vào là chiều cao, chiều rộng.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// HÀM PHÁT SINH 
//Cách 1: Dùng hàm kbhit có trong thư viện #include <conio.h>
//kbhit(void) : Kiểm tra xem người dùng có nhấn vào 1 phím bất kỳ nào trên bàn phím hay không ?
//= > Lấy giá trị của phím đó ra nhờ vào getch();
//vd:
//if (kbhit())
//{
//	char c = getch();
//	printf("\nNguoi dung dang nhan vao phim %c", c);
//}
//Cách 2: Dùng hàm GetAsyncKeyState(<Key cần nhập>) có trong thư viện : #include <Windows.h>
//vd :
//   GetAsyncKeyState(VK_UP); // Đang nhấn vào phím mũi tên đi lên.
//GetAsyncKeyState(VK_DOWN); // Đang nhấn vào phím mũi tên đi xuống.
//GetAsyncKeyState(VK_LEFT); // Đang nhấn vào phím mũi tên qua trái.
//GetAsyncKeyState(VK_RIGHT); // Đang nhấn vào phím mũi tên qua phải.
//
//Với cách 1, chỉ có các phím chữ, số mới có mã ASCII đơn.Các phím mũi tên hay các phím F1, F2, ... đều có mã kép.Mã kép ko phải là lấy 2 số cộng nhau, mà là phải getch() 2 lần liên tiếp.Ví dụ trong trường hợp phím mũi tên lên :
//
//C++ Code :
//1. int n = getch();
//2. if (n == 224)
//3. {
//	4.    n = getch(); //getch lần 2
//	5.    if (n == 72)
//		6.       cout << "Dung"; //Là phím mũi tên lên, nếu n == 80 là mũi tên xuống
//	7.    else
//		8.       cout << "Sai";
//	9. }
//10. else
//11. {
//	12.    cout << "Sai";
//	13. }﻿