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
#include <fstream>
#include <cstring>
#include "tools.h"

using namespace std;


int CompilerOptions::parse(int argc, char **argv)
{
    if (argc == 1)
    { // If no arguments are given
        help();
        exit(0);
    }

    // Parse options
    for (int i = 1; i < argc; ++i)
    {
        char *arg = argv[i];

        if (strcmp(arg, "-h") == 0 ||
            strcmp(arg, "--help") == 0)
        {
            help();
            exit(0);
        }
        else if (strcmp(arg, "-v") == 0 ||
                 strcmp(arg, "--version") == 0)
        {
            version();
            exit(0);
        }
        else if (strcmp(arg, "-cpp") == 0)
        {
            _dest_language = CPP;
        }
        else // Input file
        {
            if (!_input_file.empty())
            {
                cerr << "Multiple input files given" << endl;
                exit(1);
            }
            _input_file = arg;
        }
    }

    // Verify options
    // Verify input file is specified
    if (_input_file.empty())
    {
        cerr << "No input file specified" << endl;
        exit(1);
    }
    // Verify input file correct extension
    if (!tools::endsWith(_input_file, ".fil"))
    {
        cerr << "Input file must be a .fil file" << endl;
        exit(1);
    }
    // Verify input file exists
    ifstream input_file(_input_file);
    if (!input_file.good())
    {
        cerr << "Input file does not exist" << endl;
        exit(1);
    }
    input_file.close();

    return 0;
}

void CompilerOptions::help()
{
    version(false);

    cout << endl;
    cout << "Usage : filc <input file> [options...]" << endl;
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
