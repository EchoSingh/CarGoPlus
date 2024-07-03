#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
public:
    Customer(int id, const std::string& name, const std::string& licenseNumber);
    int getId() const;
    std::string getName() const;
    std::string getLicenseNumber() const;

private:
    int id;
    std::string name;
    std::string licenseNumber;
};

#endif // CUSTOMER_H