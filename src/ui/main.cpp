#include <wx/wx.h>
#include "database.h"
#include "car.h"
#include "customer.h"
#include "rental.h"
#include <iostream>
#include <sstream>
#include <string>

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
    MyFrame(const wxString& title);

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnAddCar(wxCommandEvent& event);
    void OnAddCustomer(wxCommandEvent& event);
    void OnRentCar(wxCommandEvent& event);

private:
    wxDECLARE_EVENT_TABLE();
    Database db;
};

enum {
    ID_AddCar = 1,
    ID_AddCustomer,
    ID_RentCar
};

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(wxID_EXIT, MyFrame::OnExit)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
EVT_MENU(ID_AddCar, MyFrame::OnAddCar)
EVT_MENU(ID_AddCustomer, MyFrame::OnAddCustomer)
EVT_MENU(ID_RentCar, MyFrame::OnRentCar)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyFrame* frame = new MyFrame("Car Rental Management System");
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title), db("tcp://127.0.0.1:3306", "root", "P@$$W0rd", "car_rental") {
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_AddCar, "&Add Car...\tCtrl-A", "Add a new car");
    menuFile->Append(ID_AddCustomer, "&Add Customer...\tCtrl-C", "Add a new customer");
    menuFile->Append(ID_RentCar, "&Rent Car...\tCtrl-R", "Rent a car");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);
    CreateStatusBar();
    SetStatusText("Welcome to Car Rental Management System!");

    try {
        db.connect();
        SetStatusText("Database connected successfully.");
    }
    catch (sql::SQLException& e) {
        wxMessageBox("Error connecting to database: " + wxString(e.what()), "Database Error", wxOK | wxICON_ERROR);
    }
}

void MyFrame::OnExit(wxCommandEvent& event) {
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("This is a Car Rental Management System using wxWidgets", "About Car Rental", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnAddCar(wxCommandEvent& event) {
    wxTextEntryDialog dialog(this, "Enter Car Details (id, make, model, year, price)", "Add Car", "", wxTextEntryDialogStyle, wxDefaultPosition);
    if (dialog.ShowModal() == wxID_OK) {
        wxString carDetails = dialog.GetValue();
        int id, year;
        double price;
        std::string make, model;
        std::istringstream iss(std::string(carDetails.mb_str()));
        iss >> id >> make >> model >> year >> price;
        Car car(id, make, model, year, price);
        db.executeQuery("INSERT INTO cars (id, make, model, year, price) VALUES (" +
            std::to_string(car.getId()) + ", '" + car.getMake() + "', '" + car.getModel() + "', " +
            std::to_string(car.getYear()) + ", " + std::to_string(car.getPrice()) + ")");
        wxMessageBox("Car added successfully.", "Success", wxOK | wxICON_INFORMATION);
    }
}

void MyFrame::OnAddCustomer(wxCommandEvent& event) {
    wxTextEntryDialog dialog(this, "Enter Customer Details (id, name, license number)", "Add Customer", "", wxTextEntryDialogStyle, wxDefaultPosition);
    if (dialog.ShowModal() == wxID_OK) {
        wxString customerDetails = dialog.GetValue();
        int id;
        std::string name, licenseNumber;
        std::istringstream iss(std::string(customerDetails.mb_str()));
        iss >> id >> name >> licenseNumber;
        Customer customer(id, name, licenseNumber);
        db.executeQuery("INSERT INTO customers (id, name, license_number) VALUES (" +
            std::to_string(customer.getId()) + ", '" + customer.getName() + "', '" + customer.getLicenseNumber() + "')");
        wxMessageBox("Customer added successfully.", "Success", wxOK | wxICON_INFORMATION);
    }
}

void MyFrame::OnRentCar(wxCommandEvent& event) {
    wxTextEntryDialog dialog(this, "Enter Rental Details (rental id, car id, customer id, start date, end date)", "Rent Car", "", wxTextEntryDialogStyle, wxDefaultPosition);
    if (dialog.ShowModal() == wxID_OK) {
        wxString rentalDetails = dialog.GetValue();
        int rentalId, carId, customerId;
        std::string startDate, endDate;
        std::istringstream iss(std::string(rentalDetails.mb_str()));
        iss >> rentalId >> carId >> customerId >> startDate >> endDate;
        Rental rental(rentalId, carId, customerId, startDate, endDate);
        db.executeQuery("INSERT INTO rentals (id, car_id, customer_id, start_date, end_date) VALUES (" +
            std::to_string(rental.getId()) + ", " + std::to_string(rental.getCarId()) + ", " +
            std::to_string(rental.getCustomerId()) + ", '" + rental.getStartDate() + "', '" + rental.getEndDate() + "')");
        wxMessageBox("Car rented successfully.", "Success", wxOK | wxICON_INFORMATION);
    }
}
