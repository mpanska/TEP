#include "stdafx.h"


bool contains_s(char* argv[], int position)
{
	if (argv[position][0] == '/' && (argv[position][1] == 's' || argv[position][1] == 'S'))
		return true;
	else
		return false;
}
