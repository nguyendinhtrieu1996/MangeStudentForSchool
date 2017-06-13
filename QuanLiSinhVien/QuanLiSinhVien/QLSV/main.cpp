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
#define GHIFILE 54

#define THOAT 61
int main() {
	DSMONHOC DANHSACHMH;
	DSLOP dsLOP;

	//đoc file
	dsLOP.docfile();
	DANHSACHMH.docFile();

	int mainMenu = 0, childMenu = 0;

	do
	{
		setNormallText();
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
			DANHSACHMH.xuatDSMON();
			break;
		}
		case SUAMH:
		{
			DANHSACHMH.suaMON();
			break;
		}
		
		case THEMDIEM:
		{
			dsLOP.nhapDiemLOP(DANHSACHMH);
			break;
		}
		case SUADIEM:
		{
			dsLOP.suaDIEMSVTheoMon(DANHSACHMH);
			break;
		}
		case XOADIEM:
		{
			dsLOP.xoaDIEMSVTheoMon(DANHSACHMH);
			break;
		}
		case DIEMTONG:
		{
			dsLOP.inDiemTongKet();
			
			break;
		}
		case DIEMMON:
		{
			dsLOP.xuatDIEMTheoMon(DANHSACHMH);
			break;
		}
		case DIEMTB:
		{
			dsLOP.inDiemTrungBinh();
			
			break;
		}
		case GHIFILE:
		{
			dsLOP.ghiFile();
			DANHSACHMH.ghiFileMon();
			gotoxy(68, 7);
			SetColor(green);
			cout << "GHI FILE THANH CONG";
			_getch();

			break;
		}
		case THOAT:
		{
			setNormallText();
			char title[10] = "THONG BAO";
			char message[30] = "Ban co muon luu FIFE";
			char td[2][10] = { "   Co  ", "   Khong" };
			gotoxy(MINX_ALERTTB, MINY_ALERTTB-10);
			int checkTHONGBAO = veKhungThongBao(title, message, td);
			//Nguoi dung chon luu
			setNormallText();
			if (checkTHONGBAO == 0)
			{
				dsLOP.ghiFile();
				DANHSACHMH.ghiFileMon();
				exit(0);
			}
			//Nguoi dung chon khong
			else if (checkTHONGBAO == 1 )
			{
				exit(0);
			}
			
			break;
		}
		}
		} while (true);

		normal();
		gotoxy(60, MAXY - 1);
		system("pause");
		return 0;
}

