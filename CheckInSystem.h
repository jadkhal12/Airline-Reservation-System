#ifndef CHECK_IN_SYSTEM_H
#define CHECK_IN_SYSTEM_H

#include "Passenger.h"
#include "BookingSystem.h"
#include <queue>
#include <memory>
using namespace std;

class CheckInSystem {
private:
    queue<shared_ptr<Passenger>> checkInQueue;
    BookingSystem& bookingSystem;

public:
    // Constructor
    CheckInSystem(BookingSystem& bookingSystem);

    // Check-in operations
    void addToCheckInQueue(const shared_ptr<Passenger>& passenger);
    bool processNextCheckIn(const string& flightNumber);
    void checkInPassenger(const string& flightNumber, const string& passengerId);
    void displayCheckInQueue() const;
};

#endif 