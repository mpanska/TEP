#include "stdafx.h"

/*
int main(int argc, char* argv[], char* env[])
{
    bool flag = false;

    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            string currentArg = argv[i];

            while (*env != NULL)
            {
                string currentEnvVar = *env;
                size_t index = currentEnvVar.find(currentArg);

                if (index != string::npos)
                {
                    size_t eqIndex = currentEnvVar.find('=');
                    if (eqIndex != string::npos)
                    {
                        flag = true;
                        if (!contains_s(argv, argc - 1)) {
                            cout << currentEnvVar.substr(0, eqIndex) << endl;
                            cout << '=' << endl;
                        }

                        size_t nextIndex = eqIndex;
                        do {
                            currentEnvVar = currentEnvVar.substr(nextIndex + 1);
                            nextIndex = currentEnvVar.find(';');

                            if (!contains_s(argv, argc - 1))
                                cout << currentEnvVar.substr(0, nextIndex) << endl;

                        } while (nextIndex != string::npos);
                    }
                }
                env++;
            }
            if (!flag) {
                if (!contains_s(argv, argc - 1))
                    cout << argv[i] << " = NONE" << endl;
            }
        }
    }
    else {
        if (!contains_s(argv, argc - 1))
            puts("Nie podano argumentow");
    }

    return 0;
}
         */