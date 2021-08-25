#include <iostream>

using namespace std;

int main() {

    int userinput = 0;
    cin >> userinput;

       

    while (userinput != 1) {

         cout << userinput << " ";


        if (userinput % 2 == 0) { // if even

            userinput = userinput / 2;

        }
        else { // if odd

            userinput = (userinput * 3) + 1;

        }

        
    }

    cout << "1";

}