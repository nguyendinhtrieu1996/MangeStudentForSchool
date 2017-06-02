#include "NODEMH.h"

NODEMH::NODEMH()
{
	left = NULL;
	right = NULL;
}

NODEMH::~NODEMH()
{
}

char * NODEMH::getMAMH()
{
	return MAMH;
}

void NODEMH::setMAMH(char _MAMH[])
{
	strcpy(MAMH, _MAMH);
}
