// File Name: Assignment3.cpp
// 
// Author: Erich Scott Ellsworth, wqi7
// Collaborators: N/A
// Date: October 13. 2021
// Assignment Number: 3
// CS 2308 Fall 2021
//
// This program serves an inventory management for a bakeries. It supports 
// managing the inventory for multiple locations. The program uses a 2D 
// dynamically allocated array of structs. Therefor the system can hold as many
// items as needed. (Assuming there is enough RAM to go around.)

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
void linearSearchAndUpdate(Bakery* bakery, string productName, int M); 
void sortById(Bakery **bakeries, int numBakeries, int numItems);
void sortByQuantityPrice(Bakery *bakeries, const int SIZE);
void displayBakery(const Bakery& bakery);
void releaseMemory(Bakery**, int, int);
Bakery** allocateMemory(int N, int M);

// custom constructors
void readBakeryMetadata(ifstream& in, int &numBakeries, int &numItems);
void checkOutItem(Bakery** bakery, int numItems);

int main() {

    ifstream in;
    in.open("bakery.txt");

    int userInput = -1;
    int numBakeries = 0, numItems = 0;

    readBakeryMetadata(in, numBakeries, numItems);

    Bakery** arr = allocateMemory(numBakeries, numItems);

    readBakery(in, arr, numBakeries, numItems);
    
    displayBakeryItems(arr, numBakeries, numItems);
    
    while (userInput != 5) {

        
        displayMenu();

        cin >> userInput;

        switch (userInput) {
            case 1:
                sortById(arr, numBakeries, numItems);
                break;
            case 2:
                for (int i = 0; i < numBakeries; i++) {
                    sortByQuantityPrice(arr[i], numItems);
                }
                break;
            case 3:
                searchMax(arr, numBakeries, numItems);
                break;
            case 4:
                checkOutItem(arr, numItems);
                break;
            case 5:
                break;
        }

        if (userInput != 3 && userInput != 5) {
            displayBakeryItems(arr, numBakeries, numItems);
        }

    }

    releaseMemory(arr, numBakeries, numItems);

}

//***********************************************************
// displayHeader: Used for displaying the header for displayBakeryItems.
//***********************************************************

void displayHeader() {
    cout << left
         << setw(3) << "ID"
         << setw(26) << "Name"
         << setw(12) << "Quantity"
         << "Price"
         << endl;
}

//***********************************************************
// searchMax: Finds the item with the max quantity.
//
// Bakery** bakeries: 2D array of Bakery struct
// N: number of bakeries
// M: number of items per bakery
// returns: 0
//***********************************************************

int searchMax(Bakery** bakeries, int N, int M) {

    int maxN = 0, maxM = 0;

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < M; j++) {

            if (bakeries[i][j].quantity > bakeries[maxN][maxM].quantity) {

                maxN = i;
                maxM = j;

            }
        
        }

    }

    cout << "Product needs attention: " << bakeries[maxN][maxM].name << " ";
    cout << bakeries[maxN][maxM].quantity << " in bakery " << N << endl;

    return 0;
}

//***********************************************************
// sortById: Sorts a 2D array of bakery structs by ID
//
// Bakery** bakeries: 2D array of Bakery struct
// numBakeries: number of bakeries
// numItems: number of items per bakery
//***********************************************************

void sortById(Bakery **bakeries, int numBakeries, int numItems) {

    for (int i = 0; i < numBakeries; i++) {
        for (int j = 0; j < numItems - 1; j++) {

            if (bakeries[i][j].id > bakeries[i][j + 1].id) {

                swap(bakeries[i][j], bakeries[i][j + 1]);
            }

            

        }
    }

}

//***********************************************************
// linearSearchAndUpdate: Finds an item in a 1D array. If found and enough
//      stock, remove one from quantity and print error or success message.
//
// Bakery* bakeries: 1D array of Bakery struct
// productName: name to be searched
// M: number of items per bakery
//***********************************************************


void linearSearchAndUpdate(Bakery* bakery, string productName, int M) {

    bool foundItem = false;

    for (int i = 0; i < M; i++) {

        if (bakery[i].name == productName && bakery[i].quantity > 0) {

            cout << "Successfully checked out " << productName << endl;
            bakery[i].quantity--;

            foundItem = true;

        }

    }

    if (!foundItem) {
        cout << "The item " << productName << " does not exist" << endl;
    } 
}

//***********************************************************
// displayMenu: prints the menu.
//***********************************************************

void displayMenu(){
    cout << "\nMenu\n"
         << "1. Display bakeries sorted by id\n"
         << "2. Display bakeries sorted by quantity, then price-per-item\n"
         << "3. Find the product with maximum quantity among all bakeries\n"
         << "4. Purchase items\n"
         << "5. Quit the Program\n"
         << "Enter your choice:\n";
}

//***********************************************************
// readBakery: reads data from fstream and fills up a 2D array of bakery struct.
//
// in: ifstream file input
// bakeries: 2D array of Bakery struct
// numBakeries: number of bakeries
// numItems: number of items per bakery
//***********************************************************

void readBakery(ifstream& in,Bakery **bakeries, int numBakeries, int numItems) {

    int currentBakery = 0, currentItem = 0;
    string blankline;

    while(getline(in,blankline)) {

        if(!blankline.size());
        else {
            bakeries[currentBakery][currentItem].id = stoi(blankline);
            getline(in, bakeries[currentBakery][currentItem].name);
            in >> bakeries[currentBakery][currentItem].quantity;
            in >> bakeries[currentBakery][currentItem].price;

            currentItem++;
        }

        if (currentItem == numItems) {
            currentItem = 0;
            currentBakery++;
        }

    }


}

//***********************************************************
// readBakeryMetadata: reads first two lines from fstream 
//
// in: ifstream file input
// numBakeries: number of bakeries
// numItems: number of items per bakery
//***********************************************************

void readBakeryMetadata(ifstream& in, int &numBakeries, int &numItems) {

    in >> numBakeries;
    in >> numItems;

    return;
}

//***********************************************************
// allocateMemory: allocate memory and create a 2D array of bakery struct. 
//
// N: number of bakeries
// M: number of items per bakery
//
// returns: created 2d dynamic bakery array
//***********************************************************

Bakery** allocateMemory(int N, int M) {

    Bakery** arr = new Bakery*[N]; //1st dimension

	for(int i = 0; i<N ; i++){
		arr[i] = new Bakery[M];
	}

    return arr;

}

//***********************************************************
// releaseMemory: destroy 2D array of bakery struct.
//
// arr: dynamic 2D array of bakery struct.
// N: number of bakeries
// M: number of items per bakery
//
// returns: created 2d dynamic bakery array
//***********************************************************


void releaseMemory(Bakery** arr, int N, int M) {

    for(int i = 0; i < N; i++) {
        delete [] arr[i];
    }
    delete [] arr;
}

//***********************************************************
// sortByQuantityPrice: sorts 1D array of bakery struct by quantity, then price.
//
// bakeries: 1D array of bakery struct
//
// SIZE: number of items per bakery
//***********************************************************

void sortByQuantityPrice(Bakery *bakeries, const int SIZE) {

    for (int i = 0; i < SIZE - 1; i++) {

        if (bakeries[i].quantity > bakeries[i + 1].quantity) {

            swap(bakeries[i], bakeries[i + 1]);

        }
        
        // if same quantity, compare their price
        if (bakeries[i].quantity == bakeries[i + 1].quantity) {
            
            if (bakeries[i].price < bakeries[i + 1].price) {

                swap(bakeries[i], bakeries[i + 1]);
    
            }
        }

    }


}

//***********************************************************
// displayBakery: prints certain attributes of bakery struct.
//
// bakery: bakery struct
//***********************************************************

void displayBakery(const Bakery& bakery){
    cout << left
         << setw(3) << bakery.id
         << setw(26) << bakery.name
         << setw(12) << bakery.quantity
         << fixed << setprecision(1) << bakery.price
         << endl;
}

//***********************************************************
// displayBakeryItems: prints all items stored in 2D array of Bakery struct.
//
// bakeries: dynamic 2D array of bakery struct.
// N: number of bakeries
// M: number of items per bakery
//***********************************************************

void displayBakeryItems(Bakery** bakeries, int N, int M) {

    displayHeader();

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < M; j++) {

            displayBakery(bakeries[i][j]);

        }

        cout << "--------" << endl;
    }
}

//***********************************************************
// checkOutItem: Asks user for bakery ID and item name and passes that
//      info to linearSearchAndUpdate.
//
// bakery: dynamic 2D array of bakery struct.
// numItems: number of items per bakery
//***********************************************************

void checkOutItem(Bakery** bakery, int numItems) {

    int bakeryId;
    string productName;

    cout << "Enter bakery ID:" << endl;

    cin >> bakeryId;
    bakeryId--;

    cout << "Enter product name:" << endl;
    cin.ignore();
    getline(cin, productName);

    linearSearchAndUpdate(bakery[bakeryId], productName, numItems);

}
 