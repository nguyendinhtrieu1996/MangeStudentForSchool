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
	void xepDSTangTheoTenMH(PTRNODEMH a[], int, int);
	void xepDSTangTheoTenMHdemo(PTRNODEMH a[], int);
	void inMonHocTheoHang(PTRNODEMH, int, int);
	//Xóa môn học
	void XoaNODEMonHoc(PTRNODEMH &,char[]);
	void XoaTruongHop3(PTRNODEMH &, PTRNODEMH &);
	void xoaMON();
	void hienThiTTMON(PTRNODEMH);

	//	------------HÀM DÙNG THÊM CON TRỎ VÀO CUỐI MẢNG 
	//	=> Mảng động cấp phát nới rộng dần
	//Hàm thêm con trỏ PTRNODEMH vào cuối mảng động chứa con trỏ PTRMODEMH
	//PTRNODEMH *& => truyền vào mảng mỗi phần tử có kiểu dữ liệu con trỏ PTRNODEMH
	//n => số lượng phần tử mảng động đang có
	// PTRNODEMH => con trỏ muốn thêm vào mảng động
	void PTRNODEMHPushBack(PTRNODEMH *&, int &, PTRNODEMH);
	~DSMONHOC();
};

