#include "stdafx.h"


int main(int argc, char* argv[], char* env[])
{
	puts("argumenty programu:");
	for (int i = 0; i < argc; i++)
		puts(argv[i]);
	puts("\nzmienne srodowiska:");
	while (*env != NULL) 
		puts(*env++);

	return 0;
}
