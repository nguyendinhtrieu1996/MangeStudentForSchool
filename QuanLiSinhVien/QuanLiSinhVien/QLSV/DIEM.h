#pragma once
#include "MyLibrary.h"
#include <iostream>
using namespace std;

class DIEM
{
private:
	char MAMH[20];
	int LAN;

public:
	DIEM();
	void nhap();
	void xuat();
	void nhapDiem();
	void xuatDiem();
	~DIEM();
};

