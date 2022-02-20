/* _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
 *     Created by Kevin Traini
 *
 *     Fil compiler
 *
 *     GNU General Public License v3.0
 * _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
 */

#include "FilCompiler.h"

#include <iostream>
#include <antlr4-runtime.h>
#include "FilLexer.h"

using namespace std;
using namespace antlr4;
using namespace antlrcpp;

void FilCompiler::compile(const string &inputFileName)
{
    ifstream inputFile(inputFileName);
    ANTLRInputStream input(inputFile);
    FilLexer lexer(&input);

    CommonTokenStream tokens(&lexer);
    tokens.fill();
    for (auto token: tokens.getTokens())
    {
        cout << token->toString() << endl;
    }
}
