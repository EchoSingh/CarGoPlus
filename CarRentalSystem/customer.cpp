#include "customer.h"

Customer::Customer(int id, const std::string& name, const std::string& licenseNumber)
    : id(id), name(name), licenseNumber(licenseNumber) {}

int Customer::getId() const { return id; }
std::string Customer::getName() const { return name; }
std::string Customer::getLicenseNumber() const { return licenseNumber; }