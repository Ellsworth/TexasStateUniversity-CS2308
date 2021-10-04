// File Name: Assignment2.cpp
// 
// Author: Erich Scott Ellsworth, wqi7
// Collaborators: N/A
// Date: 10/1/2021
// Assignment Number: 2
// CS 2308 Fall 2021
// 
// This program allows the user to view a movie database. The user may choose
// how the list is sorted and search for a specific item. 

#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;

struct Movie {
    int id;
    string name, releaseDate;
    double rating;
};

// Rubric required function constructors. DO NOT EDIT.
void readMovies(ifstream& in, Movie movies[], int& size);  // in is a file stream to "movies.txt" file, set in main
void displayMovies(Movie movies[], int SIZE);
void sortByDateRating(Movie movies[], int SIZE);
void sortById(Movie movies[], const int SIZE);
int linearSearchByName(Movie movies[], int SIZE, string targetName);

// Custom constructors.
void displayMenu();
int dateToEpoch(string input);
void swapMovie(int x, int y, Movie movies[]);
void searchMovieByName(Movie movies[], int size);
void findMovieByID(Movie movies[], int size);

int main() {

    ifstream in;
    in.open("movies.txt");

    Movie movies[100];
    int size = 0;

    readMovies(in, movies, size);

    int userInput = -1;

    while (userInput != 5) {
        displayMenu();

        cin >> userInput;

            
        // When userInput is invalid, print valid options and reprompt.
        while (userInput < 1 || userInput > 5) {
            
            cout << "Please enter 1, 2, 3, 4, or 5:" << endl;
            cin >> userInput;
        }


        switch (userInput) {
            case 1:
                sortById(movies, size);
                displayMovies(movies, size);
                break;
            case 2:
                sortByDateRating(movies, size);
                displayMovies(movies, size);
                break;

            case 3:
                searchMovieByName(movies, size);
                break;

            case 4:
                findMovieByID(movies, size);
                break;

            case 5:
                cout << "Exiting the program..." << endl;
                break;

        }
    }


    in.close();
}

//***********************************************************
// displayMenu: Prints the menu for the program.
//***********************************************************

void displayMenu() {
    cout << "\nMenu\n"
         << "1. Display movies sorted by id\n"
         << "2. Display movies sorted by release date, then rating\n"
         << "3. Lookup a release date given a name\n"
         << "4. Lookup a movie by id\n"
         << "5. Quit the Program\n"
         << "Enter your choice:\n";
}

//***********************************************************
// readMovies: Reads a movies.txt file and stores the data into an array of
// structs.
//
// ifstream& in - ifstream. File is read thru this ifstream. Declared in main 
// Movie movies[] - movies is the array of movie structs. We will fill this with
//      the data from movies.txt
// &size - the size of the array. Every time we add an element to movies[],
//      this int is incremented by one.
//***********************************************************

void readMovies(ifstream& in, Movie movies[], int& size) {

    size = 0;

    while (in >> movies[size].id) {
        in >> ws;       // skips the newline after the number in the file

        getline(in, movies[size].name);
        in >> movies[size].releaseDate;
        in >> movies[size].rating;

        size++;


    }

}

//***********************************************************
// displayMovies: prints the contents of the movies array.
//
// Movie movies[] - movies is the array of movie structs.
// SIZE - the size of the array. set by readMovies.
//***********************************************************

void displayMovies(Movie movies[], int SIZE) {
    cout << left << showpoint << setprecision(2)
         << setw(3) << "ID"
         << setw(26) << "Name"
         << setw(12) << "Date"
         << "Rating"
         << endl;

    for (int i = 0; i < SIZE; i++) {

        cout << setw(3) << movies[i].id;
        cout << setw(26) << movies[i].name;
        cout << setw(12) << movies[i].releaseDate;
        cout << movies[i].rating;

        cout << endl;

    }
}

//***********************************************************
// sortByDateRating: Sorts an array of Movie by Date. If they share the same
//      date, then the are sorted by rating.
//
// Movie movies[] - movies is the array of movie structs.
// SIZE - the size of the array. set by readMovies.
//***********************************************************

void sortByDateRating(Movie movies[], int SIZE) {


    for (int j = 0; j < SIZE; j++) {

        for (int i = 0; i < SIZE - 1; i++) {
            int first = dateToEpoch(movies[i].releaseDate);
            int second = dateToEpoch(movies[i + 1].releaseDate);

            if (first > second) swapMovie(i, i + 1, movies);

            if (first == second) { // if the dates are the same, look at the rating

                if (movies[i].rating < movies[i + 1].rating) {
                    swapMovie(i, i + 1, movies);
                }
            }

        }

    }
    
    return;

}

//***********************************************************
// dateToEpoch: Takes a date string formatted as YYYY/MM/DD and converts it to
//      an aprox date since the year 0000. A touch hacky, but it works well.
//
// string input - a string formatted as YYYY/MM/DD eg. 2011/04/25
//
// returns: int. aprox days since year zero. 
//***********************************************************

int dateToEpoch(string input) {

    int year = stoi(input.substr(0, 4));
    int month = stoi(input.substr(5, 7));
    int day = stoi(input.substr(8, 10));

    int epoch = (year * 365) + (month * 31) + day;

    return epoch;

}

//***********************************************************
// swapMovie: swaps two entries of an array of Movie
//
// int x - index of the 1st entry to swap
// int y - index of the 2nd entry to swap
//***********************************************************

void swapMovie(int x, int y, Movie movies[]) {

    Movie buffer = movies[x]; // temp storage

    movies[x] = movies[y];
    movies[y] = buffer;

    return;
}

//***********************************************************
// linearSearchByName: Finds the index of the movie with given name.
//
// Movie movies[] - movies is the array of movie structs.
// int SIZE - the size of the array. set by readMovies.
// string targetname - the name of the movie that is to be searched.
//
// returns: int. index of the array with given name. returns -1 if no result.
//***********************************************************

int linearSearchByName(Movie movies[], int SIZE, string targetName) {

    int targetIndex = -1;

    for (int i = 0; i < SIZE; i++) {
        if (movies[i].name == targetName) targetIndex = i;
    }

    return targetIndex;

}

//***********************************************************
// searchMovieByName: Prompts user for name of movie and returns release date
//      if found in the array
//
// Movie movies[] - movies is the array of movie structs.
// int size - the size of the array. set by readMovies.
//***********************************************************

void searchMovieByName(Movie movies[], int size) {

    string targetName;
    int index;
    
    cin.ignore();
    cout << "Please enter a movie name:" << endl;
    getline(cin, targetName);
    index = linearSearchByName(movies, size, targetName);

    if (index == -1) {
        cout << "No movie found with name: " << targetName << endl;
    }
    else {

        cout << "Release date of '" << targetName << "' is ";
        cout << movies[index].releaseDate << endl;

    }
}

//***********************************************************
// findMovieByID: Finds the index of the movie with given name.
//
// Movie movies[] - movies is the array of movie structs.
// int SIZE - the size of the array. set by readMovies.
// string targetname - the name of the movie that is to be searched.
//
// returns: int. index of the array with given name. returns -1 if no result.
//***********************************************************

void findMovieByID(Movie movies[], int size) {

    int targetIndex = -1, targetID = 0;

    cout << "Please enter a movie id:" << endl;
    cin >> targetID;

    for (int i = 0; i < size; i++) {

        if (movies[i].id == targetID) {
            targetIndex = i;
        }
    
    }

    // if movies exists, print
    if (targetIndex != -1) {

        cout << left << showpoint << setprecision(2)
            << setw(3) << "ID"
            << setw(26) << "Name"
            << setw(12) << "Date"
            << "Rating"
            << endl;
        
        cout << left << showpoint << setprecision(2)
            << setw(3) << movies[targetIndex].id
            << setw(26) << movies[targetIndex].name
            << setw(12) << movies[targetIndex].releaseDate
            << movies[targetIndex].rating
            << endl;
        
    }
    
    // no movie found
    if (targetIndex == -1) {
        cout << "No movie found with id: " << targetID << endl;
    }

}

//***********************************************************
// sortById: Sorts an array of Movie by ID. Smallest to greatest.
//
// Movie movies[] - movies is the array of movie structs.
// int SIZE - the size of the array. set by readMovies.
//
// returns: int. index of the array with given name. returns -1 if no result.
//***********************************************************

void sortById(Movie movies[], const int SIZE) {
    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < SIZE - 1; j++) {

            if (movies[j].id > movies[j + 1].id) {
                swapMovie(j, j + 1, movies);
            }

        }

    }
}