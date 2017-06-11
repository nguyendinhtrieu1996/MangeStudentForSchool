#include "SINHVIEN.h"

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

PTRNODEDIEM SINHVIEN::createDSDIEM(char MaMH[], float diemThi, int lanThi)
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
			}
		}
	}
	return temp;
}

bool SINHVIEN::kiemTraMH(char MMH[], int lanThi)
{
	return false;
}

void SINHVIEN::nhapDiem(char MMH[], int lanThi)
{
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