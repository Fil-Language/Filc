/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#ifndef FILC_UTILS_H
#define FILC_UTILS_H

#include <string>

std::string &ltrim(std::string &input);

class IndentPrinter {
public:
    IndentPrinter();

    explicit IndentPrinter(const std::string &indent);

    IndentPrinter *write(const std::string &str);

    IndentPrinter *writeIndent(const std::string &str);

    IndentPrinter *indent();

    IndentPrinter *unindent();

    const std::string &getBuffer() const;

private:
    std::string _indent;
    std::string _buffer;
    int _nb;
};

std::ostream &operator<<(std::ostream &os, const IndentPrinter &printer);

std::ostream &operator<<(std::ostream &os, const IndentPrinter *printer);

#endif //FILC_UTILS_H
