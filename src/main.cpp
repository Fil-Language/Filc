/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *        Under MIT
 * -----------------------
 */
#include "cxxopts.hpp"
#include "VERSION.h"
#include "FilCompiler.h"
#include "utils.h"
#include <string>

using namespace std;

int main(int argc, char **argv) {
    cxxopts::Options options("filc", "Fil compiler \nVersion: " + FILC_VERSION_STRING + "\nLicense: " + FILC_LICENSE);
    options.custom_help("[options...]");
    options.positional_help("<main source filename>");
    options.add_options("General")
            ("f,filename", "Main filename", cxxopts::value<string>())
            ("h,help", "Display help message")
            ("v,version", "Display version of compiler")
            ("verbose", "Verbose level (0-5)", cxxopts::value<int>()->default_value("0")->implicit_value("1"));
    options.add_options("Compile flags")
            ("d,decompile", "Decompile AST")
            ("a,ast", "Print AST structure")
            ("debug", "Compile with debug information")
            ("o,out", "Executable output filename", cxxopts::value<string>()->default_value("a.out"));
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
        cout << "     _______ __    \n"
                "    / ____(_) /____\n"
                "   / /_  / / / ___/\n"
                "  / __/ / / / /__  \n"
                " /_/   /_/_/\\___/  \n"
                "                   " << endl;
        cout << "Filc version " << FILC_VERSION_STRING << " - " << FILC_VERSION << endl;
        cout << "License: " << FILC_LICENSE << endl;
        return 0;
    }

    if (!result.count("filename")) {
        cout << options.help() << endl;
        return 1;
    }
    string filename = result["filename"].as<string>();
    if (extension(filename) != "fil") {
        cout << "\033[1;31mError: \033[00m" << "Invalid file extension" << endl;
        return 1;
    }

    // Flags
    FLAGS flag = NONE;
    if (result.count("decompile")) {
        flag = DECOMPILE;
    } else if (result.count("ast")) {
        flag = AST;
    }

    bool debug = false;
    if (result.count("debug")) {
        debug = true;
    }
    string out = result["out"].as<string>();

    auto compiler = FilCompiler(filename);

    return compiler.compile(flag, debug, out);
}
