#pragma once
#include "MyLibrary.h"

class MONHOC
{
private:
	char MAMH[20];
	char TENMH[50];
	int STCLT;
	int STCTH;
public:
	MONHOC();
	void nhapMH();
	void xuatMH();
	~MONHOC();
	friend class DSMH;
};

