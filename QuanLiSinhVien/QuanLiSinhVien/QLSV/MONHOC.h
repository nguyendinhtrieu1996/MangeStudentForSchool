#pragma once
#include "MyLibrary.h"

class MONHOC
{
private:
	char MAMH[constMAMON];
	char TENMH[constTENMH];
	int STCLT;
	int STCTH;
public:
	MONHOC();
	void nhapMH(char _maMh[], char _tenMh[], int _sTCLT, int _sTCTH);
	void xuatMH();

	void setMAMH(char _maMh[]);
	char* getMAMH();

	void setTENMH(char _tenMh[]);
	char* getTENMH();

	void setLT(int _lt);
	int getLT();

	void setTH(int _th);
	int getTH();
	~MONHOC();
	friend class DSMONHOC;
};

