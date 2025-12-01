#include "BookingSystem.h"
#include <iostream>
using namespace std;

//implementation for bookingsystem.h file

BookingSystem::BookingSystem() {} // O(1)

void BookingSystem::addFlight(const shared_ptr<Flight>& flight) { // O(1)
    flights.push_back(flight);
}

shared_ptr<Flight> BookingSystem::findFlight(const string& flightNumber) { // O(n)
    for (const auto& flight : flights) {
        if (flight->getFlightNumber() == flightNumber) {
            return flight;
        }
    }
    return nullptr;
}

void BookingSystem::displayAllFlights() const { // O(n)
    if (flights.empty()) {
        cout << "No flights available." << endl;
        return;
    }

    cout << "Available Flights:" << endl;
    for (const auto& flight : flights) {
        flight->displayInfo();
    }
}

bool BookingSystem::bookFlight(const string& flightNumber, const shared_ptr<Passenger>& passenger) { // O(n)
    auto flight = findFlight(flightNumber); // O(n)
    if (!flight) {
        cout << "Flight not found." << endl;
        return false;
    }

    if (flight->getAvailableSeats() <= 0) { // O(1)
        cout << "No available seats on this flight." << endl;
        return false;
    }

    string seatNumber = flight->getNextAvailableSeat(); // O(n)
    if (seatNumber.empty()) {
        cout << "No available seats on this flight." << endl;
        return false;
    }

    if (flight->bookSeat(seatNumber)) { // O(log n)
        passenger->setSeatNumber(seatNumber); // O(1)
        bookings[flightNumber].push_back(passenger); // O(1)
        cout << "Booking successful. Seat " << seatNumber << " assigned to " << passenger->getName() << "." << endl;
        return true;
    }

    cout << "Failed to book seat." << endl;
    return false;
}

bool BookingSystem::cancelBooking(const string& flightNumber, const string& passengerId) { // O(n)
    auto flight = findFlight(flightNumber); // O(n)
    if (!flight) {
        cout << "Flight not found." << endl;
        return false;
    }

    auto& passengerList = bookings[flightNumber];
    for (auto it = passengerList.begin(); it != passengerList.end(); ++it) { // O(n)
        if ((*it)->getId() == passengerId) {
            string seatNumber = (*it)->getSeatNumber(); // O(1)
            flight->cancelSeat(seatNumber); // O(log n)
            passengerList.erase(it); // O(1)
            cout << "Booking canceled successfully." << endl;
            return true;
        }
    }

    cout << "Passenger not found on this flight." << endl;
    return false;
}

void BookingSystem::displayBookings(const string& flightNumber) const { // O(n)
    auto it = bookings.find(flightNumber); // O(1)
    if (it == bookings.end() || it->second.empty()) {
        cout << "No bookings found for flight " << flightNumber << "." << endl;
        return;
    }

    cout << "Bookings for flight " << flightNumber << ":" << endl;
    for (const auto& passenger : it->second) {
        passenger->displayInfo();
    }
}

list<shared_ptr<Passenger>> BookingSystem::getBookedPassengers(const string& flightNumber) const { // O(1)
    auto it = bookings.find(flightNumber);
    if (it == bookings.end()) {
        return {};
    }
    return it->second;
}
