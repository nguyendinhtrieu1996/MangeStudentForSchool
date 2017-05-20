#include "DSMH.h"

DSMH::DSMH()
{
	root = NULL;
}

PTRNODEMH DSMH::newNODEMH()
{
	PTRNODEMH p;
	p = new NODEMH;
	return p;
}

void DSMH::insertNODEMH(PTRNODEMH &p, int x, int a)
{
	//
}

void DSMH::nhapDSMH()
{
	MONHOC MH;
	veKhungNhapMH();
	do
	{

	} while (true);
}
 
void DSMH::xuatDSMH()
{

}

bool DSMH::kiemTraMH(char mamh[])
{
	return false;
}

bool DSMH::searchMH(char mamh[])
{
	return false;
}


DSMH::~DSMH()
{
}
