#include "MONHOC.h"

MONHOC::MONHOC()
{

}

void MONHOC::nhapMH(char _maMh[], char _tenMh[], int _sTCLT, int _sTCTH)
{
	strcpy(_maMh, MAMH);
	strcpy(_tenMh, TENMH);
	STCLT = _sTCLT;
	STCTH = _sTCTH;
}

void MONHOC::xuatMH()
{
}

MONHOC::~MONHOC()
{
}
