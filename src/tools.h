/* _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
 *     Created by Kevin Traini
 *
 *     Fil compiler
 *
 *     GNU General Public License v3.0
 * _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
 */

#ifndef FILC_TOOLS_H
#define FILC_TOOLS_H

#include <string>

namespace tools
{
    bool endsWith(std::string const &fullString, std::string const &ending)
    {
        if (fullString.length() >= ending.length())
            return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
        else
            return false;
    }
}
#endif //FILC_TOOLS_H
