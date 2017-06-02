#pragma once
#include "NODESV.h"
#include "Constant.h"

class LOP
{
private:
	char MALOP[constMALOP];
	char TENLOP[constTENLOP];
	int NAMHOC;
	PTRNODESV First;
public:
	LOP();
	//-------------------XU LI CHUC NANG LOP---------------
	void nhapLOP(char MLOP[], char TENL[], int NH);
	void xuatLOP();
	void setNH(int nh);
	void setMLOP(char ML[]);
	void setTENL(char TL[]);
	void getMALOP(char ML[]);
	void getTENLOP(char TENL[]);
	int getNH();
	//-------------------XU LI CHUC NANG DIEM-----------------
	void nhapDiem(char MAMH[], int lanThi);
	void inDiem(char MAMH[], int lanThi);
	//-------------------XU LI CHUC NANG SINH VIEN------------
	//*****************CAC HAM HO TRO SU LI NODESV*************
	//Thêm con trỏ sinh viên vào cuối mảng động
	void PTRNODESVPushBack(PTRNODESV *&, int &, PTRNODESV);
	PTRNODESV newNODESV();
	void insertFirst(SINHVIEN);
	void insertAfter(SINHVIEN , PTRNODESV);
	void insertLast(SINHVIEN);
	void createDSSV();
	void xuatDSSV();
	//**********************************************************
	PTRNODESV searchSV(char maSV[]);
	void inSVTheoHang(PTRNODESV sv, int y, int stt);
	void suaSVTheoMaSo(char _MASO[]);
	void suaSVtheoConTro(PTRNODESV);
	void xoaSVtheoConTro(PTRNODESV);
	void hienThiTTSV(PTRNODESV);
	~LOP();
	friend class DSLOP;
};

