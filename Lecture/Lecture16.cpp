#include <iostream>

using namespace std;

struct AutoParts{
	int value;
	AutoParts* next;
};

//A pointer is passed by value, since it is just a variable of special type. 
void insertNode(AutoParts** head, AutoParts* newNode){
	AutoParts* p = NULL;
	AutoParts* n = NULL;
	n = NULL;
	p = *head;
	while(p != NULL && (p->value < newNode->value)){
		n = p;
		p = p->next;
	}	
	
	newNode->next = p;
	if(n != NULL)
		n->next = newNode;
	else{
		*head = newNode;
		cout << "...." << (*head)->value << endl;
	}
}

void deleteList(AutoParts* head){
	AutoParts* p = head;
	while(head != NULL){
		p = head;
		head = head->next;
		delete p;
	}
}

void displayList(AutoParts* head){
	AutoParts* p = head;
	while(p != NULL){
		cout << p->value;
		if(p->next != NULL)
			cout << " ";
		p = p->next;
	}
	cout << endl;
}


int main(){
	AutoParts* head = NULL;

	AutoParts* newNode = NULL;

	int val;

	do{
		cin >> val;
		if(val == -1)
			break;

		if(head == NULL){
			head = new AutoParts;
			head->value = val;
			head->next =NULL;
		}
		else{
		newNode = new AutoParts;
		newNode->value = val;
		newNode->next = NULL;
		
			insertNode(&head, newNode);
		
		}
		displayList(head);
	}while(true);

	displayList(head);

	//deleteList(head);
}
