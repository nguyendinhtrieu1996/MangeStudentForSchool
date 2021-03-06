﻿#include "SINHVIEN.h"

SINHVIEN::SINHVIEN()
{
	dsDiem = NULL;
}

SINHVIEN::SINHVIEN(char _MASV[], char _HO[], char _TEN[], char _PHAI[], char _SDT[])
{
	strcpy_s(MASV, _MASV);
	strcpy_s(HO, _HO);
	strcpy_s(TEN, _TEN);
	strcpy_s(PHAI, _PHAI);
	strcpy_s(SDT, _SDT);
	dsDiem = NULL;
}

void SINHVIEN::nhapSV()
{
}

void SINHVIEN::xuatSV()
{
}

double SINHVIEN::tinhDiemTB()
{
	return 0.0;
}

PTRNODEDIEM SINHVIEN::createDSDIEM(char MaMH[], int diemThi, int lanThi)
{
	DIEM diem;
	diem.nhapDiem(MaMH, diemThi, lanThi);

	PTRNODEDIEM p = insertLast(diem);
	return p;
}

void SINHVIEN::xuatDSDIEM()
{
}

PTRNODEDIEM SINHVIEN::insertFirst(DIEM diemSV)
{
	PTRNODEDIEM pDiem = new NODEDIEM;
	pDiem->diem = diemSV;
	pDiem->next = dsDiem;
	dsDiem = pDiem;
	return pDiem;
}

void SINHVIEN::insertAfter()
{

}

PTRNODEDIEM SINHVIEN::insertLast(DIEM diemSV)
{
	if (dsDiem == NULL)
	{
		PTRNODEDIEM temp = insertFirst(diemSV);
		return temp;
	}

	PTRNODEDIEM p = dsDiem;
	while (p->next != NULL)
	{
		p = p->next;
	}

	PTRNODEDIEM q = new NODEDIEM;
	q->diem = diemSV;
	q->next = p->next;
	p->next = q;

	return q;
}

int SINHVIEN::demSLdiemCuaSV() {
	int dem = 0;
	for (PTRNODEDIEM pDiemMH = dsDiem; pDiemMH != NULL; pDiemMH = pDiemMH->next)
	{
		dem++;
	}
	return dem;
}

void SINHVIEN::timDSDiemThiLonNhatSV(PTRNODEDIEM *&pNodeDiem, int &size)
{
	for (PTRNODEDIEM p = dsDiem; p != NULL; p = p->next)
	{
		if (pNodeDiem == NULL)
		{
			pushbackDSDIEM(pNodeDiem, size, p);
			continue;
		}

		int check = kiemTraDiemTrongDSDIEM(pNodeDiem, size, p);

		//Mã môn học trùng và bị thay thế
		if (check == 1)
		{
			pushbackDSDIEM(pNodeDiem, size, p);
		}
	}
}

int SINHVIEN::kiemTraDiemTrongDSDIEM(PTRNODEDIEM *& pNodeDiem, int & size, PTRNODEDIEM nodeDiem)
{
	for (int i = 0; i < size; ++i)
	{
		//Kiểm tra xem 2 mã môn học có trùng nhau không
		if (strcmp(pNodeDiem[i]->diem.getMaMH(), nodeDiem->diem.getMaMH()) == 0) // 2 mã môn học trùng nhau
		{
			//Môn học có điểm thi lớn hơn
			if (nodeDiem->diem.getDiem() > pNodeDiem[i]->diem.getDiem())
			{
				pNodeDiem[i] = nodeDiem;
			}
			return -1;
		}
	}
	return 1;
}

void SINHVIEN::pushbackDSDIEM(PTRNODEDIEM *& pNodeDiem, int & size, PTRNODEDIEM nodeDiem)
{
	int m = size + 1;
	PTRNODEDIEM * aNew = (PTRNODEDIEM *)realloc(pNodeDiem, m * sizeof(PTRNODEDIEM));

	if (aNew != NULL)
	{
		aNew[size] = nodeDiem;
		size++;
		pNodeDiem = aNew;
	}
}

PTRNODEDIEM SINHVIEN::timlanThiLonNhatCuaMH(char MaMonHoc[])
{
	int maxLanThi = -1;
	PTRNODEDIEM temp = NULL;
	for (PTRNODEDIEM pDiemMH = dsDiem; pDiemMH != NULL; pDiemMH = pDiemMH->next)
	{
		DIEM diem = pDiemMH->diem;
		//Kiểm tra 2 mã môn học trùng nhau
		if (strcmp(MaMonHoc, diem.getMaMH()) == 0)
		{
			//Kiểm tra lần thi lớn hơn lần thi trước đó tìm được
			if (diem.getLanThi() > maxLanThi)
			{
				maxLanThi = diem.getLanThi();
				temp = pDiemMH;
			}
		}
	}
	return temp;
}

PTRNODEDIEM SINHVIEN::timNODElanThiTuongUng(char MaMonHoc[], int lanThi)
{
	PTRNODEDIEM temp = NULL;
	for (PTRNODEDIEM pDiemMH = dsDiem; pDiemMH != NULL; pDiemMH = pDiemMH->next)
	{
		DIEM diem = pDiemMH->diem; 
		//Kiểm tra 2 mã môn học trùng nhau
		if (strcmp(MaMonHoc, diem.getMaMH()) == 0)
		{
			//Trùng với lần thi thì lấy
			if (diem.getLanThi() == lanThi)
			{
				temp = pDiemMH;
				return temp;
			}
		}
	}
	return temp;
}

void SINHVIEN::ghiFileMon(ofstream &ofs)
{
	int sl = 0;
	if (dsDiem == NULL) {

		ofs.write(reinterpret_cast< const char *> (&sl), sizeof(int));
	}
	else {
		sl = demSLdiemCuaSV();
		ofs.write(reinterpret_cast< const char *> (&sl), sizeof(int));
		for (PTRNODEDIEM pDiemMH = dsDiem; pDiemMH != NULL; pDiemMH = pDiemMH->next)
		{
			DIEM diem = pDiemMH->diem;
			ofs.write(reinterpret_cast< const char *> (&diem), sizeof(DIEM));
		}
	}
}

void SINHVIEN::docFileDiem(ifstream &ifs)
{
	int dem = 0;//số lượng điểm
	dsDiem = NULL;
	ifs.read(reinterpret_cast< char *> (&dem), sizeof(int));
	
	for (int i = 0; i<dem; i++) {
		DIEM diem;
		ifs.read(reinterpret_cast< char *> (&diem), sizeof(DIEM));
		insertLast(diem);
	}
}

int SINHVIEN::suaDiem(char MMH[], int lanThi)
{
	PTRNODEDIEM pDiem = timNODElanThiTuongUng(MMH, lanThi);
	if(pDiem==NULL) return fail;

	xoaNoiDungVe(MINX_NDIEM, 4, 70, 18);
	veKhungSuaTTDiem();
	
	gotoxy(MINX_BSDIEM +5, MINY_BSDIEM + 4);
	cout << this->getMASV();
	gotoxy(BSDIEMCot1 + 5, MINY_BSDIEM + 4);
	cout << MMH;
	gotoxy(BSDIEMCot2 + 7, MINY_BSDIEM + 4);
	cout << lanThi;
	gotoxy(BSDIEMCot3 + 5, MINY_BSDIEM + 4);
	cout << pDiem->diem.getDiem();;
	int kiTu;
	do {
		char cdiem[constDiemThi];
		int diem = pDiem->diem.getDiem(); 

		cdiem[0] = '/0';

		itoa(diem, cdiem, 10);
		kiTu = 0;
		fflush(stdin);
		char temp = _getch();
		if (temp == 0 || temp == -32)
		{
			temp = _getch();
			kiTu = temp + 1000;
		}
		else
		{
			kiTu = temp;
		}

		if (kiTu == ESC)
		{
			return 1;
		}
		if (kiTu == F2)
		{
			
				int check = NhapSo(cdiem, constDiemThi, BSDIEMCot3 + 5, MINY_BSDIEM + 4);
				diem = atoi(cdiem);
				if (diem > 10) {
					char title[10] = "THONG BAO";
					char message[30] = "Diem khong hop le!";
					char td[2][10] = { "Chinh sua", "    Huy" };
					gotoxy(MINX_ALERTTB, MINY_ALERTNL);
					int check2 = veKhungThongBao(title, message, td);
					setNormallText();
					//Nguoi dung chon chinh sua diem
					if (check2 == 0)
					{
						//Xóa bảng thông báo vừa in ra
						xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
						xoaNoiDungVe(BSDIEMCot3 + 4, MINY_BSDIEM + 4, 3, 1);
						gotoxy(BSDIEMCot3 + 5, MINY_BSDIEM + 4);
						diem = pDiem->diem.getDiem();

						cdiem[0] = '/0';

						itoa(diem, cdiem, 10);
						cout << diem;
						continue;
					}
					else if (check2 == 1)
					{
						xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);

						xoaNoiDungVe(MINX_BLOP - 1, MINY_BLOP - 1, 70, 7);
						return 1;
					}
				 }
				else {
					//tim lan thi cao nhat
					PTRNODEDIEM pNodeDiemThiSV = timlanThiLonNhatCuaMH(MMH);
					int MaxLan = pNodeDiemThiSV->diem.getLanThi();
					if (lanThi == MaxLan) {

						pDiem->diem.setDiem(diem);
						gotoxy(MINX_ALERTTB, 24);
						cout << "Da sua Diem";
						Sleep(1000);
						xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
						gotoxy(BSDIEMCot3 + 5 + strlen(cdiem), MINY_BSDIEM + 4);
					}
					//điểm hiện tại không phải lần thi sau cùng
					else {
						if (diem > 4)
						{
							char title[10] = "THONG BAO";
							char message[30] = "Diem khong hop le!";
							char td[2][10] = { "Chinh sua", "    Huy" };
							gotoxy(MINX_ALERTTB, MINY_ALERTNL);
							int check2 = veKhungThongBao(title, message, td);
							setNormallText();
							//Nguoi dung chon chinh sua diem
							if (check2 == 0)
							{
								//Xóa bảng thông báo vừa in ra
								xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
								xoaNoiDungVe(BSDIEMCot3 + 4, MINY_BSDIEM + 4, 3, 1);
								gotoxy(BSDIEMCot3 + 5, MINY_BSDIEM + 4);
								diem = pDiem->diem.getDiem();

								cdiem[0] = '/0';

								itoa(diem, cdiem, 10);
								cout << diem;
								continue;
							}
							else if (check2 == 1)
							{
								xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);

								xoaNoiDungVe(MINX_BLOP - 1, MINY_BLOP - 1, 70, 7);
								return 1;

							}
						}
						else
						{
							pDiem->diem.setDiem(diem);
							gotoxy(MINX_ALERTTB, 24);
							cout << "Da sua Diem";
							Sleep(1000);
							xoaNoiDungVe(MINX_ALERTTB, 24, 30, 1);
							gotoxy(BSDIEMCot3 + 4 + strlen(cdiem), MINY_BSDIEM + 4);
							
						}
					}
				}	
		}

	} while (true);
	return 1;
}

bool SINHVIEN::kiemTraMH(char MMH[], int lanThi)
{
	return false;
}

void SINHVIEN::nhapDiem(char MMH[], int lanThi)
{
}

int SINHVIEN::xoaDiem(char MMH[], int lanThi)
{
	PTRNODEDIEM pDiem = timNODElanThiTuongUng(MMH, lanThi);
	if (pDiem == NULL) return fail;

	xoaNoiDungVe(MINX_NDIEM, 4, 70, 18);
	veKhungSuaTTDiem();

	gotoxy(MINX_BSDIEM + 5, MINY_BSDIEM + 4);
	cout << this->getMASV();
	gotoxy(BSDIEMCot1 + 5, MINY_BSDIEM + 4);
	cout << MMH;
	gotoxy(BSDIEMCot2 + 7, MINY_BSDIEM + 4);
	cout << lanThi;
	gotoxy(BSDIEMCot3 + 5, MINY_BSDIEM + 4);
	cout << pDiem->diem.getDiem();

	char message1[] = "Ban co chac chan xoa?";
	char title[] = "THONG BAO";
	char td[2][10] = { "  Co", "   Khong" };
	gotoxy(MINX_ALERTTB, MINY_ALERTNL);
	int select = veKhungThongBao(title, message1, td);
	setNormallText();
	if (select == 0)
	{
		xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);

		PTRNODEDIEM pNodeDiemThiSV = timlanThiLonNhatCuaMH(MMH);
		int MaxLan = pNodeDiemThiSV->diem.getLanThi();
		if (lanThi == MaxLan) 
		{  

			xoaNODEDiem(pDiem);
			char title[] = "THONG BAO";
			char message[] = "    Xoa thanh cong";
			char td[2][10] = { "Tiep tuc", "  Thoat" };
			gotoxy(MINX_ALERTTB, MINY_ALERTNL);
			int select = veKhungThongBao(title, message, td);
			setNormallText();
			if (select == 0)
			{
				xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
				xoaNoiDungVe(MINX_BSV, MINY_BSV, 70, 10);
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else {
			char title[] = "THONG BAO";
			char message[] = " Xoa khong thanh cong";
			char td[2][10] = { "Tiep tuc", "  Thoat" };
			gotoxy(MINX_ALERTTB, MINY_ALERTNL);
			int select = veKhungThongBao(title, message, td);
			setNormallText();
			if (select == 0)
			{
				xoaNoiDungVe(MINX_ALERTTB, MINY_ALERTNL, widthAlert, heightAlert);
				xoaNoiDungVe(MINX_BSV, MINY_BSV, 70, 10);
				return 0;
			}
			else
			{
				return 1;
			}
		}

		

	}
	return 1;
}

void SINHVIEN::xoaNODEDiem(PTRNODEDIEM p)
{
	if (dsDiem == p) {

		dsDiem = p->next;
		delete p;
	}
	else {
		PTRNODEDIEM q;
		for (q = dsDiem; q->next != p; q = q->next) {}
		q->next = p->next;
		delete p;
	}
}

SINHVIEN::~SINHVIEN()
{
}

char* SINHVIEN::getMASV(){
	return MASV;
}

char*SINHVIEN::getHO()
{
	return HO;
}

char*SINHVIEN::getPHAI(){
	return PHAI;
}

char*SINHVIEN::getTEN(){
	return TEN;
}

char* SINHVIEN::getSDT(){
	return SDT;
}

void SINHVIEN::setMASV(char _MASV[])
{
	strcpy(MASV, _MASV);
}

void SINHVIEN::setHO(char _HO[])
{
	strcpy(HO, _HO);
}

void SINHVIEN::setPHAI(char _PHAI[])
{
	strcpy(PHAI, _PHAI);
}

void SINHVIEN::setSDT(char _SDT[])
{
	strcpy(SDT, _SDT);
}

void SINHVIEN::setTEN(char _TEN[])
{
	strcpy(TEN, _TEN);
}