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

int main() {

    ifstream in;
    in.open("movies.txt");

    Movie movies[100];
    int size = 0;

    int userInput = 5;

    while (userInput != 5) {
        displayMenu();

        cin >> userInput;
    }

    readMovies(in, movies, size);

    for (int i = 0; i < size; i++) {
        cout << i << " " << movies[i].id << " " << movies[i].name << endl;
    }

    cout << "Database entries: " << size << endl;


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