#include <iostream>
using namespace std;

// employee struct
struct employee {
    string name;
    int salary;

};

void printEmployeeData(employee arr[], int size) {
    cout << "ID Name Salary" << endl;

    for (int i = 1; i <= size; i++) {
        cout << i << " " << arr[i].name << " " << arr[i].salary;

        if (i < size) cout << endl;
    }

}

float calcAverageSalary(employee arr[], int size) {
    int total = 0;

    for (int i = 1; i <= size; i++) {
        total += arr[i].salary;
    }

    return total / size;
}
// Size of our employee struct.
const int SIZE = 4;

int main() {

    // init employee struct, with size one greater than "size."
    // This is due to the employee id's starting with 1.

    struct employee company[SIZE + 1] = {
        {"", 0},
        {"A", 615},
        {"B", 625},
        {"C", 635},
        {"D", 645},

    };
    
    printEmployeeData(company, SIZE);

    cout << endl << calcAverageSalary(company, SIZE) << endl;

   


}