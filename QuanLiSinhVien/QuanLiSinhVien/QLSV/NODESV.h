#pragma once
#include "SINHVIEN.h"
typedef class NODESV* PTRNODESV;

class NODESV
{
private:
	SINHVIEN SV;
	PTRNODESV next;
public:
	NODESV();
	~NODESV();
	friend class LOP;
	friend class DSLOP;
};

