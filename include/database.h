#pragma once
#ifndef DATABASE_H
#define DATABASE_H 

#include <string>
#include <memory>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

class Database {
public:
    Database(const std::string& host, const std::string& user, const std::string& password, const std::string& database);
    ~Database();

    void connect();
    void disconnect();
    void executeQuery(const std::string& query);
    std::unique_ptr<sql::ResultSet> executeSelectQuery(const std::string& query);

private:
    std::string host;
    std::string user;
    std::string password;
    std::string database;
    sql::mysql::MySQL_Driver* driver;
    std::unique_ptr<sql::Connection> connection;
};

#endif // DATABASE_H
