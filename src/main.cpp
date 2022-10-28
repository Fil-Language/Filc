/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#include "cxxopts.hpp"
#include "VERSION.h"
#include "FilCompiler.h"
#include <string>

using namespace std;

int main(int argc, char **argv) {
    cxxopts::Options options("filc", "Fil compiler \nVersion: " + FILC_VERSION_STRING);
    options.custom_help("[options...]");
    options.positional_help("<main source filename>");
    options.add_options("General")
            ("f,filename", "Main filename", cxxopts::value<string>())
            ("h,help", "Display help message")
            ("v,version", "Display version of compiler")
            ("verbose", "Verbose level (0-5)", cxxopts::value<int>()->default_value("0")->implicit_value("1"));
    options.add_options("Compile flags")
            ("a,ast", "Print AST structure in file ast.out");
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
        cout << "Filc version " << FILC_VERSION_STRING << " - " << FILC_VERSION << endl;
        return 0;
    }

    if (!result.count("filename")) {
        cout << options.help() << endl;
        return 1;
    }

    // Flags
    int flag = -1;
    if (result.count("ast")) {
        flag = FLAGS::AST;
    }

    auto compiler = FilCompiler(result["filename"].as<string>());

    return compiler.compile(flag);
}
