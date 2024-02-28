#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

// Define a structure to hold crop information
struct Crop {
    string name;
    double price;
    int amount;
};

class Farmer {
private:
    string name;
    string address;
    Crop crops[100]; // Assuming maximum 100 crops per farmer
    int numCrops;

public:
    // Constructor
    Farmer(string n, string addr) {
        name = n;
        address = addr;
        numCrops = 0;
    }

    // Add a crop
    void addCrop(string cropName, double cropPrice, int cropAmount) {
        if (numCrops < 100) {
            crops[numCrops].name = cropName;
            crops[numCrops].price = cropPrice;
            crops[numCrops].amount = cropAmount;
            numCrops++;
        } else {
            cout << "Maximum number of crops reached." << endl;
        }
    }

    // Show all crops
    void showCrops() {
        cout << "Crop information for farmer " << name << ":" << endl;
        for (int i = 0; i < numCrops; ++i) {
            cout << "Crop: " << crops[i].name << ", Price: $" << crops[i].price << ", Amount: " << crops[i].amount << endl;
        }
    }

    // Search for a specific crop
    void searchCrop(string cropName) {
        int found = -1;
        for (int i = 0; i < numCrops; ++i) {
            if (crops[i].name == cropName) {
                cout << "Crop: " << crops[i].name << ", Price: $" << crops[i].price << ", Amount: " << crops[i].amount << endl;
                found = i;
                break;
            }
        }
        if (found == -1) {
            cout << "Crop not found." << endl;
        }
    }

    // Update crop information
    void updateCrop(string cropName, double newPrice, int newAmount) {
        for (int i = 0; i < numCrops; ++i) {
            if (crops[i].name == cropName) {
                crops[i].price = newPrice;
                crops[i].amount = newAmount;
                cout << "Crop information updated." << endl;
                return;
            }
        }
        cout << "Crop not found." << endl;
    }

    // Delete a crop
    void deleteCrop(string cropName) {
        for (int i = 0; i < numCrops; ++i) {
            if (crops[i].name == cropName) {
                for (int j = i; j < numCrops - 1; ++j) {
                    crops[j] = crops[j + 1];
                }
                numCrops--;
                cout << "Crop deleted." << endl;
                return;
            }
        }
        cout << "Crop not found." << endl;
    }
};

int main() {
    string name, address, cropName;
    double price, newPrice;
    int amount, newAmount, choice;

    cout << "Enter the full name of the farmer: ";
    getline(cin, name);
    cout << "Enter the address of the farmer: ";
    getline(cin, address);

    Farmer farmer(name, address);

    while (true) {
        cout << "\n1. Add crop\n2. Show all crops\n3. Search for a crop\n4. Update crop information\n5. Delete a crop\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter crop name: ";
                cin.ignore(); // Clear input buffer
                getline(cin, cropName);
                cout << "Enter crop price: $";
                cin >> price;
                cout << "Enter crop amount: ";
                cin >> amount;
                farmer.addCrop(cropName, price, amount);
                break;
            case 2:
                farmer.showCrops();
                break;
            case 3:
                cout << "Enter the name of the crop to search for: ";
                cin.ignore(); // Clear input buffer
                getline(cin, cropName);
                farmer.searchCrop(cropName);
                break;
            case 4:
                cout << "Enter the name of the crop to update: ";
                cin.ignore(); // Clear input buffer
                getline(cin, cropName);
                cout << "Enter new price: $";
                cin >> newPrice;
                cout << "Enter new amount: ";
                cin >> newAmount;
                farmer.updateCrop(cropName, newPrice, newAmount);
                break;
            case 5:
                cout << "Enter the name of the crop to delete: ";
                cin.ignore(); // Clear input buffer
                getline(cin, cropName);
                farmer.deleteCrop(cropName);
                break;
            case 6:
                cout << "Exiting...";
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
