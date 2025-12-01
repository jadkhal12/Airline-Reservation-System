#include "BoardingManager.h"
#include <iostream>
using namespace std;

// implementation for the boardingmanager.h file

BoardingManager::BoardingManager(BookingSystem& bookingSystem) : bookingSystem(bookingSystem) {} // O(1)

void BoardingManager::startBoarding(const string& flightNumber) {   // O(n)
    auto bookedPassengers = bookingSystem.getBookedPassengers(flightNumber); // O(1)

    if (bookedPassengers.empty()) {
        cout << "No passengers booked for flight " << flightNumber << "." << endl;
        return;
    }

    cout << "Starting boarding for flight " << flightNumber << "." << endl;
    cout << "The following passengers are ready for boarding:" << endl;

    int readyCount = 0;
    for (const auto& passenger : bookedPassengers) {    // O(n)
        if (passenger->isCheckedIn() && !passenger->isBoarded()) {
            cout << "  - " << passenger->getName() << " (Seat: " << passenger->getSeatNumber() << ")" << endl;
            readyCount++;
        }
    }

    if (readyCount == 0) {
        cout << "No passengers are ready for boarding." << endl;
    }
}

void BoardingManager::boardPassenger(const string& flightNumber, const string& passengerId) { // O(n)
    auto bookedPassengers = bookingSystem.getBookedPassengers(flightNumber); // O(1)

    for (const auto& passenger : bookedPassengers) { // O(n)
        if (passenger->getId() == passengerId) {
            if (!passenger->isCheckedIn()) {
                cout << "Passenger " << passenger->getName() << " has not checked in yet." << endl;
            }
            else if (passenger->isBoarded()) {
                cout << "Passenger " << passenger->getName() << " has already boarded." << endl;
            }
            else {
                passenger->setBoarded(true);
                cout << "Passenger " << passenger->getName() << " has boarded the flight." << endl;
            }
            return;
        }
    }

    cout << "Passenger with ID " << passengerId << " not found on flight " << flightNumber << "." << endl;
}

void BoardingManager::addLastMinuteChange(const shared_ptr<Passenger>& passenger) { // O(1)
    lastMinuteChanges.push(passenger);
    cout << "Last-minute change added for passenger " << passenger->getName() << "." << endl;
}

void BoardingManager::processLastMinuteChanges() { // O(1)
    if (lastMinuteChanges.empty()) {
        cout << "No last-minute changes to process." << endl;
        return;
    }

    cout << "Processing last-minute changes:" << endl;
    while (!lastMinuteChanges.empty()) {
        auto passenger = lastMinuteChanges.top();
        lastMinuteChanges.pop();

        cout << "Processing change for passenger " << passenger->getName() << "..." << endl;
        
    }

    cout << "All last-minute changes processed." << endl;
}

void BoardingManager::displayBoardingStatus(const string& flightNumber) const {  // O(n)
    auto bookedPassengers = bookingSystem.getBookedPassengers(flightNumber); // O(1)

    if (bookedPassengers.empty()) {
        cout << "No passengers booked for flight " << flightNumber << "." << endl;
        return;
    }

    int totalPassengers = 0;
    int checkedInPassengers = 0;
    int boardedPassengers = 0;

    for (const auto& passenger : bookedPassengers) { // O(n)
        totalPassengers++;
        if (passenger->isCheckedIn()) {
            checkedInPassengers++;
        }
        if (passenger->isBoarded()) {
            boardedPassengers++;
        }
    }

    cout << "Boarding Status for Flight " << flightNumber << ":" << endl;
    cout << "Total passengers: " << totalPassengers << endl;
    cout << "Checked-in passengers: " << checkedInPassengers << endl;
    cout << "Boarded passengers: " << boardedPassengers << endl;

    cout << "\nPassenger Details:" << endl;
    for (const auto& passenger : bookedPassengers) {    // O(n)
        cout << "  - " << passenger->getName()
            << " (Seat: " << passenger->getSeatNumber() << ")"
            << " - " << (passenger->isCheckedIn() ? "Checked-in" : "Not checked-in")
            << ", " << (passenger->isBoarded() ? "Boarded" : "Not boarded") << endl;
    }
}