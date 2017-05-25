#pragma once
#include "NODEMH.h"

class DSMONHOC
{
	PTRNODEMH root;
public:
	DSMONHOC();
	void createDSMONHOC();
	void insertNodeMH(MONHOC monHoc);
	~DSMONHOC();
};

