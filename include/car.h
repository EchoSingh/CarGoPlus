#pragma once
#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
public:
    Car(int id, const std::string& make, const std::string& model, int year, double price);
    int getId() const;
    std::string getMake() const;
    std::string getModel() const;
    int getYear() const;
    double getPrice() const;

private:
    int id;
    std::string make;
    std::string model;
    int year;
    double price;
};

#endif // CAR_H
