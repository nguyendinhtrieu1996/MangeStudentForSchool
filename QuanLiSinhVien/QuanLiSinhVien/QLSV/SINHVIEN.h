#pragma once
#include "NODEDIEM.h"

class SINHVIEN
{
private:
	char MASV[10];
	char HO[20];
	char TEN[10];
	char PHAI[4];
	char SDT[12];
	PTRNODEDIEM dsDiem;
public:
	SINHVIEN();
	SINHVIEN(char _MASV[10], char _HO[20], char _TEN[10], char _PHAI[4], char _SDT[12]);
	void nhapSV();
	char* getMASV();
	char* getHO();
	char* getPHAI();
	char* getSDT();
	char* getTEN();
	void setMASV(char[]);
	void setHO(char[]);
	void setPHAI(char[]);
	void setSDT(char[]);
	void setTEN(char[]);
	void xuatSV();
	double tinhDiemTB();
	void createDSDIEM();
	void xuatDSDIEM();
	void insertFirst();
	void insertAfter();
	void insertLast();

	bool kiemTraMH(char MMH[], int lanThi);
	void nhapDiem(char MMH[], int lanThi);
	~SINHVIEN();
	//friend class NODESV;
};

