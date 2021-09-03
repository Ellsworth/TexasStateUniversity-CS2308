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
    float userNewFileSize = 0;

    while (userInput != 0) {
        printFilesystem(files, SIZE);

    }



}

void printFilesystem(filesystem files[], int size) {

    cout << left << setprecision(2)
        << setw(3) << "N"
        << setw(15) << "Name"
        << setw(10) << "Num files"
        << setw(10) << "Size(Mb)"
        << endl;

    for (int i = 1; i < size; i++) {

        cout << setw(3) << i
            << setw(15) << files[i].name
            << setw(10) << files[i].fileCount
            << setw(10) << files[i].fileSize
            << endl;

        //cout << setw(10) << files[i].fileCount;
    }



    return;


}

int promptUser(filesystem files[], int size) {

    int userInput, userNewFileSize;

    cout << "Enter the folder number (0 to quit):" << endl;
    cin >> userInput;

    if (userInput > 0 && userInput < SIZE) {
        cout << "Enter the file size:" << endl;
        cin >> userNewFileSize;

        files[userInput].fileSize += userNewFileSize;
        files[userInput].fileCount++;
    }
    else (userInput < 0 || userInput >= SIZE) {
        cout << "Invalid folder number" << endl;
    }

    if (userInput == 0) {
        cout << "Total size of all folders: " << getTotalSize(files, SIZE) << endl;
        cout << "Folder with the largest average file size: " << files[findLargestAvgFile(files, SIZE)].name << endl;
    }

}

int findLargestAvgFile(filesystem files[], int size) {

    int max = 1;

    for (int i = 1; i < size; i++) {
        if ((files[i].fileSize / files[i].fileCount) > (files[max].fileSize / files[max].fileCount)) {
            max = i;
        }

    }

    return max;

}

float getTotalSize(filesystem files[], int size) {

    float total = 0;

    for (int i = 1; i < size; i++) {
        total += files[i].fileSize;
    }

    return total;

}