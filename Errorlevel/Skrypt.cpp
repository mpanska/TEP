#include "stdafx.h"


int main(int argc, char* argv[], char* env[]) {

	int code = kodPowrotu(argc, argv, true);

	if (code == 11) {
		puts("Brak parametrow");
		return code;
	}	
	else if (code == 12) {
		puts("Parametr nie jest cyfra");
		return code;
	}	
	else if (code == 13) {
		puts("Niewlasciwa wartosc parametru");
		return code;
	}
	else
		puts("Przekazano: prawidlowa wartosc");

	return 0;
}
