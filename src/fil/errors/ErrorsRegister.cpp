/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "ErrorsRegister.h"

void ErrorsRegister::init() {
    if (_instance == nullptr)
        _instance = new ErrorsRegister();
}

void ErrorsRegister::clean() {
    // TODO
}

bool ErrorsRegister::containsError() {
    return _instance->_containsError;
}
