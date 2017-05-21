#pragma once
#include "LOP.h"
#include "DSMH.h"

class DSLOP
{
private:
	int SL;
	LOP DANHSACHLOP[100];
public:
	DSLOP();
	void nhapDSLOP();
	void xuatDSLOPNK();
	bool nhapDSSVLOP( );
	bool xuatDSSVLOP();
	int searchLOP(char MLOP[]);
	void chinhSuaTTLOP();
	void xoaLOP();
	bool nhapDiemLOP(DSMH ds, char MLOP[], char MAMH[], int lanThi);
	bool inBangDiemTheoLanThi(DSMH ds, char MLOP[], char MAMH[], int lanThi);
	bool inDiemTrungBinh(char MLOP[]);
	void inDiemTongKet(char MLOP[]);
	void inLOPTheoHang(LOP lop, int y, int stt);
	PTRNODESV searchAllSV(char MSV[], int &);
	int suaTTSinhVien();
	void xoaSV();
	~DSLOP();
	friend class LOP;
};

