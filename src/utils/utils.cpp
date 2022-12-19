/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "utils.h"

#include <fstream>

std::string &ltrim(std::string &input) {
    return input.erase(0, input.find_first_not_of(' '));
}

Position::Position(int line, int column, const std::string &filename)
        : _line(line), _column(column), _filename(filename) {}

int Position::getLine() const {
    return _line;
}

int Position::getColumn() const {
    return _column;
}

std::string Position::getFilename() const {
    return _filename;
}

std::string Position::getLineContent() const {
    std::ifstream file(_filename);
    std::string line;

    for (int i = 0; i < _line; i++) {
        std::getline(file, line);
    }

    file.close();

    return line;
}

std::string replace(const std::string &str, char from, char to) {
    auto cpy = str;
    for (char &c: cpy) {
        if (c == from) {
            c = to;
        }
    }

    return cpy;
}
