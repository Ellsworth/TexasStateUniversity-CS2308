#include <iostream>
using namespace std;

int getTotal(int, int[]);
float getAverage(int, int[]);
int getMaxValue(int, int[]);


int main() {
   int size;
   
   cin >> size; 
   
   int scores[size];
   
   // Fill the array with our values.
   for (int i = 0; i < size; i++) {
      cin >> scores[i];
      
   }

   float average = getAverage(size, scores);
   
   cout << average << " " << getMaxValue(size, scores);
   
   return 0;
}

int getMaxValue(int size, int array[]) {

   int maxIndex = 0;

   for (int i = 0; i < size; i++) {
      if (array[i] > array[maxIndex]) maxIndex = i;
   
   }

   return array[maxIndex];

}

int getTotal(int size, int array[]) {

   int total = 0;

   for (int i = 0; i < size; i++) total += array[i];

   return total;
}

float getAverage(int size, int array[]) {

   return (float)getTotal(size, array) / (float)size;

}