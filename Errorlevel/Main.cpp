#include "stdafx.h"


int main(int argc, char* argv[], char* env[])  //char* env[] zmienne systemowe
{
	pokazWszystkie(argc, argv[], env[]);

	return 0; // kod b??du dost?pny w systemie jako zmienna ERRORLEVEL
}