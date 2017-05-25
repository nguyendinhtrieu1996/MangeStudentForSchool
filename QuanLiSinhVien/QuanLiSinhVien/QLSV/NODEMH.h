#pragma once
#include "MONHOC.h"
typedef class NODEMH* PTRNODEMH;

class NODEMH
{
private:
	char MAMH[20];
	MONHOC MH;
	PTRNODEMH left;
	PTRNODEMH right;
public:
	NODEMH();
	~NODEMH();

	friend class DSMONHOC;
};

