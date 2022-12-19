/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#ifndef FILC_ERRORSREGISTER_H
#define FILC_ERRORSREGISTER_H


class ErrorsRegister {
private:
    static ErrorsRegister *_instance;

    ErrorsRegister() = default;

public:
    static void init();

    static void clean();

    static bool containsError();

private:
    bool _containsError = false;
};


#endif //FILC_ERRORSREGISTER_H
