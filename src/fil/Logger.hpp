/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#ifndef FILC_LOGGER_HPP
#define FILC_LOGGER_HPP

#include <string>
#include <iostream>
#include <deque>

class Logger {
private:
    static Logger *_instance;
    std::deque<std::string> _logs;

    Logger() = default;

public:
    static Logger *getInstance() {
        if (_instance == nullptr) {
            _instance = new Logger();
        }
        return _instance;
    }

    void log(int line, const std::string &filename, const std::string &msg) {
        _logs.push_back(filename + ":" + std::to_string(line) + " -> " + msg);
    }

    bool hasError() {
        return !_logs.empty();
    }

    void printLogs() {
        for (auto &log: _logs) {
            std::cout << log << std::endl;
        }
    }
};


#endif //FILC_LOGGER_HPP
