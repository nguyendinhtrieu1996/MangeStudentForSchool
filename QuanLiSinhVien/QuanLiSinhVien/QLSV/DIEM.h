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
	void nhapDiem(char MaMonHoc[], int diemThi, int lanThi);;
	char* getMaMH();
	int getLanThi();
	char* getMAMONHOC();
	int getDiem();
	void setDiem(int);
	~DIEM();
	friend class NODEDIEM;
};

