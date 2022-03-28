/* _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
 *     Created by Kevin Traini
 *
 *     Fil compiler
 *
 *     GNU General Public License v3.0
 * _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
 */

#ifndef FILC_COMPILEROPTIONS_H
#define FILC_COMPILEROPTIONS_H

#include <string>

#define VERSION "1.0"
#define AUTHORS "Kevin Traini"
#define LICENSE "GNU General Public License v3.0"

class CompilerOptions
{
public: // Structures declarations
    /**
     * The destination language for the compiler
     * - CPP : pre-compilation, use cpp compiler after to have assembler code
     */
    typedef enum dest_language
    {
        CPP,
    } dest_language;

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

public: // Methods
    static int parse(int argc, char **argv);

    static dest_language getDestLanguage();

    static const std::string &getInputFile();

private:
    static void help();

    static void version(bool isCalledDirectly = true);

    CompilerOptions() = default;

    ~CompilerOptions() = default;

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

private: // Attributes
    inline static dest_language _dest_language = CPP;
    inline static std::string _input_file;
};


#endif //FILC_COMPILEROPTIONS_H
