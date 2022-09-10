#include "Logger.hpp"

bool Logger::isInitialized = false;

std::ofstream Logger::file("");

std::vector<std::ostream *> Logger::additionalStreams = std::vector<std::ostream *>();

int Logger::nbLog = 0;

pthread_mutex_t Logger::mutex;

LoggerOption Logger::verbose = FILE_AND_CONSOLE;

std::vector <LoggerType> Logger::showTypes = {INFO, SUCCESS, ERROR, WARNING, DEBUG};


std::string Logger::getColor(LoggerColor color) {
    switch (color) {
        case DEFAULT:
            return "\x1B[00m";

        case BLACK:
            return "\x1B[30m";
        case RED:
            return "\x1B[31m";
        case GREEN:
            return "\x1B[32m";
        case YELLOW:
            return "\x1B[33m";
        case BLUE:
            return "\x1B[34m";
        case PURPLE:
            return "\x1B[35m";
        case CYAN:
            return "\x1B[36m";
        case WHITE:
            return "\x1B[37m";

        case BACKGROUND_BLACK:
            return "\x1B[40m";
        case BACKGROUND_RED:
            return "\x1B[41m";
        case BACKGROUND_GREEN:
            return "\x1B[42m";
        case BACKGROUND_YELLOW:
            return "\x1B[43m";
        case BACKGROUND_BLUE:
            return "\x1B[44m";
        case BACKGROUND_PURPLE:
            return "\x1B[45m";
        case BACKGROUND_CYAN:
            return "\x1B[46m";
        case BACKGROUND_WHITE:
            return "\x1B[47m";

        default:
            return "\x1B[00m";
    }
}

std::string Logger::getTypeColor(LoggerType type) {
    switch (type) {
        case INFO:
            return getColor(BLUE);
        case SUCCESS:
            return getColor(GREEN);
        case ERROR:
            return getColor(RED);
        case WARNING:
            return getColor(YELLOW);
        case DEBUG:
            return getColor(PURPLE);

        default:
            return getColor(DEFAULT);
    }
}

std::string Logger::getTypeName(LoggerType type) {
    switch (type) {
        case INFO:
            return "INFO";
        case SUCCESS:
            return "SUCCESS";
        case ERROR:
            return "ERROR";
        case WARNING:
            return "WARNING";
        case DEBUG:
            return "DEBUG";

        default:
            return "";
    }
}

void Logger::init(LoggerOption verboseP, const std::vector <LoggerType> &showTypesP) {
    if (!isInitialized) {
        verbose = verboseP;
        showTypes = showTypesP;

        bool dirCreated = false;

        if (!file.is_open()) {
#ifdef _WIN32
            if (mkdir(LOG_PATH.c_str()) == 0)
#else
            if (mkdir(LOG_PATH.c_str(), S_IRWXU) == 0)
#endif
                dirCreated = true;

            std::string fileName = (LOG_PATH + "/" + PROJECT_NAME + "_log_") + getDate() + ".log";
            file.open(fileName, std::ios::out);
        }

        nbLog = 0;

        if (pthread_mutex_init(&mutex, nullptr) != 0)
            ERROR_LOG(CONSOLE_ONLY, "Error mutex : %d\n", errno);

        INFO_LOG(FILE_ONLY, "Log start\n");
        isInitialized = true;
        if (dirCreated)
            WARNING_LOG(FILE_AND_CONSOLE, "Log directory created\n");
    } else
        WARNING_LOG(FILE_AND_CONSOLE, "Log already init\n");
}

void Logger::exit() {
    if (isInitialized) {
        INFO_LOG(FILE_ONLY, "End log\n");
        isInitialized = false;

        if (file.is_open())
            file.close();

        pthread_mutex_destroy(&mutex);
    } else
        ERROR_LOG(CONSOLE_ONLY, "Please init before exit\n");
}

void Logger::addOutputStream(std::ostream *os) {
    additionalStreams.push_back(os);
}

void Logger::genericLog(const std::string &function, const std::string &message, LoggerType type, LoggerOption option) {
    std::string t = message;

    if (t[t.length() - 1] != '\n') {
        t += "\n";
    }

    if (option != FILE_ONLY && verbose != FILE_ONLY &&
        std::find(showTypes.begin(), showTypes.end(), type) != showTypes.end())
        std::cout << getTypeColor(type) << constructMessage(t, function, getTypeName(type), CONSOLE_FORMAT)
                  << getColor(DEFAULT);

    if (option != CONSOLE_ONLY && verbose != CONSOLE_ONLY) {
        pthread_mutex_lock(&mutex);
        writeToFile(constructMessage(t, function, getTypeName(type), FILE_FORMAT));
        pthread_mutex_unlock(&mutex);
    }

    if (option != CONSOLE_ONLY && option != FILE_ONLY && verbose == FILE_AND_CONSOLE) {
        for (const auto &os: additionalStreams) {
            std::string m = constructMessage(t, function, getTypeName(type), ADDITIONAL_FORMAT);
            os->write(m.c_str(), (long) m.length());
            os->flush();
        }
    }

    nbLog++;
}

std::string Logger::constructMessage(const std::string &message, const std::string &trace, const std::string &logType,
                                     const std::string &format) {
    std::string res;

    int i = 0;
    while (i < format.length()) {
        char c = format[i];
        if (c == '%') {
            i++;
            c = format[i];

            struct timespec now{};
            clock_gettime(CLOCK_REALTIME, &now);
            struct tm *t = localtime(&now.tv_sec);
            switch (c) {
                case 'Y':
                    res += std::to_string(t->tm_year + 1900);
                    break;
                case 'M':
                    res += std::to_string(t->tm_mon + 1);
                    break;
                case 'D':
                    res += std::to_string(t->tm_mday);
                    break;
                case 'H':
                    res += std::to_string(t->tm_hour);
                    break;
                case 'm':
                    res += std::to_string(t->tm_min);
                    break;
                case 'S':
                    res += std::to_string(t->tm_sec);
                    break;
                case 'N':
                    res += std::to_string(now.tv_nsec);
                    break;
                case 'd':
                    res += getDate();
                    break;
                case 'h':
                    res += getHour();
                    break;
                case 'T':
                    res += trace;
                    break;
                case 'C':
                    res += message;
                    break;
                case 'n':
                    res += std::to_string(nbLog);
                    break;
                case 't':
                    res += logType;
                    break;
                default:
                    break;
            }
        } else {
            res += c;
        }

        i++;
    }

    return res;
}

void Logger::writeToFile(const std::string &message) {
    if (file.is_open()) {
        file << message;
        file.flush();
    } else if (!isInitialized)
        ERROR_LOG(CONSOLE_ONLY, "Please init logger\n");
}

std::string Logger::getHour() {
    struct timespec now{};
    clock_gettime(CLOCK_REALTIME, &now);
    struct tm *t = localtime(&now.tv_sec);

    return std::to_string(t->tm_hour) + ":"
           + std::to_string(t->tm_min) + ":"
           + std::to_string(t->tm_sec) + ":"
           + std::to_string(now.tv_nsec);
}

std::string Logger::getDate() {
    time_t now;
    time(&now);
    struct tm *t = localtime(&now);

    return std::to_string(t->tm_year + 1900) + "-"
           + std::to_string(t->tm_mon + 1) + "-"
           + std::to_string(t->tm_mday) + "@"
           + std::to_string(t->tm_hour) + "-"
           + std::to_string(t->tm_min) + "-"
           + std::to_string(t->tm_sec);
}