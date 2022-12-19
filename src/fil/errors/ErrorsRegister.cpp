/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "ErrorsRegister.h"

ErrorsRegister *ErrorsRegister::_instance = nullptr;

ErrorsRegister::ErrorsRegister() {
    _messages = std::vector<Message *>();
}

void ErrorsRegister::init() {
    if (_instance == nullptr)
        _instance = new ErrorsRegister();
}

void ErrorsRegister::clean() {
    _instance->_messages.clear();
}

bool ErrorsRegister::containsError() {
    return _instance->_containsError;
}

bool ErrorsRegister::containsWarning() {
    return _instance->_containsWarning;
}

void ErrorsRegister::addWarning(const std::string &message, Position *position) {
    _instance->_messages.push_back(new Warning(message, position));
    _instance->_containsWarning = true;
}

void ErrorsRegister::addError(const std::string &message, Position *position) {
    _instance->_messages.push_back(new Error(message, position));
    _instance->_containsError = true;
}

void ErrorsRegister::dump(std::ostream &out) {
    for (auto &message: _instance->_messages) {
        out << message->dump() << std::endl;
    }
}
