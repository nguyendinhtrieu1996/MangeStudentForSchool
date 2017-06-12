#pragma once
#include "MyLibrary.h"

class DIEM
{
private:
	char MAMH[constMAMON];
	int Diem;
	int LAN;
public:
	DIEM();
	void nhap();
	void xuat();
	void nhapDiem(char MaMonHoc[], int diemThi, int lanThi);;
	void xuatDiem();
	char* getMaMH();
	int getLanThi();
	int getDiem();
	~DIEM();
	friend class NODEDIEM;
};

