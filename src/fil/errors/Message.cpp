/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "Message.h"

Message::Message(const std::string &message, Position *position)
        : _message(message), _position(position) {}

Warning::Warning(const std::string &message, Position *position) : Message(message, position) {}

std::string printMessage(const std::string &message,
                         Position *position,
                         const std::string &type,
                         const std::string &color) {
    static const std::string reset = "\033[0m";

    std::string res = color + type + ": " + reset + message + "\n  " + position->dump() + "\n\n";

    std::string n = " " + std::to_string(position->getLine()) + " ";

    res += n + "|" + position->getLineContent() + "\n";
    res += std::string(n.length(), ' ') + "|";
    std::string spaces = position->getColumn() > 0 ? std::string(position->getColumn() - 1, ' ') : "";
    res += spaces + color + "^" + reset + "\n";

    return res + "\n";
}

std::string Warning::dump() const {
    return printMessage(_message, _position, "WARNING", "\033[1;33m");
}

Error::Error(const std::string &message, Position *position) : Message(message, position) {}

std::string Error::dump() const {
    return printMessage(_message, _position, "ERROR", "\033[1;31m");
}
