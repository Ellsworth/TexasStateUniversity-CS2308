#include <iostream>

using namespace std;

class Country {

    private:

        string name;
        int athletes;
        int numMedals;

    public:

        void setName(string newName) {name = newName; }
        void setAthletes(int newAthletes) { athletes = newAthletes; }
        void setMedals(int newMedals) {numMedals = newMedals; }

        string getName() {return name;}
        int getAthletes() {return athletes;}
        int getMedals() {return numMedals;}

        Country();
        Country(string, int, int);


};

Country::Country() {
    name = "";
    athletes = 0;
    numMedals = 0;
}

Country::Country(string newName, int newAthletes, int newNumMedals) {
    name = newName;
    athletes = newAthletes;
    numMedals = newNumMedals;
}

int main() {

    Country c("Switzerland", 5, 10);

    cout << c.getMedals() << endl;

}