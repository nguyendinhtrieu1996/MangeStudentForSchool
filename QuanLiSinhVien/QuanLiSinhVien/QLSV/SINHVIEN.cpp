#include "SINHVIEN.h"



SINHVIEN::SINHVIEN()
{
	dsDiem = NULL;
}

SINHVIEN::SINHVIEN(char _MASV[10], char _HO[20], char _TEN[10], char _PHAI[4], char _SDT[12])
{
	strcpy_s(MASV, _MASV);
	strcpy_s(HO, _HO);
	strcpy_s(TEN, _TEN);
	strcpy_s(PHAI, _PHAI);
	strcpy_s(SDT, _SDT);
	dsDiem = NULL;
}

void SINHVIEN::nhapSV()
{
}

void SINHVIEN::xuatSV()
{
}

double SINHVIEN::tinhDiemTB()
{
	return 0.0;
}

void SINHVIEN::createDSDIEM()
{
}

void SINHVIEN::xuatDSDIEM()
{
}

void SINHVIEN::insertFirst()
{
}

void SINHVIEN::insertAfter()
{
}

void SINHVIEN::insertLast()
{
}

bool SINHVIEN::kiemTraMH(char MMH[], int lanThi)
{
	return false;
}

void SINHVIEN::nhapDiem(char MMH[], int lanThi)
{
}


SINHVIEN::~SINHVIEN()
{
}
char* SINHVIEN::getMASV(){
	return MASV;
}
char*SINHVIEN::getHO()
{
	return HO;
}
char*SINHVIEN::getPHAI(){
	return PHAI;
}
char*SINHVIEN::getTEN(){
	return TEN;
}
char* SINHVIEN::getSDT(){
	return SDT;
}
void SINHVIEN::setMASV(char _MASV[])
{
	strcpy(MASV, _MASV);
}
void SINHVIEN::setHO(char _HO[])
{
	strcpy(HO, _HO);
}
void SINHVIEN::setPHAI(char _PHAI[])
{
	strcpy(PHAI, _PHAI);
}
void SINHVIEN::setSDT(char _SDT[])
{
	strcpy(SDT, _SDT);
}
void SINHVIEN::setTEN(char _TEN[])
{
	strcpy(TEN, _TEN);
}