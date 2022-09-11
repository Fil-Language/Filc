/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#ifndef FILC_PROGRAM_HPP
#define FILC_PROGRAM_HPP

#include "AST.h"

#include <string>

namespace ast {
    class Program {
    public:
        Program() = default;

        explicit Program(const std::string &moduleName) {
            _moduleName = moduleName;
        }

        ~Program() = default;

    private:
        std::string _moduleName;
    };
}

#endif //FILC_PROGRAM_HPP
