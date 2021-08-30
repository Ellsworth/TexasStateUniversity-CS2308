#include <iostream>
using namespace std;

int getTotal(int size, int scores[]) {

    int total = 0;

    for (int i = 0; i < size; i++) {
      
      total += scores[i];
      
   }

   return total;

}

double getAverage(int size, int array[]) {

    int total = getTotal(size, array);

    double average = (double)total / (double)size;

    return average;

}

int getMaxIndex(int size, int array[]) {
    int maxIndex = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] > array[maxIndex]) maxIndex = i;
    }

    return maxIndex;
}


int main() {

    int n;
   
    cin >> n;
   
    int scores[n];
   
    // Fill the array with our values.
    for (int i = 0; i < n; i++) {
       cin >> scores[i];
       
    }

    cout << getAverage(n, scores);
    cout << " "  << scores[getMaxIndex(n, scores)] << endl;


    return 0;
}