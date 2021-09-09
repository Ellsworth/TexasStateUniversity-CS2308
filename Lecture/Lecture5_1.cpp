#include <iostream>
#include <iomanip>

using namespace std;

void swap(int*, int*);
void printArray(int[], int);
void sortArray(int[], int);
int linearSearch(int, int[], int);

int main() {
    int target, size;

    cin >> size;

    int array[size];

    for (int i = 0; i < size; i++) {

        cin >> array[i];

    }

    cin >> target;

    

    sortArray(array, size);

    cout << linearSearch(target, array, size) << endl;
    printArray(array, size);
    
    



}

void swap(int *x, int *y) 
{ 
    int buffer = *x; 
    *x = *y; 
    *y = buffer;
    
    return;
} 

void printArray(int array[], int size) {

    for (int i = 0; i < size; i++) {
        cout << array[i];

        if (i < (size - 1)) cout << " ";
    }

}


void sortArray(int array[], int size) {

    for (int j = 0; j < size; j++) {

        for (int i = 0; i < (size - 1); i++) {

            if (array[i] > array[i + 1]) {
                swap(array[i], array[i + 1]);
            }

        }

    }
}

int linearSearch(int target, int arr[], int size) {

    int target_index = -1;

    for (int i = 0; i < size; i++) {

        if (arr[i] == target) target_index = i;
    }

    return target_index;

}