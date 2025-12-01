#include "Passenger.h"
#include <iostream>
using namespace std;

//implementation for passenger.h file

Passenger::Passenger(const string& name, const string& id) // O(1)
    : name(name), id(id), seatNumber(""), checkedIn(false), boarded(false) {}

string Passenger::getName() const { // O(1)
    return name;
}

string Passenger::getId() const { // O(1)
    return id;
}

string Passenger::getSeatNumber() const { // O(1)
    return seatNumber;
}

bool Passenger::isCheckedIn() const { // O(1)
    return checkedIn;
}

bool Passenger::isBoarded() const { // O(1)
    return boarded;
}

void Passenger::setSeatNumber(const string& seatNumber) { // O(1)
    this->seatNumber = seatNumber;
}

void Passenger::setCheckedIn(bool status) { // O(1)
    checkedIn = status;
}

void Passenger::setBoarded(bool status) { // O(1)
    boarded = status;
}

void Passenger::displayInfo() const { // O(1)
    cout << "Passenger: " << name << ", ID: " << id << ", Seat: " << (seatNumber.empty() ? "Not Assigned" : seatNumber)
        << ", Check-in status: " << (checkedIn ? "Checked-in" : "Not checked-in")
        << ", Boarding status: " << (boarded ? "Boarded" : "Not boarded") << endl;
}