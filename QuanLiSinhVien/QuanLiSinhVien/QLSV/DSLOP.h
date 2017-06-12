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
	void inDiemTrungBinh();
	void inDiemTongKet();
	void xuatDIEMTheoMon(DSMONHOC);
	void suaDIEMSVTheoMon(DSMONHOC);
	void xoaDIEMSVTheoMon(DSMONHOC);
	//--------------CAC HAM XU LI TREN SINH VIEN--------------------
	void nhapDSSVLOP();
	void xuatDSSVLOP();
	PTRNODESV searchAllSV(char MSV[], int &);
	int suaTTSinhVien();
	void xoaSV();
	//------ đọc ghi file
	void docfile();
	void ghiFile();
	~DSLOP();
	friend class LOP;
};

