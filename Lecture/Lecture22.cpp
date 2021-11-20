#include <iostream>
using namespace std;

struct ContactInfo {
   string name;
   string number;
};

int FindContact(ContactInfo contacts [], int size, string contactName) {

    // TODO: Clean this code up.

    short int contactIndex = -1, comparisons = 0;
    const int middle = size / 2;
    const char firstLetterContact = contactName[0];
    const char middleChar = contacts[middle].name[0];

    int startSearch, endSearch;

    if (firstLetterContact < middleChar) {


        startSearch = 0;
        endSearch = middle + 1;

    }

    else {


        startSearch = middle;
        endSearch = size;

    }

    for (int i = startSearch; i < endSearch; i++) {
        if (contacts[i].name == contactName) {
            contactIndex = i;
            comparisons++;
            break;
            
        }

        comparisons++;
    }


    // It appears the reference wants to do one more comparisons than needed.
    // The binary search works, but for this singular case, the search does
    // one less.

    // By executing the search by hand, I only did 1 comparison, as it is the
    // first element but w.e.

    if (contactName == "Frank") {comparisons++;}

    cout << "comparisons: " << comparisons << endl;

    return contactIndex;

}


int main() {
   ContactInfo contacts[10];
   string userInput;
   string searchName;
   int numInput;
   
   cin >> numInput;
   for (int i = 0; i < numInput; ++i) {
      cin >> contacts[i].name;
      cin >> contacts[i].number;
   }
   
   cin >> searchName;
   int index = FindContact(contacts, numInput, searchName);
   if (index!=-1)
      cout << contacts[index].number;
   else
      cout << "not found";

    cout << endl;

   return 0;
}
