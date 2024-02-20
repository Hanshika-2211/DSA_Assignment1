#include <iostream>
#include <string>
using namespace std;

void displayInventory(int[], string[], int);
void addProduct(int[], string[], int&);
void updateQuantity(int[], string[], int);
void checkStock(int[], string[], int);

int main() {
    const int MAX_PRODUCTS = 100;
    int quantities[MAX_PRODUCTS] = {0};
    string products[MAX_PRODUCTS];
    int numProducts = 0;

    int choice;
    do {
        cout << "\nInventory Management System\n";
        cout << "1. Display Inventory\n";
        cout << "2. Add Product\n";
        cout << "3. Update Quantity\n";
        cout << "4. Check Stock\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayInventory(quantities, products, numProducts);
                break;
            case 2:
                addProduct(quantities, products, numProducts);
                break;
            case 3:
                updateQuantity(quantities, products, numProducts);
                break;
            case 4:
                checkStock(quantities, products, numProducts);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

void displayInventory(int quantities[], string products[], int numProducts) {
    cout << "Current Inventory:\n";
    cout << "Product\t\tQuantity\n";
    for (int i = 0; i < numProducts; i++) {
        cout << products[i] << "\t\t" << quantities[i] << "\n";
    }
}

void addProduct(int quantities[], string products[], int& numProducts) {
    string productName;
    cout << "Enter product name: ";
    cin.ignore();
    getline(cin, productName);

    products[numProducts] = productName;
    quantities[numProducts] = 0;
    numProducts++;

    cout << "Product added successfully.\n";
}

void updateQuantity(int quantities[], string products[], int numProducts) {
    string productName;
    int newQuantity;

    cout << "Enter product name: ";
    cin.ignore();
    getline(cin, productName);

    bool found = false;
    for (int i = 0; i < numProducts; i++) {
        if (products[i] == productName) {
            found = true;
            cout << "Enter new quantity: ";
            cin >> newQuantity;
            quantities[i] = newQuantity;
            cout << "Quantity updated successfully.\n";
            break;
        }
    }

    if (!found) {
        cout << "Product not found.\n";
    }
}

void checkStock(int quantities[], string products[], int numProducts) {
    string productName;

    cout << "Enter product name: ";
    cin.ignore();
    getline(cin, productName);

    bool found = false;
    for (int i = 0; i < numProducts; i++) {
        if (products[i] == productName) {
            found = true;
            if (quantities[i] <= 5) {
                cout << "Alert: " << productName << " is running low on stock. Quantity: " << quantities[i] << "\n";
            } else {
                cout << productName << " is in stock. Quantity: " << quantities[i] << "\n";
            }
            break;
        }
    }

    if (!found) {
        cout << "Product not found.\n";
    }
}