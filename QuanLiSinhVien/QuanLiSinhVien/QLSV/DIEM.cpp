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

void DIEM::nhapDiem(char MaMonHoc[], float diemThi, int lanThi)
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

float DIEM::getDiem()
{
	return Diem;
}

DIEM::~DIEM()
{
}
