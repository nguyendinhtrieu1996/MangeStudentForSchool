#pragma once
#include "MyLibrary.h"

class MONHOC
{
private:
	char MAMH[15];
	char TENMH[40];
	int STCLT;
	int STCTH;
public:
	MONHOC();
	void nhapMH(char _maMh[], char _tenMh[], int _sTCLT, int _sTCTH);
	void xuatMH();
	~MONHOC();
	friend class DSMH;
};

