/* _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
 *     Created by Kevin Traini
 *
 *     Fil compiler
 *
 *     GNU General Public License v3.0
 * _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
 */

#include "CompilerOptions.h"

int main(int argc, char **argv)
{
    int parse_result = CompilerOptions::parse(argc, argv);
    if (parse_result != 0)
        return parse_result;

    return 0;
}
