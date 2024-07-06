CREATE DATABASE car_rental;

USE car_rental;

CREATE TABLE cars (
    id INT PRIMARY KEY,
    make VARCHAR(50),
    model VARCHAR(50),
    year INT,
    price DOUBLE
);

CREATE TABLE customers (
    id INT PRIMARY KEY,
    name VARCHAR(100),
    license_number VARCHAR(50)
);

CREATE TABLE rentals (
    id INT PRIMARY KEY,
    car_id INT,
    customer_id INT,
    start_date DATE,
    end_date DATE,
    FOREIGN KEY (car_id) REFERENCES cars(id),
    FOREIGN KEY (customer_id) REFERENCES customers(id)
);
