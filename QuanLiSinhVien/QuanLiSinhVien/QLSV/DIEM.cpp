#include "DIEM.h"

DIEM::DIEM()
{
}

void DIEM::nhapDiem(char MaMonHoc[], int diemThi, int lanThi)
{
	strcpy(MAMH, MaMonHoc);
	Diem = diemThi;
	LAN = lanThi;
}

char * DIEM::getMaMH()
{
	return MAMH;
}

int DIEM::getLanThi()
{
	return LAN;
}

char * DIEM::getMAMONHOC()
{
	return MAMH;
}

int DIEM::getDiem()
{
	return Diem;
}

void DIEM::setDiem(int _diem)
{
	Diem = _diem;
}

DIEM::~DIEM()
{
}
