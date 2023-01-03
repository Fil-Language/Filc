/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#ifndef FILC_MESSAGE_H
#define FILC_MESSAGE_H

#include <string>
#include "utils.h"

class Message {
protected:
    Message(const std::string &message, Position *position);

public:
    ~Message() = default;

    virtual std::string dump() const = 0;

protected:
    std::string _message;
    Position *_position;
};

class Warning : public Message {
public:
    Warning(const std::string &message, Position *position);

    std::string dump() const override;
};

class Error : public Message {
public:
    Error(const std::string &message, Position *position);

    std::string dump() const override;
};


#endif //FILC_MESSAGE_H
