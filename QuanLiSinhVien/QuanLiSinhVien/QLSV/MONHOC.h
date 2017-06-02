#pragma once
#include "MyLibrary.h"

class MONHOC
{
private:
<<<<<<< HEAD
	char MAMH[15];
=======
	char MAMH[constMAMON];
>>>>>>> 747d2841e66a3d7665905081e67162f6680d375d
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

