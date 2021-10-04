#include <iostream>
using namespace std;

int* func(int arr[], int n){
	int* list = new int[n];
	int i;

	for(i = 0; i < n; i++)
		list[i] = arr[i]*2;
	return list;

}


int main(){
	
	int n, m, i, j;
	
	cin >> n;
	cin >> m;

    // 1st dimension
	int** arr = new int*[n]; 
	for(i = 0; i<n; i++){
		arr[i] = new int[m];
	}

	// init array
	for(i = 0 ; i < n; i++){
		for(j = 0; j < m; j++)
			arr[i][j] = i;
	}

	


	// Deallocating 1-D array
	for(i = 0; i<n; i++){
		delete [] arr[i];
	}



	delete [] arr;
	
	cout << "Done";
	
	return 0;

}
