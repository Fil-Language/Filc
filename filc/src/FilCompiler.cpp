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

void FilCompiler::compile(const string &inputFileName)
{
    ifstream inputFile(inputFileName);
    antlr4::ANTLRInputStream input(inputFile);
    FilLexer lexer(&input);

    antlr4::CommonTokenStream tokens(&lexer);
    tokens.fill();
    for (auto token: tokens.getTokens())
    {
        cout << token->toString() << endl;
    }
}
