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
	//--------------CAC HAM XU LI TREN DIEM------------------------
	bool nhapDiemLOP(DSMONHOC ds, char MLOP[], char MAMH[], int lanThi);
	bool inBangDiemTheoLanThi(DSMONHOC ds, char MLOP[], char MAMH[], int lanThi);
	bool inDiemTrungBinh(char MLOP[]);
	void inDiemTongKet(char MLOP[]);
	//--------------CAC HAM XU LI TREN SINH VIEN--------------------
	bool nhapDSSVLOP();
	bool xuatDSSVLOP();
	PTRNODESV searchAllSV(char MSV[], int &);
	int suaTTSinhVien();
	void xoaSV();

	//---------xử lý Điểm
	void themDIEM(DSMONHOC);
	~DSLOP();
	friend class LOP;
};

