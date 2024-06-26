/**
 * MIT License
 *
 * Copyright (c) 2024-Present Kevin Traini
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
#include "Config.h"
#include "test_tools.h"
#include <filesystem>

using namespace std;
using namespace filc::utils::config;

TEST(Config, init) {
    Config::init("project_name");
    ASSERT_STREQ("project_name", Config::get()->getName().c_str());
    ASSERT_STREQ("description", Config::get()->getDescription().c_str());
    ASSERT_STREQ("0.1.0", Config::get()->getVersion().c_str());
    ASSERT_STREQ("src/main.fil", Config::get()->getEntrypoint().c_str());
    Config::clear();
}

TEST(Config, save) {
    Config::init("project_name");
    Config::save(FIXTURES_PATH "/module.yml");
    ASSERT_TRUE(std::filesystem::exists(FIXTURES_PATH "/module.yml"));
    std::filesystem::remove(FIXTURES_PATH "/module.yml");
    Config::clear();
}

TEST(Config, name) {
    Config::init("project_name");
    Config::get()->setName("custom-name");
    ASSERT_STREQ("custom-name", Config::get()->getName().c_str());
    Config::clear();
}

TEST(Config, description) {
    Config::init("project_name");
    Config::get()->setDescription("custom-description");
    ASSERT_STREQ("custom-description", Config::get()->getDescription().c_str());
    Config::clear();
}

TEST(Config, version) {
    Config::init("project_name");
    Config::get()->setVersion("1.2.5-rc4");
    ASSERT_STREQ("1.2.5-rc4", Config::get()->getVersion().c_str());
    Config::clear();
}

TEST(Config, entrypoint) {
    Config::init("project_name");
    Config::get()->setEntrypoint("sources/index.fil");
    ASSERT_STREQ("sources/index.fil", Config::get()->getEntrypoint().c_str());
    Config::clear();
}

TEST(Config, namespaces) {
    Config::init("project_name");
    Config::get()->setNamespace("com.fil.main", "src");
    ASSERT_STREQ("", Config::get()->getNamespace("non-existing").c_str());
    ASSERT_STREQ("src", Config::get()->getNamespace("com.fil.main").c_str());
    Config::get()->setNamespace("com.fil.main", "src/com/fil/main");
    ASSERT_STREQ("src/com/fil/main", Config::get()->getNamespace("com.fil.main").c_str());
    const auto namespaces = Config::get()->getNamespaces();
    ASSERT_THAT(namespaces, SizeIs(2));
    ASSERT_THAT(
        namespaces,
        UnorderedElementsAre(make_pair("project_name", "src"), make_pair("com.fil.main", "src/com/fil/main"))
    );
    Config::clear();
}

TEST(Config, clear) {
    ASSERT_EQ(nullptr, Config::get());
    Config::init("project_name");
    ASSERT_NE(nullptr, Config::get());
    Config::clear();
    ASSERT_EQ(nullptr, Config::get());
}

#define ERROR_MESSAGE(filename, message) "\033[31mFailed to load " filename ": " message "\033[0m\n"

TEST(Config, load) {
    ASSERT_EQ(false, Config::load(FIXTURES_PATH "/utils/invalid_module_file.yml"));
    Config::clear();

    getOutput(
        []() {
            ASSERT_EQ(false, Config::load(FIXTURES_PATH "/utils/invalid_module_1.yml"));
        },
        [](const string &result) {
            ASSERT_STREQ(
                ERROR_MESSAGE(
                    FIXTURES_PATH "/utils/invalid_module_1.yml", "File format is invalid, it should be a yaml map"
                ),
                result.c_str()
            );
        }
    );

    Config::clear();

    getOutput(
        []() {
            ASSERT_EQ(false, Config::load(FIXTURES_PATH "/utils/invalid_module_2.yml"));
        },
        [](const string &result) {
            ASSERT_STREQ(
                ERROR_MESSAGE(FIXTURES_PATH "/utils/invalid_module_2.yml", "Missing name key"), result.c_str()
            );
        }
    );

    Config::clear();

    getOutput(
        []() {
            ASSERT_EQ(false, Config::load(FIXTURES_PATH "/utils/invalid_module_3.yml"));
        },
        [](const string &result) {
            ASSERT_STREQ(
                ERROR_MESSAGE(FIXTURES_PATH "/utils/invalid_module_3.yml", "Missing version key"), result.c_str()
            );
        }
    );

    Config::clear();

    getOutput(
        []() {
            ASSERT_EQ(false, Config::load(FIXTURES_PATH "/utils/invalid_module_4.yml"));
        },
        [](const string &result) {
            ASSERT_STREQ(
                ERROR_MESSAGE(FIXTURES_PATH "/utils/invalid_module_4.yml", "Missing entrypoint key"), result.c_str()
            );
        }
    );

    Config::clear();

    getOutput(
        []() {
            ASSERT_EQ(false, Config::load(FIXTURES_PATH "/utils/invalid_module_5.yml"));
        },
        [](const string &result) {
            ASSERT_STREQ(
                ERROR_MESSAGE(FIXTURES_PATH "/utils/invalid_module_5.yml", "Missing namespaces key"), result.c_str()
            );
        }
    );

    Config::clear();

    getOutput(
        []() {
            ASSERT_EQ(false, Config::load(FIXTURES_PATH "/utils/invalid_module_6.yml"));
        },
        [](const string &result) {
            ASSERT_STREQ(
                ERROR_MESSAGE(
                    FIXTURES_PATH "/utils/invalid_module_6.yml", "Namespaces value is invalid, it should be a yaml map"
                ),
                result.c_str()
            );
        }
    );

    Config::clear();

    ASSERT_EQ(true, Config::load(FIXTURES_PATH "/utils/module.yml"));
    const auto config = Config::get();
    ASSERT_STREQ("my_project", config->getName().c_str());
    ASSERT_STREQ("", config->getDescription().c_str());
    ASSERT_STREQ("1.0.0", config->getVersion().c_str());
    ASSERT_STREQ("src/main.fil", config->getEntrypoint().c_str());
    ASSERT_THAT(config->getNamespaces(), SizeIs(1));
    ASSERT_STREQ("src", config->getNamespace("com.fil.main").c_str());
    Config::clear();
}
