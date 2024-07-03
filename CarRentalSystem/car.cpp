#include "car.h"

Car::Car(int id, const std::string& make, const std::string& model, int year, double price)
    : id(id), make(make), model(model), year(year), price(price) {}

int Car::getId() const { return id; }
std::string Car::getMake() const { return make; }
std::string Car::getModel() const { return model; }
int Car::getYear() const { return year; }
double Car::getPrice() const { return price; }