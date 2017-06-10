#pragma once
#include "DSLOP.h"
#include "DSMONHOC.h"
#include "menu.h"

#define THEMLOP 11
#define SUALOP 12
#define XOALOP 13
#define INLOP 14

#define THEMSV 21
#define SUASV 22
#define XOASV 23
#define INDSSV 24

#define THEMMH 31
#define SUAMH 32
#define XOAMH 33
#define INDSMH 34

#define THEMDIEM 41
#define SUADIEM 42
#define XOADIEM 43

#define DIEMTONG 51
#define DIEMMON 52
#define DIEMTB 53


int main() {
	DSMONHOC DANHSACHMH;
	DSLOP dsLOP;
	//đoch file
	dsLOP.docfile();
	DANHSACHMH.docFile();

	int mainMenu = 0, childMenu = 0;
	do
	{
		int chon = veMenu(mainMenu, childMenu);
		mainMenu = chon / 10;
		childMenu = chon % 10;
		switch (chon)
		{
		case THEMLOP:
		{
			dsLOP.nhapDSLOP();
			break;
		}
		case SUALOP:
		{
			dsLOP.chinhSuaTTLOP();
			break;
		}
		case XOALOP:
		{
			dsLOP.xoaLOP();
			break;
		}
		case INLOP:
		{
			dsLOP.xuatDSLOPNK();
			break;
		}
		case THEMSV:
			dsLOP.nhapDSSVLOP();
			break;

		case SUASV:
			dsLOP.suaTTSinhVien();
			break;

		case INDSSV:
			dsLOP.xuatDSSVLOP();
			break;

		case XOASV:
			dsLOP.xoaSV();
			break;

		case THEMMH:
		{
			DANHSACHMH.createDSMONHOC();
			break;
		}
		case XOAMH:
		{
			DANHSACHMH.xoaMON();
			break;
		}
		case INDSMH:
		{
			DANHSACHMH.xuatDSLMON();
			break;
		}
		case SUAMH:
		{
			DANHSACHMH.suaMON();
			break;
		}

		case THEMDIEM:
		{
			//veKhungNhapDiemChoLop();
			//veKhungNhapDiemTrenDSLop();
			
			dsLOP.nhapDiemLOP(DANHSACHMH);
			break;
		}
		case DIEMTONG:
		{
			dsLOP.ghiFile();
			DANHSACHMH.ghiFileMon();
			break;
		}
		case DIEMTB:
		{
			
			break;
		}
		}
		} while (true);

		normal();
		gotoxy(60, MAXY - 1);
		system("pause");
		return 0;
}

