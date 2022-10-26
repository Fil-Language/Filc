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