#include <iostream>
#include <string>

using namespace std;

// Structure for a car
struct Car {
    string make;
    string model;
    int year;
    bool available;
    Car* next;
    Car* prev; // Only for doubly linked list
};

// Class for Circular Linked List
class CircularLinkedList {
private:
    Car* head;

public:
    // Constructor
    CircularLinkedList() {
        head = nullptr;
    }

    // Destructor to free memory
    ~CircularLinkedList() {
        if (head == nullptr) return;
        Car* current = head->next;
        while (current != head) {
            Car* temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
    }

    // Function to add a car to the rental system
    void addCar(string make, string model, int year) {
        Car* newCar = new Car;
        newCar->make = make;
        newCar->model = model;
        newCar->year = year;
        newCar->available = true;
        newCar->next = nullptr;
        
        if (head == nullptr) {
            head = newCar;
            newCar->next = head;
        } else {
            Car* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newCar;
            newCar->next = head;
        }
        cout << "Car added to the rental system." << endl;
    }

    // Function to rent a car
    void rentCar(string make, string model) {
        Car* current = head;
        do {
            if (current->make == make && current->model == model && current->available) {
                current->available = false;
                cout << "You have rented the car: " << make << " " << model << endl;
                return;
            }
            current = current->next;
        } while (current != head);
        cout << "Car not available for rental." << endl;
    }

    // Function to return a rented car
    void returnCar(string make, string model) {
        Car* current = head;
        do {
            if (current->make == make && current->model == model && !current->available) {
                current->available = true;
                cout << "Thank you for returning the car: " << make << " " << model << endl;
                return;
            }
            current = current->next;
        } while (current != head);
        cout << "Invalid return. Car was not rented or does not exist." << endl;
    }

    // Function to display available cars
    void displayAvailableCars() {
        cout << "Available Cars:" << endl;
        Car* current = head;
        do {
            if (current->available) {
                cout << "Make: " << current->make << ", Model: " << current->model << ", Year: " << current->year << endl;
            }
            current = current->next;
        } while (current != head);
    }
};

// Class for Singly Linked List
class SinglyLinkedList {
private:
    Car* head;

public:
    // Constructor
    SinglyLinkedList() {
        head = nullptr;
    }

    // Destructor to free memory
    ~SinglyLinkedList() {
        Car* current = head;
        while (current != nullptr) {
            Car* next = current->next;
            delete current;
            current = next;
        }
    }

    // Function to add a car to the rental system
    void addCar(string make, string model, int year) {
        Car* newCar = new Car;
        newCar->make = make;
        newCar->model = model;
        newCar->year = year;
        newCar->available = true;
        newCar->next = head;
        head = newCar;
        cout << "Car added to the rental system." << endl;
    }

    // Function to rent a car
    void rentCar(string make, string model) {
        Car* current = head;
        while (current != nullptr) {
            if (current->make == make && current->model == model && current->available) {
                current->available = false;
                cout << "You have rented the car: " << make << " " << model << endl;
                return;
            }
            current = current->next;
        }
        cout << "Car not available for rental." << endl;
    }

    // Function to return a rented car
    void returnCar(string make, string model) {
        Car* current = head;
        while (current != nullptr) {
            if (current->make == make && current->model == model && !current->available) {
                current->available = true;
                cout << "Thank you for returning the car: " << make << " " << model << endl;
                return;
            }
            current = current->next;
        }
        cout << "Invalid return. Car was not rented or does not exist." << endl;
    }

    // Function to display available cars
    void displayAvailableCars() {
        cout << "Available Cars:" << endl;
        Car* current = head;
        while (current != nullptr) {
            if (current->available) {
                cout << "Make: " << current->make << ", Model: " << current->model << ", Year: " << current->year << endl;
            }
            current = current->next;
        }
    }
};

// Class for Doubly Linked List
class DoublyLinkedList {
private:
    Car* head;

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
    }

    // Destructor to free memory
    ~DoublyLinkedList() {
        Car* current = head;
        while (current != nullptr) {
            Car* next = current->next;
            delete current;
            current = next;
        }
    }

    // Function to add a car to the rental system
    void addCar(string make, string model, int year) {
        Car* newCar = new Car;
        newCar->make = make;
        newCar->model = model;
        newCar->year = year;
        newCar->available = true;
        newCar->next = head;
        newCar->prev = nullptr;
        if (head != nullptr) {
            head->prev = newCar;
        }
        head = newCar;
        cout << "Car added to the rental system." << endl;
    }

    // Function to rent a car
    void rentCar(string make, string model) {
        Car* current = head;
        while (current != nullptr) {
            if (current->make == make && current->model == model && current->available) {
                current->available = false;
                cout << "You have rented the car: " << make << " " << model << endl;
                return;
            }
            current = current->next;
        }
        cout << "Car not available for rental." << endl;
    }

    // Function to return a rented car
    void returnCar(string make, string model) {
        Car* current = head;
        while (current != nullptr) {
            if (current->make == make && current->model == model && !current->available) {
                current->available = true;
                cout << "Thank you for returning the car: " << make << " " << model << endl;
                return;
            }
            current = current->next;
        }
        cout << "Invalid return. Car was not rented or does not exist." << endl;
    }

    // Function to display available cars
    void displayAvailableCars() {
        cout << "Available Cars:" << endl;
        Car* current = head;
        while (current != nullptr) {
            if (current->available) {
                cout << "Make: " << current->make << ", Model: " << current->model << ", Year: " << current->year << endl;
            }
            current = current->next;
        }
    }
};

int main() {
    int choice;
    CircularLinkedList circularList;
    SinglyLinkedList singlyList;
    DoublyLinkedList doublyList;

    do {
        cout << "\nCar Rental System Menu:\n";
        cout << "1. Add a Car\n";
        cout << "2. Rent a Car\n";
        cout << "3. Return a Car\n";
        cout << "4. Display Available Cars\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string make, model;
        int year;

        switch (choice) {
            case 1:
                cout << "Enter car details:" << endl;
                cout << "Make: ";
                cin >> make;
                cout << "Model: ";
                cin >> model;
                cout << "Year: ";
                cin >> year;
                circularList.addCar(make, model, year);
                singlyList.addCar(make, model, year);
                doublyList.addCar(make, model, year);
                break;
            case 2:
                cout << "Enter car details to rent:" << endl;
                cout << "Make: ";
                cin >> make;
                cout << "Model: ";
                cin >> model;
                circularList.rentCar(make, model);
                singlyList.rentCar(make, model);
                doublyList.rentCar(make, model);
                break;
            case 3:
                cout << "Enter car details to return:" << endl;
                cout << "Make: ";
                cin >> make;
                cout << "Model: ";
                cin >> model;
                circularList.returnCar(make, model);
                singlyList.returnCar(make, model);
                doublyList.returnCar(make, model);
                break;
            case 4:
                cout << "Circular Linked List - Available Cars" << endl;
                circularList.displayAvailableCars();
                cout << "\nSingly Linked List - Available Cars" << endl;
                singlyList.displayAvailableCars();
                cout << "\nDoubly Linked List - Available Cars" << endl;
                doublyList.displayAvailableCars();
                break;
            case 5:
                cout << "Exiting the program. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
