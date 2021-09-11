// File Name: Assignment1.cpp
// 
// Author: Erich Scott Ellsworth, wqi7
// Collaborators: N/A
// Date: 09/10/2021
// Assignment Number: 1
// CS 2308 Fall 2021
// 
// This program simulates a basic computer filesystem. It utilizes an array
// of structs to keep track of filecount and filesizings of a fictional
// filesystem.

#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 10 + 1;

struct filesystem {
    string name;
    int fileCount;
    double fileSize;
};

void printFilesystem(filesystem[], int);

int promptUser(filesystem[], int);

int findLargestAvgFile(filesystem[], int);

float getTotalSize(filesystem[], int);


int main() {
    filesystem files[] = {
        {"", 0, 0},
        {"Documents", 5, 12.38},
        {"Downloads", 11, 17.22},
        {"Pictures", 27, 30.26},
        {"Videos", 6, 22.75},
        {"Projects", 3, 7.94},
        {"Labs", 6, 1.44},
        {"Music", 45, 102.73},
        {"Favorites", 4, 2.10},
        {"Contacts", 35, 3.51},
        {"Miscellaneous", 1, 2.23} };
    
    int userInput = -1;

    while (userInput != 0) {
        printFilesystem(files, SIZE);
        userInput = promptUser(files, SIZE);

    }

}

//***********************************************************
// printFilesystem: Prints folders of filesystem. Displays folder ID, name, 
// filecount, and size.
// 
// files[] - array of "filesystem" type struct.
// size - int of the size of the files[] array.
//***********************************************************

void printFilesystem(filesystem files[], int size) {

    cout << left << showpoint << fixed << setprecision(2);
    
    cout << setw(3) << "N";
    cout << setw(15) << "Name";
    cout << setw(10) << "Num files";
    cout << setw(10) << "Size(Mb)" << endl;

    for (int i = 1; i < size; i++) {

        cout << setw(3) << i;
        cout << setw(15) << files[i].name;
        cout << setw(10) << files[i].fileCount;
        cout << setw(10) << files[i].fileSize << endl;

    }

    return;

}

//***********************************************************
// function name: Ask user for input, if valid, increase folder size and 
// increment file count. When user quits (option 0), the give total size
// and folder with largest avg. file size
//
// files[] - array of "filesystem" type struct.
// size - int of the size of the files[] array.
//
// returns: int - User's menu choice. Used for knowing when to stop looping in
// the main function.
//***********************************************************
int promptUser(filesystem files[], int size) {

    int userInput = -1;
    double userNewFileSize = 0;

    cout << "Enter the folder number (0 to quit):" << endl;
    cin >> userInput;
    
    // If user input is valid.
    if (userInput > 0 && userInput < size) {
        cout << "Enter the file size:" << endl;
        cin >> userNewFileSize;

        files[userInput].fileSize += userNewFileSize;
        files[userInput].fileCount++;

    }

    // If user input is less than 0 or bigger than size, then it is invalid.
    if (userInput < 0 || userInput > size - 1) {
        cout << "Invalid folder number" << endl;

    }
    
    // If user input is zero, print the filesystem stats before we exit in main.
    if (userInput == 0) {
        
        cout << "Total size of all folders: ";
        cout << getTotalSize(files, SIZE) << endl;

        cout << "Folder with the largest average file size: ";
        cout << files[findLargestAvgFile(files, SIZE)].name << endl;

    }

    return userInput;

}
//***********************************************************
// findLargestAvgFile: Returns the index of the folder with the largest avg.
// file size 
//
// files[] - array of "filesystem" type struct.
// size - int of the size of the files[] array.
// 
// returns: index of the filesystem array
//***********************************************************
int findLargestAvgFile(filesystem files[], int size) {

    int max = 1, avg_size = 0, avg_size_max = 0;

    for (int i = 1; i < size; i++) {

        // calculute the avg size for i
        avg_size = (files[i].fileSize / files[i].fileCount);
        
        if (avg_size > avg_size_max) {
            max = i;

            // calculate the avg size for the max.
            avg_size_max = avg_size;
        }

    }

    return max;

}

//***********************************************************
// getTotalSize: Finds the total size of all of the folders in the array
// of filesystems
//
// files[] - array of "filesystem" type struct.
// size - int of the size of the files[] array.
// 
// returns: total size of all of the folders of the filesystem.
//***********************************************************
float getTotalSize(filesystem files[], int size) {

    float total = 0;

    for (int i = 1; i < size; i++) {
        total += files[i].fileSize;
    }

    return total;

}