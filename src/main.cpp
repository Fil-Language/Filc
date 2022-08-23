#include "utils/cxxopts.hpp"
#include <string>

#define VERSION "0.0.1"

int main(int argc, char **argv) {
    cxxopts::Options options("filc", "Fil language compiler");
    options.custom_help("[options...]");
    options.positional_help("<main source filename>");
    options.add_options()
            ("f,filename", "Main filename", cxxopts::value<std::string>())
            ("h,help", "Display help message")
            ("v,version", "Display version of compiler")
            ("verbose", "Verbose level (0-5)", cxxopts::value<int>()->default_value("0"));
    options.parse_positional({"filename"});

    cxxopts::ParseResult result;
    try {
        result = options.parse(argc, argv);
    } catch (cxxopts::OptionException &e) {
        std::cout << "\033[1;31mSomething went wrong during parsing options\033[00m" << std::endl << std::endl;
        std::cout << options.help() << std::endl;
        return 1;
    }

    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        return 0;
    }

    if (result.count("version")) {
        std::cout << "Filc version " VERSION << std::endl;
        return 0;
    }

    if (!result.count("filename")) {
        std::cout << "\033[1;31mNo filename specified\033[00m" << std::endl << std::endl;
        std::cout << options.help() << std::endl;
        return 1;
    }

    std::cout << "filename:" << result["filename"].as<std::string>() << std::endl;
    std::cout << "verbose level:" << result["verbose"].as<int>() << std::endl;

    // TODO : Compile $filename

    return 0;
}