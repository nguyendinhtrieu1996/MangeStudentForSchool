#pragma once
#include "DIEM.h"
typedef class NODEDIEM* PTRNODEDIEM;

class NODEDIEM
{
private:
	DIEM diem;
	PTRNODEDIEM next;
public:
	NODEDIEM();
	~NODEDIEM();
	friend class SINHVIEN;
	friend class LOP;
};

