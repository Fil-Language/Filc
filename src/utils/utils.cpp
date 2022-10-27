/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "utils.h"

std::string &ltrim(std::string &input) {
    return input.erase(0, input.find_first_not_of(' '));
}

IndentPrinter::IndentPrinter() : IndentPrinter("\t") {}

IndentPrinter::IndentPrinter(const std::string &indent) : _indent(indent), _nb(0) {}

IndentPrinter *IndentPrinter::write(const std::string &str) {
    _buffer += str;

    return this;
}

IndentPrinter *IndentPrinter::writeIndent(const std::string &str) {
    for (int i = 0; i < _nb; ++i) {
        _buffer += _indent;
    }

    _buffer += str;

    return this;
}

IndentPrinter *IndentPrinter::indent() {
    _nb++;

    return this;
}

IndentPrinter *IndentPrinter::unindent() {
    if (_nb > 0) {
        _nb--;
    }

    return this;
}

const std::string &IndentPrinter::getBuffer() const {
    return _buffer;
}

std::ostream &operator<<(std::ostream &os, const IndentPrinter &printer) {
    return os << printer.getBuffer();
}

std::ostream &operator<<(std::ostream &os, const IndentPrinter *printer) {
    return os << printer->getBuffer();
}
