#include "DIEM.h"

DIEM::DIEM()
{
}

void DIEM::nhap()
{
}

void DIEM::xuat()
{
}

void DIEM::nhapDiem(char MaMonHoc[], int diemThi, int lanThi)
{
	strcpy(MAMH, MaMonHoc);
	Diem = diemThi;
	LAN = lanThi;
}

void DIEM::xuatDiem()
{
}

char * DIEM::getMaMH()
{
	return MAMH;
}

int DIEM::getLanThi()
{
	return LAN;
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
