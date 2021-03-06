﻿#pragma once
#include "NODEDIEM.h"
#include "Constant.h"

class SINHVIEN
{
private:
	char MASV[constMASV];
	char HO[constHO];
	char TEN[constTENSV];
	char PHAI[constPHAI];
	char SDT[constSDT];
	PTRNODEDIEM dsDiem;
public:
	SINHVIEN();
	SINHVIEN(char _MASV[], char _HO[], char _TEN[], char _PHAI[], char _SDT[]);
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
	//----------------------XU LI TREN DIEM-----------------------
	double tinhDiemTB();
	PTRNODEDIEM createDSDIEM(char MaMH[], int diemThi, int lanThi);
	void xuatDSDIEM();
	PTRNODEDIEM insertFirst(DIEM diemSV);
	void insertAfter();
	PTRNODEDIEM insertLast(DIEM diemSV);
	PTRNODEDIEM timlanThiLonNhatCuaMH(char MaMonHoc[]);
	PTRNODEDIEM timNODElanThiTuongUng(char MaMonHoc[],int lanThi);
	int demSLdiemCuaSV();
	void timDSDiemThiLonNhatSV(PTRNODEDIEM *&pNodeDiem, int &size);

	//Hàm này kiểm tra Node Điểm có trong DS điểm chưa nếu tồn tại kiểm tra nếu điểm lớn hơn thì thay thế
	// => hàm trả về 1 nếu MAMH trùng và điểm lớn hay  và trả về 0 nếu không thay đổi gì
	int kiemTraDiemTrongDSDIEM(PTRNODEDIEM *&pNodeDiem, int &size, PTRNODEDIEM nodeDiem);
	void pushbackDSDIEM(PTRNODEDIEM *&pNodeDiem, int &size, PTRNODEDIEM nodeDiem);

	int suaDiem(char MMH[], int lanThi);
	bool kiemTraMH(char MMH[], int lanThi);
	void nhapDiem(char MMH[], int lanThi);
	int xoaDiem(char MMH[], int lanThi);
	void xoaNODEDiem(PTRNODEDIEM );

	//ghi file điểm
	void ghiFileMon(ofstream &);
	void docFileDiem(ifstream &);

	~SINHVIEN();
	//friend class NODESV;
};








