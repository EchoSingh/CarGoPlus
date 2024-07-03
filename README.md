# 🚗 Car Rental System

Welcome to the Car Rental System! This project is designed to manage car rentals, track customers, and handle rental transactions efficiently. Below you'll find information on the project structure, setup instructions, and usage details.

## 📑 Table of Contents
- [Project Structure](#project-structure)
- [Setup Instructions](#setup-instructions)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## 📂 Project Structure

The project is organized as follows:

```plaintext
CarRentalSystem/
├── .gitattributes
├── .gitignore
├── CarRentalSystem.sln
├── LICENSE.txt
├── README.md
└── CarRentalSystem/
    ├── car.cpp
    ├── car.h
    ├── customer.cpp
    ├── customer.h
    ├── database.cpp
    ├── database.h
    ├── main.cpp
    ├── rental.cpp
    ├── rental.h
└── MySQL tables/
    ├── cars.ibd
    ├── customers.ibd
    └── rentals.ibd
```
## ⚙️ Setup Instructions
1. Clone the repository:

```sh
git clone https://github.com/adi26062003/CarRentalSystem.git
cd CarRentalSystem
```
2. Set up the database:

   Ensure you have MySQL installed.
   Import the .ibd files into your MySQL server.

3. Build the project:
   Open CarRentalSystem.sln with Visual Studio.

4. Build the solution to compile the project.

## 🚀 Usage
Run the executable:
After building the project, run the generated executable file.
Interact with the system:

Follow the on-screen instructions to manage cars, customers, and rentals.

## 🤝 Contributing
I welcome contributions! Please follow these steps to contribute:

1. Fork the repository.
Create a new branch: git checkout -b feature/your-feature-name.
2. Make your changes and commit them: git commit -m 'Add some feature'.
Push to the branch: git push origin feature/your-feature-name.
3. Open a pull request.

## 📄 License
This project is licensed under the MIT License - see the [LICENSE](LICENSE.txt) file for details.
