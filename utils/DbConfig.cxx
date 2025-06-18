// config.cxx
#include "DbConfig.hxx"
#include <fstream>
#include <nlohmann/json.hpp>

std::string loadDatabaseConnectionString(const std::string& path) {
    std::ifstream in(path);
    if (!in.is_open()) {
        throw std::runtime_error("无法打开配置文件: " + path);
    }

    nlohmann::json j;
    in >> j;

    if (!j.contains("connection")) {
        throw std::runtime_error("配置文件缺少 connection 字段");
    }

    return j["connection"];
}
