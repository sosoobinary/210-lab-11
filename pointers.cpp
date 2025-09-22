#include <iostream>
#include <string>
using namespace std;

const int numCustomers = 3;

struct Customer {
    string name;
    int age;
    string* drinks;

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
    cout << "Name: " << cptr->name << endl;
    getline(cin, cptr->name);
    cout << "Age: " << cptr->age << endl;
    cin >> cptr->age;
    cptr->drinks = new string[numCustomers];
    for(int i = 0; i < numCustomers; i++) {
        cout << "Drink #" << i+1 << ": ";
        cin >> cptr->drinks[i];
    }
    cin.ignore();
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

