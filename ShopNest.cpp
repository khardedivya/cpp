#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Structure for a product
struct Product {
    string name;
    string description;
    double price;
    int quantity;
};

// Structure for an order
struct Order {
    string date;
    Product products[10];
    double totalAmount;
    string status;
};

// Class for managing products and orders
class ShopNest {
private:
    unordered_map<string, Product> productCatalog;
    Order orders[100];
    int numOrders;

public:
    // Constructor
    ShopNest() {
        numOrders = 0;
    }

    // Function to add a product to the catalog
    void addProduct() {
        Product newProduct;
        cout << "Enter product name: ";
        cin >> newProduct.name;
        cout << "Enter product description: ";
        cin.ignore();
        getline(cin, newProduct.description);
        cout << "Enter product price: $";
        cin >> newProduct.price;
        cout << "Enter product quantity: ";
        cin >> newProduct.quantity;
        productCatalog[newProduct.name] = newProduct;
        cout << "Product \"" << newProduct.name << "\" added to catalog." << endl;
    }

    // Function to display all products in the catalog
    void displayProducts() {
        cout << "Product Catalog:" << endl;
        for (auto& entry : productCatalog) {
            cout << "Name: " << entry.second.name << ", Description: " << entry.second.description << ", Price: $" << entry.second.price << ", Quantity: " << entry.second.quantity << endl;
        }
    }

    // Function to add a product to the shopping cart
    void addToCart() {
        string productName;
        int quantity;
        cout << "Enter product name: ";
        cin >> productName;
        if (productCatalog.find(productName) != productCatalog.end()) {
            Product product = productCatalog[productName];
            cout << "Enter quantity: ";
            cin >> quantity;
            if (product.quantity >= quantity) {
                orders[numOrders].products[numOrders] = product;
                orders[numOrders].totalAmount += (product.price * quantity);
                cout << quantity << " units of \"" << productName << "\" added to cart." << endl;
            } else {
                cout << "Insufficient quantity of \"" << productName << "\" in stock." << endl;
            }
        } else {
            cout << "Product \"" << productName << "\" not found in catalog." << endl;
        }
    }

    // Function to display the shopping cart
    void displayCart() {
        cout << "Shopping Cart:" << endl;
        for (int i = 0; i < numOrders; ++i) {
            cout << "Name: " << orders[numOrders].products[i].name << ", Price: $" << orders[numOrders].products[i].price << ", Quantity: " << orders[numOrders].products[i].quantity << endl;
        }
        cout << "Total Amount: $" << orders[numOrders].totalAmount << endl;
    }

    // Function to place an order
    void placeOrder() {
        string date;
        cout << "Enter order date (YYYY-MM-DD): ";
        cin >> date;
        orders[numOrders].date = date;
        orders[numOrders].status = "Placed";
        numOrders++;
        cout << "Order placed successfully on " << date << "!" << endl;
    }

    // Function to return an order
    void returnOrder() {
        string date;
        cout << "Enter order date to return (YYYY-MM-DD): ";
        cin >> date;
        for (int i = 0; i < numOrders; ++i) {
            if (orders[i].date == date) {
                orders[i].status = "Returned";
                cout << "Order returned successfully for order placed on " << date << "!" << endl;
                return;
            }
        }
        cout << "No order found for the specified date." << endl;
    }

    // Function to display all orders
    void displayOrders() {
        cout << "Orders:" << endl;
        for (int i = 0; i < numOrders; ++i) {
            cout << "Date: " << orders[i].date << ", Status: " << orders[i].status << ", Total Amount: $" << orders[i].totalAmount << endl;
        }
    }
};

int main() {
    ShopNest shopNest;
    int choice;
    do {
        cout << "\nShopNest Menu:" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Display Products" << endl;
        cout << "3. Add to Cart" << endl;
        cout << "4. View Cart" << endl;
        cout << "5. Place Order" << endl;
        cout << "6. Return Order" << endl;
        cout << "7. View Orders" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                shopNest.addProduct();
                break;
            case 2:
                shopNest.displayProducts();
                break;
            case 3:
                shopNest.addToCart();
                break;
            case 4:
                shopNest.displayCart();
                break;
            case 5:
                shopNest.placeOrder();
                break;
            case 6:
                shopNest.returnOrder();
                break;
            case 7:
                shopNest.displayOrders();
                break;
            case 8:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 8);

    return 0;
}









// <!-- unordered_map:
// 1. **Efficient Lookup**: `unordered_map` provides constant-time average complexity for lookup operations (`O(1)`), which allows for quick retrieval of product information based on their names.
// 2. **Flexibility**: `unordered_map` allows the association of each product name with its corresponding `Product` structure, enabling easy retrieval and modification of product details.
// 3. **No Sorting Overhead**: Unlike `map`, `unordered_map` does not impose any ordering on its elements. Since the product catalog does not require sorting based on keys, `unordered_map` avoids unnecessary overhead associated with maintaining a sorted order. -->
