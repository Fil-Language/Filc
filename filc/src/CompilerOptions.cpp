/* _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
 *     Created by Kevin Traini
 *
 *     Fil compiler
 *
 *     GNU General Public License v3.0
 * _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
 */

#include "CompilerOptions.h"

#include <iostream>
#include <string>
#include <cstring>

using namespace std;


int CompilerOptions::parse(int argc, char **argv)
{
    if (argc == 1)
    { // If no arguments are given
        help();
        exit(0);
    }

    // Parse options
    for (int i = 0; i < argc; ++i)
    {
        char *arg = argv[i];

        if (strcmp(arg, "-h") == 0 ||
            strcmp(arg, "--help") == 0)
        {
            help();
            exit(0);
        }
        if (strcmp(arg, "-v") == 0 ||
            strcmp(arg, "--version") == 0)
        {
            version();
            exit(0);
        }
        if (strcmp(arg, "-cpp") == 0)
        {
            _dest_language = CPP;
        }
    }

    // Verify options
    // nothing to verify

    return 0;
}

void CompilerOptions::help()
{
    version(false);

    cout << endl;
    cout << "\t-h, --help       " << "Show this help" << endl;
    cout << "\t-v, --version    " << "Show the version" << endl;
    cout << "\t-cpp             " << "Pre-compile to cpp before use cpp compiler to obtain ass code" << endl;
}

void CompilerOptions::version(bool isCalledDirectly)
{
    if (isCalledDirectly)
    {
        cout << "    _______ __             ___  ____ \n"
                "   / ____(_) /____   _   _<  / / __ \\\n"
                "  / /_  / / / ___/  | | / / / / / / /\n"
                " / __/ / / / /__    | |/ / /_/ /_/ / \n"
                "/_/   /_/_/\\___/    |___/_/(_)____/  \n"
                "                                     " << endl;
    }
    else
    {
        cout << "Filc v" << VERSION << endl;
    }

    cout << "Created by : " << AUTHORS << endl;
    cout << LICENSE << endl;
}
