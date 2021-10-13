// File Name: Assignment3.cpp
// 
// Author: Erich Scott Ellsworth, wqi7
// Collaborators: N/A
// Date: October 13. 2021
// Assignment Number: 3
// CS 2308 Fall 2021

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Bakery {

    int id;
    string name;
    int quantity;
    double price;


};

void readBakery(ifstream& in,Bakery **bakeries, int N, int M);
void displayMenu();
void displayBakeryItems(Bakery **bakeries, int N, int M);
void displayHeader();
int searchMax(Bakery** bakeries, int N, int M);
void sortById(Bakery *bakeries, const int SIZE);
void sortByDateRating(Bakery *bakeries, const int SIZE);
void displayBakery(const Bakery& bakery);
void releaseMemory(Bakery**, int, int);
Bakery** allocateMemory(int N, int M);

int main() {

}

void displayHeader(){
    cout << left
         << setw(3) << "ID"
         << setw(26) << "Name"
         << setw(12) << "Quantity"
         << "Price"
         << endl;
}

void displayMenu(){
    cout << "\nMenu\n"
         << "1. Display bakeries sorted by id\n"
         << "2. Display bakeries sorted by quantity, then price-per-item\n"
         << "3. Find the product with maximum quantity among all bakeries\n"
         << "4. Purchase items\n"
         << "5. Quit the Program\n"
         << "Enter your choice:\n";
}