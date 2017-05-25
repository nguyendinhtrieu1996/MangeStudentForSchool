#include "DSMONHOC.h"



DSMONHOC::DSMONHOC()
{
	root = NULL;
}

void DSMONHOC::createDSMONHOC()
{
	MONHOC monHoc;

	char maMH[15];
	char tenMH[40];
	int sTCLT;
	int sTCTH;

	//tiêu đề chức năng nhập danh scahs môn học
	char titleNhapDSMH[] = "NHAP DANH SACH MON HOC";
	
	//x tọa độ bắt đầu in tiêu đề
	int x = MINX_NDSMH + (MAXX_NDSMH - MINX_NDSMH) / 2 - strlen(titleNhapDSMH) / 2 + 1;

	setGreenText();
	gotoxy(x, 2);
	cout << titleNhapDSMH;
	normal();

NHAPDSMONHOC:
	maMH[0] = '\0';
	tenMH[0] = '\0';
	sTCLT = 0;
	sTCTH = 0;

	veKhungNhapDSMONHOC();

NHAPTENMONHOC:
	int checkMH = NhapChuoiVaChuSo(maMH, 15, MINX_NDSMH + 1, MINY_NDSMH + 4);
	if (checkMH == 0)
	{

	}
	else if (checkMH == ESC || checkMH == -1)
	{

	}
}

void DSMONHOC::insertNodeMH(MONHOC monHoc)
{

}

DSMONHOC::~DSMONHOC()
{
}
