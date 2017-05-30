#include "MyLibrary.h"

//Các hàm trong thư viện để vẽ
void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x,y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
int wherex(void)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.X;
}
int wherey(void)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.Y;
}
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

//Set Color cho Text
void setGreenText()
{
	SetBGColor(0);
	SetColor(10);
}
void setNormallText()
{
	SetBGColor(0);
	SetColor(15);
}

//Các hàm setColor khác
void normal() {
	SetColor(15);
	SetBGColor(0);
}
void normalButton() {
	SetColor(15);
	SetBGColor(4);
}
void highLight() {
	SetColor(15);
	SetBGColor(12);
}
void colorStroke() {
	SetColor(4);
}

//Các hàm xử lí chuỗi
void xoaKiTu(char a[], int & n, int i)
{
	for (int j = i; j < n - 1; ++j)
	{
		a[j] = a[j + 1];
	}
	--n;
}
void themKiTu(char a[], int & n, int & i, char c)
{
	for (int j = n; j > i; --j)
	{
		a[j] = a[j - 1];
	}
	a[i] = c;
	n++;
}

//-----------------CÁC HÀM NHẬP CHUỖI-----------------------
//Nhap chuoi co khoang trang (khong chua chu so)
int NhapChuoi(char a[], int MAX, int x, int y)
{
	int length = strlen(a);
	if (length == 0)
	{
		gotoxy(x, y);
	}
	else
	{
		gotoxy(x + length, y);
	}
	int kiTu = 0;
	int i = length;
	//n cho biet so luong cac ki tu trong mang a
	int n = length;
	while (true)
	{
		kiTu = 0;
		fflush(stdin);
		char temp = _getch();
		if (temp == -32 || temp == 0)
		{
			temp = _getch();
			kiTu = temp + 1000;
		}
		else
		{
			kiTu = temp;
		}

			if (n >= MAX - 1 && kiTu != Enter && kiTu != BackSpace && kiTu != Left && kiTu != Right && kiTu != ESC)
			{
				continue;
			}
			else
			{
				if (kiTu == Enter && n != 0)
				{
					a[n] = '\0';
					break;
				}
				else if (kiTu == BackSpace && i > 0 && i == n)
				{
					gotoxy(wherex() - 1, wherey());
					a[i] = ' ';
					cout << a[i--];
					n--;
					gotoxy(wherex() - 1, wherey());
					continue;
				}
				else if (kiTu == Left && i > 0)
				{
					i--;
					gotoxy(wherex() - 1, wherey());
					continue;
				}
				else if (kiTu == Right && i < n)
				{
					i++;
					gotoxy(wherex() + 1, wherey());
					continue;
				}
				else if (kiTu == BackSpace && i > 0)
				{
					int viTriHT = wherex();
					i--;
					xoaKiTu(a, n, i);
					gotoxy(viTriHT - 1, wherey());
					for (int j = i; j < n; ++j)
					{
						cout << a[j];
					}
					cout << " ";
					gotoxy(viTriHT - 1, wherey());
				}
				else if (kiTu == Delete)
				{
					int viTriHT = wherex();
					xoaKiTu(a, n, i);
					gotoxy(viTriHT, wherey());
					for (int j = i; j < n; ++j)
					{
						cout << a[j];
					}
					cout << " ";
					gotoxy(viTriHT, wherey());
				}
				/* a[i - 1] != ' ': Kí tự trước mặt nó khác khoảng trắng mới Space được,
				   n != 0: Khi không có kí tự không cho bám Space
				*/
				else if (kiTu == Space && a[i - 1] != ' ' && n != 0)
				{
					int viTri = wherex();
					themKiTu(a, n, i, temp);
					gotoxy(viTri, wherey());
					for (int j = i; j < n; ++j)
					{
						cout << a[j];
					}
					i++;
					gotoxy(viTri + 1, wherey());
				}
			}
			if (kiTu >= 'a' && kiTu <= 'z')
			{
				kiTu -= 32;
			}
			if (kiTu >= 'A' && kiTu <= 'Z')
			{
				int viTri = wherex();
				themKiTu(a, n, i, kiTu);
				gotoxy(viTri, wherey());
				for (int j = i; j < n; ++j)
				{
					cout << a[j];
				}
				i++;
				gotoxy(viTri + 1, wherey());
			}
			if (kiTu == ESC)
			{
				a[n] = '\0';
				return (int)kiTu;
			}
		}
		return 0;
}

//Chuoi va chu so khong co khoang trang
int NhapChuoiVaChuSo(char a[], int MAX, int x, int y)
{
	int length = strlen(a);
	gotoxy(x + length, y);

	int kiTu = 0;
	//i lưu vị trí con nháy
	int i = length;
	//n cho biet so luong cac ki tu trong mang a
	int n = length;
	while (true)
	{
		kiTu = 0;
		fflush(stdin);
		char temp = _getch();
		if (temp == -32 || temp == 0)
		{
			temp = _getch();
			kiTu = temp + 1000;
		}
		else
		{
			kiTu = temp;
		}
		if (n >= MAX - 1 && kiTu != Enter && kiTu != BackSpace && kiTu != Left && kiTu != Right && kiTu != ESC)
		{
			continue;
		}
		if (n == 0 && kiTu == Enter)
		{
			a[n] = '\0';
			return -1;
		}
		else
		{
			if (kiTu == Enter)
			{
				a[n] = '\0';
				return 0;
			}
			else if (kiTu == BackSpace && i > 0 && i == n)
			{
				gotoxy(wherex() - 1, wherey());
				a[i] = ' ';
				cout << a[i--];
				n--;
				gotoxy(wherex() - 1, wherey());
				continue;
			}
			else if (kiTu == Left && i > 0)
			{
				i--;
				gotoxy(wherex() - 1, wherey());
				continue;
			}
			else if (kiTu == Right && i < n)
			{
				i++;
				gotoxy(wherex() + 1, wherey());
				continue;
			}
			else if (kiTu == BackSpace && i > 0)
			{
				int viTriHT = wherex();
				i--;
				xoaKiTu(a, n, i);
				gotoxy(viTriHT - 1, wherey());
				for (int j = i; j < n; ++j)
				{
					cout << a[j];
				}
				cout << " ";
				gotoxy(viTriHT - 1, wherey());
			}
			else if (kiTu == Delete)
			{
				int viTriHT = wherex();
				xoaKiTu(a, n, i);
				gotoxy(viTriHT, wherey());
				for (int j = i; j < n; ++j)
				{
					cout << a[j];
				}
				cout << " ";
				gotoxy(viTriHT, wherey());
			}
		}
		if (kiTu >= 'a' && kiTu <= 'z')
		{
			kiTu -= 32;
		}
		if (kiTu >= 'A' && kiTu <= 'Z' || kiTu >= '0' && kiTu <= '9')
		{
			int viTri = wherex();
			themKiTu(a, n, i, kiTu);
			gotoxy(viTri, wherey());
			for (int j = i; j < n; ++j)
			{
				cout << a[j];
			}
			i++;
			gotoxy(viTri + 1, wherey());
		}
		if (kiTu == ESC)
		{
			a[n] = '\0';
			return (int)kiTu;
		}
	}
}
//Nhap so khong co khoang trang ki tu dac biet
int NhapSo(char a[], int MAX, int x, int y)
{
	int length = strlen(a);
	
	gotoxy(x + length, y);

	int kiTu = 0;
	//Lưu vị trí con nháy
	int i = length;
	//n cho biet so luong cac ki tu trong mang a
	int n = length;

	while (true)
	{
		kiTu = 0;
		fflush(stdin);
		char temp = _getch();
		if (temp == -32 || temp == 0)
		{
			temp = _getch();
			kiTu = temp + 1000;
		}
		else
		{
			kiTu = temp;
		}
		if (n >= MAX - 1 && kiTu != Enter && kiTu != BackSpace && kiTu != Left && kiTu != Right && kiTu != ESC)
		{
			continue;
		}
		else
		{
			if (kiTu == Enter && n != 0)
			{
				a[n] = '\0';
				break;
			}
			else if (kiTu == BackSpace && i > 0 && i == n)
			{
				gotoxy(wherex() - 1, wherey());
				a[i] = ' ';
				cout << a[i--];
				n--;
				gotoxy(wherex() - 1, wherey());
				continue;
			}
			else if (kiTu == Left && i > 0)
			{
				i--;
				gotoxy(wherex() - 1, wherey());
				continue;
			}
			else if (kiTu == Right && i < n)
			{
				i++;
				gotoxy(wherex() + 1, wherey());
				continue;
			}
			else if (kiTu == BackSpace && i > 0)
			{
				int viTriHT = wherex();
				i--;
				xoaKiTu(a, n, i);
				gotoxy(viTriHT - 1, wherey());
				for (int j = i; j < n; ++j)
				{
					cout << a[j];
				}
				cout << " ";
				gotoxy(viTriHT - 1, wherey());
			}
			else if (kiTu == Delete)
			{
				int viTriHT = wherex();
				xoaKiTu(a, n, i);
				gotoxy(viTriHT, wherey());
				for (int j = i; j < n; ++j)
				{
					cout << a[j];
				}
				cout << " ";
				gotoxy(viTriHT, wherey());
			}
		}
		if (kiTu >= '0' && kiTu <= '9')
		{
			int viTri = wherex();
			themKiTu(a, n, i, kiTu);
			gotoxy(viTri, wherey());
			for (int j = i; j < n; ++j)
			{
				cout << a[j];
			}
			i++;
			gotoxy(viTri + 1, wherey());
		}
		if (kiTu == ESC)
		{
			a[n] = '\0';
			return (int)kiTu;
		}
	}
	return 0;
}
//Nhap chuoi không khoảng trắng
int NhapTen(char a[], int MAX, int x, int y)
{
	int length = strlen(a);
	if (length == 0)
	{
		gotoxy(x, y);
	}
	else
	{
		gotoxy(x + length, y);
	}
	int kiTu = 0;
	int i = length;
	//n cho biet so luong cac ki tu trong mang a
	int n = length;
	while (true)
	{
		kiTu = 0;
		fflush(stdin);
		char temp = _getch();
		if (temp == -32 || temp == 0)
		{
			temp = _getch();
			kiTu = temp + 1000;
		}
		else
		{
			kiTu = temp;
		}
		if (n >= MAX - 1 && kiTu != Enter && kiTu != BackSpace && kiTu != Left && kiTu != Right && kiTu != ESC)
		{
			continue;
		}
		else
		{
			if (kiTu == Enter && n!= 0)
			{
				a[n] = '\0';
				break;
			}
			else if (kiTu == BackSpace && i > 0 && i == n)
			{
				gotoxy(wherex() - 1, wherey());
				a[i] = ' ';
				cout << a[i--];
				n--;
				gotoxy(wherex() - 1, wherey());
				continue;
			}
			else if (kiTu == Left && i > 0)
			{
				i--;
				gotoxy(wherex() - 1, wherey());
				continue;
			}
			else if (kiTu == Right && i < n)
			{
				i++;
				gotoxy(wherex() + 1, wherey());
				continue;
			}
			else if (kiTu == BackSpace && i > 0)
			{
				int viTriHT = wherex();
				i--;
				xoaKiTu(a, n, i);
				gotoxy(viTriHT - 1, wherey());
				for (int j = i; j < n; ++j)
				{
					cout << a[j];
				}
				cout << " ";
				gotoxy(viTriHT - 1, wherey());
			}
			else if (kiTu == Delete)
			{
				int viTriHT = wherex();
				xoaKiTu(a, n, i);
				gotoxy(viTriHT, wherey());
				for (int j = i; j < n; ++j)
				{
					cout << a[j];
				}
				cout << " ";
				gotoxy(viTriHT, wherey());
			}
		}
		if (kiTu >= 'a' && kiTu <= 'z')
		{
			kiTu -= 32;
		}
		if (kiTu >= 'A' && kiTu <= 'Z')
		{
			int viTri = wherex();
			themKiTu(a, n, i, kiTu);
			gotoxy(viTri, wherey());
			for (int j = i; j < n; ++j)
			{
				cout << a[j];
			}
			i++;
			gotoxy(viTri + 1, wherey());
		}
		if (kiTu == ESC)
		{
			a[n] = '\0';
			return (int)kiTu;
		}
	}
	return 0;
}

//Các hàm vẽ Khung
void veLineNamNgang(int x, int y, int width, int maMau = 15)
{
	SetColor(maMau);
	gotoxy(x, y);
	for (int i = 0; i < width; ++i)
	{
		cout << (char)196;
	}
}
void veLineThangDung(int x, int y, int height, int maMau = 15)
{
	SetColor(maMau);
	for (int i = y; i < y + height; ++i)
	{
		gotoxy(x, i);
		cout << (char)179;
	}
}
void veGocTrenBenTrai(int x, int y, int maMau = 15)
{
	SetColor(maMau);
	gotoxy(x, y);
	cout << char(218);
}
void veGocTrenBenPhai(int x, int y, int maMau)
{
	gotoxy(x, y);
	cout << char(191);
}
void veGocDuoiBenTrai(int x, int y, int maMau)
{
	gotoxy(x, y);
	cout << char(192);
}
void veGocDuoiBenPhai(int x, int y, int maMau)
{
	gotoxy(x, y);
	cout << char(217);
}

//Cac ham ve giao dien
void xoaNoiDungVe(int x, int y, int width, int height)
{
	normal();
	for (int i = 0; i <= height; ++i)
	{
		gotoxy(x, y + i);
		for (int j = 0; j <= width; ++j)
		{
			cout << " ";
		}
	}
}
void veKhungNhapTTLop()
{
	for (int i = MINY_BLOP + 1; i < MAXY_BLOP; ++i)
	{
		gotoxy(MINX_BLOP, i);
		cout << char(179);
		gotoxy(MAXX_BLOP, i);
		cout << char(179);
		gotoxy(MINX_BLOP, i);
		cout << char(179);
		//Ve Cot 1
		gotoxy(xCot1, i);
		cout << char(179);

		//Ve Cot 2
		gotoxy(xCot2, i);
		cout << char(179);
	}
	for (int i = MINX_BLOP + 1; i < MAXX_BLOP; ++i)
	{
		gotoxy(i, MINY_BLOP);
		cout << char(196);
		gotoxy(i, MAXY_BLOP);
		cout << char(196);
		gotoxy(i, MINY_BLOP + 2);
		cout << char(196);
	}
	//Ve them thanh ngang
	gotoxy(MINX_BLOP, MINY_BLOP + 2);
	cout << char(195);
	gotoxy(MAXX_BLOP, MINY_BLOP + 2);
	cout << char(180);

	//Ve 4 goc
	gotoxy(MINX_BLOP, MINY_BLOP);
	cout << char(218);
	gotoxy(MINX_BLOP, MAXY_BLOP);
	cout << char(192);
	gotoxy(MAXX_BLOP, MINY_BLOP);
	cout << char(191);
	gotoxy(MAXX_BLOP, MAXY_BLOP);
	cout << char(217);

	//Ve Them cac giao diem cot 1
	gotoxy(xCot1, MINY_BLOP);
	cout << char(194);
	gotoxy(xCot1, MINY_BLOP + 2);
	cout << char(197);
	gotoxy(xCot1, MAXY_BLOP);
	cout << char(193);

	//Ve Them cac giao diem cot 2
	gotoxy(xCot2, MINY_BLOP);
	cout << char(194);
	gotoxy(xCot2, MINY_BLOP + 2);
	cout << char(197);
	gotoxy(xCot2, MAXY_BLOP);
	cout << char(193);

	//text
	gotoxy(52, MINY_BLOP + 1);
	cout << "MA LOP";
	gotoxy(78, MINY_BLOP + 1);
	cout << "TEN LOP";
	gotoxy(107, MINY_BLOP + 1);
	cout << "NAM HOC";
}
void veKhungXuatLopTheoNK()
{
	normal();
	veLineNamNgang(MINX_XLOP, MINY_XLOP, widthBANG_XLOP, trang);
	veLineNamNgang(MINX_XLOP, MAXY_XLOP, widthBANG_XLOP, trang);
	veLineThangDung(MINX_XLOP, MINY_XLOP + 1, heightBANG_XLOP - 2, trang);
	veLineThangDung(MAXX_XLOP, MINY_XLOP + 1, heightBANG_XLOP - 2, trang);

	veGocTrenBenTrai(MINX_XLOP, MINY_XLOP, trang);
	veGocTrenBenPhai(MAXX_XLOP, MINY_XLOP, trang);
	veGocDuoiBenTrai(MINX_XLOP, MAXY_XLOP, trang);
	veGocDuoiBenPhai(MAXX_XLOP, MAXY_XLOP, trang);

	veLineNamNgang(MINX_XLOP + 1, MINY_XLOP + 2, widthBANG_XLOP - 2, trang);
	veLineThangDung(X_XLOP_COT1, MINY_XLOP + 1, heightBANG_XLOP - 2, trang);
	veLineThangDung(X_XLOP_COT2, MINY_XLOP + 1, heightBANG_XLOP - 2, trang);
	veLineThangDung(X_XLOP_COT3, MINY_XLOP + 1, heightBANG_XLOP - 2, trang);

	gotoxy(X_XLOP_COT1, MINY_XLOP);
	cout << (char)194;
	gotoxy(X_XLOP_COT2, MINY_XLOP);
	cout << (char)194;
	gotoxy(X_XLOP_COT3, MINY_XLOP);
	cout << (char)194;

	gotoxy(X_XLOP_COT1, MAXY_XLOP);
	cout << (char)193;
	gotoxy(X_XLOP_COT2, MAXY_XLOP);
	cout << (char)193;
	gotoxy(X_XLOP_COT3, MAXY_XLOP);
	cout << (char)193;

	gotoxy(MINX_XLOP, MINY_XLOP + 2);
	cout << (char)195;
	gotoxy(MAXX_XLOP, MINY_XLOP + 2);
	cout << (char)180;

	gotoxy(X_XLOP_COT1, MINY_XLOP + 2);
	cout << (char)197;
	gotoxy(X_XLOP_COT2, MINY_XLOP + 2);
	cout << (char)197;
	gotoxy(X_XLOP_COT3, MINY_XLOP + 2);
	cout << (char)197;

	//add title 
	gotoxy(MINX_XLOP + 2, MINY_XLOP + 1);
	cout << "STT";
	gotoxy(X_XLOP_COT1 + 2, MINY_XLOP + 1);
	cout << "  MA LOP";
	gotoxy(X_XLOP_COT2 + 2, MINY_XLOP + 1);
	cout << "               TEN LOP";
	gotoxy(X_XLOP_COT3 + 1, MINY_XLOP + 1);
	cout << "NAM HOC";
}

//Hàm vẽ khung nhập danh sách môn học
void veKhungNhapDSMONHOC()
{
	//Ve cot
	for (int i = MINY_NDSMH + 1; i < MAXY_NDSMH; ++i)
	{
		gotoxy(MINX_NDSMH, i);
		cout << char(179);
		//Ve cot 1
		gotoxy(XCOT1_NDSMH, i);
		cout << char(179);
		//Ve cot 2
		gotoxy(XCOT2_NDSMH, i);
		cout << char(179);
		//ve cot 3
		gotoxy(XCOT3_NDSMH, i);
		cout << char(179);
		gotoxy(MAXX_NDSMH, i);
		cout << char(179);
	}

	//ve Hang
	for (int i = MINX_NDSMH + 1; i < MAXX_NDSMH; ++i)
	{
		gotoxy(i, MINY_NDSMH);
		cout << char(196);
		gotoxy(i, MINY_NDSMH + 2);
		cout << char(196);
		gotoxy(i, MAXY_NDSMH);
		cout << char(196);
	}

	//Vẽ góc trên bên trái
	gotoxy(MINX_NDSMH, MINY_NDSMH);
	cout << char(218);

	//Vẽ góc trên bên phải
	gotoxy(MAXX_NDSMH, MINY_NDSMH);
	cout << char(191);

	//Vẽ góc duoi bên trái
	gotoxy(MINX_NDSMH, MAXY_NDSMH);
	cout << char(192);

	//Vẽ góc duoi bên phải
	gotoxy(MAXX_NDSMH, MAXY_NDSMH);
	cout << char(217);

	//Ve cac diem giao nhau
	gotoxy(XCOT1_NDSMH, MINY_NDSMH);
	cout << char(194);
	gotoxy(XCOT2_NDSMH, MINY_NDSMH);
	cout << char(194);
	gotoxy(XCOT3_NDSMH, MINY_NDSMH);
	cout << char(194);

	gotoxy(XCOT1_NDSMH, MAXY_NDSMH);
	cout << char(193);
	gotoxy(XCOT2_NDSMH, MAXY_NDSMH);
	cout << char(193);
	gotoxy(XCOT3_NDSMH, MAXY_NDSMH);
	cout << char(193);

	gotoxy(MINX_NDSMH, MINY_NDSMH + 2);
	cout << char(195);
	gotoxy(XCOT1_NDSMH, MINY_NDSMH + 2);
	cout << char(197);
	gotoxy(XCOT2_NDSMH, MINY_NDSMH + 2);
	cout << char(197);
	gotoxy(XCOT3_NDSMH, MINY_NDSMH + 2);
	cout << char(197);
	gotoxy(MAXX_NDSMH, MINY_NDSMH + 2);
	cout << char(180);

	//title bảng
	char titleMAMH[] = "MA MON HOC";
	char titleTENMH[] = "TEN MON HOC";
	char titleLT[] = "LT";
	char titleTH[] = "TH";

	//Tọa độ x bắt đầu in tiêu đề
	int x1 = MINX_NDSMH + (XCOT1_NDSMH - MINX_NDSMH) / 2 - strlen(titleMAMH) / 2 + 1;
	int x2 = XCOT1_NDSMH + (XCOT2_NDSMH - XCOT1_NDSMH) / 2 - strlen(titleTENMH) / 2 + 1;

	normal();

	gotoxy(x1, MINY_NDSMH + 1);
	cout << titleMAMH;
	gotoxy(x2, MINY_NDSMH + 1);
	cout << titleTENMH;

	gotoxy(XCOT2_NDSMH + 2, MINY_NDSMH + 1);
	cout << titleLT;
	gotoxy(XCOT3_NDSMH + 2, MINY_NDSMH + 1);
	cout << titleTH;
}

int veKhungThongBao(char title[], char message[], char td[][10])
{
	int kiTu; 
	int x_Select;
	int chon = 0;
	int x = wherex();
	int y = wherey();

	//Ve line ngang tren
	veLineNamNgang(x + 1, y, widthAlert, 15);
	//Ve line ngang duoi
	veLineNamNgang(x + 1, y + heightAlert, widthAlert, 15);
	//Ve line thang dung 
	veLineThangDung(x , y + 1, heightAlert, 15);
	veLineThangDung(x + widthAlert, y, heightAlert, 15);

	//Ve  4 goc
	veGocTrenBenTrai(x, y, 15);
	veGocTrenBenPhai(x + widthAlert, y, 15);
	veGocDuoiBenTrai(x, y + heightAlert, 15);
	veGocDuoiBenPhai(x + widthAlert, y + heightAlert, 15);

	//Chen Text trong Alert
	gotoxy(x + 10, y + 1);
	cout << title;
	gotoxy(x + 5, y + 3);
	cout << message;

	//Ve button
	highLightButton(x + 1, y + heightAlert - 1, td[0], widthAlert / 2, 1);
	paintColorButton(x + widthAlert / 2, y + heightAlert - 1 , td[1], widthAlert / 2, 1, 3);
	do
	{
		fflush(stdin);
		char c = _getch();
		if (c == -32 || c == 0)
		{
			c = _getch();
			kiTu = c + 1000;
		}
		else
		{
			kiTu = c;
		}
		switch (kiTu)
		{
		case Right:
		{
			x_Select = x + chon * widthAlert / 2;
			if (chon == 0)
			{
				x_Select++;
			}
			paintColorButton(x_Select, y + heightAlert - 1, td[chon], widthAlert / 2, 1, 3);
			if (chon == 0)
			{
				chon++;
			}
			else
			{
				chon = 0;
			}
			x_Select = x + chon * widthAlert / 2;
			if (chon == 0)
			{
				x_Select++;
			}
			highLightButton(x_Select, y + heightAlert - 1, td[chon], widthAlert / 2, 1);
			break;
		}
		case Left:
		{
			x_Select = x + chon * widthAlert / 2;
			if (chon == 0)
			{
				x_Select++;
			}
			paintColorButton(x_Select, y + heightAlert - 1, td[chon], widthAlert / 2, 1, 3);
			if (chon == 1)
			{
				chon = 0;
			}
			else
			{
				chon = 1;
			}
			x_Select = x + chon * widthAlert / 2;
			if (chon == 0)
			{
				x_Select++;
			}
			highLightButton(x_Select, y + heightAlert - 1, td[chon], widthAlert / 2, 1);
			break;
		}
		case Enter:
		{
			return chon;
		}
		case ESC:
		{
			return (int)ESC;
		}
		}

	} while (true);
	return 0;
}
int veTextFieldNhapNamHoc(char KQ[], char title[], char message[])
{
	int x = wherex();
	int y = wherey();

	//Ve line ngang tren
	veLineNamNgang(x + 1, y, widthAlert, 15);
	//Ve line ngang duoi
	veLineNamNgang(x + 1, y + heightTextField, widthAlert, 15);
	//Ve line thang dung 
	veLineThangDung(x, y + 1, heightTextField, 15);
	veLineThangDung(x + widthAlert, y, heightTextField, 15);

	//Ve  4 goc
	veGocTrenBenTrai(x, y, 15);
	veGocTrenBenPhai(x + widthAlert, y, 15);
	veGocDuoiBenTrai(x, y + heightTextField, 15);
	veGocDuoiBenPhai(x + widthAlert, y + heightTextField, 15);

	//Chen Text trong Alert
	gotoxy(x + 10, y + 1);
	cout << title;
	gotoxy(x + 1, y + 2);
	cout << message;
	
	gotoxy(MINX_ALERTTB + 2, MINY_ALERTNL + 2);
	SetColor(green);
	for (int i = 0; i < widthAlert - 4; ++i)
	{
		cout << (char)196;
	}
	normal();
	int kitu = NhapSo(KQ, 5, MINX_ALERTTB + 13, wherey() - 1);
	return kitu;
}
int veTextFieldNhapKituSo(char KQ[], int MAX, char title[], char message[])
{
	int x = wherex();
	int y = wherey();

	//Ve line ngang tren
	veLineNamNgang(x + 1, y, widthAlert, 15);
	//Ve line ngang duoi
	veLineNamNgang(x + 1, y + heightTextField, widthAlert, 15);
	//Ve line thang dung 
	veLineThangDung(x, y + 1, heightTextField, 15);
	veLineThangDung(x + widthAlert, y, heightTextField, 15);

	//Ve  4 goc
	veGocTrenBenTrai(x, y, 15);
	veGocTrenBenPhai(x + widthAlert, y, 15);
	veGocDuoiBenTrai(x, y + heightTextField, 15);
	veGocDuoiBenPhai(x + widthAlert, y + heightTextField, 15);

	//Chen Text trong Alert
	gotoxy(x + 10, y + 1);
	cout << title;
	gotoxy(x + 1, y + 2);
	cout << message;

	gotoxy(MINX_ALERTTB + 2, MINY_ALERTNL + 2);
	SetColor(green);
	for (int i = 0; i < widthAlert - 4; ++i)
	{
		cout << (char)196;
	}
	normal();
	int kiTu = NhapChuoiVaChuSo(KQ, MAX, MINX_ALERTTB + 10, wherey() - 1);
	return kiTu;
}

//cac ham ve button
void paintNormalButton(int x, int y, char label[], int width, int height) {
	normalButton();
	for (int i = 0; i < height; ++i)
	{
		gotoxy(x, y + i);
		cout << setw(width) << "  ";
	}
	gotoxy(x, y + height / 2);
	cout << setw(2) << "  " << left << setw(width - 2) << label;
}
void highLightButton(int x, int y, char label[], int width, int height) {
	highLight();
	for (int i = 0; i < height; ++i) 
	{
		gotoxy(x, y + i);
		cout << setw(width) << "  ";
	}
	gotoxy(x, y + height / 2);
	cout << setw(2) << "  " << left << setw(width - 4) << label << (char)175;
}
void paintColorButton(int x, int y, char label[], int width, int height, int color)
{
	SetColor(15);
	SetBGColor(color);
	for (int i = 0; i < height; ++i)
	{
		gotoxy(x, y + i);
		cout << setw(width) << "  ";
	}
	gotoxy(x, y + height / 2);
	cout << setw(2) << "  " << left << setw(width - 2) << label;
}

//Tra ve nam hien ti
int getNamHienTai()
{
	time_t bayGio = time(0);
	tm *ltm = localtime(&bayGio);
	int namHienTai = 1900 + ltm->tm_year;
	return namHienTai;
}

void labelTable(char label[])
{
	xoaNoiDungVe(72, 2, 30, 1);
	gotoxy(72, 2);
	setGreenText();
	cout << label;
	normal();
}

void veKhungNhapTTSinhVien()
{
	for (int i = MINY_BSV + 1; i < MAXY_BSV; ++i)
	{
		gotoxy(MINX_BSV, i);
		cout << char(179);
		gotoxy(MAXX_BSV, i);
		cout << char(179);
		gotoxy(MINX_BSV, i);
		cout << char(179);
		//Ve Cot 1
		gotoxy(svCot1, i);
		cout << char(179);

		//Ve Cot 2
		gotoxy(svCot2, i);
		cout << char(179);

		//Ve Cot 3
		gotoxy(svCot3, i);
		cout << char(179);

		//Ve Cot 4
		gotoxy(svCot4, i);
		cout << char(179);
	}
	for (int i = MINX_BSV + 1; i < MAXX_BSV; ++i)
	{
		gotoxy(i, MINY_BSV);
		cout << char(196);
		gotoxy(i, MAXY_BSV);
		cout << char(196);
		gotoxy(i, MINY_BSV + 2);
		cout << char(196);
	}
	//Ve them thanh ngang
	gotoxy(MINX_BLOP, MINY_BSV + 2);
	cout << char(195);
	gotoxy(MAXX_BLOP, MINY_BSV + 2);
	cout << char(180);

	//Ve 4 goc
	gotoxy(MINX_BSV, MINY_BSV);
	cout << char(218);
	gotoxy(MINX_BSV, MAXY_BSV);
	cout << char(192);
	gotoxy(MAXX_BSV, MINY_BSV);
	cout << char(191);
	gotoxy(MAXX_BSV, MAXY_BSV);
	cout << char(217);

	//Ve Them cac giao diem cot 1
	gotoxy(svCot1, MINY_BSV);
	cout << char(194);
	gotoxy(svCot1, MINY_BSV + 2);
	cout << char(197);
	gotoxy(svCot1, MAXY_BSV);
	cout << char(193);

	//Ve Them cac giao diem cot 2
	gotoxy(svCot2, MINY_BSV);
	cout << char(194);
	gotoxy(svCot2, MINY_BSV + 2);
	cout << char(197);
	gotoxy(svCot2, MAXY_BSV);
	cout << char(193);
	//Ve Them cac giao diem cot 3
	gotoxy(svCot3, MINY_BSV);
	cout << char(194);
	gotoxy(svCot3, MINY_BSV + 2);
	cout << char(197);
	gotoxy(svCot3, MAXY_BSV);
	cout << char(193);
	//Ve Them cac giao diem cot 4
	gotoxy(svCot4, MINY_BSV);
	cout << char(194);
	gotoxy(svCot4, MINY_BSV + 2);
	cout << char(197);
	gotoxy(svCot4, MAXY_BSV);
	cout << char(193);
	//text
	gotoxy(MINX_BSV + 4, MINY_BSV + 1);
	cout << "MA SV";
	gotoxy(svCot1 + 10, MINY_BSV + 1);
	cout << "HO SV";
	gotoxy(svCot2 + 4, MINY_BSV + 1);
	cout << "TEN SV";
	gotoxy(svCot3 + 1, MINY_BSV + 1);
	cout << "GIOI";
	gotoxy(svCot4 + 5, MINY_BSV + 1);
	cout << "SO DT";
};

void veKhungXuatSVTheoLop()
{

	normal();
	veLineNamNgang(MINX_XSV, MINY_XSV, widthBANG_XSV, trang);
	veLineNamNgang(MINX_XSV, MAXY_XSV, widthBANG_XSV, trang);
	veLineThangDung(MINX_XSV, MINY_XSV + 1, heightBANG_XSV - 2, trang);
	veLineThangDung(MAXX_XSV, MINY_XSV + 1, heightBANG_XSV - 2, trang);

	veGocTrenBenTrai(MINX_XSV, MINY_XSV, trang);
	veGocTrenBenPhai(MAXX_XSV, MINY_XSV, trang);
	veGocDuoiBenTrai(MINX_XSV, MAXY_XSV, trang);
	veGocDuoiBenPhai(MAXX_XSV, MAXY_XSV, trang);
	
	veLineNamNgang(MINX_XSV + 1, MINY_XSV + 2, widthBANG_XSV - 2, trang);
	veLineThangDung(X_XSV_COT1, MINY_XSV + 1, heightBANG_XSV - 2, trang);
	veLineThangDung(X_XSV_COT2, MINY_XSV + 1, heightBANG_XSV - 2, trang);
	veLineThangDung(X_XSV_COT3, MINY_XSV + 1, heightBANG_XSV - 2, trang);
	veLineThangDung(X_XSV_COT4, MINY_XSV + 1, heightBANG_XSV - 2, trang);
	veLineThangDung(X_XSV_COT5, MINY_XSV + 1, heightBANG_XSV - 2, trang);

	gotoxy(X_XSV_COT1, MINY_XLOP);
	cout << (char)194;
	gotoxy(X_XSV_COT2, MINY_XLOP);
	cout << (char)194;
	gotoxy(X_XSV_COT3, MINY_XLOP);
	cout << (char)194;
	gotoxy(X_XSV_COT4, MINY_XLOP);
	cout << (char)194;
	gotoxy(X_XSV_COT5, MINY_XLOP);
	cout << (char)194;

	gotoxy(X_XSV_COT1, MAXY_XLOP);
	cout << (char)193;
	gotoxy(X_XSV_COT2, MAXY_XLOP);
	cout << (char)193;
	gotoxy(X_XSV_COT3, MAXY_XLOP);
	cout << (char)193;
	gotoxy(X_XSV_COT4, MAXY_XLOP);
	cout << (char)193;
	gotoxy(X_XSV_COT5, MAXY_XLOP);
	cout << (char)193;

	gotoxy(MINX_XSV, MINY_XSV + 2);
	cout << (char)195;
	gotoxy(MAXX_XSV, MINY_XSV + 2);
	cout << (char)180;

	gotoxy(X_XSV_COT1, MINY_XSV + 2);
	cout << (char)197;
	gotoxy(X_XSV_COT2, MINY_XSV + 2);
	cout << (char)197;
	gotoxy(X_XSV_COT3, MINY_XSV + 2);
	cout << (char)197;
	gotoxy(X_XSV_COT4, MINY_XSV + 2);
	cout << (char)197;
	gotoxy(X_XSV_COT5, MINY_XSV + 2);
	cout << (char)197;

	//add title 
	gotoxy(MINX_XSV + 1, MINY_XSV + 1);
	cout << "STT";
	gotoxy(X_XSV_COT1 + 4, MINY_XSV + 1);
	cout << "MA SV";
	gotoxy(X_XSV_COT2 + 5, MINY_XSV + 1);
	cout << " HO SV";
	gotoxy(X_XSV_COT3 + 3, MINY_XSV + 1);
	cout << "TEN";
	gotoxy(X_XSV_COT4 + 1, MINY_XSV + 1);
	cout << "GIOI";
	gotoxy(X_XSV_COT5 + 3, MINY_XSV + 1);
	cout << "SDT";
}

void veKhungXuatMonHoc()
{
	//Ve cot
	for (int i = MINY_XDSMH + 1; i < MAXY_XDSMH; ++i)
	{
		gotoxy(MINX_XDSMH, i);
		cout << char(179);
		//Ve cot 1
		gotoxy(XCOT1_XDSMH, i);
		cout << char(179);
		//Ve cot 2
		gotoxy(XCOT2_XDSMH, i);
		cout << char(179);
		//ve cot 3
		gotoxy(XCOT3_XDSMH, i);
		cout << char(179);
		//ve cot 4
		gotoxy(XCOT4_XDSMH, i);
		cout << char(179);
		gotoxy(MAXX_XDSMH, i);
		cout << char(179);
	}

	//ve Hang
	for (int i = MINX_XDSMH + 1; i < MAXX_XDSMH; ++i)
	{
		gotoxy(i, MINY_XDSMH);
		cout << char(196);
		gotoxy(i, MINY_XDSMH + 2);
		cout << char(196);
		gotoxy(i, MAXY_XDSMH);
		cout << char(196);
	}

	//Vẽ góc trên bên trái
	gotoxy(MINX_XDSMH, MINY_XDSMH);
	cout << char(218);

	//Vẽ góc trên bên phải
	gotoxy(MAXX_XDSMH, MINY_XDSMH);
	cout << char(191);

	//Vẽ góc duoi bên trái
	gotoxy(MINX_XDSMH, MAXY_XDSMH);
	cout << char(192);

	//Vẽ góc duoi bên phải
	gotoxy(MAXX_XDSMH, MAXY_XDSMH);
	cout << char(217);

	//Ve cac diem giao nhau
	gotoxy(XCOT1_XDSMH, MINY_XDSMH);
	cout << char(194);
	gotoxy(XCOT2_XDSMH, MINY_XDSMH);
	cout << char(194);
	gotoxy(XCOT3_XDSMH, MINY_XDSMH);
	cout << char(194);
	gotoxy(XCOT4_XDSMH, MINY_XDSMH);
	cout << char(194);

	gotoxy(XCOT1_XDSMH, MAXY_XDSMH);
	cout << char(193);
	gotoxy(XCOT2_XDSMH, MAXY_XDSMH);
	cout << char(193);
	gotoxy(XCOT3_XDSMH, MAXY_XDSMH);
	cout << char(193);
	gotoxy(XCOT3_XDSMH, MAXY_XDSMH);
	cout << char(193);
	gotoxy(XCOT4_XDSMH, MAXY_XDSMH);
	cout << char(193);

	gotoxy(MINX_XDSMH, MINY_XDSMH + 2);
	cout << char(195);
	gotoxy(XCOT1_XDSMH, MINY_XDSMH + 2);
	cout << char(197);
	gotoxy(XCOT2_XDSMH, MINY_XDSMH + 2);
	cout << char(197);
	gotoxy(XCOT3_XDSMH, MINY_XDSMH + 2);
	cout << char(197);
	gotoxy(XCOT4_XDSMH, MINY_XDSMH + 2);
	cout << char(197);
	gotoxy(MAXX_XDSMH, MINY_XDSMH + 2);
	cout << char(180);

	//title bảng
	char titleSTT[] = "STT";
	char titleMAMH[] = "MA MON HOC";
	char titleTENMH[] = "TEN MON HOC";
	char titleLT[] = "LT";
	char titleTH[] = "TH";

	
	normal();

	gotoxy(MINX_XDSMH +1, MINY_XDSMH + 1);
	cout << titleSTT;
	gotoxy(XCOT1_XDSMH+2, MINY_XDSMH + 1);
	cout << titleMAMH;

	gotoxy(XCOT2_XDSMH + 5, MINY_XDSMH + 1);
	cout << titleTENMH;
	gotoxy(XCOT3_XDSMH + 1, MINY_XDSMH + 1);
	cout << titleLT;
	gotoxy(XCOT4_XDSMH + 1, MINY_XDSMH + 1);
	cout << titleTH;
}
