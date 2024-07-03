#include <iostream>
#include "car.h"
#include "customer.h"
#include "rental.h"
#include "database.h"


void showMenu() {
    std::cout << "1. Add Car\n";
    std::cout << "2. Add Customer\n";
    std::cout << "3. Rent Car\n";
    std::cout << "4. Return Car\n";
    std::cout << "5. Exit\n";
}

int main() {
    Database db("tcp://127.0.0.1:3306", "root", "P@$$W0rd", "car_rental");

    try {
        db.connect();
        std::cout << "Database connected successfully.\n";
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error connecting to database: " << e.what() << std::endl;
        return 1;
    }

    int choice;
    do {
        showMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int id, year;
            double price;
            std::string make, model;
            std::cout << "Enter car ID, make, model, year, and price: ";
            std::cin >> id >> make >> model >> year >> price;
            Car car(id, make, model, year, price);
            db.executeQuery("INSERT INTO cars (id, make, model, year, price) VALUES (" +
                std::to_string(car.getId()) + ", '" + car.getMake() + "', '" + car.getModel() + "', " +
                std::to_string(car.getYear()) + ", " + std::to_string(car.getPrice()) + ")");
            std::cout << "Car added successfully.\n";
            break;
        }
        case 2: {
            int id;
            std::string name, licenseNumber;
            std::cout << "Enter customer ID, name, and license number: ";
            std::cin >> id >> name >> licenseNumber;
            Customer customer(id, name, licenseNumber);
            db.executeQuery("INSERT INTO customers (id, name, license_number) VALUES (" +
                std::to_string(customer.getId()) + ", '" + customer.getName() + "', '" + customer.getLicenseNumber() + "')");
            std::cout << "Customer added successfully.\n";
            break;
        }
        case 3: {
            int rentalId, carId, customerId;
            std::string startDate, endDate;
            std::cout << "Enter rental ID, car ID, customer ID, start date, and end date: ";
            std::cin >> rentalId >> carId >> customerId >> startDate >> endDate;
            Rental rental(rentalId, carId, customerId, startDate, endDate);
            db.executeQuery("INSERT INTO rentals (id, car_id, customer_id, start_date, end_date) VALUES (" +
                std::to_string(rental.getId()) + ", " + std::to_string(rental.getCarId()) + ", " +
                std::to_string(rental.getCustomerId()) + ", '" + rental.getStartDate() + "', '" + rental.getEndDate() + "')");
            std::cout << "Car rented successfully.\n";
            break;
        }
        case 4:
            std::cout << "Returning car...\n";
            break;
        case 5:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    db.disconnect();
    return 0;
}
