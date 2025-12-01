#include "Flight.h"
#include <iostream>
using namespace std;

//implementation for flight.h file

Flight::Flight(const string& flightNumber, const string& departure, const string& destination,
    const string& departureTime, const string& arrivalTime, int totalSeats) // O(1)
    : flightNumber(flightNumber), departure(departure), destination(destination),
    departureTime(departureTime), arrivalTime(arrivalTime), totalSeats(totalSeats), availableSeats(totalSeats) {}

string Flight::getFlightNumber() const { // O(1)
    return flightNumber;
}

string Flight::getDeparture() const { // O(1)
    return departure;
}

string Flight::getDestination() const { // O(1)
    return destination;
}

string Flight::getDepartureTime() const { // O(1)
    return departureTime;
}

string Flight::getArrivalTime() const { // O(1)
    return arrivalTime;
}

int Flight::getTotalSeats() const { // O(1)
    return totalSeats;
}

int Flight::getAvailableSeats() const { // O(1)
    return availableSeats;
}

bool Flight::bookSeat(const string& seatNumber) { // O(log n)
    if (isSeatAvailable(seatNumber)) { // O(log n)
        bookedSeats.insert(seatNumber); // O(log n)
        availableSeats--; // O(1)
        return true;
    }
    return false;
}

bool Flight::cancelSeat(const string& seatNumber) { // O(log n)
    auto it = bookedSeats.find(seatNumber); // O(log n)
    if (it != bookedSeats.end()) {
        bookedSeats.erase(it); // O(log n)
        availableSeats++; // O(1)
        return true;
    }
    return false;
}

bool Flight::isSeatAvailable(const string& seatNumber) const { // O(log n)
    return bookedSeats.find(seatNumber) == bookedSeats.end();
}

string Flight::getNextAvailableSeat() const { // O(n)
    char row = 'A';
    int col = 1;

    while (row <= 'Z') { // Max 26 rows
        while (col <= totalSeats / 6) { // Columns per row
            string seat = row + to_string(col);
            if (isSeatAvailable(seat)) { // O(log n)
                return seat;
            }
            col++;
        }
        row++;
        col = 1;
    }

    return ""; // No available seats
}

void Flight::displayInfo() const { // O(1)
    cout << "Flight: " << flightNumber << ", From: " << departure << ", To: " << destination
        << ", Departure: " << departureTime << ", Arrival: " << arrivalTime
        << ", Available seats: " << availableSeats << "/" << totalSeats << endl;
}
