#include <iostream>

using namespace std;

int linearSearch(int, int[], int);
void swapIndexPos(int, int, int[]);
void printArray(int[], int);
void bubbleSort(int[], int);

int main() {

    /**
    
    int size;

    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    **/

   int size = 5;
   int arr[] = {5, 7, 4, 2, 1};

   printArray(arr, size);

   cout << endl;

   swapIndexPos(0, 1, arr);
   bubbleSort(arr, size);

   printArray(arr, size);

}

int linearSearch(int target, int arr[], int size) {

    int target_index = -1;

    for (int i = 0; i < size; i++) {

        if (arr[i] == target) {
            target_index = i;
            break;
        }
    }

    return target_index;

}

void swapIndexPos(int x, int y, int arr[]) {
    int buffer;

    buffer = arr[x];
    arr[x] = arr[y];
    arr[y] = buffer;

    return;

}

void printArray(int arr[], int size) {

    for (int i = 0; i < size; i++) {
        cout << i << " " << arr[i] << endl;
    }

    return;

}

void bubbleSort(int arr[], int size) {

    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swapIndexPos(i, i + 1, arr);
        }
    }

}