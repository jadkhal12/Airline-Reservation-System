#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <set>
using namespace std;

class Flight {
private:
    string flightNumber;
    string departure;
    string destination;
    string departureTime;
    string arrivalTime;
    int totalSeats;
    int availableSeats;
    set<string> bookedSeats;

public:
    // Constructor
    Flight(const string& flightNumber, const string& departure, const string& destination,
        const string& departureTime, const string& arrivalTime, int totalSeats);

    // Getters
    string getFlightNumber() const;
    string getDeparture() const;
    string getDestination() const;
    string getDepartureTime() const;
    string getArrivalTime() const;
    int getTotalSeats() const;
    int getAvailableSeats() const;

    // Flight operations
    bool bookSeat(const string& seatNumber);
    bool cancelSeat(const string& seatNumber);
    bool isSeatAvailable(const string& seatNumber) const;
    string getNextAvailableSeat() const;

    // Display flight information
    void displayInfo() const;
};

#endif 