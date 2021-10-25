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

// Rubric required function constructors. DO NOT EDIT.
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

// custom constructors
void readBakeryMetadata(ifstream& in, int &numBakeries, int &numItems);



int main() {

    ifstream in;
    in.open("bakery.txt");

    int userInput = 5;

    int numBakeries = 0, numItems = 0;

    readBakeryMetadata(in, numBakeries, numItems);

    Bakery** arr = allocateMemory(numBakeries, numItems);
    

    cout << numBakeries << " " << numItems << endl;

    readBakery(in, arr, numBakeries, numItems);

    //displayBakeryItems(arr, numBakeries, numItems);

    
    while (userInput != 5) {

        cin >> userInput;

        switch (userInput) {
            case 5:
                break;
        }

    }

    releaseMemory(arr, numBakeries, numItems);



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

void readBakery(ifstream& in,Bakery **bakeries, int numBakeries, int numItems) {

    int currentBakery = 0, currentItem = 0;
    string blankline;

    while(getline(in,blankline)) {

        if(!blankline.size());//cout << "BREAK" << endl;
        else {
            bakeries[currentBakery][currentItem].id = stoi(blankline);
            getline(in, bakeries[currentBakery][currentItem].name);
            in >> bakeries[currentBakery][currentItem].quantity;
            in >> bakeries[currentBakery][currentItem].price;

            cout << "Bakery " << currentBakery + 1 << "/" << numBakeries << " Item " << currentItem + 1 << "/" << numItems << endl;

            cout << "ID       : " << bakeries[currentBakery][currentItem].id << endl;
            cout << "Name     : " << bakeries[currentBakery][currentItem].name << endl;
            cout << "Quantity : " << bakeries[currentBakery][currentItem].quantity << endl;
            cout << "Price    : " << bakeries[currentBakery][currentItem].price << endl;

            currentItem++;
        }

        if (currentItem == numItems) {
            currentItem = 0;
            currentBakery++;
        }

    }


}

void readBakeryMetadata(ifstream& in, int &numBakeries, int &numItems) {

    string blankline;

    in >> numBakeries;
    in >> numItems;

    return;
}


Bakery** allocateMemory(int N, int M) {

    Bakery** arr = new Bakery*[N]; //1st dimension

	for(int i = 0; i<N ; i++){
		arr[i] = new Bakery[M];
	}

    return arr;

}

void releaseMemory(Bakery** arr, int N, int M) {

    for(int i = 0; i < N; i++) {
        delete [] arr[i];
    }
    delete [] arr;
}

/**

void displayBakeryItems(Bakery bakeries, int N, int M) {

        for (int i = 0; i < N; i++) { // loop for every bakery

        for (int j = 0; j < M; j++) { // loop for every item

            


        }

    }

}
**/


void displayBakery(const Bakery& bakery){
    cout << left
         << setw(3) << bakery.id
         << setw(26) << bakery.name
         << setw(12) << bakery.quantity
         << fixed << setprecision(1) << bakery.price
         << endl;
}