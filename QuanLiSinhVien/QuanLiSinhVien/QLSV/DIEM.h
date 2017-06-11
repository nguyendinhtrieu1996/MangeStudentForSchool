#pragma once
#include "MyLibrary.h"

class DIEM
{
private:
	char MAMH[constMAMON];
	float Diem;
	int LAN;
public:
	DIEM();
	void nhap();
	void xuat();
	void nhapDiem(float diemThi);
	void xuatDiem();
	char* getMaMH();
	int getLanThi();
	int getDiem();
	~DIEM();
	friend class NODEDIEM;
};

