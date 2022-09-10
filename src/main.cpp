/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "utils/cxxopts.hpp"
#include "utils/logger/Logger.hpp"
#include "VERSION.h"
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    cxxopts::Options options("filc", "Fil compiler \nVersion: " FILC_VERSION_STRING);
    options.custom_help("[options...]");
    options.positional_help("<main source filename>");
    options.add_options()
            ("f,filename", "Main filename", cxxopts::value<string>())
            ("h,help", "Display help message")
            ("v,version", "Display version of compiler")
            ("verbose", "Verbose level (0-5)", cxxopts::value<int>()->default_value("0")->implicit_value("1"));
    options.parse_positional({"filename"});

    cxxopts::ParseResult result;
    try {
        result = options.parse(argc, argv);
    } catch (cxxopts::OptionException &e) {
        cout << "\033[1;31mSomething went wrong during parsing options\033[00m" << endl << endl;
        cout << options.help() << endl;
        return 1;
    }

    if (result.count("help")) {
        cout << options.help() << endl;
        return 0;
    }

    if (result.count("version")) {
        cout << "Filc version " FILC_VERSION_STRING << " - " << FILC_VERSION << endl;
        return 0;
    }

    if (!result.count("filename")) {
        cout << options.help() << endl;
        return 1;
    }

    auto types = vector{DEBUG, SUCCESS, INFO, WARNING, ERROR};
    vector<LoggerType> logTypes;
    for (int i = 0; i < result["verbose"].as<int>(); ++i) {
        logTypes.push_back(types[i]);
    }
    Logger::init(CONSOLE_ONLY, logTypes);

    cout << "filename:" << result["filename"].as<string>() << endl;

    // TODO : Compile $filename

    return 0;
}