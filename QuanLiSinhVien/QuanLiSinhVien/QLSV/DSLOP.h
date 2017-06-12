#pragma once
#include "LOP.h"
#include "DSMONHOC.h"

class DSLOP
{
private:
	int SL;
	LOP DANHSACHLOP[constNumberDSLOP];
public:
	DSLOP();
	//---------------CAC HAM XU LI TREN DSLOP------------------
	void nhapDSLOP();
	void xuatDSLOPNK();
	int searchLOP(char MLOP[]);
	void chinhSuaTTLOP();
	void xoaLOP();
	void inLOPTheoHang(LOP lop, int y, int stt);
	void pushBackChiSoDSLOP(int *&a, int &n, int i);;

	//--------------CAC HAM XU LI TREN DIEM------------------------
	void nhapDiemLOP(DSMONHOC DSMH);
	bool inBangDiemTheoLanThi(DSMONHOC ds, char MLOP[], char MAMH[], int lanThi);
	bool inDiemTrungBinh(char MLOP[]);
	void inDiemTongKet(char MLOP[]);
	void xuatDIEMTheoMon(DSMONHOC);
	//--------------CAC HAM XU LI TREN SINH VIEN--------------------
	bool nhapDSSVLOP();
	bool xuatDSSVLOP();
	PTRNODESV searchAllSV(char MSV[], int &);
	int suaTTSinhVien();
	void xoaSV();
	//------ đọc ghi file
	void docfile();
	void ghiFile();
	~DSLOP();
	friend class LOP;
};

