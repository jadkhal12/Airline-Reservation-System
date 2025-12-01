#include "CheckInSystem.h"
#include <iostream>
using namespace std;

// implementation for checkinsystem.h file

CheckInSystem::CheckInSystem(BookingSystem& bookingSystem) : bookingSystem(bookingSystem) {} // O(1)

void CheckInSystem::addToCheckInQueue(const shared_ptr<Passenger>& passenger) { // O(1)
    checkInQueue.push(passenger);
    cout << "Passenger " << passenger->getName() << " added to check-in queue." << endl;
}

bool CheckInSystem::processNextCheckIn(const string& flightNumber) { // O(m)
    if (checkInQueue.empty()) {
        cout << "Check-in queue is empty." << endl;
        return false;
    }

    auto passenger = checkInQueue.front();
    checkInQueue.pop();

    // Check if the passenger is booked on this flight
    auto bookedPassengers = bookingSystem.getBookedPassengers(flightNumber); // O(1)
    bool isBooked = false;

    for (const auto& bookedPassenger : bookedPassengers) { // O(n)
        if (bookedPassenger->getId() == passenger->getId()) {
            isBooked = true;
            break;
        }
    }

    if (!isBooked) {
        cout << "Passenger " << passenger->getName() << " is not booked on flight " << flightNumber << "." << endl;
        return false;
    }
    // Mark the passenger as checked in
    passenger->setCheckedIn(true); // O(1)
    cout << "Passenger " << passenger->getName() << " checked in for flight " << flightNumber
        << ", Seat: " << passenger->getSeatNumber() << "." << endl;

    return true;
}

void CheckInSystem::checkInPassenger(const string& flightNumber, const string& passengerId) { // O(n)
    auto bookedPassengers = bookingSystem.getBookedPassengers(flightNumber); // O(1)

    for (const auto& passenger : bookedPassengers) { // O(n)
        if (passenger->getId() == passengerId) {
            if (passenger->isCheckedIn()) {
                cout << "Passenger " << passenger->getName() << " is already checked in." << endl;
            }
            else {
                passenger->setCheckedIn(true);
                cout << "Passenger " << passenger->getName() << " checked in for flight " << flightNumber
                    << ", Seat: " << passenger->getSeatNumber() << "." << endl;
            }
            return;
        }
    }

    cout << "Passenger with ID " << passengerId << " not found on flight " << flightNumber << "." << endl;
}

void CheckInSystem::displayCheckInQueue() const { // O(n)
    if (checkInQueue.empty()) {
        cout << "Check-in queue is empty." << endl;
        return;
    }

    // We can't directly iterate through a queue without modifying it,
    // so we'll create a temporary copy
    queue<shared_ptr<Passenger>> tempQueue = checkInQueue;
    int position = 1;

    cout << "Check-in Queue:" << endl;
    while (!tempQueue.empty()) {
        cout << position << ". ";
        tempQueue.front()->displayInfo();
        tempQueue.pop();
        position++;
    }
}
