#pragma once
#include "MyLibrary.h"

class DIEM
{
private:
	char MAMH[constMAMON];
	int LAN;
public:
	DIEM();
	void nhap();
	void xuat();
	void nhapDiem();
	void xuatDiem();
	char* getMaMH();
	int getLanThi();
	~DIEM();
	friend class NODEDIEM;
};

