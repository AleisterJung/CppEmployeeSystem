// database.hxx
#include <pqxx/pqxx>
#include <memory>

class Database {
public:
    explicit Database(const std::string& connStr);
    ~Database();

    pqxx::connection& getConnection();

private:
    std::unique_ptr<pqxx::connection> conn;
};
