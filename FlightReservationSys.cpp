#include <iostream>
#include <string>

using namespace std;

// Structure for a flight
struct Flight {
    string flightNumber;
    string source;
    string destination;
    int availableSeats;
};

// Class for managing flights using arrays
class FlightManager {
private:
    static const int MAX_FLIGHTS = 100;
    Flight flights[MAX_FLIGHTS];
    int numFlights;

public:
    // Constructor
    FlightManager() {
        numFlights = 0;
    }

    // Function to add a flight
    void addFlight(string flightNum, string src, string dest, int seats) {
        if (numFlights < MAX_FLIGHTS) {
            flights[numFlights].flightNumber = flightNum;
            flights[numFlights].source = src;
            flights[numFlights].destination = dest;
            flights[numFlights].availableSeats = seats;
            numFlights++;
            cout << "Flight " << flightNum << " from " << src << " to " << dest << " added successfully." << endl;
        } else {
            cout << "Maximum number of flights reached. Cannot add more flights." << endl;
        }
    }

    // Function to search for available flights between two cities
    void searchFlights(string src, string dest) {
        bool found = false;
        cout << "Available Flights between " << src << " and " << dest << ":" << endl;
        for (int i = 0; i < numFlights; ++i) {
            if (flights[i].source == src && flights[i].destination == dest && flights[i].availableSeats > 0) {
                cout << "Flight Number: " << flights[i].flightNumber << ", Available Seats: " << flights[i].availableSeats << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No available flights found between " << src << " and " << dest << endl;
        }
    }

    // Function to book a seat on a flight
    void bookSeat(string flightNum) {
        for (int i = 0; i < numFlights; ++i) {
            if (flights[i].flightNumber == flightNum && flights[i].availableSeats > 0) {
                flights[i].availableSeats--;
                cout << "Seat booked successfully on flight " << flightNum << endl;
                return;
            }
        }
        cout << "Sorry, no available seats on flight " << flightNum << endl;
    }

    // Function to cancel a seat booking
    void cancelBooking(string flightNum) {
        for (int i = 0; i < numFlights; ++i) {
            if (flights[i].flightNumber == flightNum) {
                flights[i].availableSeats++;
                cout << "Booking cancelled successfully for flight " << flightNum << endl;
                return;
            }
        }
        cout << "No booking found for flight " << flightNum << endl;
    }

    // Function to display all flights
    void displayFlights() {
        cout << "All Flights:" << endl;
        for (int i = 0; i < numFlights; ++i) {
            cout << "Flight Number: " << flights[i].flightNumber << ", Source: " << flights[i].source << ", Destination: " << flights[i].destination << ", Available Seats: " << flights[i].availableSeats << endl;
        }
    }
};

int main() {
    FlightManager flightManager;

    int choice;
    do {
        cout << "\nFlight Reservation System Menu:" << endl;
        cout << "1. Add Flight" << endl;
        cout << "2. Search Flights" << endl;
        cout << "3. Book Seat" << endl;
        cout << "4. Cancel Booking" << endl;
        cout << "5. Display All Flights" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        string flightNum, src, dest;

        switch (choice) {
            case 1:
                cout << "Enter flight details:" << endl;
                cout << "Flight Number: ";
                cin >> flightNum;
                cout << "Source: ";
                cin >> src;
                cout << "Destination: ";
                cin >> dest;
                int seats;
                cout << "Available Seats: ";
                cin >> seats;
                flightManager.addFlight(flightNum, src, dest, seats);
                break;
            case 2:
                cout << "Enter source city: ";
                cin >> src;
                cout << "Enter destination city: ";
                cin >> dest;
                flightManager.searchFlights(src, dest);
                break;
            case 3:
                cout << "Enter flight number to book seat: ";
                cin >> flightNum;
                flightManager.bookSeat(flightNum);
                break;
            case 4:
                cout << "Enter flight number to cancel booking: ";
                cin >> flightNum;
                flightManager.cancelBooking(flightNum);
                break;
            case 5:
                flightManager.displayFlights();
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}
