Airline Reservation System
A comprehensive airline reservation and boarding management system built in C++ that streamlines operations from flight booking to passenger boarding.

📚 Project Information
Course: Data Structures (CSC 313)
Domain: Travel & Transportation

📋 Overview
This system manages the complete airline passenger journey, implementing efficient data structures and algorithms to ensure smooth operations and an organized passenger experience. The application handles flight bookings, passenger check-in, and boarding processes in a structured and efficient manner.

✨ Features
1. Flight Booking Management

Search for available flights
Check seat availability in real-time
Book tickets and store reservation details
Manage confirmed reservations

2. Passenger Check-in System

Process passenger check-in before flights
Assign boarding passes and seat numbers
Store checked-in passenger information for boarding

3. Boarding Management

Call passengers in order for boarding
Verify boarding passes
Track boarded passengers
Handle last-minute reassignments and cancellations

🏗️ System Architecture
Classes

Flight: Stores flight details including flight number, destination, and available seats
BookingSystem: Manages booking requests and confirmed reservations
Passenger: Contains passenger information such as name, ID, and seat number
CheckInSystem: Handles passenger check-in operations
BoardingManager: Manages the passenger boarding process

🔧 Technical Implementation
Algorithm

Binary Search: Implemented for efficient flight and passenger lookup

Data Structures

list<Flight>: Stores available flights for easy display and searching
queue<Passenger>: Manages the check-in process in FIFO order
stack<Passenger>: Handles last-minute passenger reassignments or cancellations
map<int, list<Flight>>: Maps flight numbers to corresponding bookings

🎯 Key Benefits

Streamlined airline operations from booking to boarding
Efficient passenger management through appropriate data structures
Reduced delays and enhanced overall system efficiency
Smooth and organized passenger experience

💡 Learning Outcomes
This project demonstrates practical application of:

Multiple data structure types working together
Algorithm optimization for search operations
Real-world system design and architecture
Queue and stack operations in a practical context


Designed to make air travel management efficient and passenger-friendly ✈️
