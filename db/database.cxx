// database.cxx
#include "database.hxx"
#include <stdexcept>

Database::Database(const std::string& connStr) {
    try {
        conn = std::make_unique<pqxx::connection>(connStr);
        if (!conn->is_open()) {
            throw std::runtime_error("无法打开数据库连接");
        }
    } catch (const std::exception& e) {
        throw std::runtime_error(std::string("数据库连接失败: ") + e.what());
    }
}

Database::~Database() = default;

pqxx::connection& Database::getConnection() {
    return *conn;
}
 