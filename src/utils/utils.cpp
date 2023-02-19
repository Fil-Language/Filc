/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
 * -----------------------
 */
#include "utils.h"

#include <fstream>
#include <sstream>

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

std::string Position::dump() const {
    return _filename + ":" + std::to_string(_line) + ":" + std::to_string(_column);
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

std::string to_string(char *str) {
    std::stringstream ss;
    ss << str;

    return ss.str();
}

std::vector<std::string> split(const std::string &str, char delim) {
    std::vector<std::string> result;

    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}
