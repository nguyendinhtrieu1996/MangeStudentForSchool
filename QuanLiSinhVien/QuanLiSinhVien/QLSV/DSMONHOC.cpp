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

NHAPDSMONHOC:
	maMH[0] = '\0';
	tenMH[0] = '\0';
	sTCLT = 0;
	sTCTH = 0;

	veKhungNhapDSMONHOC();

	Sleep(10000);
}

void DSMONHOC::insertNodeMH(MONHOC monHoc)
{

}

DSMONHOC::~DSMONHOC()
{
}
