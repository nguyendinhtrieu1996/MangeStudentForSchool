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
	void nhapDiem(char MaMonHoc[], float diemThi, int lanThi);;
	void xuatDiem();
	char* getMaMH();
	int getLanThi();
	float getDiem();
	~DIEM();
	friend class NODEDIEM;
};

