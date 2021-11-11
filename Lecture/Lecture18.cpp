#include <iostream>

using namespace std;

#define MAXSIZE 1000


//Define our ADT
class NumberList{
	private:

	double *array;
	int count;

	public:
	NumberList();
	void displayList();
	void insert(double num);
	void appendNode(double num);
	void deleteNode(double num);
};

NumberList::NumberList(){
	//Implementing member variable using an array
	array = new double[MAXSIZE];
	count = 0;
}


void NumberList::displayList(){

	for(int i=0; i<count; i++)
	{
		cout << array[i];
		if(i < count-1)
			cout << " ";
	}
	cout << endl;
}

void NumberList::appendNode(double num){
	
	int i;
	if(count < MAXSIZE){
		array[count] = num;
		count++;
	}
	else{
		cout << "No more room to grow" << endl;
	}

}

void NumberList::insert(double num){
	int i, pos, j;
	for(i = 0; i < count; i++){
		if(array[i] > num)
			break;
	}
	pos = i;
	if (pos == count){
		array[pos] = num;
	}
	else{
		for(j = count - 1; j >= pos; j--){
			array[j+1] = array[j];
		}
		array[pos] = num;
	}
	count++;
}

void NumberList::deleteNode(double num){
	int i, j;
	for(i = 0; i < count; i++){
		if(array[i] == num)
			break;
	}
	if(i == count)
		return;
	

	for(j = i; j < count - 1; j++){
		array[j] = array[j+1];
	}	
	count--;
}

int main(){

	NumberList list;

	int value;
    do{
      cin >> value;
      if(value < 0) {
		  list.displayList();
         break; //Insertion ends
		  }
      list.insert(value);
	  
      
   }while(true);
   
   //Display the list by calling list.displayList()
   bool flag = false;
   
    do{
      cin >> value;
      if(value < 0)
         break; //Deletion ends
      //delete from the list
      list.deleteNode(value);
      list.displayList();
      
   }while(flag == true);

	list.displayList();
}
