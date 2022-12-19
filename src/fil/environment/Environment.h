/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#ifndef FILC_ENVIRONMENT_H
#define FILC_ENVIRONMENT_H


class Environment {
public:
    explicit Environment(Environment *parent = nullptr);

    ~Environment();

    static Environment *getGlobalEnvironment();

private:
    Environment *_parent;
};


#endif //FILC_ENVIRONMENT_H
