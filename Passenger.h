#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
using namespace std;

class Passenger {
private:
    string name;
    string id;
    string seatNumber;
    bool checkedIn;
    bool boarded;

public:
    // Constructor
    Passenger(const string& name, const string& id);

    // Getters
    string getName() const;
    string getId() const;
    string getSeatNumber() const;
    bool isCheckedIn() const;
    bool isBoarded() const;

    // Setters
    void setSeatNumber(const string& seatNumber);
    void setCheckedIn(bool status);
    void setBoarded(bool status);

    // Display passenger information
    void displayInfo() const;
};

#endif 