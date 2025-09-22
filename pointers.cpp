// COMSC-210 | Lab 13 | Quang Ngo
// IDE: Visual Studio Code
#include <iostream>
#include <string>
using namespace std;

// Need a constant to set amount of customers for easy access
const int numCustomers = 3;

// Struct for customers with variables for name, age, drinks, and number of drinks
struct Customer {
    string name;
    int age;
    string* drinks;
    int numDrinks;

    // Default parameters
    Customer() : drinks(nullptr), numDrinks(0) {}

    // Deconstructor
    ~Customer() {
        if (drinks) {
            delete [] drinks;
        }
    }
};

// Function prototypes
void inputCustomer(Customer *);
void displayCustomer(Customer *);

int main() {
    Customer *barTable = new Customer[numCustomers];

    // Loop the input and display functions based off the number of customers in the bar
    for(int i = 0; i < numCustomers; i++) {
        inputCustomer(&barTable[i]);
    }

    for(int i = 0; i < numCustomers; i++) {
        displayCustomer(&barTable[i]);
    }

    return 0;
}

// sets all info for each customer
void inputCustomer(Customer * cptr) {
    static int numCust = 1;
    cout << "Input data for Customer #" << numCust << ":\n";
    cout << "Name: ";
    getline(cin, cptr->name);
    cout << "Age: ";
    cin >> cptr->age;
    cout << "Number of Drinks: ";
    cin >> cptr->numDrinks;
    cin.ignore();
    cptr->drinks = new string[cptr->numDrinks];
    for(int i = 0; i < cptr->numDrinks; i++) {
        cout << "Drink #" << i+1 << ": ";
        getline(cin, cptr->drinks[i]);
    }
    cout << endl << endl;
    numCust++;
}
// displays all customer information
void displayCustomer(Customer * cptr) {
    cout << "Customer summary:\n";
    cout << "Name: " << cptr->name << endl;
    cout << "Age: " << cptr->age << endl;
    for (int i = 0; i < numCustomers; i++)
        cout << "Drink #" << i + 1 << ": " 
             << cptr->drinks[i] << endl;
    cout << endl << endl;
}

