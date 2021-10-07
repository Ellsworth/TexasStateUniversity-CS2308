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

        void display();


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

void Country::display() {

    cout << name << " " << athletes << " " << numMedals << endl;

}

int main() {

    // : {"A", 13, 10} and {"B", 12, 14}, {"C", 1, 114} and {"D", 19, 24}

    Country a("A", 13, 10);
    Country b("B", 12, 14);
    Country c("C", 1, 114);
    Country d("D", 19, 24);

    a.display();
    b.display();
    c.display();
    d.display();
    
}