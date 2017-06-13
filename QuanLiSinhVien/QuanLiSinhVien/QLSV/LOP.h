#pragma once
#include "NODESV.h"
#include "DSMONHOC.h"
#include "Constant.h"
typedef struct DIEM_SV* PTRDIEM_SV;
typedef struct DANHSACH_DIEMSV* PTRDANHSACH_DIEMSV;

/*
	struct DIEM_SV dùng để lưu sinh viên và điểm môn học thỏa điều kiện
	=> Khi duyệt trong danh sách điểm và tìm được sinh viên thảo điều kiện để nhập điểm (Mã môn học trùng lần thi = lanThi - 1 + rớt môn)
	=> thì lưu con trỏ đến sinh viên đó và con trỏ điểm đó vào PTRDIEM_SV
*/
typedef struct DIEM_SV
{
	PTRNODESV nodeSV;
	PTRNODEDIEM diemSV;
};

typedef struct DANHSACH_DIEMSV
{
	PTRNODESV nodeSV;
	//Lưu số lượng điểm
	int n;
	PTRNODEDIEM *pDiemSV;
};

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
	void xuatDiemTheoHang(PTRDIEM_SV pDiemSV, int y, int stt);
	int nhapDiem(char MAMH[], int lanThi);

	/* Hàm này dùng để tìm tất cả sinh viên có mã môn học trùng với môn học người dùng nhập vào
	và có lần thi = lanThi - 1 đồng thời điểm ở lần thi đó phải < 4 (rớt môn)
	- Tham số truyền vào: MaMonHoc[] => chuỗi chứa mã môn học
	- lanThi => lần thi do người dùng nhập vào
	- a: mảng động cấp phát nới rộng dần lưu PTRDIEM_SV thỏa điều kiện
	- &n => biến đến cho biết có tất cả bao nhiêu sinh viên thỏa điều kiện
	*/
	void timSinhVienNhapDiem(char MaMonHoc[], int lanThi, PTRDIEM_SV *&a, int &n);
	void timSinhVienXuatDiemTheoMon(char MaMonHoc[], int lanThi, PTRDIEM_SV *&a, int &n);
	void pushBackPTRDIEM_SV(PTRDIEM_SV *&a, int &n, PTRNODESV pSv, PTRNODEDIEM pDiem);
	int inDiemTheoMON(char MAMH[], int lanThi);
	void nhapTTDiem();

	void xuatDiemTBtheoHang(PTRDANHSACH_DIEMSV diemSV, int y, int stt, DSMONHOC root);
	int inDiemTBLOP(DSMONHOC root);
	int inDiemTongketLOP();
	PTRDANHSACH_DIEMSV timDS_SVvaDiemThiLonNhat();
	void timSVInDiemTB(PTRDANHSACH_DIEMSV *&pDSDiemSV, int &SL);
	void pushbackDSDiemSV(PTRDANHSACH_DIEMSV *&dsDiemSV, int &size, PTRNODESV nodeSV, int SLDiem, PTRNODEDIEM* dsNodeDiem);
	float tinhDiemTBSinhVien(PTRNODEDIEM* dsNodeDiem, int n, DSMONHOC root);

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
	int demSVTrongLop();
	//ghi file lớp
	void ghiFile(ofstream &);
	void docFile(ifstream &);
	void ghiFileDSSV(ofstream &);
	void docFileDSSV(ifstream &);
	~LOP();
	friend class DSLOP;
};















