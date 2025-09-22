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

