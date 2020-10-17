#include "stdafx.h"


int main(int argc, char* argv[], char* env[])
{
	if (argc > 2 && !contains_s(argv, 2)) {
		if (!contains_s(argv, argc - 1))
				puts("13");

		return 13;
	}

	if (argv[1] == nullptr || contains_s(argv, 1)) {
		if (!contains_s(argv, argc - 1))
				puts("11");

		return 11;
	}

	if (!isdigit(*argv[1]) || int(*argv[1]) < 0) {
		if (!contains_s(argv, argc - 1))
				puts("12");

		return 12;
	}

	if (!contains_s(argv, argc - 1))
			puts(argv[1]);

	return (int)*argv[1] - 48;
}

