#pragma once
#include "MONHOC.h"
typedef class NODEMH* PTRNODEMH;

class NODEMH
{
private:
	char MAMH[constMAMON];
	MONHOC MH;
	PTRNODEMH left;
	PTRNODEMH right;
public:
	NODEMH();
	~NODEMH();
	char* getMAMH();
	void setMAMH(char[]);
	friend class DSMONHOC;
};

