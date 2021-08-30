#include <iostream>
using namespace std;

struct employee {
    string name;
    int salary;

};

const int SIZE = 4;

int main() {

    employee company[SIZE + 1];

    company[1].name = "A";
    company[1].salary= 615;

    company[2].name = "B";
    company[2].salary= 625;

    company[3].name = "C";
    company[3].salary= 635;

    company[4].name = "D";
    company[4].salary = 645;

    cout << "ID Name Salary" << endl;

    for (int i = 1; i <= SIZE; i++) {
        cout << i << " " << company[i].name << " " << company[i].salary;

        if (i < SIZE) cout << endl;
    }
}