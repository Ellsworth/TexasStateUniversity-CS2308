#include <iostream>

using namespace std;

class LunchBox {
    private:
        string *items;
        int count;

    public:
        LunchBox() {items = NULL; count = 0;}
        LunchBox(int);
        ~LunchBox();

        void init(int number);

        void setItem(string newItem){items[count]= newItem;count++;}

        string getItem(int id) {return items[id];}

        int getCount() {return count;}

};

LunchBox::LunchBox(int numItems){
    items = new string[numItems];
    count = 0;
}

LunchBox::~LunchBox(){
    delete [] items;
}

void LunchBox::init(int numItems){
    items = new string[numItems];
}

int main() {

    int numStudents, numItems;
    string itemName;

    // Total amount of LunchBox needed.
    cin >> numStudents;

    //cout << "Total Students: " << numStudents << endl;

    // init the array of lunchboxes.
    LunchBox* studentLunch = new LunchBox[numStudents];


    for (int i = 0; i < numStudents; i++) {

        cin >> numItems;
        studentLunch[i].init(numItems);

        //cout << "Current Student: " << i + 1<< "/" << numStudents << endl;

        for (int j = 0; j < numItems; j++) {

            //cout << "item name: ";
            cin >> itemName;
            //cout << endl;

            studentLunch[i].setItem(itemName);

        }

    }

    for (int i = 0; i < numStudents; i++) {

        for (int j = 0; j < studentLunch[i].getCount(); j++) {

            cout << studentLunch[i].getItem(j);

            if (j < studentLunch[i].getCount()) cout << " ";

        }

        cout << endl;

    }



}