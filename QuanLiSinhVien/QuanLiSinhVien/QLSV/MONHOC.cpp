#include "MONHOC.h"

MONHOC::MONHOC()
{

}

void MONHOC::nhapMH(char _maMh[], char _tenMh[], int _sTCLT, int _sTCTH)
{
	strcpy( MAMH,_maMh);
	strcpy(TENMH,_tenMh);
	STCLT = _sTCLT;
	STCTH = _sTCTH;
}

void MONHOC::xuatMH()
{
}

void MONHOC::setMAMH(char _maMh[])
{
	strcpy( MAMH,_maMh);
}

char * MONHOC::getMAMH()
{
	return MAMH;
}

void MONHOC::setTENMH(char _tenMh[])
{
	strcpy(TENMH, _tenMh);
}

char * MONHOC::getTENMH()
{
	return TENMH;
}

void MONHOC::setLT(int _lt)
{
	STCLT = _lt;
}

int MONHOC::getLT()
{
	return STCLT;
}

void MONHOC::setTH(int _th)
{
	STCTH = _th;
}

int MONHOC::getTH()
{
	return STCTH;
}

MONHOC::~MONHOC()
{
}
