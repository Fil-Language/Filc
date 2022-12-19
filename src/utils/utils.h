/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#ifndef FILC_UTILS_H
#define FILC_UTILS_H

#include <string>

/**
 * Trim left
 *
 * @param input
 * @return
 */
std::string &ltrim(std::string &input);

/**
 * Describe a position in a file
 */
class Position {
public:
    /**
     * Main constructor
     *
     * @param line
     * @param column
     * @param filename
     */
    Position(int line, int column, const std::string &filename);

    int getLine() const;

    int getColumn() const;

    std::string getFilename() const;

    /**
     * @return The line in the file where the position is
     */
    std::string getLineContent() const;

private:
    int _line;
    int _column;
    std::string _filename;
};

#endif //FILC_UTILS_H
