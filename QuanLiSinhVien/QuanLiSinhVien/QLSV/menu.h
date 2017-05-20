#pragma once
#include "MyLibrary.h"

//Tọa độ bảng lớn hiển thị thông tin
const int MINX = 1;
const int MAXX = 117;
const int MINY = 1;
const int MAXY = 28;

const int so_item = 6; 
const int soItemMenuLop = 4;
const int soItemMenuSV = 4;
const int soItemMenuMon = 4;
const int soItemMenuDiem = 3;
const int soItemMenuXuat = 3;
const int xCotChild = 26;

const int x_MainButton = 4;
const int y_FirstMainButton = 3;

const int widthButton = 20;
const int heightButton = 3;
const int widthChildButton = 13;

const int widthChildMenu = 17;
const int heightChildMenu = 3;

char mainMenu[so_item][20] = { "LOP",
"SINH VIEN",
"MON HOC",
"DIEM",
"XUAT",
"THOAT" };
char lopMenu[soItemMenuLop][10] = { "THEM MOI",
"CHINH SUA",
"XOA",
"IN DSACH" };
char svMenu[soItemMenuSV][10] = { "THEM MOI",
"CHINH SUA",
"XOA",
"IN DSACH" };
char monMenu[soItemMenuMon][10] = { "THEM MOI",
"CHINH SUA",
"XOA",
"IN DSACH" };
char diemMenu[soItemMenuDiem][10] = { "THEM MOI",
"CHINH SUA",
"XOA" };
char inMenu[soItemMenuXuat][20] = { "DIEM TONG",
"DIEM THEO MON",
"DIEM TB" };

//vẽ khung
void paintStroke() {
	colorStroke();
	//stroke left + right
	for (int i = MINY + 1; i < MAXY; i++) {
		//Ve truc dung ben trai
		gotoxy(MINX, i);
		cout << char(179);
		//Ve truc dung ben phai
		gotoxy(MAXX, i);
		cout << char(179);
	}
	//Ve duong ngan cach
	for (int i = MINY; i < MAXY; i++) {
		gotoxy(44, i);
		cout << char(179);

	}
	//Ve duong ngang tren
	gotoxy(MINX + 1, MINY);
	for (int i = MINX + 1; i < MAXX; i++) {
		cout << char(196);
	}
	//Ve duong ngang duoi
	gotoxy(MINX + 1, MAXY);
	for (int i = MINX + 1; i < MAXX; i++) {
		cout << char(196);
	}
	// vẽ 2 góc giữa
	gotoxy(44, MINY);
	printf("%c", 194);
	gotoxy(44, MAXY);
	printf("%c", 193);
	//vẽ 4 góc khung
	gotoxy(MINX, MINY);
	printf("%c", 218);
	gotoxy(MINX, MAXY);
	printf("%c", 192);
	gotoxy(MAXX, MINY);
	printf("%c", 191);
	gotoxy(MAXX, MAXY);
	printf("%c", 217);

	normal();
}

//td: danh sách thực đơn, main dang chon cai nao trong maniMenu, child (select) dang chon cai nao trong child menu
void mainMenuDong(char td[so_item][20], int &main, int child = 0) {
	system("cls");
	paintStroke();//vẽ khung

	for (int i = 0; i < so_item; i++)
	{
		int y = y_FirstMainButton + i * (heightButton + 1);
		paintNormalButton(x_MainButton, y, td[i], widthButton, heightButton);
	}
	int y = y_FirstMainButton + main * (heightButton + 1);
	highLightButton(x_MainButton, y, td[main], widthButton, heightButton);

	if (child != 0)
	{
		main++;
		return;
	}

	int kiTu = 0;

	do {
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

		switch (kiTu) {
		case PageUp:
		{
			//sửa
			if (main != 0)
			{
				paintNormalButton(x_MainButton, y, td[main], widthButton, heightButton);
				main--;
				y = y_FirstMainButton + main * (heightButton + 1);
				highLightButton(x_MainButton, y, td[main], widthButton, heightButton);
			}
			else
			{
				paintNormalButton(x_MainButton, y, td[main], widthButton, heightButton);
				main = so_item - 1;
				y = y_FirstMainButton + main * (heightButton + 1);
				highLightButton(x_MainButton, y, td[main], widthButton, heightButton);
			}
			break;
		}
		case PageDown:
		{
			if (main == so_item - 1)
			{
				paintNormalButton(x_MainButton, y, td[main], widthButton, heightButton);
				main = 0;
				y = y_FirstMainButton + main * (heightButton + 1);
				highLightButton(x_MainButton, y, td[main], widthButton, heightButton);
			}
			else
			{
				paintNormalButton(x_MainButton, y, td[main], widthButton, heightButton);
				main++;
				y = y_FirstMainButton + main * (heightButton + 1);
				highLightButton(x_MainButton, y, td[main], widthButton, heightButton);
			}
			break;
		}
		case Right:
		{
			main++;
			return;
		}
		case Enter:
		{
			if (main == so_item - 1)
			{
				exit(0);
			}
			main++;
			return;
		}
		}  
	} while (true);
}

void diemChildMenu(char td[3][10], int x, int y, int &select) {
	int i;
	//Luu toa do y cua child button
	int y_btn;
	for (i = 0; i < 3; i++)
	{
		y_btn = y + i * (heightChildMenu + 1);
		paintNormalButton(x, y_btn, td[i], widthChildButton, heightButton);

	}
	y_btn = y + select * (heightChildMenu + 1);
	highLightButton(x, y_btn, td[select], widthChildButton, heightChildMenu);

	int kiTu;
	do {
		char temp = _getch();

		if (temp == 0 || temp == -32)
		{
			temp = _getch();
			kiTu = temp + 1000;
		}
		else
		{
			kiTu = temp;
		}
		switch (kiTu)
		{
		case PageUp:
			if (select > 0)
			{
				paintNormalButton(x, y_btn, td[select], widthChildButton, heightChildMenu);
				select--;
			}
			break;
		case PageDown:
			if (select < 2)
			{
				paintNormalButton(x, y_btn, td[select], widthChildButton, heightChildMenu);
				select++;
			}
			else
			{
				paintNormalButton(x, y_btn, td[select], widthChildButton, heightChildMenu);
				select = 0;
			}
			break;
		case Right:
		{
			select++;
			return;
		}
		case Enter: 
		{
			select++;
			return;
		}
		case ESC: 
		{
			select = 0;
			return;
		}
		case Left: 
		{
			select = 0;
			return;
		}
		}  // end switch
		y_btn = y + select * (heightChildMenu + 1);
		highLightButton(x, y_btn, td[select], widthChildButton, heightChildMenu);
	} while (1);
}

void xuatChildMenu(char td[soItemMenuXuat][20], int x, int y, int &select) {
	int i;
	int y_btn;
	for (i = 0; i < 3; i++)
	{
		y_btn = y + i * (heightChildMenu + 1);
		paintNormalButton(x, y_btn, td[i], widthChildButton + 3, heightChildMenu);

	}
	y_btn = y + select * (heightChildMenu + 1);
	highLightButton(x, y_btn, td[select], widthChildButton + 3, heightChildMenu);
	int kiTu;
	do {
		char temp = _getch();

		if (temp == 0 || temp == -32)
		{
			temp = _getch();
			kiTu = temp + 1000;
		}
		else
		{
			kiTu = temp;
		}
		switch (kiTu) {
		case PageUp:
				if (select > 0)
				{
					paintNormalButton(x, y_btn, td[select], widthChildButton + 3, heightChildMenu);
					select--;
				}
				else
				{
					paintNormalButton(x, y_btn, td[select], widthChildButton + 3, heightChildMenu);
					select = soItemMenuXuat - 1;
				}
				break;
			case PageDown:
				if (select < (soItemMenuXuat - 1))
				{
					paintNormalButton(x, y_btn, td[select], widthChildButton + 3, heightChildMenu);
					select++;
				}
				else
				{
					paintNormalButton(x, y_btn, td[select], widthChildButton + 3, heightChildMenu);
					select = 0;
				}
				break;
			case Right:
			{
				++select;
				return;
			}
			case Enter:
			{
				++select;
				return;
			}
			case ESC: 
			{
				select = 0;
				return;
			}
			case Left: 
			{
				select = 0;
				return;
			}
			} 
		y_btn = y + select * (heightChildMenu + 1);
		highLightButton(x, y_btn, td[select], widthChildButton + 3, heightChildMenu);
		} while (1);
}

void childMenu(char td[4][10], int x, int y, int &select)
{
	int i;
	int y_btn;

	for (i = 0; i < 4; i++)
	{
		y_btn = y + i * (heightChildMenu + 1);
		paintNormalButton(x, y_btn, td[i], widthChildButton, heightChildMenu);

	}
	y_btn = y + select * (heightChildMenu + 1);
	highLightButton(x, y_btn, td[select], widthChildButton, heightChildMenu);

	int kiTu;
	do {
		kiTu = 0;
		fflush(stdin);
		char temp = _getch();
		if (temp == -32)
		{
			temp = _getch();
			kiTu = temp + 1000;
		}
		else
		{
			kiTu = temp;
		}

		switch (kiTu) {
		case PageUp:
			if (select > 0)
			{
				paintNormalButton(x, y_btn, td[select], widthChildButton, heightButton);
				select--;
			}
			else {
				paintNormalButton(x, y_btn, td[select], widthChildButton, heightButton);
				select = 3;
			}
			break;
		case PageDown:
			if (select < 3)
			{
				paintNormalButton(x, y_btn, td[select], widthChildButton, heightButton);
				select++;
			}
			else
			{
				paintNormalButton(x, y_btn, td[select], widthChildButton, heightButton);
				select = 0;
			}
			break;
		case Right:
		{
			++select;
			return;
		}
		case Enter: 
		{
			++select;
			return;
		}
		case ESC: 
		{
			select = 0;
			return;
		}
		case Left: 
		{
			select = 0;
			return;
		}
		}  // end switch
		y_btn = y + select * (heightChildMenu + 1);
		highLightButton(x, y_btn, td[select], widthChildButton, heightChildMenu);
	} while (1);
}

int veMenu(int main, int child)
{
	paintStroke();// vẽ khung

menu:
	if (main != 0)
	{
		main--;
	}
	mainMenuDong(mainMenu, main, child);
	if (child != 0)
	{
		child--;
	}
	if (main == 4)
	{
		diemChildMenu(diemMenu, xCotChild, wherey() - 1, child);
	}
	else if (main == 5)
	{
		child = 2;
		xuatChildMenu(inMenu, xCotChild, wherey() - 9, child);
	}
	else
	{
		childMenu(lopMenu, xCotChild, wherey() - 1, child);
	}
	if (child == 0)
	{
		normal();
		goto menu;
	}
	normal();
	return  main * 10 + child;
}





