#pragma once
#include "NODESV.h"
//Cho trieu
//#include "DSLOP.h"

class LOP
{
private:
	char MALOP[15];
	char TENLOP[38];
	int NAMHOC;
	PTRNODESV First;
public:
	LOP();
	void nhapLOP(char MLOP[], char TENL[], int NH);
	void xuatLOP();
	void setNH(int nh);
	void setMLOP(char ML[]);
	void setTENL(char TL[]);
	void getMALOP(char ML[]);
	void getTENLOP(char TENL[]);
	int getNH();
	void nhapDiem(char MAMH[], int lanThi);
	void inDiem(char MAMH[], int lanThi);
	PTRNODESV newNODESV();
	void xuatDSSV();
	void inSVTheoHang(PTRNODESV sv, int y, int stt);
	void suaSVTheoMaSo(char _MASO[]);
	void suaSV();
	void insertFirst(SINHVIEN);
	void insertAfter(SINHVIEN , PTRNODESV);
	void insertLast(SINHVIEN);
	void createDSSV();
	PTRNODESV searchSV(char maSV[]);
	~LOP();
	friend class DSLOP;
};

