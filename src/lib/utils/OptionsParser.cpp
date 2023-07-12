/**
 * MIT License
 *
 * Copyright (c) 2023-Present Kevin Traini
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "OptionsParser.h"
#include "VERSION.h"

namespace filc::utils {
    OptionsParser::OptionsParser()
            : _options("filc", "Fil compiler\nVersion: " + FILC_VERSION_STRING + "\nLicense: " + FILC_LICENSE),
              _verbose(0),
              _debug(false), _out("a.out") {
        _options.custom_help("[options...]");
        _options.positional_help("<source files>");
        _options.add_options()("f,filenames", "Filenames", cxxopts::value<std::vector<std::string>>());
        _options.add_options()("h,help", "Display help message");
        _options.add_options()("v,version", "Display version of compiler");
        _options.add_options()("verbose", "Verbose level (0-5)",
                               cxxopts::value<uint>()->default_value("0")->implicit_value("1"));
        _options.add_options()("d,debug", "Compile with debug information");
        _options.add_options()("o,out", "Executable output filename",
                               cxxopts::value<std::string>()->default_value("a.out"));
        _options.parse_positional({"filenames"});
    }

    auto OptionsParser::parse(int argc, const char **argv) -> bool {
        cxxopts::ParseResult result;
        try {
            result = _options.parse(argc, argv);
        } catch (cxxopts::OptionException &e) {
            std::cout << "\033[1;31mSomething went wrong during parsing options\033[00m" << std::endl
                      << std::endl;
            help();

            return false;
        }

        if (result.count("help") != 0) {
            help();

            return true;
        }

        if (result.count("version") != 0) {
            version();

            return true;
        }

        if (result.count("filenames") == 0) {
            help();

            return false;
        }

        _filenames = result["filenames"].as<std::vector<std::string>>();
        for (const auto &filename: _filenames) {
            if (extension(filename) != "fil") {
                std::cout << "\033[1;31mError: \033[00m"
                          << "Invalid file extension" << std::endl;

                return false;
            }
        }
        auto verbose = result["verbose"].as<uint>();
        const auto MAX_VERBOSE = 5;
        _verbose = verbose > MAX_VERBOSE ? MAX_VERBOSE : verbose;
        _debug = result.count("debug") != 0;
        _out = result["out"].as<std::string>();

        return true;
    }

    auto OptionsParser::help() -> void {
        std::cout << _options.help() << std::endl;
    }

    auto OptionsParser::version() -> void {
        std::cout << "     _______ __    \n"
                     "    / ____(_) /____\n"
                     "   / /_  / / / ___/\n"
                     "  / __/ / / / /__  \n"
                     " /_/   /_/_/\\___/  \n"
                     "                   "
                  << std::endl;
        std::cout << "Filc version " << FILC_VERSION_STRING << " - " << FILC_VERSION << std::endl;
        std::cout << "License: " << FILC_LICENSE << std::endl;
    }

    auto OptionsParser::extension(const std::string &filename) -> std::string {
        auto dot = filename.find_last_of('.');
        if (dot == std::string::npos) {
            return "";
        }

        return filename.substr(dot + 1);
    }

    auto OptionsParser::getOptions() const -> const cxxopts::Options & {
        return _options;
    }

    auto OptionsParser::getFilenames() const -> const std::vector<std::string> & {
        return _filenames;
    }

    auto OptionsParser::getVerbose() const -> uint {
        return _verbose;
    }

    auto OptionsParser::isDebug() const -> bool {
        return _debug;
    }

    auto OptionsParser::getOut() const -> const std::string & {
        return _out;
    }
}
