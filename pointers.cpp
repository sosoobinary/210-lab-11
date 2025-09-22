#include <iostream>
#include <string>
using namespace std;

const int numCustomers = 3;

struct Customer {
    string name;
    int age;
    string* drinks;
    int numDrinks;

    ~Customer() {
        if (drinks) {
            delete [] drinks;
        }
        drinks = nullptr;
    }
};

void inputCustomer(Customer *);
void displayCustomer(Customer *);

int main() {
    Customer *barTable = new Customer[numCustomers];

    for(int i = 0; i < numCustomers; i++) {
        inputCustomer(&barTable[i]);
    }

    for(int i = 0; i < numCustomers; i++) {
        displayCustomer(&barTable[i]);
    }

    return 0;
}

void inputCustomer(Customer * cptr) {
    static int numCust = 1;
    cout << "Input data for Customer #" << numCust << ":\n";
    cout << "Name: " << cptr->name;
    getline(cin, cptr->name);
    cout << "Age: " << cptr->age << endl;
    cin >> cptr->age;
    cout << "Number of Drinks: " << cptr->numDrinks << endl;
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
void displayCustomer(Customer * cptr) {
    cout << "Customer summary:\n";
    cout << "Name: " << cptr->name << endl;
    cout << "Age: " << cptr->age << endl;
    for (int i = 0; i < numCustomers; i++)
        cout << "Drink #" << i + 1 << ": " 
             << cptr->drinks[i] << endl;
    cout << endl << endl;
}

