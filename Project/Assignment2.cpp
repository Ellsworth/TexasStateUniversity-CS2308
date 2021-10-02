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
                displayMovies(movies, size);
                break;
            case 5:
                cout << "Exiting the program..." << endl;
                break;

        }
    }


    in.close();
}

void displayMenu() {
    cout << "\nMenu\n"
         << "1. Display movies sorted by id\n"
         << "2. Display movies sorted by release date, then rating\n"
         << "3. Lookup a release date given a name\n"
         << "4. Lookup a movie by id\n"
         << "5. Quit the Program\n"
         << "Enter your choice:\n";
}

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

void sortByDateRating(Movie movies[], int SIZE) {


    for (int j = 0; j < SIZE; j++) {

        for (int i = 0; i < SIZE - 1; i++) {
            int first = dateToEpoch(movies[i].releaseDate);
            int second = dateToEpoch(movies[i + 1].releaseDate);

            if (first > second) swapMovie(i, i + 1, movies);

            if (first == second) { // if the dates are the same, look at the rating

                if (movies[i].rating > movies[i + 1].rating) {
                    swapMovie(i, i + 1, movies);
                }
            }

        }

    }
    
    return;

}

int dateToEpoch(string input) {

    int year = stoi(input.substr(0, 4));
    int month = stoi(input.substr(5, 7));
    int day = stoi(input.substr(8, 10));

    int epoch = (year * 365) + (month * 31) + day;

    return epoch;

}

void swapMovie(int x, int y, Movie movies[]) {

    Movie buffer = movies[x]; // temp storage

    movies[x] = movies[y];
    movies[y] = buffer;

    return;
}