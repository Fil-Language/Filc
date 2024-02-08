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

#include <fstream>
#include <iostream>
#include <map>
#include <yaml-cpp/yaml.h>

using namespace std;
using namespace filc::utils::config;

Config *Config::_instance;

Config::Config()
    : _root(new SchemaMap) {}

auto Config::init(const string &name) -> void {
    if (_instance != nullptr) {
        return;
    }
    _instance = new Config;

    _instance->setName(name);
    _instance->setDescription("description");
    _instance->setVersion("0.1.0");
    _instance->setEntrypoint("src/main.fil");
    _instance->setNamespace(name, "src");
}

auto Config::get() -> Config * {
    return _instance;
}

auto Config::clear() -> void {
    _instance = nullptr;
}

auto Config::save(const string &filename) -> void {
    YAML::Node result_yaml;
    const auto config = get();

    result_yaml["name"]        = config->getName();
    result_yaml["description"] = config->getDescription();
    result_yaml["version"]     = config->getVersion();
    result_yaml["entrypoint"]  = config->getEntrypoint();
    for (const auto &item: config->getNamespaces()) {
        result_yaml["namespaces"][item.first] = item.second;
    }

    ofstream fout(filename);
    if (!fout.good() || !fout.is_open()) {
        return;
    }
    fout << result_yaml;
    fout.flush();
    fout.close();
}

#define ERROR_MESSAGE(filename, message) "\033[31mFailed to load " << filename << ": " << message << "\033[0m\n"

auto Config::load(const string &filename) -> bool {
    if (_instance != nullptr) {
        return true;
    }
    _instance         = new Config;
    const auto config = _instance;

    YAML::Node file_config;
    try {
        file_config = YAML::LoadFile(filename);
    } catch (exception &e) {
        cout << ERROR_MESSAGE(filename, e.what());
    }

    if (!file_config.IsMap()) {
        cout << ERROR_MESSAGE(filename, "File format is invalid, it should be a yaml map");
        return false;
    }

    if (!file_config["name"].IsDefined()) {
        cout << ERROR_MESSAGE(filename, "Missing name key");
        return false;
    }
    config->setName(file_config["name"].as<string>());

    if (file_config["description"].IsDefined()) {
        config->setDescription(file_config["description"].as<string>());
    } else {
        config->setDescription("");
    }

    if (!file_config["version"].IsDefined()) {
        cout << ERROR_MESSAGE(filename, "Missing version key");
        return false;
    }
    config->setVersion(file_config["version"].as<string>());

    if (!file_config["entrypoint"].IsDefined()) {
        cout << ERROR_MESSAGE(filename, "Missing entrypoint key");
        return false;
    }
    config->setEntrypoint(file_config["entrypoint"].as<string>());

    if (!file_config["namespaces"].IsDefined()) {
        cout << ERROR_MESSAGE(filename, "Missing namespaces key");
        return false;
    }
    if (!file_config["namespaces"].IsMap()) {
        cout << ERROR_MESSAGE(filename, "Namespaces value is invalid, it should be a yaml map");
        return false;
    }
    for (auto entry = file_config["namespaces"].begin(); entry != file_config["namespaces"].end(); entry++) {
        config->setNamespace(entry->first.as<string>(), entry->second.as<string>());
    }

    return true;
}

auto Config::getName() const -> const string & {
    return _root->get("name")->as<SchemaString>()->get();
}

auto Config::setName(const string &name) -> void {
    if (_root->has("name")) {
        _root->get("name")->as<SchemaString>()->set(name);
    } else {
        _root->set("name", new SchemaString(name));
    }
}

auto Config::getDescription() const -> const string & {
    return _root->get("description")->as<SchemaString>()->get();
}

auto Config::setDescription(const string &description) -> void {
    if (_root->has("description")) {
        _root->get("description")->as<SchemaString>()->set(description);
    } else {
        _root->set("description", new SchemaString(description));
    }
}

auto Config::getVersion() const -> const string & {
    return _root->get("version")->as<SchemaString>()->get();
}

auto Config::setVersion(const string &version) -> void {
    if (_root->has("version")) {
        _root->get("version")->as<SchemaString>()->set(version);
    } else {
        _root->set("version", new SchemaString(version));
    }
}

auto Config::getEntrypoint() const -> const string & {
    return _root->get("entrypoint")->as<SchemaString>()->get();
}

auto Config::setEntrypoint(const string &entrypoint) -> void {
    if (_root->has("entrypoint")) {
        _root->get("entrypoint")->as<SchemaString>()->set(entrypoint);
    } else {
        _root->set("entrypoint", new SchemaString(entrypoint));
    }
}

auto Config::getNamespaces() const -> map<string, string> {
    const auto schema = _root->get("namespaces")->as<SchemaMap>();
    map<string, string> result;

    for (const auto &key: schema->keys()) {
        result[key] = schema->get(key)->as<SchemaString>()->get();
    }

    return result;
}

auto Config::getNamespace(const string &name) const -> string {
    const auto schema = _root->get("namespaces")->as<SchemaMap>();
    if (schema->has(name)) {
        return schema->get(name)->as<SchemaString>()->get();
    }

    return "";
}

auto Config::setNamespace(const string &name, const string &path) -> void {
    if (!_root->has("namespaces")) {
        _root->set("namespaces", new SchemaMap);
    }
    const auto schema = _root->get("namespaces")->as<SchemaMap>();
    if (schema->has(name)) {
        schema->get(name)->as<SchemaString>()->set(path);
    } else {
        schema->set(name, new SchemaString(path));
    }
}
