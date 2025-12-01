#ifndef BOOKING_SYSTEM_H
#define BOOKING_SYSTEM_H

#include "Flight.h"
#include "Passenger.h"
#include <map>
#include <list>
#include <memory>
using namespace std;

class BookingSystem {
private:
    list<shared_ptr<Flight>> flights;
    map<string, list<shared_ptr<Passenger>>> bookings;

public:
    // Constructor
    BookingSystem();

    // Flight management
    void addFlight(const shared_ptr<Flight>& flight);
    shared_ptr<Flight> findFlight(const string& flightNumber);
    void displayAllFlights() const;

    // Booking management
    bool bookFlight(const string& flightNumber, const shared_ptr<Passenger>& passenger);
    bool cancelBooking(const string& flightNumber, const string& passengerId);
    void displayBookings(const string& flightNumber) const;
    list<shared_ptr<Passenger>> getBookedPassengers(const string& flightNumber) const;
};

#endif 