/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#ifndef FILC_ERRORSREGISTER_H
#define FILC_ERRORSREGISTER_H

#include <vector>
#include <ostream>
#include "Message.h"

class ErrorsRegister {
private:
    static ErrorsRegister *_instance;

    ErrorsRegister();

public:
    static void init();

    static void clean();

    static bool containsError();

    static bool containsWarning();

    static void addWarning(const std::string &message, Position *position);

    static void addError(const std::string &message, Position *position);

    static void dump(std::ostream &out);

private:
    bool _containsError = false;
    bool _containsWarning = false;
    std::vector<Message *> _messages;
};


#endif //FILC_ERRORSREGISTER_H
