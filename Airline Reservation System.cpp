/* 
                                 Airline Reservation System Project for CSC313 Spring 2025 
                                                     
                                                     Made by Jad & Joe
                                      
                                      Jad Khalil. ID: 20231975; Major: Computer Science
                                      Joe Chahwan. ID:20221859; Major: Computer Science
            
*/

#include "Flight.h"
#include "Passenger.h"
#include "BookingSystem.h"
#include "CheckInSystem.h"
#include "BoardingManager.h"
#include <iostream>
#include <memory>
#include <limits>

using namespace std;

// Define menu options using enum
enum MenuOption {
    EXIT = 0,
    FLIGHT_MANAGEMENT = 1,
    BOOKING_MANAGEMENT = 2,
    CHECK_IN_MANAGEMENT = 3,
    BOARDING_MANAGEMENT = 4
};

// Function prototypes
void displayMainMenu();
void handleFlightManagement(BookingSystem& bookingSystem);
void handleBookingManagement(BookingSystem& bookingSystem);
void handleCheckInManagement(BookingSystem& bookingSystem, CheckInSystem& checkInSystem);
void handleBoardingManagement(BookingSystem& bookingSystem, BoardingManager& boardingManager);

int main() {
    // Initialize systems
    BookingSystem bookingSystem;
    CheckInSystem checkInSystem(bookingSystem);
    BoardingManager boardingManager(bookingSystem);

    // Add some sample flights
    bookingSystem.addFlight(make_shared<Flight>("100", "New York", "London", "10:00", "22:00", 150));
    bookingSystem.addFlight(make_shared<Flight>("200", "London", "Paris", "12:30", "14:00", 100));
    bookingSystem.addFlight(make_shared<Flight>("300", "Chicago", "Tokyo", "14:45", "18:30", 200));

    int choice;

    do {
        displayMainMenu();
        cout << "Enter your choice (0-4): ";

        // Input validation
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (static_cast<MenuOption>(choice)) {
        case FLIGHT_MANAGEMENT:
            handleFlightManagement(bookingSystem);
            break;
        case BOOKING_MANAGEMENT:
            handleBookingManagement(bookingSystem);
            break;
        case CHECK_IN_MANAGEMENT:
            handleCheckInManagement(bookingSystem, checkInSystem);
            break;
        case BOARDING_MANAGEMENT:
            handleBoardingManagement(bookingSystem, boardingManager);
            break;
        case EXIT:
            cout << "Thank You for Using the Airline Reservation System. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != EXIT);

    return 0;
}

void displayMainMenu() {
    cout << "\n****** AIRLINE RESERVATION SYSTEM ******" << endl;
    cout << "1. Flight Management" << endl;
    cout << "2. Booking Management" << endl;
    cout << "3. Check-in Management" << endl;
    cout << "4. Boarding Management" << endl;
    cout << "0. Exit" << endl;
    cout << "------------------------------------------" << endl;
}

void handleFlightManagement(BookingSystem& bookingSystem) {
    int choice;

    do {
        cout << "\n******Flight Management ******" << endl;
        cout << "1. Add Flight" << endl;
        cout << "2. Display All Flights" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "-----------------------------" << endl;
        cout << "Enter your choice (0-2): ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            string flightNumber, departure, destination, departureTime, arrivalTime;
            int totalSeats;

            cout << "Enter flight number: ";
            getline(cin, flightNumber);

            cout << "Enter departure city: ";
            getline(cin, departure);

            cout << "Enter destination city: ";
            getline(cin, destination);

            cout << "Enter departure time (HH:MM): ";
            getline(cin, departureTime);

            cout << "Enter arrival time (HH:MM): ";
            getline(cin, arrivalTime);

            cout << "Enter total number of seats: ";
            cin >> totalSeats;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            bookingSystem.addFlight(make_shared<Flight>(flightNumber, departure, destination, departureTime, arrivalTime, totalSeats));
            cout << "Flight added successfully." << endl;
            break;
        }
        case 2:
            bookingSystem.displayAllFlights();
            break;
        case 0:
            cout << "Returning to main menu." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);
}

void handleBookingManagement(BookingSystem& bookingSystem) {
    int choice;

    do {
        cout << "\n****** Booking Management ******" << endl;
        cout << "1. Book a Flight" << endl;
        cout << "2. Cancel a Booking" << endl;
        cout << "3. Display Bookings for a Flight" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "-------------------------------" << endl;
        cout << "Enter your choice (0-3): ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            bookingSystem.displayAllFlights();

            string flightNumber, passengerName, passengerId;

            cout << "Enter flight number: ";
            getline(cin, flightNumber);

            // Check if flight exists
            auto flight = bookingSystem.findFlight(flightNumber);
            if (!flight) {
                cout << "Flight not found." << endl;
                break;
            }

            cout << "Enter passenger name: ";
            getline(cin, passengerName);

            cout << "Enter passenger ID: ";
            getline(cin, passengerId);

            // Completing the handleBookingManagement function in main.cpp
            auto passenger = make_shared<Passenger>(passengerName, passengerId);
            bookingSystem.bookFlight(flightNumber, passenger);
            break;
        }
        case 2: {
            string flightNumber, passengerId;

            cout << "Enter flight number: ";
            getline(cin, flightNumber);

            // Check if flight exists
            auto flight = bookingSystem.findFlight(flightNumber);
            if (!flight) {
                cout << "Flight not found." << endl;
                break;
            }

            cout << "Enter passenger ID: ";
            getline(cin, passengerId);

            bookingSystem.cancelBooking(flightNumber, passengerId);
            break;
        }
        case 3: {
            string flightNumber;

            cout << "Enter flight number: ";
            getline(cin, flightNumber);

            // Check if flight exists
            auto flight = bookingSystem.findFlight(flightNumber);
            if (!flight) {
                cout << "Flight not found." << endl;
                break;
            }

            bookingSystem.displayBookings(flightNumber);
            break;
        }
        case 0:
            cout << "Returning to main menu." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);
}

void handleCheckInManagement(BookingSystem& bookingSystem, CheckInSystem& checkInSystem) {
    int choice;

    do {
        cout << "\n****** Check-in Management ******" << endl;
        cout << "1. Add Passenger to Check-in Queue" << endl;
        cout << "2. Process Next Check-in" << endl;
        cout << "3. Check-in a Specific Passenger" << endl;
        cout << "4. Display Check-in Queue" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Enter your choice (0-4): ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            string passengerName, passengerId;

            cout << "Enter passenger name: ";
            getline(cin, passengerName);

            cout << "Enter passenger ID: ";
            getline(cin, passengerId);

            auto passenger = make_shared<Passenger>(passengerName, passengerId);
            checkInSystem.addToCheckInQueue(passenger);
            break;
        }
        case 2: {
            string flightNumber;

            cout << "Enter flight number: ";
            getline(cin, flightNumber);

            // Check if flight exists
            auto flight = bookingSystem.findFlight(flightNumber);
            if (!flight) {
                cout << "Flight not found." << endl;
                break;
            }

            checkInSystem.processNextCheckIn(flightNumber);
            break;
        }
        case 3: {
            string flightNumber, passengerId;

            cout << "Enter flight number: ";
            getline(cin, flightNumber);

            // Check if flight exists
            auto flight = bookingSystem.findFlight(flightNumber);
            if (!flight) {
                cout << "Flight not found." << endl;
                break;
            }

            cout << "Enter passenger ID: ";
            getline(cin, passengerId);

            checkInSystem.checkInPassenger(flightNumber, passengerId);
            break;
        }
        case 4:
            checkInSystem.displayCheckInQueue();
            break;
        case 0:
            cout << "Returning to main menu." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);
}

void handleBoardingManagement(BookingSystem& bookingSystem, BoardingManager& boardingManager) {
    int choice;

    do {
        cout << "\n****** Boarding Management ******" << endl;
        cout << "1. Start Boarding for a Flight" << endl;
        cout << "2. Board a Passenger" << endl;
        cout << "3. Add Last-minute Change" << endl;
        cout << "4. Process Last-minute Changes" << endl;
        cout << "5. Display Boarding Status" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Enter your choice (0-5): ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            string flightNumber;

            cout << "Enter flight number: ";
            getline(cin, flightNumber);

            // Check if flight exists
            auto flight = bookingSystem.findFlight(flightNumber);
            if (!flight) {
                cout << "Flight not found." << endl;
                break;
            }

            boardingManager.startBoarding(flightNumber);
            break;
        }
        case 2: {
            string flightNumber, passengerId;

            cout << "Enter flight number: ";
            getline(cin, flightNumber);

            // Check if flight exists
            auto flight = bookingSystem.findFlight(flightNumber);
            if (!flight) {
                cout << "Flight not found." << endl;
                break;
            }

            cout << "Enter passenger ID: ";
            getline(cin, passengerId);

            boardingManager.boardPassenger(flightNumber, passengerId);
            break;
        }
        case 3: {
            string passengerName, passengerId;

            cout << "Enter passenger name: ";
            getline(cin, passengerName);

            cout << "Enter passenger ID: ";
            getline(cin, passengerId);

            auto passenger = make_shared<Passenger>(passengerName, passengerId);
            boardingManager.addLastMinuteChange(passenger);
            break;
        }
        case 4:
            boardingManager.processLastMinuteChanges();
            break;
        case 5: {
            string flightNumber;

            cout << "Enter flight number: ";
            getline(cin, flightNumber);

            // Check if flight exists
            auto flight = bookingSystem.findFlight(flightNumber);
            if (!flight) {
                cout << "Flight not found." << endl;
                break;
            }

            boardingManager.displayBoardingStatus(flightNumber);
            break;
        }
        case 0:
            cout << "Returning to main menu." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);
}