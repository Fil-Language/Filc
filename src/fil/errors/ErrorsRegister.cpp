/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
 * -----------------------
 */
#include "ErrorsRegister.h"

ErrorsRegister *ErrorsRegister::_instance = nullptr;

ErrorsRegister::ErrorsRegister()
        : _messages(std::vector<Message *>()) {}

void ErrorsRegister::init() {
    if (_instance == nullptr)
        _instance = new ErrorsRegister();
}

void ErrorsRegister::clean() {
    if (_instance)
        _instance->_messages.clear();
}

bool ErrorsRegister::containsError() {
    return _instance != nullptr && _instance->_containsError;
}

bool ErrorsRegister::containsWarning() {
    return _instance != nullptr && _instance->_containsWarning;
}

void ErrorsRegister::addWarning(Message *message) {
    if (_instance) {
        _instance->_messages.push_back(message);
        _instance->_containsWarning = true;
    }
}

void ErrorsRegister::addError(Message *message) {
    if (_instance) {
        _instance->_messages.push_back(message);
        _instance->_containsError = true;
    }
}

void ErrorsRegister::dump(std::ostream &out) {
    if (_instance) {
        for (auto &message: _instance->_messages) {
            out << message->dump() << std::endl;
        }
    }
}
