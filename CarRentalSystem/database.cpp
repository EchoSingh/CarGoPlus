#include "database.h"
#include <stdexcept>  

Database::Database(const std::string& host, const std::string& user, const std::string& password, const std::string& database)
    : host(host), user(user), password(password), database(database), driver(nullptr), connection(nullptr) {
    driver = sql::mysql::get_mysql_driver_instance();
}

Database::~Database() {
    disconnect();
}

void Database::connect() {
    if (!driver) {
        throw std::runtime_error("Database driver not initialized.");
    }
    connection.reset(driver->connect(host, user, password));  
    if (!connection) {
        throw std::runtime_error("Failed to connect to the database.");
    }
    connection->setSchema(database);
}

void Database::disconnect() {
    if (connection) {
        connection->close();
        connection.reset();
    }
}

void Database::executeQuery(const std::string& query) {
    if (!connection) {
        throw std::runtime_error("Database connection is not established.");
    }
    std::unique_ptr<sql::Statement> stmt(connection->createStatement());
    stmt->execute(query);
}

std::unique_ptr<sql::ResultSet> Database::executeSelectQuery(const std::string& query) {
    if (!connection) {
        throw std::runtime_error("Database connection is not established.");
    }
    std::unique_ptr<sql::Statement> stmt(connection->createStatement());
    return std::unique_ptr<sql::ResultSet>(stmt->executeQuery(query));
}