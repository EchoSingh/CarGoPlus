#include "rental.h"

Rental::Rental(int id, int carId, int customerId, const std::string& startDate, const std::string& endDate)
    : id(id), carId(carId), customerId(customerId), startDate(startDate), endDate(endDate) {}

int Rental::getId() const { return id; }
int Rental::getCarId() const { return carId; }
int Rental::getCustomerId() const { return customerId; }
std::string Rental::getStartDate() const { return startDate; }
std::string Rental::getEndDate() const { return endDate; }
