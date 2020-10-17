#include "stdafx.h"

int main(int argc, char* argv[], char* env[])
{
	int counter = 0;
	string result = "";
	while (*env != NULL)
	{
		string currentEnvVar = *env;
		if (env[counter++][0] == 'a') 
		{
			size_t eqIndex = currentEnvVar.find('=');
			if (eqIndex != string::npos)
			{
				do {
					currentEnvVar = currentEnvVar.substr(eqIndex + 1);
					eqIndex = currentEnvVar.find(';');
					cout << currentEnvVar.substr(0, eqIndex) + " ";
				} while (eqIndex != string::npos);
			}
		}
		env++;
	}
}