#pragma once
#ifndef RENTAL_H
#define RENTAL_H

#include <string>

class Rental {
public:
    Rental(int id, int carId, int customerId, const std::string& startDate, const std::string& endDate);
    int getId() const;
    int getCarId() const;
    int getCustomerId() const;
    std::string getStartDate() const;
    std::string getEndDate() const;

private:
    int id;
    int carId;
    int customerId;
    std::string startDate;
    std::string endDate;
};

#endif // RENTAL_H
