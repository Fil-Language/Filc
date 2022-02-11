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

#define VERSION "1.0"
#define AUTHORS "Kevin Traini"
#define LICENSE "GNU General Public License v3.0"

class CompilerOptions
{
private: // Structures declarations
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

private:
    static void help();

    static void version(bool isCalledDirectly = true);

    // _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.

private: // Attributes
    inline static dest_language _dest_language = CPP;
};


#endif //FILC_COMPILEROPTIONS_H
