#pragma once
#include "NODEMH.h"

class DSMONHOC
{
	PTRNODEMH root;
public:
	DSMONHOC();
	 
	//	Hàm tạo (thêm) môn học vào DSMH
	void createDSMONHOC();

	void insertNodeMH(PTRNODEMH &p, MONHOC monHoc);

	//	Hàm này kiểm tra mã môn học có tồn tại trong danh sách môn học hay không
	//	=> kết quả trả về con trỏ trỏ đến NODE môn học đó
	PTRNODEMH kiemTraMH(char maMH[]);

	void xuatDSLMON();
	void duyetMAMHtang(PTRNODEMH, PTRNODEMH a[], int&);
	void xepDSTangTheoTenMH(PTRNODEMH a[], int,int);
	void xepDSTangTheoTenMHdemo(PTRNODEMH a[], int);
	void inMonHocTheoHang(PTRNODEMH, int, int);
	//Xóa môn học
	void XoaNODEMonHoc( PTRNODEMH,char[]);
	void XoaTruongHop3(PTRNODEMH &, PTRNODEMH &);
	void xoaMON();
	void hienThiTTMON(PTRNODEMH);
	~DSMONHOC();
};

