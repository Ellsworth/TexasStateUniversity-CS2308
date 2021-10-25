#include <iostream>

using namespace std;


struct ListNode {
    double value; // data
    ListNode *next; // ptr to next node
};

void display(ListNode* ptrList) {
    ListNode* p = ptrList;

    while (p != NULL)
    {
        cout << p->value;
        p = p->next;

        if (p != NULL) cout << " ";
    }
    
}
int main() {

    // T1 - Create empty list
    ListNode *head = NULL;

    float userInput = 0;


    ListNode *newNode = new ListNode;

    while (true) {
        cin >> userInput;

        if (userInput < 0) break;


        ListNode *newNode = new ListNode;
        newNode->value = userInput;

        newNode->next = head;
        head = newNode;


    } 

    display(head);



    
}