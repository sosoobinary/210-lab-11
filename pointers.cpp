#include <iostream>
#include <string>

using namespace std;

struct Customer {
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
    Customer *
}

