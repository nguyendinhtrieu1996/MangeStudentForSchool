#pragma once
#include "NODEMH.h"

class DSMH
{
	PTRNODEMH root;
public:
	DSMH();
	PTRNODEMH newNODEMH();
	void insertNODEMH(PTRNODEMH &p, int x, int a);
	void nhapDSMH();
	void xuatDSMH();
	bool kiemTraMH(char mamh[]);
	bool searchMH(char mamh[]);
	~DSMH();
};

