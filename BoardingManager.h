#ifndef BOARDING_MANAGER_H
#define BOARDING_MANAGER_H

#include "Passenger.h"
#include "BookingSystem.h"
#include <stack>
#include <memory>
using namespace std;

class BoardingManager {
private:
    stack<shared_ptr<Passenger>> lastMinuteChanges;
    BookingSystem& bookingSystem;

public:
    // Constructor
    BoardingManager(BookingSystem& bookingSystem);

    // Boarding operations
    void startBoarding(const string& flightNumber);
    void boardPassenger(const string& flightNumber, const string& passengerId);
    void addLastMinuteChange(const shared_ptr<Passenger>& passenger);
    void processLastMinuteChanges();
    void displayBoardingStatus(const string& flightNumber) const;
};

#endif 